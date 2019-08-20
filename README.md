# ETISS (Extendable Translating Instruction Set Simulator)

ETISS is a C++ ISS (Instruction Set Simulator), which is designed to
simulate instructions for target core in host computer. It translates
binary instruction into C code and appends translated code into a block,
which will be compiled and executed at runtime. As aforementioned, it is
Extendable, thus it supports myriad level of customization by adopting the
technique of plug-in. ETISS supports varied **Instruction Set Architecture
(ISA)** according to user needs (see architecture models in `./ArchImpl`).
Meanwhile, the simulator could be enhanced with customized plug-ins to set
up many applications (see application examples in `./examples`).

<center> <img src="etiss.png" alt="ETISS diagram" width="520"> </center>

ETISS will be set up as shown in diagram above, and it is capable of
translating binary instruction according to loaded architecture models.
Furthermore, plug-in could be developed to model new features of architecture
and be added flexibly without any hacking in ETISS source code.

## Getting Started

ETISS has to be built into separate libraries, and a main file is needed
to set up simulator. After build and installation, the folder `./examples`
will be installed into `<etiss_install_dir>/examples` with correct
configuration. Check `README` in `<etiss_install_dir>/examples` respectively
to set up simulator for varied bare-metal simulations.

### System Requirements

ETISS currently could only be built on Linux OS.

  - Architectures:
    - x86 (32bit)
    - x86_64 (64bit)
  - Compilier:
    - GNU C++ Compilier
  - Build Environment:
    - Cmake (Minimum Version is cmake 3.13! check with cmake --version)

### Dependencies

  -  libstdc++ (make sure it is updated to latest version)
  -  gcc-multilib; g++-multilib
  -  zlib1g-dev
  -  libtinfo-dev
  -  graphviz; doxygen (For documentation generation)
  -  LLVM + Clang  <= LLVM3.4.2v API
  (If you want to use LLVM-JIT compiler then you have to setup <LLVM + Clang>
   toolchain somewhere on hostPC and source it (in a specific layout as provided
   in pre-build binaries on the download page of LLVM-Releases)
   Please have a look at <root/JITImpl/LLVM/Makefile> file for clarification
   Currently the ETISS source is compatible with <= LLVM3.4.2v API)
  - Boost library <= boost1.54


### Build and Installation

Follow the instructions to quickly build ETISS. As for detailed build
instructions for full featured ETISS, refer to `./INSTALL`, e.g. using verilator.

	$ mkdir build_dir

Change to the created directory, e.g.,

	$ cd build_dir

Configure the build system, e.g.,
Replace `pwd/installed` with your `<etiss_install_path>` if you do not like to install etiss into `/build_dir/installed`. Set up path to cmake if necessary.

> Note: If you want to use LLVM-JIT compiler, then
     also update the LLVM related variables in <root/JITImpl/LLVM/Makefile>
     accordingly

	$ cmake -DCMAKE_BUILD_TYPE=Release -DETISS_BUILD_MANUAL_DOC=ON \
	        -DETISS_USE_PYTHON=OFF -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/installed \
	        --graphviz=test.dot -G "CodeBlocks - Unix Makefiles" ../

Compile the package:

	$ make

Build the documentation (optional):

	$ make doc

Install the package :

	$ make install

## Example project to run etiss

Go into `<etiss_install_path>/examples`
Follow steps in `<etiss_install_path>/examples/README`

## Licensing and Copyright

See the separate `./LICENSE` file to determine your rights and responsibilities
for using ETISS.

## User Documentation

The documentation is build with ETISS and can be found in `<etiss_install_path>/doc/html/index.html`
