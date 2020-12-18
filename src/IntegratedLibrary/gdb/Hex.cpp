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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
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
