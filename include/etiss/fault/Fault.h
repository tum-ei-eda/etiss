// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief contains the fault container class that stores triggers and actions for fault injection

        @detail

*/
#ifndef ETISS_FAULT_FAULT_H_
#define ETISS_FAULT_FAULT_H_

#include <exception>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <stdint.h>
#include <vector>

#ifndef NO_ETISS
#include "etiss/Misc.h"
#include "etiss/fault/Defs.h"
#else
#include "fault/Defs.h"
#endif

/// if true then mutex will be used to create unique ids for faults in a threadsafe way
#define MUTEX_SUPPORTED CXX0X_UP_SUPPORTED

namespace etiss
{
namespace fault
{

typedef uint64_t INT;

class Action;
class Trigger;

class Fault : public etiss::ToString
{
  public:
    std::string toString() const; ///< operator<< can be used.

    void resolveTime(uint64_t time); ///< Resolves time for all its Triggers.
    bool isResoved() const;          ///< check all Triggers if they are resolved.

    Fault(); ///< Constructor: Generates a new Fault with unique ID
    Fault(int nullid);

  public:
    std::string name_;
    int32_t id_;                   ///< @attention negative ids are reserved
    std::vector<Trigger> triggers; ///< contains the triggers for this fault
    std::vector<Action> actions;   ///< contains the actions for this fault
};

class FaultRef : public etiss::ToString
{
  private:
    mutable Fault fault_; ///< referenced Fault, needs to be resolved during sim. runtime
    std::string name_;    ///< string identifier, used to resolve actual reference via fault_

  public:
    std::string toString() const; ///< operator<< can be used.

    bool is_set() const { return (fault_.name_ == name_); }
    bool set_fault_reference(const std::string &identifier);
    bool resolve_reference() const;
    const Fault &get_fault() const { return fault_; }
    const std::string &get_name() const { return name_; }
};

#if ETISS_FAULT_XML

namespace xml
{

} // namespace xml

#endif

} // namespace fault
} // namespace etiss

#endif
