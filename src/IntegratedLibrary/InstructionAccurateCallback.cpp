// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/IntegratedLibrary/InstructionAccurateCallback.h"
#include "etiss/fault/Stressor.h"

#include "etiss/CPUCore.h"
#include "etiss/Instruction.h"

extern "C"
{
    etiss_int32 etiss_plugin_InstructionAccurateCallback_OnEntry(void *ptr)
    {
        etiss::plugin::InstructionAccurateCallback &vvl = *(etiss::plugin::InstructionAccurateCallback *)ptr;
        return vvl.call_on_entry();
    }
}

namespace etiss
{

namespace plugin
{

InstructionAccurateCallback::InstructionAccurateCallback() {}
InstructionAccurateCallback::~InstructionAccurateCallback() {}

void InstructionAccurateCallback::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().insert("extern etiss_int32 etiss_plugin_InstructionAccurateCallback_OnEntry(void *); ");
}

void InstructionAccurateCallback::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    mis.foreach (
        [this](etiss::instr::VariableInstructionSet &vis)
        {
            vis.foreach (
                [this](etiss::instr::InstructionSet &is)
                {
                    is.foreach (
                        [this](etiss::instr::Instruction &i)
                        {
                            i.addCallback(
                                [this](etiss::instr::BitArray &, etiss::CodeSet &cs, etiss::instr::InstructionContext &)
                                {
                                    etiss::CodePart &pp = cs.prepend(etiss::CodePart::INITIALREQUIRED);
                                    pp.code() =
                                        std::string(
                                            "etiss_int32 ret_iac = etiss_plugin_InstructionAccurateCallback_OnEntry(") +
                                        getPointerCode() + ");\nif(ret_iac != 0)return(ret_iac);";
                                    return true;
                                },
                                0);
                        });
                });
        });
}

std::string InstructionAccurateCallback::_getPluginName() const
{
    return std::string("InstructionAccurateCallback");
}

etiss_int32 InstructionAccurateCallback::call_on_entry()
{
    bool trigger_fired = false;
    auto time = plugin_cpu_->cpuTime_ps;

    etiss::fault::Stressor::reset_event();

    trigger_fired |= plugin_core_->getStruct()->instructionAccurateCallback(
        time);                                // call instruction callback of plugin-associated core
    plugin_core_->getStruct()->foreachStruct( // call instruction callback of all VirtualStructs mounted on core
        [time, &trigger_fired](const std::string &name, VirtualStruct &vs)
        { trigger_fired |= vs.instructionAccurateCallback(time); });

    return (trigger_fired ? etiss::fault::Stressor::get_event()
                          : 0); // signal that a trigger has thrown an exception back to the JIT code calling
}

} // namespace plugin

} // namespace etiss
