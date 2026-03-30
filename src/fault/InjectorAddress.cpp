// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef NO_ETISS
#include "etiss/fault/XML.h"
#include "etiss/fault/InjectorAddress.h"
#include "etiss/fault/Injector.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/Action.h"
#else
#include "fault/XML.h"
#include "fault/InjectorAddress.h"
#include "fault/Injector.h"
#include "fault/Trigger.h"
#include "fault/Action.h"
#endif

namespace etiss
{
namespace fault
{

InjectorAddress::InjectorAddress()
{
    etiss::log(etiss::VERBOSE, "Called etiss::fault::InjectorAddress::InjectorAddress()");
    path_ = ":";
    iptr_ = 0;
}
InjectorAddress::InjectorAddress(const std::string &address)
{
    etiss::log(etiss::VERBOSE, "Called etiss::fault::InjectorAddress::InjectorAddress(address=" + address + ")");
    path_ = address;
    iptr_ = 0;
}
InjectorAddress::InjectorAddress(const InjectorAddress &cpy)
{
    etiss::log(etiss::VERBOSE,
               "Called etiss::fault::InjectorAddress::InjectorAddress(InjectorAddress=" + cpy.toString() + ")");
    *this = cpy;
}
InjectorAddress &InjectorAddress::operator=(const InjectorAddress &cpy)
{
    etiss::log(etiss::VERBOSE,
               "Called etiss::fault::InjectorAddress::operator=(InjectorAddress=" + cpy.toString() + ")");
    path_ = cpy.path_;
    iptr_ = cpy.iptr_;
    return *this;
}

#if CXX0X_UP_SUPPORTED

InjectorAddress::InjectorAddress(InjectorAddress &&ia)
{
    etiss::log(etiss::VERBOSE, "Called etiss::fault::InjectorAddress::InjectorAddress(InjectorAddress && ia)");
    operator=(ia);
}
InjectorAddress &InjectorAddress::operator=(InjectorAddress &&ia)
{
    etiss::log(etiss::VERBOSE, "Called etiss::fault::InjectorAddress::operator=(InjectorAddress && ia)");
    operator=((const InjectorAddress &)ia);
    return *this;
}

#endif

const std::string &InjectorAddress::getInjectorPath() const
{
    return path_;
}
const Injector_ptr &InjectorAddress::getInjector() const
{

    if (!iptr_)
    {
        iptr_ = Injector::get(path_);
        if (!iptr_)
        {
#ifdef NO_ETISS
            std::cout << "etiss::fault::InjectorAddress::getInjector(): Injector not found for path_=" << path_
                      << std::endl;
#else
            etiss::log(etiss::ERROR, std::string("etiss::fault::InjectorAddress::getInjector():") +
                                         std::string(" Injector not found for path_= ") + path_);
#endif
        }
    }
    return iptr_;
}

bool InjectorAddress::isResolved() const
{
    return (bool)iptr_;
}

#if ETISS_FAULT_XML
namespace xml
{

template <>
bool parse<etiss::fault::InjectorAddress>(pugi::xml_node node, etiss::fault::InjectorAddress &dst, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::parse<etiss::fault::") +
                                   "InjectorAddress>(node, InjectorAddress&=" + dst.toString() + ", Diagnostics&)");
    std::string val;
    if (!parse<std::string>(node, val, diag))
    {
        return false;
    }
    setCoreName(val);
    dst = InjectorAddress(val);
    return true;
}
template <>
bool write<etiss::fault::InjectorAddress>(pugi::xml_node node, const etiss::fault::InjectorAddress &src,
                                          Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::write<etiss::fault::") +
                                   "InjectorAddress>(node, InjectorAddress&=" + src.toString() + ", Diagnostics&)");
    return write<std::string>(node, src.getInjectorPath(), diag);
}

template <>
bool parse<etiss::fault::InjectorAddress *>(pugi::xml_node node, etiss::fault::InjectorAddress *&dst, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::parse<etiss::fault::") +
                                   "InjectorAddress*>(node, InjectorAddress*&=" + dst->toString() + ", Diagnostics&)");
    InjectorAddress val;
    if (!parse<etiss::fault::InjectorAddress>(node, val, diag))
    {
        dst = 0;
        return false;
    }
    dst = new InjectorAddress(val);
    return true;
}
template <>
bool write<const etiss::fault::InjectorAddress *>(pugi::xml_node node, const etiss::fault::InjectorAddress *const &src,
                                                  Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::write<etiss::fault::") +
                                   "InjectorAddress*>(node, InjectorAddress*&=" + src->toString() + ", Diagnostics&)");
    if (!src)
        return false;
    return write(node, *src, diag);
}

} // namespace xml
#endif

} // namespace fault

} // namespace etiss
