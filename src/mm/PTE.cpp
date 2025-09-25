// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

/**
        @brief Page Table Entry (PTE) defines the composition of Page Frame Number
        (PFN) and relavant flags.

        @details A PTE contains page frame number (pfn) and protection flags. PTEFormat
        is used to record bit field of PFR and flags in PTE raw value.PFN or flags
        could be read/write with help of PTEFormat, which could be built up by its
        builder utility.
*/

#include "etiss/mm/PTE.h"

namespace etiss
{
namespace mm
{

void PTE::Update(uint64_t new_pte)
{

    if (PTEFormat::Instance().GetFormatMap().find(std::string("PPN")) == PTEFormat::Instance().GetFormatMap().end())
    {
        PTEFormat::Instance().Dump();
        PTEFormat::Instance().Dump();
        etiss::log(etiss::FATALERROR, "PPN not defined in PTE format");
    }

    std::pair<uint32_t, uint32_t> bit_field = PTEFormat::Instance().GetFormatMap().find(std::string("PPN"))->second;
    if (new_pte & (~GenerateMask(PTEFormat::Instance().GetPTELength())))
    {
        std::stringstream msg;
        msg << "PTE value: [0x" << std::hex << new_pte << "] exceed the format length " << std::dec
            << PTEFormat::Instance().GetPTELength() << "." << std::endl;
        PTEFormat::Instance().Dump();
        etiss::log(etiss::FATALERROR, msg.str());
    }

    ppn_val_ = new_pte >> bit_field.second;
    ;
    pte_val_ = new_pte;
}

uint64_t PTE::GetByName(std::string const name) const
{
    PTEFormatMap::const_iterator itr = PTEFormat::Instance().GetFormatMap().find(name);
    if (itr == PTEFormat::Instance().GetFormatMap().end())
    {
        std::stringstream msg;
        msg << "Trying to get value of non-existed Flag in PTE: " << name << std::endl;
        PTEFormat::Instance().Dump();
        etiss::log(etiss::FATALERROR, msg.str());
    }
    std::pair<uint32_t, uint32_t> bit_field = itr->second;
    uint32_t msb_pos = bit_field.first;
    uint32_t lsb_pos = bit_field.second;
    uint32_t len = msb_pos - lsb_pos + 1;
    return (pte_val_ >> lsb_pos) & GenerateMask(len);
}

void PTE::SetFlagByName(std::string name, uint64_t val)
{
    PTEFormatMap::const_iterator itr = PTEFormat::Instance().GetFormatMap().find(name);
    if (itr == PTEFormat::Instance().GetFormatMap().end())
    {
        std::stringstream msg;
        msg << "Trying to set value of non-existed Flag in PTE: " << name << std::endl;
        PTEFormat::Instance().Dump();
        etiss::log(etiss::FATALERROR, msg.str());
    }
    std::pair<uint32_t, uint32_t> bit_field = itr->second;
    uint32_t i = 0;
    do
    {
        if (val & (static_cast<uint64_t>(1) << i))
            SetBit(i + bit_field.second);
        ++i;
    } while (i <= bit_field.first);
}

void PTE::ClearFlagByName(std::string name)
{
    PTEFormatMap::const_iterator itr = PTEFormat::Instance().GetFormatMap().find(name);
    if (itr == PTEFormat::Instance().GetFormatMap().end())
    {
        std::stringstream msg;
        msg << "Trying to clear value of non-existed Flag in PTE: " << name << std::endl;
        PTEFormat::Instance().Dump();
        etiss::log(etiss::FATALERROR, msg.str());
    }
    std::pair<uint32_t, uint32_t> bit_field = itr->second;
    uint32_t i = 0;
    do
    {
        ClearBit(i + bit_field.second);
        ++i;
    } while (i <= bit_field.first);
}

void PTE::Dump()
{
    std::cout << "PTE length : " << PTEFormat::Instance().GetPTELength() << std::endl;
    std::cout << "PTE entry value: 0x" << std::hex << pte_val_ << std::endl;
    std::cout << "Bit field details: " << std::endl;
    PTEFormatMap::const_iterator itr = PTEFormat::Instance().GetFormatMap().begin();
    for (; itr != PTEFormat::Instance().GetFormatMap().end(); ++itr)
    {
        std::string name = itr->first;
        PTEFormat::Instance().DumpBitFild(name);
        std::cout << "Value of " << name << " : 0x" << std::hex << GetByName(name) << std::endl;
    }
    return;
}

} // namespace mm
} // namespace etiss
