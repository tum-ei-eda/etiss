set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR Pulpino)

IF(WIN32)
    set(EXE_EXT ".exe")
    set(RISCV_ELF_GCC_PREFIX "D:/a/etiss/riscv-tc" CACHE PATH "install location for riscv-gcc toolchain")
    set(RISCV_ELF_GCC_BASENAME "riscv64-unknown-elf" CACHE STRING "base name of the toolchain executables")
    set(RISCV_ARCH "rv32gc" CACHE STRING "march argument to the compiler")
    set(RISCV_ABI "ilp32d" CACHE STRING "mabi argument to the compiler")

    set(CMAKE_C_COMPILER D:/a/etiss/riscv-tc/bin/${RISCV_ELF_GCC_BASENAME}-gcc${EXE_EXT})
    set(CMAKE_CXX_COMPILER D:/a/etiss/riscv-tc/bin/${RISCV_ELF_GCC_BASENAME}-g++${EXE_EXT})
    set(CMAKE_OBJCOPY D:/a/etiss/riscv-tc/bin/${RISCV_ELF_GCC_BASENAME}-objcopy${EXE_EXT})

ELSE()
    set(RISCV_ELF_GCC_PREFIX "/usr/local/research/projects/SystemDesign/tools/riscv/current" CACHE PATH "install location for riscv-gcc toolchain")
    set(RISCV_ELF_GCC_BASENAME "riscv64-unknown-elf" CACHE STRING "base name of the toolchain executables")
    set(RISCV_ARCH "rv32gc" CACHE STRING "march argument to the compiler")
    set(RISCV_ABI "ilp32d" CACHE STRING "mabi argument to the compiler")

    set(TC_PREFIX "${RISCV_ELF_GCC_PREFIX}/bin/${RISCV_ELF_GCC_BASENAME}-")
    set(CMAKE_C_COMPILER ${TC_PREFIX}gcc${EXE_EXT})
    set(CMAKE_CXX_COMPILER ${TC_PREFIX}g++${EXE_EXT})
    set(CMAKE_ASM_COMPILER ${TC_PREFIX}gcc${EXE_EXT})
    set(CMAKE_LINKER ${TC_PREFIX}ld${EXE_EXT})
    set(CMAKE_OBJCOPY ${TC_PREFIX}objcopy${EXE_EXT})
    set(CMAKE_AR ${TC_PREFIX}ar${EXE_EXT})
    set(CMAKE_RANLIB ${TC_PREFIX}ranlib${EXE_EXT})
ENDIF()

add_definitions(-D__riscv__)
add_definitions(-march=${RISCV_ARCH})
add_definitions(-mabi=${RISCV_ABI})

# The linker argument setting below will break the cmake test program on 64-bit, so disable test program linking for now.
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=${RISCV_ARCH} -mabi=${RISCV_ABI}")
