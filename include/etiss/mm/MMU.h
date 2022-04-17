/**

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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @date June 24, 2018

        @version 0.1

*/
/**
        @file

        @brief Modeling hardware memory management for virtual memory -> physical
        memory translation and protection. It is oriented for porting OS to ETISS.

        @detail Memory Management Unit is the key component to support OS. Modern
        architectures vote for TLB to speed up virtual memory address (vma) to physical
        memory address (pma) translation. Since vma to pma could easily become the
        bottleneck, it is assumed hardware managed TLB is adopted. As for software
        managed TLB (old design), MMU has to be modified accordingly.

*/

#ifndef ETISS_INCLUDE_MM_MMU_H_
#define ETISS_INCLUDE_MM_MMU_H_

#include "etiss/mm/PTE.h"
#include "etiss/mm/PageFaultVector.h"
#include "etiss/mm/TLB.h"

#include "etiss/Plugin.h"

namespace etiss
{
namespace mm
{

int32_t tlb_miss_handler(int32_t fault, MMU *mmu, uint64_t vma, MM_ACCESS access);
// int32_t tlb_full_handler(int32_t fault, MMU * mmu);

class MMU
{

#define DEFAULT_PAGE_TABLE_WALKER -15

  public:
    /**
     * @brief MMU ctor. It is needed to explicitly declared whether the MMU has a
     * 		hardware page table walker, or support process identifier
     *
     */

    explicit MMU(bool hw_ptw, std::string name, bool pid_enabled);

    virtual ~MMU() {}

    /**
     * @brief Conduct the actual translation according to the format set by
     *		PTEFormatBuilder
     *
     *@see 	etiss::mm::PTEFormatBuilder and etiss::mm::PTEFormat
     *
     */
    virtual int32_t Translate(const uint64_t vma, uint64_t *const pma_buf, MM_ACCESS access, etiss_uint32 length = 0, uint64_t data = 0);

    /**
     * @brief Whenever the MMU control register changes, the MMU has to be notified
     *		with the updated control register value.
     *
     */
    virtual void SignalMMU(uint64_t control_reg_val_);

    /**
     * @brief Dump the details of the MMU, when page fault cannot be handled
     *
     */
    void Dump();

    /**
     * @brief Initialize the MMU, when DMMUWrapper is wrapping the MMU
     *
     * @see 	etiss::mm::DMMUWrapper
     *
     */
    void Init(ETISS_CPU *cpu, ETISS_System *system);

    /**
     * @brief Keep a record of mapping between cached PTE with its physical
     *		address
     *
     */
    void AddTLBEntryMap(uint64_t phy_addr_, PTE &pte);

    /**
     * @brief MMU is enabled in certain mode. Thus the privilege mode check should
     *		be implemented in architectural part
     *
     */
    virtual bool CheckPrivilegedMode() = 0;

    /**
     * @brief Memory protection is architecture-dependent, which should be implemented
     *		with architecture model
     *
     */
    virtual int32_t CheckProtection(const PTE &, MM_ACCESS access) = 0;

    /**
     * @brief Page table walking is required to translate virtual address to physical
     *		address if TLB miss occurs
     *
     */
    virtual int32_t WalkPageTable(uint64_t, MM_ACCESS) { return DEFAULT_PAGE_TABLE_WALKER; }

    /**
     * @brief Reserved for some MMU that might update PTE when translating
     *
     */
    virtual int32_t UpdatePTEFlags(PTE &, MM_ACCESS) = 0;

    bool IsTLBFull() const { return tlb_->IsFull(); }

    PTE EvictTLBEntry(const uint64_t vfn) { return tlb_->EvictPTE(vfn); }

    bool HasPageTableWalker() { return hw_page_table_walker_; }

    bool IsProcessIdEnabled() { return pid_enabled_; }

    void UpdatePid(uint32_t new_pid)
    {
        if (pid_enabled_)
            pid_ = new_pid;
    }

    uint64_t GetMMUControlReg() { return mmu_control_reg_val_; }

    int32_t AddTLBEntry(const uint64_t vfn, const PTE &pte);

    std::string GetName() const { return name_; }

    virtual int32_t GetPid(uint64_t control_reg_val_) { return 0; }

    std::shared_ptr<etiss::mm::TLB<0>> GetTLB() { return tlb_; }

    /**
     * @brief Checks if memory access is overlapping page-boundary.
     *    This is architecture specific and should be implemented by architecture.
     * 
     * @param vma 
     * @param pma_buf 
     * @param access 
     * @param length 
     * @return int32_t 
     */
    virtual int32_t CheckPageOverlap(const uint64_t vma, uint64_t *const pma_buf, MM_ACCESS access, etiss_uint32 length, const PTE &pte) = 0;

  protected:
    ETISS_CPU *cpu_;
    ETISS_System *system_;
    bool mmu_enabled_;
    // Resources in MMU
    std::shared_ptr<etiss::mm::TLB<0>> tlb_;
    // Map the virtual memory address (vma) of TLB entries to its own physical
    // location for coherence
    // NOTE: Write to TLB entries occurs rarely, so it is acceptable to evict
    //		 them directly
    std::map<uint64_t, PTE *> tlb_entry_map_;

    uint64_t mmu_control_reg_val_;

    const bool pid_enabled_;

  private:
    uint32_t pid_;
    std::string name_;
    const bool hw_page_table_walker_;
};

void DUMP_MMU(MMU *mmu);

} // namespace mm
} // namespace etiss

#endif
