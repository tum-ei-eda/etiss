// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef NO_ETISS
#include "etiss/fault/Injector.h"
#include "etiss/Misc.h"
#include "etiss/fault/Stressor.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/Action.h"
#include "etiss/fault/Fault.h"
#else
#include "fault/Injector.h"
#include "fault/Stressor.h"
#include "fault/Trigger.h"
#include "fault/Action.h"
#include "fault/Fault.h"
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
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Injector::freeFastFieldAccessPtr(void*) not implemented"));
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
    if (unlikely(has_pending_triggers))
    {
#if CXX0X_UP_SUPPORTED
        std::lock_guard<std::mutex> lock(sync);
#endif
        unknown_triggers.insert(unknown_triggers.end(), pending_triggers.begin(), pending_triggers.end());
        pending_triggers.clear();
    }
    if (unlikely(has_remove_triggers))
    {
#if CXX0X_UP_SUPPORTED
        std::lock_guard<std::mutex> lock(sync);
#endif
        unknown_triggers.erase(std::remove_if(unknown_triggers.begin(), unknown_triggers.end(),
                                              [&](const auto &unknown)
                                              {
                                                  for (const auto &rm : remove_triggers)
                                                  {
                                                      if (unknown.second == rm.second)
                                                          return true;
                                                  }
                                                  return false;
                                              }),
                               unknown_triggers.end());
        remove_triggers.clear();
        has_remove_triggers = false;
    }
    // check triggers
    if (!unknown_triggers.empty())
    {
        for (auto &it : unknown_triggers)
        {
            if (it.first.check(time_ps, this))
            { // trigger fired
                // signal fired trigger
                ret = true;
                if (Stressor::firedTrigger(it.first, it.second, this, time_ps))
                {
                    // explicitly remove triggers through Stressor::removeFault via Action::Type::EJECTION
                }
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
    if (!iptr)
        return path;

    // Get Injector name
    ptr cur;
    for (const auto &name : iptr->listSubInjectors())
    {
        cur = iptr->getSubInjector(name);
        if (cur == this)
        {
            path = name;
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
        bool ok = false;
        for (const auto &name : iptr->listSubInjectors())
        {
            ptr tmp = iptr->getSubInjector(name);
            if (tmp == cur)
            {
                path = name + "::" + path;
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

void Injector::removeTrigger(const Trigger &t, int32_t fault_id)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::removeTrigger(Trigger&=") + t.toString() +
                                   ", fault_id=" + std::to_string(fault_id) + ")");
#if CXX0X_UP_SUPPORTED
    std::lock_guard<std::mutex> lock(sync);
#endif
    remove_triggers.push_back(std::pair<Trigger, int32_t>(t, fault_id));
    has_remove_triggers = true;
}

bool Injector::acceleratedTrigger(const etiss::fault::Trigger &t, int32_t fault_id)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::Injector::acceleratedTrigger(Trigger&=") +
                                   t.toString() + ", fault_id=" + std::to_string(fault_id) + ")");
    return false;
}

} // namespace fault

} // namespace etiss
