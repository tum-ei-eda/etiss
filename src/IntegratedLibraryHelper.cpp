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
