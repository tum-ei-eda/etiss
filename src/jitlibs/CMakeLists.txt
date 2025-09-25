# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

MACRO(InstallJitLib TARGET_NAME)
    set_property(GLOBAL APPEND PROPERTY etiss_jitlibs ${TARGET_NAME})
    INSTALL(TARGETS ${TARGET_NAME} DESTINATION include/jit/etiss/jit)
ENDMACRO()

ADD_SUBDIRECTORY(softfloat)
ADD_SUBDIRECTORY(resources)
ADD_SUBDIRECTORY(semihost)
ADD_SUBDIRECTORY(CSRCounters)
