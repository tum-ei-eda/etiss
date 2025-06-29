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

#ifndef ETISS_INCLUDE_TRANSLATION_H
#define ETISS_INCLUDE_TRANSLATION_H

#include "etiss/CPUArch.h"
#include "etiss/CodePart.h"
#include "etiss/Instruction.h"
#include "etiss/JIT.h"

#include <memory>
#include <unordered_map>

#include <thread>           // For std::thread
#include <mutex>           // For std::mutex
#include <condition_variable> // For std::condition_variable
#include <queue>           // For std::queue
#include <atomic>          // For std::atomic
#include <chrono>      

namespace etiss
{

typedef etiss::int32 (*ExecBlockCall)(ETISS_CPU *cpu, ETISS_System *system, void **plugin_pointers);

/**
                @brief structure to store additional information with a function pointer to the translated code
        */
class BlockLink
{
  public:
    const etiss::uint64 start;          ///< start instruction index
    const etiss::uint64 end;            ///< end instruction index (excluded)
    BlockLink *next;                    ///< next block; ONLY MODIFY WITH updateRef
    BlockLink *branch;                  ///< last branch block; ONLY MODIFY WITH updateRef
    unsigned refcount;                  ///< number of references to this instance; DO NOT MODIFY
    ExecBlockCall execBlock;            ///< current function pointer
    bool valid;                         ///< true if the associated function implements current code
    std::shared_ptr<void> jitlib;       ///< library of the current function

    // Fast compilation version
    ExecBlockCall fastExecBlock;        ///< Fast version (e.g. TCC)
    std::shared_ptr<void> fastJitLib;   ///< Library of fast version
    bool hasOptimized;  // Whether optimized version is available

    // New fields for optimized version
    ExecBlockCall optimizedExecBlock;   ///< Optimized version
    std::shared_ptr<void> optimizedJitLib; ///< Optimized library

    BlockLink(etiss::uint64 start, etiss::uint64 end, ExecBlockCall execBlock, std::shared_ptr<void> lib);
    ~BlockLink();
    /**
            @brief increase reference count to a BlockLink
            @param link MAY NOT BE 0
    */
    static inline void incrRef(BlockLink *link) { link->refcount++; }
    /**
            @brief decrease reference count to a BlockLink and delete the instance if no other references exist
            @param link MAY NOT BE 0
    */
    static inline void decrRef(BlockLink *&link)
    {
        link->refcount--;
        if (unlikely(link->refcount == 0))
        {
            delete link;
        }
        link = 0;
    }
    /**
            @brief change the value of a BlockLink pointer. handles reference count updates and cleanup of unreferenced
       BlockLinks
            @param link may be 0
            @param newValue may be 0
    */
    static inline void updateRef(BlockLink *&link, BlockLink *newValue)
    {
        if (link == newValue)
        {
            return;
        }
        if (likely(link != 0))
        {
            link->refcount--;
            if (unlikely(link->refcount == 0))
            {
                delete link;
            }
        }
        if (likely(newValue != 0))
        {
            incrRef(newValue);
        }
        link = newValue;
    }
};

class OptimizationManager {
private:
    struct OptimizationTask {
        std::string code;                    // Generated C code
        std::string blockFunctionName;       // Function name in the compiled code
        std::set<std::string> headers;       // Required header paths
        std::set<std::string> libloc;        // Library paths
        std::set<std::string> libs;          // Required libraries
        BlockLink* targetBlock;              // Block to optimize
        bool debug;                          // Debug flag
    };

    static const size_t NUM_THREADS = 3;          // Number of worker threads
    std::shared_ptr<etiss::JIT> optimizingJit_;   // GCC/Clang JIT instance
    std::vector<std::thread> workerThreads_;      // Pool of worker threads
    std::mutex taskMutex_;                        // Protects task queue
    std::condition_variable taskCV_;              // Signals new tasks
    std::queue<OptimizationTask> taskQueue_;      // Queue of blocks to optimize
    std::atomic<bool> shutdown_;                  // Thread shutdown flag
    std::atomic<size_t> activeThreads_;           // Number of threads currently processing tasks
    
    void optimizationWorker(size_t threadId);

public:
    OptimizationManager(std::shared_ptr<etiss::JIT> optimizingJit);
    ~OptimizationManager();
    
    void queueForOptimization(const std::string& code,
                             const std::string& blockFunctionName,
                             const std::set<std::string>& headers,
                             const std::set<std::string>& libloc,
                             const std::set<std::string>& libs,
                             BlockLink* block,
                             bool debug);

    void updateBlockWithOptimizedVersion(BlockLink* block,
                                       ExecBlockCall optimizedExec,
                                       std::shared_ptr<void> optimizedLib);
};

class Translation
{
  private:
    std::shared_ptr<etiss::CPUArch> &archptr_;
    std::shared_ptr<etiss::JIT> &jitptr_;      ///< Main JIT (optimizing)
    std::shared_ptr<etiss::JIT> &fastJitptr_;  ///< Fast JIT (e.g. TCC)
    etiss::CPUArch *const arch_;
    etiss::JIT *const jit_;                    ///< Main JIT instance
    etiss::JIT *const fastJit_;                ///< Fast JIT instance
    std::list<std::shared_ptr<etiss::Plugin>> &plugins_;
    ETISS_System &system_;
    ETISS_CPU &cpu_;
    etiss::TranslationPlugin **plugins_array_;
    void **plugins_handle_array_;
    size_t plugins_array_size_;

    std::unique_ptr<OptimizationManager> optManager_;

    /**
               Function pointer,
               the function is getting defined in Translation::init via template function etiss::call_initCodeBlock
               It calls the TranslationPlugin::initCodeBlock functions of all translation plugins
    */
    void (*plugins_initCodeBlock_)(etiss::TranslationPlugin **, CodeBlock &);
    /**
       Function pointer,
       the function is getting defined in Translation::init via template function etiss::call_finalizeCodeBlock
       It calls the TranslationPlugin::finalizeCodeBlock functions of all translation plugins
*/
    void (*plugins_finalizeCodeBlock_)(etiss::TranslationPlugin **, CodeBlock &);

    etiss::instr::ModedInstructionSet *mis_;

    std::unordered_map<etiss::uint64, std::list<BlockLink *>> blockmap_;
#if ETISS_TRANSLATOR_STAT
    etiss::uint64 next_count_;
    etiss::uint64 branch_count_;
    etiss::uint64 miss_count_;
#endif
  public:
    Translation(std::shared_ptr<etiss::CPUArch> &arch, 
               std::shared_ptr<etiss::JIT> &jit,
               std::shared_ptr<etiss::JIT> &fastJit,
               std::list<std::shared_ptr<etiss::Plugin>> &plugins, 
               ETISS_System &system, 
               ETISS_CPU &cpu);
    ~Translation();
    void **init();
    /**
            CALL THIS function NOT getBlock(...) since getBlock will not check next/branch references
            @return a reference to a block containing the instruction index if it is referenced by the current block
    */
    inline BlockLink *getBlockFast(BlockLink *prev, const etiss::uint64 &instructionindex)
    {
        if (prev != 0)
        {
            BlockLink *bl = prev->next;
            if (instructionindex >= prev->end && bl != 0 && bl->end > instructionindex)
            { // ->next MUST always start immediately after the current block since it is not checked here
                // check if block is invalid
                if (bl->valid)
                {
#if ETISS_TRANSLATOR_STAT
                    next_count_++;
#endif
                    return bl;
                }
                else
                {
                    BlockLink::updateRef(prev->next, 0);
                }
            }
            bl = prev->branch;
            if (bl != 0 && bl->start <= instructionindex && bl->end > instructionindex)
            {
                // check if block is invalid
                if (bl->valid)
                { // check
#if ETISS_TRANSLATOR_STAT
                    branch_count_++;
#endif
                    return bl;
                }
                else
                {
                    BlockLink::updateRef(prev->branch, 0);
                }
            }
        }
#if ETISS_TRANSLATOR_STAT
        miss_count_++;
#endif
        return getBlock(prev, instructionindex);
    }

    BlockLink *getBlock(BlockLink *prev, const etiss::uint64 &instructionindex);

    etiss::int32 translateBlock(CodeBlock &cb);

    void unloadBlocksAll();

    void unloadBlocks(etiss::uint64 startindex = 0, etiss::uint64 endindex = ((etiss::uint64)((etiss::int64)-1)));

    std::string disasm(uint8_t *buf, unsigned len, int &append);

  private:
    /// unique id used to generate unique function names across translation instances
    const uint64_t id;
    /// countes translated blocks. needed to guarantee unique block function names
    uint64_t tblockcount;
};

} // namespace etiss

#endif // ETISS_INCLUDE_TRANSLATION_H
