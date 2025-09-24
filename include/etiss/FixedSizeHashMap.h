// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
