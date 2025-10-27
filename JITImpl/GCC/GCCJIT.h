// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/JIT.h"

/**
        @brief provides compilation via gcc and load the compilation result with dlopen/dlsym functions
        @detail use the option "cleanup" -> "false" to keep code after destruction of a GCCJIT instance
*/
class GCCJIT : public etiss::JIT
{
  public:
    GCCJIT(bool cleanup = true, std::string opt_level = "fast", bool quiet = false);
    virtual ~GCCJIT();
    virtual void *translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                            std::set<std::string> libraries, std::string &error, bool debug = false);
    virtual void *getFunction(void *handle, std::string name, std::string &error);
    virtual void free(void *handle);

  private:
  private:
    unsigned id;
    std::string path_;
    bool cleanup_;
    std::string opt_level_;
    bool quiet_;
};
