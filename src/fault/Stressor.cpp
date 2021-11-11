/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#ifndef NO_ETISS
#include "etiss/fault/Stressor.h"
#include "etiss/Misc.h"
#include "etiss/fault/Injector.h"
#else
#include "fault/Injector.h"
#include "fault/Stressor.h"
#endif

#include <fstream>
#include <iostream>
#include <map>

#if CXX0X_UP_SUPPORTED
#include <mutex>
#endif

namespace etiss
{

namespace fault
{

#if CXX0X_UP_SUPPORTED
static std::mutex &faults_sync()
{
    static std::mutex mu;
    return mu;
}
#endif
// Map with all faults found in XML file
static std::map<int32_t, Fault> &faults()
{
    static std::map<int32_t, Fault> map;
    return map;
}

bool Stressor::loadXML(const std::string &file, const int coreID)
{

#ifdef NO_ETISS
    std::cout << std::string("Called etiss::fault::Stressor::loadXML(file=") + file + std::string(")") << std::endl;
#else
    etiss::log(etiss::INFO, std::string("Called etiss::fault::Stressor::loadXML(file=") + file + std::string(")"));
#endif

    coreIDActuallXML = coreID;

    // Vector which gets the faults of the xml file
    std::vector<Fault> faults;

    // open and parse file
    std::ifstream in;
    in.open(file.c_str());
    if (!in.is_open())
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::loadXML(): Failed open file " << file << std::endl;
#else
        etiss::log(etiss::ERROR, std::string("etiss::fault::Stressor::loadXML:") +
                                     std::string(" Failed to open Trigger file ") + file);
#endif
        return false;
    }
    if (!etiss::fault::parseXML(faults, in, std::cout))
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::loadXML: Failed parse file " << file << std::endl;
#else
        etiss::log(etiss::ERROR,
                   std::string("etiss::fault::Stressor::loadXML:") + std::string(" Failed to parse file ") + file);
#endif
        return false;
    }

    // add faults into a map ->  access with static std::map<int32_t,Fault> &
    // faults()
    bool ok = true;
    for (size_t i = 0; i < faults.size(); ++i)
    {
        if (!addFault(faults[i]))
        {
#ifdef NO_ETISS
            std::cout << "etiss::fault::Stressor::loadXML: Failed to add Fault: " << faults[i].name_ << std::endl;
#else
            etiss::log(etiss::ERROR,
                       std::string("etiss::fault::Stressor::loadXML:") + std::string(" Failed to add Fault "),
                       faults[i]);
#endif
            ok = false;
        }
    }
    return ok;
}

bool Stressor::addFault(const Fault &f)
{
#if CXX0X_UP_SUPPORTED
    std::lock_guard<std::mutex> lock(faults_sync());
#endif

#ifdef NO_ETISS
    std::cout << "etiss::fault::Stressor::addFault called." << std::endl;
#else
    etiss::log(etiss::INFO, std::string("etiss::fault::Stressor::addFault called. "));
#endif

    // check if fault already exists
    std::map<int32_t, Fault>::iterator find = faults().find(f.id_);
    if (find != faults().end())
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::addFault:  Trigger already exists:" << f.toString() << std::endl;
#else
        etiss::log(etiss::ERROR,
                   std::string("etiss::fault::Stressor::addFault:") + std::string("  Trigger already exists. "), f);
#endif
        return false;
    }

    // insert fault into map
    faults().insert(std::pair<int32_t, Fault>(f.id_, f));

    // Iterate through triggers of the fault
    for (std::vector<Trigger>::const_iterator iter = f.triggers.begin(); iter != f.triggers.end(); ++iter)
    {
        if(iter->getType() != etiss::fault::Trigger::NOP) // only add Trigger, if it is not a NOP
        {
            Injector::ptr iptr = iter->getInjector();

            if (iptr)
            {
#ifdef NO_ETISS
                std::cout << "etiss::fault::Stressor::addFault: Added trigger: " << iter->toString() << std::endl;
#else
                etiss::log(etiss::INFO, std::string("etiss::fault::Stressor::addFault:") + std::string(" Added trigger: "),
                           *iter);
#endif
                iptr->addTrigger(*iter, f.id_);
            }
            else
            {
#ifdef NO_ETISS
                std::cout << "etiss::fault::Stressor::addFault: Error: Injector not found for: " << iter->toString()
                          << std::endl;
#else
                etiss::log(etiss::ERROR,
                           std::string("etiss::fault::Stressor::addFault:") + std::string(" Injector not found for "),
                           *iter);
#endif
                /// TODO signal error and roll back
            }
        }
        else // Trigger is of type NOP
        {
            etiss::log(etiss::WARNING, std::string("etiss::fault::Stressor::addFault:") + std::string(" Trigger is a NOP and is not added."));
        }
    }

    return true;
}

bool Stressor::firedTrigger(const Trigger &triggered, int32_t fault_id, Injector *injector, uint64_t time_ps)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Stressor::firedTrigger() called. "));
#if CXX0X_UP_SUPPORTED
    std::lock_guard<std::mutex> lock(faults_sync());
#endif
    bool ret = true;
    // find fault in fault-map
    std::map<int32_t, Fault>::iterator find = faults().find(fault_id);
    if (find != faults().end())
    {
        // iterate through the actions of the given fault
        for (std::vector<etiss::fault::Action>::iterator iter = find->second.actions.begin();
             iter != find->second.actions.end(); ++iter)
        {
            if (iter->getType() == etiss::fault::Action::INJECTION)
            {
                /// TODO for time relative triggers resolve time must be called!
                addFault(iter->getFault(), true);
            }
            else if(iter->getType() == etiss::fault::Action::NOP)
            {
                etiss::log(etiss::VERBOSE, std::string("Stressor::firedTrigger: Discarded - Action is NOP (do not care)."));
                return true;
            }
            else
            {
                if (iter->getInjectorAddress().getInjector())
                {
#if CXX0X_UP_SUPPORTED
                    if (iter->getInjectorAddress().getInjector().get() != injector)
#else
                    if (iter->getInjectorAddress().getInjector() != injector)
#endif
                    {
#ifndef NO_ETISS
                        etiss::log(etiss::WARNING,
                                   std::string("etiss::fault::Stressor::firedTrigger: Action") +
                                       std::string(" injector is not the injector that triggered this event.") +
                                       std::string(" threadsafety must be ensured by user."),
                                   find->second, *iter);
#endif
                    }
                    std::string err;
                    bool ret_applyaction = iter->getInjectorAddress().getInjector()->applyAction(find->second, *iter, err);
                    if (!ret_applyaction)
                    {
#ifdef NO_ETISS
                        std::cout << "Stressor::firedTrigger: Failed to apply action. Fault: " << fault_id << " ["
                                  << err << "]" << std::endl;
#else
                        etiss::log(etiss::ERROR, std::string("Stressor::firedTrigger: Failed to apply action "),
                                   find->second, *iter, err);
#endif
                    }
                    ret = ret && ret_applyaction; // mask return value with ret_applyaction foreach(!) action, return false, if one fails
                }
                else
                {
#ifdef NO_ETISS
                    std::cout << "Stressor::firedTrigger: Failed to find action target. Fault: " << fault_id
                              << std::endl;
#else
                    etiss::log(etiss::ERROR, std::string("Stressor::firedTrigger: Failed to find action target"),
                               find->second, *iter);
#endif
                }
            }
        }
    }
    else
    {
#ifdef NO_ETISS
        std::cout << "Stressor::firedTrigger: Failed to find triggered Fault: " << fault_id << std::endl;
#else
        etiss::log(etiss::ERROR, std::string("Stressor::firedTrigger: Failed to find triggered Fault: "), fault_id);
#endif
    }

    return ret;
}

void Stressor::clear()
{
#if CXX0X_UP_SUPPORTED
    std::lock_guard<std::mutex> lock(faults_sync());
#endif
    faults().clear();
}

} // namespace fault

} // namespace etiss
