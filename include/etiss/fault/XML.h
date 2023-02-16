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

        @brief contains XML related functions. pugixml is used as a backend for parsing.

        @detail \see parse() and \see write() and their specializations.

*/
#ifndef ETISS_FAULT_XML_H_
#define ETISS_FAULT_XML_H_

#include <list>
#include <string>
#include <vector>

#ifndef NO_ETISS
#include "etiss/fault/Defs.h"
#include "pugixml.hpp"
#else
#include "fault/Defs.h"
#include "pugixml.hpp"
#endif

#include <cstdio>

namespace etiss
{

namespace fault
{

// forwards
class Trigger;
class Fault;
class FaultRef;
class Action;
class InjectorAddress;

// some helper for changing Core Names
extern int coreIDActuallXML;
void setCoreName(std::string &str);

#if ETISS_FAULT_XML

/**
    Parser/writer structure:

    class and field structure is closely modeled by the xml structure. each class is a node and each field is either a
sub node or an attribute. This allows for a simple parsing concept. the template function parse() is implemented for
each type that needs to be read and is called recursively for fields of different types. e.g. <pre> C++: class Trigger {
            [...]
        };
        class Fault {
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
            parse_attr("name",...)

</pre>


*/
namespace xml
{

/**
    prints information about parsing problems
*/
class Diagnostics
{
  public:
    std::list<std::string> warnings;
    std::list<std::string> errors;
    void ignoredNode(const pugi::xml_node &node, const std::string &msg);
    void unexpectedNode(const pugi::xml_node &node, const std::string &msg);
    void print(std::ostream &out) const;
};

///////// basic parser templates /////////////////
#if CXX0X_UP_SUPPORTED
template <typename T>
bool parse(pugi::xml_node node, T &dst, Diagnostics &diag)
{
    static_assert((sizeof(T) == -1), "etiss::fault::xml::parse needs to be specialized.");
    return false;
}
template <typename T>
bool write(pugi::xml_node node, const T &src, Diagnostics &diag)
{
    static_assert((sizeof(T) == -1), "etiss::fault::xml::write needs to be specialized.");
    return false;
}
#else
template <typename T>
bool parse(pugi::xml_node node, T &dst, Diagnostics &diag);
template <typename T>
bool write(pugi::xml_node node, const T &src, Diagnostics &diag);
#endif

#if CXX0X_UP_SUPPORTED
template <typename T>
bool parse_attr(pugi::xml_node node, const std::string &attr_name, T &dst, Diagnostics &diag)
{
    static_assert((sizeof(T) == -1), "etiss::fault::xml::parse_attr needs to be specialized.");
    return false;
}
template <typename T>
bool write_attr(pugi::xml_node node, const std::string &attr_name, const T &src, Diagnostics &diag)
{
    static_assert((sizeof(T) == -1), "etiss::fault::xml::write_attr needs to be specialized.");
    return false;
}
#else
template <typename T>
bool parse_attr(pugi::xml_node node, const std::string &attr_name, T &dst, Diagnostics &diag);
template <typename T>
bool write_attr(pugi::xml_node node, const std::string &attr_name, const T &src, Diagnostics &diag);
#endif

///////////////////////////////////////////////

template <>
bool parse<std::string>(pugi::xml_node node, std::string &dst, Diagnostics &diag);
template <>
bool write<std::string>(pugi::xml_node node, const std::string &src, Diagnostics &diag);

template <>
bool parse<uint64_t>(pugi::xml_node node, uint64_t &dst, Diagnostics &diag);

bool parse_hex(pugi::xml_node node, uint64_t &dst, Diagnostics &diag);
template <>
bool write<uint64_t>(pugi::xml_node node, const uint64_t &src, Diagnostics &diag);

template <>
bool parse<unsigned>(pugi::xml_node node, unsigned &dst, Diagnostics &diag);
template <>
bool write<unsigned>(pugi::xml_node node, const unsigned &src, Diagnostics &diag);

template <>
bool parse_attr<std::string>(pugi::xml_node node, const std::string &attr_name, std::string &dst, Diagnostics &diag);
template <>
bool write_attr<std::string>(pugi::xml_node node, const std::string &attr_name, const std::string &src,
                             Diagnostics &diag);

///////////////////////////helper functions
template <typename T>
/// conversion of string to type t
bool fromString(const std::string &s, T &val);

template <>
bool fromString<uint64_t>(const std::string &s, uint64_t &val);
template <>
bool fromString<unsigned>(const std::string &s, unsigned &val);

bool hasName(const pugi::xml_node &node, const std::string &name);
bool hasName(const pugi::xml_attribute &attr, const std::string &name);

pugi::xml_node findSingleNode(pugi::xml_node node, const std::string &name, Diagnostics &diag);

////////////////////////////////////////////

// TRIGGER
template <>
bool parse<etiss::fault::Trigger *>(pugi::xml_node node, etiss::fault::Trigger *&f, Diagnostics &diag);
template <>
bool write<const etiss::fault::Trigger *>(pugi::xml_node node, const etiss::fault::Trigger *const &f,
                                          Diagnostics &diag);

template <>
bool parse<etiss::fault::Trigger>(pugi::xml_node node, etiss::fault::Trigger &f, Diagnostics &diag);
template <>
bool write<etiss::fault::Trigger>(pugi::xml_node node, const etiss::fault::Trigger &f, Diagnostics &diag);

// FAULT
template <>
bool parse<etiss::fault::Fault>(pugi::xml_node node, etiss::fault::Fault &f, Diagnostics &diag);
template <>
bool write<etiss::fault::Fault>(pugi::xml_node node, const etiss::fault::Fault &f, Diagnostics &diag);
template <>
bool parse<etiss::fault::FaultRef>(pugi::xml_node node, etiss::fault::FaultRef &fref, Diagnostics &diag);
template <>
bool write<etiss::fault::FaultRef>(pugi::xml_node node, const etiss::fault::FaultRef &fref, Diagnostics &diag);

// ACTION
template <>
bool parse<etiss::fault::Action>(pugi::xml_node node, etiss::fault::Action &f, Diagnostics &diag);
template <>
bool write<etiss::fault::Action>(pugi::xml_node node, const etiss::fault::Action &f, Diagnostics &diag);

// INJECTORADDRESS
template <>
bool parse<etiss::fault::InjectorAddress>(pugi::xml_node node, etiss::fault::InjectorAddress &dst, Diagnostics &diag);
template <>
bool write<etiss::fault::InjectorAddress>(pugi::xml_node node, const etiss::fault::InjectorAddress &src,
                                          Diagnostics &diag);

template <>
bool parse<etiss::fault::InjectorAddress *>(pugi::xml_node node, etiss::fault::InjectorAddress *&dst,
                                            Diagnostics &diag);
template <>
bool write<const etiss::fault::InjectorAddress *>(pugi::xml_node node, const etiss::fault::InjectorAddress *const &src,
                                                  Diagnostics &diag);

} // namespace xml
#endif

/** @brief parse a XML document held in \p input stream and return as \p doc
 */
bool parseXML(pugi::xml_document &doc, std::istream &input, std::ostream &diagnostics_out = std::cout);

bool parseXML(std::vector<Fault> &vec, const pugi::xml_document &doc, xml::Diagnostics &diag);
bool parseXML(std::vector<FaultRef> &vec, const pugi::xml_document &doc, xml::Diagnostics &diag);

bool writeXML(const std::vector<Fault> &vec, std::ostream &out, std::ostream &diagnostics_out = std::cout);

} // namespace fault

} // namespace etiss

#endif
