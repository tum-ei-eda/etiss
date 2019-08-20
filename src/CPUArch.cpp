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

        @brief implementation of etiss/CPUArch.h

        @detail

*/
#include "etiss/CPUArch.h"

#include <iostream>

#include "etiss/CPUCore.h"

using namespace etiss;

CPUArchRegListenerInterface::~CPUArchRegListenerInterface() {}

CPUArchCPUManipulation::~CPUArchCPUManipulation() {}

etiss::Plugin *CPUArchDefaultPlugins::newTimer(ETISS_CPU *cpu)
{ // disfunctional implementation
    return 0;
}

void CPUArchDefaultPlugins::deleteTimer(etiss::Plugin *timer)
{ // disfunctional implementation
    delete timer;
}

CPUArch::CPUArch(std::string archname) : archname_(archname)
{
    setCorrespondingCPUCoreName(std::string("core") + std::to_string(CPUCore::getNextID()));
}

CPUArch::~CPUArch() {}

std::string CPUArch::getArchName() const
{
    return archname_;
}

bool CPUArch::unlikelyInstruction(etiss::uint8 *instr, unsigned length, bool &ismetainstruction)
{ // simple implementation that return 0 if the
  // data is 0
    ismetainstruction = false;
    while (length >= 4)
    {
        if (*(etiss::uint32 *)instr != 0)
            return false;
        instr += 4;
        length -= 4;
    }
    while (length > 0)
    {
        if (*instr != 0)
            return false;
        instr += 1;
        length -= 1;
    }
    return true;
}

std::string CPUArch::getBlockGlobalCode()
{
    return "";
}

unsigned CPUArch::getMaximumInstructionsPerMetaInstruction()
{
    return getMaximumInstructionSizeInBytes() / getInstructionSizeInBytes(); /// TODO update to remove deprecated
                                                                             /// function
}

unsigned CPUArch::getSuperInstructionCount()
{
    return 1;
}

etiss::int32 CPUArch::handleException(etiss::int32 code, ETISS_CPU *cpu)
{ // disfunctional implementation
    return code;
}

etiss::InterruptVector *CPUArch::createInterruptVector(ETISS_CPU *cpu)
{ // disfunctional implementation
    return (etiss::InterruptVector *)0;
}
void CPUArch::deleteInterruptVector(etiss::InterruptVector *vec, ETISS_CPU *cpu)
{ // disfunctional
  // implementation allow
  // memory leak
}

etiss::plugin::gdb::GDBCore &CPUArch::getGDBCore()
{ // disfunctional implementation
    return gdbcore_;
}

std::string CPUArch::getIncludePath()
{
    return etiss::cfg().get<std::string>("etiss_wd", "") + "Arch/" + getName() + "/";
}

std::string CPUArch::_getPluginName() const
{
    return getName();
}

static void CPUArch_finalizeInstrSet(etiss::instr::InstructionSet *set)
{
    if (set == nullptr)
        return;
    set->foreach ([](etiss::instr::Instruction &instr) {
        if (((uint32_t)instr.presentBuiltinGroups() &
             (uint32_t)etiss::instr::Instruction::BUILTINGROUP::CPUTIMEUPDATE) == 0)
        { // update time
            instr.addCallback(
                [](etiss::instr::BitArray &, etiss::CodeSet &cs, etiss::instr::InstructionContext &) {
                    CodePart &cp = cs.prepend(CodePart::INITIALREQUIRED);
                    cp.getAffectedRegisters().add("cpuTime_ps", 64);
                    cp.code() = "cpu->cpuTime_ps += (1 * cpu->cpuCycleTime_ps);";
                    return true;
                },
                (uint32_t)etiss::instr::Instruction::BUILTINGROUP::CPUTIMEUPDATE);
        }
        /// TODO? ensure instruction pointer update
    });
}

void CPUArch::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    mis.foreach ([](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([](etiss::instr::InstructionSet &set) { CPUArch_finalizeInstrSet(&set); });
    });
}

void CPUArch::compensateEndianess(ETISS_CPU *cpu, etiss::instr::BitArray &ba) const
{
    ba.recoverFromEndianness(4, etiss::_BIG_ENDIAN_);
}

extern "C"
{

    void ETISS_signalChangedRegisterValue(ETISS_CPU *cpu, const char *registerName)
    {
        CPUArch::signalChangedRegisterValue(cpu, registerName);
    }
}
