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
    std::stringstream ss;
    ss << std::hex << ret;
    ss >> val;
    dst = val;
    return true;
}
template <>
bool write<uint64_t>(pugi::xml_node node, const uint64_t &src, Diagnostics &diag)
{
    std::stringstream ss;
    ss << src;
    return write<std::string>(node, ss.str(), diag);
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
    std::stringstream ss;
    ss << src;
    return write<std::string>(node, ss.str(), diag);
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

} // namespace fault

} // namespace etiss
