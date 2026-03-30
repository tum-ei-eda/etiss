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
#ifndef ETISS_INCLUDE_HELPER_PLUGINLIBRARY_H_
#define ETISS_INCLUDE_HELPER_PLUGINLIBRARY_H_

#include "etiss/helper/Misc.h"

#include "etiss/Misc.h"

extern "C"
{

    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(
        ETISS_LIBNAME, _countPlugin)(); ///< function to get number of plugin types supplied by a library
    ETISS_PLUGIN_EXPORT const char *etiss_helper_merge(ETISS_LIBNAME, _namePlugin)(
        unsigned index); ///< function to get the name of a plugin type at index
    ETISS_PLUGIN_EXPORT etiss::Plugin *etiss_helper_merge(ETISS_LIBNAME, _createPlugin)(
        unsigned index,
        std::map<std::string, std::string> options); ///< create new instance of the plugin type at index
    ETISS_PLUGIN_EXPORT void etiss_helper_merge(ETISS_LIBNAME, _deletePlugin)(etiss::Plugin *); ///< delete instance
}

#endif
