// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef NO_ETISS
#include "etiss/fault/XML.h"
#else
#include "fault/XML.h"
#endif

#include <sstream>

namespace etiss
{

namespace fault
{

// some helper for changing Core Names
int coreIDActuallXML;
void setCoreName(std::string &str)
{
    size_t pos = 0;
    std::string token = "%i%";
    std::string replace = std::to_string(coreIDActuallXML);
    while ((pos = str.find(token, pos)) != std::string::npos)
    {
        str.replace(pos, token.length(), replace);
        pos += replace.length();
    }
}

#if ETISS_FAULT_XML
namespace xml
{

void Diagnostics::ignoredNode(const pugi::xml_node &node, const std::string &msg)
{
    warnings.push_back(std::string("XML Warning: ") + msg + " [" + node.path() + "]");
}
void Diagnostics::unexpectedNode(const pugi::xml_node &node, const std::string &msg)
{
    errors.push_back(std::string("XML Error: ") + msg + " [" + node.path() + "]");
}
void Diagnostics::print(std::ostream &out) const
{
    for (std::list<std::string>::const_iterator iter = warnings.begin(); iter != warnings.end(); ++iter)
    {
        out << *iter << std::endl;
    }
    for (std::list<std::string>::const_iterator iter = errors.begin(); iter != errors.end(); ++iter)
    {
        out << *iter << std::endl;
    }
}

template <>
bool parse<std::string>(pugi::xml_node node, std::string &dst, Diagnostics &diag)
{
    if (node.type() == pugi::node_null)
    {
        diag.unexpectedNode(node, "cannot get string from null node");
        return false;
    }
    pugi::xml_node tnode = node.first_child();
    if (tnode.type() != pugi::node_pcdata)
    {
        diag.unexpectedNode(tnode, "cannot get string from non pcdata node");
        return false;
    }
    if (tnode.next_sibling().type() != pugi::node_null)
    {
        diag.unexpectedNode(node, "node conatains more than just one text node");
        return false;
    }
    dst = tnode.value();
    return true;
}
template <>
bool write<std::string>(pugi::xml_node node, const std::string &src, Diagnostics &diag)
{
    node.append_child(pugi::node_pcdata).set_value(src.c_str());
    return true;
}

template <>
bool parse<uint64_t>(pugi::xml_node node, uint64_t &dst, Diagnostics &diag)
{
    std::string ret;
    if (!parse<std::string>(node, ret, diag))
    {
        return false;
    }
    return fromString(ret, dst);
}

bool parse_hex(pugi::xml_node node, uint64_t &dst, Diagnostics &diag)
{
    std::string ret;
    if (!parse<std::string>(node, ret, diag))
    {
        return false;
    }
    uint64_t val;
    val = std::stoll(ret, nullptr, 16);
    dst = val;
    return true;
}
template <>
bool write<uint64_t>(pugi::xml_node node, const uint64_t &src, Diagnostics &diag)
{
    return write<std::string>(node, std::to_string(src), diag);
}

template <>
bool parse<unsigned>(pugi::xml_node node, unsigned &dst, Diagnostics &diag)
{
    std::string ret;
    if (!parse<std::string>(node, ret, diag))
    {
        return false;
    }
    return fromString(ret, dst);
}
template <>
bool write<unsigned>(pugi::xml_node node, const unsigned &src, Diagnostics &diag)
{
    return write<std::string>(node, std::to_string(src), diag);
}

template <>
bool parse_attr<std::string>(pugi::xml_node node, const std::string &attr_name, std::string &dst, Diagnostics &diag)
{
    unsigned count = 0;
    for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute())
    {
        if (hasName(attr, attr_name))
        {
            if (count == 0)
            {
                dst = attr.value();
            }
            else
            {
                diag.unexpectedNode(node, std::string("Duplicated attribute: ") + attr_name);
            }
            count++;
        }
    }
    return count == 1;
}

template <>
bool write_attr<std::string>(pugi::xml_node node, const std::string &attr_name, const std::string &src,
                             Diagnostics &diag)
{
    for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute())
    {
        if (hasName(attr, attr_name))
        {
            attr.set_value(src.c_str());
            return true;
        }
    }
    node.append_attribute(attr_name.c_str()).set_value(src.c_str());
    return true;
}

template <>
bool fromString<uint64_t>(const std::string &s, uint64_t &val)
{
#if CXX0X_UP_SUPPORTED
    static_assert(sizeof(uint64_t) <= sizeof(unsigned long long), "cannot convert string to uint64_t with stoull");
    try
    {
        val = std::stoull(s);
        return true;
    }
    catch (...)
    {
        return false;
    }
#else
    unsigned long long tmp;
    if (!sscanf(s.c_str(), "%llu", &tmp))
        return false;
    val = (uint64_t)tmp;
    return true;
#endif
}
template <>
bool fromString<unsigned>(const std::string &s, unsigned &val)
{
#if CXX0X_UP_SUPPORTED
    try
    {
        val = (unsigned)std::stoull(s);
        return true;
    }
    catch (...)
    {
        return false;
    }
#else
    if (!sscanf(s.c_str(), "%iu", &val))
        return false;
    return true;
#endif
}

bool hasName(const pugi::xml_node &node, const std::string &name)
{
    const char *cname = node.name();
    if (cname == 0)
        return false;
    return name == cname;
}
bool hasName(const pugi::xml_attribute &attr, const std::string &name)
{
    const char *cname = attr.name();
    if (cname == 0)
        return false;
    return name == cname;
}

pugi::xml_node findSingleNode(pugi::xml_node node, const std::string &name, Diagnostics &diag)
{
    pugi::xml_node ret;
    bool retset = false;
    for (pugi::xml_node cnode = node.first_child(); cnode; cnode = cnode.next_sibling())
    {
        if (hasName(cnode, name))
        {
            if (retset)
            {
                ret = pugi::xml_node();
                diag.unexpectedNode(cnode, "only one node with this name may exist");
            }
            else
            {
                retset = true;
                ret = cnode;
            }
        }
    }
    return ret;
}

} // namespace xml
#endif

bool parseXML(pugi::xml_document &doc, std::istream &input, std::ostream &diagnostics_out)
{
    pugi::xml_parse_result pr = doc.load(input); // load from stream

    if (!pr)
    { // load failure
        diagnostics_out << "failed to load xml from stream: " << pr.description() << std::endl;
        return false;
    }

    return true;
}

} // namespace fault

} // namespace etiss
