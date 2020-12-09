#
#	Copyright 2018 Infineon Technologies AG
#
#	This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>
#
#	The initial version of this software has been created with the funding support by the German Federal
#	Ministry of Education and Research(BMBF) in the project EffektiV under grant 01IS13022.
#
#	Redistribution and use in source and binary forms, with or without modification, are permitted
#	provided that the following conditions are met:
#
#	1. Redistributions of source code must retain the above copyright notice, this list of conditions and
#	the following disclaimer.
#
# 	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
#	and the following disclaimer in the documentation and / or other materials provided with the distribution.
#
# 	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
# 	or promote products derived from this software without specific prior written permission.
#
#	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
#	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
#	PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
#	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
#	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING
#	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#	POSSIBILITY OF SUCH DAMAGE.
#
#
#	Author: Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#


PROJECT(LLVMJIT)

IF(NOT DEFINED ENV{LLVM_DIR})
    SET(ENV{LLVM_DIR} "/opt/clang+llvm-7.0.1-x86_64-linux-gnu-ubuntu-18.04")
ENDIF()

FIND_PACKAGE(LLVM 7 CONFIG)

IF(LLVM_FOUND)
    MESSAGE("Using LLVM_DIR: ${LLVM_DIR}")
    MESSAGE("LLVM Version: ${LLVM_VERSION}")

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
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
            clangFrontend
            clangSerialization
            clangDriver
            clangCodeGen
            clangParse
            clangSema
            clangAnalysis
            clangEdit
            clangAST
            clangLex
            clangBasic
            ${LLVM_LIBS}
        )
    ELSE()
        TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
            -Wl,--start-group
            ${LLVM_LIBS}
            clangFrontend
            clangCodeGen
            clangLex
            clangSerialization
            clangAST
            clangBasic
            clangSema
            clangEdit
            clangAnalysis
            clangDriver
            clangParse
            -Wl,--end-group
        )
    ENDIF()
    TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include ${LLVM_INCLUDE_DIRS})
ENDIF()
