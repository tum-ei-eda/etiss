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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date September 2, 2014

        @version 0.1

*/
/**
        @file

        @brief

        @detail




*/

#ifndef ETISS_INCLUDE_GDB_HEX_H_
#define ETISS_INCLUDE_GDB_HEX_H_

#include "etiss/jit/types.h"

#include <iostream>
#include <string>

namespace etiss
{

namespace plugin
{

namespace gdb
{

namespace hex
{

/**
        @brief convert a character to the hex value it represents(0-15)
        @param c hex repesentation 0-9,a-f,A-F
        @return represented hex value or 16 if invalid character
*/
extern uint8_t fromHex(char c);
/**
        @brief converts the lower 4 bits to a representing char
        @param l whose lower 4 bits are used. higher bits may not be set
        @return character 0-9,A-F or '?' if l > 15
*/
extern char toHex(uint8_t l);

/**
        @brief converts 2 hex characters to a byte
        @brief h character representing higher 4 bits; may not be invalid
        @brief l character representing lower 4 bits; may not be invalid
        @return represented value
*/
extern uint8_t toByte(char h, char l);
/**
        @brief converts 2 characters from a hex string to one byte
        @param hex string representing a hex value. must be longer than pos+1
        @param pos start position of the hex representation
*/
extern uint8_t toByte(std::string hex, unsigned pos = 0);

/**
        @brief converts a byte to a hex string (without "0x" prefix);
        @param byte
        @return a string of length 2 representing the passed byte in hex
*/
extern std::string fromByte(uint8_t byte);
/**
        @brief converts a byte to hexadecimal representation and appends it to the passed string
        @param append
        @param byte
*/
extern void fromByte(std::string &append, uint8_t byte);

/**
        @brief converts a sequence of bytes to a representing hex string (without "0x" prefix)
        @param buf
        @param length
        @return hex representation of the passed byte sequence
*/
extern std::string fromBytes(uint8_t *buf, unsigned length);

template <typename INT>
/**
        @brief converts an integer type variable to a hexadecimal representation with the given endianness
        @param string the string where hex characters will be appended
        @param val interger value to convert
        @param isLittleEndian true for little endian hex representaion, false for big endian
*/
void fromInt(std::string &string, INT val, bool isLittleEndian)
{
    for (size_t i = 0; i < sizeof(INT); i++)
    {
        fromByte(string, (uint8_t)(val >> (isLittleEndian ? (i * 8) : ((sizeof(INT) - i - 1) * 8))));
    }
}

template <typename INT>
/**
        @brief convert a string of length (pos + sizeof(INT)) or larger to the represented value. no error checking will
   be performed
*/
INT toInt(const std::string &string, bool isLittleEndian, unsigned pos = 0)
{
    INT ret = 0;
    for (size_t i = 0; i < sizeof(INT); i++)
    {
        ret |= ((((INT)toByte(string, pos + i * 2)) & ((INT)0xFF))
                << (isLittleEndian ? (i * 8) : ((sizeof(INT) - i - 1) * 8)));
    }
    return ret;
}
template <typename INT>
/**
        @brief parses a hex string and returns the result. the string will be parsed until the end is reached, an
   invalid character was encountered or maxlength was reached. this function cannot handle a "0x" prefix
        @param string string to parse;
        @param pos current position in the string. will be set to the index of the first character that was not part of
   the returned value
        @param maxlength maximum parse length in characters (may be uneven)
*/
INT tryInt(std::string &string, unsigned &pos, unsigned maxlength = sizeof(INT) * 2)
{
    INT ret = 0;
    unsigned opos = pos;
    while (string.length() > pos && pos - opos < maxlength)
    {
        uint8_t hb = fromHex(string[pos]);
        if (hb >= 16) // invalid character
            return ret;
        ret = (ret << 4) | hb;
        pos++;
    }
    return ret;
}
} // namespace hex

} // namespace gdb

} // namespace plugin

} // namespace etiss

#endif
