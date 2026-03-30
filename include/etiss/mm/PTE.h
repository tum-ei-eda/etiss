// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_INCLUDE_MM_PTE_H_
#define ETISS_INCLUDE_MM_PTE_H_

#include "etiss/mm/PTEFormat.h"
#include "etiss/mm/PTEFormatBuilder.h"

#include "etiss/Misc.h"

namespace etiss
{
namespace mm
{

/**
        @brief Page Table Entry (PTE) defines the composition of Page Frame Number
        (PFN) and relavant flags.

        @details A PTE contains page frame number (pfn) and protection flags. PTEFormat
        is used to record bit field of PFR and flags in PTE raw value.PFN or flags
        could be read/write with help of PTEFormat, which could be built up by its
        builder utility.
*/

class PTE
{
  public:
    PTE() {};

    PTE(uint64_t pte) { Update(pte); }

    // PTE(const PTE & pte_cp_){
    // 	Update(pte_cp_.pte_val_);

    // }

    // PTE & operator= (const PTE & pte_assign_){
    // 	if (& pte_assign_ == this)
    // 		return *this;
    // 	Update(pte_assign_.pte_val_);
    // 	return *this;
    // }

    /**
     * @brief Update the PTE with a new value.
     *
     */
    void Update(uint64_t new_pte);

    /**
     * @brief Get the bit field value with its name
     *
     */
    uint64_t GetByName(std::string const name) const;

    /**
     * @brief Set the bit field value with its name
     *
     */
    void SetFlagByName(std::string name, uint64_t val);

    /**
     * @brief Clear the bit field value with its name
     *
     */
    void ClearFlagByName(std::string name);

    /**
     * @brief Dump the details of the PTE entry
     *
     */
    void Dump();

    uint64_t Get() const { return pte_val_; }

    uint64_t GetPPN() const { return ppn_val_; }

  private:
    uint64_t GenerateMask(uint64_t len) const
    {
        // In order to generate 64 bit mask, mask has to be declared
        // as 64 bit integer.
        if (len >= 64)
            return static_cast<uint64_t>(-1);
        else
            return (static_cast<uint64_t>(1) << len) - 1;
    }

    void SetBit(uint32_t pos) { pte_val_ |= (static_cast<uint64_t>(1) << pos); }

    void ClearBit(uint32_t pos) { pte_val_ &= (~(static_cast<uint64_t>(1) << pos)); }

    bool CheckBit(uint32_t pos) const { return pte_val_ & (static_cast<uint64_t>(1) << pos) ? true : false; }

    uint64_t ppn_val_;
    uint64_t pte_val_;
};

} // namespace mm
} // namespace etiss

#endif
