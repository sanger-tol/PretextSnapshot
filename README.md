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

## Usage

```bash
PretextSnapshot -m map.pretext --sequences "<sequences to image>" [options]
```

| Option | Description |
|---|---|
| `-m` | Input contact map (`.pretext` file) |
| `--sequences` | Which sequence(s) or region(s) to render (see examples below) |
| `--help` | Show the full list of options |
| `--sequenceHelp` | Show how to format the sequence specification string |

## Examples

**Whole contact map**

```bash
PretextSnapshot -m map.pretext --sequences "=full"
```

**One image per sequence**

```bash
PretextSnapshot -m map.pretext --sequences "=all"
```

**A single sequence**

```bash
PretextSnapshot -m map.pretext --sequences "seq_0"
```

**Several sequences, one image each**

```bash
PretextSnapshot -m map.pretext --sequences "seq_0, seq_1"
```

**A range of sequences (from `seq_0` to `seq_10`)**

```bash
PretextSnapshot -m map.pretext --sequences "seq_0 > seq_10"
```

**Inter-sequence contacts between two sequences**

```bash
PretextSnapshot -m map.pretext --sequences "{seq_0, seq_1}"
```

## Sequence specification syntax

| Syntax | Meaning |
|---|---|
| `=full` | Entire contact map in a single image |
| `=all` | One image for every sequence |
| `seq_0` | Only the named sequence |
| `seq_0, seq_1` | Separate images for each listed sequence |
| `seq_0 > seq_10` | One image spanning all sequences from `seq_0` to `seq_10` |
| `{seq_0, seq_1}` | Contacts between `seq_0` and `seq_1` (off-diagonal region) |
# Custom order snapshots
To generate snapshots using a custom chromosome/scaffold/sequence order from a file:

```sh
PretextSnapshot -m map.pretext --order order.txt
```

The order file should list one sequence name per line (empty lines and `#` comments are ignored). By default, a single image is created with sequences displayed in the order file's order. Use `--per-sequence` for one image per sequence:

```sh
PretextSnapshot -m map.pretext --order order.txt --per-sequence
```

Example order file:

```
chr1
chr2
chr3
chrX
chrY
```

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
* g++ (or clang) >= 11.0.0
* meson >= 0.57.1
```bash
git submodule update --init --recursive
env CXX=g++ meson setup --buildtype=release --unity on builddir
cd builddir
meson compile
meson test
meson install
```
