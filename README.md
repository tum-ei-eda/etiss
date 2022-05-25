# ETISS (Extendable Translating Instruction Set Simulator)

[![Build Status](https://github.com/tum-ei-eda/etiss/workflows/CI/badge.svg)](https://github.com/tum-ei-eda/etiss/blob/master/.github/workflows/ci.yml)

ETISS is a C++ ISS (Instruction Set Simulator), which is designed to
simulate instructions for a target core on a host computer. It translates
binary instructions into C code and appends translated code into a block,
which will be compiled and executed at runtime. As aforementioned, it is
Extendable, thus it supports myriad level of customization by adopting the
technique of plug-ins. ETISS supports varied **Instruction Set Architectures
(ISAs)** according to user needs (see architecture models in `ArchImpl/`).
Meanwhile, the simulator could be enhanced with customized plug-ins to set
up many applications (see application examples in `examples/`).

<center> <img src="etiss.png" alt="ETISS diagram" width="520"> </center>

ETISS is structured as shown in the diagram above, and it is capable of
translating binary instructions according to loaded architecture models.
Furthermore, plug-ins could be developed to model new features of architecture
and be added flexibly without any hacking in the ETISS source code.

## Getting Started

The ETISS core and included plugins are built as libraries. To make use of the simulator, a program using the library is needed. A very simple bare-metal processor is included in this repository in [src/bare_etiss_processor](src/bare_etiss_processor). This program is built during the normal build process; its compiled binary will be placed under `<build_-_dir>/bin` and `<etiss_install_dir>/bin`. See its [README](src/bare_etiss_processor/README.md) for more details.


### System Requirements

ETISS is supported on x86_64 Linux and Windows hosts. Tested compilers include GCC 7.4 and MSVC 2019. CMake 3.13 is required as build system.

### Dependencies

  - GCC Compiler >= 5.0
  - Boost >= 1.54
  - Graphviz + Doxygen (For documentation generation)
  - LLVM + Clang 11 (Please download appropriate pre-built binaries from https://releases.llvm.org/download.html and put them in /opt/)

## LINUX SYSTEM

Packages for Ubuntu 18:

    sudo apt-get install g++ libboost-system-dev libboost-filesystem-dev libboost-program-options-dev graphviz doxygen libtinfo-dev zlib1g-dev texinfo

### Build and Installation

Follow these instructions to quickly build ETISS. Start in the root directory of ETISS by creating a build directory:

	$ mkdir build_dir

Change to the created directory, e.g.,

	$ cd build_dir

If LLVM-JIT compiler is used, source it with the environment variable:

	$ export LLVM_DIR=/path/to/llvm

Configure the build system, e.g.,
Replace `` `pwd`/installed`` with your `<etiss_install_path>` if you do not like to install etiss into `build_dir/installed/`. Set up path to cmake if necessary.

	$ cmake -DCMAKE_BUILD_TYPE=Release -DETISS_BUILD_MANUAL_DOC=ON \
	        -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/installed \
	        ..

Compile the package:

	$ make

Build the documentation (optional):

	$ make doc

Install the package:

	$ make install

To save time, compiling can be sped up by using multiple CPU cores:

	$ make -j$(nproc)

## WINDOWS SYSTEM

Requirements for Windows:

 - Install Visual Studio (2019 community edition). In the installer, select the component "Desktop development with C++". Here, under "Optional" make sure "C++ CMake tools for Windows" is selected.
 - Install Chocolately software from https://chocolatey.org/install

Packages for Windows:

 - choco install boost-msvc-14.2
 - choco install make
 - choco install git

   > NOTE: If developer powershell is not used, please also install the CMake package as follows:

   - choco install cmake --version=3.13.3

### Build and Installation

Follow these instructions to quickly build ETISS. The developer powershell of Visual Studio is recommended. Otherwise the environment PATH variable might have to be set accordingly to locate various tools. Start in the root directory of ETISS by creating a build directory:

	$ mkdir build_dir

Change to the created directory, e.g.,

	$ cd build_dir

Configure the build system:

	$ cmake -DCMAKE_BUILD_TYPE=Release -DETISS_BUILD_MANUAL_DOC=ON -DCMAKE_INSTALL_PREFIX:PATH=X:/install/path ..

Compile the package:

Compile in Release mode or Debug mode by setting $BUILD_TYPE to Release or Debug appropriately.

	$ cmake --build . --config $BUILD_TYPE

Install the package:

	$ cmake --build . --config $BUILD_TYPE --target install

## Example project to run etiss

Follow steps in `<etiss_install_path>/examples/README`

## Licensing and Copyright

See the separate `LICENSE` file to determine your rights and responsibilities
for using ETISS.

## User Documentation

The documentation is optionally built with ETISS and can be found in `<etiss_install_path>/doc/html/index.html`

It is also hosted at https://tum-ei-eda.github.io/etiss/
