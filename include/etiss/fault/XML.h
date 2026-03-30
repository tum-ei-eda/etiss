// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
