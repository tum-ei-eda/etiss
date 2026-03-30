// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
