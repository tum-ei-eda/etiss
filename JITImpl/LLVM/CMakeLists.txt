# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

PROJECT(LLVMJIT)

IF(NOT DEFINED ENV{LLVM_DIR})
    SET(ENV{LLVM_DIR} "/opt/clang+llvm-11.0.0-x86_64-linux-gnu-ubuntu-20.04")
ENDIF()

IF(NOT DEFINED ENV{Clang_DIR})
    SET(ENV{Clang_DIR} $ENV{LLVM_DIR})
ENDIF()

FIND_PACKAGE(LLVM 11 CONFIG QUIET)
IF(NOT LLVM_FOUND)
    FIND_PACKAGE(LLVM 11.1 CONFIG QUIET)
ENDIF()

FIND_PACKAGE(Clang 11 CONFIG QUIET)
IF(NOT Clang_FOUND)
    FIND_PACKAGE(Clang 11.1 CONFIG QUIET)
ENDIF()

OPTION(ETISS_LINK_CLANG_DYLIB "Link against the clang dynamic library" ${CLANG_LINK_CLANG_DYLIB})
OPTION(ETISS_LINK_LLVM_DYLIB "Link against the llvm dynamic library" ${LLVM_LINK_LLVM_DYLIB})

IF(LLVM_FOUND)
    MESSAGE("Using LLVM_DIR: ${LLVM_DIR}")
    MESSAGE("LLVM Version: ${LLVM_VERSION}")
    MESSAGE("Clang DYLIB Link: ${ETISS_LINK_CLANG_DYLIB}")
    MESSAGE("LLVM DYLIB Link: ${ETISS_LINK_LLVM_DYLIB}")

    LINK_DIRECTORIES(${LLVM_LIBRARY_DIRS})
    ADD_DEFINITIONS(${LLVM_DEFINITIONS})
    llvm_map_components_to_libnames(LLVM_LIBS
        option
        object
        profiledata
        support
        core
        mc
        bitreader
        MCParser
        BinaryFormat
        ExecutionEngine
        Target
        MCJIT
        orcjit
        X86CodeGen
        X86AsmParser
        Interpreter
        passes
        coverage
        ObjCARCOpts
        LTO
        Coroutines
    )


    FILE(GLOB_RECURSE CLANG_INTERNAL_HEADERS ${LLVM_LIBRARY_DIRS}/clang/${LLVM_VERSION}/include/*.h)
    FOREACH(JITFILE ${CLANG_INTERNAL_HEADERS})
        STRING(REGEX REPLACE ".*/lib/clang/.*/include/(.*)" "clang_stdlib/\\1" TargetFile ${JITFILE})
        list(APPEND CLANG_JITFILES "${TargetFile},${JITFILE}")
    ENDFOREACH()
    RegisterJITFiles("${CLANG_JITFILES}")

    ADD_LIBRARY(${PROJECT_NAME} SHARED
        LLVMJITLIB.cpp
        src/LLVMJIT.cpp
    )
    ETISSPlugin(${PROJECT_NAME})

    if(ETISS_LINK_CLANG_DYLIB)
        TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC clang-cpp)
    else()
        TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
            clangCodeGen
            clangFrontend
            clangSerialization
            clangDriver
            clangParse
            clangSema
            clangAnalysis
            clangEdit
            clangAST
            clangLex
            clangBasic
        )
    endif()

    if(ETISS_LINK_LLVM_DYLIB)
        TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC LLVM)
    else()
        TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${LLVM_LIBS})
    endif()

    TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include ${LLVM_INCLUDE_DIRS})
ENDIF()
