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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#ifndef ETISS_FASTSTRING_H_
#define ETISS_FASTSTRING_H_

#include <inttypes.h>
#include <cstdlib>
#include <type_traits>
#if ETISS
#include "etiss/Misc.h"
#endif

namespace etiss
{

namespace string
{

template <unsigned maxlen_plus1>
/**

*/
void strcpy(char *dst, const char *src)
{
    size_t pos = 0;
    while (pos < maxlen_plus1)
    {
        const char sc = src[pos];
        if (unlikely(sc == 0))
            break;
        dst[pos++] = sc;
    }
    dst[pos] = 0;
}

/**
    @attention this function relies on spaces being an acceptable fill character
   in case of field/input length missmatch
*/
class form_string
{
  private:
    char *buffer;
    size_t size;
    std::vector<std::pair<size_t, size_t>> fields; ///< list of field in the form_string. (offset,length) pairs

  private:
    /// terminates template recursion
    size_t char_size(unsigned, size_t *, bool *) { return 0; }
    template <typename... O>
    size_t char_size(unsigned pos, size_t *size, bool *isPlaceholder, const char *s, O... others)
    {
        size[pos] = strlen(s);
        isPlaceholder[pos] = false;
        return size[pos] + char_size(pos + 1, size, isPlaceholder, others...);
    }
    template <typename... O>
    size_t char_size(unsigned pos, size_t *size, bool *isPlaceholder, size_t len, O... others)
    {
        size[pos] = len;
        isPlaceholder[pos] = true;
        return size[pos] + char_size(pos + 1, size, isPlaceholder, others...);
    }

  private:
    ///  terminates template recursion
    void char_copy(unsigned, char *, size_t *) {}
    template <typename... O>
    void char_copy(unsigned pos, char *buf, size_t *size, const char *s, O... others)
    {
        memcpy(buf, s, size[pos]); // copy string
        char_copy(pos + 1, buf + size[pos], size, others...);
    }
    template <typename... O>
    void char_copy(unsigned pos, char *buf, size_t *size, size_t /*ignored*/, O... others)
    {
        memset(buf, ' ', size[pos]); // fill with spaces (keep string valid)
        char_copy(pos + 1, buf + size[pos], size, others...);
    }

  public:
    template <typename... T>
    form_string(T... str)
    {

        size_t element[sizeof...(str)];
        bool placeholder[sizeof...(str)];
        size_t total = char_size(0, element, placeholder, str...); // calculate total length

        buffer = new char[total + 1]; // allocate buffer
        size = total;

        char_copy(0, buffer, element, str...); // copy strings, fill placeholders with ' '

        buffer[size] = 0; // terminating 0

        size_t offset = 0;
        for (size_t i = 0; i < sizeof...(str); i++)
        {
            if (placeholder[i])
            {                                                         // placeholder field
                fields.push_back(std::make_pair(offset, element[i])); // store offset and length
            }
            offset = offset + element[i];
        }
    }

    template <typename T>
    std::enable_if<std::is_integral<T>::value, void> write_dec(unsigned field, T value)
    {
        std::pair<size_t, size_t> f = fields[field];
        size_t pos = f.first + f.second;
        do
        {
#if DEBUG
            if (pos < f.first)
            {
#if ETISS
                etiss::log(etiss::FATALERROR, "out of range buffer operation", ETISS_SRCLOC);
#else
                std::cerr << "out of range buffer operation" << std::endl;
                abort();
#endif
            }
#endif
            T tmp = value / 10;
            char c = (char)(value % 10); // the compiler should detect the division and use the remainder here without
                                         // calculating modulo
            value = tmp;
            buffer[pos] = '0' + c;
            pos--;
        } while (value);
        while (pos >= f.first)
        {
            buffer[pos] = ' ';
        }
    }

    inline void write(unsigned field, const char *buf, size_t length)
    {
        auto f = fields[field];
#if DEBUG
        if (length > f.second)
        {
#if ETISS
            etiss::log(etiss::FATALERROR, "out of range buffer operation", ETISS_SRCLOC);
#else
            std::cerr << "out of range buffer operation" << std::endl;
            abort();
#endif
        }
#endif
        memcpy(buffer + f.first, buf, length);
        memset(buffer + f.first, ' ', f.second - length);
    }
    inline void writet(unsigned field, const char *buf, size_t length, char terminator = ' ', char fill = ' ')
    {
        auto f = fields[field];
#if DEBUG
        if (length + 2 > f.second)
        {
#if ETISS
            etiss::log(etiss::FATALERROR, "out of range buffer operation", ETISS_SRCLOC);
#else
            std::cerr << "out of range buffer operation" << std::endl;
            abort();
#endif
        }
#endif
        memcpy(buffer + f.first, buf, length);
        buffer[f.first + length] = terminator;
        memset(buffer + f.first + length + 1, fill, f.second - length - 1);
    }

    inline char *c_str() { return buffer; }
    inline const char *c_str() const { return buffer; }
};

std::ostream &operator<<(std::ostream &os, const form_string &fs)
{
    os << fs.c_str();
    return os;
}

} // namespace string

} // namespace etiss

#endif // ETISS_FASTSTRING_H_
