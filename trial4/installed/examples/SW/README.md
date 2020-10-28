# Target Software

The code in this folder cannot be used directly. Once ETISS is build and 
installed, a copy of these files is available in the install 
directory:`<build_dir>/installed/examples/SW`

The target softwares for simulated architecture are located in this folder. 
Or1k and riscv directories contain boot code, linker script and Makefile
for each architecture respectively. These provided files serve as 
infrastructure when developing software. 

The source codes in `./test_cases` are benchmarks provisioned with ETISS 
project, which are called by main function in or1k and riscv software
as test example.

## Prerequisites
In order to compile target software for an simulated architecture, the 
following requirements has to be met:

  - Toolchain path in corresponding Makefile has to point to correct 
  cross-compile `toolchain`
  - Memory address space has to be correctly allocated in linker
  script for each system.
  - The Makefile split memory image into ROM and RAM, which should be 
  consistent with linker script.
  - The simulated memory space has to be greater than **0x80000000** 
  to support *cust_print()* fucntion, which provides feature to print 
  out in terminal.

## Documentation
  - RISCV: see README @`./riscv` 
  - Or1k: see README @`./or1k`
