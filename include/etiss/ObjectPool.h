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

        @date November 21, 2014

        @version 0.4

*/
/**
        @file

        @brief

        @detail

*/
#ifndef ETISS_OBJECTPOOL_H_
#define ETISS_OBJECTPOOL_H_

#include "etiss/Misc.h"
#include "etiss/RefCountedObject.h"

#include <cstring>

#define ETISS_OBJECTPOOL_LOGSIZE 1
#define ETISS_OBJECTPOOL_DBG_OBJLIMIT 0 // set to 0 to disable

namespace etiss
{

template <typename T, size_t prealloc_inc = 100>
class ObjectPool;

namespace internal
{
// functions to set a pointer from object to memory pool if object inherited
// RefCounted Object
template <typename T>
/// empty fallback function
typename std::enable_if<!std::is_base_of<etiss::RefCountedObject<ObjectPool<T>>, T>::value, void>::type
ObjectPool_setAllocatorPointer(T *obj, ObjectPool<T> *this_)
{
}
template <typename T>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<ObjectPool<T>>, T>::value, void>::type
ObjectPool_setAllocatorPointer(T *obj, ObjectPool<T> *this_)
{
    etiss::helper_allocator_ptr_ref<T, ObjectPool<T>>(obj) = this_;
}
} // namespace internal

// patch missing alignof support for msvc
#ifdef _MSC_VER
#define alignof(x) __alignof(x)
#endif
/// prealloc_inc defines the number of objects that is availabe within ObjectPools memory; default: 100
template <typename T, size_t prealloc_inc>
/**
        implements the interface of std::allocator. uses blocks of memory to speed up creation/deletion of object.
   possibly large memory consumption
*/
class ObjectPool
{
  public:
    const size_t blocksize_;

  private:
    std::set<void *> areas_;
    std::vector<void *> empty_;

  public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;

    typedef typename std::aligned_storage<sizeof(T), alignof(T)>::type storage;

  private:
    storage stackstore[prealloc_inc]; // small (fast) possibly stack allocation of the first elements
    bool stackstore_used;

  public:
    template <class Type>
    struct rebind
    {
        typedef ObjectPool<Type> other;
    };

    ObjectPool(size_t blockElementCount = 5000) : blocksize_(blockElementCount), stackstore_used(false) {}
    ObjectPool(const ObjectPool &alloc) : blocksize_(alloc.blocksize_), stackstore_used(false) {}
    template <class U>
    ObjectPool(const ObjectPool<U> &alloc) : blocksize_(alloc.blocksize_), stackstore_used(false)
    {
    }
    ~ObjectPool()
    {
        // no other cleanup must be preformed since all allocated objects are required to be destroyed prior to this
        // destruction
        for (auto iter = areas_.begin(); iter != areas_.end(); ++iter)
            if (*iter != stackstore)
                delete[](storage *)(*iter);
    }

    T *address(T &x) const { return &x; }
    const T *address(const T &x) const { return &x; }
    T *allocate(size_t n = 1, const T * = 0)
    {
        if (unlikely(n <= 0))
            throw std::bad_alloc();
        if (unlikely(n > 1)) // fall back to simple malloc call
        {
            return (T *)new storage[n];
        }
        else
        {
            if (unlikely(empty_.empty()))
            {
                if (!stackstore_used)
                {
                    stackstore_used = true;
                    for (size_t i = 0; i < prealloc_inc; ++i)
                    {
                        empty_.push_back((void *)(&(stackstore[i])));
                    }
                }
                else
                {
                    storage *area = new storage[blocksize_];
                    if (area == 0)
                        throw std::bad_alloc();
                    areas_.insert(area);
#if ETISS_OBJECTPOOL_DBG_OBJLIMIT
                    if (areas_.size() * blocksize_ > ETISS_OBJECTPOOL_DBG_OBJLIMIT)
                        throw new std::bad_alloc();
#endif
                    for (size_t i = 0; i < blocksize_; ++i)
                    {
                        empty_.push_back((void *)(&(area[i])));
                    }
#if ETISS_OBJECTPOOL_LOGSIZE
                    // etiss::log(etiss::VERBOSE,"ObjectPool increased size",areas_.size()*blocksize_+100);
#endif
                }
            }
            void *area = empty_.back();
            empty_.pop_back();
            return (T *)area;
        }
    }
    void deallocate(T *p, size_t n = 1)
    {
        if (unlikely(p == 0))
            return;
        if (unlikely(n <= 0))
            throw std::bad_alloc();
        if (unlikely(n > 1))
        {
            delete[](storage *) p;
        }
        else
        {
            empty_.push_back(p);
        }
    }
    size_t max_size() const { return (size_t)-1; }
    template <class U, class... Args>
    void construct(U *p, Args &&... args)
    {
        ::new ((void *)p) U(std::forward<Args>(args)...);
        etiss::internal::ObjectPool_setAllocatorPointer<T>((T *)p, this);
    }
    template <class U>
    void destroy(U *p)
    {
        p->~U();
    }
};

template <typename T>
typename std::enable_if<std::is_base_of<etiss::RefCountedObject<ObjectPool<T>>, T>::value, bool>::type decRef(T *ptr)
{
    bool ret = helper_decRef<T, typename T::refcount_allocatorT>(ptr);
    if (ret)
    {
        ObjectPool<T> *&pool = etiss::helper_allocator_ptr_ref<T, typename T::refcount_allocatorT>(ptr);
#if DEBUG
        if (pool == 0)
            throw std::bad_alloc();
#endif
        pool->destroy(ptr);
        pool->deallocate(ptr);
        ptr = 0;
    }
    return ret;
}

/**
    implements a stack that may only grow (if needed) and can only contain native types since no destructor / contructor
   / initialization is called. if this object is allocated on the stack heap allocations may be preventd by using the
   stackallocatedsize parameter to allocate an initial integrated storage

*/
template <typename T, size_t stackallocatedsize = 1>
class ExpandingNativeStack
{
    static_assert(std::is_pod<T>::value, "ExpandingNativeStack can only handle types without constructor/destructor. "
                                         "This cannot be fullfilled by non POD objects");

  private:
    T stackbuf_[stackallocatedsize > 0 ? stackallocatedsize : 1]; // must be >0 to conform to c++ standard
    T *stack_;
    size_t size_;
    ssize_t pos_;

  public:
    ExpandingNativeStack() : stack_(stackbuf_), size_(stackallocatedsize > 0 ? stackallocatedsize : 1), pos_(-1) {}
    ~ExpandingNativeStack()
    {
        if (stack_ != stackbuf_)
            delete stack_;
    }
    inline T operator[](ssize_t pos)
    {
#if DEBUG
        if (unlikely((pos >= size_) || pos < 0))
            etiss::log(etiss::FATALERROR, "Array index out of bounds", pos, ETISS_SRCLOC);
#endif
        return stack_[pos];
    }
    inline const T operator[](size_t pos) const
    {
#if DEBUG
        if (unlikely((pos >= size_) || pos < 0))
            etiss::log(etiss::FATALERROR, "Array index out of bounds", pos, ETISS_SRCLOC);
#endif
        return stack_[pos];
    }
    inline ssize_t pos() const { return pos_; }
    inline ssize_t size() const { return pos_ + 1; }
    inline ssize_t capacity() const { return size_; }
    inline T &back() { return stack_[pos_]; }
    inline const T &back() const { return stack_[pos_]; }
    inline T &front() { return stack_[0]; }
    inline const T &front() const { return stack_[0]; }
    inline void pop()
    {
#if DEBUG
        if (unlikely(pos_ < 0))
            etiss::log(etiss::FATALERROR, "Array index out of bounds (negative)", ETISS_SRCLOC);
#endif
        --pos_;
    }
    inline void push(T t)
    {
        if (unlikely((++pos_) == (ssize_t)size_)) // reached end of old stack
        {
            size_t new_size = size_ + 10 + (size_ / 20); // increase stack size
            T *tmp = new T[new_size];                    // allocate new stack
            memcpy(tmp, stack_, size_ * sizeof(T));      // copy old elements
            if (stack_ != stackbuf_)
                delete[] stack_;
            stack_ = tmp;
            size_ = new_size;
        }
        stack_[pos_] = t;
    }
    inline bool empty() const { return pos_ < 0; }
};

} // namespace etiss

#endif
