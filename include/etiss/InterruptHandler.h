// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief interrupt checking and signaling

        @detail

*/

#ifndef ETISS_INCLUDE_INTERRUPTHANDLER_H_
#define ETISS_INCLUDE_INTERRUPTHANDLER_H_

#include "etiss/Misc.h"
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
    InterruptHandler(etiss::InterruptVector *interruptVector, etiss::InterruptEnable *interruptEnable,
                     std::shared_ptr<etiss::CPUArch> arch, InterruptType itype = EDGE_TRIGGERED, bool sync = true);
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
