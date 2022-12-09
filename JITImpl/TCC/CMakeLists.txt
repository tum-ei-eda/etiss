#
#    Copyright 2018 Infineon Technologies AG
#
#    This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>
#
#    The initial version of this software has been created with the funding support by the German Federal
#    Ministry of Education and Research(BMBF) in the project EffektiV under grant 01IS13022.
#
#    Redistribution and use in source and binary forms, with or without modification, are permitted
#    provided that the following conditions are met:
#
#    1. Redistributions of source code must retain the above copyright notice, this list of conditions and
#    the following disclaimer.
#
#     2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
#    and the following disclaimer in the documentation and / or other materials provided with the distribution.
#
#     3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
#     or promote products derived from this software without specific prior written permission.
#
#    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
#    WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
#    PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
#    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
#    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING
#    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#    POSSIBILITY OF SUCH DAMAGE.
#
#
#    Author: Chair of Electronic Design Automation, TUM
#
#    Version 0.2
#


project(TCCJIT)

set(ETISS_TCC_SELINUX OFF CACHE BOOL "Enable SELinux support in the TCC JIT engine")

add_library(${PROJECT_NAME} SHARED
    TCCJIT.cpp
    TCCJIT.h
    TCCJITLib.cpp
)

### configure tcc architecture
unset(TCCJIT_ARCH)
if(UNIX)
    set(TCCJIT_ARCH unix)

    # Try to detect SELinux and check if it is active
    execute_process(
        COMMAND getenforce
        OUTPUT_VARIABLE ETISS_TCC_GETENFORCE_OUT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(ETISS_TCC_GETENFORCE_OUT STREQUAL "Enforcing")
        set(ETISS_TCC_SELINUX ON)
    endif()
elseif(WIN32)
    if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
        set(TCCJIT_ARCH win64)
    else()
        set(TCCJIT_ARCH win32)
    endif()
else()
    message(ERROR "cannot build TCCJIT on this unknown system")
endif()

set(ETISS_TCC_CONFIGURE_ARGS "--with-libgcc")
if(ETISS_TCC_SELINUX)
    set(ETISS_TCC_CONFIGURE_ARGS ${ETISS_TCC_CONFIGURE_ARGS} --with-selinux)
endif()

include(FetchContent)
FetchContent_Declare(tcc_srcs
    GIT_REPOSITORY "https://github.com/TinyCC/tinycc"
    GIT_TAG "d0c26ba4e50a36779456af71b06ec01985e406e5"
)

if(NOT tcc_srcs_POPULATED)
    FetchContent_Populate(tcc_srcs)
    FetchContent_GetProperties(tcc_srcs)
    message(STATUS "[TCC] Fetch SOURCE_DIR: ${tcc_srcs_SOURCE_DIR}")
    message(STATUS "[TCC] Fetch BINARY_DIR: ${tcc_srcs_BINARY_DIR}")

    message(STATUS "[TCC] configure in build tree")
    set(INSTALL_DIR ${tcc_srcs_BINARY_DIR}/installed)

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(TCC_ADDITIONAL_CFLAGS "-Og;-g;-Wall")
    endif()
    execute_process(
        COMMAND bash ${tcc_srcs_SOURCE_DIR}/configure --prefix=${INSTALL_DIR} --extra-cflags=-fPIC;${TCC_ADDITIONAL_CFLAGS} ${ETISS_TCC_CONFIGURE_ARGS}
        WORKING_DIRECTORY ${tcc_srcs_BINARY_DIR}
        COMMAND_ECHO STDOUT
    )
    message(STATUS "[TCC] build in build tree")
    execute_process(
        COMMAND make
        WORKING_DIRECTORY ${tcc_srcs_BINARY_DIR}
        COMMAND_ECHO STDOUT
    )
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "[TCC] test in build tree")
        execute_process(
            COMMAND make test
            WORKING_DIRECTORY ${tcc_srcs_BINARY_DIR}
            COMMAND_ECHO STDOUT
        )
    endif()
    message(STATUS "[TCC] install in build tree")
    execute_process(
        COMMAND make install
        WORKING_DIRECTORY ${tcc_srcs_BINARY_DIR}
        COMMAND_ECHO STDOUT
    )
endif()

if (UNIX)
    target_include_directories(${PROJECT_NAME} PUBLIC ${INSTALL_DIR}/include)
    target_link_directories(${PROJECT_NAME} PUBLIC ${INSTALL_DIR}/lib)
    target_link_libraries(${PROJECT_NAME} PUBLIC tcc pthread dl)
elseif (WIN32)
    execute_process(
        COMMAND lib /DEF:<INSTALL_DIR>/libtcc/libtcc.def /MACHINE:X64 /OUT:<INSTALL_DIR>/libtcc.lib
        DEPENDEES install
    )
    target_include_directories(${PROJECT_NAME} PUBLIC ${INSTALL_DIR}/libtcc)
    target_link_directories(${PROJECT_NAME}
        PUBLIC ${INSTALL_DIR}/libtcc
        PUBLIC ${INSTALL_DIR}
    )
    target_link_libraries(${PROJECT_NAME} libtcc)
endif()

set(TCC_H_PATH "${INSTALL_DIR}/lib/tcc")
list(APPEND TCC_H_FILES "tcc/lib/libtcc1.a,${TCC_H_PATH}/libtcc1.a")
list(APPEND TCC_H_FILES "tcc/libtcc1.a,${TCC_H_PATH}/libtcc1.a")

file(GLOB_RECURSE TCC_H_FILES_TMP RELATIVE "${TCC_H_PATH}" "${TCC_H_PATH}/include/*")
foreach(tccfile ${TCC_H_FILES_TMP})
    set(pp1 "tcc/${tccfile}")
    string(REGEX REPLACE ".*include/(.*)" "tcc_stdlib/\\1" pp1 ${pp1})
    set(pp2 "${TCC_H_PATH}/${tccfile}")
    list(APPEND TCC_H_FILES "${pp1},${pp2}")
endforeach()

RegisterJITFiles("${TCC_H_FILES}")

ETISSPlugin(${PRO