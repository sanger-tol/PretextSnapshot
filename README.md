# PretextSnapshot
Commandline image generator for Pretext contact maps.

# Usage
PretextSnapshot -m map.pretext --sequences "sequences to image" [other options] <br/>
PretextSnapshot --help for a full list of options. <br/>
PretextSnapshot --sequenceHelp for how to format the sequence specification string. <br/>

# Examples
PretextSnapshot -m map.pretext --sequences "=full"  ::  Generates an image of the whole contact map.<br/>
PretextSnapshot -m map.pretext --sequences "=all"   ::  Generates an image of each sequence in the contact map.<br/>
PretextSnapshot -m map.pretext --sequences "seq_0"  ::  Generates an image of the sequence named "seq_0".<br/>
PretextSnapshot -m map.pretext --sequences "seq_0, seq_1"  ::  Generates an image of "seq_0" and an image of "seq_1".<br/>
PretextSnapshot -m map.pretext --sequences "seq_0 > seq_10" ::  Generates an image between "seq_0" and "seq_10".<br/>
PretextSnapshot -m map.pretext --sequences "{seq_0, seq_1}"::  Generates an image of the inter-sequence region between "seq_0" and "seq_1".<br/>

# Requirments, running
4 cpu cores <br/>
(30 * output image size) + 6M RAM, i.e. if your output resolution is set to 1K (1024 pixels) your memory requirments will be (30 * 1K * 1K) + 6M = 36M

# Windows, Mac and Linux builds
Prebuild binaries for Windows, Mac and Linux are available<br/>
The Mac binary was build on MacOS 10.13.6<br/>
The Linux binary was build on kernel 3.13<br/>
The Windows binary was build on Windows 10, and should work on at least Windows 7<br/>

# non-AVX builds
By default, all prebuild binaries use AVX instructions. Non-AVX versions are also available.<br/>
For optimal performance, AVX versions are recomended.

# Third-Party acknowledgements
PretextSnapshot uses the following third-party libraries:<br/>
    AVIR image resizing algorithm designed by Aleksey Vaneev (https://github.com/avaneev/avir)<br/>
    avx_mathfun.h (http://software-lisc.fbk.eu/avx_mathfun/)<br/>
    sse_mathfun.h (http://gruntthepeon.free.fr/ssemath/sse_mathfun.h)<br/>
    kgetopt.h (https://github.com/attractivechaos/klib/blob/master/ketopt.h)<br/>
    libdeflate (https://github.com/ebiggers/libdeflate)<br/>
    mpc (https://github.com/orangeduck/mpc)<br/>
    stb_image_write.h (https://github.com/nothings/stb/blob/master/stb_image_write.h)<br/>
    stb_sprintf.h (https://github.com/nothings/stb/blob/master/stb_sprintf.h)

# Requirments, building via script (Mac and Linux only)
make<br/>
python (2 or 3) to run the installation script<br/>
clang or gcc to compile<br/>

Tested on Ubuntu linux kernel 3.13 with clang-10, gcc-5.5<br/>
Tested on MacOS 10.13.6 with clang-10<br/>

PretextSnapshot requires libdeflate (https://github.com/ebiggers/libdeflate). By default the install script will clone and build the libdeflate.a static library for compilation with PretextSnapshot. You can specify your own version to the install script if you wish (you'll have to specify appropriate linking flags as well if you specify a shared library).

PretextSnapshot requires mpc (https://github.com/orangeduck/mpc). By default the install script will clone and build the libmpc.a static library for compilation with PretextSnapshot. You can specify your own version to the install script if you wish (you'll have to specify appropriate linking flags as well if you specify a shared library).

run ./install to build (run ./install -h to see options)

# Requirments, building on Windows
Only recomended if the prebuilt binary doesn't work for you and you know how to compile executables for Windows.<br/>

Tested on Windows 10 using the Visual Studio 2019 toolchain<br/>
Tested with clang-9<br/>

Requires libdeflate (https://github.com/ebiggers/libdeflate)<br/>
Requires mpc (https://github.com/orangeduck/mpc)<br/>

Compile PretextSnapshot.cpp and link against libdeflate and libmpc<br/>
