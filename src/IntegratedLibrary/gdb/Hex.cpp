// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/gdb/Hex.h

        @detail

*/
#include "etiss/IntegratedLibrary/gdb/Hex.h"

using namespace etiss::plugin::gdb::hex;

uint8_t etiss::plugin::gdb::hex::fromHex(char c)
{
    if (c <= '9' && c >= '0')
    {
        return (uint8_t)(c - '0');
    }
    else if (c <= 'f' && c >= 'a')
    {
        return (uint8_t)(c - 'a' + 10);
    }
    else if (c <= 'F' && c >= 'A')
    {
        return (uint8_t)(c - 'A' + 10);
    }
    else
    {
        return 16;
    }
}
char etiss::plugin::gdb::hex::toHex(uint8_t l)
{
    if (l < 10)
    {
        return '0' + (char)l;
    }
    else if (l < 16)
    {
        return 'A' + (char)l - 10;
    }
    else
    {
        return '?';
    }
}

uint8_t etiss::plugin::gdb::hex::toByte(std::string hex, size_t pos)
{
    return toByte(hex[pos], hex[pos + 1]);
}
uint8_t etiss::plugin::gdb::hex::toByte(char h, char l)
{
    return fromHex(h) << 4 | fromHex(l);
}

std::string etiss::plugin::gdb::hex::fromByte(uint8_t byte)
{
    std::string ret = "  ";
    ret[0] = toHex(byte >> 4);
    ret[1] = toHex(byte & 0x0F);
    return ret;
}

void etiss::plugin::gdb::hex::fromByte(std::string &append, uint8_t byte)
{
    append.push_back(toHex(byte >> 4));
    append.push_back(toHex(byte & 0x0F));
}

std::string etiss::plugin::gdb::hex::fromBytes(uint8_t *buf, size_t length)
{
    std::string ret;
    ret.resize(length * 2);
    for (unsigned i = 0; i < length; i++)
    {
        ret[i * 2] = toHex(buf[i] >> 4);
        ret[i * 2 + 1] = toHex(buf[i] & 0x0F);
    }
    return ret;
}
