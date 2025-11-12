// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#pragma once

#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "clang/Basic/LangOptions.h"

namespace compat
{

using lookup_symbol_T = llvm::orc::ExecutorSymbolDef;
#if LLVM_VERSION_MAJOR < 19
static constexpr auto tu_module_T{ clang::TranslationUnitKind::TU_Module };
#else
static constexpr auto tu_module_T{ clang::TranslationUnitKind::TU_ClangModule };
#endif

} // namespace compat