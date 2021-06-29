/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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

        @date July 28, 2014

        @version 0.1

*/
/**
        @file

        @brief class for simple library access. Libraries can be integrated or loaded at runtime fom a dynamic library

        @detail




*/

#ifndef ETISS_INCLUDE_LIBRARY_H_
#define ETISS_INCLUDE_LIBRARY_H_

#include <map>
#include <memory>
#include <mutex>
#include <string>

#include "etiss/config.h"

#define etiss_helper_merge_l2(X1, X2) X1##X2
#define etiss_helper_merge(X1, X2) etiss_helper_merge_l2(X1, X2)
#include "etiss/Misc.h"

#include "etiss/CPUArch.h"
#include "etiss/ClassDefs.h"
#include "etiss/JIT.h"
#include "etiss/Plugin.h"
#include "etiss/pluginexport.h"

namespace etiss
{

/**
        @brief interface class for libraries. override functions as needed.
        @detail it is neccessary to override all function of the same category. e.g. for plugins:
   countPlugins(),namePlugin(1),createPlugin(1),deletePlugin(1). isEmpty() uses countXXXXXX() functions to assess its
   return value and doesn't need to be implemented.

                to implement a dynamic library do NOT use this class. Refer to etiss/helper/CPUArchLibrary.h ,
   etiss/helper/JITLibrary.h , etiss/helper/PluginLibrary.h for library functions to implement and use
   etiss::LibraryInterface::openSharedLibrary to load the dynamic library


*/
class LibraryInterface
{
  private:
    // friend void etiss::addLibrary(std::shared_ptr<etiss::LibraryInterface> interface);
  public:
    /**
            @param name name of the library
            @param path location of the library and its files
    */
    LibraryInterface(std::string name);

    virtual ~LibraryInterface();

    /// simple version info string. intended to present information in a human readable way.
    virtual std::string versionInfo();

    virtual unsigned countPlugins();
    virtual unsigned countCPUArchs();
    virtual unsigned countJITs();

    virtual std::string nameJIT(unsigned index);
    virtual std::string namePlugin(unsigned index);
    virtual std::string nameCPUArch(unsigned index);

  public:
    virtual etiss::JIT *createJIT(unsigned index,
                                  std::map<std::string, std::string> options = std::map<std::string, std::string>());
    virtual etiss::CPUArch *createCPUArch(
        unsigned index, std::map<std::string, std::string> options = std::map<std::string, std::string>());
    virtual etiss::Plugin *createPlugin(
        unsigned index, std::map<std::string, std::string> options = std::map<std::string, std::string>());

    virtual void deleteJIT(etiss::JIT *);
    virtual void deleteCPUArch(etiss::CPUArch *);
    virtual void deletePlugin(etiss::Plugin *);

  public:
    /**
            @brief returns true if this library provides nothing
    */
    virtual bool isEmpty();
    /**
            @return name of this library
    */
    virtual const std::string &getName();

  public:
    static std::shared_ptr<LibraryInterface> openSharedLibrary(std::string path, std::string name);

    static std::shared_ptr<LibraryInterface> openIntegratedLibrary();

    static unsigned getCurrentLibraryVersion();

    static void AddSearchPath(const std::string &path);

  private:
    std::string name_;
};

} // namespace etiss

#endif
