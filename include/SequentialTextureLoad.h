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

/*
Sequential texture load for large Pretext snapshots.

A .pretext texture section stores the upper triangle, including the diagonal,
as contiguous records: uint32 byte count, then a raw deflate payload. The
contact map is symmetric, so (x, y) and (y, x) share one record.

FillImage's per-tile path seeks to every cell. On a high-resolution map that
is one random read per cell, and each off-diagonal record is inflated twice.
SequentialFillLodImage reads the section from the first payload to the last,
inflates each record once, and writes both triangles. The coarse mip sits at
the end of that deflate stream, so the whole record is still inflated.

Use this when the snapshot covers most of the texture grid. A small window
should keep the seeking path: a sequential pass would read records the window
never displays.
*/

#ifndef SEQUENTIAL_TEXTURE_LOAD_H
#define SEQUENTIAL_TEXTURE_LOAD_H

#include <stdint.h>
#include <stdio.h>

struct file_atlas_entry
{
    uint64_t base;
    uint32_t nBytes;
};

enum
{
    SequentialTexture_Ok = 0,
    SequentialTexture_Io = 1,
    SequentialTexture_Format = 2,
    SequentialTexture_Decompress = 3,
    SequentialTexture_Memory = 4,
    /* Bases are not contiguous, so the caller can keep the seeking loader. */
    SequentialTexture_NotPacked = 5,
    SequentialTexture_Range = 6
};

/* Read and discard nBytes. Does not seek. Safe to call from one thread. */
uint32_t
SequentialDiscard(FILE *file, uint64_t nBytes);

/*
True when the window is large enough that one sequential pass is cheaper than
seeking to each cell. textureEnd is exclusive.
*/
static inline uint32_t
SequentialFillPreferred(uint32_t textureStartX, uint32_t textureEndX,
                        uint32_t textureStartY, uint32_t textureEndY,
                        uint32_t numberOfTextures1D)
{
    uint32_t spanX;
    uint32_t spanY;
    uint64_t covered;
    uint64_t all;

    if (numberOfTextures1D < 32) return 0;
    if (textureEndX <= textureStartX || textureEndY <= textureStartY) return 0;
    spanX = textureEndX - textureStartX;
    spanY = textureEndY - textureStartY;
    covered = (uint64_t)spanX * (uint64_t)spanY;
    all = (uint64_t)numberOfTextures1D * (uint64_t)numberOfTextures1D;
    return covered >= 4096 && covered * 2 >= all;
}

/*
LOD images are tightly packed, one byte per texel, row-major.
image0 receives mip lodLevel. image1 receives lodLevel + 1 when fillTwoImageBuffers is set.
Coordinates are in that mip's texel space. range is the width and height.
pitch is the row stride in bytes. limit is the number of addressable bytes from the image pointer.
*/
struct sequential_lod_window
{
    uint8_t *image0;
    uint8_t *image1;
    uint32_t lodLevel;
    uint32_t fillTwoImageBuffers;
    uint32_t start0X, range0X, start0Y, range0Y;
    uint32_t start1X, range1X, start1Y, range1Y;
    uint32_t pitch0;
    uint32_t pitch1;
    uint32_t limit0;
    uint32_t limit1;
};

struct sequential_map_layout
{
    const char *path;
    const struct file_atlas_entry *atlas;
    uint32_t nBlocks;
    uint32_t numberOfTextures1D;
    uint32_t textureResolution;
    uint32_t bytesPerTexture;
    uint32_t nThreads;
};

uint32_t
SequentialFillLodImage(const struct sequential_map_layout *map, const struct sequential_lod_window *window);

#endif
