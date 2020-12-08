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
#ifndef ETISS_INTERFACES_WISHBONE_H
#define ETISS_INTERFACES_WISHBONE_H

#include "etiss/interfaces/Delegate.h"

#include <utility>

namespace etiss
{
namespace interfaces
{

template <typename T>
/**
        simple helper struct to trigger static_assert only if the template is instantiated
*/
struct dependent_false : std::false_type
{
};

template <typename BOOLSIG>
/**
        general helper function to read a signal; needs to be implemented as needed
*/
bool getBool(etiss::CPUCore &core, BOOLSIG &sig)
{
    static_assert(dependent_false<BOOLSIG>::value, "etiss::interfaces::getBool needs to be specialized");
    return false; // never remove static_assert above!
}

template <typename BOOLSIG>
/**
        general helper function to set a signal; needs to be implemented as needed
*/
void setBool(etiss::CPUCore &core, BOOLSIG &sig, bool val)
{
    static_assert(dependent_false<BOOLSIG>::value, "etiss::interfaces::setBool needs to be specialized");
}

template <typename VECTORSIG>
/**
        general helper function to read an address; needs to be implemented as needed
*/
uint64_t getAddr(etiss::CPUCore &core, VECTORSIG &sig, bool instrBus)
{
    static_assert(dependent_false<VECTORSIG>::value, "etiss::interfaces::getAddr needs to be specialized");
    return 0; // never remove static_assert above!
}

template <typename VECTORSIGSTORAGETYPE, typename VECTORSIG>
/**
        general helper function to read a signal; needs to be implemented as needed
*/
VECTORSIGSTORAGETYPE getData(etiss::CPUCore &core, VECTORSIG &sig)
{
    static_assert(dependent_false<VECTORSIG>::value, "etiss::interfaces::getData needs to be specialized");
    return 0; // never remove static_assert above!
}

template <typename VECTORSIGSTORAGETYPE, typename VECTORSIG>
/**
        general helper function to set a signal; needs to be implemented as needed
*/
void setData(etiss::CPUCore &core, VECTORSIG &sig, VECTORSIGSTORAGETYPE val)
{
    static_assert(dependent_false<VECTORSIG>::value, "etiss::interfaces::setData needs to be specialized");
}

/**
        general helper function to read a vector signal; needs to be implemented as needed
*/
template <typename SELSIG>
uint32_t getSel(etiss::CPUCore &core, SELSIG &sel_i)
{
    static_assert(dependent_false<SELSIG>::value, "etiss::interfaces::getSelData needs to be specialized");
    return 0;
}

template <typename BOOLSIG, typename VECTORSIG>
class WishboneSignalMap
{
  public:
    // Signals
    BOOLSIG &clk_i;
    BOOLSIG &ack_o;
    BOOLSIG &err_o;
    BOOLSIG &rty_o;
    BOOLSIG &cyc_i;
    BOOLSIG &stb_i;
    BOOLSIG &we_i;
    BOOLSIG &sel_i;
    BOOLSIG &bte_i;
    BOOLSIG &cti_i;
    VECTORSIG &dat_o;
    VECTORSIG &adr_i;
    VECTORSIG &dat_i;

  public:
    // Constructor
    WishboneSignalMap(BOOLSIG &clk_o, BOOLSIG &ack_i, BOOLSIG &err_i, BOOLSIG &rty_i, BOOLSIG &cyc_o, BOOLSIG &stb_o,
                      BOOLSIG &we_o, BOOLSIG &sel_o, BOOLSIG &bte_o, BOOLSIG &cti_o, VECTORSIG &dat_i, VECTORSIG &adr_o,
                      VECTORSIG &dat_o)
        : clk_i(clk_o)
        , ack_o(ack_i)
        , err_o(err_i)
        , rty_o(rty_i)
        , cyc_i(cyc_o)
        , stb_i(stb_o)
        , we_i(we_o)
        , sel_i(sel_o)
        , bte_i(bte_o)
        , cti_i(cti_o)
        , dat_o(dat_i)
        , adr_i(adr_o)
        , dat_i(dat_o)
    {
    }
};

template <typename BOOLSIG, typename VECTORSIG, bool instrBus, bool flipEndianess,
          unsigned bytewidth = sizeof(VECTORSIG), typename VECTORSIGSTORAGETYPE = VECTORSIG>
/**
        connects a wishbone bus interface implemented with the variables of WishboneSignalMap
        to a ETISS_System structure. the template parameter instrBus defined is the iread/iwrite
        or dread/dwrite functions are used (-> instruction bus or data bus)
*/
class WishboneBus : public Delegate
{
    static_assert(bytewidth == sizeof(VECTORSIGSTORAGETYPE), "bytewidth != sizeof(VECTORSIGSTORAGETYPE)");

  public:
    /** \brief Constructor
     *
     * \param sigs: Signals between bus and CPU
     * \param system: Underlying ETISS system for accessing external bus
     * \param cpu: ETISS CPU state
     */
    WishboneBus(WishboneSignalMap<BOOLSIG, VECTORSIG> &sigs, ETISS_System &system, ETISS_CPU &cpu, etiss::CPUCore &core)
        : Delegate(system, cpu)
        , core_(core)
        , lastutime(0)
        , etime(0)
        , lastclock(false)
        , useposclkedge(true)
        , dat_o(0)
        , po_err(false)
        , pending(0)
        , sigs(sigs)
    {
    }

    /// \brief Initiate all bus output signals and set pending status to "nothing pending"
    void init()
    {
        sigs.ack_o = false;
        sigs.err_o = false;
        sigs.rty_o = false;
        sigs.dat_o = 0;
        pending = 0;
    }

    /** \brief Update signals to CPU or read/write from/to bus
     *
     * Has to different tasks depending on parameter premain: In the premain phase all signals are
     * updated on the CPU side. Otherwise the signals are evaluated for bus access and a read or
     * write access can be fulfilled.
     * \param time: Actual simulation time
     * \param premain: Determines premain phase
     * \param reset: Determines if CPU sends reset signal
     * \param posSimTime: If true, time is checked if it has elapsed
     */
    etiss_int32 update(uint64_t time, bool premain, bool reset, bool posSimTime = true)
    {
        etiss::int32 exception = etiss::RETURNCODE::NOERROR;

        if (time != 0) // check if time has been elapsed
        {
            if (posSimTime) // safeguard
            {
                if (time <= lastutime)
                {
                    std::cout << "Wishbone::update() no time elapsed or time is negative!" << std::endl;
                    return exception;
                }
            }
            else
            {
                if (time + 2 < lastutime) // ignore differences from rounding errors (casts from double etc.)
                {
                    std::cout << "Wishbone::update() time is negative! time: " << time / 1000
                              << " ns, lastutime: " << lastutime / 1000 << " ns"
                              << " premain: " << premain << " reset: " << reset << std::endl;
                    return exception;
                }
            }
        }

        bool clkedge = (((bool)lastclock) != (getBool(core_, sigs.clk_i))) &&
                       ((getBool(core_, sigs.clk_i)) == ((bool)useposclkedge)); // detect clock edge

        if (!premain) // store last update time clock edge
        {
            lastutime = time;
            lastclock = getBool(core_, sigs.clk_i);
        }

        if (reset) // reset
        {
            init();
        }
        else
        {
            if (premain) // apply pending signal changes
            {
                if (pending != 0) // signal changes to apply?
                {
                    if (time >= etime)
                    { // event ready?
                        switch (pending)
                        {
                        case 1: // read
                            setBool(core_, sigs.ack_o, !po_err);
                            setBool(core_, sigs.err_o, po_err);
                            setBool(core_, sigs.rty_o, false);
                            if (!po_err)
                                setData<VECTORSIGSTORAGETYPE, VECTORSIG>(core_, sigs.dat_o, dat_o);
                            break;
                        case 2: // write
                            sigs.ack_o = !po_err;
                            sigs.err_o = po_err;
                            break;
                        default:
                            etiss_log(FATALERROR, "variable \"pending\" has an invalid value");
                        }
                        if (clkedge)
                            pending = 0; // clear event
                    }
                }
                else if (clkedge)
                {
                    setBool(core_, sigs.ack_o, false);
                    setBool(core_, sigs.err_o, false);
                    setBool(core_, sigs.rty_o, false);
                    setData<VECTORSIGSTORAGETYPE, VECTORSIG>(core_, sigs.dat_o, 0);
                }
            }
            else // reevaluate signals
            {
                if (clkedge && (pending == 0))
                {
                    // immediate reset of signals
                    {
                        setBool(core_, sigs.ack_o, false);
                        setBool(core_, sigs.err_o, false);
                        setBool(core_, sigs.rty_o, false);
                        setData<VECTORSIGSTORAGETYPE, VECTORSIG>(core_, sigs.dat_o, 0);
                    }
                    if (getBool(core_, sigs.cyc_i) && getBool(core_, sigs.stb_i)) // Bus access
                    {
                        uint64_t addr = getAddr(core_, sigs.adr_i, instrBus);
                        unsigned addressOffet = addr & (bytewidth - 1); // offset (only needed for validation)
                        addr &= (~uint64_t(bytewidth - 1));             // Ignore unaligned address bits
                        VECTORSIGSTORAGETYPE dataBuf = 0;
                        uint64_t localTime = time; // time on read/write call
                        unsigned dataLength;       // length of read/write access

                        if (getBool(core_, sigs.we_i)) // write
                        {
                            if (!sel2Length(getSel(core_, sigs.sel_i), dataLength, addressOffet))
                                etiss::log(etiss::ERROR,
                                           std::string("invalid sel_i: ") + std::to_string(getSel(core_, sigs.sel_i)));
                            dataBuf = getData<VECTORSIGSTORAGETYPE, VECTORSIG>(core_, sigs.dat_i);
                            flipEndianness((uint8_t *)&dataBuf);
                            exception = write(instrBus, localTime, addr + addressOffet,
                                              ((uint8_t *)&dataBuf) + addressOffet, dataLength);
                            pending = 2;

                            /*std::cout << "Wishbone " << (instrBus?"ibus":"dbus")
                                      << " - write: 0x" << std::hex << dataBuf
                                      << " at address 0x" << addr+addressOffet
                                      << " len: " << dataLength
                                      << std::dec << std::endl;*/
                        }
                        else // read
                        {
                            if (!sel2Length(getSel(core_, sigs.sel_i), dataLength, addressOffet))
                                etiss::log(etiss::ERROR,
                                           std::string("invalid sel_i: ") + std::to_string(getSel(core_, sigs.sel_i)));
                            exception = read(instrBus, localTime, addr + addressOffet,
                                             ((uint8_t *)&dataBuf) + addressOffet, dataLength);
                            flipEndianness((uint8_t *)&dataBuf);
                            dat_o = dataBuf; // store but don't provide result
                            pending = 1;

                            /*std::cout << "Wishbone " << (instrBus?"ibus":"dbus")
                                      << " - read: 0x" << std::hex << dataBuf
                                      << " at address 0x" << addr+addressOffet
                                      << " len: " << dataLength
                                      << std::dec << std::endl;*/
                        }

                        po_err = (exception == etiss::RETURNCODE::DBUS_READ_ERROR ||
                                  exception == etiss::RETURNCODE::DBUS_WRITE_ERROR ||
                                  exception == etiss::RETURNCODE::IBUS_READ_ERROR ||
                                  exception == etiss::RETURNCODE::IBUS_WRITE_ERROR);
                        if (po_err)
                            exception = etiss::RETURNCODE::NOERROR;

                        etime = localTime; // store event time
                    }
                }
            }
        }
        return exception;
    }

  private:
    /// \brief Flips endianess of a VECTORSIG
    inline void flipEndianness(uint8_t *buf)
    {
        if (flipEndianess)
        {
            for (unsigned i = 0; i < (bytewidth / 2); ++i)
            {
                std::swap(buf[i], buf[bytewidth - 1 - i]);
            }
        }
    }

    /** \brief Calculates length and offset out of signal sel
     *
     * \param[in] sel: Select signal
     * \param[out] length: Number of Bytes to read/write
     * \param[in] addressOffset: Offset on the aligned address (is proved in this function)
     * \return Select signal was valid
     */
    bool sel2Length(uint32_t sel, unsigned &length, unsigned &addressOffset)
    {
        length = 0;
        unsigned selectOffset = 0;

        // nothing to transmit on bus (len = 0)
        if (sel == 0)
            return 0;

        /* only one steam of '1's is allowed like 0011 or 1100 (correlates to halfword)
         * so we first remove all leading '0's and so get the address offset
         * (unusual cases like 0110 are not covered with this check!)
         */
        while ((sel & 1) == 0)
        {
            selectOffset++;
            sel >>= 1;
        }
        /* thereafter we check the length with the following '1's
         * if the sel signal thereafter is NOT empty it wasn't valid
         */
        while ((sel & 1) == 1)
        {
            length++;
            sel >>= 1;
        }

        /* Endianess is always swapped on the whole bus width eg. 32bit or 64bit.
         * The offset is than be seen from the other side of the stream:
         * 0010      0010
         *    ^  ->  ^^
         */
        if (flipEndianess)
            selectOffset = bytewidth - length - selectOffset;

        // Check if calculated offset is valid with given bus offset. (Normally not given in wishbone bus)
        static bool output_addressOffset_warning = false;
        if ((selectOffset != addressOffset) && !output_addressOffset_warning)
        {
            etiss::log(etiss::WARNING,
                       std::string("Wishbone bus offset not valid! (0x") + std::to_string((int)addressOffset) + ")");
            output_addressOffset_warning = true;
        }

        return sel == 0;
    }

    //--------------------------------------- Attributes ---------------------------------------
  public:
    WishboneSignalMap<BOOLSIG, VECTORSIG> &sigs; ///< Signals between bus and CPU

  private:
    etiss::CPUCore &core_;
    uint64_t lastutime; ///< time of last signal evaluation phase
    uint64_t etime;
    bool lastclock;             ///< used for determining clock edge
    bool useposclkedge;         ///< use positive or negative clock edge
    VECTORSIGSTORAGETYPE dat_o; ///< buffer for data out to CPU
    bool po_err;                ///< bus error arised
    unsigned pending;           ///< 0: nothing pending; 1: Read pending; 2: Write pending
};

} // namespace interfaces
} // namespace etiss

#endif // ETISS_INTERFACES_WISHBONE_H
