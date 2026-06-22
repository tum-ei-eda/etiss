// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief defines the functions needed for a library that provides etiss::CPUArch implementations

        @see IntegratedLibrary.h shows how this header should be used

        @detail




*/
#ifndef ETISS_INCLUDE_HELPER_CPUARCHLIBRARY_H_
#define ETISS_INCLUDE_HELPER_CPUARCHLIBRARY_H_

#include "etiss/helper/Misc.h"

#include "etiss/Misc.h"

extern "C"
{

    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(
        ETISS_LIBNAME, _countCPUArch)(); ///< function to get number of CPUArch types supplied by a library
    ETISS_PLUGIN_EXPORT const char *etiss_helper_merge(ETISS_LIBNAME, _nameCPUArch)(
        unsigned index); ///< function to get the name of a CPUArch type at index
    ETISS_PLUGIN_EXPORT etiss::CPUArch *etiss_helper_merge(ETISS_LIBNAME, _createCPUArch)(
        unsigned index,
        std::map<std::string, std::string> options); ///< create new instance of the CPUArch type at index
    ETISS_PLUGIN_EXPORT void etiss_helper_merge(ETISS_LIBNAME, _deleteCPUArch)(etiss::CPUArch *); ///< delete instance
}

#endif
