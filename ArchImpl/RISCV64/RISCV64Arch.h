/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @version 0.1

*/

// This file was generated on Thu Jul 12 13:49:55 CEST 2018
// If necessary please modify this file according to the instructions
// Contact: eda@tum

// Modified to add architecture specific functionalities on July 14 2018

#ifndef ETISS_RISCV64Arch_RISCV64Arch_H_
#define ETISS_RISCV64Arch_RISCV64Arch_H_

#include "RISCV64.h"
#include "RISCV64GDBCore.h"
#include "etiss/CPUArch.h"
#include "etiss/Instruction.h"
#include "etiss/InterruptVector.h"
// Manually added
#include "RISCV64MMU.h"
#include "RISCV64Timer.h"
#include <map>

class RISCV64Arch : public etiss::CPUArch
{

  public:
    RISCV64Arch();

    virtual const std::set<std::string> &getListenerSupportedRegisters();

    virtual ETISS_CPU *newCPU();
    virtual void resetCPU(ETISS_CPU *cpu, etiss::uint64 *startpointer);
    virtual void deleteCPU(ETISS_CPU *);

    /**
            @brief get the VirtualStruct of the core to mitigate register access

            @see RISCV64ArchSpecificImp.h
    */
    virtual std::shared_ptr<etiss::VirtualStruct> getVirtualStruct(ETISS_CPU *cpu);

    /**
            @return 8 (jump instruction + instruction of delay slot)
    */
    virtual unsigned getMaximumInstructionSizeInBytes();

    /**
            @return 2
    */
    virtual unsigned getInstructionSizeInBytes();

    /**
            @brief required headers (RISCV64.h)
    */
    virtual const std::set<std::string> &getHeaders() const;

    /**
            @brief This function will be called automatically in order to handling architecure dependent exceptions such
                   as interrupt, system call, illegal instructions

            @see RISCV64ArchSpecificImp.h
    */
    virtual etiss::int32 handleException(etiss::int32 code, ETISS_CPU *cpu);

    /**
            @brief This function is called during CPUArch initialization

            @see RISCV64ArchSpecificImp.h
    */
    virtual void initInstrSet(etiss::instr::ModedInstructionSet &) const;
    virtual void initCodeBlock(etiss::CodeBlock &cb) const;

    /**
            @brief Target architecture may have inconsistent endianess. Data read from memory is buffered, and this
       function is called to alter sequence of buffered data so that the inconsistent endianess is compensated.

            @see RISCV64ArchSpecificImp.h
    */
    virtual void compensateEndianess(ETISS_CPU *cpu, etiss::instr::BitArray &ba) const;

    /**
            @brief If interrupt handling is expected, vector table could be provided to support interrupt triggering

            @see RISCV64ArchSpecificImp.h
    */
    virtual etiss::InterruptVector *createInterruptVector(ETISS_CPU *cpu);
    virtual void deleteInterruptVector(etiss::InterruptVector *vec, ETISS_CPU *cpu);

    /**
            @brief get the GDBcore for RISCV64 architecture

            @see RISCV64GDBCore.h for implementation of GDBcore
    */
    virtual etiss::plugin::gdb::GDBCore &getGDBCore();

    // Manually added
    etiss::Plugin *newTimer(ETISS_CPU *cpu);

    // Manually added
    void deleteTimer(etiss::Plugin *timer);

    // Manually added
    etiss::mm::MMU *newMMU(ETISS_CPU *cpu);

  private:
    std::set<std::string> listenerSupportedRegisters_;
    std::set<std::string> headers_;
    RISCV64GDBCore gdbcore_;
};
#endif
