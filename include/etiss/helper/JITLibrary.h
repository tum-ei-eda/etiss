// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief defines the functions needed for a library that provides etiss::JIT implementations

        @see IntegratedLibrary.h shows how this header should be used

        @detail




*/
#ifndef ETISS_INCLUDE_HELPER_JITLIBRARY_H_
#define ETISS_INCLUDE_HELPER_JITLIBRARY_H_

#include "etiss/helper/Misc.h"

#include "etiss/JIT.h"

extern "C"
{

    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(
        ETISS_LIBNAME, _countJIT)(); ///< function to get number of jit types supplied by a library
    ETISS_PLUGIN_EXPORT const char *etiss_helper_merge(ETISS_LIBNAME, _nameJIT)(
        unsigned index); ///< function to get the name of a jit type at index
    ETISS_PLUGIN_EXPORT etiss::JIT *etiss_helper_merge(ETISS_LIBNAME, _createJIT)(
        unsigned index, std::map<std::string, std::string> options); ///< create new instance of the jit type at index
    ETISS_PLUGIN_EXPORT void etiss_helper_merge(ETISS_LIBNAME, _deleteJIT)(etiss::JIT *instance); ///< delete instance
}

#endif
