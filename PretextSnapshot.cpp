/*
Copyright (c) 2019 Ed Harry, Wellcome Sanger Institute

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

#define my_String_(x) #x
#define my_String(x) my_String_(x)

#define PretextSnapshot_Version "PretextSnapshot Version " my_String(PV)

#include "Header.h"
#include "ColourMapData.cpp"

global_variable
u08
Licence[] = R"lic(
Copyright (c) 2019 Ed Harry, Wellcome Sanger Institute

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
)lic";

global_variable
u08
ThirdParty[] = R"thirdparty(
Third-party software and resources used in this project, along with their respective licenses:

	AVIR image resizing algorithm designed by Aleksey Vaneev (https://github.com/avaneev/avir) 
	   Copyright (c) 2015-2019 Aleksey Vaneev
	   
	   Permission is hereby granted, free of charge, to any person obtaining a
	   copy of this software and associated documentation files (the "Software"),
	   to deal in the Software without restriction, including without limitation
	   the rights to use, copy, modify, merge, publish, distribute, sublicense,
	   and/or sell copies of the Software, and to permit persons to whom the
	   Software is furnished to do so, subject to the following conditions:
	   
	   The above copyright notice and this permission notice shall be included in
	   all copies or substantial portions of the Software.
	   
	   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
	   DEALINGS IN THE SOFTWARE.


	avx_mathfun.h (http://software-lisc.fbk.eu/avx_mathfun/)
	  Copyright (C) 2012 Giovanni Garberoglio
	  Interdisciplinary Laboratory for Computational Science (LISC)
	  Fondazione Bruno Kessler and University of Trento
	  via Sommarive, 18
	  I-38123 Trento (Italy)

	  This software is provided 'as-is', without any express or implied
	  warranty.  In no event will the authors be held liable for any damages
	  arising from the use of this software.

	  Permission is granted to anyone to use this software for any purpose,
	  including commercial applications, and to alter it and redistribute it
	  freely, subject to the following restrictions:

	  1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation would be
		appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.

	  (this is the zlib license)


	sse_mathfun.h (http://gruntthepeon.free.fr/ssemath/sse_mathfun.h)
	  Copyright (C) 2007  Julien Pommier

	  This software is provided 'as-is', without any express or implied
	  warranty.  In no event will the authors be held liable for any damages
	  arising from the use of this software.

	  Permission is granted to anyone to use this software for any purpose,
	  including commercial applications, and to alter it and redistribute it
	  freely, subject to the following restrictions:

	  1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation would be
		appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.

	  (this is the zlib license)


	kgetopt.h (https://github.com/attractivechaos/klib/blob/master/ketopt.h)
		Distributed under MIT/X11 license (http://en.wikipedia.org/wiki/MIT_License)


	libdeflate (https://github.com/ebiggers/libdeflate)
	  Copyright 2016 Eric Biggers

	  Permission is hereby granted, free of charge, to any person
	  obtaining a copy of this software and associated documentation files
	  (the "Software"), to deal in the Software without restriction,
	  including without limitation the rights to use, copy, modify, merge,
	  publish, distribute, sublicense, and/or sell copies of the Software,
	  and to permit persons to whom the Software is furnished to do so,
	  subject to the following conditions:

	  The above copyright notice and this permission notice shall be
	  included in all copies or substantial portions of the Software.

	  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
	  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
	  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	  SOFTWARE.


	mpc (https://github.com/orangeduck/mpc)
	  Licensed Under BSD

	  Copyright (c) 2013, Daniel Holden All rights reserved.

	  Redistribution and use in source and binary forms, with or without
          modification, are permitted provided that the following conditions are met:

	  Redistributions of source code must retain the above copyright notice, 
          this list of conditions and the following disclaimer.
	  Redistributions in binary form must reproduce the above copyright notice, 
          this list of conditions and the following disclaimer in the documentation 
          and/or other materials provided with the distribution.
	  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
          AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
          IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
          ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE 
          FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
          (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
          LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
          ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
          (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
          THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	  The views and conclusions contained in the software and documentation are those of 
          the authors and should not be interpreted as representing official policies, either 
          expressed or implied, of the FreeBSD Project.

	
	stb_image_write.h (https://github.com/nothings/stb/blob/master/stb_image_write.h)
	  ALTERNATIVE B - Public Domain (www.unlicense.org)
	  This is free and unencumbered software released into the public domain.
	  Anyone is free to copy, modify, publish, use, compile, sell, or distribute this 
	  software, either in source code form or as a compiled binary, for any purpose, 
	  commercial or non-commercial, and by any means.
	  In jurisdictions that recognize copyright laws, the author or authors of this 
	  software dedicate any and all copyright interest in the software to the public 
	  domain. We make this dedication for the benefit of the public at large and to 
	  the detriment of our heirs and successors. We intend this dedication to be an 
	  overt act of relinquishment in perpetuity of all present and future rights to 
	  this software under copyright law.
	  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
	  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
	  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
	  AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN 
	  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
	  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


	stb_sprintf.h (https://github.com/nothings/stb/blob/master/stb_sprintf.h)
	  ALTERNATIVE B - Public Domain (www.unlicense.org)
	  This is free and unencumbered software released into the public domain.
	  Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
	  software, either in source code form or as a compiled binary, for any purpose,
	  commercial or non-commercial, and by any means.
	  In jurisdictions that recognize copyright laws, the author or authors of this
	  software dedicate any and all copyright interest in the software to the public
	  domain. We make this dedication for the benefit of the public at large and to
	  the detriment of our heirs and successors. We intend this dedication to be an
	  overt act of relinquishment in perpetuity of all present and future rights to
	  this software under copyright law.
	  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	  AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
	  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
	  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
)thirdparty";

global_variable
u08
Help[] = R"help(
PretextSnapshot, an image generator for pretext contact maps.

Nomenclature:
      Texel:    A single image unit of the underlying pretext map.
      Pixel:    A single image unit of the output image(s).

Usage:
      PretextSnapshot [Options]

Options:
         --help:                Print this help message.
                                Cannot be used with any other option.
         
         -m/--map mp:           Path to a pretext map.
                                This option is required, except when using:
                                 --help,
                                 --sequenceHelp,
			         --printColourMapNames,
			         --version,
			         --licence,
			         --thirdParty

	-f/--format fmt:        Image format, one of "png"(default) "bmp" or "jpeg".

	-r/--resolution res:	Image resolution, a positive integer, default 1080.
			        For non-square images this will be the resolution
                                of the longest dimension.

	-c/--colourMap cmap:	Either, a non-negative integer, indexing the colour map to use.
			        Or, the name of the colour map to use.
			        Defaults to "Three Wave Blue-Green-Yellow" i.e. "8".

	--printColourMapNames:	Prints a list of the available colour maps.
			        Cannot be used with any other option. 

	--jpegQuality qual:	JPEG quality factor, an integer between 1 and 100, default 80.
			        Larger values result in increased image quality and file size.
			        Only applicable to JPEG images.

	-o/--folder fldr:	Output folder path, will be created if it doesn't exist.
			        Defaults to the name of the pretext map.

	--prefix pfx:		Prefix name for all image files.
			        Defaults to the name of the pretext map + "_".

	--sequences sqncs:	Sequence specification string. Each entry, except for "=all", corresponds to one output image.
			        Defaults to "=full, =all".

	--sequenceHelp:		Sequence specification string format documentation.
			        Cannot be used with any other option.

	--minTexels txls:       Minimum map texels per image (along a single dimension), a positive integer, default 64.
			        Output images over too small a range that violate this minimum will not be created.

	--gridSize grdSz:	Width in pixels of the sequence separation grid, a non-negative integer, default 1.
			        Set to 0 to not overlay a grid.

	--gridColour col:	Colour of the sequence separation grid.
			        Either, one of: "black"(default), "white", "red", "green", "blue", "yellow", "cyan" or "magenta".
			        Or, a sRGBA 32-bit hex code in RRGGBBAA format, e.g. "ff00ff80" (magenta at half-occupancy).

	--printSequenceNames:	Prints a list of the individual sequence names in the map, in order of appearance.
			        Can only be used with the -m/--map option.

	--verbose vrbs:		Verbosity level, one of: "3"(default) for error, warning and status messages.
							 "2" for error and warning messages.
							 "1" for error messages.
							 "0" for no messages.
			        Warning and status messages are printed to stdout, error messages to stderr.

	--version:		Prints the software version.
			        Cannot be used with any other option.

	--licence:		Prints the software licence.
			        Cannot be used with any other option.

	--thirdParty:		Prints a list of the third-party libraries used, along with their respective licences.
			        Cannot be used with any other option.
)help";

global_variable
u08
Seq_Help[] = R"seqhelp(
PretextSnapshot, sequence specification string format.

Nomenclature:
      Texel: 	    A single image unit of the underlying pretext map.
      Pixel:	    A single image unit of the output image(s).
      x-dimension:  The horizontal dimension of the contact maps and output images.
		    Runs from left-to-right (zero on the left-hand edge). 
      y-dimension:  The vertical dimension of the contact maps and output images.
		    Runs from top-to-bottom (zero on the top edge).

A comma separated list of entries. Each entry, except for "=all", corresponds with one output image.
"<entry> [, <entry>]*" in regex notation.


Each <entry> is either:
	one of the two strings "=full" or "=all"
	a <range>
	or a pair of comma separated <range>s enclosed in curly-brackets, { <range>, <range> }

"=full": specifies the whole contact map.

"=all": creates an image of each sequence in the contact map.

A single <range> specifies a single range of coordinates.
These coordinates are taken over both the x and y dimensions of the contact map,
resulting in a symmetric, square image, centred on the main diagonal.

A pair of <range>s specifies a pair of coordinate ranges over the x and y dimensions respectively,
{ <range>-x, <range-y>}. The resulting image can therefore be of any region of the contact map.


Each <range> is a <startCoord> with a conditionally optional <endCoord>,
separated by a ">".
"<startCoord> [\> <endCoord>]?" in regex notation.

Each <startCoord> and <endCoord> is a <name> with an optional <bpCoord>
enclosed in square-brackets.
"<name> [ \[<bpCoord>\] ]?" in regex notation.

Each <name> is the name of a sequence in the contact map.
Each <bpCoord> is a non-negative integer, specifying a base-pair coordinate,
relative to the corresponding sequence.

If a <bpCoord> is not specified, the coordinate is taken as 0 in the case of a <startCoord>
and the length of the sequence in the case of an <endCoord>.

Additionally, if a <bpCoord> is not specified in a <startCoord>, the <endCoord> of the <range>
can be omitted, and is taken as the same sequence as the <startCoord>.

Within a <range>, <startCoord> must be less than <endCoord>.
Meaning that <name> in <startCoord> must either:
	Occur before the <name> in <endCoord> in the map,
	Or be the same as the <name> in <endCoord> and the <bpCoord> of <startCoord>
        must be less than the <bpCoord> of <endCoord>.


Note that all <bpCoord> values will be taken to the nearest appropriate texel,
based on the base-pair resolution of the map.

Note that all images are subject to the minTexel constraint,
including all the sequence images implied by "=all".

The sequence string is insensitive to white-space.


Examples: 

	--sequences "=full"

	Creates a single image of the full contact map.


	--sequences "=full, =all"

	Creates an image of the full contact map, plus an image of each sequence.


	--sequences "seq_0"

	Creates a single image of the sequence named "seq_0"


	--sequences "seq_0, seq_1 > seq_2"

	Creates an image of seq_0, and an image from the start of seq_1 to the end of seq_2


	--sequences "seq_0[1000000] > seq_3"

	Creates an image starting 1Mbp into seq_0, ending at the end of seq_3


	--sequences "{seq_0, seq_1}"

	Create an single image of the off-diagonal region between seq_0 and seq_1,
        i.e. the inter-sequence map of seq_0 and seq_1.


	--sequences "{seq_2[2000000] > seq_4[1000000] , seq_0[3000000] > seq_1[4000000]} , seq_0 > seq_10"

	Creates two images. The first is the off-diagonal region between 2Mbp into seq_2 and 1Mbp
        into seq_4 along the x-dimension, and 3Mbp into seq_0 and 4Mbp into seq_1 along the y-dimension.
	The second image is the diagonal region between the start of seq_0 and the end of seq_10. 
)seqhelp";

enum
verbose_level
{
   status = 3,
   warnings = 2,
   errors = 1,
   none = 0,
};

global_variable
verbose_level
Verbose_Level = status;

global_variable
u08
Status_Marco_Expression_Sponge = 0;

global_variable
char
Message_Buffer[1024];

#define PrintError(message, ...) if (Verbose_Level >= (u32)errors) \
{ \
stbsp_snprintf(Message_Buffer, 512, message, ##__VA_ARGS__); \
stbsp_snprintf(Message_Buffer + 512, 512, "[PretextSnapshot error] :: %s\n", Message_Buffer); \
fprintf(stderr, "%s", Message_Buffer + 512); \
} \
Status_Marco_Expression_Sponge = 0

#define PrintStatus(message, ...) if (Verbose_Level == (u32)status) \
{ \
stbsp_snprintf(Message_Buffer, 512, message, ##__VA_ARGS__); \
stbsp_snprintf(Message_Buffer + 512, 512, "[PretextSnapshot status] :: %s\n", Message_Buffer); \
fprintf(stdout, "%s", Message_Buffer + 512); \
} \
Status_Marco_Expression_Sponge = 0

#define PrintWarning(message, ...) if (Verbose_Level >= (u32)warnings) \
{ \
stbsp_snprintf(Message_Buffer, 512, message, ##__VA_ARGS__); \
stbsp_snprintf(Message_Buffer + 512, 512, "[PretextSnapshot warning] :: %s\n", Message_Buffer); \
fprintf(stdout, "%s", Message_Buffer + 512); \
} \
Status_Marco_Expression_Sponge = 0

global_variable
const char *
Messages[] =
{
    "Could not decompress texture from disk",
    "Error writing image",
    "Texture load queue: could not allocate memory for libdeflate decompressors",
    "Texture load queue: could not open input file",
    "__error / warning divide",
    "Texel range too small"
};

#define Texture_Decompress_Error_Message_Index 0
#define Image_Write_Error_Message_Index 1
#define Texture_Load_Queue_Decompress_Error_Message_Index 2
#define Texture_Load_Queue_File_Handle_Error_Message_Index 3

#define Error_Warning_Divide_Message_Index_ 4

#define Texel_Range_Too_Small_Error_Message_Index 5

#include "TextureLoadQueue.cpp"

global_variable
memory_arena
Working_Set;

global_variable
thread_pool *
Thread_Pool;

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wcomma"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include "ketopt.h"
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wreserved-id-macro"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wcast-align"
#pragma GCC diagnostic ignored "-Wextra-semi-stmt"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wconditional-uninitialized"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#define STB_SPRINTF_IMPLEMENTATION
#include "stb_sprintf.h"
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#include "mpc.h"
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wdocumentation"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wweak-vtables"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wcast-align"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wimplicit-float-conversion"
#include "avir.h"

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wdocumentation-unknown-command"
#ifdef UsingAVX
#include "avir_float8_avx.h"
#else
#include "avir_float4_sse.h"
#endif
#pragma clang diagnostic pop

class
avir_thread_pool : public avir::CImageResizerThreadPool
{
    public:
        global_function
            void
            Run_Avir_Workload(void *in)
            {
                CWorkload *workload = (CWorkload *)in;
                workload->process();
            }

        virtual s32
            getSuggestedWorkloadCount() const override
            {
                return(4);
            }

        virtual void
            addWorkload(CWorkload *const workload) override
            {
                _workloads[_workLoadPtr++] = workload;
            }

        virtual void
            startAllWorkloads() override
            {
                u32 n = _workLoadPtr;
                while (n--) ThreadPoolAddTask(Thread_Pool, Run_Avir_Workload, _workloads[n]);
            }

        virtual void
            waitAllWorkloadsToFinish() override
            {
                ThreadPoolWait(Thread_Pool);
            }

        virtual void
            removeAllWorkloads() override
            {
                _workLoadPtr = 0;
            }
        
    private:
        u32 _workLoadPtr = 0;
        CWorkload *_workloads[4];
};

global_variable
avir_thread_pool *
Avir_Thread_Pool;

global_function
void
ResizeImage(u08 *source, u32 sourceWidth, u32 sourceHeight, u08 *destination, u32 destinationWidth, u32 destinationHeight, u32 channels)
{
#ifdef UsingAVX
    const avir :: CImageResizer<avir :: fpclass_float8_dil> ImageResizer(8, 0, avir :: CImageResizerParamsUltra());
#else
    const avir :: CImageResizer<avir :: fpclass_float4> ImageResizer(8, 0, avir :: CImageResizerParamsUltra());
#endif
    avir :: CImageResizerVars avirVars;
    avirVars.ThreadPool = Avir_Thread_Pool;
    avir :: CImageResizerVars *vars = &avirVars;
    ImageResizer.resizeImage(source, sourceWidth, sourceHeight, 0, destination, destinationWidth, destinationHeight, channels, 0, vars);
}

#pragma clang diagnostic pop

global_variable
memory_arena
STB_Memory_Arena;

global_variable
libdeflate_compressor *
STB_Compressor;

global_function
u08 * 
STB_Compress(u08 *data, s32 dataLen, s32 *outLen)
{
    u32 outDataSize = (u32)dataLen + 64;
    u08 *outData = PushArray(STB_Memory_Arena, u08, outDataSize);
    *outLen = (s32)libdeflate_zlib_compress(STB_Compressor, data, (size_t)dataLen, outData, (size_t)outDataSize);
    return(outData);
}

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wreserved-id-macro"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wcast-align"
#pragma GCC diagnostic ignored "-Wextra-semi-stmt"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wconditional-uninitialized"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#define STB_IMAGE_WRITE_STATIC 
#define STB_IMAGE_WRITE_IMPLEMENTATION

#ifndef DEBUG
#define STBIW_ASSERT(x)
#endif

#define STBIW_MALLOC(count) PushArray(STB_Memory_Arena, u08, count)
#define STBIW_REALLOC(x, y) PrintError("realloc called!") 
#define STBIW_FREE(x)

#define STBIW_ZLIB_COMPRESS(data, dataLen, outLen, qual) STB_Compress(data, dataLen, outLen)

#include "stb_image_write.h"
#pragma clang diagnostic pop

enum
image_type
{
    png,
    jpeg,
    bmp
};

global_variable
image_type
Image_Type = png;

global_variable
char *
Image_Type_Names[] = {(char *)"png", (char *)"jpeg", (char *)"bmp"};

#define Image_Type_Name_Index_PNG 0
#define Image_Type_Name_Index_JPEG 1
#define Image_Type_Name_Index_BMP 2

global_function
char *
GetImageTypeName()
{
    char *result;
    
    switch (Image_Type)
    {
        case png:
            result = Image_Type_Names[Image_Type_Name_Index_PNG];
            break;
        case jpeg:
            result = Image_Type_Names[Image_Type_Name_Index_JPEG];
            break;
        case bmp:
            result = Image_Type_Names[Image_Type_Name_Index_BMP];
            break;
    }

    return(result);
}

global_variable
u32
JPEG_Quality = 80;

global_function
u32
WriteImage(const char *outFile, u32 width, u32 height, u32 channels, u08 *image)
{
    ResetMemoryArena(STB_Memory_Arena);
    switch (Image_Type)
    {
        case png:
            return(!stbi_write_png(outFile, (s32)width, (s32)height, (s32)channels, (const void*)image, (s32)(channels * width)));
        case jpeg:
            return(!stbi_write_jpg(outFile, (s32)width, (s32)height, (s32)channels, (const void*)image, (s32)JPEG_Quality));
        case bmp:
            return(!stbi_write_bmp(outFile, (s32)width, (s32)height, (s32)channels, (const void*)image));
    }
}

struct
write_image_thread_data
{
    const char file[1024];
    u32 width;
    u32 height;
    u32 channels;
    u32 pad;
    u08 *image;
    u32 *returnValue;
};

global_function
void
Write_Image_Thread(void *in)
{
    write_image_thread_data *data = (write_image_thread_data *)in;
    const char *file = (const char *)data->file;
    u32 width = data->width;
    u32 height = data->height;
    u32 channels = data->channels;
    u08 *image = data->image;
    u32 *returnValue = data->returnValue;

    *returnValue = WriteImage(file, width, height, channels, image);

    if (!(*returnValue)) {PrintStatus("\'%s\' written to disk", file);}
    else {PrintError("Could not write \'%s\' to disk", file);}
}

global_variable
thread_pool *
Writing_Thread_Pool;

global_variable
write_image_thread_data
Write_Image_Thread_Data = {};

global_variable
u32
Write_Image_Threaded_Return_Value = 0;

global_function
u32
WriteImage_Threaded(const char *outFile, u32 width, u32 height, u32 channels, u08 *image)
{
    FenceIn(ThreadPoolWait(Writing_Thread_Pool));

    if (!Write_Image_Threaded_Return_Value)
    {
        stbsp_snprintf((char *)Write_Image_Thread_Data.file, ArrayCount(Write_Image_Thread_Data.file), "%s.%s", outFile, GetImageTypeName());
        Write_Image_Thread_Data.width = width;
        Write_Image_Thread_Data.height = height;
        Write_Image_Thread_Data.channels = channels;
        Write_Image_Thread_Data.image = image;
        Write_Image_Thread_Data.returnValue = &Write_Image_Threaded_Return_Value;

        ThreadPoolAddTask(Writing_Thread_Pool, Write_Image_Thread, &Write_Image_Thread_Data);
    }

    return(Write_Image_Threaded_Return_Value);
}

global_variable
texture_buffer_queue *
Texture_Buffer_Queue;

global_variable
u32
Bytes_Per_Texture;

#define NumOutputImageBufferGridFillFlags(buffer) (((buffer->outputResolution * buffer->outputResolution) + 7) >> 3)

global_function
u32
CheckPixelBitFlag(u32 pixel_x, u32 pixel_y, u32 resolution_x, volatile u08 *flags)
{
    u32 pixelLinearIndex = (pixel_y * resolution_x ) + pixel_x;
    u32 byte = pixelLinearIndex >> 3;
    u32 bit = pixelLinearIndex & 7;
    return(flags[byte] & (1 << bit));
}

global_function
void
FillPixelBitFlag(u32 pixel_x, u32 pixel_y, u32 resolution_x, volatile u08 *flags)
{
    u32 pixelLinearIndex = (pixel_y * resolution_x ) + pixel_x;
    u32 byte = pixelLinearIndex >> 3;
    u32 bit = pixelLinearIndex & 7;

#ifndef _WIN32
    __atomic_fetch_add(flags + byte, (u08)(1 << bit), 0);
#else
    _InterlockedExchangeAdd8((volatile char *)(flags + byte), (u08)(1 << bit));
#endif
}

struct
output_buffer
{
    u08 *outputImageBuffer[2];
    volatile u08 *outputImageBufferGridFillFlags;
    u08 *lodLowerBuffer;
    u08 *lodLowerResizeBuffer;
    u08 *lodHigherBuffer;
    u08 *lodHigherResizeBuffer;
    u32 outputResolution;
    u32 outputBufferPtr;
};

global_variable
output_buffer *
Output_Buffer;

global_function
u08 *
GetCurrentOutputBuffer(output_buffer *outBuffer)
{
    return(outBuffer->outputImageBuffer[outBuffer->outputBufferPtr]);
}

global_function
u08 *
FilpCurrentOutputBuffer(output_buffer *outBuffer)
{
    u08 *result = GetCurrentOutputBuffer(outBuffer);
    outBuffer->outputBufferPtr = (outBuffer->outputBufferPtr + 1) & 1;
    return(result);
}

struct
contig
{
    u32 name[16];
    f32 fractionalLength;
    f32 previousCumulativeLength;
};

struct
map_properties
{
    contig *contigs;
    u64 totalGenomeLength;
    u32 numberOfContigs;
    u32 textureResolution;
    u32 numberOfTextures1D;
    u32 numberOfMipMaps;
};

global_variable
map_properties *
Map_Properties;

global_function
const s08 *
GetContigName(u32 index)
{
    return((const s08 *)Map_Properties->contigs[index].name);
}

#define Contig_Hash_Table_Size 2609
#define Contig_Hash_Table_Seed 5506195799875623628

global_function
u32
GetHashedContigName(u32 *name, u32 nInts)
{
    return(FastHash32((void *)name, (u64)(nInts * 4), Contig_Hash_Table_Seed) % Contig_Hash_Table_Size);
}

global_function
u32
GetHashedContigName(contig *cont)
{
    return(GetHashedContigName(cont->name, ArrayCount(cont->name)));
}

struct
contig_hash_table_node
{
    u32 index;
    u32 pad;
    contig_hash_table_node *next;
};

global_variable
contig_hash_table_node **
Contig_Hash_Table = 0;

global_function
void
InitiateContigHashTable()
{
    Contig_Hash_Table = PushArray(Working_Set, contig_hash_table_node*, Contig_Hash_Table_Size);
    ForLoop(Contig_Hash_Table_Size)
    {
        *(Contig_Hash_Table + index) = 0;
    }
}

global_function
void
InsertContigIntoHashTable(u32 index, u32 hash)
{
    contig_hash_table_node *node = Contig_Hash_Table[hash];
    contig_hash_table_node *nextNode = node ? node->next : 0;

    while (nextNode)
    {
        node = nextNode;
        nextNode = node->next;
    }
    
    contig_hash_table_node *newNode = PushStruct(Working_Set, contig_hash_table_node);
    
    newNode->index = index;
    newNode->next = 0;
    
    (node ? node->next : Contig_Hash_Table[hash]) = newNode;
}

global_function
u32
ContigHashTableLookup(u32 *name, u32 nameLength, u32 *index)
{
    u32 result = 1;

    contig_hash_table_node *node = Contig_Hash_Table[GetHashedContigName(name, nameLength)];
    if (node)
    {
        while (!AreNullTerminatedStringsEqual(name, (Map_Properties->contigs + node->index)->name, nameLength))
        {
            if (node->next)
            {
                node = node->next;
            }
            else
            {
                result = 0;
                break;
            }
        }

        if (result)
        {
            *index = node->index;
        }
    }
    else
    {
        result = 0;
    }

    return(result);
}

global_function
u32
ContigHashTableLookup(u32 *name, u32 nameLength, contig **cont)
{
    u32 result = 1;

    contig_hash_table_node *node = Contig_Hash_Table[GetHashedContigName(name, nameLength)];
    if (node)
    {
        while (!AreNullTerminatedStringsEqual(name, (Map_Properties->contigs + node->index)->name, nameLength))
        {
            if (node->next)
            {
                node = node->next;
            }
            else
            {
                result = 0;
                break;
            }
        }

        if (result)
        {
            *cont = Map_Properties->contigs + node->index;
        }
    }
    else
    {
        result = 0;
    }

    return(result);
}

global_function
u32
ContigHashTableLookup(u32 *name, u32 nameLength, u32 *index, contig **cont)
{
    u32 result = 1;

    contig_hash_table_node *node = Contig_Hash_Table[GetHashedContigName(name, nameLength)];
    if (node)
    {
        while (!AreNullTerminatedStringsEqual(name, (Map_Properties->contigs + node->index)->name, nameLength))
        {
            if (node->next)
            {
                node = node->next;
            }
            else
            {
                result = 0;
                break;
            }
        }

        if (result)
        {
            *index = node->index;
            *cont = Map_Properties->contigs + node->index;
        }
    }
    else
    {
        result = 0;
    }

    return(result);
}

enum
image_target_type
{
    full,
    all,
    other
};

struct
image_target_data_entry
{
    u32 contigIdx;
    u32 bpIdx;
    u32 clip;
};

struct
image_target_data
{
    image_target_data_entry *from;
    image_target_data_entry *to;
};

struct
image_target_data_wrapper
{
    u32 square;
    u32 pad;
    image_target_data *data;
};

struct
image_target
{
    image_target_type type;
    u32 pad;
    image_target_data_wrapper *dataWrapper;
    image_target *next;
};

global_function
u32
ProcessNameEntry(char *name, image_target_data_entry **from, u32 *bpIdx = 0)
{
    u32 result = 1;
    u32 name32[16];
    u32 index = 0;
    PushStringIntoIntArray((u32 *)name32, ArrayCount(name32), (u08 *)name);
    
    if (ContigHashTableLookup((u32 *)name32, ArrayCount(name32), &index))
    { 
        (*from)->contigIdx = index;
        if (bpIdx)
        {
            (*from)->bpIdx = *bpIdx;
            (*from)->clip = 0;
        }
        else (*from)->clip = 1;
    }
    else
    {
        result = 0;
        PrintError("\'%s\' is not the name of a sequence in this map", name);
    }
    
    return(result);
}

/*global_function
u32
ProcessNameTo(char *name, image_target_data_entry **to, u32 *bpIdx = 0)
{
    u32 result = 1;
    u32 name32[16];
    u32 index = 0;
    PushStringIntoIntArray((u32 *)name32, ArrayCount(name32), (u08 *)name);
    
    if (ContigHashTableLookup((u32 *)name32, ArrayCount(name32), &index))
    { 
        (*to)->contigIdx = index;
        if (bpIdx) (*to)->bpIdx = *bpIdx;
        else (*to)->bpIdx = (u32)((f64)Map_Properties->contigs[index].fractionalLength * (f64)Map_Properties->totalGenomeLength);
    }
    else
    {
        result = 0;
        PrintError("\'%s\' is not the name of a sequence in this map", name);
    }
    
    return(result);
}*/

global_function
u32
ProcessName(char *name, image_target_data **data)
{
    u32 result = 1;
    
    (*data)->from = PushStruct(Working_Set, image_target_data_entry);
    result = result && ProcessNameEntry(name, &((*data)->from));
    (*data)->to = PushStruct(Working_Set, image_target_data_entry);
    result = result && ProcessNameEntry(name, &((*data)->to));

    return(result);
}

global_function
u32
ProcessTarget(mpc_ast_t *syntaxTree, image_target_data **data)
{
    u32 result = 1;
    
    switch (syntaxTree->children_num)
    {
        case 0:
            {
                ProcessName(syntaxTree->contents, data);
            }
            break;

        case 3:
            {
                (*data)->from = PushStruct(Working_Set, image_target_data_entry);
                result = result && ProcessNameEntry(syntaxTree->children[0]->contents, &((*data)->from));
                (*data)->to = PushStruct(Working_Set, image_target_data_entry);
                result = result && ProcessNameEntry(syntaxTree->children[2]->contents, &((*data)->to));
            }
            break;

        case 6:
            {
                switch (*(syntaxTree->children[1]->contents))
                {
                    case '[':
                        {
                            u32 fromIdx = 0;
                            StringToInt_Check((u08 *)syntaxTree->children[2]->contents, &fromIdx);
                            (*data)->from = PushStruct(Working_Set, image_target_data_entry);
                            result = result && ProcessNameEntry(syntaxTree->children[0]->contents, &((*data)->from), &fromIdx);
                            (*data)->to = PushStruct(Working_Set, image_target_data_entry);
                            result = result && ProcessNameEntry(syntaxTree->children[5]->contents, &((*data)->to));
                        }
                        break;

                    case '>':
                        {
                            u32 toIdx = 0;
                            StringToInt_Check((u08 *)syntaxTree->children[4]->contents, &toIdx);
                            (*data)->from = PushStruct(Working_Set, image_target_data_entry);
                            result = result && ProcessNameEntry(syntaxTree->children[0]->contents, &((*data)->from));
                            (*data)->to = PushStruct(Working_Set, image_target_data_entry);
                            result = result && ProcessNameEntry(syntaxTree->children[2]->contents, &((*data)->to), &toIdx);
                        }
                        break;

                    default:
                        PrintError("Command syntax error. Panic!\n"); // Should never happen
                        exit(EXIT_FAILURE);
                }
            }
            break;

        case 9:
            {
                u32 fromIdx = 0;
                StringToInt_Check((u08 *)syntaxTree->children[2]->contents, &fromIdx);
                u32 toIdx = 0;
                StringToInt_Check((u08 *)syntaxTree->children[7]->contents, &toIdx);
                (*data)->from = PushStruct(Working_Set, image_target_data_entry);
                result = result && ProcessNameEntry(syntaxTree->children[0]->contents, &((*data)->from), &fromIdx);
                (*data)->to = PushStruct(Working_Set, image_target_data_entry);
                result = result && ProcessNameEntry(syntaxTree->children[5]->contents, &((*data)->to), &toIdx);
            }
            break;

        default:
            PrintError("Command syntax error. Panic!\n"); // Should never happen
            exit(EXIT_FAILURE);
    }

    return(result);
}

global_function
void
ParseTargetSyntax(image_target **headPtr, mpc_ast_t *syntaxTree)
{
    u32 isTargetFull = strstr(syntaxTree->tag, "full") ? 1 : 0;
    u32 isTargetAll = strstr(syntaxTree->tag, "all") ? 1 : 0;
    u32 isTargetGroup = strstr(syntaxTree->tag, "group") ? 1 : 0;
    u32 isTarget = strstr(syntaxTree->tag, "target") ? 1 : 0;
    u32 isName = strstr(syntaxTree->tag, "name") ? 1 : 0;

    if (isTargetFull || isTargetAll)
    {
        image_target *newTarget = PushStruct(Working_Set, image_target);
        newTarget->type = isTargetFull ? full : all;
        newTarget->next = 0;
        (*headPtr)->next = newTarget;
        (*headPtr) = newTarget;
    }
    else if (isName)
    {
        image_target *newTarget = PushStruct(Working_Set, image_target);
        newTarget->type = other;
        newTarget->next = 0;
        newTarget->dataWrapper = PushStruct(Working_Set, image_target_data_wrapper);
        newTarget->dataWrapper->square = 1;
        newTarget->dataWrapper->data = PushStruct(Working_Set, image_target_data);

        if (ProcessName(syntaxTree->contents, &newTarget->dataWrapper->data))
        {
            (*headPtr)->next = newTarget;
            (*headPtr) = newTarget;
        }
    }
    else if (isTarget)
    {
        image_target *newTarget = PushStruct(Working_Set, image_target);
        newTarget->type = other;
        newTarget->next = 0;
        newTarget->dataWrapper = PushStruct(Working_Set, image_target_data_wrapper);
        newTarget->dataWrapper->square = 1;
        newTarget->dataWrapper->data = PushStruct(Working_Set, image_target_data);

        if (ProcessTarget(syntaxTree, &newTarget->dataWrapper->data))
        {
            (*headPtr)->next = newTarget;
            (*headPtr) = newTarget;
        }
    }
    else if (isTargetGroup)
    {
        image_target *newTarget = PushStruct(Working_Set, image_target);
        newTarget->type = other;
        newTarget->next = 0;
        newTarget->dataWrapper = PushStruct(Working_Set, image_target_data_wrapper);
        newTarget->dataWrapper->square = 0;
        newTarget->dataWrapper->data = PushArray(Working_Set, image_target_data, 2);

        image_target_data *ptr[2] = {newTarget->dataWrapper->data + 0, newTarget->dataWrapper->data + 1};
        if (ProcessTarget(syntaxTree->children[1], (image_target_data **)(ptr + 0)) && 
                ProcessTarget(syntaxTree->children[3], (image_target_data **)(ptr + 1)))
        {
            (*headPtr)->next = newTarget;
            (*headPtr) = newTarget;
        }
    }
    else
    {
        ForLoop(((u32)syntaxTree->children_num)) ParseTargetSyntax(headPtr, syntaxTree->children[index]);
    }
}

global_function
u32
ProcessImageTargetOptions(image_target ***head, char *optionString = 0)
{
    u32 returnResult = 1;
    
    if (!optionString) optionString = (char *)"=full,=all";

    mpc_parser_t *position = mpc_new("position");
    mpc_parser_t *name = mpc_new("name");
    mpc_parser_t *all = mpc_new("all");
    mpc_parser_t *full = mpc_new("full");
    mpc_parser_t *target  = mpc_new("target");
    mpc_parser_t *group  = mpc_new("group");
    mpc_parser_t *generic = mpc_new("generic");
    mpc_parser_t *expression = mpc_new("expression");
    mpc_parser_t *syntax = mpc_new("syntax");

    mpca_lang(MPCA_LANG_DEFAULT,
            " expression : <generic> (',' <generic>)*;                                                          "
            " generic : <group> | <target> | '{' <target> '}' | <full> | <all>;                     "
            " group : '{' <target> ',' <target> '}';                                                                  "
            " full : /=full/;                                                                                         "
            " all : /=all/;                                                                                           "
            " target : <name>(('>' <name>('[' <position> ']')?) | ('[' <position> ']' '>' <name>('[' <position> ']')?))?;   "
            " name : /[0-9A-Za-z!#$%&\\+\\.\\/:;\\?@^_|~\\-][0-9A-Za-z!#$%&\\*\\+\\.\\/:;=\\?@^_|~\\-]*/;                   "
            " position : /[0-9]+/;                                                                                          "
            " syntax : /^/ <expression> /$/;                                                                                ",
            expression, generic, group, full, all, target, 
            name, position, syntax, NULL);

    mpc_result_t result;

    if (mpc_parse("sequence selection", optionString, syntax, &result))
    {
        image_target *tarPtr = PushStruct(Working_Set, image_target);
        tarPtr->next = 0;
        *head = &tarPtr->next;
        ParseTargetSyntax(&tarPtr, (mpc_ast_t *)result.output);
        mpc_ast_delete((mpc_ast_t *)result.output);
    }
    else
    {
        PrintError(mpc_err_string(result.error));
        mpc_err_delete(result.error);
        returnResult = 0;
    }
    
    mpc_cleanup(9, expression, generic, group, full, all, 
            target, name, position, syntax);
    
    return(returnResult);
}

global_variable
const char *
Predefined_Colour_Names[] = 
{
    "red",
    "green",
    "blue",
    "yellow",
    "cyan",
    "magenta",
    "white",
    "black"
};

global_function
u32
Predefined_Colour_Values[] =
{
   0xff0000ff,
   0xff00ff00,
   0xffff0000,
   0xff00ffff,
   0xffffff00,
   0xffff00ff,
   0xffffffff,
   0xff000000
};

global_function
u32
ProcessGridColourString(u32 *returnValue, u08 *string)
{
    u32 returnResult = 1;

    mpc_parser_t *hexString = mpc_new("hexString");
    mpc_parser_t *name = mpc_new("name");
    mpc_parser_t *syntax = mpc_new("syntax");

    mpca_lang(  MPCA_LANG_DEFAULT,
            " hexString : /[0-9a-fA-F]{8}/;"
            " name : /[a-zA-Z]+/;"
            " syntax : /^/ (/(0(X|x))?/ <hexString> | <name>) /$/;",
            hexString, name, syntax, NULL);

    mpc_result_t result;

    if (mpc_parse("grid colour", (char *)string, syntax, &result))
    {
        if (strstr(((mpc_ast_t *)result.output)->children[2]->tag, "hexString")) 
            *returnValue = StringRGBAHexCodeToU32((u08 *)(((mpc_ast_t *)result.output)->children[2]->contents));
        else if (strstr(((mpc_ast_t *)result.output)->children[1]->tag, "name"))
        {
            returnResult = 0;
            ForLoop(ArrayCount(Predefined_Colour_Names))
            {
                if (AreNullTerminatedStringsEqual((u08 *)Predefined_Colour_Names[index], (u08 *)(((mpc_ast_t *)result.output)->children[1])->contents))
                {
                    *returnValue = Predefined_Colour_Values[index];
                    returnResult = 1;
                    break;
                }
            }
            if (!returnResult)
            {
                PrintError("Grid colour error, \'%s\' is not the name of a pre-defined colour or a valid 32-bit hex code", ((mpc_ast_t *)result.output)->children[1]->contents);
            }
        }

        mpc_ast_delete((mpc_ast_t *)result.output);
    }
    else
    {
        PrintError(mpc_err_string(result.error));
        mpc_err_delete(result.error);
        returnResult = 0;
    }

    mpc_cleanup(3, hexString, name, syntax);
    return(returnResult);
}

global_function
u32
ProcessColourMapSelection(u32 *returnValue, u08 *string)
{
    u32 returnResult = 1;

    mpc_parser_t *name = mpc_new("name");
    mpc_parser_t *number = mpc_new("number");
    mpc_parser_t *syntax = mpc_new("syntax");

    mpca_lang(  MPCA_LANG_DEFAULT,
            " number : /[0-9]+/;"
            " name : /[0-9a-zA-Z\\-\\ ]+/;"
            " syntax : /^/ (<number> | <name>) /$/;",
            number, name, syntax, NULL);

    mpc_result_t result;

    if (mpc_parse("colour map", (char *)string, syntax, &result))
    {
        mpc_ast_t *selection = ((mpc_ast_t *)result.output)->children[1];
       
        if (strstr(selection->tag, "number"))
        {
            u32 check = StringToInt_Check((u08 *)selection->contents, returnValue);
            if (!check || *returnValue >= Number_of_Colour_Maps)
            {
                PrintError("Colour map selection error, \'%s\' not a number less than %d", selection->contents, Number_of_Colour_Maps);
                returnResult = 0;
            }
        }
        else if (strstr(selection->tag, "name"))
        {
            returnResult = 0;
            ForLoop(Number_of_Colour_Maps)
            {
                if (AreNullTerminatedStringsEqual((u08 *)selection->contents, (u08 *)Colour_Map_Names[index]))
                {
                    *returnValue = index;
                    returnResult = 1;
                    break;
                }
            }

            if (!returnResult)
            {
                PrintError("Colour map selection error, \'%s\' not a valid colour map", selection->contents);
            }
        }
        else
        {
            PrintError("Colour map syntax error, panic!");
            exit(EXIT_FAILURE);
        }

        mpc_ast_delete((mpc_ast_t *)result.output);
    }
    else
    {
        PrintError(mpc_err_string(result.error));
        mpc_err_delete(result.error);
        returnResult = 0;
    }

    mpc_cleanup(3, number, name, syntax);
    return(returnResult);
}

struct
file_atlas_entry
{
    u32 base;
    u32 nBytes;
};

global_variable
file_atlas_entry *
File_Atlas;

struct
bc4_block
{
    u08 values[8];
    u08 lookup[6];
};

global_function
void
FillBC4Block(bc4_block *block, u08 *rawBytes)
{
    block->values[0] = rawBytes[0];
    block->values[1] = rawBytes[1];
    block->values[2] = (u08)(((6 * (u16)block->values[0]) + (1 * (u16)block->values[1])) / 7);
    block->values[3] = (u08)(((5 * (u16)block->values[0]) + (2 * (u16)block->values[1])) / 7);
    block->values[4] = (u08)(((4 * (u16)block->values[0]) + (3 * (u16)block->values[1])) / 7);
    block->values[5] = (u08)(((3 * (u16)block->values[0]) + (4 * (u16)block->values[1])) / 7);
    block->values[6] = (u08)(((2 * (u16)block->values[0]) + (5 * (u16)block->values[1])) / 7);
    block->values[7] = (u08)(((1 * (u16)block->values[0]) + (6 * (u16)block->values[1])) / 7);
    ForLoop(6)
    {
        block->lookup[index] = rawBytes[index + 2];
    }
}

global_function
u08
GetBC4ValueAt(bc4_block *block, u08 x, u08 y)
{
    u08 coord = x + (4 * y);
    u08 bitsIntoBlock = 3 * coord;
    u08 bytesIntoBlock = bitsIntoBlock >> 3;
    u08 bitsFromByteStart = bitsIntoBlock & 7;
#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"	
    u16 lookup = *((u16 *)(block->lookup + bytesIntoBlock));
#pragma clang diagnostic pop
    lookup >>= bitsFromByteStart;
    lookup &= 7;
    return(block->values[lookup]);
}

struct
fillImage_thread_data
{
    u32 texelLodStart0_x;
    u32 texelLodRange0_x;
    u32 texelLodStart0_y;
    u32 texelLodRange0_y;
    u32 texelLodStart1_x;
    u32 texelLodRange1_x;
    u32 texelLodStart1_y;
    u32 texelLodRange1_y;
    u32 lodLevel;
    u32 fillTwoImageBuffers;
    u32 lodPixelResolution0_x;
    u32 lodPixelResolution1_x;
    u32 im0Offset;
    u32 im1Offset;
    u32 *returnStatus;
};

global_function
void
FillImage_Thread(void *in)
{
    fillImage_thread_data *data = (fillImage_thread_data *)in;
    
    u32 texelLodStart0_x = data->texelLodStart0_x;
    u32 texelLodRange0_x = data->texelLodRange0_x;
    u32 texelLodStart0_y = data->texelLodStart0_y;
    u32 texelLodRange0_y = data->texelLodRange0_y;
    u32 texelLodStart1_x = data->texelLodStart1_x;
    u32 texelLodRange1_x = data->texelLodRange1_x;
    u32 texelLodStart1_y = data->texelLodStart1_y;
    u32 texelLodRange1_y = data->texelLodRange1_y;
    u32 lodLevel = data->lodLevel;
    u32 fillTwoImageBuffers = data->fillTwoImageBuffers;
    u32 lodPixelResolution0_x = data->lodPixelResolution0_x;
    u32 lodPixelResolution1_x = data->lodPixelResolution1_x;
    u32 im0Offset = data->im0Offset;
    u32 im1Offset = data->im1Offset;
    u32 *returnStatus = data->returnStatus;
    
    u32 textureStart_x = (texelLodStart0_x << lodLevel) / Map_Properties->textureResolution;
    u32 textureStart_y = (texelLodStart0_y << lodLevel) / Map_Properties->textureResolution;
    u32 textureEnd_x = (((texelLodStart0_x + texelLodRange0_x - 1) << lodLevel) / Map_Properties->textureResolution) + 1;
    u32 textureEnd_y = (((texelLodStart0_y + texelLodRange0_y - 1) << lodLevel) / Map_Properties->textureResolution) + 1;

    auto texture2DTo1DIndex = [](u32 x, u32 y)->u32
    {
        return((y * (Map_Properties->numberOfTextures1D - 1)) - ((y & 1) ? (((y-1)>>1) * y) : ((y>>1)*(y-1))) + x);
    };

    u08 *image[2];
    image[0] = Output_Buffer->lodHigherBuffer + im0Offset;
    image[1] = Output_Buffer->lodLowerBuffer + im1Offset;
    u32 textureIm_x[2];
    textureIm_x[0] = 0;
    textureIm_x[1] = 0;
    u32 textureIm_y[2];
    textureIm_y[0] = 0;
    textureIm_y[1] = 0;
    u32 textureCoordStart_x[2];
    textureCoordStart_x[0] = 0;
    textureCoordStart_x[1] = 0;
    u32 textureCoordStart_y[2];
    textureCoordStart_y[0] = 0;
    textureCoordStart_y[1] = 0;
    u32 textureCoordEnd_x[2];
    textureCoordEnd_x[0] = 0;
    textureCoordEnd_x[1] = 0;
    u32 textureCoordEnd_y[2];
    textureCoordEnd_y[0] = 0;
    textureCoordEnd_y[1] = 0;

    texture_buffer *buffer = TakeTextureBufferFromQueue_Wait(Texture_Buffer_Queue);
    for (   u32 textureY = textureStart_y;
            textureY < textureEnd_y;
            ++textureY )
    {
        for (   u32 textureX = textureStart_x;
                textureX < textureEnd_x;
                ++textureX )
        {
            u32 lowerTriangular = textureX < textureY;

            u32 tex_x = Max(textureX, textureY);
            u32 tex_y = Min(textureX, textureY);

            u32 linearTextureIndex = texture2DTo1DIndex(tex_x, tex_y);

            file_atlas_entry *entry = File_Atlas + linearTextureIndex;
            u32 nBytes = entry->nBytes;
            fseek(buffer->file, entry->base, SEEK_SET);

            fread(buffer->compressionBuffer, 1, nBytes, buffer->file);

            if (libdeflate_deflate_decompress(buffer->decompressor, (const void *)buffer->compressionBuffer, nBytes, (void *)buffer->texture, Bytes_Per_Texture, NULL))
            {
                *returnStatus = 1;
                return;
            }
            u08 *texture[2];
            texture[0] = buffer->texture;

            u32 bytesPerLod = Map_Properties->textureResolution * (Map_Properties->textureResolution >> 1);
            ForLoop3(lodLevel)
            {
                texture[0] += bytesPerLod;
                bytesPerLod >>= 2;
            }
            if (fillTwoImageBuffers) texture[1] = texture[0] + bytesPerLod;

            u32 textureBlockStart_x[2];
            textureBlockStart_x[0] = (textureX * Map_Properties->textureResolution) >> lodLevel;
            textureBlockStart_x[1] = (textureX * Map_Properties->textureResolution) >> (lodLevel + 1);
            u32 textureBlockStart_y[2];
            textureBlockStart_y[0] = (textureY * Map_Properties->textureResolution) >> lodLevel;
            textureBlockStart_y[1] = (textureY * Map_Properties->textureResolution) >> (lodLevel + 1);
            u32 textureSize[2];
            textureSize[0] = Map_Properties->textureResolution >> lodLevel;
            textureSize[1] = Map_Properties->textureResolution >> (lodLevel + 1);

            textureCoordStart_x[0] = Max(texelLodStart0_x, ((textureX * Map_Properties->textureResolution) >> lodLevel));
            textureCoordStart_y[0] = Max(texelLodStart0_y, ((textureY * Map_Properties->textureResolution) >> lodLevel));
            textureCoordEnd_x[0] = Min(texelLodStart0_x + texelLodRange0_x, (((textureX + 1) * Map_Properties->textureResolution) >> lodLevel));
            textureCoordEnd_y[0] = Min(texelLodStart0_y + texelLodRange0_y, (((textureY + 1) * Map_Properties->textureResolution) >> lodLevel));
            textureCoordStart_x[1] = Max(texelLodStart1_x, ((textureX * Map_Properties->textureResolution) >> (lodLevel + 1)));
            textureCoordStart_y[1] = Max(texelLodStart1_y, ((textureY * Map_Properties->textureResolution) >> (lodLevel + 1)));
            textureCoordEnd_x[1] = Min(texelLodStart1_x + texelLodRange1_x, (((textureX + 1) * Map_Properties->textureResolution) >> (lodLevel + 1)));
            textureCoordEnd_y[1] = Min(texelLodStart1_y + texelLodRange1_y, (((textureY + 1) * Map_Properties->textureResolution) >> (lodLevel + 1)));

            u32 bc4BlockStart_x[2];
            bc4BlockStart_x[0] = (textureCoordStart_x[0] - textureBlockStart_x[0]) >> 2;
            bc4BlockStart_x[1] = (textureCoordStart_x[1] - textureBlockStart_x[1]) >> 2;
            u32 bc4BlockStart_y[2];
            bc4BlockStart_y[0] = (textureCoordStart_y[0] - textureBlockStart_y[0]) >> 2;
            bc4BlockStart_y[1] = (textureCoordStart_y[1] - textureBlockStart_y[1]) >> 2;
            u32 bc4BlockEnd_x[2];
            bc4BlockEnd_x[0] = textureCoordEnd_x[0] == textureBlockStart_x[0] ? 0 : (((textureCoordEnd_x[0] - textureBlockStart_x[0] - 1) >> 2) + 1);
            bc4BlockEnd_x[1] = textureCoordEnd_x[1] == textureBlockStart_x[1] ? 0 : (((textureCoordEnd_x[1] - textureBlockStart_x[1] - 1) >> 2) + 1);
            u32 bc4BlockEnd_y[2];
            bc4BlockEnd_y[0] = textureCoordEnd_y[0] == textureBlockStart_y[0] ? 0 : (((textureCoordEnd_y[0] - textureBlockStart_y[0] - 1) >> 2) + 1);
            bc4BlockEnd_y[1] = textureCoordEnd_y[1] == textureBlockStart_y[1] ? 0 : (((textureCoordEnd_y[1] - textureBlockStart_y[1] - 1) >> 2) + 1);
            u32 bc4Size[2];
            bc4Size[0] = textureSize[0] >> 2;
            bc4Size[1] = textureSize[1] >> 2;

            for (   u32 bc4_y = bc4BlockStart_y[0];
                    bc4_y < bc4BlockEnd_y[0];
                    ++bc4_y )
            {
                for (   u32 bc4_x = bc4BlockStart_x[0];
                        bc4_x < bc4BlockEnd_x[0];
                        ++bc4_x )
                {
                    u32 bc4Index = lowerTriangular ? ((bc4_x * bc4Size[0]) + bc4_y) : ((bc4_y * bc4Size[0]) + bc4_x);
                    u08 *bc4BlockData = texture[0] + (bc4Index << 3);

                    bc4_block bc4Block;
                    FillBC4Block(&bc4Block, bc4BlockData);

                    u32 bc4TexelStart_x = (bc4_x << 2) + textureBlockStart_x[0];
                    u32 bc4TexelStart_y = (bc4_y << 2) + textureBlockStart_y[0];

                    u32 bc4TexelEnd_x = ((bc4_x + 1) << 2) + textureBlockStart_x[0];
                    u32 bc4TexelEnd_y = ((bc4_y + 1) << 2) + textureBlockStart_y[0];

                    u32 texel_x = Max(textureCoordStart_x[0], bc4TexelStart_x);
                    u32 texel_y = Max(textureCoordStart_y[0], bc4TexelStart_y);

                    u32 texelEnd_x = Min(textureCoordEnd_x[0], bc4TexelEnd_x);
                    u32 texelEnd_y = Min(textureCoordEnd_y[0], bc4TexelEnd_y);

                    u32 blockIm_x = textureIm_x[0] + (texel_x - textureCoordStart_x[0]);
                    u32 blockIm_y = textureIm_y[0] + (texel_y - textureCoordStart_y[0]);

                    for (   u32 y = (texel_y & 3), im_y = blockIm_y, texelPtr_y = texel_y;
                            y < 4 && texelPtr_y < texelEnd_y;
                            ++y, ++im_y, ++texelPtr_y )
                    {
                        for (   u32 x = (texel_x & 3), im_x = blockIm_x, texelPtr_x = texel_x;
                                x < 4 && texelPtr_x < texelEnd_x;
                                ++x, ++im_x, ++texelPtr_x )
                        {
                            u08 bc4Index_x = lowerTriangular ? (u08)y : (u08)x;
                            u08 bc4Index_y = lowerTriangular ? (u08)x : (u08)y;

                            u08 val = GetBC4ValueAt(&bc4Block, (u08)bc4Index_x, (u08)bc4Index_y);

                            image[0][(im_y * lodPixelResolution0_x) + im_x] = val;
                        }
                    }
                }
            }

            if (fillTwoImageBuffers)
            {
                for (   u32 bc4_y = bc4BlockStart_y[1];
                        bc4_y < bc4BlockEnd_y[1];
                        ++bc4_y )
                {
                    for (   u32 bc4_x = bc4BlockStart_x[1];
                            bc4_x < bc4BlockEnd_x[1];
                            ++bc4_x )
                    {
                        u32 bc4Index = lowerTriangular ? ((bc4_x * bc4Size[1]) + bc4_y) : ((bc4_y * bc4Size[1]) + bc4_x);
                        u08 *bc4BlockData = texture[1] + (bc4Index << 3);

                        bc4_block bc4Block;
                        FillBC4Block(&bc4Block, bc4BlockData);

                        u32 bc4TexelStart_x = (bc4_x << 2) + textureBlockStart_x[1];
                        u32 bc4TexelStart_y = (bc4_y << 2) + textureBlockStart_y[1];

                        u32 bc4TexelEnd_x = ((bc4_x + 1) << 2) + textureBlockStart_x[1];
                        u32 bc4TexelEnd_y = ((bc4_y + 1) << 2) + textureBlockStart_y[1];

                        u32 texel_x = Max(textureCoordStart_x[1], bc4TexelStart_x);
                        u32 texel_y = Max(textureCoordStart_y[1], bc4TexelStart_y);

                        u32 texelEnd_x = Min(textureCoordEnd_x[1], bc4TexelEnd_x);
                        u32 texelEnd_y = Min(textureCoordEnd_y[1], bc4TexelEnd_y);

                        u32 blockIm_x = textureIm_x[1] + (texel_x - textureCoordStart_x[1]);
                        u32 blockIm_y = textureIm_y[1] + (texel_y - textureCoordStart_y[1]);

                        for (   u32 y = (texel_y & 3), im_y = blockIm_y, texelPtr_y = texel_y;
                                y < 4 && texelPtr_y < texelEnd_y;
                                ++y, ++im_y, ++texelPtr_y )
                        {
                            for (   u32 x = (texel_x & 3), im_x = blockIm_x, texelPtr_x = texel_x;
                                    x < 4 && texelPtr_x < texelEnd_x;
                                    ++x, ++im_x, ++texelPtr_x )
                            {
                                u08 bc4Index_x = lowerTriangular ? (u08)y : (u08)x;
                                u08 bc4Index_y = lowerTriangular ? (u08)x : (u08)y;

                                u08 val = GetBC4ValueAt(&bc4Block, (u08)bc4Index_x, (u08)bc4Index_y);

                                image[1][(im_y * lodPixelResolution1_x) + im_x] = val;
                            }
                        }
                    }
                }
            }

            textureIm_x[0] += (textureCoordEnd_x[0] - textureCoordStart_x[0]);
            textureIm_x[1] += (textureCoordEnd_x[1] - textureCoordStart_x[1]);
        }

        textureIm_y[0] += (textureCoordEnd_y[0] - textureCoordStart_y[0]);
        textureIm_y[1] += (textureCoordEnd_y[1] - textureCoordStart_y[1]);
        textureIm_x[0] = 0;
        textureIm_x[1] = 0;
    }
    
    AddTextureBufferToQueue(Texture_Buffer_Queue, buffer);
}

struct
blend_images_thread_data
{
    u32 nPixToDo;
    u32 startOffset;
    f32 blendWeight0;
    f32 blendWeight1;
};

global_function
void
Blend_Images_Thread(void *in)
{
    blend_images_thread_data *data = (blend_images_thread_data *)in;
    u32 nPix = data->nPixToDo;
    u32 offset = data->startOffset;
    f32 blendWeight0 = data->blendWeight0;
    f32 blendWeight1 = data->blendWeight1;

#ifdef UsingAVX
    // avx
    u32 pixCount = 0;
    u32 nLanes = nPix >> 3;
    __m256 weight_0 = _mm256_broadcast_ss((f32 const * )&blendWeight0);
    __m256 weight_1 = _mm256_broadcast_ss((f32 const * )&blendWeight1);

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
    u64 *pix_0 = (u64 *)(Output_Buffer->lodHigherResizeBuffer + offset);
    u64 *pix_1 = (u64 *)(Output_Buffer->lodLowerResizeBuffer + offset);
#pragma clang diagnostic pop
    ForLoop(nLanes)
    {
        __m128i pix128i_0 = _mm_set1_epi64 ((__m64)(*pix_0));
        __m128i pix128i_1 = _mm_set1_epi64 ((__m64)(*pix_1));

        __m256i pix256i_0 = _mm256_cvtepu8_epi32 (pix128i_0);
        __m256i pix256i_1 = _mm256_cvtepu8_epi32 (pix128i_1);

        __m256 pixFloat_0 = _mm256_cvtepi32_ps (pix256i_0);
        __m256 pixFloat_1 = _mm256_cvtepi32_ps (pix256i_1);

        pixFloat_0 = _mm256_mul_ps(pixFloat_0, weight_0);
        pixFloat_1 = _mm256_mul_ps(pixFloat_1, weight_1);

        __m256 pixFloat = _mm256_add_ps(pixFloat_0, pixFloat_1);

        __m256i pixi = _mm256_cvtps_epi32(pixFloat);
        // pixi = _mm256_packus_epi32(pixi, _mm256_permute2f128_ps(pixi, pixi, 1));
        pixi = _mm256_packus_epi32(pixi, _mm256_permute2f128_si256(pixi, pixi, 1));
        pixi = _mm256_packus_epi16(pixi, pixi);
        __m128i pixi128 = _mm256_castsi256_si128 (pixi);
        *(s64 *)pix_0 = _mm_cvtsi128_si64(pixi128);

        ++pix_0;
        ++pix_1;
        pixCount += 8;
    }

    u32 *pix32_0 = (u32 *)pix_0;
    u32 *pix32_1 = (u32 *)pix_1;
    if ((nPix - pixCount) > 3)
    {
#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
        __m64 *pix64_0 = (__m64 *)pix32_0;
        __m64 *pix64_1 = (__m64 *)pix32_1;
#pragma clang diagnostic pop

        __m128 pixFloat_0 = _mm_cvtpu8_ps(*pix64_0);
        __m128 pixFloat_1 = _mm_cvtpu8_ps(*pix64_1);

        pixFloat_0 = _mm_mul_ps(pixFloat_0, _mm256_castps256_ps128(weight_0));
        pixFloat_1 = _mm_mul_ps(pixFloat_1, _mm256_castps256_ps128(weight_1));

        __m128 pixFloat = _mm_add_ps(pixFloat_0, pixFloat_1);

        __m128i pixi = _mm_cvtps_epi32(pixFloat);
        pixi = _mm_packus_epi32(pixi, pixi);
        pixi = _mm_packus_epi16(pixi, pixi);
        *(s32 *)pix_0 = _mm_cvtsi128_si32(pixi);

        ++pix32_0;
        ++pix32_1;
        pixCount += 4;
    }

    u08 *pix8_0 = (u08 *)pix32_0;
    u08 *pix8_1 = (u08 *)pix32_1;
    while (pixCount++ < nPix)
    {
        *pix8_0 = (u08)((((f32)(*pix8_0) * blendWeight0) + ((f32)(*pix8_1) * blendWeight1)) + 0.5f);
        ++pix8_0;
        ++pix8_1;
    }
#else
    // sse4
    u32 pixCount = 0;
    u32 nLanes = nPix >> 2;
    __m128 weight_0 = _mm_set_ps1(blendWeight0);
    __m128 weight_1 = _mm_set_ps1(blendWeight1);

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
    u32 *pix_0 = (u32 *)(Output_Buffer->lodHigherResizeBuffer + offset);
    u32 *pix_1 = (u32 *)(Output_Buffer->lodLowerResizeBuffer + offset);

    ForLoop(nLanes)
    {
        __m64 *pix64_0 = (__m64 *)pix_0;
        __m64 *pix64_1 = (__m64 *)pix_1;
#pragma clang diagnostic pop

        __m128 pixFloat_0 = _mm_cvtpu8_ps(*pix64_0);
        __m128 pixFloat_1 = _mm_cvtpu8_ps(*pix64_1);

        pixFloat_0 = _mm_mul_ps(pixFloat_0, weight_0);
        pixFloat_1 = _mm_mul_ps(pixFloat_1, weight_1);

        __m128 pixFloat = _mm_add_ps(pixFloat_0, pixFloat_1);

        __m128i pixi = _mm_cvtps_epi32(pixFloat);
        pixi = _mm_packus_epi32(pixi, pixi);
        pixi = _mm_packus_epi16(pixi, pixi);
        *(s32 *)pix_0 = _mm_cvtsi128_si32(pixi);

        ++pix_0;
        ++pix_1;
        pixCount += 4;
    }

    u08 *pix8_0 = (u08 *)pix_0;
    u08 *pix8_1 = (u08 *)pix_1;
    while (pixCount++ < nPix)
    {
        *pix8_0 = (u08)((((f32)(*pix8_0) * blendWeight0) + ((f32)(*pix8_1) * blendWeight1)) + 0.5f);
        ++pix8_0;
        ++pix8_1;
    }
#endif
}

struct
colourise_image_thread_data
{
    u32 nPixToDo;
    u32 startOffset;
    u32 colourMapToUse;
};

global_function
void
Colourise_Image_Thread(void *in)
{
    colourise_image_thread_data *data = (colourise_image_thread_data *)in;
    u32 nPix = data->nPixToDo;
    u32 offset = data->startOffset;
    u32 colourMapToUse = data->colourMapToUse;
    
    u08 *colourMap = Colour_Map_Data[colourMapToUse];

    for (   u32 iGrey = offset, iCol = (3 * offset), index = 0;
            index < nPix;
            ++iGrey, ++index, iCol += 3 )
    {
        u08 pix = Output_Buffer->lodHigherResizeBuffer[iGrey];
        u08 *cols = colourMap + (3 * pix);
        GetCurrentOutputBuffer(Output_Buffer)[iCol + 0] = cols[0];
        GetCurrentOutputBuffer(Output_Buffer)[iCol + 1] = cols[1];
        GetCurrentOutputBuffer(Output_Buffer)[iCol + 2] = cols[2];
    }
}

struct
grid
{
#ifdef UsingAVX
    __m256 colourLinearPMA_R;
    u64 pad_1[4];
    __m256 colourLinearPMA_G;
    u64 pad_2[4];
    __m256 colourLinearPMA_B;
    u64 pad_3[4];
    __m256 colourOmAlpha;
#else
    __m128 colourLinearPMA_R;
    u64 pad_1[2];
    __m128 colourLinearPMA_G;
    u64 pad_2[2];
    __m128 colourLinearPMA_B;
    u64 pad_3[2];
    __m128 colourOmAlpha;
#endif
    u32 size;
    u32 pad_4;
#ifdef UsingAVX
    u64 pad_5[3];
#else
    u64 pad_5;
#endif
};

#define Default_Grid_Size 1
#define Default_Grid_Colour_sRGBA 0xff000000

global_variable
grid *
Grid;

global_function
__m128
sRGB8BitToLinearRGB_4Wide(u32 sRGB);

global_function
void
InitialiseGridColour(grid *gridData, u32 size = Default_Grid_Size, u32 colour = Default_Grid_Colour_sRGBA)
{
    gridData->size = size;
    __m128 gridColourLinearRGBA_m128 = sRGB8BitToLinearRGB_4Wide(colour);
    f32 gridColourLinearRGBA_[4];
    const f32 *gridColourLinearRGBA = (f32 *)gridColourLinearRGBA_;
    _mm_storeu_ps ((f32 *)gridColourLinearRGBA, gridColourLinearRGBA_m128);
    const f32 omAlpha = 1.0f - gridColourLinearRGBA_[3];
#ifdef UsingAVX
    __m256 colourAlpha = _mm256_broadcast_ss(gridColourLinearRGBA + 3);
    gridData->colourOmAlpha = _mm256_broadcast_ss(&omAlpha);
    gridData->colourLinearPMA_R = _mm256_mul_ps(_mm256_broadcast_ss(gridColourLinearRGBA + 0), colourAlpha);
    gridData->colourLinearPMA_G = _mm256_mul_ps(_mm256_broadcast_ss(gridColourLinearRGBA + 1), colourAlpha);
    gridData->colourLinearPMA_B = _mm256_mul_ps(_mm256_broadcast_ss(gridColourLinearRGBA + 2), colourAlpha);
#else
    __m128 colourAlpha = _mm_set_ps1(gridColourLinearRGBA_[3]);
    gridData->colourOmAlpha = _mm_set_ps1(omAlpha);
    gridData->colourLinearPMA_R = _mm_mul_ps(_mm_set_ps1(gridColourLinearRGBA_[0]), colourAlpha);
    gridData->colourLinearPMA_G = _mm_mul_ps(_mm_set_ps1(gridColourLinearRGBA_[1]), colourAlpha);
    gridData->colourLinearPMA_B = _mm_mul_ps(_mm_set_ps1(gridColourLinearRGBA_[2]), colourAlpha);
#endif
}

global_function
f32
sRGB8BitToLinearRGB(u08 sRGB)
{
    f32 sRGBFloat = (f32)sRGB / 255.0f;
    f32 result = sRGBFloat < 0.04045f ? (sRGBFloat / 12.92f) : (powf((sRGBFloat + 0.055f) / 1.055f, 2.4f));
    return(result);
}

#ifdef UsingAVX
global_function
__m256
sRGB8BitToLinearRGB_8Wide(u64 sRGB)
{
    const f32 oo255 = 1.0f / 255.0f;
    const f32 oo1292 = 1.0f / 12.92f;
    const f32 oo1055 = 1.0f / 1.055f;
    const f32 _004045 = 0.04045f;
    const f32 _0055 = 0.055f;
    const f32 _24 = 2.4f;

    __m128i sRGB128i = _mm_set1_epi64 ((__m64)sRGB);
    __m256i sRGB256i = _mm256_cvtepu8_epi32 (sRGB128i);
    __m256 sRGBFloat = _mm256_cvtepi32_ps (sRGB256i);
    sRGBFloat = _mm256_mul_ps(sRGBFloat, _mm256_broadcast_ss(&oo255));

    __m256 mask = _mm256_cmp_ps(sRGBFloat, _mm256_broadcast_ss(&_004045), _CMP_LT_OQ);
    __m256 lowRes = _mm256_mul_ps(sRGBFloat, _mm256_broadcast_ss(&oo1292));
    __m256 highRes = Pow_8wide_PositiveBase(_mm256_mul_ps(_mm256_add_ps(sRGBFloat, _mm256_broadcast_ss(&_0055)), _mm256_broadcast_ss(&oo1055)), _mm256_broadcast_ss(&_24));

    return(_mm256_blendv_ps(highRes, lowRes, mask));
}
#endif
global_function
__m128
sRGB8BitToLinearRGB_4Wide(u32 sRGB)
{
    const f32 oo255 = 1.0f / 255.0f;
    const f32 oo1292 = 1.0f / 12.92f;
    const f32 oo1055 = 1.0f / 1.055f;
    const f32 _004045 = 0.04045f;
    const f32 _0055 = 0.055f;
    const f32 _24 = 2.4f;

#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
    __m64 *sRGB64 = (__m64 *)&sRGB;
#pragma clang diagnostic pop

    __m128 sRGBFloat = _mm_cvtpu8_ps(*sRGB64);
    sRGBFloat = _mm_mul_ps(sRGBFloat, _mm_set_ps1(oo255));

    __m128 mask = _mm_cmplt_ps(sRGBFloat, _mm_set_ps1(_004045));
    __m128 lowRes = _mm_mul_ps(sRGBFloat, _mm_set_ps1(oo1292));
    __m128 highRes = Pow_4wide_PositiveBase(_mm_mul_ps(_mm_add_ps(sRGBFloat, _mm_set_ps1(_0055)), _mm_set_ps1(oo1055)), _mm_set_ps1(_24));

    return(_mm_blendv_ps(highRes, lowRes, mask));
}

global_function
u08
LinearRGBTo8BitsRGB(f32 linearRGB)
{
    f32 sRGBFloat = linearRGB < 0.0031308f ? (12.92f * linearRGB) : ((1.055f * powf(linearRGB, 1.0f / 2.4f)) - 0.055f);
    u08 result = (u08)(sRGBFloat * 255.0f);
    return(result);
}

#ifdef UsingAVX
global_function
u64
LinearRGBTo8BitsRGB_8Wide(__m256 linearRGBFloat)
{
    const f32 _255 = 255.0f;
    const f32 _1292 = 12.92f;
    const f32 _1055 = 1.055f;
    const f32 _00031308 = 0.0031308f;
    const f32 _0055 = 0.055f;
    const f32 oo_24 = 1.0f / 2.4f;

    __m256 mask = _mm256_cmp_ps(linearRGBFloat, _mm256_broadcast_ss(&_00031308), _CMP_LT_OQ);
    __m256 lowRes = _mm256_mul_ps(linearRGBFloat, _mm256_broadcast_ss(&_1292));
    __m256 highRes = _mm256_sub_ps(_mm256_mul_ps(Pow_8wide_PositiveBase(linearRGBFloat, _mm256_broadcast_ss(&oo_24)), _mm256_broadcast_ss(&_1055)), _mm256_broadcast_ss(&_0055));

    __m256 sRGBFloat = _mm256_mul_ps(_mm256_blendv_ps(highRes, lowRes, mask), _mm256_broadcast_ss(&_255));

    __m256i sRGB256i = _mm256_cvtps_epi32(sRGBFloat);
    // sRGB256i = _mm256_packus_epi32(sRGB256i, _mm256_permute2f128_ps(sRGB256i, sRGB256i, 1));
    sRGB256i = _mm256_packus_epi32(sRGB256i, _mm256_permute2f128_si256(sRGB256i, sRGB256i, 1));
    sRGB256i = _mm256_packus_epi16(sRGB256i, sRGB256i);
    __m128i sRGB128i = _mm256_castsi256_si128 (sRGB256i);
    u64 result = 0;
    *(s64 *)&result = _mm_cvtsi128_si64(sRGB128i);

    return(result);
}
#else
global_function
u32
LinearRGBTo8BitsRGB_4Wide(__m128 linearRGBFloat)
{
    const f32 _255 = 255.0f;
    const f32 _1292 = 12.92f;
    const f32 _1055 = 1.055f;
    const f32 _00031308 = 0.0031308f;
    const f32 _0055 = 0.055f;
    const f32 oo_24 = 1.0f / 2.4f;

    __m128 mask = _mm_cmplt_ps(linearRGBFloat, _mm_set_ps1(_00031308));
    __m128 lowRes = _mm_mul_ps(linearRGBFloat, _mm_set_ps1(_1292));
    __m128 highRes = _mm_sub_ps(_mm_mul_ps(Pow_4wide_PositiveBase(linearRGBFloat, _mm_set_ps1(oo_24)), _mm_set_ps1(_1055)), _mm_set_ps1(_0055));

    __m128 sRGBFloat = _mm_mul_ps(_mm_blendv_ps(highRes, lowRes, mask), _mm_set_ps1(_255));

    __m128i sRGB128i = _mm_cvtps_epi32(sRGBFloat);
    sRGB128i = _mm_packus_epi32(sRGB128i, sRGB128i);
    sRGB128i = _mm_packus_epi16(sRGB128i, sRGB128i);
    u32 result = 0;
    *(s32 *)&result = _mm_cvtsi128_si32(sRGB128i);

    return(result);
}
#endif

#ifdef UsingAVX
global_function
void
AlphaBlendGrid_8Wide(u64 *pixelData)
{
    __m256 linearColour[3];
    linearColour[0] = sRGB8BitToLinearRGB_8Wide(pixelData[0]);
    linearColour[1] = sRGB8BitToLinearRGB_8Wide(pixelData[1]);
    linearColour[2] = sRGB8BitToLinearRGB_8Wide(pixelData[2]);

    linearColour[0] = _mm256_add_ps(Grid->colourLinearPMA_R, _mm256_mul_ps(linearColour[0], Grid->colourOmAlpha));
    linearColour[1] = _mm256_add_ps(Grid->colourLinearPMA_G, _mm256_mul_ps(linearColour[1], Grid->colourOmAlpha));
    linearColour[2] = _mm256_add_ps(Grid->colourLinearPMA_B, _mm256_mul_ps(linearColour[2], Grid->colourOmAlpha));

    pixelData[0] = LinearRGBTo8BitsRGB_8Wide(linearColour[0]);
    pixelData[1] = LinearRGBTo8BitsRGB_8Wide(linearColour[1]);
    pixelData[2] = LinearRGBTo8BitsRGB_8Wide(linearColour[2]);
}
#else
global_function
void
AlphaBlendGrid_4Wide(u32 *pixelData)
{
    __m128 linearColour[3];
    linearColour[0] = sRGB8BitToLinearRGB_4Wide(pixelData[0]);
    linearColour[1] = sRGB8BitToLinearRGB_4Wide(pixelData[1]);
    linearColour[2] = sRGB8BitToLinearRGB_4Wide(pixelData[2]);

    linearColour[0] = _mm_add_ps(Grid->colourLinearPMA_R, _mm_mul_ps(linearColour[0], Grid->colourOmAlpha));
    linearColour[1] = _mm_add_ps(Grid->colourLinearPMA_G, _mm_mul_ps(linearColour[1], Grid->colourOmAlpha));
    linearColour[2] = _mm_add_ps(Grid->colourLinearPMA_B, _mm_mul_ps(linearColour[2], Grid->colourOmAlpha));

    pixelData[0] = LinearRGBTo8BitsRGB_4Wide(linearColour[0]);
    pixelData[1] = LinearRGBTo8BitsRGB_4Wide(linearColour[1]);
    pixelData[2] = LinearRGBTo8BitsRGB_4Wide(linearColour[2]);
}
#endif

struct
fill_in_grid_thread_data
{
    u32 contigStart_x;
    u32 contigEnd_x;
    u32 contigStart_y;
    u32 contigEnd_y;
    u32 nTexels;
    u32 texelStart_x;
    u32 texelRange_x;
    u32 texelStart_y;
    u32 texelRange_y;
    u32 resolution_x;
    u32 startIndex_x;
    u32 indexRange_x;
    u32 resolution_y;
    u32 startIndex_y;
    u32 indexRange_y;
    u32 doX;
};

global_function
void
FillInGrid_Thread(void *in)
{
    fill_in_grid_thread_data *data = (fill_in_grid_thread_data *)in;

    u32 contigStart_x = data->contigStart_x;
    u32 contigEnd_x = data->contigEnd_x;
    u32 contigStart_y = data->contigStart_y;
    u32 contigEnd_y = data->contigEnd_y;
    u32 nTexels = data->nTexels;
    u32 texelStart_x = data->texelStart_x;
    u32 texelRange_x = data->texelRange_x;
    u32 texelStart_y = data->texelStart_y;
    u32 texelRange_y = data->texelRange_y;
    u32 resolution_x = data->resolution_x;
    u32 resolution_y = data->resolution_y;
    u32 start_x = data->startIndex_x;
    u32 range_x = data->indexRange_x;
    u32 start_y = data->startIndex_y;
    u32 range_y = data->indexRange_y;

    u32 doX = data->doX;

    u32 halfGridSize = Grid->size >> 1;

    auto lineariseImageIndex = [resolution_x](u32 x, u32 y)->u32 
    {
        return(3 * ((y * resolution_x) + x));
    };

    if (doX)
    {
        // x
        for (   u32 iContig = contigStart_x;
                iContig <= contigEnd_x;
                ++iContig )
        {
            u32 texel = (u32)((f64)Map_Properties->contigs[iContig].previousCumulativeLength * (f64)nTexels);
            if (texel >= texelStart_x && (texel - texelStart_x) < texelRange_x)
            {
                u32 pixelCentre = (u32)((f64)(texel - texelStart_x) / (f64)texelRange_x * (f64)resolution_x);
                u32 pixelStart = pixelCentre < halfGridSize ? 0 : ((pixelCentre + halfGridSize) > resolution_x ? (resolution_x - Grid->size) : (pixelCentre - halfGridSize));

                for (   u32 pixel = pixelStart, pixelCount = 0;
                        pixelCount < Grid->size && pixel < resolution_x;
                        ++pixelCount, ++pixel )
                {
#ifdef UsingAVX
                    u64 pixelData[3] = {0, 0, 0};
                    u32 dataSize = 8;
#else
                    u32 pixelData[3] = {0, 0, 0};
                    u32 dataSize = 4;
#endif

                    u32 countMod = 0;
                    u32 index = 0;
                    u32 count = 0;
                    for (   index = start_y, count = 0;
                            count < range_y;
                            ++index, ++count )
                    {
                        u32 pixIndex = lineariseImageIndex(pixel, index);
                        u08 pixels[3];
                        pixels[0] = GetCurrentOutputBuffer(Output_Buffer)[pixIndex + 0];
                        pixels[1] = GetCurrentOutputBuffer(Output_Buffer)[pixIndex + 1];
                        pixels[2] = GetCurrentOutputBuffer(Output_Buffer)[pixIndex + 2];

                        countMod = count & (dataSize - 1);
                        if (count && !countMod)
                        {
#ifdef UsingAVX
                            AlphaBlendGrid_8Wide(pixelData);
                            ForLoop2(dataSize)
                            {
                                u32 idx = lineariseImageIndex(pixel, index - dataSize + index2);
                                GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> (index2 << 3)) & (u64)0xff);
                                GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> (index2 << 3)) & (u64)0xff);
                                GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> (index2 << 3)) & (u64)0xff);
                            }
#else
                            AlphaBlendGrid_4Wide(pixelData);
                            ForLoop2(dataSize)
                            {
                                u32 idx = lineariseImageIndex(pixel, index - dataSize + index2);
                                GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> (index2 << 3)) & (u32)0xff);
                                GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> (index2 << 3)) & (u32)0xff);
                                GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> (index2 << 3)) & (u32)0xff);
                            }
#endif
                            pixelData[0] = 0;
                            pixelData[1] = 0;
                            pixelData[2] = 0;
                        }

#ifdef UsingAVX
                        pixelData[0] |= (u64)pixels[0] << (countMod << 3);
                        pixelData[1] |= (u64)pixels[1] << (countMod << 3);
                        pixelData[2] |= (u64)pixels[2] << (countMod << 3);
#else
                        pixelData[0] |= (u32)pixels[0] << (countMod << 3);
                        pixelData[1] |= (u32)pixels[1] << (countMod << 3);
                        pixelData[2] |= (u32)pixels[2] << (countMod << 3);
#endif
                        FillPixelBitFlag(pixel, index, resolution_x, Output_Buffer->outputImageBufferGridFillFlags);
                    }

#ifdef UsingAVX
                    u32 backCount = countMod + 1;
                    AlphaBlendGrid_8Wide(pixelData);
                    ForLoop2(backCount)
                    {
                        u32 idx = lineariseImageIndex(pixel, index - backCount + index2);
                        GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> (index2 << 3)) & (u64)0xff);
                        GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> (index2 << 3)) & (u64)0xff);
                        GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> (index2 << 3)) & (u64)0xff);
                    }
#else
                    u32 backCount = countMod + 1;
                    AlphaBlendGrid_4Wide(pixelData);
                    ForLoop2(backCount)
                    {
                        u32 idx = lineariseImageIndex(pixel, index - backCount + index2);
                        GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> (index2 << 3)) & (u32)0xff);
                        GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> (index2 << 3)) & (u32)0xff);
                        GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> (index2 << 3)) & (u32)0xff);
                    }
#endif

                }
            }
        }
    }
    else
    {
        // y
        for (   u32 iContig = contigStart_y;
                iContig <= contigEnd_y;
                ++iContig )
        {
            u32 texel = (u32)((f64)Map_Properties->contigs[iContig].previousCumulativeLength * (f64)nTexels);
            if (texel >= texelStart_y && (texel - texelStart_y) < texelRange_y)
            {
                u32 pixelCentre = (u32)((f64)(texel - texelStart_y) / (f64)texelRange_y * (f64)resolution_y);
                u32 pixelStart = pixelCentre < halfGridSize ? 0 : ((pixelCentre + halfGridSize) > resolution_y ? (resolution_y - Grid->size) : (pixelCentre - halfGridSize));

                for (   u32 pixel = pixelStart, pixelCount = 0;
                        pixelCount < Grid->size && pixel < resolution_y;
                        ++pixelCount, ++pixel )
                {
#ifdef UsingAVX
                    u64 pixelData[3] = {0, 0, 0};
                    u32 dataSize = 8;
#else
                    u32 pixelData[3] = {0, 0, 0};
                    u32 dataSize = 4;
#endif
                    u32 countMod = 0;
                    u32 index = 0;
                    u32 count = 0;
                    u32 skipCount = 0;
                    for (   index = start_x, count = 0;
                            count < range_x;
                            ++index, ++count )
                    {
                        if (!CheckPixelBitFlag(index, pixel, resolution_x, Output_Buffer->outputImageBufferGridFillFlags))
                        { 
                            u32 pixIndex = lineariseImageIndex(index, pixel);
                            u08 pixels[3];
                            pixels[0] = GetCurrentOutputBuffer(Output_Buffer)[pixIndex + 0];
                            pixels[1] = GetCurrentOutputBuffer(Output_Buffer)[pixIndex + 1];
                            pixels[2] = GetCurrentOutputBuffer(Output_Buffer)[pixIndex + 2];

                            countMod = skipCount & (dataSize - 1);
                            if (skipCount && !countMod)
                            {
#ifdef UsingAVX
                                AlphaBlendGrid_8Wide(pixelData);
                                u32 skipBackIndex = 0;
                                u32 backFillCount = 0;
                                while (backFillCount < dataSize)
                                {
                                    if (!CheckPixelBitFlag(index - (++skipBackIndex), pixel, resolution_x, Output_Buffer->outputImageBufferGridFillFlags))
                                    {
                                        u32 idx = lineariseImageIndex(index - skipBackIndex, pixel);
                                        u32 backShiftIndex = (dataSize - backFillCount++ - 1) << 3;
                                        GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> backShiftIndex) & (u64)0xff);
                                        GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> backShiftIndex) & (u64)0xff);
                                        GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> backShiftIndex) & (u64)0xff);
                                    }
                                }
#else
                                AlphaBlendGrid_4Wide(pixelData);
                                u32 skipBackIndex = 0;
                                u32 backFillCount = 0;
                                while (backFillCount < dataSize)
                                {
                                    if (!CheckPixelBitFlag(index - (++skipBackIndex), pixel, resolution_x, Output_Buffer->outputImageBufferGridFillFlags))
                                    {
                                        u32 idx = lineariseImageIndex(index - skipBackIndex, pixel);
                                        u32 backShiftIndex = (dataSize - backFillCount++ - 1) << 3;
                                        GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> backShiftIndex) & (u32)0xff);
                                        GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> backShiftIndex) & (u32)0xff);
                                        GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> backShiftIndex) & (u32)0xff);
                                    }
                                }
#endif
                                pixelData[0] = 0;
                                pixelData[1] = 0;
                                pixelData[2] = 0;
                            }

#ifdef UsingAVX
                            pixelData[0] |= (u64)pixels[0] << (countMod << 3);
                            pixelData[1] |= (u64)pixels[1] << (countMod << 3);
                            pixelData[2] |= (u64)pixels[2] << (countMod << 3);
#else
                            pixelData[0] |= (u32)pixels[0] << (countMod << 3);
                            pixelData[1] |= (u32)pixels[1] << (countMod << 3);
                            pixelData[2] |= (u32)pixels[2] << (countMod << 3);
#endif
                            ++skipCount;
                        }
                    }

#ifdef UsingAVX
                    u32 backCount = countMod + 1;
                    AlphaBlendGrid_8Wide(pixelData);
                    u32 skipBackIndex = 0;
                    u32 backFillCount = 0;
                    while (backFillCount < backCount)
                    {
                        if (!CheckPixelBitFlag(index - (++skipBackIndex), pixel, resolution_x, Output_Buffer->outputImageBufferGridFillFlags))
                        {
                            u32 idx = lineariseImageIndex(index - skipBackIndex, pixel);
                            u32 backShiftIndex = (backCount - backFillCount++ - 1) << 3;
                            GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> backShiftIndex) & (u64)0xff);
                            GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> backShiftIndex) & (u64)0xff);
                            GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> backShiftIndex) & (u64)0xff);
                        }
                    }
#else
                    u32 backCount = countMod + 1;
                    AlphaBlendGrid_4Wide(pixelData);
                    u32 skipBackIndex = 0;
                    u32 backFillCount = 0;
                    while (backFillCount < backCount)
                    {
                        if (!CheckPixelBitFlag(index - (++skipBackIndex), pixel, resolution_x, Output_Buffer->outputImageBufferGridFillFlags))
                        {
                            u32 idx = lineariseImageIndex(index - skipBackIndex, pixel);
                            u32 backShiftIndex = (backCount - backFillCount++ - 1) << 3;
                            GetCurrentOutputBuffer(Output_Buffer)[idx + 0] = (u08)((pixelData[0] >> backShiftIndex) & (u32)0xff);
                            GetCurrentOutputBuffer(Output_Buffer)[idx + 1] = (u08)((pixelData[1] >> backShiftIndex) & (u32)0xff);
                            GetCurrentOutputBuffer(Output_Buffer)[idx + 2] = (u08)((pixelData[2] >> backShiftIndex) & (u32)0xff);
                        }
                    }
#endif
                }
            }
        }
    }
}

global_variable
u32
Min_Texels = 64;

global_variable
u32
Colour_Map_Index = 5+3;

global_function
u32
FillImage(u32 texelStart_x, u32 texelStart_y, u32 texelRange_x, u32 texelRange_y, u32 *outputWidth, u32 *outputHeight, u32 *returnMessageIndex, u32 *gridDrawContigRange = 0)
{
    u32 returnValue = 0;

    u32 texelRangeMin = Min(texelRange_x, texelRange_y);
    u32 texelRangeMax = Max(texelRange_x, texelRange_y);
    f32 aspectRatio = (f32)texelRangeMin / (f32)texelRangeMax;
    
    f32 texelsPerPixel = (f32)texelRangeMax / (f32)Output_Buffer->outputResolution;
    f32 log2TexelsPerPixel = Max(0.0f, Log2(Max(1.0f, texelsPerPixel)));
    u32 lodLevel = (u32)log2TexelsPerPixel;
    f32 lodOffset = log2TexelsPerPixel - (f32)lodLevel;
    
    f32 lodBlendWeights[2] = {1.0f - lodOffset, lodOffset};

    lodLevel = Min(lodLevel, (Map_Properties->numberOfMipMaps - 1));
    
    u32 lodPixelResolution_x[2];
    u32 lodPixelResolution_y[2];
    u32 texelLodStart_x[2];
    u32 texelLodStart_y[2];
    u32 texelLodEnd_x[2];
    u32 texelLodEnd_y[2];

    texelLodStart_x[0] = texelStart_x >> lodLevel;
    texelLodStart_x[1] = texelStart_x >> (lodLevel + 1);
    texelLodEnd_x[0] = ((texelStart_x + texelRange_x - 1) >> lodLevel) + 1;
    texelLodEnd_x[1] = ((texelStart_x + texelRange_x - 1) >> (lodLevel + 1)) + 1;
    lodPixelResolution_x[0] = texelLodEnd_x[0] - texelLodStart_x[0];
    lodPixelResolution_x[1] = texelLodEnd_x[1] - texelLodStart_x[1];
    
    texelLodStart_y[0] = texelStart_y >> lodLevel;
    texelLodStart_y[1] = texelStart_y >> (lodLevel + 1);
    texelLodEnd_y[0] = ((texelStart_y + texelRange_y - 1) >> lodLevel) + 1;
    texelLodEnd_y[1] = ((texelStart_y + texelRange_y - 1) >> (lodLevel + 1)) + 1;
    lodPixelResolution_y[0] = texelLodEnd_y[0] - texelLodStart_y[0];
    lodPixelResolution_y[1] = texelLodEnd_y[1] - texelLodStart_y[1];
    
    u32 fillTwoImageBuffers = lodLevel != (Map_Properties->numberOfMipMaps - 1);

    if (texelRange_x < Min_Texels || texelRange_y < Min_Texels)
    {
        *returnMessageIndex = Texel_Range_Too_Small_Error_Message_Index;
        returnValue = 1;
        goto FillImageExit;
    }

    {
        fillImage_thread_data data[4];
        u32 returnStatus = 0;
       
        u32 oneHalfYRes[2];
        oneHalfYRes[0] = lodPixelResolution_y[0] >> 1;
        oneHalfYRes[1] = lodPixelResolution_y[1] >> 1;
        u32 oneQuaterYRes[2];
        oneQuaterYRes[0] = oneHalfYRes[0] >> 1;
        oneQuaterYRes[1] = oneHalfYRes[1] >> 1;

        data[0].texelLodStart0_x = texelLodStart_x[0];
        data[0].texelLodRange0_x = lodPixelResolution_x[0];
        data[0].texelLodStart0_y = texelLodStart_y[0];
        data[0].texelLodRange0_y = oneQuaterYRes[0];
        data[0].texelLodStart1_x = texelLodStart_x[1];
        data[0].texelLodRange1_x = lodPixelResolution_x[1];
        data[0].texelLodStart1_y = texelLodStart_y[1];
        data[0].texelLodRange1_y = oneQuaterYRes[1];
        data[0].lodLevel = lodLevel;
        data[0].fillTwoImageBuffers = fillTwoImageBuffers;
        data[0].lodPixelResolution0_x = lodPixelResolution_x[0];
        data[0].lodPixelResolution1_x = lodPixelResolution_x[1];
        data[0].im0Offset = 0;
        data[0].im1Offset = 0;
        data[0].returnStatus = &returnStatus;

        data[1].texelLodStart0_x = texelLodStart_x[0];
        data[1].texelLodRange0_x = lodPixelResolution_x[0];
        data[1].texelLodStart0_y = data[0].texelLodStart0_y + data[0].texelLodRange0_y;
        data[1].texelLodRange0_y = oneHalfYRes[0] - oneQuaterYRes[0];
        data[1].texelLodStart1_x = texelLodStart_x[1];
        data[1].texelLodRange1_x = lodPixelResolution_x[1];
        data[1].texelLodStart1_y = data[0].texelLodStart1_y + data[0].texelLodRange1_y;
        data[1].texelLodRange1_y = oneHalfYRes[1] - oneQuaterYRes[1];
        data[1].lodLevel = lodLevel;
        data[1].fillTwoImageBuffers = fillTwoImageBuffers;
        data[1].lodPixelResolution0_x = lodPixelResolution_x[0];
        data[1].lodPixelResolution1_x = lodPixelResolution_x[1];
        data[1].im0Offset = lodPixelResolution_x[0] * oneQuaterYRes[0];
        data[1].im1Offset = lodPixelResolution_x[1] * oneQuaterYRes[1];
        data[1].returnStatus = &returnStatus;

        data[2].texelLodStart0_x = texelLodStart_x[0];
        data[2].texelLodRange0_x = lodPixelResolution_x[0];
        data[2].texelLodStart0_y = data[1].texelLodStart0_y + data[1].texelLodRange0_y;
        data[2].texelLodRange0_y = oneQuaterYRes[0];
        data[2].texelLodStart1_x = texelLodStart_x[1];
        data[2].texelLodRange1_x = lodPixelResolution_x[1];
        data[2].texelLodStart1_y = data[1].texelLodStart1_y + data[1].texelLodRange1_y;
        data[2].texelLodRange1_y = oneQuaterYRes[1];
        data[2].lodLevel = lodLevel;
        data[2].fillTwoImageBuffers = fillTwoImageBuffers;
        data[2].lodPixelResolution0_x = lodPixelResolution_x[0];
        data[2].lodPixelResolution1_x = lodPixelResolution_x[1];
        data[2].im0Offset = lodPixelResolution_x[0] * oneHalfYRes[0];
        data[2].im1Offset = lodPixelResolution_x[1] * oneHalfYRes[1];
        data[2].returnStatus = &returnStatus;

        data[3].texelLodStart0_x = texelLodStart_x[0];
        data[3].texelLodRange0_x = lodPixelResolution_x[0];
        data[3].texelLodStart0_y = data[2].texelLodStart0_y + data[2].texelLodRange0_y;
        data[3].texelLodRange0_y = lodPixelResolution_y[0] - data[2].texelLodRange0_y - data[1].texelLodRange0_y - data[0].texelLodRange0_y;
        data[3].texelLodStart1_x = texelLodStart_x[1];
        data[3].texelLodRange1_x = lodPixelResolution_x[1];
        data[3].texelLodStart1_y = data[2].texelLodStart1_y + data[2].texelLodRange1_y;
        data[3].texelLodRange1_y = lodPixelResolution_y[1] - data[2].texelLodRange1_y - data[1].texelLodRange1_y - data[0].texelLodRange1_y;
        data[3].lodLevel = lodLevel;
        data[3].fillTwoImageBuffers = fillTwoImageBuffers;
        data[3].lodPixelResolution0_x = lodPixelResolution_x[0];
        data[3].lodPixelResolution1_x = lodPixelResolution_x[1];
        data[3].im0Offset = lodPixelResolution_x[0] * (oneHalfYRes[0] + oneQuaterYRes[0]);
        data[3].im1Offset = lodPixelResolution_x[1] * (oneHalfYRes[1] + oneQuaterYRes[1]);
        data[3].returnStatus = &returnStatus;

        ThreadPoolAddTask(Thread_Pool, FillImage_Thread, (data + 0));
        ThreadPoolAddTask(Thread_Pool, FillImage_Thread, (data + 1));
        ThreadPoolAddTask(Thread_Pool, FillImage_Thread, (data + 2));
        ThreadPoolAddTask(Thread_Pool, FillImage_Thread, (data + 3));
        ThreadPoolWait(Thread_Pool);
        
        if (returnStatus)
        {
            *returnMessageIndex = Texture_Decompress_Error_Message_Index;
            returnValue = 1;
            goto FillImageExit;
        }
    }

    u32 outputResolution_x;
    u32 outputResolution_y;

    if (texelRange_x > texelRange_y)
    {
        outputResolution_x = Output_Buffer->outputResolution;
        outputResolution_y = (u32)(0.5f + (aspectRatio * (f32)Output_Buffer->outputResolution));
    }
    else
    {
        outputResolution_y = Output_Buffer->outputResolution;
        outputResolution_x = (u32)(0.5f + (aspectRatio * (f32)Output_Buffer->outputResolution));
    }

    *outputWidth = outputResolution_x;
    *outputHeight = outputResolution_y;

    ResizeImage(Output_Buffer->lodHigherBuffer, lodPixelResolution_x[0], lodPixelResolution_y[0], Output_Buffer->lodHigherResizeBuffer, outputResolution_x, outputResolution_y, 1);

    if (fillTwoImageBuffers)
    {
        ResizeImage(Output_Buffer->lodLowerBuffer, lodPixelResolution_x[1], lodPixelResolution_y[1], Output_Buffer->lodLowerResizeBuffer, outputResolution_x, outputResolution_y, 1);
        
        blend_images_thread_data data[4];
        u32 nPix = outputResolution_y * outputResolution_x;
        u32 halfPix = nPix >> 1;
        u32 quaterPix = halfPix >> 1;

        data[0].nPixToDo = quaterPix;
        data[0].startOffset = 0;
        data[0].blendWeight0 = lodBlendWeights[0];
        data[0].blendWeight1 = lodBlendWeights[1];
        
        data[1].nPixToDo = halfPix - data[0].nPixToDo;
        data[1].startOffset = data[0].nPixToDo;
        data[1].blendWeight0 = lodBlendWeights[0];
        data[1].blendWeight1 = lodBlendWeights[1];

        data[2].nPixToDo = quaterPix;
        data[2].startOffset = data[0].nPixToDo + data[1].nPixToDo;
        data[2].blendWeight0 = lodBlendWeights[0];
        data[2].blendWeight1 = lodBlendWeights[1];
        
        data[3].nPixToDo = nPix - data[0].nPixToDo - data[1].nPixToDo - data[2].nPixToDo;
        data[3].startOffset = data[0].nPixToDo + data[1].nPixToDo + data[2].nPixToDo;
        data[3].blendWeight0 = lodBlendWeights[0];
        data[3].blendWeight1 = lodBlendWeights[1];
        
        ThreadPoolAddTask(Thread_Pool, Blend_Images_Thread, (data + 0));
        ThreadPoolAddTask(Thread_Pool, Blend_Images_Thread, (data + 1));
        ThreadPoolAddTask(Thread_Pool, Blend_Images_Thread, (data + 2));
        ThreadPoolAddTask(Thread_Pool, Blend_Images_Thread, (data + 3));
        ThreadPoolWait(Thread_Pool);
    }

    {
        u32 nPix = outputResolution_x * outputResolution_y;
        u32 halfNPix = nPix >> 1;
        u32 quaterNPix = halfNPix >> 1;

        colourise_image_thread_data data[4];
        
        data[0].nPixToDo = quaterNPix;
        data[0].startOffset = 0;
        data[0].colourMapToUse = Colour_Map_Index;
        
        data[1].nPixToDo = halfNPix - data[0].nPixToDo;
        data[1].startOffset = data[0].nPixToDo;
        data[1].colourMapToUse = Colour_Map_Index;
        
        data[2].nPixToDo = quaterNPix;
        data[2].startOffset = data[0].nPixToDo + data[1].nPixToDo;
        data[2].colourMapToUse = Colour_Map_Index;

        data[3].nPixToDo = nPix - data[0].nPixToDo - data[1].nPixToDo - data[2].nPixToDo;
        data[3].startOffset = data[0].nPixToDo + data[1].nPixToDo + data[2].nPixToDo;
        data[3].colourMapToUse = Colour_Map_Index;

        ThreadPoolAddTask(Thread_Pool, Colourise_Image_Thread, (data + 0));
        ThreadPoolAddTask(Thread_Pool, Colourise_Image_Thread, (data + 1));
        ThreadPoolAddTask(Thread_Pool, Colourise_Image_Thread, (data + 2));
        ThreadPoolAddTask(Thread_Pool, Colourise_Image_Thread, (data + 3));
        ThreadPoolWait(Thread_Pool);
    }

    if (gridDrawContigRange)
    {
        memset((void *)Output_Buffer->outputImageBufferGridFillFlags, 0, NumOutputImageBufferGridFillFlags(Output_Buffer));
        
        u32 nTexels = Map_Properties->numberOfTextures1D * Map_Properties->textureResolution;

        fill_in_grid_thread_data data[4];

        data[0].contigStart_x = gridDrawContigRange[0];
        data[0].contigEnd_x = gridDrawContigRange[1];
        data[0].contigStart_y = gridDrawContigRange[2];
        data[0].contigEnd_y = gridDrawContigRange[3];
        data[0].nTexels = nTexels;
        data[0].texelStart_x = texelStart_x;
        data[0].texelRange_x = texelRange_x;
        data[0].texelStart_y = texelStart_y;
        data[0].texelRange_y = texelRange_y;
        data[0].resolution_x = outputResolution_x;
        data[0].resolution_y = outputResolution_y;
        data[1].contigStart_x = gridDrawContigRange[0];
        data[1].contigEnd_x = gridDrawContigRange[1];
        data[1].contigStart_y = gridDrawContigRange[2];
        data[1].contigEnd_y = gridDrawContigRange[3];
        data[1].nTexels = nTexels;
        data[1].texelStart_x = texelStart_x;
        data[1].texelRange_x = texelRange_x;
        data[1].texelStart_y = texelStart_y;
        data[1].texelRange_y = texelRange_y;
        data[1].resolution_x = outputResolution_x;
        data[1].resolution_y = outputResolution_y;
        data[2].contigStart_x = gridDrawContigRange[0];
        data[2].contigEnd_x = gridDrawContigRange[1];
        data[2].contigStart_y = gridDrawContigRange[2];
        data[2].contigEnd_y = gridDrawContigRange[3];
        data[2].nTexels = nTexels;
        data[2].texelStart_x = texelStart_x;
        data[2].texelRange_x = texelRange_x;
        data[2].texelStart_y = texelStart_y;
        data[2].texelRange_y = texelRange_y;
        data[2].resolution_x = outputResolution_x;
        data[2].resolution_y = outputResolution_y;
        data[3].contigStart_x = gridDrawContigRange[0];
        data[3].contigEnd_x = gridDrawContigRange[1];
        data[3].contigStart_y = gridDrawContigRange[2];
        data[3].contigEnd_y = gridDrawContigRange[3];
        data[3].nTexels = nTexels;
        data[3].texelStart_x = texelStart_x;
        data[3].texelRange_x = texelRange_x;
        data[3].texelStart_y = texelStart_y;
        data[3].texelRange_y = texelRange_y;
        data[3].resolution_x = outputResolution_x;
        data[3].resolution_y = outputResolution_y;

        u32 halfRes_x = outputResolution_x >> 1;
        u32 quaterRes_x = halfRes_x >> 1;
        u32 halfRes_y = outputResolution_x >> 1;
        u32 quaterRes_y = halfRes_x >> 1;

        data[0].startIndex_x = 0;
        data[0].startIndex_y = 0;
        data[0].indexRange_x = quaterRes_x;
        data[0].indexRange_y = quaterRes_y;

        data[1].startIndex_x = data[0].indexRange_x;
        data[1].startIndex_y = data[0].indexRange_y;
        data[1].indexRange_x = halfRes_x - data[0].indexRange_x;
        data[1].indexRange_y = halfRes_y - data[0].indexRange_y;

        data[2].startIndex_x = data[0].indexRange_x + data[1].indexRange_x;
        data[2].startIndex_y = data[0].indexRange_y + data[1].indexRange_y;
        data[2].indexRange_x = quaterRes_x;
        data[2].indexRange_y = quaterRes_y;

        data[3].startIndex_x = data[0].indexRange_x + data[1].indexRange_x + data[2].indexRange_x;
        data[3].startIndex_y = data[0].indexRange_y + data[1].indexRange_y + data[2].indexRange_y;
        data[3].indexRange_x = outputResolution_x - data[0].indexRange_x - data[1].indexRange_x - data[2].indexRange_x;
        data[3].indexRange_y = outputResolution_y - data[0].indexRange_y - data[1].indexRange_y - data[2].indexRange_y;

        data[0].doX = 1;
        data[1].doX = 1;
        data[2].doX = 1;
        data[3].doX = 1;
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 0));
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 1));
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 2));
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 3));
        ThreadPoolWait(Thread_Pool);

        data[0].doX = 0;
        data[1].doX = 0;
        data[2].doX = 0;
        data[3].doX = 0;
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 0));
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 1));
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 2));
        ThreadPoolAddTask(Thread_Pool, FillInGrid_Thread, (data + 3));
        ThreadPoolWait(Thread_Pool);
    }

FillImageExit:
    return(returnValue);
}

global_function
u32
FillImage(u32 texelStart, u32 texelRange, u32 *width, u32 *height, u32 *returnMessageIndex, u32 *gridDrawContigRange = 0)
{
    u32 gridDrawContigRangeRec[4];
    if (gridDrawContigRange)
    {
        gridDrawContigRangeRec[0] = gridDrawContigRange[0];
        gridDrawContigRangeRec[1] = gridDrawContigRange[1];
        gridDrawContigRangeRec[2] = gridDrawContigRange[0];
        gridDrawContigRangeRec[3] = gridDrawContigRange[1];
    }
    
    return(FillImage(texelStart, texelStart, texelRange, texelRange, width, height, returnMessageIndex, gridDrawContigRange ? (u32 *)gridDrawContigRangeRec : 0));
}

#ifndef _WIN32
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

global_function
u32
CreateOutputFolder(u08 *name, u08 *buffer, u08 **freeBufferPtr)
{
#ifndef _WIN32
    u08 sep = '/';
#else
    u08 sep = '\\';
#endif
    
    u08 buff_[128];
    if (name[0] != sep && name[0] != '.')
    {
        u08 *buff = (u08 *)buff_;
        *buff++ = '.';
        *buff++ = sep;
        CopyNullTerminatedString(name, buff);
    }
    else
    {
        CopyNullTerminatedString(name, (u08 *)buff_);
    }

    u08 *nameStart = name;
    u08 *ptr = buffer;
    while (*name) *ptr++ = *name++;
    *freeBufferPtr = ptr;
    u32 result = 0;
#ifndef _WIN32
    mkdir((char *)buff_, 0700);
    struct stat st = {};   
    result = !stat((char *)buff_, &st);
#else
    result = CreateDirectory((char *)buff_, NULL) || ERROR_ALREADY_EXISTS == GetLastError();
#endif

    if (!result)
    {
        PrintError("Could not create folder \'%s\'", nameStart);
    }
    
    return(result);
}

MainArgs
{
    s32 returnCode = EXIT_SUCCESS;

#ifndef _WIN32
    u08 sep = '/';
#else
    u08 sep = '\\';
#endif
    
    u32 texMinResolution;
    u32 outputBytes;
    memory_arena *textureBufferQueueArena;
    u32 textureBufferQueueTotalMemory = MegaByte(6);

    u08 inputFileName[1024];
    u32 inputMapSet = 0;
    
    Image_Type = png;
    u32 formatSet = 1;
    
    u32 outputResolution = 1080;
    u32 resolutionSet = 1;

    u08 outputPath[1024];
    u08 outputPrefix[1024];
    u08 *outputPrefixStart = 0;
    u08 *outputPrefixEnd = 0;
    u32 outputPathRemainingBuffer = ArrayCount(outputPath);
    u32 outputFolderSet = 0;
    u32 outputPrefixSet = 0;
    u32 outputFolderSetAttempt = 0;
    u32 outputPrefixSetAttempt = 0;

    char *targetOptions = 0;

    u32 minTexelsSet = 1;
    
    u32 gridSize = Default_Grid_Size;
    u32 gridSizeSet = 1;

    u32 gridColour = Default_Grid_Colour_sRGBA;
    u32 gridColourSet = 1;
    u32 colourMapSet = 1;
    u32 printSequenceNames = 0;
    
    u32 jpegQualitySet = 1;
    u32 jpegQualitySetAttempt = 0;
    char *jpegQualOption = 0;

    u32 verboseLevelSet = 1;
   
    u32 printHelp = 0;

    {
        static ko_longopt_t longOptions[] =
        {
            { (char *)"map",            ko_required_argument,   301 },
            { (char *)"format",         ko_required_argument,   302 },
            { (char *)"resolution",     ko_required_argument,   303 },
            { (char *)"folder",         ko_required_argument,   304 },
            { (char *)"prefix",         ko_required_argument,   305 },
            { (char *)"sequences",      ko_required_argument,   306 },
            { (char *)"minTexels",      ko_required_argument,   307 },
            { (char *)"gridSize",       ko_required_argument,   308 },
            { (char *)"gridColour",     ko_required_argument,   309 },
            { (char *)"colourMap",      ko_required_argument,   310 },
            { (char *)"printColourMapNames",  ko_no_argument,   311 },
            { (char *)"printSequenceNames",   ko_no_argument,   312 },
            { (char *)"jpegQuality",    ko_required_argument,   313 },
            { (char *)"verbose",        ko_required_argument,   314 },
	    { (char *)"version",        ko_no_argument,         315 },
            { (char *)"licence",        ko_no_argument,         316 },
            { (char *)"thirdParty",     ko_no_argument,         317 },
            { (char *)"help",           ko_no_argument,         318 },
            { (char *)"sequenceHelp",   ko_no_argument,         319 },
            { NULL, 0, 0 }
        };
        ketopt_t opt = KETOPT_INIT;
        s32 c;
        while ((c = ketopt(&opt, ArgCount, (char **)ArgBuffer, 1, "m:f:r:o:c:v:", longOptions)) >= 0)
        {
            switch (c)
            {
               case 'm':
               case 301:
                  {
                     inputMapSet = 1;
                     CopyNullTerminatedString((u08 *)opt.arg, inputFileName);
                  }
                  break;

               case 'f':
               case 302:
                  {
                     if (AreNullTerminatedStringsEqual((u08 *)"png", (u08 *)opt.arg)) Image_Type = png;
                     else if (AreNullTerminatedStringsEqual((u08 *)"bmp", (u08 *)opt.arg)) Image_Type = bmp;    
                     else if (AreNullTerminatedStringsEqual((u08 *)"jpg", (u08 *)opt.arg)) Image_Type = jpeg;
                     else if (AreNullTerminatedStringsEqual((u08 *)"jpeg", (u08 *)opt.arg)) Image_Type = jpeg;
                     else
                     {
                        formatSet = 0;
                        PrintError("Unknown format option: \'%s\'", opt.arg);
                     }
                  }
                  break;

               case 'r':
               case 303:
                  {
                     if (!StringToInt_Check((u08 *)opt.arg, &outputResolution) || !outputResolution)
                     {
                        PrintError("Cannot parse resolution option \'%s\' (positive integer required)", opt.arg);
                        resolutionSet = 0;
                     }
                  }
                  break;

               case 'o':
               case 304:
                  {
                     outputFolderSetAttempt = 1;
                     outputFolderSet = CreateOutputFolder((u08 *)opt.arg, (u08 *)outputPath, (u08 **)&outputPrefixStart);
                  }
                  break;

               case 305:
                  {
                     outputPrefixSetAttempt = 1;
                     outputPrefixSet = 1;
                     CopyNullTerminatedString((u08 *)opt.arg, (u08 *)outputPrefix);
                  }
                  break;

               case 306:
                  {
                     targetOptions = opt.arg;
                  }
                  break;

               case 307:
                  {
                     if (!StringToInt_Check((u08 *)opt.arg, &Min_Texels) || !Min_Texels)
                     {
                        PrintError("Cannot parse minTexels option \'%s\' (positive integer required)", opt.arg);
                        minTexelsSet = 0;
                     }
                  }
                  break;

               case 308:
                  {
                     if (!StringToInt_Check((u08 *)opt.arg, &gridSize))
                     {
                        PrintError("Cannot parse gridSize option \'%s\' (non-negative integer required)", opt.arg);
                        gridSizeSet = 0;
                     }
                  }
                  break;

               case 309:
                  {
                     gridColourSet = ProcessGridColourString(&gridColour, (u08 *)opt.arg);
                  }
                  break;

               case 'c':
               case 310:
                  {
                     colourMapSet = ProcessColourMapSelection(&Colour_Map_Index, (u08 *)opt.arg);
                  }
                  break;

               case 311:
                  {
                     if (ArgCount == 2)
                     {
                        ForLoop(Number_of_Colour_Maps)
                        {
                           fprintf(stdout, "%2d %s\n", index, Colour_Map_Names[index]);
                        }
                        goto end;
                     }
                  }
                  break;

               case 312:
                  {
                     if (ArgCount == 4) printSequenceNames = 1;
                  }
                  break;

               case 313:
                  {
                     jpegQualitySetAttempt = 1;
                     jpegQualOption = opt.arg;
                  }
                  break;

               case 'v':
               case 314:
                  {
                     u32 result = 4;
                     if (!StringToInt_Check((u08 *)opt.arg, &result) || result > 3)
                     {
                        PrintError("Cannot parse verbose option \'%s\', must be one of: 0 (none), 1 (errors), 2 (errors and warnings) or 3 (errors, warnings and status)", opt.arg);
                        verboseLevelSet = 0;
                     }
                     else
                     {
                        Verbose_Level = (verbose_level)result;
                     }
                  }
                  break;

               case 315:
                  {
                     if (ArgCount == 2)
                     {
                        fprintf(stdout, "%s\n", (char *)PretextSnapshot_Version);
                        goto end;
                     }
                  }
                  break;

               case 316:
                  {
                     if (ArgCount == 2)
                     {
                        fprintf(stdout, "%s\n", (char *)Licence);
                        goto end;
                     }
                  }
                  break;

               case 317:
                  {
                     if (ArgCount == 2)
                     {
                        fprintf(stdout, "%s\n", (char *)ThirdParty);
                        goto end;
                     }
                  }
                  break;

               case 318:
                  {   
                     if (ArgCount == 2) printHelp = 1;
                  }
                  break;

               case 319:
                  {
                     if (ArgCount == 2)
                     {
                        fprintf(stdout, "%s\n", (char *)Seq_Help);
                        goto end;
                     }
                  }
                  break;
            }
        }
    }
  
    if (printHelp || ArgCount == 1)
    {
       fprintf(stdout, "%s\n", (char *)Help);
       goto end;
    }

    if (!inputMapSet)
    {
        PrintError("Pretext map required");
    }
    else if ((!outputFolderSetAttempt || !outputPrefixSetAttempt) && !printSequenceNames)
    {
        u08 *name = (u08 *)inputFileName;
        u08 *nameBegin = name;
        while (*name++) {}
        while (*--name != '.' && name != nameBegin) {}
        u08 *nameStart = name;
        while (*nameStart != sep && nameStart != nameBegin) --nameStart;
        if (nameStart != nameBegin) ++nameStart;

        u08 buff[128];
        u08 *buff_ = (u08 *)buff;
        if (name != nameStart)
        {
            for (   u08 *ptr = nameStart;
                    ptr != name;
                    ++ptr )
            {
                *buff_++ = *ptr;
            }
        }
        else
        {
            while (*nameStart) *buff_++ = *nameStart++;
        }
        
        *buff_++ = '_';
        *buff_ = 0;

        if (!outputPrefixSetAttempt)
        {
            CopyNullTerminatedString((u08 *)buff, (u08 *)outputPrefix);
            outputPrefixSet = 1;
        }

        if (!outputFolderSetAttempt)
        {
            CopyNullTerminatedString((u08 *)"snapshots", (u08 *)buff_);
            outputFolderSet = CreateOutputFolder((u08 *)buff, (u08 *)outputPath, (u08 **)&outputPrefixStart);
        }
    }

    if (!printSequenceNames)
    {
       if (jpegQualitySetAttempt && Image_Type != jpeg)
       {
          PrintWarning("Ignoring jpeg quality option \'%s\', output format is %s", jpegQualOption, GetImageTypeName());
       }
       else if (jpegQualitySetAttempt)
       {
          if (!StringToInt_Check((u08 *)jpegQualOption, &JPEG_Quality) || JPEG_Quality < 1 || JPEG_Quality > 100)
          {
             PrintError("Cannot parse jpeg quality option \'%s\', must be an integer between 1 and 100", jpegQualOption);
             jpegQualitySet = 0;
          }
       }
    }

    if (!inputMapSet || ((!formatSet || !resolutionSet || !outputFolderSet || !outputPrefixSet || !minTexelsSet || !gridSizeSet || !gridColourSet ||
                !colourMapSet || !jpegQualitySet || !verboseLevelSet) && !printSequenceNames))
    {
       returnCode = EXIT_FAILURE;
       goto end;
    }

    if (outputPrefixSet)
    {
        *outputPrefixStart++ = sep;
        outputPrefixEnd = outputPrefixStart;
        u08 *ptr = (u08 *)outputPrefix;
        while (*ptr) *outputPrefixEnd++ = *ptr++;
        *outputPrefixEnd = 0;
        outputPathRemainingBuffer -= (u32)(outputPrefixEnd - (u08 *)outputPath);
    }

    PrintStatus("Input map: \'%s\'", inputFileName);
    if (!printSequenceNames)
    {
       PrintStatus("Output format: %s", GetImageTypeName());
       PrintStatus("Output resolution: %d pixels", outputResolution);
       PrintStatus("Colour map: %s", Colour_Map_Names[Colour_Map_Index]);
       PrintStatus("Minimum texels per image: %d", Min_Texels);
       PrintStatus("Grid size: %d pixel%s", gridSize, gridSize == 1 ? "" : "s");
       PrintStatus("Grid colour: %08x", RGBADisplayFormat(gridColour));
       PrintStatus("Output path: \'%s\'", outputPath);

       texMinResolution = Max(outputResolution, 1024);

       outputBytes = (u32)(((f32)(texMinResolution * texMinResolution) * 27.0f) + 0.5f);

       //CreateMemoryArena(Working_Set, (textureBufferQueueTotalMemory + outputBytes));
       CreateMemoryArena(Working_Set, MegaByte(16) + textureBufferQueueTotalMemory);
       Thread_Pool = ThreadPoolInit(&Working_Set, 4);
       Writing_Thread_Pool = ThreadPoolInit(&Working_Set, 1);
       Texture_Buffer_Queue = PushStruct(Working_Set, texture_buffer_queue);    

       Output_Buffer = PushStruct(Working_Set, output_buffer);
       Output_Buffer->outputResolution = outputResolution;
       Output_Buffer->outputImageBuffer[0] = PushArray(Working_Set, u08, 3 * outputResolution * outputResolution);
       Output_Buffer->outputImageBuffer[1] = PushArray(Working_Set, u08, 3 * outputResolution * outputResolution);
       Output_Buffer->outputImageBufferGridFillFlags = PushArray(Working_Set, volatile u08, NumOutputImageBufferGridFillFlags(Output_Buffer));
       Output_Buffer->outputBufferPtr = 0;
       Output_Buffer->lodLowerBuffer = PushArray(Working_Set, u08, texMinResolution * texMinResolution);
       Output_Buffer->lodHigherBuffer = PushArray(Working_Set, u08, 4 * texMinResolution * texMinResolution);
       Output_Buffer->lodHigherResizeBuffer = PushArray(Working_Set, u08, outputResolution * outputResolution);
       Output_Buffer->lodLowerResizeBuffer = PushArray(Working_Set, u08, outputResolution * outputResolution);

       //STB_Memory_Arena = PushSubArena(Working_Set, 12 * outputResolution * outputResolution);
       CreateMemoryArena(STB_Memory_Arena, 12 * outputResolution * outputResolution);
       STB_Compressor = libdeflate_alloc_compressor(12);
       textureBufferQueueArena = PushSubArena(Working_Set, textureBufferQueueTotalMemory);

       Avir_Thread_Pool = new avir_thread_pool();

       Grid = PushStruct(Working_Set, grid, 5);
       InitialiseGridColour(Grid, gridSize, gridColour);
    }
    else
    {
       CreateMemoryArena(Working_Set, MegaByte(4));
       textureBufferQueueArena = 0;
    }

    // load file
    {
        libdeflate_decompressor *decompressor = libdeflate_alloc_decompressor();
        u08 magic[] = {'p', 's', 't', 'm'};
        FILE *file;
        if ((file = fopen((const char *)inputFileName, "rb")))
        {
            u08 magicTest[sizeof(magic)];

            u32 bytesRead = (u32)fread(magicTest, 1, sizeof(magicTest), file);
            if (bytesRead == sizeof(magicTest))
            {
                ForLoop(sizeof(magic))
                {
                    if (magic[index] != magicTest[index])
                    {
                        fclose(file);
                        file = 0;
                        break;
                    }
                }
            }
            else
            {
                fclose(file);
                file = 0;
            }

            if (file)
            {
                u32 nBytesHeaderComp;
                u32 nBytesHeader;
                fread(&nBytesHeaderComp, 1, 4, file);
                fread(&nBytesHeader, 1, 4, file);
                u08 *header = PushArray(Working_Set, u08, nBytesHeader);
                u08 *compressionBuffer = PushArray(Working_Set, u08, nBytesHeaderComp);

                fread(compressionBuffer, 1, nBytesHeaderComp, file);
                if (!libdeflate_deflate_decompress(decompressor, (const void *)compressionBuffer, nBytesHeaderComp, (void *)header, nBytesHeader, NULL))
                {
                    FreeLastPush(Working_Set); // comp buffer

                    u64 val64;
                    u08 *ptr = (u08 *)&val64;
                    ForLoop(8)
                    {
                        *ptr++ = *header++;
                    }
                    u64 totalGenomeLength = val64;

                    u32 val32;
                    ptr = (u08 *)&val32;
                    ForLoop(4)
                    {
                        *ptr++ = *header++;
                    }
                    u32 numberOfContigs = val32;
                    
                    contig *contigs = PushArray(Working_Set, contig, (2 * numberOfContigs));
                    f32 cumulativeLength = 0.0f;
                    ForLoop(numberOfContigs)
                    {
                        contig *cont = contigs + index + numberOfContigs;
                        f32 frac;
                        u32 name[16];

                        ptr = (u08 *)&frac;
                        ForLoop2(4)
                        {
                            *ptr++ = *header++;
                        }

                        cont->fractionalLength = frac;
                        cont->previousCumulativeLength = cumulativeLength;
                        cumulativeLength += frac;

                        ptr = (u08 *)name;
                        ForLoop2(64)
                        {
                            *ptr++ = *header++;
                        }

                        ForLoop2(16)
                        {
                            cont->name[index2] = name[index2];
                        }
                    }

                    if (printSequenceNames)
                    {
                       ForLoop(numberOfContigs)
                       {
                          fprintf(stdout, "%s\n", (char *)((contigs + index + numberOfContigs)->name));
                       }
                       goto closeFileAndExit;
                    }

                    u08 textureRes = *header++;
                    u08 nTextRes = *header++;
                    u08 mipMapLevels = *header;

                    u32 textureResolution = Pow2(textureRes);
                    u32 numberOfTextures1D = Pow2(nTextRes);
                    u32 numberOfMipMaps = mipMapLevels;

                    u32 nBytesPerText = 0;
                    ForLoop(numberOfMipMaps)
                    {
                        nBytesPerText += Pow2((2 * textureRes--));
                    }
                    nBytesPerText >>= 1;
                    Bytes_Per_Texture = nBytesPerText;

                    FreeLastPush(Working_Set); // contigs
                    FreeLastPush(Working_Set); // header
                    
                    Map_Properties = PushStruct(Working_Set, map_properties);
                    Map_Properties->contigs = PushArray(Working_Set, contig, numberOfContigs);
                    u08 *source = (u08 *)(contigs + numberOfContigs);
                    u08 *dest = (u08 *)Map_Properties->contigs;

                    ForLoop(numberOfContigs * sizeof(contig))
                    {
                        *dest++ = *source++;
                    }

                    Map_Properties->totalGenomeLength = totalGenomeLength;
                    Map_Properties->numberOfContigs = numberOfContigs;
                    Map_Properties->textureResolution = textureResolution;
                    Map_Properties->numberOfTextures1D = numberOfTextures1D;
                    Map_Properties->numberOfMipMaps = numberOfMipMaps;

                    InitiateContigHashTable();
                    ForLoop(numberOfContigs)
                    {
                        InsertContigIntoHashTable(index, GetHashedContigName(Map_Properties->contigs + index));
                    }

                    u32 numberOfTextureBlocks = (Map_Properties->numberOfTextures1D + 1) * (Map_Properties->numberOfTextures1D >> 1);
                    
                    File_Atlas = PushArray(Working_Set, file_atlas_entry, numberOfTextureBlocks);

                    PrintStatus("Indexing file...");
                    u32 currLocation = sizeof(magic) + 8 + nBytesHeaderComp;
                    ForLoop(numberOfTextureBlocks)
                    {
                        file_atlas_entry *entry = File_Atlas + index;
                        u32 nBytes;
                        fread(&nBytes, 1, 4, file);
                        fseek(file, nBytes, SEEK_CUR);
                        currLocation += 4;

                        entry->base = currLocation;
                        entry->nBytes = nBytes;

                        currLocation += nBytes;
                    }
                    PrintStatus("File indexed");

                    fclose(file);
                    file = 0;

                    {
                        u32 messageIndex = 0;
                        if (InitialiseTextureBufferQueue(textureBufferQueueArena, Texture_Buffer_Queue, Bytes_Per_Texture, (const char *)inputFileName, &messageIndex))
                        {
                            PrintError(Messages[messageIndex]);
                            returnCode = EXIT_FAILURE;
                            goto closeFileAndExit;
                        }
                    }

                    image_target **targetHeadPtr = 0;
                    if (!ProcessImageTargetOptions(&targetHeadPtr, targetOptions))
                    {
                        returnCode = EXIT_FAILURE;
                        goto closeFileAndExit;
                    }
                    image_target *targetHead = *targetHeadPtr;

                    if (!targetHead)
                    {
                        PrintError("No images to process");
                        returnCode = EXIT_FAILURE;
                        goto closeFileAndExit;
                    }

                    {
                        u32 returnMessageIndex = 0;

                        u32 outputResolution_x = 0, outputResolution_y = 0;
                        u32 nTexels = Map_Properties->numberOfTextures1D * Map_Properties->textureResolution;

                        TraverseLinkedList(targetHead, image_target)
                        {
                            switch (node->type)
                            {
                                case full:
                                    {
                                        stbsp_snprintf((char *)outputPrefixEnd, (s32)outputPathRemainingBuffer, "FullMap");
                                        u32 gridContigRange[2] = {0, Map_Properties->numberOfContigs - 1};

                                        if (FillImage(0, nTexels, &outputResolution_x, &outputResolution_y, &returnMessageIndex, (u32 *)gridContigRange))
                                        {
                                            if (returnMessageIndex < Error_Warning_Divide_Message_Index_)
                                            {
                                                PrintError("Error while generating full map: %s", Messages[returnMessageIndex]);
                                                returnCode = EXIT_FAILURE;
                                            }
                                            else
                                            {
                                                PrintWarning("Warning while generating full map: %s", Messages[returnMessageIndex]);
                                            }
                                        }
                                        else if (WriteImage_Threaded((const char *)outputPath, outputResolution_x, outputResolution_y, 3, FilpCurrentOutputBuffer(Output_Buffer)))
                                        {
                                            PrintError(Messages[Image_Write_Error_Message_Index]);
                                            returnCode = EXIT_FAILURE;
                                        }

                                    }
                                    break;

                                case all:
                                    {
                                        ForLoop(Map_Properties->numberOfContigs)
                                        {
                                            contig *cont = Map_Properties->contigs + index;

                                            stbsp_snprintf((char *)outputPrefixEnd, (s32)outputPathRemainingBuffer, (const char *)cont->name);
                                            u32 startTexel = (u32)((f64)cont->previousCumulativeLength * (f64)nTexels);
                                            u32 texelRange = (u32)((f64)cont->fractionalLength * (f64)nTexels);
                                            if ((startTexel + texelRange) > nTexels) texelRange = nTexels - startTexel;

                                            if (FillImage(startTexel, texelRange, &outputResolution_x, &outputResolution_y, &returnMessageIndex))
                                            {
                                                if (returnMessageIndex < Error_Warning_Divide_Message_Index_)
                                                {
                                                    PrintError("Error while generating sequence map for \'%s\': %s", (const char *)cont->name, Messages[returnMessageIndex]);
                                                    returnCode = EXIT_FAILURE;
                                                }
                                                else
                                                {
                                                    PrintWarning("Warning while generating sequence map for \'%s\': %s", (const char *)cont->name, Messages[returnMessageIndex]);
                                                }
                                            }
                                            else if (WriteImage_Threaded((const char *)outputPath, outputResolution_x, outputResolution_y, 3, FilpCurrentOutputBuffer(Output_Buffer)))
                                            {
                                                PrintError(Messages[Image_Write_Error_Message_Index]);
                                                returnCode = EXIT_FAILURE;
                                            }
                                        }
                                    }
                                    break;

                                case other:
                                    {
                                        image_target_data *data = node->dataWrapper->data;
                                        u32 isSquare = node->dataWrapper->square;

                                        u32 texelStart_x = 0;
                                        u32 texelRange_x = 0;
                                        u32 texelStart_y = 0;
                                        u32 texelRange_y = 0;
                                        
                                        u32 fromClip_x = 0;
                                        u32 toClip_x = 0;
                                        u32 fromClip_y = 0;
                                        u32 toClip_y = 0;

                                        u32 contigIdxFrom_x = 0;
                                        u32 contigIdxTo_x = 0;
                                        u32 contigIdxFrom_y = 0;
                                        u32 contigIdxTo_y = 0;

                                        u32 bpFrom_x = 0;
                                        u32 bpTo_x = 0;
                                        u32 bpFrom_y = 0;
                                        u32 bpTo_y = 0;

                                        image_target_data_entry *entry = (data + 0)->from;
                                        u32 contigFrom = entry->contigIdx;
                                        u32 bpIdxFrom = entry->bpIdx;
                                        u32 clipFrom = entry->clip;
                                        entry = (data + 0)->to;
                                        u32 contigTo = entry->contigIdx;
                                        u32 bpIdxTo = entry->bpIdx;
                                        u32 clipTo = entry->clip;

                                        contigIdxFrom_x = contigFrom;
                                        contigIdxTo_x = contigTo;
                                        bpFrom_x = bpIdxFrom;
                                        bpTo_x = bpIdxTo;

                                        if (contigTo < contigFrom)
                                        {
                                            PrintError("Cannot accept map coordinates from \'%s\' to \'%s\', \'%s\' occurs after \'%s\' in the map", GetContigName(contigFrom), GetContigName(contigTo), GetContigName(contigFrom), GetContigName(contigTo));
                                            returnCode = EXIT_FAILURE;
                                            continue;
                                        }
                                        else if (contigFrom == contigTo && !clipFrom && !clipTo && bpIdxTo < bpIdxFrom)
                                        {
                                            PrintError("Cannot accept map coordinates from %d to %d in \'%s\', %d>%d", bpIdxFrom, bpIdxTo, GetContigName(contigFrom), bpIdxFrom, bpIdxTo);
                                            returnCode = EXIT_FAILURE;
                                            continue;
                                        }
                                        else
                                        {
                                            contig *contFrom = Map_Properties->contigs + contigFrom;
                                            contig *contTo = Map_Properties->contigs + contigTo;

                                            if (clipFrom)
                                            {
                                                texelStart_x = (u32)((f64)contFrom->previousCumulativeLength * (f64)nTexels);
                                                fromClip_x = 1;
                                            }
                                            else
                                            {
                                                f64 nBPFrom_f64 = (f64)contFrom->fractionalLength * (f64)Map_Properties->totalGenomeLength;
                                                f64 bpFrom_f64 = (f64)bpIdxFrom;
                                                if (bpFrom_f64 > nBPFrom_f64)
                                                {
                                                    PrintWarning("Clipping bp-coordinate %d to %d in \'%s\'", (u32)bpFrom_f64, (u32)nBPFrom_f64, GetContigName(contigFrom));
                                                    bpFrom_f64 = nBPFrom_f64;
                                                }
                                                
                                                texelStart_x = (u32)(((bpFrom_f64 + ((f64)contFrom->previousCumulativeLength * (f64)Map_Properties->totalGenomeLength))
                                                            / (f64)Map_Properties->totalGenomeLength) * (f64)nTexels);
                                                fromClip_x = 0;
                                            }

                                            u32 texelEnd_x;
                                            if (clipTo)
                                            {
                                                texelEnd_x = (u32)(((f64)contTo->previousCumulativeLength + (f64)contTo->fractionalLength) * (f64)nTexels);
                                                toClip_x = 1;
                                            }
                                            else
                                            {
                                                f64 nBPTo_f64 = (f64)contTo->fractionalLength * (f64)Map_Properties->totalGenomeLength;
                                                f64 bpTo_f64 = (f64)bpIdxTo;
                                                if (bpTo_f64 > nBPTo_f64)
                                                {
                                                    PrintWarning("Clipping bp-coordinate %d to %d in \'%s\'", (u32)bpTo_f64, (u32)nBPTo_f64, GetContigName(contigTo));
                                                    bpTo_f64 = nBPTo_f64;
                                                }

                                                texelEnd_x = (u32)(((bpTo_f64 + ((f64)contTo->previousCumulativeLength * (f64)Map_Properties->totalGenomeLength))
                                                            / (f64)Map_Properties->totalGenomeLength) * (f64)nTexels);
                                                toClip_x = 0;
                                            }
                                            
                                            texelRange_x = texelEnd_x > texelStart_x ? texelEnd_x - texelStart_x : 0;
                                        }

                                        if (!isSquare)
                                        {
                                            entry = (data + 1)->from;
                                            contigFrom = entry->contigIdx;
                                            bpIdxFrom = entry->bpIdx;
                                            clipFrom = entry->clip;
                                            entry = (data + 1)->to;
                                            contigTo = entry->contigIdx;
                                            bpIdxTo = entry->bpIdx;
                                            clipTo = entry->clip;
                                        
                                            contigIdxFrom_y = contigFrom;
                                            contigIdxTo_y = contigTo;
                                            bpFrom_y = bpIdxFrom;
                                            bpTo_y = bpIdxTo;
                                            
                                            if (contigTo < contigFrom)
                                            {
                                                PrintError("Cannot accept map coordinates from \'%s\' to \'%s\', \'%s\' occurs after \'%s\' in the map", GetContigName(contigFrom), GetContigName(contigTo), GetContigName(contigFrom), GetContigName(contigTo));
                                                returnCode = EXIT_FAILURE;
                                                continue;
                                            }
                                            else if (contigFrom == contigTo && !clipFrom && bpIdxTo < bpIdxFrom)
                                            {
                                                PrintError("Cannot accept map coordinates from %d to %d in \'%s\', %d>%d", bpIdxFrom, bpIdxTo, GetContigName(contigFrom), bpIdxFrom, bpIdxTo);
                                                returnCode = EXIT_FAILURE;
                                                continue;
                                            }
                                            else
                                            {
                                                contig *contFrom = Map_Properties->contigs + contigFrom;
                                                contig *contTo = Map_Properties->contigs + contigTo;

                                                if (clipFrom)
                                                {
                                                    texelStart_y = (u32)((f64)contFrom->previousCumulativeLength * (f64)nTexels);
                                                    fromClip_y = 1;
                                                }
                                                else
                                                {
                                                    f64 nBPFrom_f64 = (f64)contFrom->fractionalLength * (f64)Map_Properties->totalGenomeLength;
                                                    f64 bpFrom_f64 = (f64)bpIdxFrom;
                                                    if (bpFrom_f64 > nBPFrom_f64)
                                                    {
                                                        PrintWarning("Clipping bp-coordinate %d to %d in \'%s\'", (u32)bpFrom_f64, (u32)nBPFrom_f64, GetContigName(contigFrom));
                                                        bpFrom_f64 = nBPFrom_f64;
                                                    }

                                                    texelStart_y = (u32)(((bpFrom_f64 + ((f64)contFrom->previousCumulativeLength * (f64)Map_Properties->totalGenomeLength))
                                                                / (f64)Map_Properties->totalGenomeLength) * (f64)nTexels);
                                                    fromClip_y = 0;
                                                }

                                                u32 texelEnd_y;
                                                if (clipTo)
                                                {
                                                    texelEnd_y = (u32)(((f64)contTo->previousCumulativeLength + (f64)contTo->fractionalLength) * (f64)nTexels);
                                                    toClip_y = 1;
                                                }
                                                else
                                                {
                                                    f64 nBPTo_f64 = (f64)contTo->fractionalLength * (f64)Map_Properties->totalGenomeLength;
                                                    f64 bpTo_f64 = (f64)bpIdxTo;
                                                    if (bpTo_f64 > nBPTo_f64)
                                                    {
                                                        PrintWarning("Clipping bp-coordinate %d to %d in \'%s\'", (u32)bpTo_f64, (u32)nBPTo_f64, GetContigName(contigTo));
                                                        bpTo_f64 = nBPTo_f64;
                                                    }

                                                    texelEnd_y = (u32)(((bpTo_f64 + ((f64)contTo->previousCumulativeLength * (f64)Map_Properties->totalGenomeLength))
                                                                / (f64)Map_Properties->totalGenomeLength) * (f64)nTexels);
                                                    toClip_y = 0;
                                                }

                                                texelRange_y = texelEnd_y > texelStart_y ? texelEnd_y - texelStart_y : 0;
                                            }
                                        }

                                        char *namePtr = (char *)outputPrefixEnd;
                                        s32 bufferWritten;
                                        s32 remainingBuffer = (s32)outputPathRemainingBuffer;
                                        
                                        bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, "%s", GetContigName(contigIdxFrom_x));
                                        namePtr += bufferWritten;
                                        remainingBuffer -= bufferWritten;
                                        
                                        if (!fromClip_x)
                                        {
                                            bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, ":%d", bpFrom_x);
                                            namePtr += bufferWritten;
                                            remainingBuffer -= bufferWritten;
                                        }
                                        
                                        if (contigIdxFrom_x != contigIdxTo_x)
                                        {
                                            bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, "_to_%s", GetContigName(contigIdxTo_x));
                                            namePtr += bufferWritten;
                                            remainingBuffer -= bufferWritten;

                                            if (!toClip_x)
                                            {
                                                bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, ":%d", bpTo_x);
                                                namePtr += bufferWritten;
                                                remainingBuffer -= bufferWritten;
                                            }
                                        }
   
                                        if (!isSquare)
                                        {
                                            bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, "__vs__%s", GetContigName(contigIdxFrom_y));
                                            namePtr += bufferWritten;
                                            remainingBuffer -= bufferWritten;

                                            if (!fromClip_y)
                                            {
                                                bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, ":%d", bpFrom_y);
                                                namePtr += bufferWritten;
                                                remainingBuffer -= bufferWritten;
                                            }

                                            if (contigIdxFrom_y != contigIdxTo_y)
                                            {
                                                bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, "_to_%s", GetContigName(contigIdxTo_y));
                                                namePtr += bufferWritten;
                                                remainingBuffer -= bufferWritten;

                                                if (!toClip_y)
                                                {
                                                    bufferWritten = stbsp_snprintf(namePtr, remainingBuffer, ":%d", bpTo_y);
                                                    namePtr += bufferWritten;
                                                    remainingBuffer -= bufferWritten;
                                                }
                                            }
                                        }

                                        u32 gridContigRange[4] = {contigIdxFrom_x, contigIdxTo_x, isSquare ? contigIdxFrom_x : contigIdxFrom_y, isSquare ? contigIdxTo_x : contigIdxTo_y};

                                        if (FillImage(texelStart_x, isSquare ? texelStart_x : texelStart_y, texelRange_x, isSquare ? texelRange_x : texelRange_y, &outputResolution_x, &outputResolution_y, &returnMessageIndex, (u32 *)gridContigRange))
                                        {
                                            if (returnMessageIndex < Error_Warning_Divide_Message_Index_)
                                            {
                                                PrintError("Error while generating sequence map for \'%s\': %s", (const char *)outputPrefixEnd, Messages[returnMessageIndex]);
                                                returnCode = EXIT_FAILURE;
                                            }
                                            else
                                            {
                                                PrintWarning("Warning while generating sequence map for \'%s\': %s", (const char *)outputPrefixEnd, Messages[returnMessageIndex]);
                                            }
                                        }
                                        else if (WriteImage_Threaded((const char *)outputPath, outputResolution_x, outputResolution_y, 3, FilpCurrentOutputBuffer(Output_Buffer)))
                                        {
                                            PrintError(Messages[Image_Write_Error_Message_Index]);
                                            returnCode = EXIT_FAILURE;
                                        }
                                    }
                            }
                        }
                    }

                    ThreadPoolWait(Writing_Thread_Pool);
                    if (Write_Image_Threaded_Return_Value)
                    {
                        PrintError(Messages[Image_Write_Error_Message_Index]);
                        returnCode = EXIT_FAILURE;
                        goto closeFileAndExit;
                    }
                }
                else
                {
                    PrintError("Could not decompress header of \'%s\'", inputFileName);
                    returnCode = EXIT_FAILURE;
                }

closeFileAndExit:
                if (file) fclose(file);
                if (Texture_Buffer_Queue) CloseTextureBufferQueueFiles(Texture_Buffer_Queue);
            }
            else
            {
                PrintError("\'%s\' is not a pretext file", inputFileName);
                returnCode = EXIT_FAILURE;
            }
        }
        else
        {
            PrintError("Could not open \'%s\'", inputFileName);
            returnCode = EXIT_FAILURE;
        }
    }

    if (Thread_Pool)
    {
      ThreadPoolWait(Thread_Pool);
      ThreadPoolDestroy(Thread_Pool);
    }
    if (Writing_Thread_Pool)
    {
      ThreadPoolWait(Writing_Thread_Pool);
      ThreadPoolDestroy(Writing_Thread_Pool);
    }
end:
    return(returnCode);
}
