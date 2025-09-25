# ETISS (Extendable Translating Instruction Set Simulator)

[![Build Status](https://github.com/tum-ei-eda/etiss/actions/workflows/ci.yml/badge.svg)](https://github.com/tum-ei-eda/etiss/actions/workflows/ci.yml)
[![Documentation - GitHub Pages](https://github.com/tum-ei-eda/etiss/actions/workflows/docs.yml/badge.svg)](https://github.com/tum-ei-eda/etiss/actions/workflows/docs.yml)

ETISS is a C++ ISS (Instruction Set Simulator), which is designed to simulate instructions for a target core on a host computer. It translates binary instructions into C code and appends translated code into a block, which will be compiled and executed at runtime. As aforementioned, it is Extendable, thus it supports myriad level of customization by adopting the technique of plug-ins. ETISS supports varied **Instruction Set Architectures (ISAs)** according to user needs (see architecture models in `ArchImpl/`). Meanwhile, the simulator could be enhanced with customized plug-ins to set up many applications (see application examples in `examples/`).

<center> <img src="docs/etiss.png" alt="ETISS diagram" width="520"> </center>

ETISS is structured as shown in the diagram above, and it is capable of translating binary instructions according to loaded architecture models. Furthermore, plug-ins could be developed to model new features of architecture and be added flexibly without any hacking in the ETISS source code.

## Publication

If you use ETISS in your academic work you can cite it from this:

<details>
<summary>ETISS Publication</summary>
<p>

```
@inproceedings{Mueller-Gritschneder_ETISS_2017,
  author = {Mueller-Gritschneder, Daniel and Dittrich, Martin and Greim, Marc and Devarajegowda, Keerthikumara and Ecker, Wolfgang and Schlichtmann, Ulf},
  booktitle = {RSP '17: Proceedings of the 28th International Symposium on Rapid System Prototyping: Shortening the Path from Specification to Prototype},
  doi = {10.1145/3130265.3138858},
  pages = {79--84},
  publisher = {Association for Computing Machinery},
  series = {28th International Symposium on Rapid System Prototyping: Shortening the Path from Specification to Prototype},
  title = {{The Extendable Translating Instruction Set Simulator (ETISS) Interlinked with an MDA Framework for Fast RISC Prototyping}},
  url = {https://doi.org/10.1145/3130265.3138858},
  year = {2017}
}
```

</p>
</details>

## Getting Started

The ETISS core and included plugins are built as libraries. To make use of the simulator, a program using the library is needed. A very simple bare-metal processor is included in this repository in [src/bare_etiss_processor](src/bare_etiss_processor). This program is built during the normal build process; its compiled binary will be placed under `<build_-_dir>/bin` and `<etiss_install_dir>/bin`. See its [README](src/bare_etiss_processor/README.md) for more details.


### System Requirements

ETISS is built using C++ and verified to work on recent x86_64 Linux host systems. Windows hosts are currently only supported using WSL or similar virtualization methods.

### Dependencies

  - C++ 14 compliant compiler
  - Boost >= 1.54 development headers, specifically the sub-libraries:
    - boost-system
    - boost-filesystem
    - boost-program-options
  - CMake >= 3.13
  - Optional:
    - Graphviz + Doxygen (For documentation generation)
    - LLVM + Clang 11 (Please download appropriate pre-built binaries from https://releases.llvm.org/download.html and put them in /opt/)

## LINUX SYSTEM

Packages required for Ubuntu / Debian:

    build-essential git cmake libboost-system-dev libboost-filesystem-dev libboost-program-options-dev

### Build and Installation

Follow these instructions to quickly build ETISS. Start in the root directory of ETISS by creating a build directory:

	$ mkdir build_dir

Change to the created directory, e.g.,

	$ cd build_dir

If LLVM-JIT compiler is used, source it with the environment variable:

	$ export LLVM_DIR=/path/to/llvm

Configure the build system, e.g.,
Replace `` `pwd`/installed`` with your `<etiss_install_path>` if you do not like to install etiss into `build_dir/installed/`. Set up path to cmake if necessary. Replace `Release` with `Debug` for development purposes.

	$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=`pwd`/installed ..

Compile the package:

	$ make

Build the documentation (optional):

	$ make doc

Install the package:

	$ make install

To save time, compiling can be sped up by using multiple CPU cores:

	$ make -j$(nproc)

## WINDOWS SYSTEM

Running ETISS on Windows systems is currently only supported using WSL. The steps here are the same as for running on Linux.

## Example project to run ETISS

Example programs tailored to run in ETISS can be found in the repository https://github.com/tum-ei-eda/etiss_riscv_examples. Follow the README there to get started.

A minimal example on how to execute RISC-V Rust programs on ETISS can be found here: https://github.com/tum-ei-eda/etiss_riscv_rust_examples

## Licensing and Copyright

See the separate `LICENSE` file to determine your rights and responsibilities for using ETISS.

## User Documentation

The documentation is optionally built with ETISS and can be found in `<etiss_install_path>/doc/html/index.html`

It is also hosted at https://tum-ei-eda.github.io/etiss/
