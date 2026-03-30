# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

PROJECT(GCCJIT)

FIND_PROGRAM(GCC_AVAILABLE gcc)
# Currently not ported to support MINGW on Windows
IF(GCC_AVAILABLE AND NOT WIN32)
    ADD_LIBRARY(${PROJECT_NAME} SHARED
        GCCJIT.h

        GCCJIT.cpp
        GCCJITLIB.cpp
    )
    ETISSPlugin(${PROJECT_NAME})
ENDIF()
