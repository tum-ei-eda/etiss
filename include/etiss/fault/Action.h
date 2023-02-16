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

        @brief contains an action class that describes actions associated with a fault

        @detail

*/
#ifndef ETISS_FAULT_ACTION_H_
#define ETISS_FAULT_ACTION_H_

#include <iostream>
#include <stdint.h>

#ifndef NO_ETISS
#include "etiss/Misc.h"
#include "etiss/fault/Defs.h"
#include "enum.h"
#else
#include "fault/Defs.h"
#include "enum.h"
#endif

namespace etiss
{
namespace fault
{

class FaultRef;
class InjectorAddress;

//  BITFLIP: applies a bit flip to a bit in a specified field
//  MASK: applies a mask type injection (field <op>= mask;) where <op> can be any MaskOp
//  COMMAND: commands are targetet at Injectors, not fields. in case a command is targetet at a certain field that
//  information must be passed within the command string INJECTION: an action that injects a fault definition (trigger +
//  actions) EJECTION: an action that ejects a referenced fault (which must exist)
//  EVENT: an event that breaks the JIT-block and forces the simulation loop to handle the etiss::RETURNCODE exception
BETTER_ENUM(Action_Type, char, NOP = 0, BITFLIP, MASK, COMMAND, INJECTION, EJECTION, EVENT)
BETTER_ENUM(Action_MaskOp, char, NOP = 0, AND, OR, XOR, NAND, NOR)

class Action : public etiss::ToString
{
  public:
    typedef Action_Type type_t;
    typedef Action_MaskOp mask_op_t;
    /**
     *	@brief returns true if type_ is an action on a Field
     */
    bool is_action_on_field(void) const;

    // Constructors
    /**
     * @note Type: NOP (no operation)
     */
    Action();
#ifndef NO_ETISS
    /**
     *	@note Type: Exception
     *
     *	@brief A etiss::RETURNCODE \p exception will be injected into the etiss simulation loop
     */
    Action(int32_t event);
#endif
    /**
     *	@note Type: Command
     *
     *	@brief abstract string command will be passed to the targeted injector
     */
    Action(const InjectorAddress &inj, const std::string &command);
    /**
     *	@note Type: BitFlip
     *
     *	@brief the bit at the given position of the given field of the given injector will be flipped
     */
    Action(const InjectorAddress &inj, const std::string &field, unsigned bit);
    /**
     *	@note Type: MASK
     *
     *	@brief applies a mask type injection (field op= mask;) where <op> can be bitwise AND, OR, XOR, NAND, NOR
     */
    Action(const InjectorAddress &inj, const std::string &field, mask_op_t mask_op, uint64_t mask_value);
    /**
     * @note Type: Injection
     *
     * @brief injects a fault. this is especially usefull with Triggers of type TIMERELATIVE
     */
    Action(const FaultRef &fault_ref, type_t type);

    // Copy Constructors
    Action(const Action &cpy);
    Action &operator=(const Action &cpy);

#if CXX0X_UP_SUPPORTED
    Action(Action &&cpy);
    Action &operator=(Action &&cpy);
#endif

    // Getters
    const type_t &getType() const;

    const InjectorAddress &getInjectorAddress() const;

    /// COMMAND only
    const std::string &getCommand() const;

    /// BITFLIP only
    const std::string &getTargetField() const;
    unsigned getTargetBit() const;

    /// INJECTION and EJECTION only
    const FaultRef &getFaultRef() const;

    const mask_op_t &getMaskOp() const;

    uint64_t getMaskValue() const;
#ifndef NO_ETISS
    int32_t getEvent() const;
#endif
    // Members
    std::string toString() const; ///< operator<< can be used.

  private:                                 // Attributes
    type_t type_;                          ///< type of the Attribute
    std::unique_ptr<InjectorAddress> inj_; ///< Address of Injector
    std::string command_;                  ///< command e.g. for booting OR1KVCPU
    std::string field_;                    ///< concerning Field (for fault injection)
    unsigned bit_ = { 0 };                 ///< concerning Bit (for fault injection)
    mask_op_t mask_op_{ mask_op_t::NOP };  ///< mask operation (for mask injection)
    uint64_t mask_value_{ 0 };             ///< mask value (for mask injection)
    std::unique_ptr<FaultRef> fault_ref_;  ///< for fault injection
#ifndef NO_ETISS
    int32_t event_{ 0 }; ///< exception, or rather etiss::RETURNCODE to
                         /// to be injected into the simulation loop
#endif
    // private Members
    void ensure(type_t);
};

#ifndef NO_ETISS
/**
 *	@brief decode etiss::RETURNCODE from string
 */
bool returncode_fromstring(int32_t &out, const std::string &in);
/**
 *	@brief encode etiss::RETURNCODE to string
 */
std::string returncode_tostring(int32_t in);
#endif

#if ETISS_FAULT_XML

namespace xml
{

} // namespace xml

#endif

} // namespace fault

} // namespace etiss

#endif
