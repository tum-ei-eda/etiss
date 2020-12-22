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

        @date December 15, 2014

        @version 0.4

*/
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
#include "etiss/fault/Action.h"
#include "etiss/fault/Defs.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/XML.h"
#else
#include "fault/Action.h"
#include "fault/Defs.h"
#include "fault/Trigger.h"
#include "fault/XML.h"
#endif

/// if true then mutex will be used to create unique ids for faults in a threadsafe way
#define MUTEX_SUPPORTED CXX0X_UP_SUPPORTED

namespace etiss
{
namespace fault
{

typedef uint64_t INT;

class Action;

class Fault : public etiss::ToString
{
  public:
    Fault(); ///< Constructor: Generates a new Fault with unique ID

    std::string toString() const; ///< operator<< can be used.

    void resolveTime(uint64_t time); ///< Resolves time for all its Triggers.
    bool isResoved() const;          ///< check all Triggers if they are resolved.

  public:
    std::string name_;
    int32_t id_;                   ///< @attention negative ids are reserved
    std::vector<Trigger> triggers; ///< contains the triggers for this fault
    std::vector<Action> actions;   ///< contains the actions for this fault
};

#if ETISS_FAULT_XML

bool parseXML(std::vector<Fault> &vec, std::istream &input, std::ostream &diagnostics_out = std::cout);

bool writeXML(const std::vector<Fault> &vec, std::ostream &out, std::ostream &diagnostics_out = std::cout);

namespace xml
{

template <>
bool parse<etiss::fault::Fault>(pugi::xml_node node, etiss::fault::Fault &f, Diagnostics &diag);
template <>
bool write<etiss::fault::Fault>(pugi::xml_node node, const etiss::fault::Fault &f, Diagnostics &diag);

} // namespace xml

#endif

} // namespace fault
} // namespace etiss

#endif
