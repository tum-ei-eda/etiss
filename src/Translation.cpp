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

#include "etiss/Translation.h"
#include <mutex>

namespace etiss
{

BlockLink::BlockLink(etiss::uint64 start, etiss::uint64 end, ExecBlockCall execBlock, std::shared_ptr<void> lib)
    : start(start), end(end), execBlock(execBlock), jitlib(lib)
{
    refcount = 0;
    next = 0;
    branch = 0;
    valid = true;
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
                         std::list<std::shared_ptr<etiss::Plugin>> &plugins, ETISS_System &system, ETISS_CPU &cpu)
    : archptr_(arch)
    , jitptr_(jit)
    , arch_(archptr_.get())
    , jit_(jitptr_.get())
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
#endif
    , id(genTranslationId())
{
    tblockcount = 0;
}

Translation::~Translation()
{
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

    // generate block

    std::string blockfunctionname;
    {
        std::stringstream ss;
        ss << "_t" << id << "c" << tblockcount++ << "_block_" << instructionindex;
        blockfunctionname = ss.str();
    }

    CodeBlock block(instructionindex);
    block.fileglobalCode().insert("#include \"etiss/jit/CPU.h\"\n"
                                  "#include \"etiss/jit/System.h\"\n"
                                  "#include \"etiss/jit/libresources.h\"\n"
                                  "#include \"etiss/jit/libsemihost.h\"\n"
                                  "#include \"etiss/jit/ReturnCode.h\"\n"
                                  "#include \"etiss/jit/libCSRCounters.h\"\n");

    for(auto &it: jitExtHeaders()){
        if(it != "") block.fileglobalCode().insert("#include \"" + it + "\"\n");
    }

    block.functionglobalCode().insert("if (cpu->mode != " + toString(cpu_.mode) +
                                      ") return ETISS_RETURNCODE_RELOADCURRENTBLOCK;");

    plugins_initCodeBlock_(plugins_array_, block);

    etiss::int32 transerror = translateBlock(block);

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
    for(auto & it: jitExtHeaderPaths()){
       if(it != "") headers.insert(it);
    }

    std::set<std::string> libloc;
    libloc.insert(arch_->getIncludePath());
    libloc.insert(etiss::cfg().get<std::string>("etiss_path", "./"));
    libloc.insert(etiss::jitFiles());
    libloc.insert(etiss::jitFiles() + "/etiss/jit");
    for(auto & it: jitExtLibPaths()){
       if(it != "") libloc.insert(etiss::jitFiles() + it);
    }

    std::set<std::string> libs;
    //libs.insert("ETISS");
    libs.insert("resources");
    libs.insert("semihost");
    libs.insert("CSRCounters");
    for(auto & it: jitExtLibraries()){
       if(it != "") libs.insert(it);
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
#define ETISS_DEBUG 1
#endif
    // compile library
    void *funcs =
        jit_->translate(code, headers, libloc, libs, error, etiss::cfg().get<bool>("jit.debug", ETISS_DEBUG) != 0);

    if (funcs == 0)
    {
        etiss::log(etiss::ERROR, error);
        return 0;
    }

    // wrap library handle for cleanup
    auto local_jit = jit_;
    std::shared_ptr<void> lib(funcs, [local_jit](void *p) { local_jit->free(p); });

    // check function/library handle
    if (lib.get() != 0)
    {
        // std::cout<<"blockfunctionname:"<<blockfunctionname<<std::endl;
        ExecBlockCall execBlock = (ExecBlockCall)jit_->getFunction(lib.get(), blockfunctionname.c_str(), error);
        if (execBlock != 0)
        {
            BlockLink *nbl = new BlockLink(block.startindex_, block.endaddress_, execBlock, lib);
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
            return nbl;
        }
        else
        {
            etiss::log(etiss::ERROR, std::string("Failed to acquire function pointer from compiled library:") + error);
            return 0;
        }
    }

    return 0;
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

    etiss::instr::VariableInstructionSet *const vis_ = mis_->get(cpu_.mode);

    if (vis_ == nullptr)
    {
        return etiss::RETURNCODE::GENERALERROR;
    }

    etiss::instr::BitArray mainba(vis_->width_);

    do
    {
        context.force_append_next_instr_ = false;
        context.force_block_end_ = false;
        context.current_address_ = cb.endaddress_;
        context.current_local_address_ = cb.endaddress_ - cb.startindex_;
        context.instr_width_fully_evaluated_ = true;
        context.is_not_default_width_ = false;
        context.instr_width_ = vis_->width_;

        // read instruction
        etiss::int32 ret = (*system_.dbg_read)(system_.handle, cb.endaddress_, (etiss_uint8 *)mainba.internalBuffer(),
                                               mainba.byteCount()); // read instruction
        if (ret == etiss::RETURNCODE::IBUS_READ_ERROR)
        {
            std::cout << "Instruction bus read error while translating!" << std::endl;
            CodeBlock::Line &line = cb.append(cb.endaddress_); // allocate codeSet for Instruction
            line.getCodeSet().append(CodePart::PREINITIALDEBUGRETURNING).code() =
                std::string("cpu->cpuTime_ps += "
                            "cpu->cpuCycleTime_ps;cpu->instructionPointer += ") +
                std::to_string(mainba.byteCount()) + std::string(";return ETISS_RETURNCODE_IBUS_READ_ERROR;");
            // std::cout << "mainba.byteCount = " << mainba.byteCount() << std::endl;
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
        // mainba.recoverFromEndianness(4,etiss::_BIG_ENDIAN_); ///TODO

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
                ret = (*system_.dbg_read)(system_.handle, cb.endaddress_, (etiss_uint8 *)secba->internalBuffer(),
                                          secba->byteCount()); // read instruction
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
                // secba->recoverFromEndianness(4,etiss::_BIG_ENDIAN_);
                vis_->length_updater_(*vis_, context, *secba);
            } while (!context.instr_width_fully_evaluated_);

            etiss::instr::Instruction *instr;
            etiss::instr::InstructionSet *instrSet = vis_->get(secba->width());
            if (unlikely(!instrSet))
            {
                instr = &vis_->getMain()->getInvalid();
            }
            else
            {
                instr = instrSet->resolve(*secba);
                if (unlikely(!instr))
                {
                    instr = &instrSet->getInvalid();
                }
            }
            CodeBlock::Line &line = cb.append(cb.endaddress_); // allocate codeset for instruction
            bool ok = instr->translate(*secba, line.getCodeSet(), context);
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
                instr = &instrSet->getInvalid();
            }
            CodeBlock::Line &line = cb.append(cb.endaddress_); // allocate codeset for instruction
            bool ok = instr->translate(mainba, line.getCodeSet(), context);
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

void Translation::unloadBlocks(etiss::uint64 startindex, etiss::uint64 endindex)
{
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
    memcpy(mainba.internalBuffer(), buf, len);

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

} // namespace etiss
