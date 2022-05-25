#
#	Copyright 2018 Infineon Technologies AG
#
#	This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>
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
#	Author: Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.13 FATAL_ERROR)

PROJECT(ETISS)

# Disallow in-source builds
IF(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    MESSAGE(FATAL_ERROR "In-source builds are not allowed because they pollute the source tree with temporary files that might have to be deleted later. Please create a separate folder in which you run CMake.")
ENDIF()

set(ETISS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "ETISS build location")
# Declare ETISS version
set(ETISS_VERSION_MAJOR 0)
set(ETISS_VERSION_MINOR 8)
set(ETISS_VERSION_PATCH 0)

# Derived version variables
set(ETISS_VERSION_FULL ${ETISS_VERSION_MAJOR}.${ETISS_VERSION_MINOR}.${ETISS_VERSION_PATCH})
set(ETISS_VERSION ${ETISS_VERSION_FULL})
set(ETISS_VERSION_INTERFACE ${ETISS_VERSION_MAJOR}.${ETISS_VERSION_MINOR})

# Global project directories.
SET(ETISS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# Configuration
option(ETISS_USE_PYTHON "Support python within ETISS" OFF)
option(ETISS_BUILD_MANUAL_DOC "If enabled then the documentation will not be build by target all. run $make doc to create the documentation. default is ON for debug build OFF otherwise" ON)
option(ETISS_BUILD_DEFAULTSUB "If enabled then the ArchImpl,JITImpl,PluginImpl and projects folder will be added as subfolders. Please have a look at the CMakeLists.txt files of those folders for further information" ON)
option(ETISS_USE_PROFILEFLAGS "Enable or disable the -pg compiler and linker flags." OFF)

# Global configuration
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

IF(WIN32)
    IF(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        ADD_COMPILE_OPTIONS(/MP)  # parallel compilation
    ENDIF()
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)  # disable some microsoft warnings
    ADD_DEFINITIONS(-D_SCL_SECURE_NO_WARNINGS)  # disable some microsoft warnings
    ADD_DEFINITIONS(-DNOMINMAX)  # disable bad min and max macros
    ADD_DEFINITIONS(-DNOGDI)  # disable ERROR define
ELSE()
    # Define _DEBUG for debug builds like MSVC does.
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
    SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

    IF(BUILD_SANITIZE)
        SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
        SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
        SET(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined")
    ENDIF()

    # Set relative rpath to mimic runtime link behavior of windows (libs loadable from current dir)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    SET(CMAKE_INSTALL_RPATH "\$ORIGIN")


ENDIF()

# Support colored output for ninja generator.
IF(CMAKE_COLOR_MAKEFILE)
IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
ELSEIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")
ENDIF()

IF(ETISS_USE_PROFILEFLAGS)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
ENDIF()
ENDIF()

# Include modules.
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    "${ETISS_ROOT}/cmake"
)

INCLUDE(GenerateExportHeader)
INCLUDE(CheckCXXSourceCompiles)
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckSymbolExists)
INCLUDE(TestBigEndian)
INCLUDE(RegisterJITFiles)
INCLUDE(ETISSPlugin)

# Find packages
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE(Boost COMPONENTS filesystem system program_options REQUIRED)
FIND_PACKAGE(Doxygen)
IF(ETISS_USE_PYTHON)
    SET(Boost_VERBOSE ON)
    SET(Boost_DEBUG ON)
    FIND_PACKAGE(Python COMPONENTS Interpreter Development REQUIRED)
ENDIF()

# Define debug macro.
IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
    ADD_DEFINITIONS(-DETISS_DEBUG=1)
ENDIF()

LINK_DIRECTORIES("${Boost_LIBRARY_DIRS}")

IF(WIN32)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /wd4100")
ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")
ENDIF()


# Check build requirements.
IF(WIN32)
    SET(ETISS_USE_DLSYM OFF)
    SET(ETISS_USE_DLSYM_DEEPBIND OFF)
    SET(ETISS_USE_GETPROC ON)
    SET(ETISS_USE_BYTESWAP_H OFF)
    SET(ETISS_USE_POSIX_SOCKET OFF)
    SET(ETISS_USE_DLADDR OFF)

    CHECK_SYMBOL_EXISTS(GetProcAddress windows.h ETISS_CAN_USE_GETPROC)
    IF(NOT ETISS_CAN_USE_GETPROC)
        MESSAGE(FATAL_ERROR "Need GetProcAddress on Windows")
    ENDIF()
ELSE()
    SET(ETISS_USE_DLSYM ON)
    SET(ETISS_USE_DLSYM_DEEPBIND ON)
    SET(ETISS_USE_GETPROC OFF)
    SET(ETISS_USE_BYTESWAP_H OFF)
    SET(ETISS_USE_POSIX_SOCKET ON)
    SET(ETISS_USE_DLADDR ON)

    CHECK_INCLUDE_FILES(dlfcn.h ETISS_USE_DLSYM_CHECK)
    IF(NOT ETISS_USE_DLSYM_CHECK)
        MESSAGE(FATAL_ERROR "Need dlfcn.h on Linux")
    ENDIF()
    CHECK_CXX_SOURCE_COMPILES(
        "#include <dlfcn.h>\nint main(int,char**){ return (int) RTLD_DEEPBIND;}"
        ETISS_CAN_USE_DLSYM_DEEPBIND
    )
    IF(NOT ETISS_CAN_USE_DLSYM_DEEPBIND)
        #MESSAGE(FATAL_ERROR "Need RTLD_DEEPBIND on Linux")
    ENDIF()
    SET(CMAKE_REQUIRED_LIBRARIES dl)
    CHECK_CXX_SOURCE_COMPILES(
        "#include <dlfcn.h>\nint main(int,char**){ Dl_info i; return !dladdr((void*)main,&i);}"
        ETISS_CAN_USE_DLADDR
    )
    IF(NOT ETISS_CAN_USE_DLADDR)
        MESSAGE(FATAL_ERROR "Need dladdr on Linux")
    ENDIF()
    CHECK_INCLUDE_FILES(byteswap.h ETISS_CAN_USE_BYTESWAP_H)
    IF(NOT ETISS_CAN_USE_BYTESWAP_H)
        #MESSAGE(FATAL_ERROR "Need byteswap on Linux")
    ENDIF()
    CHECK_INCLUDE_FILES("string.h;errno.h;sys/types.h;sys/socket.h;netinet/in.h;netinet/tcp.h;unistd.h" ETISS_CAN_USE_POSIX_SOCKET)
    IF(NOT ETISS_CAN_USE_POSIX_SOCKET)
        MESSAGE(FATAL_ERROR "Need posix sockets on Linux")
    ENDIF()
ENDIF()

CHECK_CXX_SOURCE_COMPILES(
"constexpr int x() {return 1;} main(int,char**){ return x();}"
ETISS_USE_CONSTEXPR
)

TEST_BIG_ENDIAN(ETISS_ENDIANNESS)
if (NOT DEFINED ETISS_ENDIANNESS)
    message(WARNING "Failed to detect endianness. Assuming little endian")
    set(C_ETISS_ENDIANNESS ETISS_LITTLE_ENDIAN)
elseif(ETISS_ENDIANNESS)
    set(C_ETISS_ENDIANNESS ETISS_BIG_ENDIAN)
else()
    set(C_ETISS_ENDIANNESS ETISS_LITTLE_ENDIAN)
endif()


ADD_SUBDIRECTORY(src)


########### INSTALLATION ############

### config.h
configure_file(
    "${PROJECT_SOURCE_DIR}/include/etiss/config.h.in"
    "${PROJECT_BINARY_DIR}/include/etiss/config.h"
)
install(FILES ${PROJECT_BINARY_DIR}/include/etiss/config.h
        DESTINATION include/etiss)
unset(TMP_CONFIG_HEADER_REL)
file(GLOB TMP_CONFIG_HEADER_REL RELATIVE ${ETISS_ROOT} ${PROJECT_BINARY_DIR}/include/etiss/config.h)
set(ETISS_HEADER ${ETISS_HEADER} ${TMP_CONFIG_HEADER_REL})


include(FetchContent)
FetchContent_Declare(elfio_srcs
	GIT_REPOSITORY https://github.com/serge1/ELFIO.git
	GIT_TAG Release_3.6
)
if(NOT elfio_srcs_POPULATED)
	FetchContent_Populate(elfio_srcs)
	FetchContent_GetProperties(elfio_srcs)
endif()

### Doxyfile
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_BINARY_DIR}/include)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_BINARY_DIR}/include_c)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/include)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/include_c)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/src)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/ArchImpl)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/JITImpl)
set(ETISS_DOX_LOCATIONS ${ETISS_DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/PluginImpl)
 #if doxygen is available generate documentation
if(DOXYGEN_FOUND)
    string(REPLACE ";" " " P_ETISS_DOX_LOCATIONS "${ETISS_DOX_LOCATIONS}")
    string(REPLACE ";" "\n" C_ETISS_DOX_LOCATIONS "\"${ETISS_DOX_LOCATIONS}\"")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    if(ETISS_BUILD_MANUAL_DOC)
        add_custom_target(doc
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
    else()
        add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
    endif()
else()
    message(WARNING "Doxygen could not be found. target doc (e.g. make doc) will not be available")
endif()

# copy headers + doc files from include and include_c
install(	DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION include
FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
    PATTERN ".svn" EXCLUDE
    PATTERN "dox" EXCLUDE)

install(	DIRECTORY ${PROJECT_SOURCE_DIR}/include_c/
DESTINATION include
FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
    PATTERN ".svn" EXCLUDE)

# copy generated documentation
install(	DIRECTORY ${PROJECT_BINARY_DIR}/doc/
DESTINATION "doc"
OPTIONAL
FILES_MATCHING
    PATTERN "*")

# copy cmake files
set(INSTALL_CMAKE_DIR lib/CMake/ETISS CACHE PATH "Installation directory for CMake files")

# to allow linking with ETISS lib in build-tree
# copying headers
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${ETISS_BINARY_DIR}/include/)
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include_c/ DESTINATION ${ETISS_BINARY_DIR}/include/)
file(GLOB JIT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/jitlibs/**/*.h)
file(COPY ${JIT_HEADERS} DESTINATION ${ETISS_BINARY_DIR}/include/jit/etiss/jit/)
# plugins/list.txt file
file(WRITE ${ETISS_BINARY_DIR}/lib/plugins/list.txt)



############# TARGETS ##############

ADD_SUBDIRECTORY(ArchImpl)
ADD_SUBDIRECTORY(JITImpl)
ADD_SUBDIRECTORY(PluginImpl)

ADD_SUBDIRECTORY(examples)



# Register files required by the JIT engines.
FILE(GLOB_RECURSE ETISS_JITFILES_ADD RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_CURRENT_LIST_DIR}/include_c/*.h")
FOREACH(JITFILE ${ETISS_JITFILES_ADD})
    STRING(REGEX REPLACE ".*include_c/(.*)" "\\1" TargetFile ${JITFILE})
    list(APPEND ETISS_JITFILES "${TargetFile},${JITFILE}")
ENDFOREACH()
FILE(GLOB_RECURSE ETISS_JITFILES_ADD RELATIVE "${PROJECT_BINARY_DIR}" "${PROJECT_BINARY_DIR}/include_c/*.h")
FOREACH(JITFILE ${ETISS_JITFILES_ADD})
    STRING(REGEX REPLACE ".*include_c/(.*)" "\\1" TargetFile ${JITFILE})
    LIST(APPEND ETISS_JITFILES "${TargetFile},${PROJECT_BINARY_DIR}/${JITFILE}")
ENDFOREACH()
LIST(APPEND ETISS_JITFILES "etiss/pluginexport.h,${PROJECT_BINARY_DIR}/include/etiss/pluginexport.h")
RegisterJITFiles("${ETISS_JITFILES}")


SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
ADD_LIBRARY(ETISS SHARED
    ${ETISS_SOURCE} ${ETISS_HEADER}
)
set_target_properties(ETISS PROPERTIES
  COMPILE_DEFINITIONS "ETISS_LIB_SHARED=1;ETISS_EXPORTS;ETISS_PLUGIN_EXPORTS"
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/
)
IF(UNIX)
    TARGET_LINK_LIBRARIES(ETISS PUBLIC ${Boost_LIBRARIES})
ELSE(UNIX)
    TARGET_LINK_LIBRARIES(ETISS PUBLIC Boost::boost Threads::Threads)
ENDIF()
IF(WIN32)
    # Sadly CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS does not set -Wl,--export-all-symbols if gcc is sued
    IF(NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        TARGET_LINK_OPTIONS(ETISS PRIVATE -Wl,--export-all-symbols)
    ENDIF()
ELSE()
    TARGET_LINK_LIBRARIES(ETISS PUBLIC dl)
ENDIF()
IF(ETISS_USE_PYTHON)
    TARGET_LINK_LIBRARIES(ETISS PUBLIC Python::Interpreter Python::Python)
ENDIF()
TARGET_INCLUDE_DIRECTORIES(ETISS PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include_c"
    "${PROJECT_BINARY_DIR}/include_c"
    ${INCGEN_INC_DIR}
    ${elfio_srcs_SOURCE_DIR}
)

GENERATE_EXPORT_HEADER(ETISS
          BASE_NAME ETISS_PLUGIN
          EXPORT_MACRO_NAME ETISS_PLUGIN_EXPORT
          EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/include/etiss/pluginexport.h"
          DEPRECATED_MACRO_NAME ETISS_PLUGIN_DEPRECATED
          NO_EXPORT_MACRO_NAME ETISS_PLUGIN_NOEXPORT
          STATIC_DEFINE ETISS_PLUGIN_STATIC_DEFINE
          NO_DEPRECATED_MACRO_NAME ETISS_PLUGIN_NODEPRECATED
          DEFINE_NO_DEPRECATED
)

INSTALL(FILES ${PROJECT_BINARY_DIR}/include/etiss/pluginexport.h
        DESTINATION  include/etiss)
INSTALL(TARGETS ETISS DESTINATION lib)

# mimicing installation in build tree as well
file(COPY ${PROJECT_BINARY_DIR}/include/etiss/pluginexport.h DESTINATION ${PROJECT_BINARY_DIR}/include/jit/etiss/)

### create a list of plugin libraries in the install directory
string(REPLACE "." "\\\\." REGEX_CMAKE_SHARED_LIBRARY_SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
install(CODE "
    file(WRITE \"${CMAKE_INSTALL_PREFIX}/lib/plugins/list.txt\" \"\")
    ")



################ final cmake file generation #####################
### cmake package files
configure_file(
  "${PROJECT_SOURCE_DIR}/ETISSConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/ETISSConfig.cmake"
  @ONLY
 )
configure_file(
  "${PROJECT_SOURCE_DIR}/ETISSConfigVersion.cmake.in"
  "${PROJECT_BINARY_DIR}/ETISSConfigVersion.cmake"
  @ONLY
 )
install(FILES
  "${PROJECT_BINARY_DIR}/ETISSConfig.cmake"
  "${PROJECT_BINARY_DIR}/ETISSConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)



message(STATUS "ETISS_VERSION_FULL: ${ETISS_VERSION_FULL}")
message(STATUS "ETISS_USE_PYTHON: ${ETISS_USE_PYTHON}")
message(STATUS "ETISS_USE_PROFILEFLAGS: ${ETISS_USE_PROFILEFLAGS}")
message(STATUS "ETISS_USE_DLSYM: ${ETISS_USE_DLSYM}")
message(STATUS "ETISS_BUILD_MANUAL_DOC: ${ETISS_BUILD_MANUAL_DOC}")
