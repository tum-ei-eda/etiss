// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef MAKE_UNIQUE_H
#define MAKE_UNIQUE_H

#if (!defined(_MSC_VER) && __cplusplus < 201402L)
// std::make_unique reference implementation for linux c++11 mode compilers

#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>

namespace std
{
template <class T>
struct _Unique_if
{
    typedef unique_ptr<T> _Single_object;
};

template <class T>
struct _Unique_if<T[]>
{
    typedef unique_ptr<T[]> _Unknown_bound;
};

template <class T, size_t N>
struct _Unique_if<T[N]>
{
    typedef void _Known_bound;
};

template <class T, class... Args>
typename _Unique_if<T>::_Single_object make_unique(Args &&...args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <class T>
typename _Unique_if<T>::_Unknown_bound make_unique(size_t n)
{
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T>(new U[n]());
}

template <class T, class... Args>
typename _Unique_if<T>::_Known_bound make_unique(Args &&...) = delete;
} // namespace std

#endif

#endif
