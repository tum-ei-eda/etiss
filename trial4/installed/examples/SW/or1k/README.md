# open risc Software Compilation

This file contains board, linker script, Makefile for simple or1k software compilation

## Build
### Prerequisites
In order to compile or1k software, the following requirement has to be
met:

  - Toolchain path in Makefile has to point to correct cross-compile
  `toolchain`

### or1k test cases

By default, benchmark provisioned with ETIS in `../test_cases`will be
compiled. Binary code and elf file will be located at `./build`. Minimal
dependent source code in `./sys_lib` is linked against final executable,
such as default interrupt handlers and exception handlers. Both of interrupt
handlers and exception handlers are for now just endless loop and they
could be overridden by user-defined handlers.

To compile the SW:

	$ make
