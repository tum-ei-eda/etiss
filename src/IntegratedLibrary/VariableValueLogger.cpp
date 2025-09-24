// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
        writer = [](std::ostream &out, const std::string &field, uint64_t value)
        { out << field << "," << value << "\n"; };
    out_.open(file.c_str(), std::ios::binary);
    writer_ = writer;
}

void VariableValueLogger::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().insert("extern void etiss_plugin_VariableValueLogger(void *); ");
}

void VariableValueLogger::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    auto f = plugin_core_->getStruct()->findName(field_);
    unsigned width = f ? static_cast<unsigned>(f->width_) : 64;
    mis.foreach (
        [this, width](etiss::instr::VariableInstructionSet &vis)
        {
            vis.foreach (
                [this, width](etiss::instr::InstructionSet &is)
                {
                    is.foreach (
                        [this, width](etiss::instr::Instruction &i)
                        {
                            i.addCallback(
                                [this, width](etiss::instr::BitArray &, etiss::CodeSet &cs,
                                              etiss::instr::InstructionContext &)
                                {
                                    etiss::CodePart &p = cs.append(etiss::CodePart::INITIALREQUIRED);
                                    p.getRegisterDependencies().add(field_, width);
                                    p.code() =
                                        std::string("etiss_plugin_VariableValueLogger(") + getPointerCode() + ");";
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
