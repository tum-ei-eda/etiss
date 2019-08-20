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


PROJECT(TCCJIT)

### configure tcc architecture
unset(TCCJIT_ARCH)
if(UNIX)
    set(TCCJIT_ARCH unix)
elseif(WIN32)
    if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
        set(TCCJIT_ARCH win64)
    else()
        set(TCCJIT_ARCH win32)
    endif()
else()
    message(ERROR "cannot build TCCJIT on this unknown system")
endif()

#download and extract tcc (if neccessary)
if (NOT EXISTS ${PROJECT_BINARY_DIR}/tcc_${TCCJIT_ARCH})
    if(${TCCJIT_ARCH} STREQUAL unix)
        if (EXISTS ${PROJECT_SOURCE_DIR}/tcc-0.9.26.tar.bz2)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_SOURCE_DIR}/tcc-0.9.26.tar.bz2
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        else()
            file(DOWNLOAD http://download-mirror.savannah.gnu.org/releases/tinycc/tcc-0.9.26.tar.bz2 ${PROJECT_BINARY_DIR}/tcc-0.9.26.tar.bz2 SHOW_PROGRESS)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_BINARY_DIR}/tcc-0.9.26.tar.bz2
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        endif()
        file(RENAME ${PROJECT_BINARY_DIR}/tcc-0.9.26 ${PROJECT_BINARY_DIR}/tcc_unix)
        file(REMOVE ${PROJECT_BINARY_DIR}/tcc-0.9.26.tar.bz2)
        file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tcc_unix/build)
        execute_process(COMMAND ${PROJECT_BINARY_DIR}/tcc_unix/configure --extra-cflags=-fPIC
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tcc_unix/build)
        execute_process(COMMAND make
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tcc_unix/build)
    elseif(${TCCJIT_ARCH} STREQUAL win64)
        if (EXISTS ${PROJECT_SOURCE_DIR}/tcc-0.9.26.tar.bz2)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_SOURCE_DIR}/tcc-0.9.26-win64-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        else()
            file(DOWNLOAD http://download.savannah.gnu.org/releases/tinycc/tcc-0.9.26-win64-bin.zip ${PROJECT_BINARY_DIR}/tcc-0.9.26-win64-bin.zip SHOW_PROGRESS)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_BINARY_DIR}/tcc-0.9.26-win64-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        endif()
        file(RENAME ${PROJECT_BINARY_DIR}/tcc ${PROJECT_BINARY_DIR}/tcc_win64)
        file(REMOVE ${PROJECT_BINARY_DIR}/tcc-0.9.26-win64-bin.zip)
    elseif(${TCCJIT_ARCH} STREQUAL win32)
        if (EXISTS ${PROJECT_SOURCE_DIR}/tcc-0.9.26.tar.bz2)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_SOURCE_DIR}/tcc-0.9.26-win32-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        else()
            file(DOWNLOAD http://download.savannah.gnu.org/releases/tinycc/tcc-0.9.26-win32-bin.zip ${PROJECT_BINARY_DIR}/tcc-0.9.26-win32-bin.zip SHOW_PROGRESS)
            execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${PROJECT_BINARY_DIR}/tcc-0.9.26-win32-bin.zip
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        endif()
        file(RENAME ${PROJECT_BINARY_DIR}/tcc ${PROJECT_BINARY_DIR}/tcc_win32)
        file(REMOVE ${PROJECT_BINARY_DIR}/tcc-0.9.26-win32-bin.zip)
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
    include_directories("${PROJECT_BINARY_DIR}/tcc_win64/libtcc")
    set(TCC_H_PATH "${PROJECT_BINARY_DIR}/tcc_win64")
    add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib"
            COMMAND lib "/DEF:\"${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.def\"" /MACHINE:X64 /OUT:\"${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib\"
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            )
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.h"
            DESTINATION include)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib"
            DESTINATION lib)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.dll"
            DESTINATION lib)
    list(APPEND ETISS_FILES_LNK "${CMAKE_INSTALL_PREFIX}/lib/libtcc.lib")
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES ${${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES} ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib)
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES ${${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES} ${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.def ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.dll ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib)
    list(APPEND TCC_H_FILES "tcc/lib/libtcc1.a,${TCC_H_PATH}/lib/libtcc1.a")
    list(APPEND TCC_H_FILES "tcc/libtcc1.a,${TCC_H_PATH}/lib/libtcc1.a")
    list(APPEND ETISS_FILES_LNK "Dbghelp.lib")
elseif(${TCCJIT_ARCH} STREQUAL win32)
    include_directories("${PROJECT_BINARY_DIR}/tcc_win32/libtcc")
    set(TCC_H_PATH ${PROJECT_BINARY_DIR}/tcc_win32)
    add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib"
            COMMAND lib "/DEF:\"${PROJECT_BINARY_DIR}/tcc_win32/libtcc/libtcc.def\"" /MACHINE:X86 /OUT:\"${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib\"
            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
            )
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc/libtcc.h"
            DESTINATION include)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib"
            DESTINATION lib)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.dll"
            DESTINATION lib)
    list(APPEND ETISS_FILES_LNK "${CMAKE_INSTALL_PREFIX}/lib/libtcc.lib")
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES ${${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES} "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib")
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES ${${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES} "${PROJECT_BINARY_DIR}/tcc_win32/libtcc/libtcc.def" "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.dll" "${PROJECT_BINARY_DIR}/tcc_win32/libtcc.lib")
    list(APPEND TCC_H_FILES "tcc/lib/libtcc1.a,${TCC_H_PATH}/lib/libtcc1.a")
    list(APPEND TCC_H_FILES "tcc/libtcc1.a,${TCC_H_PATH}/lib/libtcc1.a")
    list(APPEND ETISS_FILES_LNK "Dbghelp.lib")
else()
    message(ERROR "Unknown TCCJIT_ARCH value")
endif()

###include headers

file(GLOB_RECURSE TCC_H_FILES_TMP RELATIVE "${TCC_H_PATH}" "${TCC_H_PATH}/include/*")
foreach(tccfile ${TCC_H_FILES_TMP})
    set(pp1 "tcc/${tccfile}")
    string(REGEX REPLACE ".*include/(.*)" "tcc_stdlib/\\1" pp1 ${pp1})
    file(TO_NATIVE_PATH "${TCC_H_PATH}/${tccfile}" pp2)
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
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${TCCJIT_ADDITIONAL_LIBRARIES} ${ETISS_FILES_LNK})
