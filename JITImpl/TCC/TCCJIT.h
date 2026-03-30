// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/JIT.h"
#include <map>

class TCCJIT : public etiss::JIT
{
  public:
    TCCJIT();
    virtual void *translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                            std::set<std::string> libraries, std::string &error, bool debug = false);
    virtual void *getFunction(void *handle, std::string name, std::string &error);
    virtual void free(void *handle);

  private:
    std::map<std::string, void *> extsymbols; ///< only use for windows. manual linking to symbols of
                                              ///< current executable
};
