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

        @brief contains a simple class that represents and resolves injector addresses as used
            by triggers (\see etiss::fault::Trigger) and actions (\see etiss::fault::Action)

        @detail

*/
#ifndef ETISS_FAULT_INJECTORADDRESS_H_
#define ETISS_FAULT_INJECTORADDRESS_H_

#include <iostream>
#include <stdint.h>
#include <string>

#ifndef NO_ETISS
#include "etiss/Misc.h"
#include "etiss/fault/Defs.h"
#else
#include "fault/Defs.h"
#endif

namespace etiss
{
namespace fault
{
class InjectorAddress : public etiss::ToString
{
  private:
    std::string path_;          ///< Contains the VirtualStruct as string where the Injector refers to.
    mutable Injector_ptr iptr_; ///< Contains the pointer to the Injector
  public:                       // ctors
    InjectorAddress();
    InjectorAddress(const std::string &address);
    InjectorAddress(const InjectorAddress &);
    InjectorAddress &operator=(const InjectorAddress &);
#if CXX0X_UP_SUPPORTED
    InjectorAddress(InjectorAddress &&);
    InjectorAddress &operator=(InjectorAddress &&);
#endif

  public:
    const std::string &getInjectorPath() const;
    const Injector_ptr &getInjector() const; ///> Calls Injector::get (implemented in VirtualStruct)
                                             /// to resolve path_ and get iptr_

    bool isResolved() const;

    inline std::string toString() const { return getInjectorPath(); }
};

#if ETISS_FAULT_XML

namespace xml
{



} // namespace xml

#endif

} // namespace fault

} // namespace etiss

#endif
