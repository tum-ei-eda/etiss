// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef REFCOUNTEDOBJECT_H_INCLUDED
#define REFCOUNTEDOBJECT_H_INCLUDED

#include "etiss/Misc.h"
#include <type_traits>

namespace etiss
{

template <typename allocatorT = void>
class RefCountedObject;

// declare templated access functions
template <typename T, typename allocatorT>
///@return true if the object has no mor references.
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT>, T>::value, bool>::type helper_decRef(
    T *ptr);
template <typename T, typename allocatorT>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT>, T>::value, void>::type helper_incRef(
    T *ptr);

template <typename T, typename allocatorT>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT>, T>::value, allocatorT *&>::type
helper_allocator_ptr_ref(T *ptr);

template <typename allocatorT>
/// base refcount class
class RefCountedObject
{
    template <typename T_, typename allocatorT_>
    friend typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT_>, T_>::value, bool>::type
    helper_decRef(T_ *ptr);
    template <typename T_, typename allocatorT_>
    friend typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT_>, T_>::value, void>::type
    helper_incRef(T_ *ptr);
    template <typename T_, typename allocatorT_>
    friend
        typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT_>, T_>::value, allocatorT_ *&>::type
        helper_allocator_ptr_ref(T_ *ptr);

  public:
    typedef allocatorT refcount_allocatorT;
    inline RefCountedObject() : refcount(0), allocator(0) {}
    inline RefCountedObject(const RefCountedObject &cpy) : refcount(0), allocator(0) {}
    inline RefCountedObject(RefCountedObject &&cpy) : refcount(0), allocator(0) {}
    inline virtual ~RefCountedObject() {}

  private:
    mutable size_t refcount;
    mutable allocatorT *allocator;
};

template <typename T, typename allocatorT>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT>, T>::value, bool>::type helper_decRef(
    T *ptr)
{
    if (unlikely(ptr == 0))
        return false;
#if DEBUG
    if (ptr->refcount == 0)
        throw std::bad_alloc();
#endif
    ptr->refcount--;
    return ptr->refcount == 0;
}
template <typename T, typename allocatorT>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT>, T>::value, void>::type helper_incRef(
    T *ptr)
{
    if (unlikely(ptr == 0))
        return;
#if DEBUG
    if (ptr->refcount + 1 < ptr->refcount)
        throw std::runtime_error("reference counting failed (overflow)");
#endif
    ptr->refcount++;
}
template <typename T, typename allocatorT>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<allocatorT>, T>::value, allocatorT *&>::type
helper_allocator_ptr_ref(T *ptr)
{
    return ptr->allocator;
}

template <typename T>
/// @attention for now this function mapps directly to helper_incRef. for future more complex management scenarios this
/// might need to change
inline void incRef(T *ptr)
{
    helper_incRef<T, typename T::refcount_allocatorT>(ptr);
}

template <typename T>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<void>, T>::value, bool>::type decRef(T *ptr)
{
    bool ret = helper_decRef<T, void>(ptr);
    if (unlikely(ret))
    {
        delete ptr;
        ptr = 0;
    }
    return ret;
}

} // namespace etiss

#endif // REFCOUNTEDOBJECT_H_INCLUDED
