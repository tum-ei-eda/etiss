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
        @modified by Yasamin Moradi <yasamin.moradi@tum.de>, Chair of Electronic Design Automation, TUM
        @date September 30, 2020
        @version 0.2
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

//set to 1 if cycles should be printed for each instructions, set to 0 otherwise
#define WITH_CYCLES 0

using namespace etiss::plugin;

void PrintInstruction::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().insert("extern void PrintInstruction_print(const char *,uint64_t);"); // add print function
    block.fileglobalCode().insert("extern void PrintInstruction_printEndCycle(uint64_t *cycles, const char **resources, uint64_t cpuTime_ps, uint64_t cpuCycleTime_ps);"); // add print End Cycle function
    block.fileglobalCode().insert("extern void PrintInstruction_printStartCycle(uint64_t *cycles, const char **resources, uint64_t cpuTime_ps, uint64_t cpuCycleTime_ps);"); // add print Start Cycle function
}

void PrintInstruction::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{

    mis.foreach ([](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([](etiss::instr::InstructionSet &set) {
            set.foreach ([](etiss::instr::Instruction &instr) {
                instr.addCallback(
                    [&instr](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
                        std::stringstream ss;

                        if (WITH_CYCLES == 1)
                        {
                            //print end cycle for previous instruction
                            ss << "PrintInstruction_printEndCycle(cpu->cycles, cpu->resources, cpu->cpuTime_ps, cpu->cpuCycleTime_ps);\n";
                            cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();
                        }

                        ss.str("");

                        //print instruction details
                        ss << "PrintInstruction_print(\"";

                        ss << "0x" << std::hex << std::setfill('0') << std::setw(16) << ic.current_address_ << ": ";

                        ss << instr.printASM(ba);

                        if (WITH_CYCLES == 0){
                            ss << "\\n";
                        }

                        ss << "\",cpu->instructionPointer);\n";

                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                        if (WITH_CYCLES == 1)
                        {
                            //print start cycle of instruction
                            ss.str("");

                            ss << "PrintInstruction_printStartCycle(cpu->cycles, cpu->resources, cpu->cpuTime_ps, cpu->cpuCycleTime_ps);\n";

                            cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();
                        }
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
        if (addr == 0x6cac)
        {
            // std::cout << "TCOUNT: " << std::dec << ++pi_6cac << "\n";
        }
    }
}

extern "C"
{
    void PrintInstruction_printStartCycle(uint64_t *cycles, const char **resources, uint64_t cpuTime_ps, uint64_t cpuCycleTime_ps)
    {
        //cycles: cpu->cycles[] and resource: cpu->resources[]

        //Check if resource calculation is turned on by computing max resources
        etiss_uint64 max = 0;
        etiss_uint64 max_resource1 = 0;
        for (int i = 0; i < 10; i++)
        //change 10 to ETISS_MAX_RESOURCES
        {
            if (resources[i])
            {
                if (cycles[i] > max)
                {
                    max = cycles[i];
                }
            }
        }

        //find out when the next instruction can be fetched
        //By when the first resource is released
        if (resources[0])
        {
            if (cycles[0] > 0)
            {
                max_resource1 = cycles[0];
            }
        }

        if (max != 0 || (max == 0 && cpuTime_ps == 0))
        { // max!=0: resource computation turned on
            std::cout << ", Start: " << max_resource1;

            // If this is the last instruction, end cycle will not be printed automatically. Print it here.
            if (false)
            {
                std::cout << ", End: " << max << std::endl;
            }
        }
    }
}

extern "C"
{
    void PrintInstruction_printEndCycle(uint64_t *cycles, const char **resources, uint64_t cpuTime_ps, uint64_t cpuCycleTime_ps)
    {
        //cycles: cpu->cycles[] and resource: cpu->resources[]

        //find out when the instruction is fully executed:
        //check what is the last resource that is being used, and when is it released
        etiss_uint64 max = 0;
        for (int i = 0; i < 10; i++)
        //change 10 to ETISS_MAX_RESOURCES
        {
            if (resources[i])
            {
                if (cycles[i] > max)
                {
                    max = cycles[i];
                }
            }
        }

        if (max != 0 || (max == 0 && cpuTime_ps == 0))
        { // max!=0: resource computation turned on
            std::cout << ", End: " << max << std::endl;
        }
    }
}
