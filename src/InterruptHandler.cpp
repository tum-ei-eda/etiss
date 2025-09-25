// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implements etiss/InterruptHandler.h

        @detail

*/
#include "etiss/InterruptHandler.h"

using namespace etiss;

InterruptHandler::InterruptHandler(etiss::InterruptVector *interruptVector, etiss::InterruptEnable *interruptEnable,
                                   std::shared_ptr<CPUArch> arch, InterruptType itype, bool sync)
    : itype_(itype), sync_(sync), vector_(interruptVector), enable_(interruptEnable), cpuarch_(arch)
{
    empty_ = true;
}

InterruptHandler::~InterruptHandler() {}

bool interrupt_handler_cmp(const std::pair<etiss::uint64, std::pair<unsigned, bool>> &o1,
                           const std::pair<etiss::uint64, std::pair<unsigned, bool>> &o2)
{
    return o1.first < o2.first;
}

void InterruptHandler::setLine(unsigned line, bool state, etiss::uint64 time_ps)
{
    if (vector_ == 0)
        return;

    if (sync_)
        mu_.lock();
    pending_.push_back(std::make_pair(time_ps, std::make_pair(line, state))); // add interrupt to list
    pending_.sort(interrupt_handler_cmp);
    empty_ = false;
    if (sync_)
        mu_.unlock();
}

etiss::int32 InterruptHandler::execute()
{
    etiss::uint64 time_ps = plugin_cpu_->cpuTime_ps;

    if (vector_ == 0)
        return etiss::RETURNCODE::NOERROR;

    if (sync_)
        mu_.lock();

    bool mayinterrupt = (itype_ != EDGE_TRIGGERED); // edge triggered may only interrupt once after a rising edge

    //	if (itype_ == EDGE_TRIGGERED) {
    //    for (int i=0; i < vector_->width() * 8; ++i) {
    //      if (vector_->getBit(i)) {
    //        std::cout << "clearing\n";
    //        vector_->setBit(i, 0);
    //      }
    //    }
    //	}

    // fast check for empty pending list
    if (!empty_)
    {

        while (!pending_.empty() && pending_.front().first <= time_ps)
        { // apply events from past
            std::pair<etiss::uint64, std::pair<unsigned, bool>> &cur = pending_.front();

            switch (itype_)
            {
            case EDGE_TRIGGERED:
                if (cur.second.second)
                { // if line high
                    if (ed_raised_.find(cur.second.first) == ed_raised_.end())
                    { // if line was low
                        ed_raised_.insert(cur.second.first);
                        mayinterrupt = true;
                    }
                }
                else
                { // line low
                    ed_raised_.erase(cur.second.first);
                }

                vector_->setBit(cur.second.first, cur.second.second);
                break;
            case LEVEL_TRIGGERED:
                // dont need to clear state in case of iss model (i.e. if not using interrupt listener plugin)
                if (!cur.second.second && !vector_->consumed_by_interruptlistener_)
                {
                    break;
                }
                vector_->setBit(cur.second.first, cur.second.second);
                break;
            default:
                std::cout << "InterruptHandler::execute: ERROR: interrupt type is invalid" << stream_code_info
                          << std::endl;
            }
            pending_.pop_front();

            // only handle one pending event in case of edge-triggered events
            if (itype_ == EDGE_TRIGGERED && mayinterrupt)
            {
                break;
            }
            // only handle one pending event in case of level-triggered events
            if (itype_ == LEVEL_TRIGGERED)
            {
                break;
            }
        }

        empty_ = pending_.empty();
    }

    if (sync_)
        mu_.unlock();

    auto active = vector_->isActive();
    auto enabled = enable_->isEnabled();

    // std::cout << "active: " << active << ", enabled: " << enabled << std::endl;

    return (mayinterrupt && active && enabled) ? etiss::RETURNCODE::INTERRUPT : etiss::RETURNCODE::NOERROR;
}

std::string InterruptHandler::_getPluginName() const
{
    return "InterruptHandler";
}
