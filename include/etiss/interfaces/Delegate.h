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
#ifndef ETISS_INTERFACES_DELEGATE_H
#define ETISS_INTERFACES_DELEGATE_H

#include "etiss/Misc.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/System.h"

namespace etiss
{
namespace interfaces
{

template <typename T, unsigned align>
CONSTEXPR T swapBitOrder(T t);

template <>
CONSTEXPR uint32_t swapBitOrder<uint32_t, 4>(uint32_t t)
{
    return ((((((t & 0xaaaaaaaa) >> 1) | ((t & 0x55555555) << 1)) & 0xcccccccc) >> 2) |
            (((((t & 0xaaaaaaaa) >> 1) | ((t & 0x55555555) << 1)) & 0x33333333)
             << 2)); // heavily requires compiler optimization. cannot be implemented smarter since a constexpr function
                     // may only have a return statement
}

class Delegate
{
  private:
    ETISS_System &system;
    ETISS_CPU &cpu;

  public:
    Delegate(ETISS_System &system, ETISS_CPU &cpu);

    void syncTime(uint64_t time_ps);

    /**
            handles read operations. the time value will be increased by the time spend by the bus
    */
    etiss::int32 read(bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, unsigned len);

    /**
            handles write operations. the time value will be increased by the time spend by the bus
    */
    etiss::int32 write(bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, unsigned len);

  private:
  public:
    /// if valid then this function will be called by read() instead of performing any action itself
    std::function<etiss::int32(bool /*ibus*/, uint64_t & /*time_ps*/, uint64_t /*addr*/, uint8_t * /*buf*/,
                               unsigned /*len*/, bool & /*continue*/, bool & /*handleNormal*/)>
        injectedRead;
    std::function<etiss::int32(bool /*ibus*/, uint64_t & /*time_ps*/, uint64_t /*addr*/, uint8_t * /*buf*/,
                               unsigned /*len*/, bool & /*continue*/, bool & /*handleNormal*/)>
        redirectedWrite;

    std::function<void(bool injected, const uint64_t &time_ps, uint64_t addr, const uint8_t *buf, unsigned len)>
        snoopRead;
};

template <typename T, bool (Delegate::*rwop)(bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, unsigned len),
          unsigned bytewidth, bool swapBitOrder_ = false>
/**
    this function handles read writes in case of busses that have a fixed output with and a select signal like e.g. a
   wishbone bus
*/
bool sel_rwop(Delegate &delg, bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, T sel_i)
{
    static_assert(std::is_integral<T>::value, "sel_rwop needs an integral type for the select signal");
    static_assert(bytewidth > 0, "bytewidth cannot be 0");
    if (unlikely(sel_i == 0))
    {
        return (delg.*rwop)(ibus, time_ps, addr, buf, 0);
    }
    // if (swapBitOrder_)
    // sel_i = swapBitOrder<T,bytewidth>(sel_i);
    // handle common cases quickly
    if (likely(sel_i == ((1 << bytewidth) - 1)))
    { // all bits are selected
        return (delg.*rwop)(ibus, time_ps, addr, buf, bytewidth);
    }
    else
    {
        // std::cout << "sel_i = " << sel_i << std::endl;
        if (!swapBitOrder_)
        { // guessing common values
            if ((sel_i == ((1 << (bytewidth >> 1)) - 1)) && (bytewidth > 1))
            { // halve of the bits are selected
                return (delg.*rwop)(ibus, time_ps, addr, buf, bytewidth >> 1);
            }
            else if ((sel_i == ((1 << (bytewidth >> 2)) - 1)) && (bytewidth > 3))
            { // one bit is selected
                return (delg.*rwop)(ibus, time_ps, addr, buf, bytewidth >> 2);
            }
        }
        else
        {
            if ((sel_i == ((1 << (bytewidth >> 1)) - 1)) && (bytewidth > 1))
            { // halve of the bits are selected
                return (delg.*rwop)(ibus, time_ps, addr, buf, bytewidth >> 1);
            }
            else if ((sel_i == ((1 << (bytewidth >> 2)) - 1)) && (bytewidth > 3))
            {
                return (delg.*rwop)(ibus, time_ps, addr, buf, bytewidth >> 2);
            }
        }
    }
    etiss::log(etiss::FATALERROR, "not implemented", ETISS_SRCLOC, sel_i);
    return false;
}

template <typename T>
class SimpleInstructionInjector
{
    static_assert(std::is_pod<T>::value, "SimpleInstructionInjector<T> requires T to be a pod type");

  public:
    SimpleInstructionInjector(bool useRefetchCompensation = true)
        : logInjectionAddresses_(false), useRefetchCompensation_(useRefetchCompensation)
    {
    }

    void append(T val) { buffer.push_back(val); }

    template <class InputIt>
    void append(InputIt first, InputIt last)
    {
        buffer.insert(buffer.end(), first, last);
    }

    /** \brief Adds a function with an unique ID to the SimpleInstructionInjector
     *
     * \param ID of the added function.
     * \param Function pointer of the function to add.
     */
    void setHelper(unsigned index, std::function<std::list<T>(T)> func)
    {
        genHelpers.insert(std::make_pair(index, func));
    }

    bool appendWithHelper(unsigned helper, T val)
    {
        auto fnc = genHelpers.find(helper);
        if (fnc == genHelpers.end())
            return false;

        std::list<T> tmp = fnc->second(val);

        append(tmp.begin(), tmp.end());

        return true;
    }

    void appendRepetitions(unsigned count)
    {
        std::list<T> oldbuf = buffer;
        for (unsigned i = 0; i < count; i++)
        {
            buffer.insert(buffer.end(), oldbuf.begin(), oldbuf.end());
        }
    }

    /**
            @attention the returned function uses the internal buffer of this object
    */
    std::function<etiss::int32(bool, uint64_t &, uint64_t, uint8_t *, unsigned, bool &, bool &)> toFunction()
    {
        std::map<uint64_t, T> refetchcompensation;
        return [refetchcompensation, this](bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, unsigned len,
                                           bool &continu, bool &handleNormal) mutable {
            continu = true;
            handleNormal = false;

            if (!ibus)
            {
                handleNormal = true;
                return etiss::RETURNCODE::GENERALERROR; // X Read bus can not handle instruction injection.
            }

            if (len != sizeof(T))
            {
                etiss::log(etiss::ERROR,
                           "SimpleInstructionInjector detected an instruction read access of invalid length");
                return etiss::RETURNCODE::IBUS_READ_ERROR;
            }

            // if data is fetched from the same address again then inject the same data again
            // is a size limited form of this compensation usefull? e.g. execute from address 4,8,12,16,4 where the
            // instructions at address 4 should differ -> size limit needs to be 3
            if (useRefetchCompensation_)
            {
                auto refetch = refetchcompensation.find(addr);
                if (refetch != refetchcompensation.end())
                {
                    *((T *)buf) = refetch->second;
                    return etiss::RETURNCODE::NOERROR;
                }
            }

            // note the injected sequence must guarantee that there is no refetch that
            // would require instructions from this function. in case of an or1k
            // processor this can be achieved by adding l.nop operations at the end
            if (buffer.size() == 0)
            {
                continu = false;
                handleNormal = true;
                return etiss::RETURNCODE::IBUS_READ_ERROR; // X
            }

            *((T *)buf) = buffer.front();
            if (useRefetchCompensation_)
                refetchcompensation.insert(std::pair<uint64_t, T>(addr, buffer.front()));
            buffer.pop_front();

            continu = buffer.size() != 0;

            if (logInjectionAddresses_)
            {
                // std::cout << "push_back(0x" << std::hex << addr << std::dec << ")" << std::endl;
                injectionAddresses_.push_back(addr);
            }

            // std::cout << "Pending: " << buffer.size() << std::endl;

            return etiss::RETURNCODE::NOERROR;
        };
    }

    /**
            swaps the endianness of all stored buffer values
    */
    void swapEndianness()
    {
        for (auto iter = buffer.begin(); iter != buffer.end(); iter++)
        {
            T tmp = *iter;
            for (size_t i = 0; i < (sizeof(T) >> 1); i++)
            {
                ((char *)&(*iter))[i] = ((char *)&tmp)[sizeof(T) - 1 - i];
                ((char *)&(*iter))[sizeof(T) - 1 - i] = ((char *)&tmp)[i];
            }
        }
    }

    inline bool injectionFinished() { return buffer.empty(); }

    inline bool logInjectionAddresses() { return logInjectionAddresses_; }
    inline void logInjectionAddresses(bool val) { logInjectionAddresses_ = val; }
    inline std::list<uint64_t> &injectionAddresses() { return injectionAddresses_; }

  private:
    std::list<T> buffer;

    std::map<unsigned, std::function<std::list<T>(T)>> genHelpers;

    bool logInjectionAddresses_;
    bool useRefetchCompensation_;
    std::list<uint64_t> injectionAddresses_;
};

} // namespace interfaces
} // namespace etiss

#endif // ETISS_INTERFACES_DELEGATE_H
