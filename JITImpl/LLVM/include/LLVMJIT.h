/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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
#include "etiss/JIT.h"

#include "clang/Basic/DiagnosticOptions.h"        // logging
#include "clang/CodeGen/CodeGenAction.h"          // code generation action "compile to IR" (for mcjit)
#include "clang/Frontend/CompilerInstance.h"      // compiler
#include "clang/Frontend/CompilerInvocation.h"    // compilation run
#include "clang/Frontend/FrontendDiagnostic.h"    // logging
#include "clang/Frontend/TextDiagnosticPrinter.h" //logging
#include "llvm/ADT/SmallString.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h" // interface to MCJIT
#include "llvm/ExecutionEngine/Interpreter.h"     // link interpreter into library (currently not used)
#include "llvm/ExecutionEngine/MCJIT.h" // IMPORTANT link MCJIT into library. if this is not included then the performance will drop by ~50%
#include "llvm/Support/TargetSelect.h" // target arch
#include "llvm/Support/raw_ostream.h"  // logging
//#include "llvm/ExecutionEngine/JIT.h" // old execution engine (performance
// drop ~50 to MCJIT)
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h" // compiled code container
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/DynamicLibrary.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/Scalar.h"
#include <cctype>
#include <clang/CodeGen/CodeGenAction.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/CompilerInvocation.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <cstdio>
#include <llvm/ADT/IntrusiveRefCntPtr.h>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace etiss
{

/**
        @brief contains compiled code from LLVMJIT::translate and a execution
   engine
*/
class LLVMLibrary
{
  public:
    LLVMLibrary(llvm::LLVMContext &context, std::unique_ptr<llvm::Module> module);
    ~LLVMLibrary();
    /**
            @brief lookup function name; NOTE: functions only NOT symbols
    */
    void *getFunction(std::string name, std::string &error);

  private:
    llvm::ExecutionEngine *engine_;
    std::string error_;
};

class LLVMJIT : public etiss::JIT
{
  public:
    LLVMJIT();
    virtual ~LLVMJIT();
    virtual void *translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                            std::set<std::string> libraries, std::string &error, bool debug = false);
    virtual void *getFunction(void *handle, std::string name, std::string &error);
    virtual void free(void *handle);

  private:
    llvm::LLVMContext context_;
};

} // namespace etiss
