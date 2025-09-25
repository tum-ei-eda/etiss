// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the
// library is named "X". IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME TCCJIT

#include "etiss/helper/JITLibrary.h" // defines the following functions

#include "TCCJIT.h"

extern "C"
{

    ETISS_PLUGIN_EXPORT const char *TCCJIT_versionInfo()
    {
        return "0.9.27";
    }

    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    ETISS_PLUGIN_EXPORT unsigned TCCJIT_countJIT()
    {
        // TODO
        return 1; // number of cpu architectures provided
    }
    ETISS_PLUGIN_EXPORT const char *TCCJIT_nameJIT(unsigned index)
    {
        // TODO
        switch (index)
        {
        case 0:
            return "TCCJIT";
        default:
            return "";
        }
    }
    ETISS_PLUGIN_EXPORT etiss::JIT *TCCJIT_createJIT(unsigned index, std::map<std::string, std::string> options)
    {
        // TODO
        switch (index)
        {
        case 0:
            // parse arguments?
            return new TCCJIT();
        default:
            return 0;
        }
    }
    ETISS_PLUGIN_EXPORT void TCCJIT_deleteJIT(etiss::JIT *arch)
    {
        delete arch;
    }
}
