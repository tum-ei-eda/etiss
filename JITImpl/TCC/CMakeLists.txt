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
#	Author: Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#


PROJECT(TCCJIT)

set(ETISS_TCC_SELINUX OFF CACHE BOOL "Enable SELinux support in the TCC JIT engine")

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

SET( PREBUILT_TOOL_PKGS_DIR "${PROJECT_SOURCE_DIR}/../toolpkgs")

SET(TCC_PKG tcc-0.9.27)

set(ETISS_TCC_CONFIGURE_ARGS "")
if(ETISS_TCC_SELINUX)
    set(ETISS_TCC_CONFIGURE_ARGS ${ETISS_TCC_CONFIGURE_ARGS} --with-selinux)
endif()
#download and extract tcc (if neccessary)
if (NOT EXISTS ${PROJECT_BINARY_DIR}/tcc_${TCCJIT_ARCH})
    if(${TCCJIT_ARCH} STREQUAL unix)
        if (EXISTS ${PROJECT_SOURCE_DIR}/${TCC_PKG}.tar.bz2)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_SOURCE_DIR}/${TCC_PKG}.tar.bz2
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        else()
            file(DOWNLOAD http://download-mirror.savannah.gnu.org/releases/tinycc/${TCC_PKG}.tar.bz2 ${PROJECT_BINARY_DIR}/${TCC_PKG}.tar.bz2 SHOW_PROGRESS)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_BINARY_DIR}/${TCC_PKG}.tar.bz2
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        endif()
        file(RENAME ${PROJECT_BINARY_DIR}/${TCC_PKG} ${PROJECT_BINARY_DIR}/tcc_unix)
        file(REMOVE ${PROJECT_BINARY_DIR}/${TCC_PKG}.tar.bz2)
        file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tcc_unix/build)
        set(ENV{CFLAGS} "-fPIC -Og -g -Wall")
        execute_process(COMMAND ${PROJECT_BINARY_DIR}/tcc_unix/configure ${ETISS_TCC_CONFIGURE_ARGS}
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tcc_unix/build)
        unset(ENV{CFLAGS})
        execute_process(COMMAND make
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tcc_unix/build)
    elseif(${TCCJIT_ARCH} STREQUAL win64)
        if (EXISTS ${PROJECT_SOURCE_DIR}/${TCC_PKG}-win64-bin.tar.bz2)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_SOURCE_DIR}/${TCC_PKG}-win64-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
			file(RENAME ${PROJECT_BINARY_DIR}/tcc ${PROJECT_BINARY_DIR}/tcc_win32)
			file(REMOVE ${PROJECT_BINARY_DIR}/${TCC_PKG}-win32-bin.zip)
		elseif(EXISTS ${PREBUILT_TOOL_PKGS_DIR}/${TCC_PKG}-win64-bin-with-import-lib.tar.bz2)
			# tarball created from ${PROJECT_BINARY_DIR} contents below
			message(STATUS "Using pre-prepared {TCC_PKG}-win64 package JITImpl/toolpkgs/${TCC_PKG}-win64-bin-with-import-lib.tar.bz2 for TCC JIT")
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PREBUILT_TOOL_PKGS_DIR}/${TCC_PKG}-win64-bin-with-import-lib.tar.bz2
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        else()
            file(DOWNLOAD http://download.savannah.gnu.org/releases/tinycc/${TCC_PKG}-win64-bin.zip ${PROJECT_BINARY_DIR}/${TCC_PKG}-win64-bin.zip SHOW_PROGRESS)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_BINARY_DIR}/${TCC_PKG}-win64-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
			file(RENAME ${PROJECT_BINARY_DIR}/tcc ${PROJECT_BINARY_DIR}/tcc_win64)
			file(REMOVE ${PROJECT_BINARY_DIR}/${TCC_PKG}-win64-bin.zip)
        endif()


    elseif(${TCCJIT_ARCH} STREQUAL win32)
        if (EXISTS ${PROJECT_SOURCE_DIR}/${TCC_PKG}.tar.bz2)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_SOURCE_DIR}/${TCC_PKG}-win32-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
			file(RENAME ${PROJECT_BINARY_DIR}/tcc ${PROJECT_BINARY_DIR}/tcc_win32)
			file(REMOVE ${PROJECT_BINARY_DIR}/${TCC_PKG}-win32-bin.zip)
		elseif(EXISTS ${PREBUILT_TOOL_PKGS_DIR}/${TCC_PKG}-win32-bin-with-import-lib.tar.bz2)
			# tarball created from ${PROJECT_BINARY_DIR} contents below
			message(STATUS "Using pre-prepared {TCC_PKG}-win64 package JITImpl/toolpkgs/${TCC_PKG}-win32-bin-with-import-lib.tar.bz2 for TCC JIT")
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PREBUILT_TOOL_PKGS_DIR}/${TCC_PKG}-win32-bin-with-import-lib.tar.bz2
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        else()
            file(DOWNLOAD http://download.savannah.gnu.org/releases/tinycc/${TCC_PKG}-win32-bin.zip ${PROJECT_BINARY_DIR}/${TCC_PKG}-win32-bin.zip SHOW_PROGRESS)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_BINARY_DIR}/${TCC_PKG}-win32-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
			file(RENAME ${PROJECT_BINARY_DIR}/tcc ${PROJECT_BINARY_DIR}/tcc_win32)
			file(REMOVE ${PROJECT_BINARY_DIR}/${TCC_PKG}-win32-bin.zip)
        endif()

    else()
        message(ERROR "Unknown TCCJIT_ARCH value")
    endif()

endif()

### add libraries
if(${TCCJIT_ARCH} STREQUAL unix)
    set(TCCJIT_ADDITIONAL_LIBRARIES ${TCCJIT_ADDITIONAL_LIBRARIES} "${PROJECT_BINARY_DIR}/tcc_unix/build/libtcc.a")
    include_directories("${PROJECT_BINARY_DIR}/tcc_unix")
    install(FILES "${PROJECT_BINARY_DIR}/tcc_unix/libtcc.h"
            DESTINATION include)
    set(TCC_H_PATH ${PROJECT_BINARY_DIR}/tcc_unix)
    list(APPEND TCC_H_FILES "tcc/lib/libtcc1.a,${TCC_H_PATH}/build/libtcc1.a")
    list(APPEND TCC_H_FILES "tcc/libtcc1.a,${TCC_H_PATH}/build/libtcc1.a")
elseif(${TCCJIT_ARCH} STREQUAL win64)
    LIST(APPEND TCCJIT_ADDITIONAL_LIBRARIES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib" "Dbghelp.lib")
    include_directories("${PROJECT_BINARY_DIR}/tcc_win64/libtcc")
    set(TCC_H_PATH "${PROJECT_BINARY_DIR}/tcc_win64")
	if(NOT EXISTS "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib")
		add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib"
			COMMAND lib "/DEF:\"${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.def\"" /MACHINE:X64 /OUT:\"${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib\"
			WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
		)
	endif()
    add_custom_target(gen_tcclib DEPENDS "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib")
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.h"
            DESTINATION include)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib"
            DESTINATION lib)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.dll"
            DESTINATION lib)
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES ${${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES} ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib)
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES ${${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES} ${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.def ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.dll ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib)
    list(APPEND TCC_H_FILES "tcc/lib/libtcc1-64.a,${TCC_H_PATH}/lib/libtcc1-64.a")
    list(APPEND TCC_H_FILES "tcc/lib/gdi32.def,${TCC_H_PATH}/lib/gdi32.def")
    list(APPEND TCC_H_FILES "tcc/lib/kernel32.def,${TCC_H_PATH}/lib/kernel32.def")
    list(APPEND TCC_H_FILES "tcc/lib/msvcrt.def,${TCC_H_PATH}/lib/msvcrt.def")
    list(APPEND TCC_H_FILES "tcc/lib/user32.def,${TCC_H_PATH}/lib/user32.def")
elseif(${TCCJIT_ARCH} STREQUAL win32)
    LIST(APPEND TCCJIT_ADDITIONAL_LIBRARIES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib" "Dbghelp.lib")
    include_directories("${PROJECT_BINARY_DIR}/tcc_win32/libtcc")
    set(TCC_H_PATH ${PROJECT_BINARY_DIR}/tcc_win32)
    add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib"
            COMMAND lib "/DEF:\"${PROJECT_BINARY_DIR}/tcc_win32/libtcc/libtcc.def\"" /MACHINE:X86 /OUT:\"${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib\"
            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
            )
    add_custom_target(gen_tcclib DEPENDS "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib")
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc/libtcc.h"
            DESTINATION include)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib"
            DESTINATION lib)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.dll"
            DESTINATION lib)
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES ${${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES} "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib")
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES ${${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES} "${PROJECT_BINARY_DIR}/tcc_win32/libtcc/libtcc.def" "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.dll" "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib")
    list(APPEND TCC_H_FILES "tcc/lib/libtcc1-32.a,${TCC_H_PATH}/lib/libtcc1-32.a")
    list(APPEND TCC_H_FILES "tcc/lib/gdi32.def,${TCC_H_PATH}/lib/gdi32.def")
    list(APPEND TCC_H_FILES "tcc/lib/kernel32.def,${TCC_H_PATH}/lib/kernel32.def")
    list(APPEND TCC_H_FILES "tcc/lib/msvcrt.def,${TCC_H_PATH}/lib/msvcrt.def")
    list(APPEND TCC_H_FILES "tcc/lib/user32.def,${TCC_H_PATH}/lib/user32.def")
else()
    message(ERROR "Unknown TCCJIT_ARCH value")
endif()

###include headers

file(GLOB_RECURSE TCC_H_FILES_TMP RELATIVE "${TCC_H_PATH}" "${TCC_H_PATH}/include/*")
foreach(tccfile ${TCC_H_FILES_TMP})
    set(pp1 "tcc/${tccfile}")
    string(REGEX REPLACE ".*include/(.*)" "tcc_stdlib/\\1" pp1 ${pp1})
    set(pp2 "${TCC_H_PATH}/${tccfile}")
    list(APPEND TCC_H_FILES "${pp1},${pp2}")
endforeach()
#string(REPLACE "winapi/winre.h" "winapi/winreg.h" TCC_H_FILES "${TCC_H_FILES}")
RegisterJITFiles("${TCC_H_FILES}")

ADD_LIBRARY(${PROJECT_NAME} SHARED
    TCCJIT.cpp
    TCCJIT.h
    TCCJITLib.cpp
)
ETISSPlugin(${PROJECT_NAME})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${TCCJIT_ADDITIONAL_LIBRARIES})

if(${TCCJIT_ARCH} STREQUAL win64)
    add_dependencies(${PROJECT_NAME} gen_tcclib)
endif()
