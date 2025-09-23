/**

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date December 15, 2014

        @version 0.4

*/
/**
        @file

        @brief contains the Trigger class that defines conditions under which actions of a Fault need to be applied.

        @detail

*/
#ifndef ETISS_FAULT_TRIGGER_H_
#define ETISS_FAULT_TRIGGER_H_

#include <iostream>
#include <stdint.h>

#if CXX0X_UP_SUPPORTED
#include <memory>
#endif

#ifndef NO_ETISS
#include "etiss/Misc.h"
#include "etiss/fault/Misc.h"
#else
#include "fault/Misc.h"
#endif

#include "enum.h"

namespace etiss
{
namespace fault
{

class Injector;
class InjectorAddress;

#if CXX0X_UP_SUPPORTED
typedef std::shared_ptr<Injector> Injector_ptr;
#else
typedef Injector *Injector_ptr;
#endif

BETTER_ENUM(Trigger_Type, char, NOP = 0, META_COUNTER, VARIABLEVALUE, TIME, TIMERELATIVE, ASAP)

class Trigger : public etiss::ToString
{
  public:
    typedef Trigger_Type type_t;
    // constructors
    /**
        Type: NOP (no operation)
    */
    Trigger();
    // constructors
    /**
        Type: typed but empty constructor (used for ASAP)
    */
    Trigger(const InjectorAddress &target_injector);
    /**
     *	@note Type: META_COUNTER
     *
     *	@brief This Trigger counts with \p count how often a \p sub trigger e.g. VRIABLEVALUE trigger fires.
     *	        When this \p sub trigger fires the \p count 'th time, the META_COUNTER trigger fires itself.
     */
    Trigger(const Trigger &sub, uint64_t count);
    /**
     *	@note Type: VARIABLEVALUE
     *
     *	@brief This Trigger fires when variable \p field has the value \p value.
     */
    Trigger(const InjectorAddress &target_injector, const std::string &field, uint64_t value);
    /**
     *	@note Type: TIMERELATIVE or TIME
     *
     *	@brief This Trigger fires when a specific runtime has passed.
     */
    Trigger(const InjectorAddress &target_injector, uint64_t time_ps, bool relative = false);

    // Copy Constructors
    Trigger(const Trigger &cpy);
    Trigger &operator=(const Trigger &cpy);

#if CXX0X_UP_SUPPORTED
    Trigger(Trigger &&cpy);
    Trigger &operator=(Trigger &&cpy);
#endif

    ~Trigger();

    // Getter
    uint64_t getTriggerCount() const;
    const Trigger &getSubTrigger() const;
    uint64_t getTriggerTime() const;
    const InjectorAddress &getInjectorAddress() const;
    const Injector_ptr &getInjector() const;
    bool isNOP() const;
    const std::string &getTriggerField() const;
    const uint64_t &getTriggerFieldValue() const;
    const type_t &getType() const;

    // Members
    /** @brief this function checks if the Trigger has just fired.
     */
    bool check(uint64_t time_ps, etiss::fault::Injector *target_injector);

    /** @brief this function calculates in case of a TIMERELATIVE Trigger a
     *         constant TIME trigger
     */
    void resolveTime(uint64_t time);
    /** @brief returns if the translation from TIMERELATIVE to TIME trigger has
     *         taken place
     */
    bool isResolved() const;

    std::string toString() const; ///< operator<< can be used.

  private: // Attributes
    type_t type_;
    std::string field_;
    std::unique_ptr<Trigger> sub_;
    std::unique_ptr<InjectorAddress> inj_;
    void *fieldptr_;
    uint64_t param1_{ 0 };
    uint64_t param2_{ 0 };

    // Private Members
    void ensure(type_t type) const;
};

#if ETISS_FAULT_XML
namespace xml
{



} // namespace xml
#endif

} // namespace fault
} // namespace etiss

#endif // ETISS_FAULT_TRIGGER_H_
