// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/Translation.h"
#include "etiss/CPUArch.h"
#include "etiss/ETISS.h"
#include "etiss/Instruction.h"
#include "etiss/JIT.h"
#include "etiss/jit/ReturnCode.h"
#include <mutex>

#if ETISS_TRANSLATOR_STAT
// Forward declaration for JIT statistics update function
extern "C" void updateJITTranslationStats(uint64_t fastJitBlocks, uint64_t optimizingJitBlocks, uint64_t cacheNextHits,
                                          uint64_t cacheBranchHits, uint64_t cacheMisses, uint64_t blocksOptimized,
                                          uint64_t blocksSwitched, bool fastJitEnabled, uint64_t totalBlockExecutions,
                                          uint64_t fastJitExecutions, uint64_t optimizedExecutions,
                                          uint64_t fastJitCompilationTime_us, uint64_t optimizingJitCompilationTime_us,
                                          uint64_t translationTime_us, uint64_t blockExecTime_ns);
extern "C" void addBlockLookupTime(uint64_t time_ns);
#endif

namespace etiss
{

BlockLink::BlockLink(etiss::uint64 start, etiss::uint64 end, ExecBlockCall execBlock, std::shared_ptr<void> lib)
    : start(start)
    , end(end)
    , next(nullptr)
    , branch(nullptr)
    , refcount(0)
    , execBlock(execBlock)
    , valid(true)
    , jitlib(lib)
    , fastExecBlock(execBlock)
    , fastJitLib(lib)
    , hasOptimized(false)
    , optimizedExecBlock(nullptr)
    , optimizedJitLib(nullptr)
{
}

BlockLink::~BlockLink()
{
    if (next != 0)
        BlockLink::decrRef(next);
    if (branch != 0)
        BlockLink::decrRef(branch);
}

template <unsigned len, unsigned pos>
static typename std::enable_if<len == pos, void>::type call_initCodeBlock(etiss::TranslationPlugin **ca, CodeBlock &cb)
{
    return;
}
template <unsigned len, unsigned pos>
static typename std::enable_if<len != pos, void>::type call_initCodeBlock(etiss::TranslationPlugin **ca, CodeBlock &cb)
{
    ca[pos]->initCodeBlock(cb);
    call_initCodeBlock<len, pos + 1>(ca, cb);
}

template <unsigned len, unsigned pos>
static typename std::enable_if<len == pos, void>::type call_finalizeCodeBlock(etiss::TranslationPlugin **ca,
                                                                              CodeBlock &cb)
{
    return;
}
template <unsigned len, unsigned pos>
static typename std::enable_if<len != pos, void>::type call_finalizeCodeBlock(etiss::TranslationPlugin **ca,
                                                                              CodeBlock &cb)
{
    ca[pos]->finalizeCodeBlock(cb);
    call_finalizeCodeBlock<len, pos + 1>(ca, cb);
}

static void call_initCodeBlock_ul(etiss::TranslationPlugin **ca, CodeBlock &cb)
{
    size_t pos = 0;
    while (ca[pos] != nullptr)
    {
        ca[pos++]->initCodeBlock(cb);
    }
}
static void call_finalizeCodeBlock_ul(etiss::TranslationPlugin **ca, CodeBlock &cb)
{
    size_t pos = 0;
    while (ca[pos] != nullptr)
    {
        ca[pos++]->finalizeCodeBlock(cb);
    }
}

static uint64_t genTranslationId()
{
    static std::mutex mu;
    static uint64_t id = 0;
    std::lock_guard<std::mutex> lock(mu);
    return id++;
}

Translation::Translation(std::shared_ptr<etiss::CPUArch> &arch, std::shared_ptr<etiss::JIT> &jit,
                         std::shared_ptr<etiss::JIT> &fastJit, std::list<std::shared_ptr<etiss::Plugin>> &plugins,
                         ETISS_System &system, ETISS_CPU &cpu)
    : archptr_(arch)
    , jitptr_(jit)
    , fastJitptr_(fastJit)
    , arch_(archptr_.get())
    , jit_(jitptr_.get())
    , fastJit_(fastJitptr_.get())
    , plugins_(plugins)
    , system_(system)
    , cpu_(cpu)
    , plugins_array_(0)
    , plugins_handle_array_(0)
    , mis_(0)
#if ETISS_TRANSLATOR_STAT
    , next_count_(0)
    , branch_count_(0)
    , miss_count_(0)
    , fastJitBlocks_(0)
    , optimizingJitBlocks_(0)
    , blocksOptimized_(0)
    , blocksSwitched_(0)
    , totalBlockExecutions_(0)
    , fastJitExecutions_(0)
    , optimizedExecutions_(0)
    , fastJitCompilationTime_us_(0)
    , optimizingJitCompilationTime_us_(0)
    , translationTime_us_(0)
#endif
    , id(genTranslationId())
    , optManager_(std::make_unique<OptimizationManager>(jit,
        static_cast<size_t>(etiss::cfg().get<int>("jit.optimization_threads", 1))))
{
    tblockcount = 0;
    
#if ETISS_TRANSLATOR_STAT
    // Set up callbacks for statistics tracking
    if (optManager_)
    {
        optManager_->setOnBlockOptimized([this]() {
            blocksOptimized_++;
        });
        optManager_->setOnCompilationTime([this](uint64_t time_us) {
            optimizingJitCompilationTime_us_.fetch_add(time_us, std::memory_order_relaxed);
        });
    }
#endif
}

Translation::~Translation()
{
#if ETISS_TRANSLATOR_STAT
    // Export final JIT statistics before cleanup
    // Note: blockExecTime_us is passed as 0 here - it's updated separately by CPUCore
    updateJITTranslationStats(
        fastJitBlocks_, optimizingJitBlocks_,
        next_count_, branch_count_, miss_count_,
        blocksOptimized_, blocksSwitched_,
        fastJit_ != nullptr,
        totalBlockExecutions_, fastJitExecutions_, optimizedExecutions_,
        fastJitCompilationTime_us_, optimizingJitCompilationTime_us_.load(), translationTime_us_, 0
    );
#endif

    optManager_.reset();
    unloadBlocks(0, (uint64_t)((int64_t)-1));
    delete[] plugins_array_;
    delete[] plugins_handle_array_;
    delete mis_;
}

void **Translation::init()
{
    delete[] plugins_array_;
    plugins_array_ = 0;
    delete[] plugins_handle_array_;
    plugins_handle_array_ = 0;
    delete mis_;
    mis_ = 0;

    if (arch_ == nullptr)
        return nullptr;

    if (jit_ == nullptr)
        return nullptr;

    // First plugin to more to tmpl list is the architecture plugin
    mis_ = new etiss::instr::ModedInstructionSet(arch_->getName());

    std::vector<etiss::TranslationPlugin *> tmpl;

    tmpl.push_back(arch_);

    // Followed by all plugins, which are of type translation plugin
    for (auto iter = plugins_.begin(); iter != plugins_.end(); iter++)
    {
        etiss::Plugin *p = iter->get();
        if (p != nullptr)
        {
            etiss::TranslationPlugin *tp = p->getTranslationPlugin();
            if (tp != nullptr)
            {
                tmpl.push_back(tp);
            }
        }
    }

    // Build up the plugin lists
    plugins_array_ = new etiss::TranslationPlugin *[tmpl.size() + 1];
    plugins_array_[tmpl.size()] = nullptr;
    plugins_handle_array_ = new void *[tmpl.size()];
    plugins_array_size_ = tmpl.size();

    for (size_t i = 0; i < tmpl.size(); i++)
    {
        plugins_array_[i] = tmpl[i];
        plugins_handle_array_[i] = plugins_array_[i]->getPluginHandle();
        /* During execution of each code block, the list plugin_handle_, which
           returned by the function init, is passed again as parameter with name
           plugin_pointers
           -> plugin_pointers is the name of the list of translation plugin in the
           generated c-code of all code blocks
        */
        plugins_array_[i]->pointerCode = std::string("(plugin_pointers[") + toString(i) + "])";
    }

    // Call the function initInstrSet for all translation plugins
    for (size_t i = 0; i < tmpl.size(); i++)
    {
        plugins_array_[i]->initInstrSet(*mis_);
    }
    // Call the function finalizeInstrSet( for all translation plugins
    for (int i = (int)tmpl.size() - 1; i >= 0; i--)
    {
        plugins_array_[i]->finalizeInstrSet(*mis_);
    }

    /// TODO verify instructions, add an error message here

    if (!mis_->compile())
    {
        etiss::log(etiss::ERROR, "Failed to compile instruction set");
        delete[] plugins_array_;
        plugins_array_ = 0;
        delete[] plugins_handle_array_;
        plugins_handle_array_ = 0;
        delete mis_;
        mis_ = 0;
    }

    // Builds the function for function pointer plugins_initCodeBlock_ It calls_initCodeBlock functions of all
    // translation plugins Builds the functions plugins_finalizeCodeBlock_ It calls_finalizeCodeBlock functions of all
    // translation plugins
    switch (plugins_array_size_)
    {
    case 1:
        plugins_initCodeBlock_ = &(call_initCodeBlock<1, 0>);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock<1, 0>);
        break;
    case 2:
        plugins_initCodeBlock_ = &(call_initCodeBlock<2, 0>);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock<2, 0>);
        break;
    case 3:
        plugins_initCodeBlock_ = &(call_initCodeBlock<3, 0>);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock<3, 0>);
        break;
    case 4:
        plugins_initCodeBlock_ = &(call_initCodeBlock<4, 0>);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock<4, 0>);
        break;
    case 5:
        plugins_initCodeBlock_ = &(call_initCodeBlock<5, 0>);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock<5, 0>);
        break;
    case 6:
        plugins_initCodeBlock_ = &(call_initCodeBlock<6, 0>);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock<6, 0>);
        break;
    default:
        plugins_initCodeBlock_ = &(call_initCodeBlock_ul);
        plugins_finalizeCodeBlock_ = &(call_finalizeCodeBlock_ul);
    }

    return plugins_handle_array_;
}

BlockLink *Translation::getBlock(BlockLink *prev, const etiss::uint64 &instructionindex)
{
    std::string error;

    if (prev != 0 && !prev->valid)
    {
        prev = 0;
    }

    // search block in cache
#if ETISS_TRANSLATOR_STAT
    auto lookupStart = std::chrono::high_resolution_clock::now();
#endif
    // TODO(MM) Dig deeper into why the shift by 9 bits
    std::list<BlockLink *> &list = blockmap_[instructionindex >> 9];
    for (std::list<BlockLink *>::iterator iter = list.begin(); iter != list.end();) // iter++ moved into block
    {
        BlockLink *iterbl = (*iter);
        if (iterbl != 0)
        {
            if (iterbl->valid) // check for valid block
            {
                if (iterbl->start <= instructionindex && iterbl->end > instructionindex)
                {
                    // Check for optimized version if available
                    if (iterbl->hasOptimized && iterbl->execBlock != iterbl->optimizedExecBlock)
                    {
                        iterbl->execBlock = iterbl->optimizedExecBlock;
                        iterbl->jitlib = iterbl->optimizedJitLib;
#if ETISS_TRANSLATOR_STAT
                        blocksSwitched_++;
#endif

                        std::string msg = "Block exists with an version from " + jit_->getName();
                        if (fastJit_ != nullptr)
                        {
                            msg += ". Switching from " + fastJit_->getName();
                        }
                        etiss::log(etiss::INFO, msg);
                    }

                    if (prev != 0)
                    {
                        if (prev->end == iterbl->start)
                        {
                            BlockLink::updateRef(prev->next, iterbl);
                        }
                        else
                        {
                            BlockLink::updateRef(prev->branch, iterbl);
                        }
                    }

                    // etiss::log(etiss::INFO, "$$$ Cache HIT!!");

#if ETISS_TRANSLATOR_STAT
                    // Track execution statistics
                    trackBlockExecution(*iter);
                    auto lookupEnd = std::chrono::high_resolution_clock::now();
                    uint64_t diff = std::chrono::duration_cast<std::chrono::nanoseconds>(lookupEnd - lookupStart).count();
                    addBlockLookupTime(diff);
#endif
                    return *iter;
                }
                iter++;
            }
            else // cleanup
            {
                BlockLink::updateRef(iterbl->next, 0);
                BlockLink::updateRef(iterbl->branch, 0);
                list.erase(iter++);
                BlockLink::decrRef(
                    iterbl); // remove reference of map // prev remains valid because this blocklink needs to be invalid
                continue;
            }
        }
    }
#if ETISS_TRANSLATOR_STAT
    {
        auto lookupEnd = std::chrono::high_resolution_clock::now();
        uint64_t diff = std::chrono::duration_cast<std::chrono::nanoseconds>(lookupEnd - lookupStart).count();
        addBlockLookupTime(diff);
    }
#endif

    // generate block
    std::string blockfunctionname;
    {
        std::stringstream ss;
        ss << "_t" << id << "c" << tblockcount++ << "_block_" << instructionindex;
        blockfunctionname = ss.str();
    }

    CodeBlock block(instructionindex);

#ifdef ETISS_USE_COREDSL_COVERAGE
    block.fileglobalCode().insert("#define ETISS_USE_COREDSL_COVERAGE");
#endif

    block.fileglobalCode().insert("#include \"etiss/jit/CPU.h\"\n"
                                  "#include \"etiss/jit/System.h\"\n"
                                  "#include \"etiss/jit/libresources.h\"\n"
                                  "#include \"etiss/jit/libsemihost.h\"\n"
                                  "#include \"etiss/jit/ReturnCode.h\"\n"
                                  "#include \"etiss/jit/libCSRCounters.h\"\n");

    for (auto &it : jitExtHeaders())
    {
        if (it != "")
            block.fileglobalCode().insert("#include \"" + it + "\"\n");
    }

    block.functionglobalCode().insert("if (cpu->mode != " + toString(cpu_.mode) +
                                      ") return ETISS_RETURNCODE_RELOADCURRENTBLOCK;");

    plugins_initCodeBlock_(plugins_array_, block);

#if ETISS_TRANSLATOR_STAT
    auto transStart = std::chrono::high_resolution_clock::now();
#endif

    etiss::int32 transerror = translateBlock(block);

#if ETISS_TRANSLATOR_STAT
    auto transEnd = std::chrono::high_resolution_clock::now();
    uint64_t diff = std::chrono::duration_cast<std::chrono::microseconds>(transEnd - transStart).count();
    translationTime_us_ += diff;
#endif

    if (transerror != ETISS_RETURNCODE_NOERROR)
    {
        etiss::log(etiss::ERROR, "Failed to translate block");
        return nullptr;
    }

    plugins_finalizeCodeBlock_(plugins_array_, block);

    std::string code;
    {
        std::stringstream ss;
        block.toCode(ss, blockfunctionname, nullptr);
        code = ss.str();
    }

    // various includes
    std::set<std::string> headers;
    headers.insert(etiss::jitFiles());
    headers.insert(arch_->getIncludePath());
    for (auto &it : jitExtHeaderPaths())
    {
        if (it != "")
            headers.insert(it);
    }

    std::set<std::string> libloc;
    libloc.insert(etiss::cfg().get<std::string>("etiss_path", "./"));
    libloc.insert(etiss::jitFiles());
    libloc.insert(etiss::jitFiles() + "/etiss/jit");
    for (auto &it : jitExtLibPaths())
    {
        if (it != "")
            libloc.insert(etiss::jitFiles() + it);
    }

    std::set<std::string> libs;
    // libs.insert("ETISS");
    libs.insert("resources");
    libs.insert("semihost");
    libs.insert("CSRCounters");
    for (auto &it : jitExtLibraries())
    {
        if (it != "")
            libs.insert(it);
    }
    /* DEBUG HELPER: write code files to work directory
    {
            static unsigned count = 0;
            std::stringstream ss;
            ss << "code" << ++count;
            std::ofstream out;
            out.open(ss.str().c_str());
            out << code;
            std::cout << "Code file " << count << std::endl;
    }
    */
#ifndef ETISS_DEBUG
#define ETISS_DEBUG 0
#endif
    // Try fast compilation first if available
    BlockLink *nbl = nullptr;
    if (fastJit_ != nullptr)
    {
#if ETISS_TRANSLATOR_STAT
        auto compileStart = std::chrono::high_resolution_clock::now();
#endif
        void *funcs = fastJit_->translate(code, headers, libloc, libs, error, ETISS_DEBUG);
#if ETISS_TRANSLATOR_STAT
        auto compileEnd = std::chrono::high_resolution_clock::now();
        fastJitCompilationTime_us_ += std::chrono::duration_cast<std::chrono::microseconds>(compileEnd - compileStart).count();
#endif
        if (funcs != nullptr)
        {
            // Create library handle with cleanup
            auto local_jit = fastJit_;
            std::shared_ptr<void> fastLib(funcs, [local_jit](void *p) { local_jit->free(p); });

            // Get function pointer
            ExecBlockCall fastExec =
                (ExecBlockCall)fastJit_->getFunction(fastLib.get(), blockfunctionname.c_str(), error);
            if (fastExec != nullptr)
            {
                // Create block with fast version
                nbl = new BlockLink(block.startindex_, block.endaddress_, fastExec, fastLib);
                nbl->fastExecBlock = fastExec;
                nbl->fastJitLib = fastLib;
                nbl->hasOptimized = false;
#if ETISS_TRANSLATOR_STAT
                fastJitBlocks_++;
#endif

                // Queue optimization in background
                if (jit_ != nullptr && optManager_ != nullptr)
                {
                    optManager_->queueForOptimization(code, blockfunctionname, headers, libloc, libs, nbl, ETISS_DEBUG);
                }
            }
        }
    }

    // Fall back to main JIT if fast compilation failed or fast JIT not available
    if (nbl == nullptr)
    {
#if ETISS_TRANSLATOR_STAT
        auto compileStart = std::chrono::high_resolution_clock::now();
#endif
        void *funcs = jit_->translate(code, headers, libloc, libs, error, ETISS_DEBUG);
#if ETISS_TRANSLATOR_STAT
        auto compileEnd = std::chrono::high_resolution_clock::now();
        // Use atomic add since this could theoretically be called from main thread
        // while background threads are also updating (though unlikely in practice)
        optimizingJitCompilationTime_us_.fetch_add(
            std::chrono::duration_cast<std::chrono::microseconds>(compileEnd - compileStart).count(),
            std::memory_order_relaxed);
#endif
        if (funcs == nullptr)
        {
            etiss::log(etiss::ERROR, error);
            return 0;
        }

        // wrap library handle for cleanup
        auto local_jit = jit_;
        std::shared_ptr<void> lib(funcs, [local_jit](void *p) { local_jit->free(p); });

        ExecBlockCall execBlock = (ExecBlockCall)jit_->getFunction(lib.get(), blockfunctionname.c_str(), error);
        if (execBlock == nullptr)
        {
            etiss::log(etiss::ERROR, std::string("Failed to acquire function pointer from compiled library:") + error);
            return nullptr;
        }

        nbl = new BlockLink(block.startindex_, block.endaddress_, execBlock, lib);
#if ETISS_TRANSLATOR_STAT
        optimizingJitBlocks_++;
#endif
    }

    // Add block to cache
    uint64 ii9 = instructionindex >> 9;
    do
    {
        blockmap_[ii9].push_back(nbl);
        BlockLink::incrRef(nbl); // map holds a reference
        ii9++;
    } while ((ii9 << 9) < block.endaddress_);

    if (prev != 0)
    {
        if (nbl->start == prev->end)
        {
            BlockLink::updateRef(prev->next, nbl);
        }
        else
        {
            BlockLink::updateRef(prev->branch, nbl);
        }
    }
    
#if ETISS_TRANSLATOR_STAT
    // Track execution statistics for newly compiled block
    trackBlockExecution(nbl);
#endif
    return nbl;
}
/// \note this function only does the instruction to C code translation. compilation (C code to function pointer) is
/// done in getBlock()
etiss::int32 Translation::translateBlock(CodeBlock &cb)
{
    cb.endaddress_ = cb.startindex_;

    etiss::instr::InstructionContext context;

    context.cf_delay_slot_ = 0;
    context.force_block_end_ = false;

    unsigned count = 0;
    const unsigned maxcount = etiss::cfg().get<unsigned>("etiss.max_block_size", 100);
    cb.reserve(maxcount);

    etiss::instr::VariableInstructionSet *const vis_ = mis_->get(cpu_.mode);

    if (vis_ == nullptr)
    {
        return etiss::RETURNCODE::GENERALERROR;
    }

    etiss::instr::BitArray mainba(vis_->width_);
    etiss::instr::Buffer buffer;

    do
    {
        context.force_append_next_instr_ = false;
        context.force_block_end_ = false;
        context.current_address_ = cb.endaddress_;
        context.current_local_address_ = cb.endaddress_ - cb.startindex_;
        context.instr_width_fully_evaluated_ = true;
        context.is_not_default_width_ = false;
        context.instr_width_ = vis_->width_;

        etiss::instr::BitArray errba(32, 0);

        buffer = etiss::instr::Buffer(mainba.intCount());
        // read instruction
        etiss::int32 ret = (*system_.dbg_read)(system_.handle, cb.endaddress_, (etiss_uint8 *)buffer.internalBuffer(),
                                               mainba.byteCount()); // read instruction
        mainba.set_value(buffer.data());
        if (ret == etiss::RETURNCODE::IBUS_READ_ERROR || ret == etiss::RETURNCODE::DBUS_READ_ERROR)
        {
            std::cout << "Instruction bus read error while translating!" << std::endl;
            errba.set_value(etiss::RETURNCODE::IBUS_READ_ERROR);
            // std::cout << "mainba.byteCount = " << mainba.byteCount() << std::endl;
            auto instr = &vis_->getMain()->getInvalid();
            CodeBlock::Line &line = cb.append(cb.endaddress_); // allocate codeset for instruction
            bool ok = instr->translate(errba, line.getCodeSet(), context);
            if (unlikely(!ok))
            {
                return etiss::RETURNCODE::GENERALERROR;
            }
            cb.endaddress_ += mainba.byteCount(); // update end address
            return etiss::RETURNCODE::NOERROR;
        }
        if (ret != etiss::RETURNCODE::NOERROR)
        {
            if (count == 0)
            {
                return ret; // empty block -> return error
            }
            else
            {
                break; // non empty block -> compile pending
            }
        }

        arch_->compensateEndianess(&cpu_, mainba);
        vis_->length_updater_(*vis_, context, mainba);

        // continue reading instruction data if neccessary
        if (unlikely(context.is_not_default_width_))
        {
            etiss::instr::BitArray *secba = nullptr;
            do
            {
                if (secba)
                    delete secba;
                secba = new etiss::instr::BitArray(context.instr_width_);

                buffer = etiss::instr::Buffer(secba->intCount());
                ret = (*system_.dbg_read)(system_.handle, cb.endaddress_, (etiss_uint8 *)buffer.internalBuffer(),
                                          secba->byteCount()); // read instruction
                secba->set_value(buffer.data());

                if (ret != etiss::RETURNCODE::NOERROR)
                {
                    if (count == 0)
                    {
                        delete secba;
                        return ret; // empty block -> return error
                    }
                    else
                    {
                        break; // non empty block -> compile pending
                    }
                }
                arch_->compensateEndianess(&cpu_, *secba);
                vis_->length_updater_(*vis_, context, *secba);
            } while (!context.instr_width_fully_evaluated_);

            etiss::instr::Instruction *instr;
            etiss::instr::InstructionSet *instrSet = vis_->get(secba->size());
            if (unlikely(!instrSet))
            {
                errba.set_value(etiss::RETURNCODE::ILLEGALINSTRUCTION);
                instr = &vis_->getMain()->getInvalid();
            }
            else
            {
                instr = instrSet->resolve(*secba);
                if (unlikely(!instr))
                {
                    errba.set_value(etiss::RETURNCODE::ILLEGALINSTRUCTION);
                    instr = &instrSet->getInvalid();
                }
            }
            CodeBlock::Line &line = cb.append(cb.endaddress_); // allocate codeset for instruction
            bool ok =
                instr->translate(errba != etiss::instr::BitArray(32, 0) ? errba : *secba, line.getCodeSet(), context);
            if (unlikely(!ok))
            {
                delete secba;
                return etiss::RETURNCODE::GENERALERROR;
            }
            cb.endaddress_ += secba->byteCount(); // update end address
            delete secba;
        }
        else
        {
            etiss::instr::InstructionSet *instrSet = vis_->getMain();
            etiss::instr::Instruction *instr = instrSet->resolve(mainba);
            if (unlikely(instr == 0))
            {
                errba.set_value(etiss::RETURNCODE::ILLEGALINSTRUCTION);
                instr = &instrSet->getInvalid();
            }
            CodeBlock::Line &line = cb.append(cb.endaddress_); // allocate codeset for instruction
            bool ok =
                instr->translate(errba != etiss::instr::BitArray(32, 0) ? errba : mainba, line.getCodeSet(), context);
            if (unlikely(!ok))
            {
                return etiss::RETURNCODE::GENERALERROR;
            }
            cb.endaddress_ += mainba.byteCount(); // update end address
        }

        count++;
    } while ((count < maxcount && !context.force_block_end_) || context.force_append_next_instr_);

    return etiss::RETURNCODE::NOERROR;
}

void Translation::unloadBlocksAll()
{
    for (auto &entry : blockmap_)
    {
        entry.second.erase(std::remove_if(entry.second.begin(), entry.second.end(),
                                          [](auto &bl)
                                          {
                                              bl->valid = false;
                                              BlockLink::updateRef(bl->next, 0);
                                              BlockLink::updateRef(bl->branch, 0);
                                              BlockLink::decrRef(bl); // remove reference of map
                                              return true;
                                          }),
                           entry.second.end());
    }
    blockmap_.clear();
}

void Translation::unloadBlocks(etiss::uint64 startindex, etiss::uint64 endindex)
{
    // Hotfix: if everything needs to be deleted, new function unloadBlocksAll()
    if (startindex == 0 && endindex == ((etiss::uint64)((etiss::int64)-1)))
    {
        unloadBlocksAll();
        return;
    }

    const etiss::uint64 startindexblock = startindex >> 9;
    const etiss::uint64 endindexblock = (endindex >> 9) + ((((endindex >> 9) << 9) == endindex) ? 0 : 1);
    for (etiss::uint64 block = startindexblock; block < endindexblock; block++)
    {
        if (blockmap_.empty())
            break;
        auto entry = blockmap_.find(block);
        if (entry != blockmap_.end())
        {
            for (std::list<BlockLink *>::iterator iter = entry->second.begin(); iter != entry->second.end();)
            {
                BlockLink *bl = *iter;
                if (bl->start < endindex || bl->end > startindex)
                {
                    bl->valid = false;
                    BlockLink::updateRef(bl->next, 0);
                    BlockLink::updateRef(bl->branch, 0);
                    entry->second.erase(iter++);
                    BlockLink::decrRef(bl); // remove reference of map
                }
                else
                {
                    iter++;
                }
            }
            if (entry->second.empty())
                blockmap_.erase(entry);
        }
    }
}

std::string Translation::disasm(uint8_t *buf, unsigned len, int &append)
{
    etiss::instr::BitArray mainba(len * 8);
    etiss::instr::Buffer buffer(mainba.intCount());

    memcpy(buffer.internalBuffer(), buf, len);
    mainba.set_value(buffer.data());

    // TODO implement propper instruction selection with append requests is neccessary

    etiss::instr::VariableInstructionSet *vis = mis_->get(cpu_.mode);

    if (vis == 0)
        return "UNKNOWN";

    etiss::instr::InstructionSet *is = vis->get(len * 8);

    if (is == 0)
        return "UNKNOWN";

    etiss::instr::Instruction *instr = is->resolve(mainba);

    if (instr == 0)
        return "UNKNOWN";

    return instr->printASM(mainba);
}

// In Translation.cpp
OptimizationManager::OptimizationManager(std::shared_ptr<etiss::JIT> optimizingJit, size_t numThreads)
    : numThreads_(numThreads)
    , optimizingJit_(optimizingJit)
    , shutdown_(false)
    , activeThreads_(0)
    , onBlockOptimized_(nullptr)
{
    // Create a separate JIT instance for each worker thread to enable parallel compilation
    // This is necessary because LLVM JIT is not thread-safe for concurrent translate() calls
    std::string jitName = optimizingJit_ ? optimizingJit_->getName() : "";
    if (!jitName.empty()) {
        threadJits_.reserve(numThreads_);
        for (size_t i = 0; i < numThreads_; i++) {
            std::shared_ptr<etiss::JIT> threadJit = etiss::getJIT(jitName, std::map<std::string, std::string>());
            if (threadJit) {
                threadJits_.push_back(threadJit);
            } else {
                // Fallback to shared instance if creation fails
                etiss::log(etiss::WARNING, "Failed to create per-thread JIT instance, using shared instance");
                threadJits_.push_back(optimizingJit_);
            }
        }
    } else {
        // If no JIT name, use shared instance for all threads
        threadJits_.resize(numThreads_, optimizingJit_);
    }

    // Create worker threads
    for (size_t i = 0; i < numThreads_; i++)
    {
        workerThreads_.emplace_back(&OptimizationManager::optimizationWorker, this, i);
        activeThreads_++;
    }
}

OptimizationManager::~OptimizationManager()
{
    // Signal all threads to stop and wait
    shutdown_ = true;
    taskCV_.notify_all();

    // Wait for all threads to finish
    for (auto &thread : workerThreads_)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}

void OptimizationManager::optimizationWorker(size_t threadId)
{
    etiss::log(etiss::INFO, "Starting optimization worker thread " + std::to_string(threadId));

    while (!shutdown_)
    {
        OptimizationTask task;
        bool hasTask = false;

        // Scope block for mutex lock
        {
            std::unique_lock<std::mutex> lock(taskMutex_);
            taskCV_.wait(lock, [this] { return !taskQueue_.empty() || shutdown_; });

            if (shutdown_)
            {
                // Release lock and exit
                lock.unlock();
                break;
            }

            if (!taskQueue_.empty())
            {
                task = std::move(taskQueue_.front());
                taskQueue_.pop();
                hasTask = true;
            }
            // Lock is automatically released here when lock goes out of scope
        }

        if (hasTask)
        {
            std::string error;
            // Use per-thread JIT instance for parallel compilation
            std::shared_ptr<etiss::JIT> threadJit = (threadId < threadJits_.size()) ? threadJits_[threadId] : optimizingJit_;

#if ETISS_TRANSLATOR_STAT
            auto compileStart = std::chrono::high_resolution_clock::now();
#endif
            void *funcs = threadJit->translate(task.code, task.headers, task.libloc, task.libs, error, task.debug);
#if ETISS_TRANSLATOR_STAT
            auto compileEnd = std::chrono::high_resolution_clock::now();
            auto compileTime_us = std::chrono::duration_cast<std::chrono::microseconds>(compileEnd - compileStart).count();
            if (onCompilationTime_)
            {
                onCompilationTime_(compileTime_us);
            }
#endif

            if (funcs)
            {
                // Create library handle with cleanup (use same JIT instance that compiled it)
                auto optimizedLib = std::shared_ptr<void>(funcs, [jit = threadJit](void *p) { jit->free(p); });

                // Get function pointer (use same JIT instance that compiled it)
                ExecBlockCall optimizedExecBlock = (ExecBlockCall)threadJit->getFunction(
                    optimizedLib.get(), task.blockFunctionName.c_str(), error);

                if (optimizedExecBlock)
                {
                    // Update block with optimized version
                    updateBlockWithOptimizedVersion(task.targetBlock, optimizedExecBlock, optimizedLib);
                }
                else
                {
                    etiss::log(etiss::WARNING, "Thread " + std::to_string(threadId) +
                                                   ": Failed to get optimized function pointer: " + error);
                }
            }
            else
            {
                etiss::log(etiss::WARNING,
                           "Thread " + std::to_string(threadId) + ": Failed to compile optimized version: " + error);
            }
        }
    }

    activeThreads_--;
    etiss::log(etiss::INFO, "Optimization worker thread " + std::to_string(threadId) + " shutting down");
}

void OptimizationManager::queueForOptimization(const std::string &code, const std::string &blockFunctionName,
                                               const std::set<std::string> &headers,
                                               const std::set<std::string> &libloc, const std::set<std::string> &libs,
                                               BlockLink *block, bool debug)
{

    std::lock_guard<std::mutex> lock(taskMutex_);
    taskQueue_.push({ code, blockFunctionName, headers, libloc, libs, block, debug });
    taskCV_.notify_one(); // Wake up one waiting thread
}

void OptimizationManager::updateBlockWithOptimizedVersion(BlockLink *block, ExecBlockCall optimizedExec,
                                                          std::shared_ptr<void> optimizedLib)
{
    if (block != nullptr)
    {
        // Store optimized version in new fields
        block->optimizedExecBlock = optimizedExec;
        block->optimizedJitLib = optimizedLib;
        block->hasOptimized = true;
        etiss::log(etiss::INFO, "==> Block updated with optimized version using " + optimizingJit_->getName());
        
        // Call callback to notify that a block was optimized
        if (onBlockOptimized_)
        {
            onBlockOptimized_();
        }
    }
}

} // namespace etiss
