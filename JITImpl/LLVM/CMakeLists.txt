# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

cmake_minimum_required(VERSION 3.16)
PROJECT(LLVMJIT)

if(NOT DEFINED LLVM_DIR)
    if(DEFINED ENV{LLVM_DIR})
        set(LLVM_DIR "$ENV{LLVM_DIR}")
    endif()
endif()

# 1st try only environment and LLVM_DIR
find_package(LLVM CONFIG NO_DEFAULT_PATH PATHS ${LLVM_DIR})
if(NOT LLVM_FOUND) # 2nd try with system and default paths
    find_package(LLVM CONFIG)
endif()
if(NOT LLVM_FOUND)
    message(STATUS "[${PROJECT_NAME}] Did not find LLVM... Skipping ${PROJECT_NAME} target.")
elseif((LLVM_FOUND AND LLVM_VERSION_MAJOR LESS 11))
    message(STATUS "[${PROJECT_NAME}] Could find LLVM at ${LLVM_DIR}, but version ${LLVM_PACKAGE_VERSION}<11... Skipping target.")
else()
    message(STATUS "[${PROJECT_NAME}] Found LLVM ${LLVM_PACKAGE_VERSION} at ${LLVM_DIR}")
    string(REGEX MATCH "^[0-9]+" LLVM_VERSION_MAJOR "${LLVM_PACKAGE_VERSION}")
    math(EXPR LLVM_VERSION_MAJOR_NEXT "${LLVM_VERSION_MAJOR} + 1" OUTPUT_FORMAT DECIMAL)
 
    if(NOT Clang_FOUND) # 1st try only in relation to found LLVM
        find_package(Clang CONFIG NO_DEFAULT_PATH PATHS "${LLVM_DIR}/../clang" "${LLVM_DIR}")
    endif()
    if(NOT Clang_FOUND) # 2nd try with system and default paths
        find_package(Clang CONFIG)
    endif()
    if(NOT Clang_FOUND)
        message(STATUS "[${PROJECT_NAME}] Did not find matching Clang... Skipping target.")
    else()
        message(STATUS "[${PROJECT_NAME}] Found Clang ${Clang_PACKAGE_VERSION} at ${Clang_DIR}")

        add_compile_definitions(LLVM_VERSION_MAJOR=${LLVM_VERSION_MAJOR})
        if(LLVM_VERSION_MAJOR GREATER 15 AND CMAKE_CXX_STANDARD LESS 17)
            message(FATAL_ERROR "LLVM_VERSION_MAJOR[${LLVM_VERSION_MAJOR}] requires c++std>=17! Is ${CMAKE_CXX_STANDARD}")
        endif()
    endif()
endif()

OPTION(ETISS_LINK_CLANG_DYLIB "Link against the clang dynamic library" ${CLANG_LINK_CLANG_DYLIB})
OPTION(ETISS_LINK_LLVM_DYLIB "Link against the llvm dynamic library" ${LLVM_LINK_LLVM_DYLIB})

IF(LLVM_FOUND AND Clang_FOUND)
    MESSAGE(STATUS "[${PROJECT_NAME}] Using LLVM_DIR: ${LLVM_DIR}")
    MESSAGE(STATUS "[${PROJECT_NAME}] LLVM Version: ${LLVM_VERSION}")
    MESSAGE(STATUS "[${PROJECT_NAME}] LLVM DYLIB Link: ${ETISS_LINK_LLVM_DYLIB}")
    MESSAGE(STATUS "[${PROJECT_NAME}] Using Clang_DIR: ${Clang_DIR}")
    MESSAGE(STATUS "[${PROJECT_NAME}] Using Clang_VERSION: ${Clang_VERSION}")
    MESSAGE(STATUS "[${PROJECT_NAME}] Clang DYLIB Link: ${ETISS_LINK_CLANG_DYLIB}")

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
        src/llvm_compat/llvm_compat.cpp
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

    TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include ${LLVM_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src/llvm_compat/)
ENDIF()
