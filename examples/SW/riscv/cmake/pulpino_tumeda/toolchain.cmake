set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR Pulpino)

IF(WIN32)
  set(EXE_EXT ".exe")
  set(DEFAULT_BASENAME "riscv64-unknown-elf")
  set(RISCV_ABI "ilp32d" CACHE STRING "mabi argument to the compiler")
ELSE()
  set(DEFAULT_BASENAME "riscv32-unknown-elf")
  set(RISCV_ABI "ilp32" CACHE STRING "mabi argument to the compiler")
ENDIF()

if(USE_VEXT)
  set(RISCV_ELF_GCC_PREFIX "/usr/local/research/projects/SystemDesign/tools/riscv/rv32imacv" CACHE PATH "install location for riscv-gcc toolchain")
  set(RISCV_ARCH "rv32imacv" CACHE STRING "march argument to the compiler")
elseif(USE_PEXT)
  set(RISCV_ELF_GCC_PREFIX "/nfs/TUEIEDAscratch/ga46peb/ma_mmo/rv32imac" CACHE PATH "install location for riscv-gcc toolchain")
  set(RISCV_ARCH "rv32imac" CACHE STRING "march argument to the compiler")
else()
  set(RISCV_ELF_GCC_PREFIX "/usr/local/research/projects/SystemDesign/tools/riscv/rv32imac" CACHE PATH "install location for riscv-gcc toolchain")
  set(RISCV_ARCH "rv32imac" CACHE STRING "march argument to the compiler")
endif()

set(RISCV_ELF_GCC_PREFIX "/usr/local/research/projects/SystemDesign/tools/riscv/current" CACHE PATH "install location for riscv-gcc toolchain")

set(RISCV_ELF_GCC_BASENAME ${DEFAULT_BASENAME} CACHE STRING "base name of the toolchain executables")

set(TC_PREFIX "${RISCV_ELF_GCC_PREFIX}/bin/${RISCV_ELF_GCC_BASENAME}-")
set(CMAKE_C_COMPILER ${TC_PREFIX}gcc${EXE_EXT})
set(CMAKE_CXX_COMPILER ${TC_PREFIX}g++${EXE_EXT})
set(CMAKE_ASM_COMPILER ${TC_PREFIX}gcc${EXE_EXT})
set(CMAKE_LINKER ${TC_PREFIX}ld${EXE_EXT})
set(CMAKE_OBJCOPY ${TC_PREFIX}objcopy${EXE_EXT})
set(CMAKE_AR ${TC_PREFIX}ar${EXE_EXT})
set(CMAKE_RANLIB ${TC_PREFIX}ranlib${EXE_EXT})

add_definitions(-D__riscv__)
add_definitions(-march=${RISCV_ARCH})
add_definitions(-mabi=${RISCV_ABI})

# The linker argument setting below will break the cmake test program on 64-bit, so disable test program linking for now.
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=${RISCV_ARCH} -mabi=${RISCV_ABI}")
