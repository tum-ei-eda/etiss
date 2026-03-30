// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief contains general definitions needed for library function definitions. Doesn't need to be included by
   user.

        @see PluginLibrary.h
        @see JITLibrary.h
        @see CPUArchLibrary.h

        @detail




*/
#ifndef ETISS_INCLUDE_HELPER_MISC_H_
#define ETISS_INCLUDE_HELPER_MISC_H_

#include "etiss/pluginexport.h"
#include <map>
#include <string>

#include "etiss/config.h"

#define etiss_helper_merge_l2(X1, X2) X1##X2
#define etiss_helper_merge(X1, X2) etiss_helper_merge_l2(X1, X2)

extern "C"
{

    /**
             must be implemented like this:

                    #include "helper/Misc.h"
                    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    */
    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(ETISS_LIBNAME, _etissversion)();
}

#define ETISS_LIBRARYIF_VERSION_FUNC_IMPL                                           \
    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(ETISS_LIBNAME, _etissversion)() \
    {                                                                               \
        return (ETISS_VERSION_MAJOR << 16) + (ETISS_VERSION_MINOR);                 \
    }

#endif
