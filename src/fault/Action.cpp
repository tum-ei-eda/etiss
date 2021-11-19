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
#include "etiss/jit/ReturnCode.h"
#else
#include "fault/Action.h"
#endif

#include <sstream>

namespace etiss
{
namespace fault
{

void Action::ensure(Type t)
{
    if (type_ != t)
        throw "wrong action type";
}

bool Action::is_action_on_field(void) const
{
    return ((type_ == Type::BITFLIP || type_ == Type::MASK) ? true : false);
}

Action::Action()
  : type_(Type::NOP)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action() called. "));
}

#ifndef NO_ETISS
Action::Action(etiss::int32 event)
  : type_(Type::EVENT)
  , event_(event)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(etiss::int32 exception) called. "));
}
#endif

Action::Action(const InjectorAddress &inj, const std::string &command)
  : type_(Type::COMMAND)
  , inj_(inj)
  , command_(command)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", command=") + command + std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, unsigned bit)
  : type_(Type::BITFLIP)
  , inj_(inj)
  , field_(field)
  , bit_(bit)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", bit=") + std::to_string(bit) +
                                   std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, MaskOp mask_op, uint64_t mask_value)
  : type_(Type::MASK)
  , inj_(inj)
  , field_(field)
  , mask_op_(mask_op)
  , mask_value_(mask_value)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", mask_op=") + std::string(mask_op_) +
                                   std::string(", mask_value=") + std::to_string(mask_value) +
                                   std::string(") called. "));
}

Action::Action(const Fault &fault)
  : type_(Type::INJECTION)
{
    etiss::log(etiss::VERBOSE,
               std::string("etiss::fault::Action::Action(Fault &=") + fault.toString() + std::string(") called. "));
    fault_.push_back(fault);
}

const Action::type_t& Action::getType() const
{
    return type_;
}

const InjectorAddress &Action::getInjectorAddress() const
{
    if(unlikely(!(type_ == Type::BITFLIP || type_ == Type::MASK || type_ == Type::COMMAND)))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::TypeStruct::getInjectorAddress(): Requested Action::Type is not Injector"));
    return inj_;
}

/// COMMAND only
const std::string &Action::getCommand() const
{
    if(unlikely(type_ != Type::COMMAND))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getCommand(): Requested Action::Type is not Command"));
    return command_;
}

/// is_action_on_field only
const std::string &Action::getTargetField() const
{
    if(unlikely(!(type_ == Type::BITFLIP || type_ == Type::MASK)))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getTargetField(): Requested Action::Type is not TargetField"));
    return field_;
}

/// BITFLIP only
unsigned Action::getTargetBit() const
{
    if(unlikely(type_ != Type::BITFLIP))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getTargetBit(): Requested Action::Type is not TargetBit"));
    return bit_;
}

const Fault &Action::getFault() const
{
    if(unlikely(type_ != Type::INJECTION))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getFault(): Requested Action::Type is not injectable Fault"));
    return fault_.front();
}

//Action::MaskOp Action::getMaskOp() const
const Action::mask_op_t& Action::getMaskOp() const
{
    if(unlikely(type_ != Type::MASK))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getMaskOp(): Requested Action::Type is not Mask"));
    return mask_op_;
}

//std::string Action::getMaskOpString() const
//{
//    if(unlikely(type_ != Type::MASK))
//        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getMaskOp(): Requested Action::Type is not Mask"));
//    return mask_op_;
//}

uint64_t Action::getMaskValue() const
{
    if(unlikely(type_ != Type::MASK))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getMaskValue(): Requested Action::Type is not Mask"));
    return mask_value_;
}

#ifndef NO_ETISS
etiss::int32 Action::getEvent() const
{
    if(unlikely(type_ != Type::EVENT))
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Action::getEvent(): Requested Action::Type is not Event"));
    return event_;
}
#endif

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
        if (! etiss::fault::Action::mask_op_t::fromString(op_str, op))
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
#ifndef NO_ETISS
    else if (type == "EVENT")
    {
        std::string event_str;
        etiss::int32 event;
        if (!parse<std::string>(findSingleNode(node, "cause", diag), event_str, diag))
        {
            diag.unexpectedNode(node, "Failed to parse node of event type: <cause>");
            return false;
        }
        if (! etiss::fault::returncode_fromstring(event, event_str))
        {
            diag.unexpectedNode(node, "Failed to parse event <cause>. Supported values: {NOERROR, RELOADBLOCKS, RELOADCURRENTBLOCK, CPUFINISHED, EXCEPTION:[cause(hex)]}");
            return false;
        }
        f = Action(event);
        return true;
    }
#endif
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
    case etiss::fault::Action::Type::NOP:
        return write_attr<std::string>(node, "type", "NOP", diag);
        break;
    case etiss::fault::Action::Type::BITFLIP:
        ok = ok & write_attr<std::string>(node, "type", "BITFLIP", diag);
        ok = ok & write(node.append_child("injector"), f.getInjectorAddress(), diag);
        ok = ok & write<std::string>(node.append_child("field"), f.getTargetField(), diag);
        ok = ok & write<unsigned>(node.append_child("bit"), f.getTargetBit(), diag);
        break;
    case etiss::fault::Action::Type::COMMAND:
        ok = ok & write_attr<std::string>(node, "type", "COMMAND", diag);
        ok = ok & write<std::string>(node.append_child("command"), f.getCommand(), diag);
        break;
    case etiss::fault::Action::Type::INJECTION:
        ok = ok & write_attr<std::string>(node, "type", "INJECTION", diag);
        ok = ok & write<Fault>(node.append_child("fault"), f.getFault(), diag);
        break;
    case etiss::fault::Action::Type::MASK:
        ok = ok & write_attr<std::string>(node, "type", "MASK", diag);
        ok = ok & write(node.append_child("injector"), f.getInjectorAddress(), diag);
        ok = ok & write<std::string>(node.append_child("field"), f.getTargetField(), diag);
        ok = ok & write<std::string>(node.append_child("op"), SmartType<Action::MaskOp>::toString(f.getMaskOp()), diag);
        ok = ok & write<uint64_t>(node.append_child("value"), f.getMaskValue(), diag);
        break;
#ifndef NO_ETISS
    case etiss::fault::Action::Type::EVENT:
        ok = ok & write_attr<std::string>(node, "type", "EVENT", diag);
        ok = ok & write<std::string>(node.append_child("cause"), etiss::fault::returncode_tostring(f.getEvent()), diag);
        break;
#endif
    }
    return false;
}

} // namespace xml
#endif

#ifndef NO_ETISS
bool returncode_fromstring(etiss::int32& out, const std::string& in)
{
    if ( (in == "NOERROR") || (in == "RETURNCODE::NOERROR") )
    {
        out = etiss::RETURNCODE::NOERROR;
    }
    else if ( (in == "RELOADBLOCKS") || (in == "RETURNCODE::RELOADBLOCKS") )
    {
        out =  etiss::RETURNCODE::RELOADBLOCKS;
    }
    else if ( (in == "RELOADCURRENTBLOCK") || (in == "RETURNCODE::RELOADCURRENTBLOCK") )
    {
        out =  etiss::RETURNCODE::RELOADCURRENTBLOCK;
    }
    else if ( (in == "CPUFINISHED") || (in == "RETURNCODE::CPUFINISHED") )
    {
        out =  etiss::RETURNCODE::CPUFINISHED;
    }
    else if ( (in == "DBUS_WRITE_ERROR") || (in == "RETURNCODE::DBUS_WRITE_ERROR") )
    {
        out = etiss::RETURNCODE::DBUS_WRITE_ERROR;
    }
    else if ( (in == "IBUS_READ_ERROR") || (in == "RETURNCODE::IBUS_READ_ERROR") )
    {
        out = etiss::RETURNCODE::IBUS_READ_ERROR;
    }
    else if ( (in == "IBUS_WRITE_ERROR") || (in == "RETURNCODE::IBUS_WRITE_ERROR") )
    {
        out = etiss::RETURNCODE::IBUS_WRITE_ERROR;
    }
    else if ( (in == "INTERRUPT") || (in == "RETURNCODE::INTERRUPT") )
    {
        out = etiss::RETURNCODE::INTERRUPT;
    }
    else if ( (in == "RESET") || (in == "RETURNCODE::RESET") )
    {
        out = etiss::RETURNCODE::RESET;
    }
    else if ( (in == "ILLEGALINSTRUCTION") || (in == "RETURNCODE::ILLEGALINSTRUCTION") )
    {
        out = etiss::RETURNCODE::ILLEGALINSTRUCTION;
    }
    else if ( (in == "ILLEGALJUMP") || (in == "RETURNCODE::ILLEGALJUMP") )
    {
        out = etiss::RETURNCODE::ILLEGALJUMP;
    }
    else if ( (in == "INSTR_PAGEFAULT") || in == ("RETURNCODE::INSTR_PAGEFAULT") )
    {
        out = etiss::RETURNCODE::INSTR_PAGEFAULT;
    }
    else if ( (in == "LOAD_PAGEFAULT") || (in == "RETURNCODE::LOAD_PAGEFAULT") )
    {
        out = etiss::RETURNCODE::LOAD_PAGEFAULT;
    }
    else if ( (in == "STORE_PAGEFAULT") || (in == "RETURNCODE::STORE_PAGEFAULT") )
    {
        out = etiss::RETURNCODE::STORE_PAGEFAULT;
    }
    else if ( (in == "SYSCALL") || (in == "RETURNCODE::SYSCALL") )
    {
        out = etiss::RETURNCODE::SYSCALL;
    }
    else if ( (in == "PAGEFAULT") || (in == "RETURNCODE::PAGEFAULT") )
    {
        out = etiss::RETURNCODE::PAGEFAULT;
    }
    else if ( (in == "BREAKPOINT") || (in == "RETURNCODE::BREAKPOINT") )
    {
        out = etiss::RETURNCODE::BREAKPOINT;
    }
    else
    {
        return false;
    }
    return true;
}

std::string returncode_tostring(etiss::int32 in)
{
    switch(in)
    {
      case etiss::RETURNCODE::NOERROR:
        return "NOERROR";
      case etiss::RETURNCODE::RELOADBLOCKS:
        return "RELOADBLOCKS";
      case etiss::RETURNCODE::RELOADCURRENTBLOCK:
        return "RELOADCURRENTBLOCK";
      case etiss::RETURNCODE::INTERRUPT:
        return "INTERRUPT";
      case etiss::RETURNCODE::DBUS_WRITE_ERROR:
        return "DBUS_WRITE_ERROR";
      case etiss::RETURNCODE::IBUS_READ_ERROR:
        return "IBUS_READ_ERROR";
      case etiss::RETURNCODE::IBUS_WRITE_ERROR:
        return "IBUS_WRITE_ERROR";
      case etiss::RETURNCODE::RESET:
        return "RESET";
      case etiss::RETURNCODE::ILLEGALINSTRUCTION:
        return "ILLEGALINSTRUCTION";
      case etiss::RETURNCODE::ILLEGALJUMP:
        return "ILLEGALJUMP";
      case etiss::RETURNCODE::INSTR_PAGEFAULT:
        return "INSTR_PAGEFAULT";
      case etiss::RETURNCODE::LOAD_PAGEFAULT:
        return "LOAD_PAGEFAULT";
      case etiss::RETURNCODE::STORE_PAGEFAULT:
        return "STORE_PAGEFAULT";
      case etiss::RETURNCODE::SYSCALL:
        return "SYSCALL";
      case etiss::RETURNCODE::PAGEFAULT:
        return "PAGEFAULT";
      case etiss::RETURNCODE::BREAKPOINT:
        return "BREAKPOINT";
      case etiss::RETURNCODE::CPUFINISHED:
        return "CPUFINISHED";
      default:
        std::stringstream ss;
        ss << "EXCEPTION:" << std::hex << in;
        return ss.str();
    }
}

#endif

template<>
Action::type_t::map_t Action::type_t::TABLE = {
      {Action::Type::NOP, "NOP"}
    , {Action::Type::BITFLIP, "BITFLIP"}
    , {Action::Type::MASK, "MASK"}
    , {Action::Type::COMMAND, "COMMAND"}
    , {Action::Type::INJECTION, "INJECTION"}
#ifndef NO_ETISS
    , {Action::Type::EVENT, "EVENT"}
#endif
};

template<>
Action::mask_op_t::map_t Action::mask_op_t::TABLE = {
      {Action::MaskOp::AND, "AND"}
    , {Action::MaskOp::OR, "OR"}
    , {Action::MaskOp::XOR, "XOR"}
    , {Action::MaskOp::NAND, "NAND"}
    , {Action::MaskOp::NOR, "NOR"}
    , {Action::MaskOp::NOP, "NOP"}
};

} // namespace fault

} // namespace etiss
