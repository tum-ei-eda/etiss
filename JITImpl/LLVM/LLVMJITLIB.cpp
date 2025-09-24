// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#define ETISS_LIBNAME LLVMJIT
#include "etiss/helper/JITLibrary.h"

#include "LLVMJIT.h"

#include <iostream>

// implement etiss library interface
extern "C"
{

    const char *LLVMJIT_versionInfo()
    {
        return "3.4.2for0.4";
    }

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned LLVMJIT_countJIT()
    {
        return 1;
    }
    const char *LLVMJIT_nameJIT(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "LLVMJIT";
        default:
            return 0;
        }
    }
    etiss::JIT *LLVMJIT_createJIT(unsigned index, std::map<std::string, std::string> options)
    {
        switch (index)
        {
        case 0:
            return new etiss::LLVMJIT();
        default:
            return 0;
        }
    }

    void LLVMJIT_deleteJIT(etiss::JIT *o)
    {
        delete o;
    }
}
