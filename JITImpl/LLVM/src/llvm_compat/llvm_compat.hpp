// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#pragma once

#include <memory>
#include "CompatLLVMJIT.h"

namespace compat
{

std::unique_ptr<llvm::orc::ExecutionSession> createExecutionSession();

std::unique_ptr<llvm::MemoryBuffer> get_virtual_source(llvm::StringRef code, clang::CompilerInstance &CI);

void *get_function_ptr(const compat::lookup_symbol_T &func);

void createDiagnostics(clang::CompilerInstance &CI);
} // namespace compat