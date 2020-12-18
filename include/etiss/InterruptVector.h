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

        @date July 28, 2014

        @version 0.1

*/
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
