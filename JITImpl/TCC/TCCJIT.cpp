// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "TCCJIT.h"
#include "etiss/Misc.h"
#include "etiss/config.h"

#include "libtcc.h"
#if ETISS_USE_GETPROC
#include "etiss/ETISS.h"
#include <windows.h>
#include <dbghelp.h>
#include <iostream>

BOOL CALLBACK etiss_tcc_allsym(PSYMBOL_INFO pSymInfo, ULONG SymbolSize, PVOID UserContext)
{
    std::map<std::string, void *> &map = *(std::map<std::string, void *> *)UserContext;
    /// TODO: check if void* conversion is allowed
    map.insert(std::pair<std::string, void *>(pSymInfo->Name, (void *)pSymInfo->Address));
    std::cout << "Found Symbol: " << pSymInfo->Name << "@0x" << std::hex << (void *)pSymInfo->Address << std::endl;
    return TRUE;
}

static void addAllSymbols(std::map<std::string, void *> &ptrs)
{

    HANDLE hProcess = GetCurrentProcess();
    // DWORD64 BaseOfDll;
    BOOL status;

    status = SymInitialize(hProcess, NULL, TRUE);
    if (status == FALSE)
    {
        return;
    }

    auto libs = etiss::listLibraryPrefixes();
    for (auto lib : libs)
    {
        std::string filter;
        filter = std::string("*!") + lib + "_*";
        std::cout << "searching in library " << lib << std::endl;
        if (SymEnumSymbols(hProcess,         // Process handle from SymInitialize.
                           NULL,             // Base address of module.
                           filter.c_str(),   // Name of symbols to match.
                           etiss_tcc_allsym, // Symbol handler procedure.
                           (PVOID)&ptrs))    // User context.
        {
            // SymEnumSymbols succeeded
        }
        else
        {
            std::cout << "Failed to iterate over all symbols for library " << lib << ":" << GetLastError() << std::endl;
        }
    }

    SymCleanup(hProcess);
}

#endif

TCCJIT::TCCJIT() : JIT("tcc")
{
#if ETISS_USE_GETPROC
    addAllSymbols(extsymbols);
#endif
}

void *TCCJIT::translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                        std::set<std::string> libraries, std::string &error, bool debug)
{

    TCCState *s = tcc_new();
    if (!s)
    {
        error = "Could not create tcc state";
        return 0;
    }

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    tcc_set_lib_path(s, (etiss::jitFiles() + "/tcc").c_str());

    // init
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    // init headers
    for (auto iter = headerpaths.begin(); iter != headerpaths.end(); iter++)
    {
        tcc_add_include_path(s, iter->c_str());
    }
    tcc_add_include_path(s, (etiss::jitFiles() + "/tcc_stdlib").c_str());

    if (tcc_compile_string(s, code.c_str()) == -1)
    { // compile
        error = "Failed to compile code: \n";
        error += code;
        return 0;
    }

#if ETISS_USE_GETPROC
    for (auto sym : extsymbols)
    {
        tcc_add_symbol(s, sym.first.c_str(), sym.second);
    }
    for (const auto &jitPath : etiss::jitExtLibPaths())
    {
        etiss::LibraryInterface::addSearchPath(etiss::jitFiles() + jitPath);
    }
#endif

    // init libs
    for (const auto &libpath : librarypaths)
    {
        if (tcc_add_library_path(s, libpath.c_str()))
        {
            error += "could not add library path: " + libpath;
            return 0;
        }
    }
    for (const auto &lib : libraries)
    {
        if (tcc_add_library(s, lib.c_str()))
        {
            error += "could not add library: " + lib;
            return 0;
        }
    }

    /* relocate the code */
    if (tcc_relocate(s) < 0)
    { // link
        error = "Failed to link";
        return 0;
    }

    /* return TCCState as handle*/
    return (void *)s;
}
void *TCCJIT::getFunction(void *handle, std::string name, std::string &error)
{

    return tcc_get_symbol((TCCState *)handle, name.c_str());
}
void TCCJIT::free(void *handle)
{
    tcc_delete((TCCState *)handle);
}
