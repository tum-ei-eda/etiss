/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "LLVMJIT.h"
#include "etiss/ETISS.h"

#include <iostream>

using namespace etiss;

using namespace llvm;
using namespace clang;

std::mutex etiss_jit_llvm_init_mu_;
bool etiss_jit_llvm_init_done_ = false;

LLVMLibrary::LLVMLibrary(llvm::LLVMContext &context, std::unique_ptr<llvm::Module> module) : engine_(0)
{

    if (module != 0)
    {
        // create engine
        engine_ = EngineBuilder(std::move(module))
                      .setErrorStr(&error_)
                      .setOptLevel(CodeGenOpt::Aggressive)
                      .setRelocationModel(llvm::Reloc::Static)
                      .create();
        if (engine_ == 0)
        {
            std::cout << "ERROR: LLVM: failed to create execution engine: " << error_ << std::endl;
            error_ = "Failed to create execution engine: " + error_;
        }
        else
        {
            // "compile" module for access
            engine_->finalizeObject();
        }
    }
    else
    {
        error_ = "Failed to get module from action";
    }
}
LLVMLibrary::~LLVMLibrary()
{
    delete engine_;
}

void *LLVMLibrary::getFunction(std::string name, std::string &error)
{
    if (engine_)
    {
        // get function decalaration
        Function *f = engine_->FindFunctionNamed(name.c_str());
        if (f != 0)
        {
            // get function pointer
            void *ret = engine_->getPointerToFunction(f);
            if (ret != 0)
            {
                return ret;
            }
            else
            {
                error = "Failed to get function: " + error_;
            }
        }
        else
        {
            error = "Failed to find function: " + name;
        }
    }
    else
    {
        error = "no llvm execution engine present";
    }
    return 0;
}

LLVMJIT::LLVMJIT() : JIT("LLVMJIT")
{

    // init environment once
    etiss_jit_llvm_init_mu_.lock();
    if (!etiss_jit_llvm_init_done_)
    {
        // LLVMInitializeNativeTarget();
        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();
        etiss_jit_llvm_init_done_ = true;
    }
    etiss_jit_llvm_init_mu_.unlock();
}

LLVMJIT::~LLVMJIT() {}

void *LLVMJIT::translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                         std::set<std::string> libraries, std::string &error, bool debug)
{
    clang::CompilerInstance CI;
    DiagnosticOptions *diagOpts = new DiagnosticOptions();
    TextDiagnosticPrinter *diagPrinter = new TextDiagnosticPrinter(llvm::outs(), diagOpts);
    CI.createDiagnostics(diagPrinter);
    auto pto = std::make_shared<clang::TargetOptions>();
    pto->Triple = llvm::sys::getDefaultTargetTriple();
    TargetInfo *pti = TargetInfo::CreateTargetInfo(CI.getDiagnostics(), pto);
    CI.setTarget(pti);
    CI.createFileManager();
    CI.createSourceManager(CI.getFileManager());
    CI.createPreprocessor(clang::TranslationUnitKind::TU_Module);

    // compilation task
    std::vector<std::string> args;
    if (debug)
    {
        args.push_back("-g");
        args.push_back("-O0");
    }
    else
    {
        args.push_back("-O3");
    }
    args.push_back("-std=c99");
    args.push_back("-isystem" + etiss::jitFiles() + "/clang_stdlib");
    args.push_back("-isystem/usr/include");
    args.push_back("-isystem/usr/include/x86_64-linux-gnu");
    for (const auto &headerPath : headerpaths)
    {
        args.push_back("-I" + headerPath);
    }
    args.push_back("/etiss_llvm_clang_memory_mapped_file.c");

    // configure compiler call
    std::vector<const char *> argsCStr;
    for (const auto &arg : args)
    {
        argsCStr.push_back(arg.c_str());
    }
    if (!CompilerInvocation::CreateFromArgs(CI.getInvocation(), &argsCStr[0], &argsCStr[argsCStr.size()], CI.getDiagnostics())) {
        printf("ERROR ON PARSING ARGS\n");
    }

    // input file is mapped to memory area containing the code
    auto buffer = MemoryBuffer::getMemBufferCopy(code, "/etiss_llvm_clang_memory_mapped_file.c");
    CI.getSourceManager().overrideFileContents(
        CI.getFileManager().getVirtualFile("/etiss_llvm_clang_memory_mapped_file.c", buffer->getBufferSize(), 0),
        buffer.get(), true);

    // compiler should only output llvm module
    EmitLLVMOnlyAction *action = new EmitLLVMOnlyAction();

    // compile
    if (!CI.ExecuteAction(*action))
    {
        error = "failed to execute translation action ";
        return 0;
    }

    // load module with mcjit
    LLVMLibrary *lib =
        new LLVMLibrary(context_, action->takeModule()); // translfer module ownershif from action to the engine

    // TODO: check if lib is valid now not later

    return (void*)lib;
}
void *LLVMJIT::getFunction(void *handle, std::string name, std::string &error)
{
    return ((LLVMLibrary *)handle)->getFunction(name, error);
}
void LLVMJIT::free(void *handle)
{
    delete (LLVMLibrary *)handle;
}
