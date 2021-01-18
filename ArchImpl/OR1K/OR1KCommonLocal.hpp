/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/
#include "OR1KArch.h"

using namespace etiss::instr;
using namespace etiss;

// define local bit array range reader
static BitArrayRange rd(25,21);
static BitArrayRange ra(20,16);
static BitArrayRange rb(15,11);
static BitArrayRange immediate(15,0);
static BitArrayRange limmediate(25,0);

// fast name resolution
static const char * const reg[] =
{
    "(((OR1K*)cpu)->R[ 0 ])",
    "(((OR1K*)cpu)->R[ 1 ])",
    "(((OR1K*)cpu)->R[ 2 ])",
    "(((OR1K*)cpu)->R[ 3 ])",
    "(((OR1K*)cpu)->R[ 4 ])",
    "(((OR1K*)cpu)->R[ 5 ])",
    "(((OR1K*)cpu)->R[ 6 ])",
    "(((OR1K*)cpu)->R[ 7 ])",
    "(((OR1K*)cpu)->R[ 8 ])",
    "(((OR1K*)cpu)->R[ 9 ])",
    "(((OR1K*)cpu)->R[ 10 ])",
    "(((OR1K*)cpu)->R[ 11 ])",
    "(((OR1K*)cpu)->R[ 12 ])",
    "(((OR1K*)cpu)->R[ 13 ])",
    "(((OR1K*)cpu)->R[ 14 ])",
    "(((OR1K*)cpu)->R[ 15 ])",
    "(((OR1K*)cpu)->R[ 16 ])",
    "(((OR1K*)cpu)->R[ 17 ])",
    "(((OR1K*)cpu)->R[ 18 ])",
    "(((OR1K*)cpu)->R[ 19 ])",
    "(((OR1K*)cpu)->R[ 20 ])",
    "(((OR1K*)cpu)->R[ 21 ])",
    "(((OR1K*)cpu)->R[ 22 ])",
    "(((OR1K*)cpu)->R[ 23 ])",
    "(((OR1K*)cpu)->R[ 24 ])",
    "(((OR1K*)cpu)->R[ 25 ])",
    "(((OR1K*)cpu)->R[ 26 ])",
    "(((OR1K*)cpu)->R[ 27 ])",
    "(((OR1K*)cpu)->R[ 28 ])",
    "(((OR1K*)cpu)->R[ 29 ])",
    "(((OR1K*)cpu)->R[ 30 ])",
    "(((OR1K*)cpu)->R[ 31 ])"
};
static const char * const reg_name[] =
{
    "R0",
    "R1",
    "R2",
    "R3",
    "R4",
    "R5",
    "R6",
    "R7",
    "R8",
    "R9",
    "R10",
    "R11",
    "R12",
    "R13",
    "R14",
    "R15",
    "R16",
    "R17",
    "R18",
    "R19",
    "R20",
    "R21",
    "R22",
    "R23",
    "R24",
    "R25",
    "R26",
    "R27",
    "R28",
    "R29",
    "R30",
    "R31"
};

template <bool isjump,bool hasdelayslot>
void update_pc(BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
{

    {
        CodePart & cp = cs.append(CodePart::APPENDEDOPTIONAL);
        cp.getRegisterDependencies().add("instructionPointer",32);
        cp.getAffectedRegisters().add("PPC",32);
        cp.code() = "*(((OR1K*)cpu)->PPC) = (uint32_t)cpu->instructionPointer;";
    }


    if (isjump)
    {
        ic.force_block_end_ = true;
        if (ic.cf_delay_slot_>0)  // no jump in delay slot
        {
            CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);
            cp.code() = "return OR1K_ILLEGALINSTRUCTIONEXCEPTION;";
            ic.force_block_end_ = true;
        }
        else
        {
            if (hasdelayslot)
            {
                ic.force_append_next_instr_ = true;
                ic.cf_delay_slot_ = 1;
                CodePart & cp = cs.append(CodePart::APPENDEDOPTIONAL);
                cp.getAffectedRegisters().add("instructionPointer",32);
                cp.code() = "cpu->instructionPointer = "+toString((uint32_t)(ic.current_address_+4))+"ULL;";
            }
            else
            {
                {
                    CodePart & cp = cs.append(CodePart::APPENDEDOPTIONAL);
                    cp.getAffectedRegisters().add("instructionPointer",32);
                    cp.code() = "cpu->instructionPointer = ((OR1K*)cpu)->instructionPointer_delayed;";
                }
                {
                    CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);
                    cp.code() = "return 0;";
                }
            }
        }
    }
    else
    {
        if (ic.cf_delay_slot_>0)  // instruction in delay slot // only one delay slot
        {
            ic.cf_delay_slot_ = 0;
            ic.force_block_end_ = true;
            {
                CodePart & cp = cs.append(CodePart::APPENDEDOPTIONAL);
                cp.getAffectedRegisters().add("instructionPointer",32);
                cp.code() = "cpu->instructionPointer = ((OR1K*)cpu)->instructionPointer_delayed;";
            }
            {
                CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);
                cp.code() = "return 0;";
            }
        }
        else
        {
            CodePart & cp = cs.append(CodePart::APPENDEDOPTIONAL);
            cp.getAffectedRegisters().add("instructionPointer",32);
            cp.code() = "cpu->instructionPointer = "+toString((uint32_t)(ic.current_address_+4))+"ULL;";
        }
    }

    {
        CodePart & cp = cs.append(CodePart::APPENDEDOPTIONAL);
        cp.getRegisterDependencies().add("instructionPointer",32);
        cp.getAffectedRegisters().add("NPC",32);
        cp.code() = "*(((OR1K*)cpu)->NPC) = (etiss_uint32) cpu->instructionPointer;";
    }

}

template <bool sig,bool imm,char op,char eop = ' '>
static bool l_sf (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
{
    std::string cast = sig?"(etiss_int32)":"(etiss_uint32)";
    typedef typename std::conditional<sig,int16_t,uint16_t>:: type IC;
    std::stringstream ss;
    ss << "*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & (~OR1K_SR_F));";
    ss << " *((OR1K*)cpu)->SR |= (" << cast << reg[ra.read(ba)] << op << eop << cast <<((!imm)?std::string(reg[rb.read(ba)]):toString((IC)immediate.read(ba))) << ")?OR1K_SR_F:0;";

    CodePart & cp =cs.append(CodePart::INITIALREQUIRED);
    cp.getRegisterDependencies().add(reg_name[ra.read(ba)],32);
    if (!imm)
        cp.getRegisterDependencies().add(reg_name[rb.read(ba)],32);
    cp.getAffectedRegisters().add("SR",32,OR1K_SR_F);
    cp.code() = ss.str();

    update_pc<false,false>(ba,cs,ic);

    return true;
}

static std::string or1k_asm_print_rDAB(BitArray & ba,Instruction& i)
{
    std::stringstream ss;
    ss << i.name_ << " R" << rd.read(ba) << ", R" << ra.read(ba) << ", R" << rb.read(ba);
    return ss.str();
}

template <bool sig> // sig currently not used
static std::string or1k_asm_print_rDAI(BitArray & ba,Instruction& i)
{
    std::stringstream ss;
    ss << i.name_ << " R" << rd.read(ba) << ", R" << ra.read(ba) << ", 0x" << std::hex << (uint16_t)immediate.read(ba) << std::dec;
    return ss.str();
}

