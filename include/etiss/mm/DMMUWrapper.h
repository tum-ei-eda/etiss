// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief Wrapper class to wrap aroud data MMU


*/

#ifndef ETISS_INCLUDE_MM_DMMUWrapper_WRAPPER_H_
#define ETISS_INCLUDE_MM_DMMUWrapper_WRAPPER_H_

#include "etiss/Misc.h"
#include "etiss/Plugin.h"

#include <sstream>

namespace etiss
{
namespace mm
{

class DMMUWrapper : public etiss::SystemWrapperPlugin
{

  public:
    explicit DMMUWrapper(std::shared_ptr<MMU> mmu);

    virtual ~DMMUWrapper() {}

    /**
            @brief SystemWrapperPlugin interface to wrap around original ETISS_System
    */
    ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system);

    /**
            @brief SystemWrapperPlugin interface to unwrap original ETISS_System
    */
    ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system);

    std::shared_ptr<MMU> mmu_;

  protected:
    std::string _getPluginName() const;
};

struct DMMUWrapperSystem
{

    struct ETISS_System sys;
    DMMUWrapper *this_;
    ETISS_System *orig;
};

} // namespace mm
} // namespace etiss

#endif
