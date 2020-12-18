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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

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
