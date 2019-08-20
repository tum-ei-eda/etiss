/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#ifndef NO_ETISS
#include "etiss/fault/Injector.h"
#include "etiss/Misc.h"
#include "etiss/fault/Stressor.h"
#else
#include "fault/Injector.h"
#include "fault/Stressor.h"
#endif

#include <iostream>

namespace etiss
{

namespace fault
{

int x;
Injector::Injector()
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::Injector()"));
    has_pending_triggers = false;
}

void Injector::freeFastFieldAccessPtr(void *)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::freeFastFieldAccessPtr(void*)"));
    etiss::log(etiss::INFO, std::string("etiss::fault::Injector::freeFastFieldAccessPtr(void*) not implemented"));
}

bool Injector::needsCallbacks()
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::needsCallbacks()"));
    return has_pending_triggers;
}

bool Injector::cycleAccurateCallback(uint64_t time_ps)
{
    bool ret = false;
#if ETISS_DEBUG
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::cycleAccurateCallback(time_ps=") +
                                   std::to_string(time_ps) + ")");
#endif
    // copy pending triggers in a threadsafe manner to unknown triggers
    if (has_pending_triggers)
    {
#if CXX0X_UP_SUPPORTED
        std::lock_guard<std::mutex> lock(sync);
#endif
        unknown_triggers.insert(unknown_triggers.end(), pending_triggers.begin(), pending_triggers.end());
        pending_triggers.clear();
    }
    // check triggers
    if (!unknown_triggers.empty())
    {
        for (std::list<std::pair<Trigger, int32_t>>::iterator iter = unknown_triggers.begin();
             iter != unknown_triggers.end();)
        {
            if (iter->first.fired(time_ps, this))
            { // trigger fired
                // signal fired trigger
                ret = true;
                if (Stressor::firedTrigger(iter->first, iter->second, this, time_ps))
                {
                    // remove fired trigger
                    unknown_triggers.erase(iter++);
                }
                else
                {
                    ++iter;
                }
            }
            else
            {
                ++iter;
            }
        }
    }
    return ret;
}
bool Injector::instructionAccurateCallback(uint64_t time_ps)
{
#if ETISS_DEBUG
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::instructionAccurateCallback(time_ps=") +
                                   std::to_string(time_ps) + ")");
#endif
    return cycleAccurateCallback(time_ps); /// todo
}
#if CXX0X_UP_SUPPORTED
template <typename T>
/**
    helper function for pointer comparison
*/
bool operator==(const std::shared_ptr<T> &p1, const T *const &p2)
{
    return p1.get() == p2;
}
#endif

std::string Injector::getInjectorPath()
{

    std::string path;
    ptr iptr = getParentInjector();
    ptr cur;
    if (!iptr)
        return path;

    // Get Injector name
    std::list<std::string> si = iptr->listSubInjectors();
    for (std::list<std::string>::const_iterator iter = si.begin(); iter != si.end(); ++iter)
    {
        cur = iptr->getSubInjector(*iter);
        if (cur == this)
        {
            path = *iter;
            break;
        }
    }
    if (!cur)
    {
#ifdef NO_ETISS
        std::cout << "Injector::getInjectorPath: Failed to find injector" << std::endl;
#else
        etiss::log(etiss::ERROR, "Injector::getInjectorPath: Failed to find injector to create path name",
                   ETISS_SRCLOC);
#endif
        return "";
    }

    // get names of parent VirtualStructs and combine them to path
    cur = iptr;
    iptr = iptr->getParentInjector();
    while (iptr)
    {
        std::list<std::string> si = iptr->listSubInjectors();
        bool ok = false;
        for (std::list<std::string>::const_iterator iter = si.begin(); iter != si.end(); ++iter)
        {
            ptr tmp = iptr->getSubInjector(*iter);
            if (tmp == cur)
            {
                path = *iter + "::" + path;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
#ifdef NO_ETISS
            std::cout << "Injector::getInjectorPath: Failed to find injector" << std::endl;
#else
            etiss::log(etiss::ERROR, "Injector::getInjectorPath: Failed to find injector to create path name",
                       ETISS_SRCLOC);
#endif
            return "";
        }
        cur = iptr;
        iptr = iptr->getParentInjector();
    }

    return path;
}

void Injector::addTrigger(const Trigger &t, int32_t fault_id)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::addTrigger(Trigger&=") + t.toString() +
                                   ", fault_id=" + std::to_string(fault_id) + ")");
#if CXX0X_UP_SUPPORTED
    std::lock_guard<std::mutex> lock(sync);
#endif

    // TODO: Commented out by MuellerGritschneder as it caused crash for time trigger
    if (acceleratedTrigger(t, fault_id))
    {

        // trigger is handled internally without callbacks
    }
    else
    {
        pending_triggers.push_back(std::pair<Trigger, int32_t>(t, fault_id));
        has_pending_triggers = true;
    }
}

bool Injector::acceleratedTrigger(const etiss::fault::Trigger &t, int32_t fault_id)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::acceleratedTrigger(Trigger&=") +
                                   t.toString() + ", fault_id=" + std::to_string(fault_id) + ")");
    return false;
}

} // namespace fault

} // namespace etiss
