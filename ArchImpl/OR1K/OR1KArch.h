/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief class definition of the CPUArch implementation for an or1k processor

        @detail

*/

#ifndef ETISS_OR1KArch_OR1KArch_H_
#define ETISS_OR1KArch_OR1KArch_H_

#include "OR1K.h"
#include "etiss/CPUArch.h"
#include "etiss/Instruction.h"
#include <map>

// include etiss library interface
#define ETISS_LIBNAME OR1KArch

//#include "etiss/helper/CPUArchLibrary.h"

#include "OR1KGDBCore.h"

/// TODO: implement opt_hostendianess for store/load instructions
class OR1KArch : public etiss::CPUArch
{

  public:
    OR1KArch();

    virtual const std::set<std::string> &getListenerSupportedRegisters();

    virtual etiss::Plugin *newTimer(ETISS_CPU *cpu);
    virtual void deleteTimer(etiss::Plugin *timer);

    virtual ETISS_CPU *newCPU();
    virtual void resetCPU(ETISS_CPU *cpu, etiss::uint64 *startpointer);
    virtual void deleteCPU(ETISS_CPU *);
    virtual std::shared_ptr<etiss::VirtualStruct> getVirtualStruct(ETISS_CPU *cpu);
    virtual void deleteVirtualStruct(etiss::VirtualStruct *stru);

    /**
            @return 8 (jump instruction + instruction of delay slot)
    */
    virtual unsigned getMaximumInstructionSizeInBytes();
    /**
            @return 4
    */
    virtual unsigned getInstructionSizeInBytes();
    /**
            @brief required headers (OR1K.h)
    */
    virtual const std::set<std::string> &getHeaders() const;
    virtual etiss::int32 handleException(etiss::int32 code, ETISS_CPU *cpu);

    virtual void initInstrSet(etiss::instr::ModedInstructionSet &) const;
    virtual void initCodeBlock(etiss::CodeBlock &cb) const;

    virtual etiss::InterruptVector *createInterruptVector(ETISS_CPU *cpu);
    virtual void deleteInterruptVector(etiss::InterruptVector *vec, ETISS_CPU *cpu);

    virtual etiss::plugin::gdb::GDBCore &getGDBCore();

  private:
    std::set<std::string> reg32names;
    std::set<std::string> listenerSupportedRegisters_;
    std::set<std::string> headers_;
    OR1KGDBCore gdbcore_;

  public:
    bool perfopt_noRangeException_; ///< performance option: if true then no range
                                    ///< exception shall be thrown (speedup of
                                    ///< additions etc.) @see etiss::CPUArch *
                                    ///< OR1KArch_createCPUArch(unsigned
                                    ///< index,std::map<std::string,std::string>
                                    ///< options)
    bool opt_returnjump_;           ///< if true then isjump will allways be false and jumps
                                    ///< will be implemented with a return statement @see
                                    ///< etiss::CPUArch * OR1KArch_createCPUArch(unsigned
                                    ///< index,std::map<std::string,std::string> options)
    bool opt_hostendianness;        ///< if true then no byte swapping will be done.
                                    ///< requires the endianness of instruction/data in
                                    ///< the memory to match host endianness @see
                                    ///< etiss::CPUArch * OR1KArch_createCPUArch(unsigned
                                    ///< index,std::map<std::string,std::string> options)
    bool ignore_sr_iee;             ///< ignore sr iee flag
};

extern etiss::instr::InstructionCollection Processor_OR1K;
extern etiss::instr::InstructionClass OR32;
extern etiss::instr::InstructionGroup ORFPX32;
extern etiss::instr::InstructionGroup ORBIS32_I;
extern etiss::instr::InstructionGroup ORBIS32_II;

extern etiss::Plugin *getOR1200Timing(etiss::Configuration &);

#define OR1KArch_translateInvalidInstruction(CODESET)                                       \
    {                                                                                       \
        etiss::CodePart &part = CODESET.append(etiss::CodePart::APPENDEDRETURNINGREQUIRED); \
        part.code() = "return OR1K_ILLEGALINSTRUCTIONEXCEPTION;";                           \
    }

/**
        @brief translates floating point instructions
        @see OR1KArch_fpu.cpp
*/
void translate_fpu(const etiss::uint32 instr, etiss::CodeSet &ret);

#endif
