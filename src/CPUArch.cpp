// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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

etiss::InterruptEnable *CPUArch::createInterruptEnable(ETISS_CPU *cpu)
{
    return new etiss::InterruptEnable();
}
void CPUArch::deleteInterruptEnable(etiss::InterruptEnable *en, ETISS_CPU *cpu)
{
    delete en;
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
    set->foreach (
        [](etiss::instr::Instruction &instr)
        {
            if (((uint32_t)instr.presentBuiltinGroups() &
                 (uint32_t)etiss::instr::Instruction::BUILTINGROUP::CPUTIMEUPDATE) == 0)
            { // update time
                instr.addCallback(
                    [](etiss::instr::BitArray &, etiss::CodeSet &cs, etiss::instr::InstructionContext &)
                    {
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
    mis.foreach ([](etiss::instr::VariableInstructionSet &vis)
                 { vis.foreach ([](etiss::instr::InstructionSet &set) { CPUArch_finalizeInstrSet(&set); }); });
}

void CPUArch::compensateEndianess(ETISS_CPU *cpu, etiss::instr::BitArray &ba) const
{
    etiss::instr::Buffer buffer(ba.intCount(), ba.to_ulong());
    buffer.recoverFromEndianness(4, etiss::_BIG_ENDIAN_);
    ba.set_value(buffer.data());
}

extern "C"
{

    void ETISS_signalChangedRegisterValue(ETISS_CPU *cpu, const char *registerName)
    {
        CPUArch::signalChangedRegisterValue(cpu, registerName);
    }

    void etiss_icache_flush(ETISS_CPU *cpu, ETISS_System *const system, void *const *const plugin_pointers)
    {
        cpu->exception = etiss::RETURNCODE::RELOADBLOCKS;
    }
}
