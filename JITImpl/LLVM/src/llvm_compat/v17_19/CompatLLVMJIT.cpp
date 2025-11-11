// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <string>

#include "LLVMJIT.h"
#include "CompatLLVMJIT.h"
#include "llvm/Support/Error.h"

#include "clang/Basic/DiagnosticOptions.h"        // logging
#include "clang/Frontend/TextDiagnosticPrinter.h" //logging

#include "llvm_compat.hpp"

namespace compat
{
void *get_function_ptr(const compat::lookup_symbol_T &func)
{
    return func.getAddress().toPtr<void *>();
}

std::unique_ptr<llvm::orc::ExecutionSession> createExecutionSession()
{
    auto ES = std::make_unique<llvm::orc::ExecutionSession>(cantFail(llvm::orc::SelfExecutorProcessControl::Create()));
    if (!ES)
        llvm::report_fatal_error("Failed to create ES");
    return ES;
}

std::unique_ptr<llvm::MemoryBuffer> get_virtual_source(llvm::StringRef code, clang::CompilerInstance &CI)
{
    // input file is mapped to memory area containing the code
    auto buffer = llvm::MemoryBuffer::getMemBufferCopy(code, "/etiss_llvm_clang_memory_mapped_file.c");
    CI.getSourceManager().overrideFileContents(
        CI.getFileManager().getVirtualFile("/etiss_llvm_clang_memory_mapped_file.c", buffer->getBufferSize(), 0),
        *buffer);

    return buffer;
}

void createDiagnostics(clang::CompilerInstance &CI)
{
    auto diagOpts = std::make_shared<clang::DiagnosticOptions>();
    auto diagPrinter = std::make_unique<clang::TextDiagnosticPrinter>(llvm::errs(), diagOpts.get());

    llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs> diagID(new clang::DiagnosticIDs());
    llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diags(
        new clang::DiagnosticsEngine(diagID, diagOpts, diagPrinter.release()));

    clang::CompilerInstance CI;
    CI.setDiagnostics(diags.get());
}
} // namespace compat