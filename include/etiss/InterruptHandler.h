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

        @brief interrupt checking and signaling

        @detail

*/

#ifndef ETISS_INCLUDE_INTERRUPTHANDLER_H_
#define ETISS_INCLUDE_INTERRUPTHANDLER_H_

#include "etiss/CPUArch.h"
#include "etiss/InterruptVector.h"
#include "etiss/InterruptHandler.h"
#include "etiss/LibraryInterface.h"
#include "etiss/Plugin.h"
#include "etiss/jit/types.h"
#include <list>
#include <mutex>
#include <set>
#include <vector>

namespace etiss
{

/**
        interrupt types supported by the default implementation
*/
enum InterruptType
{

    EDGE_TRIGGERED = 1,
    LEVEL_TRIGGERED

};

/**
        @brief class that handles interrupt signaling and checking. functions
   are declared virtual to allow customization
*/
class InterruptHandler : public etiss::CoroutinePlugin
{
  public:
    InterruptHandler(etiss::InterruptVector *interruptVector, etiss::InterruptEnable *interruptEnable, std::shared_ptr<etiss::CPUArch> arch,
                     InterruptType itype = EDGE_TRIGGERED, bool sync = true);
    virtual ~InterruptHandler();
    /**
            @brief set the state of a line at a given time. changes will not be applied until flush(2) with a time_ps
       value equal or greater than this time_ps value is called
    */
    virtual void setLine(unsigned line, bool state, etiss::uint64 time_ps);
    /**
            @brief apply interrupt changes to the InterruptVector
            @return etiss::RETURNCODE::INTERRUPT if an interrupt should occur
    */
    virtual etiss::int32 execute();
    virtual std::string _getPluginName() const;

  protected:
    const InterruptType itype_;
    std::mutex mu_;
    const bool sync_;
    InterruptVector *const vector_;
    InterruptEnable *const enable_;
    /** list: (time , (line ,state) ) */
    std::list<std::pair<etiss::uint64, std::pair<unsigned, bool>>> pending_;
    const std::shared_ptr<etiss::CPUArch> cpuarch_;
    std::set<unsigned> ed_raised_;
    bool empty_;
};
} // namespace etiss

#endif
