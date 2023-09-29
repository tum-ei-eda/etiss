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

#include "etiss/IntegratedLibrary/VariableValueLogger.h"
#include "etiss/CPUCore.h"
#include "etiss/Instruction.h"

#include <iostream>

extern "C"
{
    void etiss_plugin_VariableValueLogger(void *ptr)
    {
        etiss::plugin::VariableValueLogger &vvl = *(etiss::plugin::VariableValueLogger *)ptr;
        vvl.writeValue();
    }
}

namespace etiss
{

namespace plugin
{

VariableValueLogger::VariableValueLogger(
    const std::string &field, const std::string &file,
    std::function<void(std::ostream &out, const std::string &field, uint64_t value)> writer)
    : field_(field)
{
    if (!writer)
        writer = [](std::ostream &out, const std::string &field, uint64_t value) {
            out << field << "," << value << "\n";
        };
    out_.open(file.c_str(), std::ios::binary);
    writer_ = writer;
}

void VariableValueLogger::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().push_back("extern void etiss_plugin_VariableValueLogger(void *); ");
}

void VariableValueLogger::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    auto f = plugin_core_->getStruct()->findName(field_);
    unsigned width = f ? static_cast<unsigned>(f->width_) : 64;
    mis.foreach ([this, width](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([this, width](etiss::instr::InstructionSet &is) {
            is.foreach ([this, width](etiss::instr::Instruction &i) {
                i.addCallback(
                    [this, width](etiss::instr::BitArray &, etiss::CodeSet &cs, etiss::instr::InstructionContext &) {
                        etiss::CodePart &p = cs.append(etiss::CodePart::INITIALREQUIRED);
                        p.getRegisterDependencies().add(field_, width);
                        p.code() = std::string("etiss_plugin_VariableValueLogger(") + getPointerCode() + ");";
                        return true;
                    },
                    0);
            });
        });
    });
}

void VariableValueLogger::writeValue()
{
    if (field_ == "instructionPointer")
    {
        writer_(out_, field_, plugin_cpu_->instructionPointer);
    }
    else
    {
        writer_(out_, field_, plugin_core_->getStruct()->findName(field_)->read());
    }
    out_.flush();
}

std::string VariableValueLogger::_getPluginName() const
{
    return std::string("VariableValueLogger for ") + field_;
}

} // namespace plugin

} // namespace etiss
