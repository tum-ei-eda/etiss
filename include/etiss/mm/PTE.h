/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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
    PTE(){};

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
        uint64_t mask = 1;
        if (len == 64)
            mask = -1;
        else
            mask = (mask << len) - 1;
        return mask;
    }

    void SetBit(uint32_t pos) { pte_val_ |= (static_cast <uint64_t>(1) << pos); }

    void ClearBit(uint32_t pos) { pte_val_ &= (~(static_cast < uint64_t > (1) << pos)); }

    bool CheckBit(uint32_t pos) const { return pte_val_ & (static_cast<uint64_t>(1) << pos) ? true : false; }

    uint64_t ppn_val_;
    uint64_t pte_val_;
};

} // namespace mm
} // namespace etiss

#endif
