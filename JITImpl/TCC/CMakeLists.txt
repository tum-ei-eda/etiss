# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

project(TCCJIT)

add_library(${PROJECT_NAME} SHARED
    TCCJIT.cpp
    TCCJIT.h
    TCCJITLib.cpp
)

### configure tcc architecture
unset(TCCJIT_ARCH)
if(UNIX)
    set(TCCJIT_ARCH unix)
elseif(WIN32)
    set(PREBUILT_TOOL_PKGS_DIR "${PROJECT_SOURCE_DIR}/../toolpkgs")
    set(TCC_PKG tcc-0.9.27)

    if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
        set(TCCJIT_ARCH win64)
    else()
        set(TCCJIT_ARCH win32)
    endif()
else()
    message(ERROR "cannot build TCCJIT on this unknown system")
endif()

if(${TCCJIT_ARCH} STREQUAL unix)
    LIST(APPEND TCCJIT_ADDITIONAL_LIBRARIES
        tcc
        pthread
        dl
    )
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
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.h" DESTINATION include)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib" DESTINATION lib)
    install(FILES "${PROJECT_BINARY_DIR}/tcc_win64/libtcc.dll" DESTINATION lib)
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES ${${ETISS_PROJECT_NAME}_ADDITIONAL_LIBRARIES} ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib)
    set(${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES ${${ETISS_PROJECT_NAME}_ADDITIONAL_PROJECT_FILES} ${PROJECT_BINARY_DIR}/tcc_win64/libtcc/libtcc.def ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.dll ${PROJECT_BINARY_DIR}/tcc_win64/libtcc.lib)
    list(APPEND TCC_H_FILES "tcc/lib/libtcc1-64.a,${TCC_H_PATH}/lib/libtcc1-64.a")
    list(APPEND TCC_H_FILES "tcc/lib/gdi32.def,${TCC_H_PATH}/lib/gdi32.def")
    list(APPEND TCC_H_FILES "tcc/lib/kernel32.def,${TCC_H_PATH}/lib/kernel32.def")
    list(APPEND TCC_H_FILES "tcc/lib/msvcrt.def,${TCC_H_PATH}/lib/msvcrt.def")
    list(APPEND TCC_H_FILES "tcc/lib/user32.def,${TCC_H_PATH}/lib/user32.def")

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
if (NOT ${TCCJIT_ARCH} STREQUAL unix)
    file(GLOB_RECURSE TCC_H_FILES_TMP RELATIVE "${TCC_H_PATH}" "${TCC_H_PATH}/include/*")
    foreach(tccfile ${TCC_H_FILES_TMP})
        set(pp1 "tcc/${tccfile}")
        string(REGEX REPLACE ".*include/(.*)" "tcc_stdlib/\\1" pp1 ${pp1})
        set(pp2 "${TCC_H_PATH}/${tccfile}")
        list(APPEND TCC_H_FILES "${pp1},${pp2}")
    endforeach()
    RegisterJITFiles("${TCC_H_FILES}")

    if(${TCCJIT_ARCH} STREQUAL win64)
        add_dependencies(${PROJECT_NAME} gen_tcclib)
    endif()
endif()


target_link_libraries(${PROJECT_NAME} PUBLIC ${TCCJIT_ADDITIONAL_LIBRARIES})

ETISSPlugin(${PROJECT_NAME})
