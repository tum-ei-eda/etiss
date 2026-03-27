// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <string>

#include "LLVMJIT.h"
#include "llvm/Support/Error.h"

#include "clang/Basic/DiagnosticOptions.h"        // logging
#include "clang/Frontend/TextDiagnosticPrinter.h" //logging
#include "clang/Basic/LangOptions.h"

#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 16
#include "llvm/ExecutionEngine/JITSymbol.h"
#elif LLVM_VERSION_MAJOR >= 17
#include "llvm/ExecutionEngine/Orc/Shared/ExecutorSymbolDef.h"
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
#warning "LLVM>=11 required."
#endif

#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 12
#include "llvm/ExecutionEngine/Orc/Core.h"
#elif LLVM_VERSION_MAJOR >= 13
#include "llvm/ExecutionEngine/Orc/ExecutorProcessControl.h"
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
#warning "LLVM>=11 required."
#endif

#include "llvm_compat.hpp"

namespace compat
{

std::unique_ptr<llvm::orc::ExecutionSession> createExecutionSession()
{
    std::unique_ptr<llvm::orc::ExecutionSession> ES{ nullptr };

#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 12
    ES = std::make_unique<llvm::orc::ExecutionSession>();
#elif LLVM_VERSION_MAJOR >= 13 && LLVM_VERSION_MAJOR <= 16
    ES = std::make_unique<llvm::orc::ExecutionSession>(cantFail(llvm::orc::SelfExecutorProcessControl::Create()));
#elif LLVM_VERSION_MAJOR >= 17 && LLVM_VERSION_MAJOR <= 19
    ES = std::make_unique<llvm::orc::ExecutionSession>(cantFail(llvm::orc::SelfExecutorProcessControl::Create()));
#elif LLVM_VERSION_MAJOR >= 20
    ES = std::make_unique<llvm::orc::ExecutionSession>(cantFail(llvm::orc::SelfExecutorProcessControl::Create()));
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
    [[deprecated]]
#endif

    if (!ES)
        llvm::report_fatal_error("Failed to create ES");
    return ES;
}

std::unique_ptr<llvm::MemoryBuffer> get_virtual_source(llvm::StringRef code, clang::CompilerInstance &CI)
{
    // input file is mapped to memory area containing the code
    std::unique_ptr<llvm::MemoryBuffer> buffer{ nullptr };
    buffer = llvm::MemoryBuffer::getMemBufferCopy(code, "/etiss_llvm_clang_memory_mapped_file.c");

#if LLVM_VERSION_MAJOR == 11
    CI.getSourceManager().overrideFileContents(
        CI.getFileManager().getVirtualFile("/etiss_llvm_clang_memory_mapped_file.c", buffer->getBufferSize(), 0),
        buffer.get(), true);
#elif LLVM_VERSION_MAJOR >= 12 && LLVM_VERSION_MAJOR <= 16
    CI.getSourceManager().overrideFileContents(
        CI.getFileManager().getVirtualFile("/etiss_llvm_clang_memory_mapped_file.c", buffer->getBufferSize(), 0),
        *buffer);
#elif LLVM_VERSION_MAJOR >= 17 && LLVM_VERSION_MAJOR <= 20
    CI.getSourceManager().overrideFileContents(
        CI.getFileManager().getVirtualFileRef("/etiss_llvm_clang_memory_mapped_file.c", buffer->getBufferSize(), 0),
        *buffer);
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
    [[deprecated]]
#endif

    return buffer;
}

void *get_function_ptr(const compat::lookup_symbol_T &func)
{
    void *ret_addr{ nullptr };

#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 16
    ret_addr = (void *)func.getAddress();
#elif LLVM_VERSION_MAJOR >= 17 && LLVM_VERSION_MAJOR <= 20
    ret_addr = func.getAddress().toPtr<void *>();
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
    [[deprecated]]
#endif

    return ret_addr;
}

void createDiagnostics(clang::CompilerInstance &CI)
{
#if LLVM_VERSION_MAJOR >= 11 && LLVM_VERSION_MAJOR <= 12
    auto diagOpts = new clang::DiagnosticOptions();
    auto diagPrinter = new clang::TextDiagnosticPrinter(llvm::outs(), diagOpts);

    CI.createDiagnostics(diagPrinter);
#elif LLVM_VERSION_MAJOR >= 13 && LLVM_VERSION_MAJOR <= 20
    auto diagOpts = llvm::makeIntrusiveRefCnt<clang::DiagnosticOptions>();
    auto diagPrinter = std::make_unique<clang::TextDiagnosticPrinter>(llvm::errs(), diagOpts.get());

    llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs> diagID(new clang::DiagnosticIDs());
#if LLVM_VERSION_MAJOR < 20
    llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diags(
        new clang::DiagnosticsEngine(diagID, diagOpts, diagPrinter.release()));
#else
    llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diags(
        new clang::DiagnosticsEngine(diagID, diagOpts, diagPrinter.release(), false));
#endif
    CI.setDiagnostics(diags.get());
#else // LLVM_VERSION_MAJOR < 11 -> deprecated
    [[deprecated]]
#endif
}

} // namespace compat
