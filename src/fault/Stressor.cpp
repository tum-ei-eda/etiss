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
#include "etiss/fault/Injector.h"
#include "etiss/fault/InjectorAddress.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/Action.h"
#include "etiss/fault/Fault.h"
#include "etiss/Misc.h"
#else
#include "fault/Stressor.h"
#include "fault/Injector.h"
#include "fault/InjectorAddress.h"
#include "fault/Trigger.h"
#include "fault/Action.h"
#include "fault/Fault.h"
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
// Map with all fault definitions found in XML file
std::map<int32_t, Fault> &Stressor::faults()
{
    static std::map<int32_t, Fault> map;
    return map;
}

#ifndef NO_ETISS
etiss::int32 Stressor::event_code_;
#else
int Stressor::event_code_;
#endif

bool Stressor::loadXML(const std::string &file, const int coreID)
{

#ifdef NO_ETISS
    std::cout << std::string("Called etiss::fault::Stressor::loadXML(file=") + file + std::string(")") << std::endl;
#else
    etiss::log(etiss::INFO, std::string("Called etiss::fault::Stressor::loadXML(file=") + file + std::string(")"));
#endif

    coreIDActuallXML = coreID;

    // Vector which gets the faults of the xml file
    std::vector<Fault> fault_definitions;
    std::vector<FaultRef> initial_faults;

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
    pugi::xml_document doc;

    if (!etiss::fault::parseXML(doc, in, std::cout))
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::loadXML: Failed parse file " << file << std::endl;
#else
        etiss::log(etiss::ERROR,
                   std::string("etiss::fault::Stressor::loadXML:") + std::string(" Failed to parse file ") + file);
#endif
        return false;
    }

    xml::Diagnostics diag;

    if (!etiss::fault::parseXML(fault_definitions, doc, diag))
    {
        std::stringstream ss;
        diag.print(ss);
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::loadXML: Failed parse Fault definitions " << ss << std::endl;
#else
        etiss::log(etiss::ERROR, std::string("etiss::fault::Stressor::loadXML:") +
                                     std::string(" Failed parse Fault definitions ") + ss.str());
#endif
        return false;
    }

    // add fault_definitions into a map ->  access with static std::map<int32_t,Fault> &
    // faults()
    bool ok = true;
    for (const auto &fdef : fault_definitions)
    {
        if (!addFaultDefinition(fdef))
        {
#ifdef NO_ETISS
            std::cout << "etiss::fault::Stressor::loadXML: Failed to add Fault definitions: " << fdef.name_
                      << std::endl;
#else
            etiss::log(etiss::ERROR,
                       std::string("etiss::fault::Stressor::loadXML:") +
                           std::string(" Failed to add Fault definitions "),
                       fdef);
#endif
            ok = false;
        }
    }

    if (!etiss::fault::parseXML(initial_faults, doc, diag))
    {
        std::stringstream ss;
        diag.print(ss);
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::loadXML: Failed parse initial Faults " << ss << std::endl;
#else
        etiss::log(etiss::ERROR, std::string("etiss::fault::Stressor::loadXML:") +
                                     std::string(" Failed parse initial Faults ") + ss.str());
#endif
        return false;
    }

    for (const auto &fref : initial_faults)
    {
        if (!addFault(fref.get_fault()))
        {
#ifdef NO_ETISS
            std::cout << "etiss::fault::Stressor::loadXML: Failed to add initial Fault: " << fref.name_ << std::endl;
#else
            etiss::log(etiss::ERROR,
                       std::string("etiss::fault::Stressor::loadXML:") + std::string(" Failed to add initial Fault "),
                       fref);
#endif
            ok = false;
        }
    }

    return ok;
}

bool Stressor::addFaultDefinition(const Fault &f)
{

#ifdef NO_ETISS
    std::cout << "etiss::fault::Stressor::addFaultDefinition called." << std::endl;
#else
    etiss::log(etiss::INFO, std::string("etiss::fault::Stressor::addFaultDefinition called. "));
#endif

    // check if fault already exists
    std::map<int32_t, Fault>::iterator find = faults().find(f.id_);
    if (find != faults().end())
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::addFaultDefinition: Fault definition already registered:" << f.toString()
                  << std::endl;
#else
        etiss::log(etiss::ERROR,
                   std::string("etiss::fault::Stressor::addFaultDefinition:") +
                       std::string(" Fault definition already registered: "),
                   f);
#endif
        return false;
    }

    // insert fault into the definitions map
    faults().insert(std::pair<int32_t, Fault>(f.id_, f));

    return true;
}

bool Stressor::addFault(const Fault &f, bool injected_fault)
{

#if CXX0X_UP_SUPPORTED
    if (!injected_fault) // otherwise a deadlock from firedTrigger->addFault would occur
        std::lock_guard<std::mutex> lock(faults_sync());
#endif

    Injector::ptr iptr = nullptr;

    // check if fault is registered in fault definitions table
    std::map<int32_t, Fault>::iterator find = faults().find(f.id_);
    if (find == faults().end())
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::addFault: Fault not registered in Fault definitions:" << f.toString()
                  << std::endl;
#else
        etiss::log(etiss::ERROR,
                   std::string("etiss::fault::Stressor::addFault:") +
                       std::string(" Fault not registered in Fault definitions. "),
                   f);
#endif
        return false;
    }

    // Iterate through triggers of the fault
    for (const auto &trigger : f.triggers)
    {

        if (trigger.getType() != +etiss::fault::Trigger_Type::NOP) // only add Trigger, if it is not a NOP
        {
            iptr = trigger.getInjector();

            if (iptr != nullptr)
            {
#ifdef NO_ETISS
                std::cout << "etiss::fault::Stressor::addFault: Added trigger: " << trigger.toString() << std::endl;
#else
                etiss::log(etiss::INFO,
                           std::string("etiss::fault::Stressor::addFault:") + std::string(" Added trigger: "), trigger);
#endif
                iptr->addTrigger(trigger, f.id_);
            }
            else
            {
#ifdef NO_ETISS
                std::cout << "etiss::fault::Stressor::addFault: Error: Injector not found for: " << trigger.toString()
                          << std::endl;
#else
                etiss::log(etiss::ERROR,
                           std::string("etiss::fault::Stressor::addFault:") + std::string(" Injector not found for "),
                           trigger);
#endif
                /// TODO signal error and roll back
            }
        }
        else // Trigger is of type NOP
        {
            etiss::log(etiss::WARNING, std::string("etiss::fault::Stressor::addFault:") +
                                           std::string(" Trigger is a NOP and is not added."));
        }
    }

    if (iptr != nullptr)
    {
        for (const auto &it : f.actions)
        {
            if (it.is_action_on_field())
            {
                bool ret_update = false;
                std::string errormsg;
                ret_update = iptr->update_field_access_rights(it, errormsg);
                if (!ret_update)
                {
                    etiss::log(etiss::ERROR, std::string("etiss::fault::Stressor::addFault:") + errormsg);
                }
            }
        }
    }

    return true;
}

bool Stressor::removeFault(const Fault &f, bool injected_fault)
{

#if CXX0X_UP_SUPPORTED
    if (!injected_fault) // otherwise a deadlock from firedTrigger->addFault would occur
        std::lock_guard<std::mutex> lock(faults_sync());
#endif

    Injector::ptr iptr = nullptr;

    // check if fault is registered in fault definitions table
    std::map<int32_t, Fault>::iterator find = faults().find(f.id_);
    if (find == faults().end())
    {
#ifdef NO_ETISS
        std::cout << "etiss::fault::Stressor::addFault: Fault not registered in Fault definitions:" << f.toString()
                  << std::endl;
#else
        etiss::log(etiss::ERROR,
                   std::string("etiss::fault::Stressor::addFault:") +
                       std::string(" Fault not registered in Fault definitions. "),
                   f);
#endif
        return false;
    }

    // Iterate through triggers of the fault
    for (const auto &trigger : f.triggers)
    {

        if (trigger.getType() != +etiss::fault::Trigger_Type::NOP) // don't care
        {
            iptr = trigger.getInjector();

            if (iptr != nullptr)
            {
#ifdef NO_ETISS
                std::cout << "etiss::fault::Stressor::removeFault: Removed trigger: " << trigger.toString()
                          << std::endl;
#else
                etiss::log(etiss::INFO,
                           std::string("etiss::fault::Stressor::removeFault:") + std::string(" Removed trigger: "),
                           trigger);
#endif
                iptr->removeTrigger(trigger, f.id_);
            }
            else
            {
#ifdef NO_ETISS
                std::cout << "etiss::fault::Stressor::removeFault: Error: Injector not found for: "
                          << trigger.toString() << std::endl;
#else
                etiss::log(etiss::ERROR,
                           std::string("etiss::fault::Stressor::removeFault:") +
                               std::string(" Injector not found for "),
                           trigger);
#endif
                /// TODO signal error and roll back
            }
        }
        else // Trigger is of type NOP
        {
            etiss::log(etiss::WARNING, std::string("etiss::fault::Stressor::removeFault:") +
                                           std::string(" Trigger is a NOP and is does not need to be removed."));
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
            switch (iter->getType())
            {
            case +etiss::fault::Action_Type::INJECTION:
                if (!iter->getFaultRef().is_set())
                {
                    // try to resolve the reference again
                    if (!iter->getFaultRef().resolve_reference())
                    {
                        etiss::log(
                            etiss::ERROR,
                            std::string(
                                "Stressor::firedTrigger: Injected Fault reference not found in fault definitions."),
                            iter->getFaultRef());
                    }
                }
                addFault(iter->getFaultRef().get_fault(), true);
                break;
            case +etiss::fault::Action_Type::EJECTION:
                if (!iter->getFaultRef().is_set())
                {
                    // try to resolve the reference again
                    if (!iter->getFaultRef().resolve_reference())
                    {
                        etiss::log(
                            etiss::ERROR,
                            std::string(
                                "Stressor::firedTrigger: Injected Fault reference not found in fault definitions."),
                            iter->getFaultRef());
                    }
                }
                removeFault(iter->getFaultRef().get_fault(), true);
                break;
            case +etiss::fault::Action_Type::NOP:
                etiss::log(etiss::VERBOSE,
                           std::string("Stressor::firedTrigger: Discarded - Action is NOP (do not care)."));
                return true;
#ifndef NO_ETISS
            case +etiss::fault::Action_Type::EVENT:
                etiss::log(etiss::VERBOSE, std::string("Stressor::firedTrigger: Action is EVENT"));
                set_event(iter->getEvent());
                return true;
#endif
            default: // on field actions
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
                        etiss::log(etiss::VERBOSE,
                                   std::string("etiss::fault::Stressor::firedTrigger: Action") +
                                       std::string(" injector is not the injector that triggered this event.") +
                                       std::string(" threadsafety must be ensured by user."),
                                   find->second, *iter);
#endif
                    }
                    std::string err;
                    bool ret_applyaction =
                        iter->getInjectorAddress().getInjector()->applyAction(find->second, *iter, err);
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
                    ret = ret && ret_applyaction; // mask return value with ret_applyaction foreach(!) action, return
                                                  // false, if one fails
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

bool parseXML(pugi::xml_document &doc, std::istream &input, std::ostream &diagnostics_out)
{
    pugi::xml_parse_result pr = doc.load(input); // load from stream

    if (!pr)
    { // load failure
        diagnostics_out << "failed to load xml from stream: " << pr.description() << std::endl;
        return false;
    }

    return true;
}

} // namespace fault

} // namespace etiss
