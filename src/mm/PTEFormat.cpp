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
