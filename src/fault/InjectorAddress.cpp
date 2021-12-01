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
#include "etiss/fault/InjectorAddress.h"
#include "etiss/fault/Injector.h"
#include "etiss/fault/Trigger.h"
#include "etiss/fault/Action.h"
#else
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
