/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implements etiss/LibraryInterface.h and provides LibraryInterface implementation for shared/dynamic
   libraries that are loaded with dlsym

        @detail

*/

#include "etiss/LibraryInterface.h"
#include "etiss/Misc.h"
#if ETISS_USE_DLSYM
#include <dlfcn.h>
#elif ETISS_USE_GETPROC
#include <windows.h>
// defined by windows. clashed with etiss::ERROR
#undef ERROR
#endif

using namespace etiss;

LibraryInterface::LibraryInterface(std::string name) : name_(name) {}
LibraryInterface::~LibraryInterface() {}

std::string LibraryInterface::versionInfo()
{
    return "UNKNOWN";
}

unsigned LibraryInterface::countPlugins()
{
    return 0;
}
unsigned LibraryInterface::countCPUArchs()
{
    return 0;
}
unsigned LibraryInterface::countJITs()
{
    return 0;
}

std::string LibraryInterface::nameJIT(unsigned index)
{
    return "";
}
std::string LibraryInterface::namePlugin(unsigned index)
{
    return "";
}
std::string LibraryInterface::nameCPUArch(unsigned index)
{
    return "";
}

etiss::JIT *LibraryInterface::createJIT(unsigned index, std::map<std::string, std::string> options)
{
    return 0;
}
etiss::CPUArch *LibraryInterface::createCPUArch(unsigned index, std::map<std::string, std::string> options)
{
    return 0;
}
etiss::Plugin *LibraryInterface::createPlugin(unsigned index, std::map<std::string, std::string> options)
{
    return 0;
}

void LibraryInterface::deleteJIT(etiss::JIT *) {}
void LibraryInterface::deleteCPUArch(etiss::CPUArch *) {}
void LibraryInterface::deletePlugin(etiss::Plugin *) {}

bool LibraryInterface::isEmpty()
{
    return countPlugins() == 0 && countCPUArchs() == 0 && countJITs() == 0;
}

const std::string &LibraryInterface::getName()
{
    return name_;
}

#if ETISS_USE_DLSYM || ETISS_USE_GETPROC

std::mutex ETISS_SharedLibraryInterface_mu_;
std::set<void *> ETISS_SharedLibraryInterface_handles_;

static std::string ETISS_sdlerror()
{
#if ETISS_USE_DLSYM
    const char *e = dlerror();
    if (e)
        return std::string(e);
#endif
    return "";
}
static void *ETISS_dlsym(void *handle, std::string name, std::string symbol, bool printNotFoundWarning = false)
{
#if ETISS_USE_DLSYM
    std::string fullsymbol = (name + "_" + symbol);
    void *ret = dlsym(handle, fullsymbol.c_str()); // load function with libaray prefix
    if (ret == 0 && handle != 0)
    { // only fallback if not integrated library
        std::string error = ETISS_sdlerror();
        ret = dlsym(handle, symbol.c_str()); // fallback to unprefixed function.
        if (ret != 0)
        {
            etiss::log(etiss::WARNING, "a library does not prefix its functions as recommended: declare as \"" + name +
                                           "_" + symbol + "\" and not just as \"" + symbol + "\"");
        }
        else if (printNotFoundWarning)
        {
            etiss::log(etiss::WARNING, "failed to load symbol " + name + "_" + symbol + ": " + error +
                                           "[secondary: " + ETISS_sdlerror() + "]");
        }
    }
    return ret;
#elif ETISS_USE_GETPROC
    std::string fullsymbol = (name + "_" + symbol);
    // Technically there is no guarnatee that a function pointer type in C++ can be
    // Uniquely represented as a void *.   Of course on any common general-purpose platform
    // this is the case...
    if (!handle)
    {
        HMODULE hmodule = NULL;
        ::GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            reinterpret_cast<LPCTSTR>(&ETISS_dlsym), &hmodule);
        if (!hmodule)
            return nullptr;
        return reinterpret_cast<void *>(reinterpret_cast<intptr_t >(GetProcAddress(hmodule, TEXT(fullsymbol.c_str()))));
    }
    else
    {
        return reinterpret_cast<void *>(reinterpret_cast<intptr_t >(GetProcAddress((HMODULE)handle, TEXT(fullsymbol.c_str()))));
    }
#endif
    return nullptr;
}
static void *ETISS_dlopen(const std::string &path, const std::string &name)
{
#if ETISS_USE_DLSYM
    std::string fullname = path + "lib" + name + ".so";
    void *ret = dlopen(fullname.c_str(), RTLD_GLOBAL | RTLD_NOW
#if ETISS_USE_DLSYM_DEEPBIND
    //|RTLD_DEEPBIND
#endif
    );
    if (!ret)
    {
        std::string err = ETISS_sdlerror();
        ret = dlopen(name.c_str(), RTLD_GLOBAL | RTLD_NOW
#if ETISS_USE_DLSYM_DEEPBIND
        //|RTLD_DEEPBIND
#endif
        );
        if (ret)
            etiss::log(etiss::WARNING, std::string("Using fallback library: ") + (name) + ": " + err);
        else
        {
            // set error message right
            ret = dlopen(fullname.c_str(), RTLD_GLOBAL | RTLD_NOW
#if ETISS_USE_DLSYM_DEEPBIND
            //|RTLD_DEEPBIND
#endif
            );
        }
    }
    return ret;
#elif ETISS_USE_GETPROC
    return LoadLibrary(TEXT((path + name).c_str()));
#endif
    return nullptr;
}
static void ETISS_dlclose(void *handle)
{
#if ETISS_USE_DLSYM
    dlclose(handle);
#elif ETISS_USE_GETPROC
    FreeLibrary((HMODULE)handle);
#endif
}

class ETISS_SharedLibraryInterface : public LibraryInterface
{
  public:
    ETISS_SharedLibraryInterface(std::string path, std::string name, void *handle)
        : LibraryInterface(name)
        , name_(name)
        , path_(path)
        , wd_(etiss::cfg().get<std::string>("etiss_wd", "~/.etiss"))
        , handle_(handle)
        , isvalid_(true)
    {

        // version check
        {
            typedef unsigned (*version)();
            version vfunc = (version)ETISS_dlsym(handle_, name_, "etissversion");
            if (vfunc == 0)
            {
                isvalid_ = false;
                etiss::log(etiss::ERROR, std::string("the library ") + "lib" + name + ".so must implement unsigned " +
                                             name + "_etissversion() to check for compability.");
            }
            else
            {
                unsigned v = vfunc();
                if (v != getCurrentLibraryVersion())
                {
                    isvalid_ = false;
                    etiss::log(etiss::ERROR,
                               std::string("the library ") + "lib" + name + ".so" +
                                   " was compiled with an incompatible version of etiss. Loading aborted");
                }
            }
        }
        // try to communicate library location
        if (isvalid_)
        {
            typedef void (*publicateLocation)(const char *path);
            publicateLocation fnc = (publicateLocation)ETISS_dlsym(handle_, name_, "publicateLocation");
            if (fnc == 0)
            {
                etiss::log(etiss::VERBOSE,
                           "lib" + name + ".so may implement \'void " + name +
                               "_publicateLocation(const char * path)\' to get the library location at runtime.  The "
                               "passed string pointer remains valid as long as the library is loaded.");
            }
            else
            {
                (*fnc)(path_.c_str());
            }
        }
        // try to communicate etiss workdir
        if (isvalid_)
        {
            typedef void (*publicateWorkdir)(const char *path);
            publicateWorkdir fnc = (publicateWorkdir)ETISS_dlsym(handle_, name_, "publicateWorkdir");
            if (fnc == 0)
            {
                etiss::log(etiss::VERBOSE,
                           "lib" + name + ".so may implement \'void " + name +
                               "_publicateWorkdir(const char * path)\' to get the working directory at runtime (path "
                               "will be etiss::cfg().get<std::string>(\"etiss_wd\",\"~/.etiss\")). The passed string "
                               "pointer remains valid as long as the library is loaded.");
            }
            else
            {
                (*fnc)(wd_.c_str());
            }
        }

        version_info_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "versionInfo");
        if (isvalid_ && !version_info_)
        {
            etiss::log(etiss::VERBOSE, "lib" + name + ".so may implement \'const char * " + name +
                                           "_versionInfo()\' to provide version/build information about the library");
        }

        count_plugin_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "countPlugin");
        count_jit_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "countJIT");
        count_cpuarch_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "countCPUArch");

        name_jit_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "nameJIT", count_jit_ != 0);
        name_plugin_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "namePlugin", count_plugin_ != 0);
        name_cpuarch_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "nameCPUArch", count_cpuarch_ != 0);

        create_plugin_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "createPlugin", count_plugin_ != 0);
        create_jit_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "createJIT", count_jit_ != 0);
        create_cpuarch_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "createCPUArch", count_cpuarch_ != 0);

        delete_plugin_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "deletePlugin", count_plugin_ != 0);
        delete_jit_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "deleteJIT", count_jit_ != 0);
        delete_cpuarch_ = (!isvalid_) ? 0 : ETISS_dlsym(handle_, name_, "deleteCPUArch", count_cpuarch_ != 0);
    }
    virtual ~ETISS_SharedLibraryInterface()
    {
        {
            std::lock_guard<std::mutex> lock(ETISS_SharedLibraryInterface_mu_);
            ETISS_SharedLibraryInterface_handles_.erase(handle_);
        }
        if (handle_ != 0)
            ETISS_dlclose(handle_);
    }
    virtual std::string versionInfo()
    {
        typedef const char *(*vi)();
        if (version_info_)
        {
            return ((vi)version_info_)();
        }
        else
        {
            return LibraryInterface::versionInfo();
        }
    }
    virtual unsigned countPlugins()
    {
        typedef unsigned (*count)();
        if (count_plugin_ && name_plugin_ && create_plugin_)
        {
            return ((count)count_plugin_)();
        }
        else
        {
            return 0;
        }
    }
    virtual unsigned countCPUArchs()
    {
        typedef unsigned (*count)();
        if (count_cpuarch_ && name_cpuarch_ && create_cpuarch_)
        {
            return ((count)count_cpuarch_)();
        }
        else
        {
            return 0;
        }
    }
    virtual unsigned countJITs()
    {
        typedef unsigned (*count)();
        if (count_jit_ && name_jit_ && create_jit_)
        {
            return ((count)count_jit_)();
        }
        else
        {
            return 0;
        }
    }

    virtual std::string nameJIT(unsigned index)
    {
        typedef const char *(*name)(unsigned index);
        if (name_jit_)
        {
            return std::string(((name)name_jit_)(index));
        }
        else
        {
            return 0;
        }
    }
    virtual std::string namePlugin(unsigned index)
    {
        typedef const char *(*name)(unsigned index);
        if (name_plugin_)
        {
            return std::string(((name)name_plugin_)(index));
        }
        else
        {
            return 0;
        }
    }
    virtual std::string nameCPUArch(unsigned index)
    {
        typedef const char *(*name)(unsigned index);
        if (name_cpuarch_)
        {
            return std::string(((name)name_cpuarch_)(index));
        }
        else
        {
            return 0;
        }
    }

    virtual etiss::JIT *createJIT(unsigned index, std::map<std::string, std::string> options)
    {
        typedef etiss::JIT *(*create)(unsigned index, std::map<std::string, std::string> options);
        if (create_jit_)
        {
            return ((create)create_jit_)(index, options);
        }
        else
        {
            return 0;
        }
    }
    virtual etiss::CPUArch *createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        typedef etiss::CPUArch *(*create)(unsigned index, std::map<std::string, std::string> options);
        if (create_cpuarch_)
        {
            return ((create)create_cpuarch_)(index, options);
        }
        else
        {
            return 0;
        }
    }
    virtual etiss::Plugin *createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        typedef etiss::Plugin *(*create)(unsigned index, std::map<std::string, std::string> options);
        if (create_plugin_)
        {
            return ((create)create_plugin_)(index, options);
        }
        else
        {
            return 0;
        }
    }

    virtual void deleteJIT(etiss::JIT *o)
    {
        typedef void (*del)(etiss::JIT *);
        if (delete_jit_)
        {
            ((del)delete_jit_)(o);
        }
        else
        {
            std::cout << "Warning: " << ("lib" + name_ + ".so") << " does not implement void " << name_
                      << "_deleteJIT(etiss::JIT*). Memory leaked." << std::endl;
        }
    }
    virtual void deleteCPUArch(etiss::CPUArch *o)
    {
        typedef void (*del)(etiss::CPUArch *);
        if (delete_cpuarch_)
        {
            ((del)delete_cpuarch_)(o);
        }
        else
        {
            std::cout << "Warning: " << ("lib" + name_ + ".so") << " does not implement void " << name_
                      << "_deleteCPUArch(etiss::CPUArch *). Memory leaked." << std::endl;
        }
    }
    virtual void deletePlugin(etiss::Plugin *o)
    {
        typedef void (*del)(etiss::Plugin *);
        if (delete_plugin_)
        {
            ((del)delete_plugin_)(o);
        }
        else
        {
            std::cout << "Warning: " << ("lib" + name_ + ".so") << " does not implement void " << name_
                      << "_deletePlugin(etiss::Plugin*). Memory leaked." << std::endl;
        }
    }

    virtual bool isValid() { return isvalid_; }

  private:
    const std::string name_;
    const std::string path_;
    const std::string wd_;
    void *handle_;
    bool isvalid_;

    void *version_info_;

    void *count_plugin_;
    void *count_jit_;
    void *count_cpuarch_;

    void *name_jit_;
    void *name_plugin_;
    void *name_cpuarch_;

    void *create_plugin_;
    void *create_jit_;
    void *create_cpuarch_;

    void *delete_plugin_;
    void *delete_jit_;
    void *delete_cpuarch_;
};

#endif

std::shared_ptr<LibraryInterface> LibraryInterface::openSharedLibrary(std::string path, std::string name)
{
#if ETISS_USE_DLSYM || ETISS_USE_GETPROC
    void *handle;
    {
        // check name collision
        {
            if (ETISS_dlsym(0, name, "_etissversion"))
            {
                etiss::log(etiss::WARNING,
                           std::string("Failed to load library because the name ") + name + " is already in use.");
                return 0;
            }
        }

        if (path.size() > 0)
        {
            if (path[path.size() - 1] != '/')
                path = path + std::string("/");
        }
        handle = ETISS_dlopen(path, name);
        if (handle == 0)
        {
            std::string err = ETISS_sdlerror();
            if (ETISS_dlsym(0, name, "etissversion"))
            {
                etiss::log(etiss::VERBOSE,
                           std::string("Failed to load library: ") + (path + "lib" + name + ".so") + ": " + err);
                etiss::log(etiss::VERBOSE, std::string("using integrated library: ") + name);
            }
            else
            {
                etiss::log(etiss::ERROR,
                           std::string("Failed to load library: ") + (path + "lib" + name + ".so") + ": " + err);
                etiss::log(etiss::ERROR, std::string("Failed to use integrated library: ") + name);
                return std::shared_ptr<LibraryInterface>(0);
            }
        }

        if (handle != 0)
        {
            if (ETISS_SharedLibraryInterface_handles_.find(handle) != ETISS_SharedLibraryInterface_handles_.end())
            {
                etiss::log(etiss::VERBOSE, "Failed to load library: already loaded.", name);
                ETISS_dlclose(handle);
                return 0;
            }
            else
            {
                ETISS_SharedLibraryInterface_handles_.insert(handle);
            }
        }
    }

    ETISS_SharedLibraryInterface *retptr = new ETISS_SharedLibraryInterface(
        path, name, handle); // from here on ETISS_SharedLibraryInterface is responsible for the handle

    std::shared_ptr<LibraryInterface> ret(retptr);

    if (!(retptr->isValid()))
    {
        if (handle != 0)
        {
            std::lock_guard<std::mutex> lock(ETISS_SharedLibraryInterface_mu_);
            ETISS_SharedLibraryInterface_handles_.erase(handle);
        }
        ret.reset();
    }

    return ret;
#else
    etiss::log(etiss::INFO,
               "etiss::loadLibrary was compiled without any library loading support. library cannot be loaded.",
               ETISS_VARVAL(path), ETISS_VARVAL(name), ETISS_SRCLOC);
    return nullptr;
#endif
}
