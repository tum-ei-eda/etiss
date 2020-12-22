/*

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

        @version 0.1

*/

#ifndef FIXEDSIZEHASHTABLE_H_INCLUDED
#define FIXEDSIZEHASHTABLE_H_INCLUDED

#include <functional>
#include "etiss/ObjectPool.h"
#include <functional>

namespace etiss
{

CONSTEXPR size_t set_lsbs(size_t val)
{
    return val ? ((set_lsbs(val - 1) << 1) | 1) : 0;
}

template <typename K>
struct pointerHash
{
    size_t inline operator()(const K *const &k_) const
    {
        intptr_t k = (intptr_t)k_;
        if (sizeof(intptr_t) > 4)
        {
// disable wrong warning
#ifdef _MSC_VER
#pragma warning(suppress : 4293)
#endif
            k = k + (k >> 32);
        }
        k = k + (k >> 16);
        return (size_t)k;
    }
};

template <typename K, typename V, typename hashFunc = typename std::hash<K>, size_t log2_buckets = 16>
class FixedSizeHashMap
{
  private:
    class Entry
    {
      public:
        Entry() = delete;
        Entry(const K &key, const V &val) : key(key), val(val), next(0) {}
        Entry(const Entry &) = delete;
        Entry(Entry &&) = delete;
        Entry &operator=(const Entry &) = delete;
        Entry &operator=(Entry &&) = delete;
        K key;
        V val;
        Entry *next;
    };
    etiss::ObjectPool<Entry> pool;
    Entry *map[1 << log2_buckets];
    hashFunc hash;

  public:
    FixedSizeHashMap()
    {
        for (size_t i = 0; i < (1 << log2_buckets); i++)
        {
            map[i] = 0;
        }
        // memset(map,0,sizeof(Entry*)*(1<<log2_buckets));
    }
    ~FixedSizeHashMap()
    {
        for (size_t i = 0; i < (1 << log2_buckets); i++)
        {
            if (map[i])
            {
                Entry *del = map[i];
                do
                {
                    pool.destroy(del);
                    pool.deallocate(del);
                    Entry *n = del->next;
                    del = n;
                } while (del);
            }
        }
    }
    etiss_del_como(FixedSizeHashMap) V *insert(const K &key, const V &val)
    {
#if DEBUG
        size_t bucket_size = 0;
#endif
        size_t hk = hash(key);
        Entry **ptr = &(map[hk & set_lsbs(log2_buckets)]);
        // check if key exists
        {
            while (*ptr)
            {
                if ((*ptr)->key == key)
                {
                    (*ptr)->val = val;
                    return &(*ptr)->val;
                }
                ptr = &(*ptr)->next;
#if DEBUG
                bucket_size++;
#endif
            }
        }
        // add new key
        {
            *ptr = pool.allocate(1);
            pool.construct(*ptr, key, val);
        }
#if DEBUG
        bucket_size++;
        if (bucket_size > 2)
        {
            etiss::log(etiss::VERBOSE, "Large bucket size detected.");
        }
#endif
        return &(*ptr)->val;
    }
    void erase(const K &key)
    {
        size_t hk = hash(key);
        Entry **ptr = &(map[hk & set_lsbs(log2_buckets)]);
        // check if key exists
        {
            while (*ptr)
            {
                if ((*ptr)->key == key)
                {
                    Entry *del = *ptr;
                    *ptr = (*ptr)->next; // link to next element
                    pool.destroy(del);
                    pool.deallocate(del);
                    return;
                }
                ptr = &(*ptr)->next;
            }
        }
    }
    V *find(const K &key)
    {
        size_t hk = hash(key);
        Entry **ptr = &(map[hk & set_lsbs(log2_buckets)]);
        while (*ptr)
        {
            if ((*ptr)->key == key)
            {
                return &(*ptr)->val;
            }
            ptr = &(*ptr)->next;
        }
        return 0;
    }
    const V *find(const K &key) const
    {
        size_t hk = hash(key);
        Entry *const *ptr = &(map[hk & set_lsbs(log2_buckets)]);
        while (*ptr)
        {
            if ((*ptr)->key == key)
            {
                return &(*ptr)->val;
            }
            ptr = &(*ptr)->next;
        }
        return 0;
    }
};

} // namespace etiss

#endif // FIXEDSIZEHASHTABLE_H_INCLUDED
