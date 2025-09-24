// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implements a LibraryInterface for the integrated library which is not loaded like other libraries but
   called directly

        @detail

*/

#include "etiss/LibraryInterface.h"

#define ETISS_LIBNAME ETISSINCLUDED

#include "etiss/helper/CPUArchLibrary.h"
#include "etiss/helper/JITLibrary.h"
#include "etiss/helper/PluginLibrary.h"

/**
        @brief LibraryInterface implementation for integrated JIT/CPUArch/Plugin implementations. wraps example
   implementation of library functions defined by helper/CPUArchLibrary.h,helper/JITLibrary.h,helper/PluginLibrary.h and
   implemented in IntegratedLibrary.cpp
*/
class IntegratedLibrary : public etiss::LibraryInterface
{
  public:
    IntegratedLibrary() : etiss::LibraryInterface("ETISSINCLUDED") {}
    virtual std::string versionInfo() { return ETISS_VERSION_FULL; }
    virtual unsigned countPlugins() { return ETISSINCLUDED_countPlugin(); }
    virtual unsigned countCPUArchs() { return ETISSINCLUDED_countCPUArch(); }
    virtual unsigned countJITs() { return ETISSINCLUDED_countJIT(); }

    virtual std::string nameJIT(unsigned index)
    {
        const char *name = ETISSINCLUDED_nameJIT(index);
        if (name != 0)
        {
            return std::string(name);
        }
        return std::string();
    }
    virtual std::string namePlugin(unsigned index)
    {
        const char *name = ETISSINCLUDED_namePlugin(index);
        if (name != 0)
        {
            return std::string(name);
        }
        return std::string();
    }
    virtual std::string nameCPUArch(unsigned index)
    {
        const char *name = ETISSINCLUDED_nameCPUArch(index);
        if (name != 0)
        {
            return std::string(name);
        }
        return std::string();
    }

    virtual etiss::JIT *createJIT(unsigned index, std::map<std::string, std::string> options)
    {
        return ETISSINCLUDED_createJIT(index, options);
    }
    virtual etiss::CPUArch *createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        return ETISSINCLUDED_createCPUArch(index, options);
    }
    virtual etiss::Plugin *createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        return ETISSINCLUDED_createPlugin(index, options);
    }

    virtual void deleteJIT(etiss::JIT *o) { delete o; }
    virtual void deleteCPUArch(etiss::CPUArch *o) { delete o; }
    virtual void deletePlugin(etiss::Plugin *o) { delete o; }
};

std::shared_ptr<etiss::LibraryInterface> etiss::LibraryInterface::openIntegratedLibrary()
{
    return std::shared_ptr<etiss::LibraryInterface>(new IntegratedLibrary());
}
