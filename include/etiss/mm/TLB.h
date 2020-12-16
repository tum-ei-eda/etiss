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

        @brief Modeling Tranlation Look-up Table (TLB)

        @detail Since MMU has to cope with translation details, TLB maps merely virtual
        frame number (vfn) to PTE. If EntryNum equals 0, TLB is configured to be
        infinitely large and no eviction is required. Otherwise, an eviction strategy
        has to be explicitly declared.

*/

#ifndef ETISS_INCLUDE_MM_TLB_H_
#define ETISS_INCLUDE_MM_TLB_H_

#include <map>

#include "etiss/mm/PTE.h"

namespace etiss
{
namespace mm
{

template <uint32_t EntryNum>
class TLB
{

    typedef std::map<uint64_t, PTE> TLBMap;

  public:
    explicit TLB() : is_full_(false)
    {

        if (unlikely(0 == EntryNum))
            infinite_tlb_entries_ = true;
        else
            max_entry_ = EntryNum;
    }

    /**
     * @brief Add an PTE entry in TLB with a pte value
     *
     */
    uint32_t AddPTE(uint64_t vfn, uint64_t pte_val)
    {
        if (unlikely(is_full_))
            return TLBISFULL;
        else if (tlb_map_.find(vfn) != tlb_map_.end())
            return PTEOVERLAP;

        tlb_map_[vfn] = std::move(PTE(pte_val));

        if (EntryNum == ++current_entry_num_)
            is_full_ = true;
        return NOERROR;
    }

    /**
     * @brief Add an PTE entry in TLB from the given PTE
     *
     */
    uint32_t AddPTE(uint64_t vfn, const PTE &pte_entry)
    {
        if (unlikely(is_full_))
            return TLBISFULL;
        else if (tlb_map_.find(vfn) != tlb_map_.end())
            return PTEOVERLAP;

        tlb_map_[vfn] = std::move(PTE(pte_entry));

        if (EntryNum == ++current_entry_num_)
            is_full_ = true;
        return NOERROR;
    }

    /**
     * @brief Look up the TLB for the given given virtual page number
     *
     */
    uint32_t Lookup(uint64_t vfn, PTE *pte_buf)
    {
        TLBMap::iterator itr = tlb_map_.find(vfn);
        // Debug
        // std::cout << "vfn in TLB: 0x" << std::hex << vfn << std::endl;
        if (itr == tlb_map_.end())
            return TLBMISS;
        *pte_buf = itr->second;
        return NOERROR;
    }

    /**
     * @brief Flush the TLB
     */
    inline void Flush()
    {
        tlb_map_.clear();
        current_entry_num_ = 0;
        if (is_full_)
            is_full_ = false;
    }

    /**
     * @brief Update the PTE entry
     *
     */
    uint32_t UpdatePTE(uint64_t vfn, uint64_t pte_val)
    {
        TLBMap::iterator itr = tlb_map_.find(vfn);
        if (unlikely(itr == tlb_map_.end()))
            return PTENOTEXISTED;
        itr->second.Update(pte_val);
        return NOERROR;
    }

    /**
     * @brief Evict the PTE entry
     *
     */
    uint32_t EvictPTE(uint64_t vfn)
    {
        TLBMap::iterator itr = tlb_map_.find(vfn);
        if (unlikely(itr == tlb_map_.end()))
            return PTENOTEXISTED;
        tlb_map_.erase(itr);
        --current_entry_num_;
        is_full_ = false;
        return NOERROR;
    }

    inline bool IsFull() const { return is_full_; }

    /**
     * @brief Dump the PTE details according to the given VPN
     *
     */
    void DumpEntry(uint64_t vfn)
    {
        TLBMap::iterator itr = tlb_map_.find(vfn);
        if (unlikely(itr == tlb_map_.end()))
        {
            etiss::log(etiss::ERROR, "No Virtual Memory Address (VMA) mapping existed");
            return;
        }
        std::cout << "Virtual Frame Number (VFN) : 0x" << std::hex << vfn << std::endl;
        itr->second.Dump();
        std::cout << "---------------------------" << std::endl;
        return;
    }

    /**
     * @brief Dump all PTEs in TLB and TLB details
     *
     */
    void Dump()
    {
        using std::cout;
        using std::endl;
        TLBMap::const_iterator itr = tlb_map_.begin();
        std::cout << "----------TLB Details---------" << std::endl;
        cout << "TLB is full : " << std::boolalpha << is_full_ << endl;
        cout << "Total entry number in TLB : " << (infinite_tlb_entries_ ? "infinite" : std::to_string(max_entry_))
             << endl;
        cout << "TLB current entry number : " << current_entry_num_ << endl;
        for (; itr != tlb_map_.end(); ++itr)
            DumpEntry(itr->first);
        return;
    }

  private:
    TLBMap tlb_map_;

    uint32_t max_entry_;
    uint32_t current_entry_num_;
    bool is_full_;
    bool infinite_tlb_entries_;
};

} // namespace mm
} // namespace etiss

#endif
