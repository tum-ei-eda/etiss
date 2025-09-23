####################################################################################################
# Copyright 2023 Chair of EDA, Technical University of Munich
#
# Licensed under the Apache License, Version 2.0 (the License);
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
####################################################################################################

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
include(FetchContent)

####################################################################################################
# ELFIO (used for loading cross compiled ELFs to ETISS Memory Systems)
# Makes CMake target "elfio::elfio" aka "elfio" available
add_subdirectory(elfio)

####################################################################################################
# SimpleIni (used for loading cross compiled ELFs to ETISS Memory Systems)
# Makes CMake target "simpleini" aka "elfio" available
add_subdirectory(simpleini)

####################################################################################################
# (berkeley) softfloat (used for floating point support in JIT code)
# Makes CMake target berkeley-softfloat
add_subdirectory(softfloat)

####################################################################################################
# pugixml (used in fault injection plugins)
# Makes CMake target pugixml available
add_subdirectory(pugixml EXCLUDE_FROM_ALL)
####################################################################################################
# tcc (used in JITImpl)
# Makes CMake target TinyCC and tcc available (only UNIX)
if(UNIX)
    set(ETISS_TCC_SELINUX OFF CACHE BOOL "Enable SELinux support in the TCC JIT engine")
    include(ExternalProject)

    # Try to detect SELinux and check if it is active
    execute_process(
        COMMAND getenforce
        OUTPUT_VARIABLE ETISS_TCC_GETENFORCE_OUT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(ETISS_TCC_GETENFORCE_OUT STREQUAL "Enforcing")
        set(ETISS_TCC_SELINUX ON)
    endif()
    if(ETISS_TCC_SELINUX)
        set(ETISS_TCC_CONFIGURE_ARGS ${ETISS_TCC_CONFIGURE_ARGS} --with-selinux)
    endif()

    set(TCC_ADDITIONAL_CFLAGS "-Ofast -Wall")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(TCC_ADDITIONAL_CFLAGS "-Og -g -Wall")
    endif()

    set(TCCJIT_BINARY_DIR ${ETISS_BINARY_DIR}/include/jit/tcc)
    set(TinyCC_LIBNAME ${CMAKE_STATIC_LIBRARY_PREFIX}tcc${CMAKE_STATIC_LIBRARY_SUFFIX})
    set(TinyCC_STD_LIBNAME ${CMAKE_STATIC_LIBRARY_PREFIX}tcc1${CMAKE_STATIC_LIBRARY_SUFFIX})

    ExternalProject_Add(TinyCC
        URL "${CMAKE_CURRENT_SOURCE_DIR}/tcc"
    
        CONFIGURE_COMMAND bash <SOURCE_DIR>/configure
            --prefix=<TMP_DIR> # we do not care about TCC long term. Only stdlib will be installed manually
            "--extra-cflags=-fPIC ${TCC_ADDITIONAL_CFLAGS}"
            ${ETISS_TCC_CONFIGURE_ARGS}

        BUILD_COMMAND make -j ${CMAKE_BUILD_PARALLEL_LEVEL}
        BUILD_BYPRODUCTS <BINARY_DIR>/${CMAKE_STATIC_LIBRARY_PREFIX}tcc${CMAKE_STATIC_LIBRARY_SUFFIX}
                         <BINARY_DIR>/include

        INSTALL_COMMAND "" # we only need the standard library which can be copied
    )
    ExternalProject_Get_Property(TinyCC BINARY_DIR SOURCE_DIR)
    set(TinyCC_SOURCE_DIR ${SOURCE_DIR})
    set(TinyCC_BINARY_DIR ${BINARY_DIR})

    # Import tcc library from External Project
    add_library(tcc STATIC IMPORTED GLOBAL)
    set_property(TARGET tcc PROPERTY IMPORTED_LOCATION ${TinyCC_BINARY_DIR}/${TinyCC_LIBNAME})
    set_property(TARGET tcc PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${TinyCC_SOURCE_DIR}>
    )

    ###################################################################################################################
    # TCC JIT stdlib
    # Need to copy TCC's stdlib with headers manually, because they are only copied by TCC on `make install`.
    # ETISS Build JIT:
    add_custom_command(TARGET TinyCC POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${TinyCC_SOURCE_DIR}/include/" "${TCCJIT_BINARY_DIR}/../tcc_stdlib/"
        COMMAND ${CMAKE_COMMAND} -E copy "${TinyCC_BINARY_DIR}/${TinyCC_STD_LIBNAME}"
                                         "${TCCJIT_BINARY_DIR}/${TinyCC_STD_LIBNAME}"
        VERBATIM
        COMMENT "[TCC] Copy stdlib and headers to build JIT"
    )
    # ETISS install JIT:
    install(DIRECTORY ${TCCJIT_BINARY_DIR} DESTINATION "include/jit/" FILES_MATCHING REGEX "\.a")
    install(DIRECTORY ${TCCJIT_BINARY_DIR}/../tcc_stdlib DESTINATION "include/jit/" FILES_MATCHING REGEX "\.h")
endif()

####################################################################################################
# betternums (used in fault injection plugins)
# Makes CMake target betterenums available
set(betterenums_srcs_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/betterenums)
add_library(betterenums INTERFACE)
set_target_properties(betterenums PROPERTIES
    PUBLIC_HEADER "${betterenums_srcs_SOURCE_DIR}/enum.h"
)
target_include_directories(betterenums INTERFACE
    $<BUILD_INTERFACE:${betterenums_srcs_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/third_party/betterenums>
)
install(TARGETS betterenums
    PUBLIC_HEADER DESTINATION include/third_party/betterenums
)