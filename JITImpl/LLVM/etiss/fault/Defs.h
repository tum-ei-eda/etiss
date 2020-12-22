/**

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date December 15, 2014

        @version 0.4

*/
/**
        @file

        @brief contains general definitions used by other fault library code

        @detail

*/

#ifndef ETISS_FAULT_DEFS_H_
#define ETISS_FAULT_DEFS_H_

#include <iostream>
#include <stdint.h>

/// if this code and other parts of the fault injection interface is used standalone (not as a part of ETISS) then
/// NO_ETISS must be defined in the compiler command. The makefile include (fault_xml_module.mk) defines this by
/// default.
//

/// set to 1 to enable xml support
#define ETISS_FAULT_XML 1

/// if true then C++0x or newer will be used
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L || !defined(NO_ETISS)
#define CXX0X_UP_SUPPORTED 1
#else
#define CXX0X_UP_SUPPORTED 0
#endif

#if CXX0X_UP_SUPPORTED
#include <memory>
#endif

namespace etiss
{
namespace fault
{

class Injector;

#if CXX0X_UP_SUPPORTED
typedef std::shared_ptr<Injector> Injector_ptr;
#else
typedef Injector *Injector_ptr;
#endif

} // namespace fault

} // namespace etiss

#ifdef NO_ETISS
namespace etiss
{
class ToString
{
  public:
    inline ToString() {}
    virtual inline ~ToString() {}
    virtual inline std::string toString() { return ""; }
};
} // namespace etiss
#endif

#endif
