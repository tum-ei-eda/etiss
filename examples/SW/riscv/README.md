# RISC-V Software Compilation

This file contains ctr0, linker script, Makefile (originally from plupino
project) for simple RISC-V software compilation

## Build
### Prerequisites
In order to compile riscv software, the following requirements has to be
met:

  - Toolchain path in Makefile has to point to correct cross-compile
  `toolchain`

  - To get the required libraries from pulpino project and additional
  instruction tests, either install Apache Subversion 
  (https://subversion.apache.org/) and run:

	$ make gitlib
    
  - Or get the libraries manually:
  1) Copy files from 
  https://github.com/pulp-platform/pulpino/tree/master/sw/libs/sys_lib
  to folder sys_lib
  2) Copy files from 
  https://github.com/pulp-platform/pulpino/tree/master/sw/libs/string_lib
  to folder string_lib
  3) Copy files from 
  https://github.com/cliffordwolf/picorv32/tree/master/tests
  to folder instr_tests

### RISC-V test cases

By default, benchmark provisioned with ETIS in `../test_cases`will be
compiled. Binary code and elf file will be located at `./build`. Minimal
dependent source code in `./sys_lib` is linked against final executable,
such as default interrupt handlers and exception handlers. Both of interrupt
handlers and exception handlers are for now just endless loop and they
could be overridden by user-defined handlers.

To compile the SW:

	$ make

### Instruction test software

In the folder `./instr_tests`, there are the test SWs which could be used
to test ISA model instruction by instruction. These SWs originates from
UCB and they cover integer, multiplication and compressed instructions.

 To compile instruction tests:

	$ (cd instr_tests; make all)

## More software in github

Softwares provided by pulpino project is also compatible with our model.

	$ git clone https://github.com/pulp-platform/pulpino.git

The software is located in ./pulpino/SW and they have their own cmake
compilation script (which does not work for now, modify it if in need.
Comment date: 15, Mar., 2018)
