// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief defines a general interface to set interrupt bits

        @detail

*/

#ifndef ETISS_INCLUDE_INTERRUPTVECTOR_H_
#define ETISS_INCLUDE_INTERRUPTVECTOR_H_

#include "etiss/Misc.h"
#include "etiss/jit/types.h"
#include <list>
#include <mutex>
#include <set>
#include <vector>

namespace etiss
{

/**
        @brief interface to set interrupt bits
*/
class InterruptVector
{
  public:
    virtual ~InterruptVector();
    /**
            @brief set the bit of an interrupt line to state (true = raised)
    */
    virtual void setBit(unsigned bit, bool state) = 0;
    /**
            @brief get the bit of an interrupt line
    */
    virtual bool getBit(unsigned bit) const = 0;
    /**
            @brief number of interrupt bits
    */
    virtual unsigned width() const = 0;
    /**
            @return true if any bit is set to true
    */
    virtual bool isActive() const;
    /**
            @brief sets every bit to false
    */
    virtual void clear();

    bool consumed_by_interruptlistener_{ false };
};

template <typename INT>
/**
        @brief template implementation of an InterruptVector that uses integer variables to store interrupt bit values
   and to read interrupt masks. this implementaion should work with most cpu architecture implementations.
*/
class MappedInterruptVector : public InterruptVector
{
  public:
    typedef typename std::vector<INT *> Vector;
    /**
            @brief pass two equally long integer pointer vectors that will be used for interrupt bit vectors and masks
    */
    MappedInterruptVector(Vector vec, Vector mask) : vector_(vec), mask_(mask)
    {
        if (vector_.size() > mask.size())
        {
            vector_.resize(mask.size());
            etiss::log(etiss::ERROR, "MappedInterruptVector: the interrupt and mask vectors must have equal size.");
        }
        if (vector_.size() < mask.size())
        {
            mask.resize(vector_.size());
            etiss::log(etiss::ERROR, "MappedInterruptVector: the interrupt and mask vectors must have equal size.");
        }
    }
    virtual ~MappedInterruptVector() {}
    virtual void setBit(unsigned bit, bool state)
    {
        unsigned o = bit % (sizeof(INT) * 8);
        unsigned i = (bit - o) / (sizeof(INT) * 8);
        if (i < vector_.size())
        {
            INT mask = ((INT)1) << o;
            *vector_[i] = (*vector_[i] & ~mask) | (state ? mask : 0);
        }
        //                        std::cout << "etiss::InterruptVector::setBit called i=" << std::dec << i << "
        //                        vector[i]=" << std::hex << *vector_[i] << " mask[i]=" << *mask_[i] << std::dec <<
        //                        std::endl;
    }
    virtual bool getBit(unsigned bit) const
    {
        unsigned o = bit % (sizeof(INT) * 8);
        unsigned i = (bit - o) / (sizeof(INT) * 8);
        INT mask = ((INT)1) << o;
        if (i < vector_.size())
        {
            return ((*vector_[i] & mask) & (*mask_[i] & mask)) != 0;
        }
        return false;
    }
    virtual unsigned width() const { return (unsigned)vector_.size() * sizeof(INT); }
    virtual bool isActive() const
    {
        for (unsigned i = 0; i < vector_.size(); i++)
        {
            if (*vector_[i] & *mask_[i])
                return true;
        }
        return false;
    }
    virtual void clear()
    {
        for (unsigned i = 0; i < vector_.size(); i++)
        {
            *vector_[i] = (INT)0;
        }
    }

  private:
    Vector vector_;
    Vector mask_;
};

} // namespace etiss

#endif
