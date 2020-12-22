/*

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

void Action::ensure(Type t)
{
    if (type_ != t)
        throw "wrong action type";
}

Action::Action() : type_(NOP)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action() called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &command) : type_(COMMAND), inj_(inj), command_(command)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", command=") + command + std::string(") called. "));
}

Action::Action(const InjectorAddress &inj, const std::string &field, unsigned bit)
    : type_(BITFLIP), inj_(inj), field_(field), bit_(bit)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Action::Action(InjectorAddress &=") + inj.getInjectorPath() +
                                   std::string(", field=") + field + std::string(", bit=") + std::to_string(bit) +
                                   std::string(") called. "));
}

Action::Action(const Fault &fault) : type_(INJECTION)
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
    return inj_;
}

/// COMMAND only
const std::string &Action::getCommand() const
{
    return command_;
}

/// BITFLIP only
const std::string &Action::getTargetField() const
{
    return field_;
}

/// BITFLIP only
unsigned Action::getTargetBit() const
{
    return bit_;
}

const Fault &Action::getFault() const
{
    if (type_ != INJECTION)
        throw "Action doesn't have the type INJECTION: cannot call getFault()";
    return fault_.front();
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
            diag.unexpectedNode(node, "Failed to parse target injector");
            return false;
        }
        std::string field;
        if (!parse<std::string>(findSingleNode(node, "field", diag), field, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target field");
            return false;
        }
        setCoreName(field);
        unsigned bit;
        if (!parse<unsigned>(findSingleNode(node, "bit", diag), bit, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target bit");
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
            diag.unexpectedNode(node, "Failed to parse target injector");
            return false;
        }
        std::string command;
        if (!parse<std::string>(findSingleNode(node, "command", diag), command, diag))
        {
            diag.unexpectedNode(node, "Failed to parse target command");
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
            diag.unexpectedNode(node, "Failed to parse fault to inject");
            return false;
        }
        f = Action(inj);
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
    }
    return false;
}

} // namespace xml
#endif

} // namespace fault

} // namespace etiss
