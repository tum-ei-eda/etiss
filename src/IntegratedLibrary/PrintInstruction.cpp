// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/PrintInstruction.h

        @detail

*/

extern "C"
{
    int pi_6cac = 0;
}

#include "etiss/IntegratedLibrary/PrintInstruction.h"
#include "etiss/CPUArch.h"

using namespace etiss::plugin;

void PrintInstruction::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().insert("extern void PrintInstruction_print(const char *,uint64_t);"); // add print function
}

void PrintInstruction::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{

    mis.foreach (
        [](etiss::instr::VariableInstructionSet &vis)
        {
            vis.foreach (
                [](etiss::instr::InstructionSet &set)
                {
                    set.foreach (
                        [](etiss::instr::Instruction &instr)
                        {
                            instr.addCallback(
                                [&instr](etiss::instr::BitArray &ba, etiss::CodeSet &cs,
                                         etiss::instr::InstructionContext &ic)
                                {
                                    std::stringstream ss;

                                    ss << "PrintInstruction_print(\"";

                                    ss << "0x" << std::hex << std::setfill('0') << std::setw(16) << ic.current_address_
                                       << ": ";

                                    ss << instr.printASM(ba);

                                    ss << "\\n";

                                    ss << "\",cpu->instructionPointer);\n";

                                    cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                                    return true;
                                },
                                0);
                        });
                });
        });
}

std::string PrintInstruction::_getPluginName() const
{
    return "PrintInstruction";
}

void *PrintInstruction::getPluginHandle()
{
    return nullptr;
}

extern "C"
{
    void PrintInstruction_print(const char *c, uint64_t addr)
    {
        std::cout << c;
        std::cout.flush();
        if (addr == 0x6cac)
        {
            // std::cout << "TCOUNT: " << std::dec << ++pi_6cac << "\n";
        }
    }
}
