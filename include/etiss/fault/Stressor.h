// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief contains the stressor class that loads and activates faults.

        @detail

*/

#ifndef ETISS_STRESSOR_H_
#define ETISS_STRESSOR_H_

#ifndef NO_ETISS
#include "etiss/jit/ReturnCode.h"
#endif

#include <iostream>

namespace etiss
{

namespace fault
{

class Fault;
class Trigger;
class Action;
class Injector;

class Stressor
{
  public:
    enum Event
    {
        TERMINATE = (1 << 0)
#ifndef NO_ETISS
            ,
        ETISS_FLUSH_TRANSLATION_CACHE = (1 << 1),
        ETISS_RELOAD_TRANSLATION_BLOCK = (1 << 2)
#else
#endif
    };

#ifndef NO_ETISS
  private:
    static etiss::int32 event_code_;

  public:
    static etiss::int32 get_event(void) { return event_code_; }
    static void set_event(etiss::int32 code) { event_code_ = code; }
#else
  private:
    static int event_code_;

  public:
    static int get_event(void) { return event_code_; }
    static void set_event(int code) { event_code_ = code; }
    static void set_event_flag(Event flag) { event_code_ |= flag; }
#endif
    static void reset_event(void) { event_code_ = 0; }
    /** @brief extracts faults out of the given xml file.
     * @param file the xmlfile with fault triggers.
     * @return true if XML file could be loaded.
     */
    static bool loadXML(const std::string &file, const int coreID = 0);

    /** @brief adds a fault to a static map that can be accessed
     *        by static std::map<int32_t,Fault> & faults().
     * @param f the fault for adding to the map.
     * @return false if fault already exists in map faults().
     */
    static bool addFaultDefinition(const Fault &f);

    /** @brief activates a fault's triggers in their injectors
     * @param f the fault to activate
     * @return false if refernced fault is not the static fault list faults().
     */
    static bool addFault(const Fault &f, bool injected_fault = false);

    /** @brief removes a fault's active triggers from their injectors, thus,
     *         deactivating the fault.
     * @param f the fault for adding to the map.
     * @return false if referenced fault is not the static fault list faults().
     */
    static bool removeFault(const Fault &f, bool injected_fault = false);

    /** @brief Checks if the given trigger is valid and calls applyAction.
     *
     *         Is called by a VirtualStruct e.g. OR1KVCPU::vcoreState.
     *         The VirtualStruct inherits the Injector so it can call
     *         Injector::cycleAccurateCallback, which calls this function
     * @param firedTrigger the Trigger which was called.
     * @param fault_id the id of the fault to which the trigger corresponds.
     * @param injector injector which called this function.
     * @param time_ps cpu time.
     * @return true if the fired trigger expired.
     */
    static bool firedTrigger(const Trigger &firedTrigger, int32_t fault_id, Injector *injector, uint64_t time_ps);

    /** @brief clears the fault map.
     */
    static void clear();
    /** @brief static map with all referencable faults.
     */
    static std::map<int32_t, Fault> &faults();
};

} // namespace fault

} // namespace etiss

#endif
