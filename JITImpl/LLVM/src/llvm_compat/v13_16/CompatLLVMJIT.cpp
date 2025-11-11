// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <string>

#include "LLVMJIT.h"
#include "CompatLLVMJIT.h"
#include "llvm/Support/Error.h"

namespace compat
{
void *get_function_ptr(const compat::lookup_symbol_T &func)
{
    return (void *)func.getAddress();
}
} // namespace compat