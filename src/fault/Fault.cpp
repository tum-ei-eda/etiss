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
#include "etiss/fault/Fault.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/Action.h"
#include "etiss/fault/Injector.h"
#include "etiss/fault/InjectorAddress.h"
#include "etiss/fault/Stressor.h"
#include "pugixml.hpp"
#else
#include "fault/Fault.h"
#include "fault/Trigger.h"
#include "fault/Action.h"
#include "fault/Injector.h"
#include "fault/InjectorAddress.h"
#include "fault/Stressor.h"
#include "pugixml.hpp"
#endif

#if MUTEX_SUPPORTED
#include <mutex>
#endif

#if CXX0X_UP_SUPPORTED == 0
#define static_assert(x, y)
#endif

namespace etiss
{
namespace fault
{

// Helper for XML parsing and generating
namespace xml
{

/**
    Parser/writer structure:

    class and field structure is closely modeled by the xml structure. each class is a node and each field is either a
sub node or an attribute. This allows for a simple parsing concept. the template function parse() is implemented for
each type that needs to be read and is called recursively for fields of different types. parsed values are written
directly into the fields. This requires all fields to be public/accessible e.g. \code C++:

        class Fault {
            class Trigger {
                [...]
            };
            std::vector<Trigger> triggers;
            const char * name;
        };

    XML:

        <fault name="...">
            <triggers>
                <trigger>
                    [...]
                </trigger>
            </triggers>
        </fault>

    example parser recursion:

        parse<Fault>(...)
            parse<std::vector<Trigger> >(...)
                parse<Trigger>(...)
                    [...]
            getAttribute("name",...)

\endcode

*/

static bool getAttribute(const pugi::xml_node &node, const std::string &attr_name, std::string &dst, Diagnostics &diag)
{
    bool first = true;
    for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute())
    {
        if (hasName(attr, attr_name))
        {
            if (first)
            {
                dst = attr.value();
                first = false;
            }
            else
            {
                diag.unexpectedNode(node, std::string("Duplicated attribute: ") + attr_name);
            }
        }
    }
    return !first;
}
static bool setAttribute(pugi::xml_node &node, const std::string &attr_name, const std::string &src, Diagnostics &diag)
{
    node.append_attribute(attr_name.c_str()).set_value(src.c_str());
    return true;
}
static bool getAttribute(const pugi::xml_node &node, const std::string &attr_name, int32_t &dst, Diagnostics &diag)
{
    std::string val;
    if (!getAttribute(node, attr_name, val, diag))
        return false;
    std::stringstream(val) >> dst; /// TODO propper conversion
    return true;
}
static bool setAttribute(pugi::xml_node &node, const std::string &attr_name, const int32_t &src, Diagnostics &diag)
{
    static_assert(sizeof(int32_t) <= sizeof(long long),
                  "pugixml cannot handle int32_t natively. custom string conversion required");
    node.append_attribute(attr_name.c_str()).set_value((long long)src);
    return true;
}

template <>
bool parse<std::vector<etiss::fault::Fault>>(pugi::xml_node node, std::vector<etiss::fault::Fault> &dst,
                                             Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::parse<std::vector<etiss::fault::Fault") +
                                   std::string("> >(node, vector<Fault>, Diagnostics) called. "));

    bool ret = true;
    for (pugi::xml_node cnode = node.first_child(); cnode; cnode = cnode.next_sibling())
    {
        if (hasName(cnode, "fault"))
        { // handle fault node
            Fault f;
            if (parse<etiss::fault::Fault>(cnode, f, diag))
            {
                dst.push_back(f);
            }
            else
            {
                ret = false;
            }
        }
        else
        {
            diag.ignoredNode(cnode, "non \"fault\" node in fault list.");
        }
    }
    return ret;
}

template <>
bool write<std::vector<etiss::fault::Fault>>(pugi::xml_node node, const std::vector<etiss::fault::Fault> &src,
                                             Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::write<std::vector<etiss::fault::Fault") +
                                   std::string("> >(node, vector<Fault>, Diagnostics) called. "));

    bool ret = true;
    for (size_t i = 0; i < src.size(); ++i)
    {
        ret = ret && write(node.append_child("fault"), src[i], diag);
    }
    return ret;
}

template <>
bool parse<std::vector<etiss::fault::FaultRef>>(pugi::xml_node node, std::vector<etiss::fault::FaultRef> &dst,
                                                Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::parse<std::vector<etiss::fault::FaultRef") +
                                   std::string("> >(node, vector<FaultRef>, Diagnostics) called. "));

    bool ret = true;
    for (pugi::xml_node cnode = node.first_child(); cnode; cnode = cnode.next_sibling())
    {
        if (hasName(cnode, "fault_ref"))
        { // handle fault node
            FaultRef f;
            if (parse<etiss::fault::FaultRef>(cnode, f, diag))
            {
                dst.push_back(f);
            }
            else
            {
                ret = false;
            }
        }
        else
        {
            diag.ignoredNode(cnode, "non \"fault_ref\" node in list.");
        }
    }
    return ret;
}

template <>
bool write<std::vector<etiss::fault::FaultRef>>(pugi::xml_node node, const std::vector<etiss::fault::FaultRef> &src,
                                                Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::write<std::vector<etiss::fault::FaultRef") +
                                   std::string("> >(node, vector<FaultRef>, Diagnostics) called. "));

    bool ret = true;
    for (size_t i = 0; i < src.size(); ++i)
    {
        ret = ret && write(node.append_child("fault_ref"), src[i], diag);
    }
    return ret;
}

} // namespace xml

// generates a unique ID for a new Fault
static int32_t uniqueFaultId()
{
#if MUTEX_SUPPORTED
    static std::mutex mu;
    std::lock_guard<std::mutex> lock(mu);
#endif
    static int32_t cid = -1;
    return cid--;
}

Fault::Fault() : id_(uniqueFaultId())
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Fault::Fault() called. "));
}

Fault::Fault(int nullid) : id_(nullid) {}

std::string Fault::toString() const
{

    pugi::xml_document doc;
    doc.load_string("<?xml version=\"1.0\"?>");

    etiss::fault::xml::Diagnostics diag;

    etiss::fault::xml::write<etiss::fault::Fault>(doc.append_child("fault"), *this, diag);

    std::stringstream ss;

    doc.save(ss);

    return ss.str();
}

void Fault::resolveTime(uint64_t time)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Fault::resolveTime(time=") + std::to_string(time) +
                                   std::string(") called. "));
    for (std::vector<Trigger>::iterator iter = triggers.begin(); iter != triggers.end(); ++iter)
    {
        iter->resolveTime(time);
    }
}
bool Fault::isResoved() const
{
    for (std::vector<Trigger>::const_iterator iter = triggers.begin(); iter != triggers.end(); ++iter)
    {
        if (!iter->isResolved())
            return false;
    }
    return true;
}

std::string FaultRef::toString() const
{

    pugi::xml_document doc;
    doc.load_string("<?xml version=\"1.0\"?>");

    etiss::fault::xml::Diagnostics diag;

    etiss::fault::xml::write<etiss::fault::FaultRef>(doc.append_child("fault_ref"), *this, diag);

    std::stringstream ss;

    doc.save(ss);

    return ss.str();
}

bool FaultRef::set_fault_reference(const std::string &identifier)
{
    name_ = identifier;

    return (resolve_reference());
}

bool FaultRef::resolve_reference() const
{
    for (auto const &it : Stressor::faults())
    {
        if (it.second.name_ == name_)
        {
            fault_ = it.second;
            return true;
        }
    }

    return false;
}

#if ETISS_FAULT_XML

bool parseXML(std::vector<Fault> &vec, const pugi::xml_document &doc, xml::Diagnostics &diag)
{
    bool ret = parse(findSingleNode(doc.document_element(), "definitions", diag), vec, diag); // parse document

    return ret;
}

bool parseXML(std::vector<FaultRef> &vec, const pugi::xml_document &doc, xml::Diagnostics &diag)
{
    bool ret = parse(findSingleNode(doc.document_element(), "initial", diag), vec, diag); // parse document

    return ret;
}

bool writeXML(const std::vector<Fault> &vec, std::ostream &out, std::ostream &diagnostics_out)
{
    pugi::xml_document doc;

    doc.load_string("<?xml version=\"1.0\"?>");

    etiss::fault::xml::Diagnostics diag;

    bool ret = write(doc.append_child("faults"), vec, diag); // write document

    doc.save(out);

    diag.print(diagnostics_out);

    return ret;
}

namespace xml
{

template <>
bool parse<etiss::fault::Fault>(pugi::xml_node node, etiss::fault::Fault &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::parse<etiss::fault::Fault>") +
                                   std::string("(node, Fault, Diagnostics) called. "));
    bool ret = true;
    ret = ret && getAttribute(node, "name", f.name_, diag); // non-optional
    /*ret = ret &*/ getAttribute(node, "id_", f.id_, diag); // optional
    for (pugi::xml_node cnode = node.first_child(); cnode; cnode = cnode.next_sibling())
    {
        if (hasName(cnode, "triggers"))
        {
            for (pugi::xml_node ccnode = cnode.first_child(); ccnode; ccnode = ccnode.next_sibling())
            {
                if (hasName(ccnode, "trigger"))
                {
                    etiss::fault::Trigger t;
                    if (parse<etiss::fault::Trigger>(ccnode, t, diag))
                    {
                        f.triggers.push_back(t);
                    }
                    else
                    {
                        ret = false;
                    }
                }
                else
                {
                    diag.ignoredNode(ccnode, "\"trigger\" node expected");
                }
            }
        }
        else if (hasName(cnode, "actions"))
        {
            for (pugi::xml_node ccnode = cnode.first_child(); ccnode; ccnode = ccnode.next_sibling())
            {
                if (hasName(ccnode, "action"))
                {
                    etiss::fault::Action t;
                    if (parse<etiss::fault::Action>(ccnode, t, diag))
                    {
                        f.actions.push_back(t);
                    }
                    else
                    {
                        ret = false;
                    }
                }
                else
                {
                    diag.ignoredNode(ccnode, "\"trigger\" node expected");
                }
            }
        }
        else
        {
            diag.ignoredNode(cnode, "unknown node");
        }
    }

    return ret;
}
template <>
bool write<etiss::fault::Fault>(pugi::xml_node node, const etiss::fault::Fault &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::write<etiss::fault::Fault>") +
                                   std::string("(node, Fault, Diagnostics) called. "));
    bool ok = true;
    ok = ok && setAttribute(node, "name", f.name_, diag);
    ok = ok && setAttribute(node, "id", f.id_, diag);
    pugi::xml_node triggers = node.append_child("triggers");
    for (std::vector<etiss::fault::Trigger>::const_iterator iter = f.triggers.begin(); iter != f.triggers.end(); ++iter)
    {
        ok = ok && write<etiss::fault::Trigger>(triggers.append_child("trigger"), *iter, diag);
    }
    pugi::xml_node actions = node.append_child("actions");
    for (std::vector<etiss::fault::Action>::const_iterator iter = f.actions.begin(); iter != f.actions.end(); ++iter)
    {
        ok = ok && write<etiss::fault::Action>(actions.append_child("action"), *iter, diag);
    }
    return ok;
}

template <>
bool parse<etiss::fault::FaultRef>(pugi::xml_node node, etiss::fault::FaultRef &fref, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::parse<etiss::fault::Fault>") +
                                   std::string("(node, Fault, Diagnostics) called. "));
    bool ret = true;
    std::string name;
    ret = ret && getAttribute(node, "name", name, diag); // non-optional
    // try to resolve reference, could (and is allowed to) fail in case of injected/ejected fault_ref
    fref.set_fault_reference(name);
    return ret;
}

template <>
bool write<etiss::fault::FaultRef>(pugi::xml_node node, const etiss::fault::FaultRef &fref, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::xml::write<etiss::fault::Fault>") +
                                   std::string("(node, Fault, Diagnostics) called. "));
    bool ok = true;
    ok = ok && setAttribute(node, "name", fref.get_name(), diag);
    return ok;
}

} // namespace xml

#endif

} // namespace fault
} // namespace etiss
