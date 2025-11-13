// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#pragma once

#if LLVM_VERSION_MAJOR >= 13 && LLVM_VERSION_MAJOR <= 16 // for linter

#include "llvm/ExecutionEngine/JITSymbol.h"
#include "clang/Basic/LangOptions.h"

namespace compat
{

using lookup_symbol_T = llvm::JITEvaluatedSymbol;
static constexpr auto tu_module_T{ clang::TranslationUnitKind::TU_Module };

} // namespace compat

#endif