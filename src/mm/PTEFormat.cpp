// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

/**
        @brief Singleton to represent specific PTE format, every PTE uses this singleton
        to parse raw PTE value into PPN and protection flags, read/write PPN or flags.
*/

#include "etiss/mm/PTEFormat.h"

namespace etiss
{
namespace mm
{

void PTEFormat::AddBitField(std::string name, uint32_t begin, uint32_t end)
{
    if ((begin + 1) > pte_len_)
    {
        pte_len_ = begin + 1;
    }
    format_map_.insert(std::make_pair(name, std::make_pair(begin, end)));
}

void PTEFormat::DumpBitFild(std::string name)
{
    using std::cout;
    using std::endl;
    PTEFormatMap::iterator itr = format_map_.find(name);
    if (itr != format_map_.end())
    {
        cout << "Bit Field Name : [" << itr->first << "]  Position: [" << std::dec << itr->second.first << ","
             << std::dec << itr->second.second << "]" << endl;
        return;
    }
    cout << "Bit Field Name : [" << name << "] not founded" << endl;
    return;
}

void PTEFormat::Dump()
{
    using std::cout;
    using std::endl;
    cout << "-------PTE Format Details------" << endl;
    for (PTEFormatMap::iterator itr = format_map_.begin(); itr != format_map_.end(); ++itr)
    {
        cout << "Bit Field Name : [" << itr->first << "]  Position: [" << itr->second.first << "," << itr->second.second
             << "]" << endl;
    }
    return;
}

} // namespace mm
} // namespace etiss
