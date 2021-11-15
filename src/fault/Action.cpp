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
#include "etiss/fault/Action.h"
#else
#include "fault/Action.h"
#endif

#include <sstream>

namespace etiss
{
namespace fault
{

bool maskop_fromstring(Action::MaskOp& out, const std::string& in)
{
    if (in == "AND" or in == "&")
    {
        out = Action::MaskOp::AND;
    }
    else if (in == "OR" or in == "|")
    {
        out = Action::MaskOp::OR;
    }
    else if (in == "XOR" or in == "^")
    {
        out = Action::MaskOp::XOR;
    }
    else if (in == "NAND" or in == "!&")
    {
        out = Action::MaskOp::NAND;
    }
    else if (in == "NOR" or in == "!|")
    {
        out = Action::MaskOp::NOR;
    }
    else
    {
        return false;
    }
    return true;
}

std::string maskop_tostring(Action::MaskOp in)
{
    switch(in)
    {
      case Action::MaskOp::AND:
        return "AND";
      case Action::MaskOp::OR:
        return "OR";
      case Action::MaskOp::XOR:
        return "XOR";
      case Action::MaskOp::NAND:
        return "NAND";
      case Action::MaskOp::NOR:
        return "NOR";
      default:
        return "NOP";
    }
}

void Action::ensure(Type t)
{
    if (type_ != t)
        throw "wrong action type";
}

bool Action::is_action_on_field(void) const
{
    return ((type_ == BITFLIP || type_ == MASK) ? true : false);
}

Action::Action()
  : type_(NOP)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action() called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &command)
  : type_(COMMAND)
  , inj_(inj)
  , command_(command)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", command=") + command + std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, unsigned bit)
  : type_(BITFLIP)
  , inj_(inj)
  , field_(field)
  , bit_(bit)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", bit=") + std::to_string(bit) +
                                   std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, MaskOp mask_op, uint64_t mask_value)
  : type_(MASK)
  , inj_(inj)
  , field_(field)
  , mask_op_(mask_op)
  , mask_value_(mask_value)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", mask_op=") + std::to_string(mask_op) +
                                   std::string(", mask_value=") + std::to_string(mask_value) +
                                   std::string(") called. "));
}

Action::Action(const Fault &fault)
  : type_(INJECTION)
{
    etiss::log(etiss::VERBOSE,
               std::string("etiss::fault::Action::Action(Fault &=") + fault.toString() + std::string(") called. "));
    fault_.push_back(fault);
}

Action::Type Action::getType() const
{
    return type_;
}

const InjectorAddress &Action::getInjectorAddress() const
{
    if(unlikely(!(type_ == BITFLIP || type_ == MASK || type_ == COMMAND)))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getInjectorAddress(): Requested Action::Type has no Injector"));
    return inj_;
}

/// COMMAND only
const std::string &Action::getCommand() const
{
    if(unlikely(type_ != COMMAND))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getCommand(): Requested Action::Type has no Command"));
    return command_;
}

/// is_action_on_field only
const std::string &Action::getTargetField() const
{
    if(unlikely(!(type_ == BITFLIP || type_ == MASK)))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getTargetField(): Requested Action::Type has no TargetField"));
    return field_;
}

/// BITFLIP only
unsigned Action::getTargetBit() const
{
    if(unlikely(type_ != BITFLIP))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getTargetBit(): Requested Action::Type has no TargetBit"));
    return bit_;
}

const Fault &Action::getFault() const
{
    if(unlikely(type_ != INJECTION))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getFault(): Requested Action::Type has no injectable Fault"));
    return fault_.front();
}

Action::MaskOp Action::getMaskOp() const
{
    if(unlikely(type_ != MASK))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getMaskOp(): Requested Action::Type has no Mask"));
    return mask_op_;
}

uint64_t Action::getMaskValue() const
{
    if(unlikely(type_ != MASK))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getMaskValue(): Requested Action::Type has no Mask"));
    return mask_value_;
}

std::string Action::toString() const
{
    pugi::xml_document doc;
    doc.load("<?xml version=\"1.0\"?>");

    etiss::fault::xml::Diagnostics diag;

    etiss::fault::xml::write<etiss::fault::Action>(doc.append_child("action"), *this, diag);

    std::stringstream ss;

    doc.save(ss);

    return ss.str();
}

#if ETISS_FAULT_XML
namespace xml
{
template <>
bool parse<etiss::fault::Action>(pugi::xml_node node, etiss::fault::Action &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::parse<etiss::fault::Action>(node, Action") +
                                   std::string(", Diagnostics) called. "));

    std::string type;
    if (!parse_attr(node, "type", type, diag))
    {
        diag.unexpectedNode(node, "Failed to parse type of action");
        return false;
    }

    if (type == "NOP")
    {
        f = Action();
        return true;
    }
    else if (type == "BITFLIP")
    {
        etiss::fault::InjectorAddress inj;
        if (!etiss::cfg().get<bool>("faultInjection::allowBitFlip", true))
            return true;
        if (!parse<etiss::fault::InjectorAddress>(findSingleNode(node, "injector", diag), inj, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <injector>");
            return false;
        }
        std::string field;
        if (!parse<std::string>(findSingleNode(node, "field", diag), field, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <field>");
            return false;
        }
        setCoreName(field);
        unsigned bit;
        if (!parse<unsigned>(findSingleNode(node, "bit", diag), bit, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <bit>");
            return false;
        }
        f = Action(inj, field, bit);
        return true;
    }
    else if (type == "COMMAND")
    {
        etiss::fault::InjectorAddress inj;
        if (!parse<etiss::fault::InjectorAddress>(findSingleNode(node, "injector", diag), inj, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <injector>");
            return false;
        }
        std::string command;
        if (!parse<std::string>(findSingleNode(node, "command", diag), command, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <command>");
            return false;
        }
        f = Action(inj, command);
        return true;
    }
    else if (type == "INJECTION")
    {
        etiss::fault::Fault inj;
        if (!parse<Fault>(findSingleNode(node, "fault", diag), inj, diag))
        {
            diag.unexpectedNode(node, "Failed to parse <fault> to inject");
            return false;
        }
        f = Action(inj);
        return true;
    }
    else if (type == "MASK")
    {
        etiss::fault::InjectorAddress inj;
        if (!parse<etiss::fault::InjectorAddress>(findSingleNode(node, "injector", diag), inj, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <injector>");
            return false;
        }
        std::string field;
        if (!parse<std::string>(findSingleNode(node, "field", diag), field, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target <field>");
            return false;
        }
        setCoreName(field);
        std::string op_str;
        etiss::fault::Action::MaskOp op;
        if (!parse<std::string>(findSingleNode(node, "op", diag), op_str, diag))
        {
            diag.unexpectedNode(node, "Failed to parse mask operation <op>");
            return false;
        }
        if (! etiss::fault::maskop_fromstring(op, op_str))
        {
            diag.unexpectedNode(node, "Failed to parse mask operation <op>");
            return false;
        }
        uint64_t value;
        if (!parse_hex(findSingleNode(node, "value", diag), value, diag))
        {
            diag.unexpectedNode(node, "Failed to parse mask operation <value>");
            return false;
        }
        f = Action(inj, field, op, value);
        return true;
    }
    else
    {
        diag.unexpectedNode(node, std::string("Unknown type of action: ") + type);
        return false;
    }
    return false;
}
template <>
bool write<etiss::fault::Action>(pugi::xml_node node, const etiss::fault::Action &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::write<etiss::fault::Action>(node, Action&=") +
                                   std::string(", Diagnostics) called. "));
    bool ok = true;
    switch (f.getType())
    {
    case etiss::fault::Action::NOP:
        return write_attr<std::string>(node, "type", "NOP", diag);
        break;
    case etiss::fault::Action::BITFLIP:
        ok = ok & write_attr<std::string>(node, "type", "BITFLIP", diag);
        ok = ok & write(node.append_child("injector"), f.getInjectorAddress(), diag);
        ok = ok & write<std::string>(node.append_child("field"), f.getTargetField(), diag);
        ok = ok & write<unsigned>(node.append_child("bit"), f.getTargetBit(), diag);
        break;
    case etiss::fault::Action::COMMAND:
        ok = ok & write_attr<std::string>(node, "type", "COMMAND", diag);
        ok = ok & write<std::string>(node.append_child("command"), f.getCommand(), diag);
        break;
    case etiss::fault::Action::INJECTION:
        ok = ok & write_attr<std::string>(node, "type", "INJECTION", diag);
        ok = ok & write<Fault>(node.append_child("fault"), f.getFault(), diag);
        break;
    case etiss::fault::Action::MASK:
        ok = ok & write_attr<std::string>(node, "type", "MASK", diag);
        ok = ok & write(node.append_child("injector"), f.getInjectorAddress(), diag);
        ok = ok & write<std::string>(node.append_child("field"), f.getTargetField(), diag);
        ok = ok & write<std::string>(node.append_child("op"), etiss::fault::maskop_tostring(f.getMaskOp()), diag);
        ok = ok & write<uint64_t>(node.append_child("value"), f.getMaskValue(), diag);
        break;
    }
    return false;
}

} // namespace xml
#endif

} // namespace fault

} // namespace etiss
