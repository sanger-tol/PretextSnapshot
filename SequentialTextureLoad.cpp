/*
Copyright (c) 2026 Genome Research Ltd.
author: Yumi Sims, Wellcome Sanger Institute, 2026

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "SequentialTextureLoad.h"
#include "libdeflate.h"

#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#else
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#define Sequential_Compression_Header_Size 128
#define Sequential_Max_Workers 16

struct bc4_block
{
    uint8_t values[8];
    /* Six index bytes, plus two pad bytes. The last texel's 3-bit index is read
       as a little-endian u16 that begins on the final index byte. */
    uint8_t lookup[8];
};

static void
FillBC4Block(struct bc4_block *block, const uint8_t *rawBytes)
{
    uint32_t index;

    memset(block, 0, sizeof(*block));
    block->values[0] = rawBytes[0];
    block->values[1] = rawBytes[1];
    block->values[2] = (uint8_t)(((6 * (uint16_t)block->values[0]) + (1 * (uint16_t)block->values[1])) / 7);
    block->values[3] = (uint8_t)(((5 * (uint16_t)block->values[0]) + (2 * (uint16_t)block->values[1])) / 7);
    block->values[4] = (uint8_t)(((4 * (uint16_t)block->values[0]) + (3 * (uint16_t)block->values[1])) / 7);
    block->values[5] = (uint8_t)(((3 * (uint16_t)block->values[0]) + (4 * (uint16_t)block->values[1])) / 7);
    block->values[6] = (uint8_t)(((2 * (uint16_t)block->values[0]) + (5 * (uint16_t)block->values[1])) / 7);
    block->values[7] = (uint8_t)(((1 * (uint16_t)block->values[0]) + (6 * (uint16_t)block->values[1])) / 7);
    for (index = 0; index < 6; ++index)
    {
        block->lookup[index] = rawBytes[index + 2];
    }
}

static uint8_t
GetBC4ValueAt(const struct bc4_block *block, uint8_t x, uint8_t y)
{
    uint8_t coord = (uint8_t)(x + (4 * y));
    uint8_t bitsIntoBlock = (uint8_t)(3 * coord);
    uint8_t bytesIntoBlock = (uint8_t)(bitsIntoBlock >> 3);
    uint8_t bitsFromByteStart = (uint8_t)(bitsIntoBlock & 7);
    uint16_t lookup;

    memcpy(&lookup, block->lookup + bytesIntoBlock, sizeof(lookup));
    lookup = (uint16_t)(lookup >> bitsFromByteStart);
    lookup = (uint16_t)(lookup & 7);
    return block->values[lookup];
}

static int
RangesOverlap(uint32_t a0, uint32_t a1, uint32_t b0, uint32_t b1)
{
    return a0 < b1 && b0 < a1;
}

static int
TileOverlaps(uint32_t textureX, uint32_t textureY, uint32_t textureResolution, uint32_t lodShift,
             uint32_t viewX, uint32_t viewY, uint32_t viewW, uint32_t viewH)
{
    uint32_t x0, x1, y0, y1;

    if (!viewW || !viewH) return 0;
    x0 = (textureX * textureResolution) >> lodShift;
    x1 = ((textureX + 1) * textureResolution) >> lodShift;
    y0 = (textureY * textureResolution) >> lodShift;
    y1 = ((textureY + 1) * textureResolution) >> lodShift;
    return RangesOverlap(x0, x1, viewX, viewX + viewW) && RangesOverlap(y0, y1, viewY, viewY + viewH);
}

static int
BlockHits(uint32_t texX, uint32_t texY, const struct sequential_map_layout *map, const struct sequential_lod_window *window)
{
    uint32_t res = map->textureResolution;
    uint32_t lod = window->lodLevel;

    if (TileOverlaps(texX, texY, res, lod, window->start0X, window->start0Y, window->range0X, window->range0Y)) return 1;
    if (texX != texY && TileOverlaps(texY, texX, res, lod, window->start0X, window->start0Y, window->range0X, window->range0Y)) return 1;
    if (!window->fillTwoImageBuffers) return 0;
    if (TileOverlaps(texX, texY, res, lod + 1, window->start1X, window->start1Y, window->range1X, window->range1Y)) return 1;
    if (texX != texY && TileOverlaps(texY, texX, res, lod + 1, window->start1X, window->start1Y, window->range1X, window->range1Y)) return 1;
    return 0;
}

static uint32_t
SplatOneLod(const uint8_t *mip, uint32_t mipBytes,
            uint32_t textureX, uint32_t textureY, uint32_t lowerTriangular,
            uint32_t textureResolution, uint32_t lodShift,
            uint32_t viewX, uint32_t viewY, uint32_t viewW, uint32_t viewH,
            uint8_t *image, uint32_t pitch, uint32_t limit)
{
    uint32_t tileX0, tileY0, tileX1, tileY1;
    uint32_t textureSize, bc4Size;
    uint32_t coordX0, coordY0, coordX1, coordY1;
    uint32_t bc4X0, bc4Y0, bc4X1, bc4Y1;
    uint32_t bc4Y, bc4X;

    if (!viewW || !viewH || !image) return SequentialTexture_Ok;

    tileX0 = (textureX * textureResolution) >> lodShift;
    tileY0 = (textureY * textureResolution) >> lodShift;
    tileX1 = ((textureX + 1) * textureResolution) >> lodShift;
    tileY1 = ((textureY + 1) * textureResolution) >> lodShift;
    textureSize = textureResolution >> lodShift;
    if (!textureSize) return SequentialTexture_Ok;

    coordX0 = viewX > tileX0 ? viewX : tileX0;
    coordY0 = viewY > tileY0 ? viewY : tileY0;
    coordX1 = (viewX + viewW) < tileX1 ? (viewX + viewW) : tileX1;
    coordY1 = (viewY + viewH) < tileY1 ? (viewY + viewH) : tileY1;
    if (coordX1 <= coordX0 || coordY1 <= coordY0) return SequentialTexture_Ok;

    bc4Size = textureSize >> 2;
    if (!bc4Size) return SequentialTexture_Ok;

    bc4X0 = (coordX0 - tileX0) >> 2;
    bc4Y0 = (coordY0 - tileY0) >> 2;
    bc4X1 = ((coordX1 - tileX0 - 1) >> 2) + 1;
    bc4Y1 = ((coordY1 - tileY0 - 1) >> 2) + 1;

    for (bc4Y = bc4Y0; bc4Y < bc4Y1; ++bc4Y)
    {
        for (bc4X = bc4X0; bc4X < bc4X1; ++bc4X)
        {
            uint32_t bc4Index = lowerTriangular ? ((bc4X * bc4Size) + bc4Y) : ((bc4Y * bc4Size) + bc4X);
            uint32_t maxBc4Index = bc4Size * bc4Size;
            const uint8_t *bc4BlockData;
            struct bc4_block bc4Block;
            uint32_t bc4TexelX0, bc4TexelY0, bc4TexelX1, bc4TexelY1;
            uint32_t texelX, texelY, texelEndX, texelEndY;
            uint32_t y, x;

            if (bc4Index >= maxBc4Index) continue;
            if ((bc4Index << 3) + 8 > mipBytes) return SequentialTexture_Range;
            bc4BlockData = mip + (bc4Index << 3);
            FillBC4Block(&bc4Block, bc4BlockData);

            bc4TexelX0 = (bc4X << 2) + tileX0;
            bc4TexelY0 = (bc4Y << 2) + tileY0;
            bc4TexelX1 = ((bc4X + 1) << 2) + tileX0;
            bc4TexelY1 = ((bc4Y + 1) << 2) + tileY0;

            texelX = coordX0 > bc4TexelX0 ? coordX0 : bc4TexelX0;
            texelY = coordY0 > bc4TexelY0 ? coordY0 : bc4TexelY0;
            texelEndX = coordX1 < bc4TexelX1 ? coordX1 : bc4TexelX1;
            texelEndY = coordY1 < bc4TexelY1 ? coordY1 : bc4TexelY1;

            for (y = (texelY & 3); y < 4 && texelY < texelEndY; ++y, ++texelY)
            {
                uint32_t rowTexelX = texelX;
                for (x = (texelX & 3); x < 4 && rowTexelX < texelEndX; ++x, ++rowTexelX)
                {
                    uint8_t sampleX = lowerTriangular ? (uint8_t)y : (uint8_t)x;
                    uint8_t sampleY = lowerTriangular ? (uint8_t)x : (uint8_t)y;
                    uint32_t imX = rowTexelX - viewX;
                    uint32_t imY = texelY - viewY;
                    uint32_t pix;

                    if (imX >= pitch || imY >= viewH) return SequentialTexture_Range;
                    pix = (imY * pitch) + imX;
                    if (pix >= limit) return SequentialTexture_Range;
                    image[pix] = GetBC4ValueAt(&bc4Block, sampleX, sampleY);
                }
            }
        }
    }

    return SequentialTexture_Ok;
}

static uint32_t
SplatBlock(const uint8_t *texture, const struct sequential_map_layout *map, const struct sequential_lod_window *window,
           uint32_t texX, uint32_t texY)
{
    uint32_t offset = 0;
    uint32_t bytesPerLod = map->textureResolution * (map->textureResolution >> 1);
    uint32_t level;
    const uint8_t *mip0;
    uint32_t status;

    for (level = 0; level < window->lodLevel; ++level)
    {
        if (map->bytesPerTexture - offset < bytesPerLod) return SequentialTexture_Decompress;
        offset += bytesPerLod;
        bytesPerLod >>= 2;
    }
    if (map->bytesPerTexture - offset < bytesPerLod) return SequentialTexture_Decompress;
    mip0 = texture + offset;

    status = SplatOneLod(mip0, bytesPerLod, texX, texY, 0, map->textureResolution, window->lodLevel,
                         window->start0X, window->start0Y, window->range0X, window->range0Y,
                         window->image0, window->pitch0, window->limit0);
    if (status) return status;
    if (texX != texY)
    {
        status = SplatOneLod(mip0, bytesPerLod, texY, texX, 1, map->textureResolution, window->lodLevel,
                             window->start0X, window->start0Y, window->range0X, window->range0Y,
                             window->image0, window->pitch0, window->limit0);
        if (status) return status;
    }

    if (window->fillTwoImageBuffers)
    {
        uint32_t nextBytes = bytesPerLod >> 2;
        const uint8_t *mip1 = mip0 + bytesPerLod;

        if ((uint32_t)(mip1 - texture) > map->bytesPerTexture || map->bytesPerTexture - (uint32_t)(mip1 - texture) < nextBytes)
        {
            return SequentialTexture_Decompress;
        }
        status = SplatOneLod(mip1, nextBytes, texX, texY, 0, map->textureResolution, window->lodLevel + 1,
                             window->start1X, window->start1Y, window->range1X, window->range1Y,
                             window->image1, window->pitch1, window->limit1);
        if (status) return status;
        if (texX != texY)
        {
            status = SplatOneLod(mip1, nextBytes, texY, texX, 1, map->textureResolution, window->lodLevel + 1,
                                 window->start1X, window->start1Y, window->range1X, window->range1Y,
                                 window->image1, window->pitch1, window->limit1);
            if (status) return status;
        }
    }

    return SequentialTexture_Ok;
}

struct load_slot
{
    uint8_t *data;
    uint32_t nBytes;
    uint32_t texX;
    uint32_t texY;
    int32_t next;
};

struct load_pipeline
{
    struct load_slot *slots;
    int32_t freeHead;
    int32_t readyHead;
    int32_t readyTail;
    int done;
    int error;
    const struct sequential_map_layout *map;
    const struct sequential_lod_window *window;
    uint8_t *textures;
    struct libdeflate_decompressor **decompressors;
#ifndef _WIN32
    pthread_mutex_t mu;
    pthread_cond_t ready;
    pthread_cond_t space;
#else
    CRITICAL_SECTION mu;
    CONDITION_VARIABLE ready;
    CONDITION_VARIABLE space;
#endif
};

static void
PipelineInit(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_mutex_init(&pipe->mu, NULL);
    pthread_cond_init(&pipe->ready, NULL);
    pthread_cond_init(&pipe->space, NULL);
#else
    InitializeCriticalSection(&pipe->mu);
    InitializeConditionVariable(&pipe->ready);
    InitializeConditionVariable(&pipe->space);
#endif
}

static void
PipelineDestroy(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_cond_destroy(&pipe->space);
    pthread_cond_destroy(&pipe->ready);
    pthread_mutex_destroy(&pipe->mu);
#else
    DeleteCriticalSection(&pipe->mu);
#endif
}

static void
PipelineLock(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_mutex_lock(&pipe->mu);
#else
    EnterCriticalSection(&pipe->mu);
#endif
}

static void
PipelineUnlock(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_mutex_unlock(&pipe->mu);
#else
    LeaveCriticalSection(&pipe->mu);
#endif
}

static void
PipelineBroadcast(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_cond_broadcast(&pipe->ready);
    pthread_cond_broadcast(&pipe->space);
#else
    WakeAllConditionVariable(&pipe->ready);
    WakeAllConditionVariable(&pipe->space);
#endif
}

static void
PipelineWaitReady(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_cond_wait(&pipe->ready, &pipe->mu);
#else
    SleepConditionVariableCS(&pipe->ready, &pipe->mu, INFINITE);
#endif
}

static void
PipelineWaitSpace(struct load_pipeline *pipe)
{
#ifndef _WIN32
    pthread_cond_wait(&pipe->space, &pipe->mu);
#else
    SleepConditionVariableCS(&pipe->space, &pipe->mu, INFINITE);
#endif
}

static void
PipelineSetError(struct load_pipeline *pipe, uint32_t code)
{
    PipelineLock(pipe);
    if (!pipe->error) pipe->error = (int)code;
    PipelineBroadcast(pipe);
    PipelineUnlock(pipe);
}

static int
ReserveSlot(struct load_pipeline *pipe, int32_t *slotIndex)
{
    PipelineLock(pipe);
    while (pipe->freeHead < 0 && !pipe->error) PipelineWaitSpace(pipe);
    if (pipe->error)
    {
        PipelineUnlock(pipe);
        return 0;
    }
    *slotIndex = pipe->freeHead;
    pipe->freeHead = pipe->slots[*slotIndex].next;
    PipelineUnlock(pipe);
    return 1;
}

static void
PublishSlot(struct load_pipeline *pipe, int32_t slotIndex)
{
    PipelineLock(pipe);
    pipe->slots[slotIndex].next = -1;
    if (pipe->readyTail < 0)
    {
        pipe->readyHead = slotIndex;
        pipe->readyTail = slotIndex;
    }
    else
    {
        pipe->slots[pipe->readyTail].next = slotIndex;
        pipe->readyTail = slotIndex;
    }
#ifndef _WIN32
    pthread_cond_signal(&pipe->ready);
#else
    WakeConditionVariable(&pipe->ready);
#endif
    PipelineUnlock(pipe);
}

static int
PopSlot(struct load_pipeline *pipe, int32_t *slotIndex)
{
    PipelineLock(pipe);
    while (pipe->readyHead < 0 && !pipe->done && !pipe->error) PipelineWaitReady(pipe);
    if (pipe->error || pipe->readyHead < 0)
    {
        PipelineUnlock(pipe);
        return 0;
    }
    *slotIndex = pipe->readyHead;
    pipe->readyHead = pipe->slots[*slotIndex].next;
    if (pipe->readyHead < 0) pipe->readyTail = -1;
    PipelineUnlock(pipe);
    return 1;
}

static void
ReleaseSlot(struct load_pipeline *pipe, int32_t slotIndex)
{
    PipelineLock(pipe);
    pipe->slots[slotIndex].next = pipe->freeHead;
    pipe->freeHead = slotIndex;
#ifndef _WIN32
    pthread_cond_signal(&pipe->space);
#else
    WakeConditionVariable(&pipe->space);
#endif
    PipelineUnlock(pipe);
}

struct worker_start
{
    struct load_pipeline *pipe;
    uint32_t workerIndex;
};

#ifndef _WIN32
static void *
#else
static DWORD WINAPI
#endif
WorkerMain(void *arg)
{
    struct worker_start *start = (struct worker_start *)arg;
    struct load_pipeline *pipe = start->pipe;
    uint8_t *texture = pipe->textures + ((uint64_t)start->workerIndex * pipe->map->bytesPerTexture);
    struct libdeflate_decompressor *decompressor = pipe->decompressors[start->workerIndex];
    int32_t slotIndex;

    while (PopSlot(pipe, &slotIndex))
    {
        struct load_slot *slot = pipe->slots + slotIndex;
        enum libdeflate_result inflated;
        uint32_t status;

        inflated = libdeflate_deflate_decompress(decompressor, slot->data, slot->nBytes, texture, pipe->map->bytesPerTexture, NULL);
        if (inflated != LIBDEFLATE_SUCCESS)
        {
            ReleaseSlot(pipe, slotIndex);
            PipelineSetError(pipe, SequentialTexture_Decompress);
            break;
        }
        status = SplatBlock(texture, pipe->map, pipe->window, slot->texX, slot->texY);
        ReleaseSlot(pipe, slotIndex);
        if (status)
        {
            PipelineSetError(pipe, status);
            break;
        }
    }

#ifndef _WIN32
    return NULL;
#else
    return 0;
#endif
}

static int
SeekAbsolute(FILE *file, uint64_t offset)
{
#ifdef _WIN32
    return _fseeki64(file, (__int64)offset, SEEK_SET) == 0;
#else
    return fseeko(file, (off_t)offset, SEEK_SET) == 0;
#endif
}

static int
ReadExact(FILE *file, void *dst, size_t nBytes)
{
    return fread(dst, 1, nBytes, file) == nBytes;
}

static int
DiscardExact(FILE *file, uint64_t nBytes, uint8_t *scratch, uint32_t scratchBytes)
{
    while (nBytes)
    {
        size_t chunk = nBytes > scratchBytes ? scratchBytes : (size_t)nBytes;
        if (!ReadExact(file, scratch, chunk)) return 0;
        nBytes -= chunk;
    }
    return 1;
}

static void
AdviseSequential(FILE *file)
{
#ifndef _WIN32
    int fd = fileno(file);
    if (fd < 0) return;
#if defined(__APPLE__)
    fcntl(fd, F_RDAHEAD, 1);
#elif defined(POSIX_FADV_SEQUENTIAL)
    posix_fadvise(fd, 0, 0, POSIX_FADV_SEQUENTIAL);
#else
    (void)fd;
#endif
#else
    (void)file;
#endif
}

static uint8_t gDiscardScratch[1 << 20];

uint32_t
SequentialDiscard(FILE *file, uint64_t nBytes)
{
    if (!file) return SequentialTexture_Io;
    if (!DiscardExact(file, nBytes, gDiscardScratch, (uint32_t)sizeof(gDiscardScratch))) return SequentialTexture_Io;
    return SequentialTexture_Ok;
}

static int
AtlasIsPacked(const struct file_atlas_entry *atlas, uint32_t nBlocks, uint32_t bytesPerTexture)
{
    uint32_t index;
    uint32_t maxBytes = bytesPerTexture + Sequential_Compression_Header_Size;

    if (!nBlocks) return 1;
    if (!atlas[0].nBytes || atlas[0].nBytes > maxBytes) return 0;
    for (index = 1; index < nBlocks; ++index)
    {
        uint64_t next = atlas[index - 1].base + (uint64_t)atlas[index - 1].nBytes + 4ull;
        if (!atlas[index].nBytes || atlas[index].nBytes > maxBytes) return 0;
        if (next != atlas[index].base) return 0;
    }
    return 1;
}

uint32_t
SequentialFillLodImage(const struct sequential_map_layout *map, const struct sequential_lod_window *window)
{
    uint32_t nThreads;
    uint32_t nSlots;
    uint32_t slotCap;
    uint32_t result = SequentialTexture_Ok;
    uint32_t expectBlocks;
    uint64_t slotBytes64;
    uint64_t textureBytes64;
    struct load_pipeline pipe;
    struct worker_start starts[Sequential_Max_Workers];
#ifndef _WIN32
    pthread_t threads[Sequential_Max_Workers];
#else
    HANDLE threads[Sequential_Max_Workers];
#endif
    uint32_t nStarted = 0;
    uint32_t index;
    FILE *file = NULL;
    char *ioBuffer = NULL;
    uint8_t *slotStorage = NULL;
    uint8_t *discard = NULL;
    int syncReady = 0;
    uint32_t texX;
    uint32_t texY;
    uint32_t block;

    if (!map || !window || !map->path || !map->atlas || !map->nBlocks || !map->numberOfTextures1D || !map->textureResolution || !map->bytesPerTexture)
    {
        return SequentialTexture_Format;
    }
    if (!window->image0 || !window->pitch0 || !window->range0X || !window->range0Y)
    {
        return SequentialTexture_Format;
    }
    if (window->fillTwoImageBuffers && (!window->image1 || !window->pitch1 || !window->range1X || !window->range1Y))
    {
        return SequentialTexture_Format;
    }

    expectBlocks = (map->numberOfTextures1D + 1u) * (map->numberOfTextures1D >> 1);
    if (map->nBlocks != expectBlocks) return SequentialTexture_NotPacked;
    if (!AtlasIsPacked(map->atlas, map->nBlocks, map->bytesPerTexture)) return SequentialTexture_NotPacked;

    nThreads = map->nThreads ? map->nThreads : 4;
    if (nThreads > Sequential_Max_Workers) nThreads = Sequential_Max_Workers;
    nSlots = nThreads * 2;
    slotCap = map->bytesPerTexture + Sequential_Compression_Header_Size;

    memset(&pipe, 0, sizeof(pipe));
    pipe.freeHead = -1;
    pipe.readyHead = -1;
    pipe.readyTail = -1;
    pipe.map = map;
    pipe.window = window;
    pipe.slots = (struct load_slot *)calloc(nSlots, sizeof(struct load_slot));
    pipe.decompressors = (struct libdeflate_decompressor **)calloc(nThreads, sizeof(struct libdeflate_decompressor *));
    slotBytes64 = (uint64_t)nSlots * (uint64_t)slotCap;
    textureBytes64 = (uint64_t)nThreads * (uint64_t)map->bytesPerTexture;
    if (!pipe.slots || !pipe.decompressors || slotBytes64 / nSlots != slotCap)
    {
        result = SequentialTexture_Memory;
        goto cleanup;
    }
    slotStorage = (uint8_t *)malloc((size_t)slotBytes64);
    pipe.textures = (uint8_t *)malloc((size_t)textureBytes64);
    discard = (uint8_t *)malloc(slotCap);
    if (!slotStorage || !pipe.textures || !discard)
    {
        result = SequentialTexture_Memory;
        goto cleanup;
    }
    for (index = 0; index < nSlots; ++index)
    {
        pipe.slots[index].data = slotStorage + ((uint64_t)index * slotCap);
        pipe.slots[index].next = pipe.freeHead;
        pipe.freeHead = (int32_t)index;
    }
    for (index = 0; index < nThreads; ++index)
    {
        pipe.decompressors[index] = libdeflate_alloc_decompressor();
        if (!pipe.decompressors[index])
        {
            result = SequentialTexture_Memory;
            goto cleanup;
        }
    }

    PipelineInit(&pipe);
    syncReady = 1;

    file = fopen(map->path, "rb");
    if (!file)
    {
        result = SequentialTexture_Io;
        goto cleanup;
    }
    ioBuffer = (char *)malloc(8u << 20);
    if (ioBuffer) setvbuf(file, ioBuffer, _IOFBF, 8u << 20);
    AdviseSequential(file);
    if (!SeekAbsolute(file, map->atlas[0].base))
    {
        result = SequentialTexture_Io;
        goto cleanup;
    }

    for (index = 0; index < nThreads; ++index)
    {
        starts[index].pipe = &pipe;
        starts[index].workerIndex = index;
#ifndef _WIN32
        if (pthread_create(threads + index, NULL, WorkerMain, starts + index) != 0)
#else
        threads[index] = CreateThread(NULL, 0, WorkerMain, starts + index, 0, NULL);
        if (!threads[index])
#endif
        {
            result = SequentialTexture_Memory;
            goto cleanup;
        }
        ++nStarted;
    }

    texX = 0;
    texY = 0;
    for (block = 0; block < map->nBlocks; ++block)
    {
        uint32_t nBytes = map->atlas[block].nBytes;

        if (texY >= map->numberOfTextures1D)
        {
            result = SequentialTexture_Format;
            goto cleanup;
        }
        if (BlockHits(texX, texY, map, window))
        {
            int32_t slotIndex;
            if (!ReserveSlot(&pipe, &slotIndex))
            {
                result = pipe.error ? (uint32_t)pipe.error : SequentialTexture_Io;
                goto cleanup;
            }
            if (!ReadExact(file, pipe.slots[slotIndex].data, nBytes))
            {
                ReleaseSlot(&pipe, slotIndex);
                result = SequentialTexture_Io;
                goto cleanup;
            }
            pipe.slots[slotIndex].nBytes = nBytes;
            pipe.slots[slotIndex].texX = texX;
            pipe.slots[slotIndex].texY = texY;
            PublishSlot(&pipe, slotIndex);
        }
        else if (!DiscardExact(file, nBytes, discard, slotCap))
        {
            result = SequentialTexture_Io;
            goto cleanup;
        }

        if (block + 1 < map->nBlocks)
        {
            uint32_t onDisk = 0;
            if (!ReadExact(file, &onDisk, 4))
            {
                result = SequentialTexture_Io;
                goto cleanup;
            }
            if (onDisk != map->atlas[block + 1].nBytes)
            {
                result = SequentialTexture_Format;
                goto cleanup;
            }
        }

        ++texX;
        if (texX == map->numberOfTextures1D)
        {
            ++texY;
            texX = texY;
        }
    }

cleanup:
    if (syncReady)
    {
        PipelineLock(&pipe);
        pipe.done = 1;
        if (result != SequentialTexture_Ok && !pipe.error) pipe.error = (int)result;
        PipelineBroadcast(&pipe);
        PipelineUnlock(&pipe);
    }
    for (index = 0; index < nStarted; ++index)
    {
#ifndef _WIN32
        pthread_join(threads[index], NULL);
#else
        WaitForSingleObject(threads[index], INFINITE);
        CloseHandle(threads[index]);
#endif
    }
    if (result == SequentialTexture_Ok && pipe.error) result = (uint32_t)pipe.error;

    if (file) fclose(file);
    free(ioBuffer);
    free(discard);
    free(slotStorage);
    free(pipe.textures);
    if (pipe.decompressors)
    {
        for (index = 0; index < nThreads; ++index)
        {
            if (pipe.decompressors[index]) libdeflate_free_decompressor(pipe.decompressors[index]);
        }
    }
    free(pipe.decompressors);
    free(pipe.slots);
    if (syncReady) PipelineDestroy(&pipe);
    return result;
}
