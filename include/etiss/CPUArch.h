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

        @date July 23, 2014

        @version 0.1

*/
/**
        @file

        @brief contains neccesary interfaces for instruction translation.

        to enable ETISS to translate instructions of a certain ISA the etiss::CPUArch class needs to be
   extended/implemented. etiss::CPUArch inherits all other classes defined in this header file. Those classes are
   intended to provide structuring of member functions by purpose.

*/
#ifndef ETISS_INCLUDE_CPUARCH_H_
#define ETISS_INCLUDE_CPUARCH_H_

#include <map>
#include <set>
#include <string>

#include "etiss/CodePart.h"
#include "etiss/Instruction.h"
#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include "etiss/InterruptVector.h"
#include "etiss/Plugin.h"
#include "etiss/VirtualStruct.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/System.h"
#include "etiss/mm/MMU.h"

namespace etiss
{

/**
        @brief allows to inform plugins about changes to a register that is present in the cpu structure.
        an architecture should provide information about configuration registers (e.g. special purpose registers) so
   that plugins may simulate additional hardware. if such a register value has changed the etiss::CPUArch implementation
   is required to call etiss::CPUArch::signalChangedRegisterValue(ETISS_CPU* cpu,const char * registerName).
*/
class CPUArchRegListenerInterface
{
  public:
    virtual ~CPUArchRegListenerInterface();

    /**
            @see CPUArchRegListenerInterface::signalChangedRegisterValue
    */
    virtual const std::set<std::string> &getListenerSupportedRegisters() = 0;

  public:
    /**
            @brief call this function to inform RegisterDevicePlugins about changed special register values. call must
       be done by the architecture implementation!!!
            @details example pseudo implementation:
                            Instruction: write value 13 to special purpose register Y
                            Translated code: YOURARCH_writeToSPR(cpu,Y,13);
                            declaration of YOURARCH_writeToSPR: extern void
       YOURARCH_writeToSPR(ETISS_CPU*cpu,etiss_uint32 Y,etiss_uint32 X); implementation of YOURARCH_writeToSPR: void
       YOURARCH_writeToSPR(ETISS_CPU*cpu,etiss_uint32 Y,etiss_uint32 X){
                                                    // set value of register first
                                                    ((YOURARCH*)cpu)->Y = X;
                                                    // signal change
                                                    CPUArch::signalChangedRegisterValue(cpu,"nameOfRegisterY"); // very
       important
                                            }
                            alternatively void ETISS_signalChangedRegisterValue(ETISS_CPU* cpu,const char *
       registerName) may be used as a C function (e.g. call it directly from the translated code)
            @attention may only be called from within the etiss::CPUCore::execute() function.
            @attention this function is not very performant. to improve performance a bit call
       etiss::VirtualStruct::Field::signalWrite() directly for the appropriate field. in general it must be avaioded to
       use listeners on registers that are frequently changed (e.g. general purpose registers, special purpose registers
       for flags of arithmetic operations, etc.
            @see CPUCore.cpp (implemented there)
    */
    static void signalChangedRegisterValue(ETISS_CPU *cpu, const char *registerName);
};

/**
        @brief interface for cpu structure access.
        @detail this interface provides functions to read,write and list registers of a cpu. An empty default
   implementation is provided. At least the registers referenced in etiss::CPUArch::getGDBCore() should be supported.
*/
class CPUArchCPUManipulation
{
  public:
    virtual ~CPUArchCPUManipulation();

    /**
            this function must return a valid pointer to a virtual struct
    */
    virtual std::shared_ptr<etiss::VirtualStruct> getVirtualStruct(ETISS_CPU *cpu) = 0;
};

/**
        @brief provides common basic plugins
*/
class CPUArchDefaultPlugins
{
  public:
    virtual ~CPUArchDefaultPlugins() {}
    /**
            @brief create a simple default timer implementaion instance for this architecture.
            @return may be 0
    */
    virtual etiss::Plugin *newTimer(ETISS_CPU *cpu);
    /**
            @brief delete timer instance
            @return may be 0
    */
    virtual void deleteTimer(etiss::Plugin *timer);
};

/**
        @brief the interface to translate instructions of and processor architecture
*/
class CPUArch : public CPUArchRegListenerInterface,
                public CPUArchCPUManipulation,
                public CPUArchDefaultPlugins,
                public TranslationPlugin
{
    friend class LibraryInterface;

  public:
    /**
            @param archname must match the returned string of
       LibraryInterface::nameCPUArch(unsigned)/YOURLIBRARY_nameCPUArch(unsigned)
    */
    CPUArch(std::string archname);
    virtual ~CPUArch();

    /**
            @brief returns the name of this architecture. this name was passed to the constructor and must match the
       returned string of LibraryInterface::nameCPUArch(unsigned)/YOURLIBRARY_nameCPUArch(unsigned)
            @deprecated
    */
    std::string getArchName() const;

    /**
            @brief returns the name of this architecture. this name was passed to the constructor and must match the
       returned string of LibraryInterface::nameCPUArch(unsigned)/YOURLIBRARY_nameCPUArch(unsigned)
    */
    inline std::string getName() const { return getArchName(); }
    /**
            @brief allocate new cpu structure
    */
    virtual ETISS_CPU *newCPU() = 0;
    /**
            reset cpu (structure)
    */
    virtual void resetCPU(ETISS_CPU *cpu, etiss::uint64 *startpointer) = 0;
    /**
            @brief delete cpu structure
    */
    virtual void deleteCPU(ETISS_CPU *) = 0;
    /**
            used for variable instruction size and delay slots
            @deprecated use getMaximumInstructionsPerMetaInstruction()
    */
    virtual unsigned getMaximumInstructionSizeInBytes() = 0;
    /**
            @brief maximum number of instructions in a meta instruction
    */
    virtual unsigned getMaximumInstructionsPerMetaInstruction();
    /**
            size of one instruction/ smalest data unit for instructions of variable length
    */
    virtual unsigned getInstructionSizeInBytes() = 0;
    /**
            @brief fixed number of sub instructions per instruction (e.g. thumb -> 2 16bit instructions per 1 32bit
       instruction)
    */
    virtual unsigned getSuperInstructionCount();
    /**
            get c++ code snippet that is placed at the top of a translated block
    */
    virtual std::string getBlockGlobalCode();
    /**
            return true if the given data is unlikely to be an instruction. used for precompilation. default
       implementation returns true if data is all zeros
    */
    virtual bool unlikelyInstruction(etiss::uint8 *instr, unsigned length, bool &ismetainstruction);
    /**
            set of code header files e.g. CustomCPU.h containing a cpu register structure needed to compile the
       generated code
    */
    virtual const std::set<std::string> &getHeaders() const = 0;
    /**
            translate/process exceptions that occur at runtime
    */
    virtual etiss::int32 handleException(etiss::int32 code, ETISS_CPU *cpu);
    /**
            allocate a new interrupt vector object for the given cpu
    */
    virtual etiss::InterruptVector *createInterruptVector(ETISS_CPU *cpu);
    /**
            delete an allocated interrupt vector object
    */
    virtual void deleteInterruptVector(etiss::InterruptVector *vec, ETISS_CPU *cpu);
    /**
            returns arch dependent gdb functions. althought not required it is strongly recommended to implement this
    */
    virtual etiss::plugin::gdb::GDBCore &getGDBCore();
    /**
            returns a path that will be used to look up header files
    */
    virtual std::string getIncludePath();
    /**
            the default behavior of this function of a cpu arch is to add "cpu->cpuTime_ps += cpu->cpuCycleTime_ps;" if
       the cpu time update group is not in use
    */
    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;
    /**
            this function should compensate for any endianess on a BitArray so that bit 0 is always the LSB. the
       function etiss::instr::BitArray::recoverFromEndianness() can be used or the operation can be performed directly
       on th byte array with etiss::instr::BitArray::internalBuffer() by default bigendian aligned to 4 bytes is assumed
    */
    virtual void compensateEndianess(ETISS_CPU *cpu, etiss::instr::BitArray &ba) const;

    /**
     *	@brief It is an interface to instanciate a Memory Management Unit
     */
    virtual etiss::mm::MMU *newMMU(ETISS_CPU *cpu) { return nullptr; }

  protected:
    /// do not override. maps to getName().
    virtual std::string _getPluginName() const;

  private:
    etiss::plugin::gdb::GDBCore gdbcore_;
    std::string archname_;
};

} // namespace etiss

#endif
