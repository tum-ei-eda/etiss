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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @date June 24, 2018

        @version 0.1

*/
/**
        @file

        @brief Wrapper class to wrap aroud data MMU


*/

#ifndef ETISS_INCLUDE_MM_DMMUWrapper_WRAPPER_H_
#define ETISS_INCLUDE_MM_DMMUWrapper_WRAPPER_H_

#include "etiss/ETISS.h"
#include "etiss/Plugin.h"
#include "etiss/mm/MMU.h"

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
