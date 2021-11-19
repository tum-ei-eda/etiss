/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

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
    mis.foreach ([this](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([this](etiss::instr::InstructionSet &is) {
            is.foreach ([this](etiss::instr::Instruction &i) {
                i.addCallback(
                    [this](etiss::instr::BitArray &, etiss::CodeSet &cs, etiss::instr::InstructionContext &) {
                        etiss::CodePart &pp = cs.prepend(etiss::CodePart::INITIALREQUIRED);
                        pp.code() = std::string("etiss_int32 ret_iac = etiss_plugin_InstructionAccurateCallback_OnEntry(") + getPointerCode() + ");\nif(ret_iac != 0)return(ret_iac);";
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

    trigger_fired |= plugin_core_->getStruct()->instructionAccurateCallback(time); // call instruction callback of plugin-associated core
    plugin_core_->getStruct()->foreachStruct( // call instruction callback of all VirtualStructs mounted on core
      [time,&trigger_fired](const std::string &name, VirtualStruct &vs)
      {
          trigger_fired |= vs.instructionAccurateCallback(time);
      }
    );

    return(trigger_fired ? etiss::fault::Stressor::get_event() : 0); // signal that a trigger has thrown an exception back to the JIT code calling
}


} // namespace plugin

} // namespace etiss
