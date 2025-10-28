// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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

    static void addSearchPath(const std::string &path);

  private:
    std::string name_;
};

} // namespace etiss

#endif
