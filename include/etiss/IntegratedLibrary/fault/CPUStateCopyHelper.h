// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <vector>

#include "etiss/jit/CPU.h"
#include "etiss/Misc.h"

namespace etiss
{
namespace fault
{

class CPUStateCopyHelper
{
  public:
    etiss_del_como(CPUStateCopyHelper) private : std::list<std::pair<uint8_t *, size_t>> instructions_;
    std::map<std::string, std::function<std::pair<uint8_t *, size_t>(std::string, ETISS_CPU *)>>
        allocatorMap_; ///< type -> std::pair<uint8_t*,size_t>(*func)(std::string registername,ETISS_CPU * cpu)
  public:
    void registerAllocator(std::string type,
                           std::function<std::pair<uint8_t *, size_t>(std::string, ETISS_CPU *)> allocator);
};

} // namespace fault
} // namespace etiss
