/**

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
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

static std::ofstream outfile;

PrintInstruction::PrintInstruction(bool print_to_file) : print_to_file_(print_to_file)
{
    if (print_to_file_) {
        std::string prefix = etiss::cfg().get<std::string>("etiss.output_path_prefix", "");
        std::string path = prefix + "/instr_trace.csv";
        outfile.open(path);
    } else {
    }
}

PrintInstruction::~PrintInstruction()
{
    if (print_to_file_) {
        outfile.close();
    }
}

void PrintInstruction::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().insert("extern void PrintInstruction_print(const char *,uint64_t);"); // add print function
    block.fileglobalCode().insert("extern void PrintInstruction_tofile(const char *,uint64_t);"); // add tofile function
}

void PrintInstruction::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{

    bool print_to_file = print_to_file_;
    mis.foreach ([print_to_file](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([print_to_file](etiss::instr::InstructionSet &set) {
            set.foreach ([print_to_file](etiss::instr::Instruction &instr) {
                instr.addCallback(
                    [&instr,print_to_file](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
                        std::stringstream ss;

                        if (print_to_file) {
                            ss << "PrintInstruction_tofile(\"";
                        } else {
                            ss << "PrintInstruction_print(\"";
                        }

                        ss << "0x" << std::hex << std::setfill('0') << std::setw(16) << ic.current_address_ << ": ";

                        ss << instr.printASM(ba); // TODO: make optional

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
    void PrintInstruction_tofile(const char *c, uint64_t addr)
    {
        outfile << c;
        outfile.flush();
    }
}
