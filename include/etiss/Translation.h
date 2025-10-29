// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_INCLUDE_TRANSLATION_H
#define ETISS_INCLUDE_TRANSLATION_H

#include "etiss/Misc.h"

#include <memory>
#include <unordered_map>

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
    const ExecBlockCall execBlock;      ///< function pointer
    bool valid;                         ///< true if the associated function implements current code
    const std::shared_ptr<void> jitlib; ///< library of the associated function
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

class Translation
{
  private:
    std::shared_ptr<etiss::CPUArch> &archptr_;
    std::shared_ptr<etiss::JIT> &jitptr_;
    etiss::CPUArch *const arch_;
    etiss::JIT *const jit_;
    std::list<std::shared_ptr<etiss::Plugin>> &plugins_;
    ETISS_System &system_;
    ETISS_CPU &cpu_;
    etiss::TranslationPlugin **plugins_array_;
    void **plugins_handle_array_;
    size_t plugins_array_size_;

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
    Translation(std::shared_ptr<etiss::CPUArch> &arch, std::shared_ptr<etiss::JIT> &jit,
                std::list<std::shared_ptr<etiss::Plugin>> &plugins, ETISS_System &system, ETISS_CPU &cpu);
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
