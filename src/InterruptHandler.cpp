/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implements etiss/InterruptHandler.h

        @detail

*/
#include "etiss/InterruptHandler.h"

using namespace etiss;

InterruptHandler::InterruptHandler(etiss::InterruptVector *interruptVector, std::shared_ptr<CPUArch> arch,
                                   InterruptType itype, bool sync)
    : itype_(itype), sync_(sync), vector_(interruptVector), cpuarch_(arch)
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

    return (mayinterrupt && vector_->isActive()) ? etiss::RETURNCODE::INTERRUPT : etiss::RETURNCODE::NOERROR;
}

std::string InterruptHandler::_getPluginName() const
{
    return "InterruptHandler";
}
