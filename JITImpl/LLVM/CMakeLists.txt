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

find_package(LLVM CONFIG # 1st try only environment and LLVM_DIR
    NO_DEFAULT_PATH
    NO_SYSTEM_ENVIRONMENT_PATH
    PATHS ${LLVM_DIR}
)
if(NOT LLVM_FOUND) # 2nd try with system and default paths
    find_package(LLVM CONFIG)
endif()
if(NOT LLVM_FOUND)
    message(STATUS "Did not find LLVM... Skipping ${PROJECT_NAME} target.")
elseif((LLVM_FOUND AND LLVM_VERSION_MAJOR LESS 11))
    message(STATUS "Could find LLVM at ${LLVM_DIR}, but version ${LLVM_PACKAGE_VERSION}<11... Skipping ${PROJECT_NAME} target.")
else()
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} at ${LLVM_DIR}")
    string(REGEX MATCH "^[0-9]+" LLVM_VERSION_MAJOR "${LLVM_PACKAGE_VERSION}")

    find_package(Clang CONFIG # 1st try to find Clang in relation to found LLVM
        NO_DEFAULT_PATH
        NO_SYSTEM_ENVIRONMENT_PATH
        PATHS ${Clang_DIR_SEARCH} "${LLVM_DIR}/../../../lib/cmake/clang" "${LLVM_DIR}/../../clang/${LLVM_VERSION_MAJOR}"
    )
    if(NOT Clang_FOUND) # 2nd try with system and default paths
        find_package(Clang CONFIG)
    endif()
    if(NOT Clang_FOUND)
        message(STATUS "Did not find matching Clang... Skipping LLVMJIT target.")
    else()
        message(STATUS "Found Clang ${Clang_PACKAGE_VERSION} at ${Clang_DIR}")

        add_compile_definitions(LLVM_VERSION_MAJOR=${LLVM_VERSION_MAJOR})
        if(LLVM_VERSION_MAJOR LESS 13)
            set(LLVM_COMPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/llvm_compat/v11_12)
        elseif(LLVM_VERSION_MAJOR LESS 17)
            set(LLVM_COMPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/llvm_compat/v13_16)
        elseif(LLVM_VERSION_MAJOR LESS 20)
            set(LLVM_COMPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/llvm_compat/v17_19)
        else()
            set(LLVM_COMPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/llvm_compat/v20)
        endif()
        if(LLVM_VERSION_MAJOR GREATER 15 AND CMAKE_CXX_STANDARD LESS 17)
            message(FATAL_ERROR "LLVM_VERSION_MAJOR[${LLVM_VERSION_MAJOR}] requires c++std>=17! Is ${CMAKE_CXX_STANDARD}")
        endif()

        message(STATUS "Using LLVM compatibility layer: ${LLVM_COMPAT_DIR}")
        file(GLOB_RECURSE COMPAT_SRCS "${LLVM_COMPAT_DIR}/*.cpp")
    endif()
endif()

OPTION(ETISS_LINK_CLANG_DYLIB "Link against the clang dynamic library" ${CLANG_LINK_CLANG_DYLIB})
OPTION(ETISS_LINK_LLVM_DYLIB "Link against the llvm dynamic library" ${LLVM_LINK_LLVM_DYLIB})

IF(LLVM_FOUND AND Clang_FOUND)
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
        ${COMPAT_SRCS}
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

    TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include ${LLVM_INCLUDE_DIRS} ${LLVM_COMPAT_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/llvm_compat/)
ENDIF()
