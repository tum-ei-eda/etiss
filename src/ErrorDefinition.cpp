// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
