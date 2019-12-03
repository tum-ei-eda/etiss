set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR Pulpino)

#set(RISCV_ELF_GCC_PREFIX "/usr/local/research/projects/SystemDesign/tools/riscv/current" CACHE PATH "install location for riscv-gcc toolchain")
set(RISCV_ELF_GCC_PREFIX "F:/gcc-riscv" CACHE PATH "install location for riscv-gcc toolchain")
set(CMAKE_C_COMPILER ${RISCV_ELF_GCC_PREFIX}/bin/riscv64-unknown-elf-gcc.exe)
set(CMAKE_CXX_COMPILER ${RISCV_ELF_GCC_PREFIX}/bin/riscv64-unknown-elf-g++.exe)
set(CMAKE_OBJCOPY ${RISCV_ELF_GCC_PREFIX}/bin/riscv64-unknown-elf-objcopy.exe)

add_definitions(-D__riscv__)
add_definitions(-march=rv32imac)
add_definitions(-mabi=ilp32)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=rv32imac -mabi=ilp32")
