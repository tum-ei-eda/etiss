// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#pragma once

#include <memory>

#include "llvm/Config/llvm-config.h"

// Core utilities
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/MemoryBuffer.h"
#if LLVM_VERSION_MAJOR < 17
#include "llvm/Support/Host.h"
#else
#include "llvm/TargetParser/Host.h"
#endif
#include "llvm/Support/TargetSelect.h" // target arch

#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/IRTransformLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/Orc/CompileOnDemandLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#if LLVM_VERSION_MAJOR < 12 // ORC v1 – old JIT
#include "llvm/ExecutionEngine/Orc/OrcABISupport.h"
#include "llvm/ExecutionEngine/Orc/LambdaResolver.h"
#else // LLVM_VERSION_MAJOR >= 12 // Thread safety abstractions appeared in LLVM 12
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#endif
// Transform passes
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Scalar.h"

#include "clang/CodeGen/CodeGenAction.h" // code generation action "compile to IR" (for mcjit)
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/FileManager.h"
#include "clang/Frontend/CompilerInstance.h"

namespace compat
{

#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 16
using lookup_symbol_T = llvm::JITEvaluatedSymbol;
#elif LLVM_VERSION_MAJOR >= 17 && LLVM_VERSION_MAJOR <= 20
using lookup_symbol_T = llvm::orc::ExecutorSymbolDef;
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
#warning "LLVM>=11 required."
#endif

#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 18
static constexpr auto tu_module_T{ clang::TranslationUnitKind::TU_Module };
#elif LLVM_VERSION_MAJOR >= 19 && LLVM_VERSION_MAJOR <= 20
static constexpr auto tu_module_T{ clang::TranslationUnitKind::TU_ClangModule };
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
#warning "LLVM>=11 required."
#endif

std::unique_ptr<llvm::orc::ExecutionSession> createExecutionSession();

std::unique_ptr<llvm::MemoryBuffer> get_virtual_source(llvm::StringRef code, clang::CompilerInstance &CI);

void *get_function_ptr(const compat::lookup_symbol_T &func);

void createDiagnostics(clang::CompilerInstance &CI);
} // namespace compat