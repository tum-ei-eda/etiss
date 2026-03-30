// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief


*/
#ifndef ETISS_ERRORDEFINITION_H_
#define ETISS_ERRORDEFINITION_H_
#include "etiss/Misc.h"
#include <iostream>
#include <string>
#include <vector>

#if defined(__GXX_EXPERIMENTAL_CXX0X) || __cplusplus >= 201103L // check if c++0x/c++11 is supported
#define ETISS_USE_CPP11 1
#else
#define ETISS_USE_CPP11 0
#endif

namespace etiss
{

namespace error
{

/**
    base error class for simple handling of errors
    @attention any class is required to implement virtual void apply(uint64_t & var) AND provide a templated function
   template<typename T> fapply(T & var) that applies the error.
    @attention currently no variable largt than uint64_t can be used
*/
class Error
{
  public:
    const bool persistent_;
    int id_;
    std::string name_;
    /**
        @param id if id is negative the a new negative id from a global id pool will be used. the pool may assign the
       same id if the total number of error instances during progam execution exceds 2^(sizeof(int)*8-1)
    */
    Error(bool persistent, int id = -1, const std::string &name = "");
    virtual ~Error();
    virtual void apply(uint64_t &var) = 0;
    virtual void apply(uint32_t &var);
    virtual void apply(uint16_t &var);
    virtual void apply(uint8_t &var);
    virtual const std::vector<unsigned> affectedBits() = 0;
};

class BitFlip : public Error
{
  private:
    std::vector<unsigned> flipped_positions;
    uint64_t flip;

  public:
    template <typename iterateableT>
    BitFlip(const iterateableT &positions, int id = -1, const std::string &name = "") : Error(false, id, name)
    {
        flip = 0;
        flipped_positions.resize(positions.size());
        for (typename iterateableT::const_iterator iter = positions.begin(); iter != positions.end(); ++iter)
        {
            flipped_positions.push_back(*iter);
            flip |= 1 << (*iter);
        }
    }

    virtual void apply(uint64_t &var);

    template <typename T>
    inline void fapply(T &var)
    {
        var = (T)(var ^ flip);
    }

    virtual const std::vector<unsigned> affectedBits();
};

class StuckHigh : public Error
{
  private:
    std::vector<unsigned> high_positions;
    uint64_t high;

  public:
    template <typename iterateableT>
    StuckHigh(const iterateableT &positions, int id = -1, const std::string &name = "") : Error(true, id, name)
    {
        high = 0;
        high_positions.resize(positions.size());
        for (typename iterateableT::const_iterator iter = positions.begin(); iter != positions.end(); ++iter)
        {
            high_positions.push_back(*iter);
            high |= 1 << (*iter);
        }
    }

    virtual void apply(uint64_t &var);

    template <typename T>
    inline void fapply(T &var)
    {
        var = (T)(var | high);
    }

    virtual const std::vector<unsigned> affectedBits();
};

class StuckLow : public Error
{
  private:
    std::vector<unsigned> low_positions;
    uint64_t low;

  public:
    template <typename iterateableT>
    StuckLow(const iterateableT &positions, int id = -1, const std::string &name = "") : Error(true, id, name)
    {
        low = 0;
        low_positions.resize(positions.size());
        for (typename iterateableT::const_iterator iter = positions.begin(); iter != positions.end(); ++iter)
        {
            low_positions.push_back(*iter);
            low |= 1 << (*iter);
        }
        low = ~low;
    }

    virtual void apply(uint64_t &var);

    template <typename T>
    inline void fapply(T &var)
    {
        var = (T)(var & low);
    }

    virtual const std::vector<unsigned> affectedBits();
};

} // namespace error

} // namespace etiss

#endif // ETISS_ERRORDEFINITION_H_
