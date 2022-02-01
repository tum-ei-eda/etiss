/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

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

#include "RISCV64MMU.h"

#include "etiss/mm/PTEFormat.h"
#include "etiss/mm/PTEFormatBuilder.h"

#include "etiss/jit/ReturnCode.h"

RISCV64MMU::RISCV64MMU(bool pid_enabled) : MMU(true, "RISCV-sv39-MMU", pid_enabled)
{
    // Use builder utility to build up format singleton, bit field for Page Table Entry (PTE)
    PTEFormatBuilder::Instance()
        .AddPPNBitField(53, 10)
        .AddFlag("D", 7)
        .AddFlag("A", 6)
        .AddFlag("G", 5)
        .AddFlag("U", 4)
        .AddFlag("X", 3)
        .AddFlag("W", 2)
        .AddFlag("R", 1)
        .AddFlag("V", 0)
        .AddFlag("MODE", 63, 60)
        .AddFlag("ASID", 59, 44);

    // Set page size offset
    PTEFormatBuilder::Instance().AddPageOffset(11, 0);

    // Convenient manipulation for Virtual Address (VM), not part of PTE
    PTEFormatBuilder::Instance().AddFlag("VPN2", 38, 30).AddFlag("VPN1", 29, 21).AddFlag("VPN0", 20, 12);

    // Convenient manipulation for Physical Address (PM), not part of PTE
    PTEFormatBuilder::Instance().AddFlag("PPN2", 53, 28).AddFlag("PPN1", 27, 19).AddFlag("PPN0", 18, 10);

    // Allow mapping several vma to same pma
    REGISTER_PAGE_FAULT_HANDLER(PTEOVERLAP, tlb_overlap_handler);
}

void RISCV64MMU::SignalMMU(uint64_t control_reg_val_)
{   
    // Enable/Disable MMU
    uint8_t satp_mode = (control_reg_val_ & SATP64_MODE) >> 60;
    if (satp_mode == SATP_MODE_OFF)
        mmu_enabled_ = false;
    else if (!mmu_enabled_)
    {
        mmu_enabled_ = true;
        etiss::log(etiss::VERBOSE, GetName() + " : MMU is enabled.");
    }
    // Flush TLB and Cache, if ASID or PPN have changed, or if mode has been switched between SV39 and SV48
    // but not if mmu was enabled/disabled
    bool asidppn_changed = (control_reg_val_ & ~SATP_MODE_OFF) != (mmu_control_reg_val_ & ~SATP_MODE_OFF);
    bool mode_switched = false;
    if (unlikely(satp_mode != prev_satp_mode_)) // is this really necessary?
    {
        prev_satp_mode_ = satp_mode;
        mode_switched = true;
    }
    if (asidppn_changed || mode_switched)
    {
        cache_flush_pending = true;
        tlb_->Flush();
        tlb_entry_map_.clear();
        etiss::log(etiss::VERBOSE, GetName() + " : TLB flushed due to page directory update.");
        if (pid_enabled_)
            UpdatePid(GetPid(control_reg_val_));
    }
    if (mmu_control_reg_val_ != control_reg_val_)
        mmu_control_reg_val_ = control_reg_val_;
    else
        etiss::log(etiss::WARNING, "Redundant MMU control register write");
}

int32_t RISCV64MMU::WalkPageTable(uint64_t vma, MM_ACCESS access) 
{

    if (mmu_enabled_)
    {
        // Initialize leaf PTE
        PTE leaf_pte = PTE(0);
        PTE vma_pte = PTE(vma);
        // Get the PPN of page global directory
        uint64_t addr_ppn = GetMMUControlReg() & SATP_PPN_MASK;
        // Walk through page directory to find Page Table Entry (PTE)
        uint64_t leaf_pte_val = 0;
        unsigned char *buffer = (unsigned char *)(&leaf_pte_val);
        int32_t i = LEVELS;
        uint64_t addr = 0;
        uint64_t addr_offset = 0;
        int32_t fault = etiss::RETURNCODE::NOERROR;

        while (1)
        {
            // Point to current vpn index
            --i;
            std::stringstream vpn_name;
            vpn_name << "VPN" << i;
            addr_offset = vma_pte.GetByName(vpn_name.str());
            addr = (addr_ppn << PAGE_OFFSET) + addr_offset * PTESIZE;

            if ((fault = system_->dread(system_->handle, cpu_, addr, buffer, PTESIZE)))
                return fault;
            // A new leaf pte value is read from page directory
            leaf_pte.Update(leaf_pte_val);

            if ((0 == leaf_pte.GetByName("V")) || ((0 == leaf_pte.GetByName("R")) && (1 == leaf_pte.GetByName("W"))))
            {
                etiss::log(etiss::INFO, GetName() + ": PTE invalid");
                goto RETURN_PAGEFAULT;
            }
            if ((1 == leaf_pte.GetByName("R")) || (1 == leaf_pte.GetByName("X")))
                break;
            if (0 > i)
            {
                etiss::log(etiss::INFO, GetName() + ": Found no valid pte in page table");
                goto RETURN_PAGEFAULT;
            }
            // The leaf node turn out to be a page table/page directory, go to the next level with new ppn.
            addr_ppn = leaf_pte.GetByName("PPN");
        }

        // TODO: MXR, SUM check should be implemented later on.

        for (int tmp_i = i; tmp_i > 0; --tmp_i)
        {
        }

        if (0 == leaf_pte.GetByName("A"))
        {
            leaf_pte_val |= PTE_A;
            leaf_pte.Update(leaf_pte_val);
            if ((fault = system_->dwrite(system_->handle, cpu_, addr, buffer, PTESIZE)))
                return fault;
        }

        if ((0 == leaf_pte.GetByName("A")) && (W_ACCESS == access))
        {
            leaf_pte_val |= PTE_D;
            leaf_pte.Update(leaf_pte_val);
            if ((fault = system_->dwrite(system_->handle, cpu_, addr, buffer, PTESIZE)))
                return fault;
        }

        // TODO: PMA, PMP check should be implemented later on.

        uint64_t new_pte_val = leaf_pte.Get();

        // Superpage translation
        if (i > 0)
        {
            for (int tmp_i = i; tmp_i-- > 0; --tmp_i)
            {
                // Check misagligned superpage
                std::stringstream ppn_name;
                ppn_name << "PPN" << tmp_i;
                if (0 != leaf_pte.GetByName(ppn_name.str()))
                {
                    etiss::log(etiss::WARNING, GetName() + ": Superpage misagligned");
                    goto RETURN_PAGEFAULT;
                }
                std::stringstream vpn_name;
                vpn_name << "VPN" << tmp_i;
                // Debug +10 is just a work around
                new_pte_val |= vma_pte.GetByName(vpn_name.str()) << ((VPN_OFFSET * tmp_i) + 10);
            }
        }
        PTE new_pte = PTE(new_pte_val);
        AddTLBEntry(vma >> PAGE_OFFSET, new_pte);
        // Map TLB entry to physical address for write-through, because TLB is more or less a cache
        AddTLBEntryMap(addr, new_pte);
    }

    return etiss::RETURNCODE::NOERROR;

RETURN_PAGEFAULT:
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

int32_t RISCV64MMU::CheckProtection(const PTE &pte, MM_ACCESS access)
{
    bool priv_violation = false;
    auto priv = ((RISCV64*)cpu_)->CSR[3088];

    // MPRV check
    if(unlikely((((RISCV64*)cpu_)->CSR[CSR_MSTATUS] & MSTATUS_MPRV) && (access != X_ACCESS)))
        priv = ((RISCV64*)cpu_)->CSR[CSR_MSTATUS] & MSTATUS_MPP >> 11;

    // Check if current PRIV has access to page
    switch (priv)
    {
    case PRV_S:
        if ((pte.GetByName("U") == 1) && (((RISCV64*)cpu_)->CSR[CSR_SSTATUS] & SSTATUS_SUM) == 0)
            priv_violation = true;
        break;
    case PRV_U:
        if (pte.GetByName("U") != 1)
            priv_violation = true; 
        break;
    }
    
    if (priv_violation)
    {
        switch (access)
        {
        case R_ACCESS:
            return etiss::RETURNCODE::LOAD_PAGEFAULT;
        case W_ACCESS:
            return etiss::RETURNCODE::STORE_PAGEFAULT;
        case X_ACCESS:
            return etiss::RETURNCODE::INSTR_PAGEFAULT;
        }
    }
    
    switch (access)
    {
    case R_ACCESS:
        if (1 == pte.GetByName("R") || (((RISCV64*)cpu_)->CSR[CSR_MSTATUS] & MSTATUS_MXR && (pte.GetByName("X") == 1)))
            break;
        return etiss::RETURNCODE::LOAD_PAGEFAULT;
    case W_ACCESS:
        if (1 == pte.GetByName("W"))
            break;
        return etiss::RETURNCODE::STORE_PAGEFAULT;
    case X_ACCESS:
        if (1 == pte.GetByName("X"))
            break;
        return etiss::RETURNCODE::INSTR_PAGEFAULT;
    }
    return etiss::RETURNCODE::NOERROR;
}
