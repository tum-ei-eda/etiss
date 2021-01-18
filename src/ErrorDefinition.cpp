/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "etiss/ErrorDefinition.h"

#if ETISS_USE_CPP11
#include <mutex>
#endif

namespace etiss
{

namespace error
{

namespace
{

int getGlobalId()
{
    static int cur = -1;
#if ETISS_USE_CPP11
    static std::mutex id_lock;
    std::lock_guard<std::mutex> lock(id_lock);
#endif
    int ret = cur;
    --cur;
    if (cur >= 0)
    {
        std::cerr << "\n\nWARNING: etiss::error::Error ran out of ids. From now on negative ids may be assigned "
                     "multiple times.\n\n"
                  << std::endl;
        cur = -1;
    }
    return ret;
}

} // namespace

Error::Error(bool persistent, int id, const std::string &name)
    : persistent_(persistent), id_(id < 0 ? getGlobalId() : id), name_(name)
{
}
Error::~Error() {}

void Error::apply(uint32_t &var)
{
    uint64_t tmp = var;
    apply(tmp);
    var = (uint32_t)tmp;
}
void Error::apply(uint16_t &var)
{
    uint64_t tmp = var;
    apply(tmp);
    var = (uint16_t)tmp;
}
void Error::apply(uint8_t &var)
{
    uint64_t tmp = var;
    apply(tmp);
    var = (uint8_t)tmp;
}

void BitFlip::apply(uint64_t &var)
{
    var ^= flip;
}
void StuckHigh::apply(uint64_t &var)
{
    var |= high;
}
void StuckLow::apply(uint64_t &var)
{
    var &= low;
}

const std::vector<unsigned> BitFlip::affectedBits()
{
    return flipped_positions;
}
const std::vector<unsigned> StuckHigh::affectedBits()
{
    return high_positions;
}
const std::vector<unsigned> StuckLow::affectedBits()
{
    return low_positions;
}

} // namespace error

} // namespace etiss
