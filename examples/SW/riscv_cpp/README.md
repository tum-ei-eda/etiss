# RISC-V Software Compilation for C++

This file contains ctr0, linker script, Makefile (originally from plupino
project) for simple RISC-V software compilation using C++

## Build
### Prerequisites
In order to compile riscv software, the following requirements has to be
met:

  - Toolchain path in Makefile has to point to correct cross-compile
  `toolchain`

  - To get the required libraries from pulpino project and additional
  instruction tests, run:

	$ make gitlib

### RISC-V target software

The target software runs some basic C++ specific tests. Binary code and elf file will be located at `./build`. Minimal
dependent source code in `./sys_lib` is linked against final executable,
such as default interrupt handlers and headers. Interrupt
handlers are for now just endless loop and they
could be overridden by user-defined handlers.

To compile the SW:

	$ make
