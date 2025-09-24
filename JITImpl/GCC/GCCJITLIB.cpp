// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "GCCJIT.h"

#define ETISS_LIBNAME GCCJIT

#include "etiss/Misc.h"
#include "etiss/helper/JITLibrary.h"

extern "C"
{

    const char *GCCJIT_versionInfo() { return "0.4"; }

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned GCCJIT_countJIT() { return 1; }

    const char *GCCJIT_nameJIT(unsigned i) { return "GCCJIT"; }

    etiss::JIT *GCCJIT_createJIT(unsigned i, std::map<std::string, std::string> options)
    {
        etiss::Configuration cfg;
        cfg.config() = options;
        return new GCCJIT(cfg.get<bool>("jit.gcc.cleanup", true), cfg.get<std::string>("jit.gcc.opt_level", "fast"), cfg.get<bool>("jit.gcc.quiet", false));
    }

    void GCCJIT_deleteJIT(etiss::JIT *jit) { delete (GCCJIT *)jit; }
}
