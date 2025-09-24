// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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

#include "etiss/mm/MMU.h"
#include "etiss/CPUCore.h"
#include "etiss/jit/ReturnCode.h"

namespace etiss
{
namespace mm
{

MMU::MMU(bool hw_ptw, std::string name, bool pid_enabled)
    : mmu_enabled_(false)
    , mmu_control_reg_val_(0)
    , pid_(0)
    , name_(name)
    , pid_enabled_(pid_enabled)
    , hw_page_table_walker_(hw_ptw)
{
    tlb_ = std::shared_ptr<etiss::mm::TLB<0>>(new TLB<0>());

    REGISTER_PAGE_FAULT_HANDLER(TLBMISS, tlb_miss_handler);
    // REGISTER_PAGE_FAULT_HANDLER(TLBISFULL, tlb_full_handler);
}

int32_t MMU::Translate(const uint64_t vma, uint64_t *const pma_buf, MM_ACCESS access, uint64_t data)
{

    if (!mmu_enabled_)
    {
        *pma_buf = vma;
        return NOERROR;
    }

    if (!this->CheckPrivilegedMode())
    {
        *pma_buf = vma;
        return NOERROR;
    }

    if (PTEFormat::Instance().GetFormatMap().find(std::string("PPN")) == PTEFormat::Instance().GetFormatMap().end())
        etiss::log(etiss::FATALERROR, "PPN not defined in PTE format");

    if (PTEFormat::Instance().GetFormatMap().find(std::string("PAGEOFFSET")) ==
        PTEFormat::Instance().GetFormatMap().end())
        etiss::log(etiss::FATALERROR, "Page size offset not defined in PTE format");

    std::pair<uint32_t, uint32_t> page_offset_bitfield =
        PTEFormat::Instance().GetFormatMap().find(std::string("PAGEOFFSET"))->second;

    std::pair<uint32_t, uint32_t> ppn_bitfield = PTEFormat::Instance().GetFormatMap().find(std::string("PPN"))->second;

    uint32_t page_offset_msb_pos = page_offset_bitfield.first;

    uint32_t ppn_msb_pos = ppn_bitfield.first;

    // Add PID as part of TLB tag to reduce flush possibility.
    uint64_t vpn = vma >> (page_offset_msb_pos + 1);

    if (pid_enabled_)
    {
        vpn |= pid_ << (ppn_msb_pos + 1);
    }

    PTE pte_buf = PTE(0);
    int32_t fault = tlb_->Lookup(vpn, &pte_buf);
    if (fault)
    {
        if ((fault = HANDLE_PAGE_FAULT(fault, this, vma, access)))
            return fault;
        if ((fault = tlb_->Lookup(vpn, &pte_buf)))
        {
            Dump();
            etiss::log(etiss::FATALERROR, "TLB MISS is not correctly handled");
        }
    }

    if ((fault = CheckProtection(pte_buf, access)))
        return fault;

    uint64_t offset_mask = (1 << (page_offset_msb_pos + 1)) - 1;
    *pma_buf = (pte_buf.GetPPN() << (page_offset_msb_pos + 1)) | (vma & offset_mask);

    UpdatePTEFlags(pte_buf, access);

    // Check whether vma is trying to write the data cached in TLB, if so
    // evict the PTE entry in the TLB
    if (W_ACCESS == access)
    {
        std::map<uint64_t, PTE *>::iterator itr = tlb_entry_map_.find(*pma_buf);
        if (itr != tlb_entry_map_.end())
            tlb_entry_map_.erase(itr);
    }

    return NOERROR;
}

int32_t MMU::AddTLBEntry(const uint64_t vpn, const PTE &pte)
{
    uint32_t fault = tlb_->AddPTE(vpn, pte);
    if (fault)
    {
        if ((fault = HANDLE_PAGE_FAULT(fault, this, 0, R_ACCESS)))
            return fault;
        tlb_->AddPTE(vpn, pte);
    }
    return NOERROR;
}

void MMU::SignalMMU(uint64_t control_reg_val_)
{
    if (0 == control_reg_val_)
        mmu_enabled_ = false;
    else if (control_reg_val_ && (!mmu_enabled_))
    {
        mmu_enabled_ = true;
        etiss::log(etiss::VERBOSE, GetName() + " : MMU is enabled.");
    }
    if (control_reg_val_ != mmu_control_reg_val_)
    {
        cache_flush_pending = true;
        tlb_->Flush();
        tlb_entry_map_.clear();
        etiss::log(etiss::VERBOSE, GetName() + " : TLB flushed due to page directory update.");
        mmu_control_reg_val_ = control_reg_val_;
        if (pid_enabled_)
            UpdatePid(GetPid(control_reg_val_));
    }
    else
        etiss::log(etiss::WARNING, "Redundant MMU control register write");
}

void MMU::Dump()
{
    using std::cout;
    using std::endl;
    cout << "------------MMU Details-----------" << endl;
    cout << "MMU name : " << name_ << endl;
    cout << "MMU enabled: " << std::boolalpha << mmu_enabled_ << endl;
    cout << "PID enabled: " << std::boolalpha << pid_enabled_ << endl;
    if (pid_enabled_)
        cout << "Current PID : 0x" << std::hex << pid_ << endl;
    cout << "Current control register value : 0x" << std::hex << mmu_control_reg_val_ << endl;

    tlb_->Dump();
}

void MMU::Init(ETISS_CPU *cpu, ETISS_System *system)
{
    cpu_ = cpu;
    system_ = system;
    if (hw_page_table_walker_)
        // Page table walker probe
        if (DEFAULT_PAGE_TABLE_WALKER == this->WalkPageTable(0, R_ACCESS))
            etiss::log(etiss::FATALERROR, "No hardware page table walker, software page table walker is required ");
}

void MMU::AddTLBEntryMap(uint64_t phy_addr_, PTE &pte)
{
    if (tlb_entry_map_.find(phy_addr_) != tlb_entry_map_.end())
        HANDLE_PAGE_FAULT(PTEOVERLAP, this, 0, R_ACCESS);
    tlb_entry_map_[phy_addr_] = &pte;
}

int32_t tlb_miss_handler(int32_t fault, MMU *mmu, uint64_t vma, MM_ACCESS access)
{
    if (mmu->HasPageTableWalker())
    {
        int32_t handled_fault = NOERROR;
        if ((handled_fault = mmu->WalkPageTable(vma, access)))
            return handled_fault;
        return NOERROR;
    }

    switch (access)
    {
    case R_ACCESS:
        return etiss::RETURNCODE::LOAD_PAGEFAULT;
    case W_ACCESS:
        return etiss::RETURNCODE::STORE_PAGEFAULT;
    case X_ACCESS:
        return etiss::RETURNCODE::INSTR_PAGEFAULT;
    default:
        abort();
    }
}

void DUMP_MMU(MMU *mmu)
{
    mmu->Dump();
}

} // namespace mm
} // namespace etiss

using namespace etiss;

extern "C"
{
    void ETISS_SIGNAL_MMU(ETISS_CPU *cpu, etiss_uint64 mmu_signal_)
    {
        CPUCore *core = (CPUCore *)cpu->_etiss_private_handle_;
        if (!core)
        {
            etiss::log(etiss::ERROR, "CPUArchRegListenerInterface::signalChangedRegisterValue() called from outside "
                                     "etiss::CPUCore::execute(). this should not happen and indicates a faultiy "
                                     "CPUArch (or Plugin) implementation. This function may have been called "
                                     "indirectly from ETISS_signalChangedRegisterValue()");
            return;
        }
        auto mmu = core->getMMU();
        if (mmu)
            mmu->SignalMMU(mmu_signal_);
    }
}
