// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef NO_ETISS
#include "etiss/fault/XML.h"
#include "etiss/fault/Action.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/Fault.h"
#include "etiss/fault/InjectorAddress.h"
#include "etiss/jit/ReturnCode.h"
#else
#include "fault/XML.h"
#include "fault/Action.h"
#include "fault/Trigger.h"
#include "fault/Fault.h"
#include "fault/InjectorAddress.h"
#endif

#include <sstream>

namespace etiss
{
namespace fault
{

void Action::ensure(type_t t)
{
    if (type_ != t)
        throw "wrong action type";
}

bool Action::is_action_on_field(void) const
{
    return ((type_ == +type_t::BITFLIP || type_ == +type_t::MASK) ? true : false);
}

Action::Action() : type_(type_t::NOP)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action() called. "));
}

#ifndef NO_ETISS
Action::Action(int32_t event) : type_(type_t::EVENT), event_(event)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(int32_t exception) called. "));
}
#endif

Action::Action(const InjectorAddress &inj, const std::string &command)
    : type_(type_t::COMMAND), inj_(std::make_unique<InjectorAddress>(inj)), command_(command)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", command=") + command + std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, unsigned bit)
    : type_(type_t::BITFLIP), inj_(std::make_unique<InjectorAddress>(inj)), field_(field), bit_(bit)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", bit=") + std::to_string(bit) +
                                   std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, mask_op_t mask_op, uint64_t mask_value)
    : type_(type_t::MASK)
    , inj_(std::make_unique<InjectorAddress>(inj))
    , field_(field)
    , mask_op_(mask_op)
    , mask_value_(mask_value)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", mask_op=") + mask_op_._to_string() +
                                   std::string(", mask_value=") + std::to_string(mask_value) +
                                   std::string(") called. "));
}

Action::Action(const FaultRef &fault_ref, type_t type) : type_(type), fault_ref_(std::make_unique<FaultRef>(fault_ref))
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(FaultRef &=") + fault_ref.toString() +
                                   std::string(") called. "));
}

Action::Action(const Action &cpy) : type_(cpy.getType())
{
    *this = cpy;
}

Action &Action::operator=(const Action &cpy)
{
    type_ = cpy.type_;
    switch (type_)
    {
    case type_t::BITFLIP:
        inj_ = std::make_unique<InjectorAddress>(cpy.getInjectorAddress());
        field_ = cpy.getTargetField();
        bit_ = cpy.getTargetBit();
        break;
    case type_t::MASK:
        inj_ = std::make_unique<InjectorAddress>(cpy.getInjectorAddress());
        field_ = cpy.getTargetField();
        mask_op_ = cpy.getMaskOp();
        mask_value_ = cpy.getMaskValue();
        break;
    case type_t::COMMAND:
        inj_ = std::make_unique<InjectorAddress>(cpy.getInjectorAddress());
        command_ = cpy.getCommand();
        break;
    case type_t::EJECTION:
        [[fallthrough]];
    case type_t::INJECTION:
        fault_ref_ = std::make_unique<FaultRef>(cpy.getFaultRef());
        break;
#ifndef NO_ETISS
    case type_t::EVENT:
        event_ = cpy.getEvent();
        break;
#endif
    case type_t::NOP:
        break;
    }
    return *this;
}

#if CXX0X_UP_SUPPORTED
Action::Action(Action &&cpy) : type_(cpy.getType())
{
    operator=(cpy);
}
Action &Action::operator=(Action &&cpy)
{
    operator=((const Action &)cpy);
    return *this;
}
#endif

const Action::type_t &Action::getType() const
{
    return type_;
}

const InjectorAddress &Action::getInjectorAddress() const
{
    if (!(type_ == +type_t::BITFLIP || type_ == +type_t::MASK || type_ == +type_t::COMMAND))
        etiss::log(
            etiss::FATALERROR,
            std::string(
                "etiss::fault::Action::TypeStruct::getInjectorAddress(): Requested Action::Type is not Injector"));
    return *inj_;
}

/// COMMAND only
const std::string &Action::getCommand() const
{
    if (type_ != +type_t::COMMAND)
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getCommand(): Requested Action::Type is not Command"));
    return command_;
}

/// is_action_on_field only
const std::string &Action::getTargetField() const
{
    if (!(type_ == +type_t::BITFLIP || type_ == +type_t::MASK))
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getTargetField(): Requested Action::Type is not TargetField"));
    return field_;
}

/// BITFLIP only
unsigned Action::getTargetBit() const
{
    if (type_ != +type_t::BITFLIP)
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getTargetBit(): Requested Action::Type is not TargetBit"));
    return bit_;
}

const FaultRef &Action::getFaultRef() const
{
    if (!((type_ == +type_t::INJECTION) || (type_ == +type_t::EJECTION)))
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getFault(): Requested Action::Type is not injectable Fault"));
    return *fault_ref_;
}

const Action::mask_op_t &Action::getMaskOp() const
{
    if (type_ != +type_t::MASK)
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getMaskOp(): Requested Action::Type is not Mask"));
    return mask_op_;
}

uint64_t Action::getMaskValue() const
{
    if (type_ != +type_t::MASK)
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getMaskValue(): Requested Action::Type is not Mask"));
    return mask_value_;
}

#ifndef NO_ETISS
int32_t Action::getEvent() const
{
    if (type_ != +type_t::EVENT)
        etiss::log(etiss::FATALERROR,
                   std::string("etiss::fault::Action::getEvent(): Requested Action::Type is not Event"));
    return event_;
}
#endif

std::string Action::toString() const
{
    pugi::xml_document doc;
    doc.load_string("<?xml version=\"1.0\"?>");

    xml::Diagnostics diag;

    xml::write<etiss::fault::Action>(doc.append_child("action"), *this, diag);

    std::stringstream ss;

    doc.save(ss);

    return ss.str();
}

#if ETISS_FAULT_XML
namespace xml
{
template <>
bool parse<Action>(pugi::xml_node node, Action &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::parse<etiss::fault::Action>(node, Action") +
                                   std::string(", Diagnostics) called. "));

    std::string type_s;
    if (!parse_attr(node, "type", type_s, diag))
    {
        diag.unexpectedNode(node, "Failed to parse type of action");
        return false;
    }
    if (!Action::type_t::_from_string_nothrow(type_s.c_str()))
    {
        diag.unexpectedNode(node, std::string("There is no Action type ") + type_s);
        return false;
    }
    auto type = Action::type_t::_from_string(type_s.c_str());

    switch (type)
    {
    case Action::type_t::NOP:
    {
        f = Action();
        return true;
        break;
    }
    case Action::type_t::BITFLIP:
    {
        InjectorAddress inj;
        if (!etiss::cfg().get<bool>("faultInjection::allowBitFlip", true))
            return true;
        if (!parse<InjectorAddress>(findSingleNode(node, "injector", diag), inj, diag))
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
        break;
    }
    case Action::type_t::COMMAND:
    {
        InjectorAddress inj;
        if (!parse<InjectorAddress>(findSingleNode(node, "injector", diag), inj, diag))
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
        break;
    }
    case Action::type_t::INJECTION:
        [[fallthrough]];
    case Action::type_t::EJECTION:
    {
        FaultRef fault_ref;
        if (!parse<FaultRef>(findSingleNode(node, "fault_ref", diag), fault_ref, diag))
        {
            diag.unexpectedNode(node, "Failed to parse <fault_ref> to inject");
            return false;
        }
        f = Action(fault_ref, type);
        return true;
        break;
    }
    case Action::type_t::MASK:
    {
        InjectorAddress inj;
        if (!parse<InjectorAddress>(findSingleNode(node, "injector", diag), inj, diag))
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
        if (!parse<std::string>(findSingleNode(node, "op", diag), op_str, diag))
        {
            diag.unexpectedNode(node, "Failed to parse mask operation <op>");
            return false;
        }

        if (!(etiss::fault::Action::mask_op_t::_from_string_nothrow(op_str.c_str())))
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
        f = Action(inj, field, Action::mask_op_t::_from_string(op_str.c_str()), value);
        return true;
        break;
    }
#ifndef NO_ETISS
    case Action::type_t::EVENT:
    {
        std::string event_str;
        int32_t event;
        if (!parse<std::string>(findSingleNode(node, "cause", diag), event_str, diag))
        {
            diag.unexpectedNode(node, "Failed to parse node of event type: <cause>");
            return false;
        }
        if (!etiss::fault::returncode_fromstring(event, event_str))
        {
            diag.unexpectedNode(node, "Failed to parse event <cause>. Supported values: {NOERROR, RELOADBLOCKS, "
                                      "RELOADCURRENTBLOCK, CPUFINISHED, EXCEPTION:[cause(hex)]}");
            return false;
        }
        f = Action(event);
        return true;
    }
#endif
    default:
        diag.unexpectedNode(node, std::string("Unknown type of action: ") + type._to_string());
        return false;
        break;
    }
    return false;
}
template <>
bool write<Action>(pugi::xml_node node, const Action &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::write<etiss::fault::Action>(node, Action&=") +
                                   std::string(", Diagnostics) called. "));
    bool ok = true;
    switch (f.getType())
    {
    case Action::type_t::NOP:
        return write_attr<std::string>(node, "type", "NOP", diag);
        break;
    case Action::type_t::BITFLIP:
        ok = ok & write_attr<std::string>(node, "type", "BITFLIP", diag);
        ok = ok & write(node.append_child("injector"), f.getInjectorAddress(), diag);
        ok = ok & write<std::string>(node.append_child("field"), f.getTargetField(), diag);
        ok = ok & write<unsigned>(node.append_child("bit"), f.getTargetBit(), diag);
        break;
    case Action::type_t::COMMAND:
        ok = ok & write_attr<std::string>(node, "type", "COMMAND", diag);
        ok = ok & write<std::string>(node.append_child("command"), f.getCommand(), diag);
        break;
    case Action::type_t::INJECTION:
        ok = ok & write_attr<std::string>(node, "type", "INJECTION", diag);
        ok = ok & write<FaultRef>(node.append_child("fault_ref"), f.getFaultRef(), diag);
        break;
    case Action::type_t::EJECTION:
        ok = ok & write_attr<std::string>(node, "type", "EJECTION", diag);
        ok = ok & write<FaultRef>(node.append_child("fault_ref"), f.getFaultRef(), diag);
        break;
    case Action::type_t::MASK:
        ok = ok & write_attr<std::string>(node, "type", "MASK", diag);
        ok = ok & write(node.append_child("injector"), f.getInjectorAddress(), diag);
        ok = ok & write<std::string>(node.append_child("field"), f.getTargetField(), diag);
        ok = ok & write<std::string>(node.append_child("op"), f.getMaskOp()._to_string(), diag);
        ok = ok & write<uint64_t>(node.append_child("value"), f.getMaskValue(), diag);
        break;
#ifndef NO_ETISS
    case Action::type_t::EVENT:
        ok = ok & write_attr<std::string>(node, "type", "EVENT", diag);
        ok = ok & write<std::string>(node.append_child("cause"), etiss::fault::returncode_tostring(f.getEvent()), diag);
        break;
#endif
    }
    if (!ok)
        etiss::log(etiss::ERROR, std::string("etiss::fault::write<etiss::fault::Action>(node, Action&=") +
                                     std::string(", Diagnostics) failed. "));
    return ok;
}

} // namespace xml
#endif

#ifndef NO_ETISS
bool returncode_fromstring(int32_t &out, const std::string &in)
{
    if ((in == "NOERROR") || (in == "RETURNCODE::NOERROR"))
    {
        out = etiss::RETURNCODE::NOERROR;
    }
    else if ((in == "RELOADBLOCKS") || (in == "RETURNCODE::RELOADBLOCKS"))
    {
        out = etiss::RETURNCODE::RELOADBLOCKS;
    }
    else if ((in == "RELOADCURRENTBLOCK") || (in == "RETURNCODE::RELOADCURRENTBLOCK"))
    {
        out = etiss::RETURNCODE::RELOADCURRENTBLOCK;
    }
    else if ((in == "CPUFINISHED") || (in == "RETURNCODE::CPUFINISHED"))
    {
        out = etiss::RETURNCODE::CPUFINISHED;
    }
    else if ((in == "DBUS_WRITE_ERROR") || (in == "RETURNCODE::DBUS_WRITE_ERROR"))
    {
        out = etiss::RETURNCODE::DBUS_WRITE_ERROR;
    }
    else if ((in == "IBUS_READ_ERROR") || (in == "RETURNCODE::IBUS_READ_ERROR"))
    {
        out = etiss::RETURNCODE::IBUS_READ_ERROR;
    }
    else if ((in == "IBUS_WRITE_ERROR") || (in == "RETURNCODE::IBUS_WRITE_ERROR"))
    {
        out = etiss::RETURNCODE::IBUS_WRITE_ERROR;
    }
    else if ((in == "INTERRUPT") || (in == "RETURNCODE::INTERRUPT"))
    {
        out = etiss::RETURNCODE::INTERRUPT;
    }
    else if ((in == "RESET") || (in == "RETURNCODE::RESET"))
    {
        out = etiss::RETURNCODE::RESET;
    }
    else if ((in == "ILLEGALINSTRUCTION") || (in == "RETURNCODE::ILLEGALINSTRUCTION"))
    {
        out = etiss::RETURNCODE::ILLEGALINSTRUCTION;
    }
    else if ((in == "ILLEGALJUMP") || (in == "RETURNCODE::ILLEGALJUMP"))
    {
        out = etiss::RETURNCODE::ILLEGALJUMP;
    }
    else if ((in == "INSTR_PAGEFAULT") || in == ("RETURNCODE::INSTR_PAGEFAULT"))
    {
        out = etiss::RETURNCODE::INSTR_PAGEFAULT;
    }
    else if ((in == "LOAD_PAGEFAULT") || (in == "RETURNCODE::LOAD_PAGEFAULT"))
    {
        out = etiss::RETURNCODE::LOAD_PAGEFAULT;
    }
    else if ((in == "STORE_PAGEFAULT") || (in == "RETURNCODE::STORE_PAGEFAULT"))
    {
        out = etiss::RETURNCODE::STORE_PAGEFAULT;
    }
    else if ((in == "SYSCALL") || (in == "RETURNCODE::SYSCALL"))
    {
        out = etiss::RETURNCODE::SYSCALL;
    }
    else if ((in == "PAGEFAULT") || (in == "RETURNCODE::PAGEFAULT"))
    {
        out = etiss::RETURNCODE::PAGEFAULT;
    }
    else if ((in == "BREAKPOINT") || (in == "RETURNCODE::BREAKPOINT"))
    {
        out = etiss::RETURNCODE::BREAKPOINT;
    }
    else
    {
        return false;
    }
    return true;
}

std::string returncode_tostring(int32_t in)
{
    switch (in)
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

} // namespace fault

} // namespace etiss
