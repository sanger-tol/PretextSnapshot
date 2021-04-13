[![test](https://github.com/wtsi-hpag/PretextSnapshot/actions/workflows/test.yml/badge.svg)](https://github.com/wtsi-hpag/PretextSnapshot/actions/workflows/test.yml)
[![Anaconda-Server Badge](https://anaconda.org/bioconda/pretext-suite/badges/installer/conda.svg)](https://conda.anaconda.org/bioconda)
[![Anaconda-Server Badge](https://anaconda.org/bioconda/pretextsnapshot/badges/downloads.svg)](https://anaconda.org/bioconda/pretextsnapshot)
# PretextSnapshot
Commandline image generator for Pretext contact maps.

# Bioconda
All commandline Pretext tools for Unix (Linux and Mac) are available on [bioconda](https://bioconda.github.io/).<br/>

The full suite of Pretext tools can be installed with
```sh
> conda install pretext-suite
```
Or, just PretextSnapshot can be installed with
```sh
> conda install pretextsnapshot
```

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

# Third-Party acknowledgements
PretextSnapshot uses the following third-party libraries:<br/>
* [AVIR image resizing algorithm designed by Aleksey Vaneev](https://github.com/avaneev/avir)<br/>
* [avx_mathfun.h](http://software-lisc.fbk.eu/avx_mathfun/)<br/>
* [sse_mathfun.h](http://gruntthepeon.free.fr/ssemath/sse_mathfun.h)<br/>
* [kgetopt.h](https://github.com/attractivechaos/klib/blob/master/ketopt.h)<br/>
* [libdeflate](https://github.com/ebiggers/libdeflate)<br/>
* [mpc](https://github.com/orangeduck/mpc)<br/>
* [stb_image_write.h](https://github.com/nothings/stb/blob/master/stb_image_write.h)<br/>
* [stb_sprintf.h](https://github.com/nothings/stb/blob/master/stb_sprintf.h)

# Installation
Requires:
* clang >= 11.0.0
* meson >= 0.57.1
```bash
git submodule update --init --recursive
env CXX=clang meson setup --buildtype=release --unity on --prefix=<installation prefix> builddir
cd builddir
meson compile
meson test
meson install
```
