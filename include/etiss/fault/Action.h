// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
#else
#include "fault/Defs.h"
#endif
#include "enum.h"

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

    /// MASK only
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
