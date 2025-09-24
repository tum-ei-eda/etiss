// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
