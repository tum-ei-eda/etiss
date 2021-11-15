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
#include "etiss/fault/Defs.h"
#include "etiss/fault/Fault.h"
#include "etiss/fault/InjectorAddress.h"
#include "etiss/fault/XML.h"
#else
#include "fault/Defs.h"
#include "fault/Fault.h"
#include "fault/InjectorAddress.h"
#include "fault/XML.h"
#endif

namespace etiss
{
namespace fault
{

class Fault;

class Action : public etiss::ToString
{
  public:
    enum Type
    {
        /// NO Operation. used by default constructor
        NOP = 0,
        /// applies a bit flip to a bit in a specified field
        BITFLIP,
        /// applies a mask type injection (field <op>= mask;) where <op> can be any MaskOp
        MASK,
        /// commands are targetet at Injectors, not fields. in case a command is targetet at a certain field that
        /// information must be passed within the command string
        COMMAND,
        /// an action that injects a fault definition (trigger + actions)
        INJECTION
    };
    enum MaskOp
    {
        AND,
        OR,
        XOR,
        NAND,
        NOR
    };

    /**
     *	@brief returns true if type_ is an action on a Field
     */
    bool is_action_on_field(void) const;

    // Constructors
    /**
     * @note Type: NOP (no operation)
     */
    Action();
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
    Action(const InjectorAddress &inj, const std::string &field, MaskOp mask_op, uint64_t mask_value);
    /**
     * @note Type: Injection
     *
     * @brief injects a fault. this is especially usefull with Triggers of type TIMERELATIVE
     */
    Action(const Fault &fault);

    // Getters
    Type getType() const;

    const InjectorAddress &getInjectorAddress() const;

    /// COMMAND only
    const std::string &getCommand() const;

    /// BITFLIP only
    const std::string &getTargetField() const;
    unsigned getTargetBit() const;

    /// INJECTION only
    const Fault &getFault() const;

    MaskOp getMaskOp() const;

    uint64_t getMaskValue() const;

    // Members
    std::string toString() const; ///< operator<< can be used.

  private:      // Attributes
    Type type_;                ///< type of the Attribute
    InjectorAddress inj_;      ///< Address of Injector
    std::string command_;      ///< command e.g. for booting OR1KVCPU
    std::string field_;        ///< concerning Field (for fault injection)
    unsigned bit_;             ///< concerning Bit (for fault injection)
    MaskOp mask_op_;           ///< mask operation (for mask injection)
    uint64_t mask_value_;      ///< mask value (for mask injection)
    std::vector<Fault> fault_; ///< for fault injection

    // private Members
    void ensure(Type);
};

/**
 *	@brief decode Action::MaskOp from string
 */
bool maskop_fromstring(Action::MaskOp& out, const std::string& in);
/**
 *	@brief encode Action::MaskOp to string
 */
std::string maskop_tostring(Action::MaskOp in);


#if ETISS_FAULT_XML

namespace xml
{

template <>
bool parse<etiss::fault::Action>(pugi::xml_node node, etiss::fault::Action &f, Diagnostics &diag);
template <>
bool write<etiss::fault::Action>(pugi::xml_node node, const etiss::fault::Action &f, Diagnostics &diag);

} // namespace xml

#endif

} // namespace fault

} // namespace etiss

#endif
