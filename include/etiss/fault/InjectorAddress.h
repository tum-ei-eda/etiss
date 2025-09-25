// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
