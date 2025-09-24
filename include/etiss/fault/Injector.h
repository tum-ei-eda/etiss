// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief contains the fault injector interface class.

        @detail

*/
#ifndef ETISS_INJECTOR_H_
#define ETISS_INJECTOR_H_

#ifndef NO_ETISS
#include "etiss/Misc.h"
#include "etiss/fault/Defs.h"
#include "etiss/fault/Misc.h"
#else
#include "fault/Defs.h"
#include "fault/Misc.h"
#endif

#if CXX0X_UP_SUPPORTED
#include <functional>
#include <memory>
#include <mutex>
#endif

#include <fstream>

namespace etiss
{

namespace fault
{

class Stressor;
class Fault;
class Trigger;
class Action;

class Injector
{
  public:
#if CXX0X_UP_SUPPORTED
    typedef std::shared_ptr<Injector> ptr;
#else
    typedef Injector *ptr;
#endif

  public: // override in inheriting classes
    Injector();
    virtual ~Injector(){};
    /**
        list all fields directly reachable by this injector
        @see etiss::VirtualStruct for example implemention
    */
    virtual std::list<std::string> listFields() = 0;
    /**
        list all sub injectors.
        @see etiss::VirtualStruct for example implemention
    */
    virtual std::list<std::string> listSubInjectors() = 0;

    /**
        get a sub injector. in case of c++11 this function returns a smart
        pointer (std::shared_ptr<Injector>)
        @see etiss::VirtualStruct for example implemention
    */
    virtual ptr getSubInjector(const std::string &name) = 0;
    /**
        get a the parent injector (root returns 0). in case of c++11 this function
        returns a smart pointer (std::shared_ptr<Injector>)
        @see etiss::VirtualStruct for example implemention
    */
    virtual ptr getParentInjector() = 0;

  public: // callbacks
    virtual bool needsCallbacks();
    virtual bool cycleAccurateCallback(uint64_t time_ps);       // returns if trigger fired
    virtual bool instructionAccurateCallback(uint64_t time_ps); // returns if trigger fired

  public: // currently public functions but might become protected later on
    /**
        @attention MUST NOT be called from without the callback functions
                   cycleAccurateCallback() and instructionAccurateCallback().
                   The assumption of a singlethreaded access/use of these
       functions MUST hold.
        @return 0 in case of failure. otherwise an internal pointer shall be
       retuned that allows to access a field in a quick manner.
       freefastFieldAccessPtr MUST be called after use.
    */
    virtual void *fastFieldAccessPtr(const std::string &name, std::string &errormsg) = 0;
    /**
        MUST be called to cleanup a pointer acquired with fastFieldAccessPtr()
        default implementation is nop
        @attention MUST NOT be called from outside the callback functions
                   cycleAccurateCallback() and instructionAccurateCallback().
                   The assumption of a singlethreaded access/use of these
                   functions MUST hold.
    */
    virtual void freeFastFieldAccessPtr(void *);
    /**
        read the value of a field
        @return true if read succeded
        @attention MUST NOT be called from outside the callback functions
       cycleAccurateCallback() and instructionAccurateCallback(). The assumption
       of a singlethreaded access/use of these functions MUST hold.

    */
    virtual bool readField(void *fastfieldaccessptr, uint64_t &val, std::string &errormsg) = 0;
    /**
        @return true if action could be applied
        @attention MUST NOT be called from without the callback functions
       cycleAccurateCallback() and instructionAccurateCallback(). The assumption
       of a singlethreaded access/use of these functions MUST hold.
    */
    virtual bool applyAction(const etiss::fault::Fault &fault, const etiss::fault::Action &action,
                             std::string &errormsg) = 0;

    virtual bool acceleratedTrigger(const etiss::fault::Trigger &, int32_t fault_id);

    /**
        @brief Update the \p field of injector with access rights to allow \p action (used to get type of action).
        @detail For example, if \p action is of etiss::fault::Action::BITFLIP, \p field requires F flag set
    */
    virtual bool update_field_access_rights(const etiss::fault::Action &action, std::string &errormsg) = 0;

  public: // static
    /**
    @param injectorPath the full path/name to/off an injector. in case of using ETISS/VirtualStruct please have a look
    at the doc of etiss::VirtualStruct for examples of the path syntax
    @attention this function needs to be implemented in case of not using ETISS/VirtualStruct
*/
    static ptr get(const std::string &injectorPath);

    /**
    returns the path of the current object.
    by default the path will consists of the injector names from getSubInjectors() seperated by "::" (see
    etiss::VirtualStruct). override this function to match other/custom syntax

    */
    virtual std::string getInjectorPath();

  private:
#if CXX0X_UP_SUPPORTED
    std::mutex sync;
#endif
    bool has_pending_triggers{ false };
    bool has_remove_triggers{ false };
    std::list<std::pair<Trigger, int32_t>> pending_triggers; ///< Triggers which were just added
    std::list<std::pair<Trigger, int32_t>> unknown_triggers; ///< Triggers to look at in callbacks
    std::list<std::pair<Trigger, int32_t>>
        remove_triggers; ///< Triggers to synchronously remove on next callback (prio over pending)
    /// TODO specialized lists. e.g. time triggers should be sorted and only the earliest time should be checked

  public: // interface for Stressor
    void addTrigger(const Trigger &t, int32_t fault_id);
    void removeTrigger(const Trigger &t, int32_t fault_id);
};

} // namespace fault

} // namespace etiss

#endif
