# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

SET(ENABLE_JIT_GCC
    ON
    CACHE BOOL "Whether to enable GCC JIT"
)
SET(ENABLE_JIT_LLVM
    ON
    CACHE BOOL "Whether to enable LLVM JIT"
)
SET(ENABLE_JIT_TCC
    ON
    CACHE BOOL "Whether to enable LLVM JIT"
)

IF("${ENABLE_JIT_GCC}")
ADD_SUBDIRECTORY(GCC)
ENDIF()

IF("${ENABLE_JIT_LLVM}")
ADD_SUBDIRECTORY(LLVM)
ENDIF()

IF("${ENABLE_JIT_TCC}")
ADD_SUBDIRECTORY(TCC)
ENDIF()
