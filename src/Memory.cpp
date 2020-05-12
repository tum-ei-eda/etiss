/*
 * Taken from https://bitbucket.org/rafzi/hacklib
 */

#include "etiss/Memory.h"
#include <stdexcept>


#ifdef _WIN32

#include <Windows.h>

etiss::ModuleHandle etiss::GetModuleByName(const std::string &name)
{
    if (name == "")
    {
        return GetModuleHandleA(NULL);
    }
    else
    {
        return GetModuleHandleA(name.c_str());
    }
}

etiss::ModuleHandle etiss::GetModuleByAddress(uintptr_t adr)
{
    etiss::ModuleHandle hModule = etiss::NullModuleHandle;

    if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                          (LPCTSTR)adr, &hModule) == 0)
    {
        if (GetLastError() != ERROR_MOD_NOT_FOUND)
        {
            throw std::runtime_error("GetModuleHandleEx failed");
        }
    }

    return hModule;
}

std::string etiss::GetModulePath(etiss::ModuleHandle hModule)
{
    char path[MAX_PATH];

    if (GetModuleFileNameA(hModule, path, MAX_PATH) == 0)
    {
        throw std::runtime_error("GetModuleFileName failed");
    }

    return path;
}
#else

#include <dlfcn.h>

etiss::ModuleHandle etiss::GetModuleByName(const std::string &name)
{
    void *handle;
    if (name == "")
    {
        handle = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL | RTLD_NOLOAD);
    }
    else
    {
        handle = dlopen(name.c_str(), RTLD_LAZY | RTLD_LOCAL | RTLD_NOLOAD);
    }

    if (handle)
    {
        // This is undocumented, but works and is easy.
        auto hModule = *(etiss::ModuleHandle *)handle;
        if (!hModule)
        {
            hModule = (etiss::ModuleHandle)0x400000;
        }
        dlclose(handle);
        return hModule;
    }
    else
    {
        return etiss::NullModuleHandle;
    }
}

etiss::ModuleHandle etiss::GetModuleByAddress(uintptr_t adr)
{
    Dl_info info = { 0 };
    dladdr((void *)adr, &info);
    return info.dli_fbase;
}

std::string etiss::GetModulePath(etiss::ModuleHandle hModule)
{
    Dl_info info = { 0 };
    if (dladdr((void *)hModule, &info) == 0)
    {
        throw std::runtime_error("dladdr failed");
    }
    return info.dli_fname;
}

#endif



etiss::ModuleHandle etiss::GetCurrentModule()
{
    static etiss::ModuleHandle hModule = 0;

    if (!hModule)
    {
        hModule = etiss::GetModuleByAddress((uintptr_t)etiss::GetCurrentModule);
    }

    return hModule;
}
std::string etiss::GetCurrentModulePath()
{
    static std::string modulePath;

    if (modulePath == "")
    {
        modulePath = etiss::GetModulePath(etiss::GetCurrentModule());
    }

    return modulePath;
}