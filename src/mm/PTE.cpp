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
    pte_val_ = new_pte;
}

void PTE::Update(uint64_t new_pte, uint32_t level, uint64_t phy_addr)
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
    pte_val_ = new_pte;
    pte_lvl_ = level;
    pte_addr_ = phy_addr;
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
