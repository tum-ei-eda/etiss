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

        @brief conatins a convinience class that can be wrapped as a ETISS_System structure

        @detail

*/

#ifndef ETISS_INCLUDE_SYSTEM_H_
#define ETISS_INCLUDE_SYSTEM_H_

#include "etiss/jit/CPU.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/System.h"

#include <memory>

namespace etiss
{
/**
 * @brief System Interface for the basic system IO operations and time
 * synchronization.
 *
 * @details Systems that are model around a CPU model, for the memory and
 * peripherals need to implement this interface in order to be simulated with
 * ETISS. These method are called by ETISS if required.
 *
 * @see etiss::CPUCore
 *
 * @note For increased performance use the ETISS_System structure instead.
 */
class System
{
  public:
    inline virtual ~System() {}

    /**
     * @brief Instruction read operation.
     *
     * @details This method should implement an instruction read operation. To
     * indicate an error a non 0 value should be returned. The CPU time needs to
     * be increased according to the delay of this instruction operation.
     *
     * @note Normally this method can be implemented as an empty method that only
     * returns an error value. Because of the translating nature of ETISS all
     * instruction operations are out of order an will be performed via the debug
     * interface.
     *
     * @param cpu Pointer to the CPU structure, that requested this operation.
     *
     * @param addr The address from which the instruction should be read.
     *
     * @param len The length of the instruction in bytes.
     *
     * @return 0 if no error occurred
     */
    virtual etiss::int32 iread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len) = 0;

    /**
     * @brief Instruction write operation.
     *
     * @details This method should implement an instruction write operation. To
     * indicate an error a non 0 value should be returned. The CPU time needs to
     * be increased according to the delay of this instruction operation.
     *
     * @note Normally this method can be implemented as an empty method that only
     * returns an error value. Because of the translating nature of ETISS all
     * instruction operations are out of order an will be performed via the debug
     * interface
     *
     * @param cpu Pointer to the CPU structure, that requested this operation.
     *
     * @param addr The address to which the instruction should be written.
     *
     * @param buf Pointer to the buffer, that contains the instruction.
     *
     * @param len The length of the instruction in bytes.
     *
     * @return 0 if no error occurred.
     */
    virtual etiss::int32 iwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;

    /**
     * @brief Data read operation.
     *
     * @details This method should implement a data read operation. To indicate an
     * error a non 0 value should be returned. The CPU time needs to be increased
     * according to the delay of this instruction operation.
     *
     * @param cpu Pointer to the CPU structure, that requested this operation.
     *
     * @param addr The address from which the data should be read.
     *
     * @param buf Pointer to the buffer, that contains the instruction.
     *
     * @param len The length of the data in bytes.
     *
     * @return 0 if no error occurred.
     */
    virtual etiss::int32 dread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;

    /**
     * @brief Data write operation.
     *
     * @details This method should implement a data write operation. To indicate
     * an error a non 0 value should be returned. The CPU time needs to be
     * increased according to the delay of this instruction operation.
     *
     * @param cpu Pointer to the CPU structure, that requested this operation.
     *
     * @param addr The address to which the data should be written.
     *
     * @param buf Pointer to the buffer, that contains the instruction.
     *
     * @param len The length of the data in bytes.
     *
     * @return 0 if no error occurred.
     */
    virtual etiss::int32 dwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;

    /**
     * @brief Debug read operation.
     *
     * @details This method should implement a debug read operation. The debug
     * operations are used for data access that should not influence the
     * simulation time. To indicate an error a non 0 value should be returned.
     *
     * @note The read debug operation is used for the instruction fetches required
     * for generating the code blocks.
     *
     * @param addr The address from which the data should be read.
     *
     * @param buf Pointer to the buffer, that contains the instruction.
     *
     * @param len The length of the data in bytes.
     *
     * @return 0 if no error occurred.
     */
    virtual etiss::int32 dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;

    /**
     * @brief Debug write operation.
     *
     * @details This method should implement a debug write operation. The debug
     * operations are used for data access that should not influence the
     * simulation time. To indicate an error a non 0 value should be returned.
     *
     * @param addr The address to which the data should be written.
     *
     * @param buf Pointer to the buffer, that contains the instruction.
     *
     * @param len The length of the data in bytes.
     *
     * @return 0 if no error occurred
     */
    virtual etiss::int32 dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;

    /**
     * @brief Synchronize simulation time.
     *
     * @detail This method should implement the synchronization between the
     * simulation time of the system and the CPU. This function call should allow
     * the system to catch up with the CPU.
     *
     * @see etiss::ETISS_CPU
     *
     * @param cpu Pointer to the CPU structure, for which the synchronization
     * should be performed.
     */
    virtual void syncTime(ETISS_CPU *cpu) = 0;
};

/**
 * @brief A simple system, that implements the etiss::System interface.
 */
class SimpleSystem : public System
{
  public:
    inline virtual ~SimpleSystem() {}
    virtual etiss::int32 iread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len);
    virtual etiss::int32 iwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    virtual etiss::int32 dread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    virtual etiss::int32 dwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    virtual etiss::int32 dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    virtual etiss::int32 dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    virtual void syncTime(ETISS_CPU *cpu);

    virtual bool read(bool debug, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;
    virtual bool write(bool debug, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) = 0;
};

/**
 * @brief wraps a etiss::System in a ETISS_System structure.
 * @see
 */
extern std::shared_ptr<ETISS_System> wrap(etiss::System *sys);

} // namespace etiss

#endif
