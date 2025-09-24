// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "LLVMJIT.h"
#include "etiss/ETISS.h"

#include "llvm/ADT/StringRef.h"
#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/IRTransformLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/ExecutionEngine/Orc/CompileOnDemandLayer.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "clang/Basic/FileManager.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"

#include <vector>
#include <iostream>

using namespace etiss;

using namespace llvm;
using namespace clang;
using namespace llvm::orc;

std::mutex etiss_jit_llvm_init_mu_;
bool etiss_jit_llvm_init_done_ = false;

class OrcJit
{
  public:
    OrcJit(llvm::orc::JITTargetMachineBuilder JTMB, llvm::DataLayout DL)
        : ObjectLayer(ES, []() { return std::make_unique<llvm::SectionMemoryManager>(); })
        , CompileLayer(ES, ObjectLayer, std::make_unique<llvm::orc::ConcurrentIRCompiler>(std::move(JTMB)))
        , OptimizeLayer(ES, CompileLayer, optimizeModule)
        , DL(std::move(DL))
        , Mangle(ES, this->DL)
        , Ctx(std::make_unique<llvm::LLVMContext>())
        , MainJITDylib(ES.createBareJITDylib("<main>"))
    {
        MainJITDylib.addGenerator(
            llvm::cantFail(llvm::orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(DL.getGlobalPrefix())));
    }

    static llvm::Expected<std::unique_ptr<OrcJit>> Create()
    {
        auto JTMB = llvm::orc::JITTargetMachineBuilder::detectHost();
        if (!JTMB)
            return JTMB.takeError();

        auto DL = JTMB->getDefaultDataLayoutForTarget();
        if (!DL)
            return DL.takeError();

        return std::make_unique<OrcJit>(std::move(*JTMB), std::move(*DL));
    }

    const llvm::DataLayout &getDataLayout() const { return DL; }
    llvm::LLVMContext &getContext() { return *Ctx.getContext(); }

    void addModule(std::unique_ptr<llvm::Module> M)
    {
        llvm::cantFail(OptimizeLayer.add(MainJITDylib, llvm::orc::ThreadSafeModule(std::move(M), Ctx)));
    }

    llvm::Expected<llvm::JITEvaluatedSymbol> lookup(llvm::StringRef Name)
    {
        return ES.lookup({ &MainJITDylib }, Mangle(Name.str()));
    }

    bool loadLib(const std::string &libName, const std::set<std::string> &libPaths)
    {
        for (const auto &libPath : libPaths)
        {
            SmallString<128> fullPath;
            sys::path::append(fullPath, libPath, "lib" + libName + ".so");
            if (sys::fs::exists(fullPath))
            {
                MainJITDylib.addGenerator(llvm::cantFail(
                    llvm::orc::DynamicLibrarySearchGenerator::Load(fullPath.c_str(), DL.getGlobalPrefix())));
                return true;
            }
        }

        return false;
    }

    static llvm::orc::ThreadSafeModule optimizeModule(llvm::orc::ThreadSafeModule TSM,
                                                      const llvm::orc::MaterializationResponsibility &R)
    {
        auto lock = TSM.getContext();
        auto M = TSM.getModuleUnlocked();

        // Create a function pass manager.
        auto FPM = std::make_unique<llvm::legacy::FunctionPassManager>(M);

        // Add some optimizations.
        FPM->add(llvm::createInstructionCombiningPass());
        FPM->add(llvm::createReassociatePass());
        FPM->add(llvm::createGVNPass());
        FPM->add(llvm::createCFGSimplificationPass());
        FPM->doInitialization();

        // Run the optimizations over all functions in the module being added to
        // the JIT.
        for (auto &F : *M)
            FPM->run(F);

        return TSM;
    }

  private:
    llvm::orc::ExecutionSession ES;
    llvm::orc::RTDyldObjectLinkingLayer ObjectLayer;
    llvm::orc::IRCompileLayer CompileLayer;
    llvm::orc::IRTransformLayer OptimizeLayer;

    llvm::DataLayout DL;
    llvm::orc::MangleAndInterner Mangle;
    llvm::orc::ThreadSafeContext Ctx;
    llvm::orc::JITDylib &MainJITDylib;
};

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

    auto orcJit = OrcJit::Create();
    if (!orcJit)
        throw std::runtime_error("fail");
    orcJit_ = (*orcJit).release();
}

LLVMJIT::~LLVMJIT()
{
    delete orcJit_;
}

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
    for (const auto &headerPath : headerpaths)
    {
        args.push_back("-isystem" + headerPath);
    }
    args.push_back("/etiss_llvm_clang_memory_mapped_file.c");
    args.push_back("-isystem/usr/include/x86_64-linux-gnu");

    for (const auto &lib : libraries)
    {
        if (loadedLibs_.count(lib) == 0)
        {
            if (!orcJit_->loadLib(lib, librarypaths))
            {
                error = "could not load library";
                return 0;
            }
            loadedLibs_.insert(lib);
        }
    }

    // configure compiler call
    std::vector<const char *> argsCStr;
    for (const auto &arg : args)
    {
        argsCStr.push_back(arg.c_str());
    }
    if (!CompilerInvocation::CreateFromArgs(CI.getInvocation(), argsCStr, CI.getDiagnostics()))
    {
        error = "error on parsing args";
        return 0;
    }

    // input file is mapped to memory area containing the code
    auto buffer = MemoryBuffer::getMemBufferCopy(code, "/etiss_llvm_clang_memory_mapped_file.c");
    CI.getSourceManager().overrideFileContents(
        CI.getFileManager().getVirtualFile("/etiss_llvm_clang_memory_mapped_file.c", buffer->getBufferSize(), 0),
        buffer.get(), true);

    // compiler should only output llvm module

    EmitLLVMOnlyAction action(&orcJit_->getContext());

    // compile
    if (!CI.ExecuteAction(action))
    {
        error = "failed to execute translation action ";
        return 0;
    }

    // load module with orcjit
    orcJit_->addModule(action.takeModule());

    return (void *)1;
}

void *LLVMJIT::getFunction(void *handle, std::string name, std::string &error)
{

    auto func = orcJit_->lookup(name);
    if (!func)
        throw std::runtime_error("fail");
    return (void *)(*func).getAddress();
}
void LLVMJIT::free(void *handle) {}
