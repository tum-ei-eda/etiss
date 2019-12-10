/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @version 0.1

*/

// This file was generated on Wed Jul 11 15:24:00 CEST 2018
// If necessary please modify this file according to the instructions
// Contact: eda@tum

// Modified to add architecture specific functionalities on July 11 2018

/*********************************************************************************************************************************

* Modification guidelines:

         1. The initial value of SP register should be initialized by ctr0.S/board.S. If not, it could be initialized
                through utility class etiss::VirtualStruct::Field.

         2. Debug mode print out all assignment results. GDB in 8 is prefered.

         3. Manually copy the content in bracket ["return ETISS_RETURNCODE_CPUFINISHED; \n"] to terminating instruction,
                otherwise the emulation can not be ended.

         4. If subset of encoding error occurs, it means the format of the encoding in the input model was not
appropriate

         5. If the PC register points to wrong address, please notice that some assembly may cause branch operation
                implicitly such as "MOV Rd Rn" in ARMv6-M

         6. If a variable is the result of dynamic slicing such as, var_1 = var_2<Hshift-1..Lshift-2>, the size would be
                calculated during process (if possible), otherwise it is assumed to be the register size. Problems may
occur when var_1 encounters bit manipulation such as "~" due to bit expansion. To change the nml model with explicit
slicing e.g var_1 = val_2<3..0> or avoid bit manipulation for dynamic sliced variable. Otherwise, manual correction has
to be done in generated code.

         7. Implementation dependent functionalities such as exception handling should be manully added. Corresponding
interfaces are provided in RISCVArchSpecificImp.h

         8. RISCVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify if in need.

 *********************************************************************************************************************************/

#include "RISCVArch.h"
#include "RISCVArchSpecificImp.h"

#define RISCV_DEBUG_CALL 0
using namespace etiss;
using namespace etiss::instr;

RISCVArch::RISCVArch() : CPUArch("RISCV")
{
    headers_.insert("Arch/RISCV/RISCV.h");
}

const std::set<std::string> &RISCVArch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

ETISS_CPU *RISCVArch::newCPU()
{
    ETISS_CPU *ret = (ETISS_CPU *)new RISCV();
    resetCPU(ret, 0);
    return ret;
}

void RISCVArch::resetCPU(ETISS_CPU *cpu, etiss::uint64 *startpointer)
{
    memset(cpu, 0, sizeof(RISCV));
    RISCV *riscvcpu = (RISCV *)cpu;

    if (startpointer)
        cpu->instructionPointer = *startpointer;
    else
        cpu->instructionPointer = 0x0; //  reference to manual
    cpu->mode = 1;
    cpu->cpuTime_ps = 0;
    cpu->cpuCycleTime_ps = 31250;

    // Instantiate the pointers in order to avoid segmentation fault
    for (int i = 0; i < 32; i++)
    {
        riscvcpu->ins_R[i] = 0;
        riscvcpu->R[i] = &riscvcpu->ins_R[i];
    }
    riscvcpu->ins_MSTATUS = 0;
    riscvcpu->MSTATUS = &riscvcpu->ins_MSTATUS;
    riscvcpu->ins_MIE = 0;
    riscvcpu->MIE = &riscvcpu->ins_MIE;
    riscvcpu->ins_MIP = 0;
    riscvcpu->MIP = &riscvcpu->ins_MIP;

    // Initialize the registers and state flags;
    riscvcpu->RA = 0;
    riscvcpu->R[1] = &(riscvcpu->RA);
    riscvcpu->SP = 0;
    riscvcpu->R[2] = &(riscvcpu->SP);
    riscvcpu->GP = 0;
    riscvcpu->R[3] = &(riscvcpu->GP);
    riscvcpu->TP = 0;
    riscvcpu->R[4] = &(riscvcpu->TP);
    // Manually modified
    riscvcpu->SSTATUS = 0xf;
    riscvcpu->MSTATUS = &(riscvcpu->SSTATUS);
    // Manually modified
    riscvcpu->SIE = 0xffffffff;
    riscvcpu->MIE = &(riscvcpu->SIE);
    riscvcpu->SIP = 0;
    riscvcpu->MIP = &(riscvcpu->SIP);
    riscvcpu->MTVEC = 0;
    riscvcpu->MEPC = 0;
    riscvcpu->MCAUSE = 0;
    // Manually modified
    riscvcpu->MISA = (1 << 20) | (1 << 18) | (1 << 12) | (1 << 8) | (1 << 2) | 1;
    riscvcpu->MHARTID = 0;
    riscvcpu->MSCRATCH = 0;
    riscvcpu->MTVAL = 0;
    riscvcpu->MEDELEG = 0;
    riscvcpu->MIDELEG = 0;
    riscvcpu->PMPADDR0 = 0;
    riscvcpu->PMPCFG0 = 0;
    riscvcpu->MCOUNTEREN = 0;
    riscvcpu->STVEC = 0;
    riscvcpu->SEPC = 0;
    riscvcpu->SCAUSE = 0;
    riscvcpu->SSCRATCH = 0;
    riscvcpu->STVAL = 0;
    riscvcpu->SATP = 0;
    riscvcpu->SCOUNTEREN = 0;
    for (int i = 0; i < 32; i++)
    {
        riscvcpu->PCCRs[i] = 0;
    }
    riscvcpu->PCER = 0;
    riscvcpu->PCMR = 0;
    for (int i = 0; i < 8; i++)
    {
        riscvcpu->HWLP[i] = 0;
    }
    riscvcpu->UHARTID = 0;
    // Manually modified
    riscvcpu->PRIVLV = PRV_M;
}

void RISCVArch::deleteCPU(ETISS_CPU *cpu)
{
    delete (RISCV *)cpu;
}

/**
        @return 8 (jump instruction + instruction of delay slot)
*/
unsigned RISCVArch::getMaximumInstructionSizeInBytes()
{
    return 8;
}
/**
        @return 2
*/
unsigned RISCVArch::getInstructionSizeInBytes()
{
    return 2;
}
/**
        @brief required headers (RISCV.h)
*/
const std::set<std::string> &RISCVArch::getHeaders() const
{
    return headers_;
}

void RISCVArch::initCodeBlock(etiss::CodeBlock &cb) const
{
    cb.fileglobalCode().insert("#include \"Arch/RISCV/RISCV.h\"\n");
}

etiss::plugin::gdb::GDBCore &RISCVArch::getGDBCore()
{

    return gdbcore_;
}

static const char *const reg_name[] = {
    "R0",  "R1",  "R2",  "R3",  "R4",  "R5",  "R6",  "R7",  "R8",  "R9",  "R10", "R11", "R12", "R13", "R14", "R15",
    "R16", "R17", "R18", "R19", "R20", "R21", "R22", "R23", "R24", "R25", "R26", "R27", "R28", "R29", "R30", "R31",
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////--//
static InstructionDefinition addi_rd_rs1_imm(
    ISA32, "addi", (uint32_t)0x13, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//addi\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = *((RISCV*)cpu)->R[" + toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition jalr_rd_rs1_imm(
    ISA32, "jalr", (uint32_t)0x67, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//jalr\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"
                          "etiss_uint32 currentPC = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "currentPC = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL ;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"currentPC = %#x\\n\",currentPC); \n"
#endif
                          "etiss_int32 cast_0 = _o_sign_extended_imm; \n"
                          "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                          "}\n"
                          "cpu->instructionPointer = (*((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + (etiss_int32)cast_0 & 4294967294);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = currentPC + 4;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition beq_rs1_rs2_imm(
    ISA32, "beq", (uint32_t)0x63, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//beq\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm1 & 0x1) << 11) + ((_i_imm2 & 0x3f) << 5) "
                          "+ ((_i_imm1 & 0x1e)>>1 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) + "] == *((RISCV*)cpu)->R[" + toString(rs2) +
                          "])\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lb_rd_rs1_imm(
    ISA32, "lb", (uint32_t)0x3, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//lb\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"
                          "etiss_uint8 o_data = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
                          "o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "etiss_int8 cast_0 = o_data; \n"
                          "if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
                          "}\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sb_rs1_rs2_imm(
    ISA32, "sb", (uint32_t)0x23, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//sb\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + (_i_imm2 << 5) + _i_imm1;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "M_mem_addr_0 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff);\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_0 = %#x\\n\",M_mem_addr_0); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slti_rd_rs1_imm(
    ISA32, "slti", (uint32_t)0x2013, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//slti\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "etiss_int32 cast_0 = _o_sign_extended_imm; \n"
                          "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                          "}\n"
                          "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "]; \n"
                          "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                          "}\n"
                          "if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = 1;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"
                          "}\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lw_rd_rs1_imm(
    ISA32, "lw", (uint32_t)0x2003, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//lw\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"
                          "etiss_uint32 o_data = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif

                          "exception = (*(system->dread))(system->handle, cpu, mem_addr, tmpbuf, 4);\n"
                          "o_data = temp;\n"

                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = o_data;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sw_rs1_rs2_imm(
    ISA32, "sw", (uint32_t)0x2023, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//sw\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + (_i_imm2 << 5) + _i_imm1;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif

                          "temp = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "]);\n"
                          "exception = (*(system->dwrite))(system->handle, cpu, mem_addr, tmpbuf, 4);\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrs_rd_csr(
    ISA32, "csrrs", (uint32_t)0x2073, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 csr = 0;
        static BitArrayRange R_csr_0(31, 20);
        etiss_uint32 csr_0 = R_csr_0.read(ba);
        csr += csr_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() =
            std::string("//csrrs\n") +
            "etiss_uint32 exception = 0;\n"
            "etiss_uint32 temp = 0;\n"
            "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
            "etiss_uint32 _i_write_val = 0;\n"
            "etiss_uint32 _o_csr_val = 0;\n"
            "etiss_uint16 _i_csr_addr = 0;\n"

            "_i_csr_addr = " +
            toString(csr) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_csr_addr = %#x\\n\",_i_csr_addr); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PRIVLV;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->UHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCER;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCMR;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->HWLP[_i_csr_addr - 1968];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MIDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MISA;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SATP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "_i_write_val = (_o_csr_val | *((RISCV*)cpu)->R[" +
            toString(rs1) +
            "]);\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_write_val = %#x\\n\",_i_write_val); \n"
#endif
            "if(" +
            toString(rd) +
            " != 0)\n"
            "{\n"
            "*((RISCV*)cpu)->R[" +
            toString(rd) +
            "] = _o_csr_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->R[" +
            toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
            "]); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 768)\n"
            "{\n"
            "*((RISCV*)cpu)->MSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "((RISCV*)cpu)->MTVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVEC = %#x\\n\",((RISCV*)cpu)->MTVEC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "((RISCV*)cpu)->MEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "((RISCV*)cpu)->PRIVLV = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "((RISCV*)cpu)->UHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->UHARTID = %#x\\n\",((RISCV*)cpu)->UHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "((RISCV*)cpu)->MHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MHARTID = %#x\\n\",((RISCV*)cpu)->MHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = %#x\\n\",((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "((RISCV*)cpu)->PCER = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCER = %#x\\n\",((RISCV*)cpu)->PCER); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "((RISCV*)cpu)->PCMR = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCMR = %#x\\n\",((RISCV*)cpu)->PCMR); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = %#x\\n\",((RISCV*)cpu)->HWLP[_i_csr_addr - 1968]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "((RISCV*)cpu)->MEDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEDELEG = %#x\\n\",((RISCV*)cpu)->MEDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "((RISCV*)cpu)->MIDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MIDELEG = %#x\\n\",((RISCV*)cpu)->MIDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "((RISCV*)cpu)->MISA = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MISA = %#x\\n\",((RISCV*)cpu)->MISA); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "*((RISCV*)cpu)->MIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIE = %#x\\n\",*((RISCV*)cpu)->MIE); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "((RISCV*)cpu)->MCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCOUNTEREN = %#x\\n\",((RISCV*)cpu)->MCOUNTEREN); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "((RISCV*)cpu)->MSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MSCRATCH = %#x\\n\",((RISCV*)cpu)->MSCRATCH); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "((RISCV*)cpu)->MCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCAUSE = %#x\\n\",((RISCV*)cpu)->MCAUSE); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "((RISCV*)cpu)->MTVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVAL = %#x\\n\",((RISCV*)cpu)->MTVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "*((RISCV*)cpu)->MIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIP = %#x\\n\",*((RISCV*)cpu)->MIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "((RISCV*)cpu)->SSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSTATUS = %#x\\n\",((RISCV*)cpu)->SSTATUS); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "((RISCV*)cpu)->SIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIE = %#x\\n\",((RISCV*)cpu)->SIE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "((RISCV*)cpu)->STVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVEC = %#x\\n\",((RISCV*)cpu)->STVEC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "((RISCV*)cpu)->SCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCOUNTEREN = %#x\\n\",((RISCV*)cpu)->SCOUNTEREN); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "((RISCV*)cpu)->SSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSCRATCH = %#x\\n\",((RISCV*)cpu)->SSCRATCH); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "((RISCV*)cpu)->SEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SEPC = %#x\\n\",((RISCV*)cpu)->SEPC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "((RISCV*)cpu)->SCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCAUSE = %#x\\n\",((RISCV*)cpu)->SCAUSE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "((RISCV*)cpu)->STVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVAL = %#x\\n\",((RISCV*)cpu)->STVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "((RISCV*)cpu)->SIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIP = %#x\\n\",((RISCV*)cpu)->SIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "((RISCV*)cpu)->SATP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SATP = %#x\\n\",((RISCV*)cpu)->SATP); \n"
#endif
            "}\n"

            "cpu->instructionPointer = " +
            toString((uint32_t)(ic.current_address_ + 4)) +
            "ULL; \n"

            "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sltiu_rd_rs1_imm(
    ISA32, "sltiu", (uint32_t)0x3013, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//sltiu\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] < _o_sign_extended_imm)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = 1;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"
                          "}\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrc_rd_csr(
    ISA32, "csrrc", (uint32_t)0x3073, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 csr = 0;
        static BitArrayRange R_csr_0(31, 20);
        etiss_uint32 csr_0 = R_csr_0.read(ba);
        csr += csr_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() =
            std::string("//csrrc\n") +
            "etiss_uint32 exception = 0;\n"
            "etiss_uint32 temp = 0;\n"
            "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
            "etiss_uint32 _i_write_val = 0;\n"
            "etiss_uint32 _o_csr_val = 0;\n"
            "etiss_uint16 _i_csr_addr = 0;\n"

            "_i_csr_addr = " +
            toString(csr) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_csr_addr = %#x\\n\",_i_csr_addr); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PRIVLV;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->UHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCER;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCMR;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->HWLP[_i_csr_addr - 1968];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MIDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MISA;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SATP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "_i_write_val = (_o_csr_val & ~*((RISCV*)cpu)->R[" +
            toString(rs1) +
            "])&0xffffffff;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_write_val = %#x\\n\",_i_write_val); \n"
#endif
            "if(" +
            toString(rd) +
            " != 0)\n"
            "{\n"
            "*((RISCV*)cpu)->R[" +
            toString(rd) +
            "] = _o_csr_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->R[" +
            toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
            "]); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 768)\n"
            "{\n"
            "*((RISCV*)cpu)->MSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "((RISCV*)cpu)->MTVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVEC = %#x\\n\",((RISCV*)cpu)->MTVEC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "((RISCV*)cpu)->MEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "((RISCV*)cpu)->PRIVLV = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "((RISCV*)cpu)->UHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->UHARTID = %#x\\n\",((RISCV*)cpu)->UHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "((RISCV*)cpu)->MHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MHARTID = %#x\\n\",((RISCV*)cpu)->MHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = %#x\\n\",((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "((RISCV*)cpu)->PCER = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCER = %#x\\n\",((RISCV*)cpu)->PCER); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "((RISCV*)cpu)->PCMR = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCMR = %#x\\n\",((RISCV*)cpu)->PCMR); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = %#x\\n\",((RISCV*)cpu)->HWLP[_i_csr_addr - 1968]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "((RISCV*)cpu)->MEDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEDELEG = %#x\\n\",((RISCV*)cpu)->MEDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "((RISCV*)cpu)->MIDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MIDELEG = %#x\\n\",((RISCV*)cpu)->MIDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "((RISCV*)cpu)->MISA = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MISA = %#x\\n\",((RISCV*)cpu)->MISA); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "*((RISCV*)cpu)->MIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIE = %#x\\n\",*((RISCV*)cpu)->MIE); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "((RISCV*)cpu)->MCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCOUNTEREN = %#x\\n\",((RISCV*)cpu)->MCOUNTEREN); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "((RISCV*)cpu)->MSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MSCRATCH = %#x\\n\",((RISCV*)cpu)->MSCRATCH); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "((RISCV*)cpu)->MCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCAUSE = %#x\\n\",((RISCV*)cpu)->MCAUSE); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "((RISCV*)cpu)->MTVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVAL = %#x\\n\",((RISCV*)cpu)->MTVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "*((RISCV*)cpu)->MIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIP = %#x\\n\",*((RISCV*)cpu)->MIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "((RISCV*)cpu)->SSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSTATUS = %#x\\n\",((RISCV*)cpu)->SSTATUS); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "((RISCV*)cpu)->SIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIE = %#x\\n\",((RISCV*)cpu)->SIE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "((RISCV*)cpu)->STVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVEC = %#x\\n\",((RISCV*)cpu)->STVEC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "((RISCV*)cpu)->SCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCOUNTEREN = %#x\\n\",((RISCV*)cpu)->SCOUNTEREN); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "((RISCV*)cpu)->SSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSCRATCH = %#x\\n\",((RISCV*)cpu)->SSCRATCH); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "((RISCV*)cpu)->SEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SEPC = %#x\\n\",((RISCV*)cpu)->SEPC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "((RISCV*)cpu)->SCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCAUSE = %#x\\n\",((RISCV*)cpu)->SCAUSE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "((RISCV*)cpu)->STVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVAL = %#x\\n\",((RISCV*)cpu)->STVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "((RISCV*)cpu)->SIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIP = %#x\\n\",((RISCV*)cpu)->SIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "((RISCV*)cpu)->SATP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SATP = %#x\\n\",((RISCV*)cpu)->SATP); \n"
#endif
            "}\n"

            "cpu->instructionPointer = " +
            toString((uint32_t)(ic.current_address_ + 4)) +
            "ULL; \n"

            "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition andi_rd_rs1_imm(
    ISA32, "andi", (uint32_t)0x7013, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//andi\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                          "] & _o_sign_extended_imm);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bgeu_rs1_rs2_imm(
    ISA32, "bgeu", (uint32_t)0x7063, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//bgeu\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm1 & 0x1) << 11) + ((_i_imm2 & 0x3f) << 5) "
                          "+ ((_i_imm1 & 0x1e)>>1 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) + "] >= *((RISCV*)cpu)->R[" + toString(rs2) +
                          "])\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrci_rd_csr(
    ISA32, "csrrci", (uint32_t)0x7073, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 csr = 0;
        static BitArrayRange R_csr_0(31, 20);
        etiss_uint32 csr_0 = R_csr_0.read(ba);
        csr += csr_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(19, 15);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() =
            std::string("//csrrci\n") +
            "etiss_uint32 exception = 0;\n"
            "etiss_uint32 temp = 0;\n"
            "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
            "etiss_uint32 _i_write_val = 0;\n"
            "etiss_uint32 _o_csr_val = 0;\n"
            "etiss_uint16 _i_csr_addr = 0;\n"

            "_i_csr_addr = " +
            toString(csr) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_csr_addr = %#x\\n\",_i_csr_addr); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PRIVLV;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->UHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCER;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCMR;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->HWLP[_i_csr_addr - 1968];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MIDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MISA;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SATP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(" +
            toString(rd) +
            " != 0)\n"
            "{\n"
            "*((RISCV*)cpu)->R[" +
            toString(rd) +
            "] = _o_csr_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->R[" +
            toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
            "]); \n"
#endif
            "}\n"

            "_i_write_val = (_o_csr_val & ~(etiss_uint32)" +
            toString(imm) +
            ")&0xffffffff;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_write_val = %#x\\n\",_i_write_val); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "*((RISCV*)cpu)->MSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "((RISCV*)cpu)->MTVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVEC = %#x\\n\",((RISCV*)cpu)->MTVEC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "((RISCV*)cpu)->MEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "((RISCV*)cpu)->PRIVLV = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "((RISCV*)cpu)->UHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->UHARTID = %#x\\n\",((RISCV*)cpu)->UHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "((RISCV*)cpu)->MHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MHARTID = %#x\\n\",((RISCV*)cpu)->MHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = %#x\\n\",((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "((RISCV*)cpu)->PCER = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCER = %#x\\n\",((RISCV*)cpu)->PCER); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "((RISCV*)cpu)->PCMR = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCMR = %#x\\n\",((RISCV*)cpu)->PCMR); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = %#x\\n\",((RISCV*)cpu)->HWLP[_i_csr_addr - 1968]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "((RISCV*)cpu)->MEDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEDELEG = %#x\\n\",((RISCV*)cpu)->MEDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "((RISCV*)cpu)->MIDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MIDELEG = %#x\\n\",((RISCV*)cpu)->MIDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "((RISCV*)cpu)->MISA = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MISA = %#x\\n\",((RISCV*)cpu)->MISA); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "*((RISCV*)cpu)->MIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIE = %#x\\n\",*((RISCV*)cpu)->MIE); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "((RISCV*)cpu)->MCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCOUNTEREN = %#x\\n\",((RISCV*)cpu)->MCOUNTEREN); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "((RISCV*)cpu)->MSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MSCRATCH = %#x\\n\",((RISCV*)cpu)->MSCRATCH); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "((RISCV*)cpu)->MCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCAUSE = %#x\\n\",((RISCV*)cpu)->MCAUSE); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "((RISCV*)cpu)->MTVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVAL = %#x\\n\",((RISCV*)cpu)->MTVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "*((RISCV*)cpu)->MIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIP = %#x\\n\",*((RISCV*)cpu)->MIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "((RISCV*)cpu)->SSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSTATUS = %#x\\n\",((RISCV*)cpu)->SSTATUS); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "((RISCV*)cpu)->SIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIE = %#x\\n\",((RISCV*)cpu)->SIE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "((RISCV*)cpu)->STVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVEC = %#x\\n\",((RISCV*)cpu)->STVEC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "((RISCV*)cpu)->SCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCOUNTEREN = %#x\\n\",((RISCV*)cpu)->SCOUNTEREN); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "((RISCV*)cpu)->SSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSCRATCH = %#x\\n\",((RISCV*)cpu)->SSCRATCH); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "((RISCV*)cpu)->SEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SEPC = %#x\\n\",((RISCV*)cpu)->SEPC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "((RISCV*)cpu)->SCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCAUSE = %#x\\n\",((RISCV*)cpu)->SCAUSE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "((RISCV*)cpu)->STVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVAL = %#x\\n\",((RISCV*)cpu)->STVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "((RISCV*)cpu)->SIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIP = %#x\\n\",((RISCV*)cpu)->SIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "((RISCV*)cpu)->SATP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SATP = %#x\\n\",((RISCV*)cpu)->SATP); \n"
#endif
            "}\n"

            "cpu->instructionPointer = " +
            toString((uint32_t)(ic.current_address_ + 4)) +
            "ULL; \n"

            "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ori_rd_rs1_imm(ISA32, "ori", (uint32_t)0x6013, (uint32_t)0x707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                etiss_uint32 imm = 0;
                                                static BitArrayRange R_imm_0(31, 20);
                                                etiss_uint32 imm_0 = R_imm_0.read(ba);
                                                imm += imm_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//ori\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                    "etiss_int32 __imm_extension = 0;\n"
                                                    "etiss_uint16 _i_imm = 0;\n"
                                                    "etiss_int32 _o_sign_extended_imm = 0;\n"

                                                    "_i_imm = " +
                                                    toString(imm) +
                                                    ";\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                                                    "if((_i_imm & 0x800)>>11 == 0)\n"
                                                    "{\n"
                                                    "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                                                    "}\n"

                                                    "else\n"
                                                    "{\n"
                                                    "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                                                    "}\n"
                                                    "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] | _o_sign_extended_imm);\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bltu_rs1_rs2_imm(
    ISA32, "bltu", (uint32_t)0x6063, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//bltu\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm1 & 0x1) << 11) + ((_i_imm2 & 0x3f) << 5) "
                          "+ ((_i_imm1 & 0x1e)>>1 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) + "] < *((RISCV*)cpu)->R[" + toString(rs2) +
                          "])\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrsi_rd_csr(
    ISA32, "csrrsi", (uint32_t)0x6073, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 csr = 0;
        static BitArrayRange R_csr_0(31, 20);
        etiss_uint32 csr_0 = R_csr_0.read(ba);
        csr += csr_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(19, 15);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() =
            std::string("//csrrsi\n") +
            "etiss_uint32 exception = 0;\n"
            "etiss_uint32 temp = 0;\n"
            "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
            "etiss_uint32 _i_write_val = 0;\n"
            "etiss_uint32 _o_csr_val = 0;\n"
            "etiss_uint16 _i_csr_addr = 0;\n"

            "_i_csr_addr = " +
            toString(csr) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_csr_addr = %#x\\n\",_i_csr_addr); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PRIVLV;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->UHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCER;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCMR;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->HWLP[_i_csr_addr - 1968];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MIDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MISA;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SATP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(" +
            toString(rd) +
            " != 0)\n"
            "{\n"
            "*((RISCV*)cpu)->R[" +
            toString(rd) +
            "] = _o_csr_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->R[" +
            toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
            "]); \n"
#endif
            "}\n"

            "_i_write_val = (_o_csr_val | (etiss_uint32)" +
            toString(imm) +
            ");\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_write_val = %#x\\n\",_i_write_val); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "*((RISCV*)cpu)->MSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "((RISCV*)cpu)->MTVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVEC = %#x\\n\",((RISCV*)cpu)->MTVEC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "((RISCV*)cpu)->MEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "((RISCV*)cpu)->PRIVLV = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "((RISCV*)cpu)->UHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->UHARTID = %#x\\n\",((RISCV*)cpu)->UHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "((RISCV*)cpu)->MHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MHARTID = %#x\\n\",((RISCV*)cpu)->MHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = %#x\\n\",((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "((RISCV*)cpu)->PCER = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCER = %#x\\n\",((RISCV*)cpu)->PCER); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "((RISCV*)cpu)->PCMR = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCMR = %#x\\n\",((RISCV*)cpu)->PCMR); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = %#x\\n\",((RISCV*)cpu)->HWLP[_i_csr_addr - 1968]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "((RISCV*)cpu)->MEDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEDELEG = %#x\\n\",((RISCV*)cpu)->MEDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "((RISCV*)cpu)->MIDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MIDELEG = %#x\\n\",((RISCV*)cpu)->MIDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "((RISCV*)cpu)->MISA = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MISA = %#x\\n\",((RISCV*)cpu)->MISA); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "*((RISCV*)cpu)->MIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIE = %#x\\n\",*((RISCV*)cpu)->MIE); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "((RISCV*)cpu)->MCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCOUNTEREN = %#x\\n\",((RISCV*)cpu)->MCOUNTEREN); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "((RISCV*)cpu)->MSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MSCRATCH = %#x\\n\",((RISCV*)cpu)->MSCRATCH); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "((RISCV*)cpu)->MCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCAUSE = %#x\\n\",((RISCV*)cpu)->MCAUSE); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "((RISCV*)cpu)->MTVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVAL = %#x\\n\",((RISCV*)cpu)->MTVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "*((RISCV*)cpu)->MIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIP = %#x\\n\",*((RISCV*)cpu)->MIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "((RISCV*)cpu)->SSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSTATUS = %#x\\n\",((RISCV*)cpu)->SSTATUS); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "((RISCV*)cpu)->SIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIE = %#x\\n\",((RISCV*)cpu)->SIE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "((RISCV*)cpu)->STVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVEC = %#x\\n\",((RISCV*)cpu)->STVEC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "((RISCV*)cpu)->SCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCOUNTEREN = %#x\\n\",((RISCV*)cpu)->SCOUNTEREN); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "((RISCV*)cpu)->SSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSCRATCH = %#x\\n\",((RISCV*)cpu)->SSCRATCH); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "((RISCV*)cpu)->SEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SEPC = %#x\\n\",((RISCV*)cpu)->SEPC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "((RISCV*)cpu)->SCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCAUSE = %#x\\n\",((RISCV*)cpu)->SCAUSE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "((RISCV*)cpu)->STVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVAL = %#x\\n\",((RISCV*)cpu)->STVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "((RISCV*)cpu)->SIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIP = %#x\\n\",((RISCV*)cpu)->SIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "((RISCV*)cpu)->SATP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SATP = %#x\\n\",((RISCV*)cpu)->SATP); \n"
#endif
            "}\n"

            "cpu->instructionPointer = " +
            toString((uint32_t)(ic.current_address_ + 4)) +
            "ULL; \n"

            "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition xori_rd_rs1_imm(
    ISA32, "xori", (uint32_t)0x4013, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//xori\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                          "] ^ _o_sign_extended_imm);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition blt_rs1_rs2_imm(
    ISA32, "blt", (uint32_t)0x4063, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//blt\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm1 & 0x1) << 11) + ((_i_imm2 & 0x3f) << 5) "
                          "+ ((_i_imm1 & 0x1e)>>1 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "]; \n"
                          "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                          "}\n"
                          "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "]; \n"
                          "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                          "}\n"
                          "if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lbu_rd_rs1_imm(
    ISA32, "lbu", (uint32_t)0x4003, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//lbu\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"
                          "etiss_uint8 o_data = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
                          "o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = (etiss_uint32)o_data;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lui_rd_imm(ISA32, "lui", (uint32_t)0x37, (uint32_t)0x7f,
                                        [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                            etiss_uint32 rd = 0;
                                            static BitArrayRange R_rd_0(11, 7);
                                            etiss_uint32 rd_0 = R_rd_0.read(ba);
                                            rd += rd_0;
                                            etiss_uint32 imm = 0;
                                            static BitArrayRange R_imm_0(31, 12);
                                            etiss_uint32 imm_0 = R_imm_0.read(ba);
                                            imm += imm_0;
                                            CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                            partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                            partInit.getAffectedRegisters().add("instructionPointer", 32);
                                            partInit.code() =
                                                std::string("//lui\n") +
                                                "etiss_uint32 exception = 0;\n"
                                                "etiss_uint32 temp = 0;\n"
                                                "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                "etiss_uint32 _i_imm = 0;\n"
                                                "etiss_uint32 _o_sign_extended_imm = 0;\n"

                                                "_i_imm = " +
                                                toString(imm) +
                                                ";\n"
#if RISCV_DEBUG_CALL
                                                "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                                                "_o_sign_extended_imm = (_i_imm << 12);\n"
#if RISCV_DEBUG_CALL
                                                "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                                                "if(" +
                                                toString(rd) +
                                                " != 0)\n"
                                                "{\n"
                                                "*((RISCV*)cpu)->R[" +
                                                toString(rd) +
                                                "] = _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                                                "printf(\"*((RISCV*)cpu)->R[" +
                                                toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                "]); \n"
#endif
                                                "}\n"

                                                "cpu->instructionPointer = " +
                                                toString((uint32_t)(ic.current_address_ + 4)) +
                                                "ULL; \n"

                                                "return exception; \n";
                                            return true;
                                        },
                                        0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition auipc_rd_imm(ISA32, "auipc", (uint32_t)0x17, (uint32_t)0x7f,
                                          [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                              etiss_uint32 rd = 0;
                                              static BitArrayRange R_rd_0(11, 7);
                                              etiss_uint32 rd_0 = R_rd_0.read(ba);
                                              rd += rd_0;
                                              etiss_uint32 imm = 0;
                                              static BitArrayRange R_imm_0(31, 12);
                                              etiss_uint32 imm_0 = R_imm_0.read(ba);
                                              imm += imm_0;
                                              CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                              partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                              partInit.getAffectedRegisters().add("instructionPointer", 32);
                                              partInit.code() =
                                                  std::string("//auipc\n") +
                                                  "etiss_uint32 exception = 0;\n"
                                                  "etiss_uint32 temp = 0;\n"
                                                  "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                  "etiss_uint32 _i_imm = 0;\n"
                                                  "etiss_uint32 _o_sign_extended_imm = 0;\n"

                                                  "_i_imm = " +
                                                  toString(imm) +
                                                  ";\n"
#if RISCV_DEBUG_CALL
                                                  "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                                                  "_o_sign_extended_imm = (_i_imm << 12);\n"
#if RISCV_DEBUG_CALL
                                                  "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                                                  "if(" +
                                                  toString(rd) +
                                                  " != 0)\n"
                                                  "{\n"
                                                  "*((RISCV*)cpu)->R[" +
                                                  toString(rd) + "] = " + toString((uint32_t)ic.current_address_) +
                                                  "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                                                  "printf(\"*((RISCV*)cpu)->R[" +
                                                  toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                  "]); \n"
#endif
                                                  "}\n"

                                                  "else\n"
                                                  "{\n"
                                                  // Explicit assignment to PC
                                                  "cpu->instructionPointer = " +
                                                  toString((uint32_t)(ic.current_address_ + 4)) +
                                                  "ULL; \n"
                                                  "}\n"
                                                  "cpu->instructionPointer = " +
                                                  toString((uint32_t)(ic.current_address_ + 4)) +
                                                  "ULL; \n"

                                                  "return exception; \n";
                                              return true;
                                          },
                                          0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition jal_rd_imm(
    ISA32, "jal", (uint32_t)0x6f, (uint32_t)0x7f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 12);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//jal\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint32 _i_imm = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x80000)>>19 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4292870144;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm & 0x80000)>>19 << 20) + ((_i_imm & 0xff) "
                          "<< 12) + ((_i_imm & 0x100)>>8 << 11) + ((_i_imm & 0x7fe00)>>9 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = " + toString((uint32_t)ic.current_address_) +
                          "ULL  + 4;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "etiss_int32 cast_0 = _o_sign_extended_imm; \n"
                          "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n";

        CodePart &partReturn = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);
        partReturn.code() = std::string("return exception; \n");

        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bne_rs1_rs2_imm(
    ISA32, "bne", (uint32_t)0x1063, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//bne\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm1 & 0x1) << 11) + ((_i_imm2 & 0x3f) << 5) "
                          "+ ((_i_imm1 & 0x1e)>>1 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) + "] != *((RISCV*)cpu)->R[" + toString(rs2) +
                          "])\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lh_rd_rs1_imm(
    ISA32, "lh", (uint32_t)0x1003, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//lh\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"
                          "etiss_uint16 o_data = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
                          "o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
                          "o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "etiss_int16 cast_0 = o_data; \n"
                          "if((etiss_int16)((etiss_uint16)cast_0 - 0x8000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint16)cast_0 ;\n"
                          "}\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sh_rs1_rs2_imm(
    ISA32, "sh", (uint32_t)0x1023, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//sh\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + (_i_imm2 << 5) + _i_imm1;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "M_mem_addr_1 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff00)>>8;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_1 = %#x\\n\",M_mem_addr_1); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "M_mem_addr_0 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff);\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_0 = %#x\\n\",M_mem_addr_0); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrw_rd_csr(
    ISA32, "csrrw", (uint32_t)0x1073, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 csr = 0;
        static BitArrayRange R_csr_0(31, 20);
        etiss_uint32 csr_0 = R_csr_0.read(ba);
        csr += csr_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() =
            std::string("//csrrw\n") +
            "etiss_uint32 exception = 0;\n"
            "etiss_uint32 temp = 0;\n"
            "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
            "etiss_uint32 _i_write_val = 0;\n"
            "etiss_uint32 _o_csr_val = 0;\n"
            "etiss_uint16 _i_csr_addr = 0;\n"

            "_i_csr_addr = " +
            toString(csr) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_csr_addr = %#x\\n\",_i_csr_addr); \n"
#endif
            "_i_write_val = *((RISCV*)cpu)->R[" +
            toString(rs1) +
            "];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_write_val = %#x\\n\",_i_write_val); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PRIVLV;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->UHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCER;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCMR;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->HWLP[_i_csr_addr - 1968];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MIDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MISA;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SATP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(" +
            toString(rd) +
            " != 0)\n"
            "{\n"
            "*((RISCV*)cpu)->R[" +
            toString(rd) +
            "] = _o_csr_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->R[" +
            toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
            "]); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 768)\n"
            "{\n"
            "*((RISCV*)cpu)->MSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "((RISCV*)cpu)->MTVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVEC = %#x\\n\",((RISCV*)cpu)->MTVEC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "((RISCV*)cpu)->MEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "((RISCV*)cpu)->PRIVLV = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "((RISCV*)cpu)->UHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->UHARTID = %#x\\n\",((RISCV*)cpu)->UHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "((RISCV*)cpu)->MHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MHARTID = %#x\\n\",((RISCV*)cpu)->MHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = %#x\\n\",((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "((RISCV*)cpu)->PCER = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCER = %#x\\n\",((RISCV*)cpu)->PCER); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "((RISCV*)cpu)->PCMR = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCMR = %#x\\n\",((RISCV*)cpu)->PCMR); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = %#x\\n\",((RISCV*)cpu)->HWLP[_i_csr_addr - 1968]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "((RISCV*)cpu)->MEDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEDELEG = %#x\\n\",((RISCV*)cpu)->MEDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "((RISCV*)cpu)->MIDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MIDELEG = %#x\\n\",((RISCV*)cpu)->MIDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "((RISCV*)cpu)->MISA = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MISA = %#x\\n\",((RISCV*)cpu)->MISA); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "*((RISCV*)cpu)->MIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIE = %#x\\n\",*((RISCV*)cpu)->MIE); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "((RISCV*)cpu)->MCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCOUNTEREN = %#x\\n\",((RISCV*)cpu)->MCOUNTEREN); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "((RISCV*)cpu)->MSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MSCRATCH = %#x\\n\",((RISCV*)cpu)->MSCRATCH); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "((RISCV*)cpu)->MCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCAUSE = %#x\\n\",((RISCV*)cpu)->MCAUSE); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "((RISCV*)cpu)->MTVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVAL = %#x\\n\",((RISCV*)cpu)->MTVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "*((RISCV*)cpu)->MIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIP = %#x\\n\",*((RISCV*)cpu)->MIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "((RISCV*)cpu)->SSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSTATUS = %#x\\n\",((RISCV*)cpu)->SSTATUS); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "((RISCV*)cpu)->SIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIE = %#x\\n\",((RISCV*)cpu)->SIE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "((RISCV*)cpu)->STVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVEC = %#x\\n\",((RISCV*)cpu)->STVEC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "((RISCV*)cpu)->SCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCOUNTEREN = %#x\\n\",((RISCV*)cpu)->SCOUNTEREN); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "((RISCV*)cpu)->SSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSCRATCH = %#x\\n\",((RISCV*)cpu)->SSCRATCH); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "((RISCV*)cpu)->SEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SEPC = %#x\\n\",((RISCV*)cpu)->SEPC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "((RISCV*)cpu)->SCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCAUSE = %#x\\n\",((RISCV*)cpu)->SCAUSE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "((RISCV*)cpu)->STVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVAL = %#x\\n\",((RISCV*)cpu)->STVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "((RISCV*)cpu)->SIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIP = %#x\\n\",((RISCV*)cpu)->SIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "((RISCV*)cpu)->SATP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SATP = %#x\\n\",((RISCV*)cpu)->SATP); \n"
#endif
            "}\n"

            "cpu->instructionPointer = " +
            toString((uint32_t)(ic.current_address_ + 4)) +
            "ULL; \n"

            "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bge_rs1_rs2_imm(
    ISA32, "bge", (uint32_t)0x5063, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(31, 25);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(11, 7);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//bge\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x40)>>6 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = __imm_extension + ((_i_imm1 & 0x1) << 11) + ((_i_imm2 & 0x3f) << 5) "
                          "+ ((_i_imm1 & 0x1e)>>1 << 1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "]; \n"
                          "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                          "}\n"
                          "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "]; \n"
                          "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                          "}\n"
                          "if((etiss_int32)cast_1 >= (etiss_int32)cast_0)\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lhu_rd_rs1_imm(
    ISA32, "lhu", (uint32_t)0x5003, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(31, 20);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//lhu\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_int32 __imm_extension = 0;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_int32 _o_sign_extended_imm = 0;\n"
                          "etiss_uint16 o_data = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x800)>>11 == 0)\n"
                          "{\n"
                          "__imm_extension = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "__imm_extension = 4294963200;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"__imm_extension = %#x\\n\",__imm_extension); \n"
#endif
                          "}\n"
                          "_o_sign_extended_imm = _i_imm + __imm_extension;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_o_sign_extended_imm = %#x\\n\",_o_sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "] + _o_sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
                          "o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
                          "o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = (etiss_uint32)o_data;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrwi_rd_csr(
    ISA32, "csrrwi", (uint32_t)0x5073, (uint32_t)0x707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 csr = 0;
        static BitArrayRange R_csr_0(31, 20);
        etiss_uint32 csr_0 = R_csr_0.read(ba);
        csr += csr_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(19, 15);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() =
            std::string("//csrrwi\n") +
            "etiss_uint32 exception = 0;\n"
            "etiss_uint32 temp = 0;\n"
            "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
            "etiss_uint32 _i_write_val = 0;\n"
            "etiss_uint32 _o_csr_val = 0;\n"
            "etiss_uint16 _i_csr_addr = 0;\n"

            "_i_csr_addr = " +
            toString(csr) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_csr_addr = %#x\\n\",_i_csr_addr); \n"
#endif
            "_i_write_val = (etiss_uint32)" +
            toString(imm) +
            ";\n"
#if RISCV_DEBUG_CALL
            "printf(\"_i_write_val = %#x\\n\",_i_write_val); \n"
#endif
            "if(_i_csr_addr == 768)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PRIVLV;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->UHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MHARTID;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCER;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->PCMR;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->HWLP[_i_csr_addr - 1968];\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MEDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MIDELEG;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MISA;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->MTVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "_o_csr_val = *((RISCV*)cpu)->MIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSTATUS;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVEC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCOUNTEREN;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SSCRATCH;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SEPC;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SCAUSE;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->STVAL;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SIP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "_o_csr_val = ((RISCV*)cpu)->SATP;\n"
#if RISCV_DEBUG_CALL
            "printf(\"_o_csr_val = %#x\\n\",_o_csr_val); \n"
#endif
            "}\n"

            "if(" +
            toString(rd) +
            " != 0)\n"
            "{\n"
            "*((RISCV*)cpu)->R[" +
            toString(rd) +
            "] = _o_csr_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->R[" +
            toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
            "]); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 768)\n"
            "{\n"
            "*((RISCV*)cpu)->MSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 773)\n"
            "{\n"
            "((RISCV*)cpu)->MTVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVEC = %#x\\n\",((RISCV*)cpu)->MTVEC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 833)\n"
            "{\n"
            "((RISCV*)cpu)->MEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3088)\n"
            "{\n"
            "((RISCV*)cpu)->PRIVLV = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 20)\n"
            "{\n"
            "((RISCV*)cpu)->UHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->UHARTID = %#x\\n\",((RISCV*)cpu)->UHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 3860)\n"
            "{\n"
            "((RISCV*)cpu)->MHARTID = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MHARTID = %#x\\n\",((RISCV*)cpu)->MHARTID); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1920) && (_i_csr_addr <= 1951))\n"
            "{\n"
            "((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920] = %#x\\n\",((RISCV*)cpu)->PCCRs[_i_csr_addr - 1920]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1952)\n"
            "{\n"
            "((RISCV*)cpu)->PCER = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCER = %#x\\n\",((RISCV*)cpu)->PCER); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 1953)\n"
            "{\n"
            "((RISCV*)cpu)->PCMR = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->PCMR = %#x\\n\",((RISCV*)cpu)->PCMR); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if((_i_csr_addr >= 1968) && (_i_csr_addr <= 1975))\n"
            "{\n"
            "((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->HWLP[_i_csr_addr - 1968] = %#x\\n\",((RISCV*)cpu)->HWLP[_i_csr_addr - 1968]); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 770)\n"
            "{\n"
            "((RISCV*)cpu)->MEDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MEDELEG = %#x\\n\",((RISCV*)cpu)->MEDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 771)\n"
            "{\n"
            "((RISCV*)cpu)->MIDELEG = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MIDELEG = %#x\\n\",((RISCV*)cpu)->MIDELEG); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 769)\n"
            "{\n"
            "((RISCV*)cpu)->MISA = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MISA = %#x\\n\",((RISCV*)cpu)->MISA); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 772)\n"
            "{\n"
            "*((RISCV*)cpu)->MIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIE = %#x\\n\",*((RISCV*)cpu)->MIE); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 774)\n"
            "{\n"
            "((RISCV*)cpu)->MCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCOUNTEREN = %#x\\n\",((RISCV*)cpu)->MCOUNTEREN); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 832)\n"
            "{\n"
            "((RISCV*)cpu)->MSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MSCRATCH = %#x\\n\",((RISCV*)cpu)->MSCRATCH); \n"
#endif
            "}\n"

            "else\n"
            "{\n"
            "if(_i_csr_addr == 834)\n"
            "{\n"
            "((RISCV*)cpu)->MCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MCAUSE = %#x\\n\",((RISCV*)cpu)->MCAUSE); \n"
#endif
            "}\n"

            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "}\n"
            "if(_i_csr_addr == 835)\n"
            "{\n"
            "((RISCV*)cpu)->MTVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->MTVAL = %#x\\n\",((RISCV*)cpu)->MTVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 836)\n"
            "{\n"
            "*((RISCV*)cpu)->MIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"*((RISCV*)cpu)->MIP = %#x\\n\",*((RISCV*)cpu)->MIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 256)\n"
            "{\n"
            "((RISCV*)cpu)->SSTATUS = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSTATUS = %#x\\n\",((RISCV*)cpu)->SSTATUS); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 260)\n"
            "{\n"
            "((RISCV*)cpu)->SIE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIE = %#x\\n\",((RISCV*)cpu)->SIE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 261)\n"
            "{\n"
            "((RISCV*)cpu)->STVEC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVEC = %#x\\n\",((RISCV*)cpu)->STVEC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 262)\n"
            "{\n"
            "((RISCV*)cpu)->SCOUNTEREN = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCOUNTEREN = %#x\\n\",((RISCV*)cpu)->SCOUNTEREN); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 320)\n"
            "{\n"
            "((RISCV*)cpu)->SSCRATCH = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SSCRATCH = %#x\\n\",((RISCV*)cpu)->SSCRATCH); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 321)\n"
            "{\n"
            "((RISCV*)cpu)->SEPC = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SEPC = %#x\\n\",((RISCV*)cpu)->SEPC); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 322)\n"
            "{\n"
            "((RISCV*)cpu)->SCAUSE = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SCAUSE = %#x\\n\",((RISCV*)cpu)->SCAUSE); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 323)\n"
            "{\n"
            "((RISCV*)cpu)->STVAL = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->STVAL = %#x\\n\",((RISCV*)cpu)->STVAL); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 324)\n"
            "{\n"
            "((RISCV*)cpu)->SIP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SIP = %#x\\n\",((RISCV*)cpu)->SIP); \n"
#endif
            "}\n"

            "if(_i_csr_addr == 384)\n"
            "{\n"
            "((RISCV*)cpu)->SATP = _i_write_val;\n"
#if RISCV_DEBUG_CALL
            "printf(\"((RISCV*)cpu)->SATP = %#x\\n\",((RISCV*)cpu)->SATP); \n"
#endif
            "}\n"

            "cpu->instructionPointer = " +
            toString((uint32_t)(ic.current_address_ + 4)) +
            "ULL; \n"

            "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slli_rd_rs1_imm(ISA32, "slli", (uint32_t)0x1013, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm = 0;
                                                 static BitArrayRange R_imm_0(24, 20);
                                                 etiss_uint32 imm_0 = R_imm_0.read(ba);
                                                 imm += imm_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() = std::string("//slli\n") +
                                                                   "etiss_uint32 exception = 0;\n"
                                                                   "etiss_uint32 temp = 0;\n"
                                                                   "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                                   "etiss_uint32 R = 0; \n"
                                                                   "for ( int i = 0; i< 32 ; i++)\n"
                                                                   "{\n"
                                                                   "R ^= ((-*((RISCV*)cpu)->R[i])^R) & (1 << i ); \n"
                                                                   "}\n"

                                                                   "if(" +
                                                                   toString(rd) +
                                                                   " != 0)\n"
                                                                   "{\n"
                                                                   "*((RISCV*)cpu)->R[" +
                                                                   toString(rd) + "] = (*((RISCV*)cpu)->R[" +
                                                                   toString(rs1) + "] << " + toString(imm) +
                                                                   ");\n"
#if RISCV_DEBUG_CALL
                                                                   "printf(\"*((RISCV*)cpu)->R[" +
                                                                   toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" +
                                                                   toString(rd) +
                                                                   "]); \n"
#endif
                                                                   "}\n"

                                                                   "cpu->instructionPointer = " +
                                                                   toString((uint32_t)(ic.current_address_ + 4)) +
                                                                   "ULL; \n"

                                                                   "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sll_rd_rs1_rs2(ISA32, "sll", (uint32_t)0x1033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//sll\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                    "etiss_uint32 R = 0; \n"
                                                    "for ( int i = 0; i< 32 ; i++)\n"
                                                    "{\n"
                                                    "R ^= ((-*((RISCV*)cpu)->R[i])^R) & (1 << i ); \n"
                                                    "}\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] << (*((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "] & 0x1f));\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srli_rd_rs1_imm(ISA32, "srli", (uint32_t)0x5013, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm = 0;
                                                 static BitArrayRange R_imm_0(24, 20);
                                                 etiss_uint32 imm_0 = R_imm_0.read(ba);
                                                 imm += imm_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() = std::string("//srli\n") +
                                                                   "etiss_uint32 exception = 0;\n"
                                                                   "etiss_uint32 temp = 0;\n"
                                                                   "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                                   "etiss_uint32 R = 0; \n"
                                                                   "for ( int i = 0; i< 32 ; i++)\n"
                                                                   "{\n"
                                                                   "R ^= ((-*((RISCV*)cpu)->R[i])^R) & (1 << i ); \n"
                                                                   "}\n"

                                                                   "if(" +
                                                                   toString(rd) +
                                                                   " != 0)\n"
                                                                   "{\n"
                                                                   "*((RISCV*)cpu)->R[" +
                                                                   toString(rd) + "] = (*((RISCV*)cpu)->R[" +
                                                                   toString(rs1) + "] >> " + toString(imm) +
                                                                   ");\n"
#if RISCV_DEBUG_CALL
                                                                   "printf(\"*((RISCV*)cpu)->R[" +
                                                                   toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" +
                                                                   toString(rd) +
                                                                   "]); \n"
#endif
                                                                   "}\n"

                                                                   "cpu->instructionPointer = " +
                                                                   toString((uint32_t)(ic.current_address_ + 4)) +
                                                                   "ULL; \n"

                                                                   "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srl_rd_rs1_rs2(ISA32, "srl", (uint32_t)0x5033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//srl\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                    "etiss_uint32 R = 0; \n"
                                                    "for ( int i = 0; i< 32 ; i++)\n"
                                                    "{\n"
                                                    "R ^= ((-*((RISCV*)cpu)->R[i])^R) & (1 << i ); \n"
                                                    "}\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] >> (*((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "] & 0x1f));\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition add_rd_rs1_rs2(ISA32, "add", (uint32_t)0x33, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//add\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = *((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] + *((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "];\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slt_rd_rs1_rs2(ISA32, "slt", (uint32_t)0x2033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//slt\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                    "}\n"
                                                    "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                                                    toString(rs1) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                                                    "}\n"
                                                    "if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) +
                                                    "] = 1;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "else\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) +
                                                    "] = 0;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sltu_rd_rs1_rs2(ISA32, "sltu", (uint32_t)0x3033, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs2 = 0;
                                                 static BitArrayRange R_rs2_0(24, 20);
                                                 etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                 rs2 += rs2_0;
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//sltu\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "if(*((RISCV*)cpu)->R[" +
                                                     toString(rs1) + "] < *((RISCV*)cpu)->R[" + toString(rs2) +
                                                     "])\n"
                                                     "{\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     "] = 1;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "else\n"
                                                     "{\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     "] = 0;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 4)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition and_rd_rs1_rs2(ISA32, "and", (uint32_t)0x7033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//and\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] & *((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "]);\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition or_rd_rs1_rs2(ISA32, "or", (uint32_t)0x6033, (uint32_t)0xfe00707f,
                                           [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                               etiss_uint32 rs2 = 0;
                                               static BitArrayRange R_rs2_0(24, 20);
                                               etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                               rs2 += rs2_0;
                                               etiss_uint32 rs1 = 0;
                                               static BitArrayRange R_rs1_0(19, 15);
                                               etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                               rs1 += rs1_0;
                                               etiss_uint32 rd = 0;
                                               static BitArrayRange R_rd_0(11, 7);
                                               etiss_uint32 rd_0 = R_rd_0.read(ba);
                                               rd += rd_0;
                                               CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                               partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                               partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                               partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                               partInit.getAffectedRegisters().add("instructionPointer", 32);
                                               partInit.code() =
                                                   std::string("//or\n") +
                                                   "etiss_uint32 exception = 0;\n"
                                                   "etiss_uint32 temp = 0;\n"
                                                   "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                   "if(" +
                                                   toString(rd) +
                                                   " != 0)\n"
                                                   "{\n"
                                                   "*((RISCV*)cpu)->R[" +
                                                   toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                                                   "] | *((RISCV*)cpu)->R[" + toString(rs2) +
                                                   "]);\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"*((RISCV*)cpu)->R[" +
                                                   toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                   "]); \n"
#endif
                                                   "}\n"

                                                   "cpu->instructionPointer = " +
                                                   toString((uint32_t)(ic.current_address_ + 4)) +
                                                   "ULL; \n"

                                                   "return exception; \n";
                                               return true;
                                           },
                                           0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition xor_rd_rs1_rs2(ISA32, "xor", (uint32_t)0x4033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//xor\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] ^ *((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "]);\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srai_rd_rs1_imm(ISA32, "srai", (uint32_t)0x40005013, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm = 0;
                                                 static BitArrayRange R_imm_0(24, 20);
                                                 etiss_uint32 imm_0 = R_imm_0.read(ba);
                                                 imm += imm_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//srai\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                     toString(rs1) +
                                                     "]; \n"
                                                     "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                     "{\n"
                                                     "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                     "}\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = ((etiss_int32)cast_0 >> " + toString(imm) +
                                                     ");\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 4)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sra_rd_rs1_rs2(ISA32, "sra", (uint32_t)0x40005033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//sra\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                    toString(rs1) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                    "}\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = ((etiss_int32)cast_0 >> (*((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "] & 0x1f));\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sub_rd_rs1_rs2(ISA32, "sub", (uint32_t)0x40000033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//sub\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = *((RISCV*)cpu)->R[" + toString(rs1) +
                                                    "] - *((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "];\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fence_predecessor_successor_imm(
 		ISA32,
 		"fence",
 		(uint32_t)0xf,
 		(uint32_t) 0xf00fffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 successor = 0;
 		static BitArrayRange R_successor_0 (23,20);
 		etiss_uint32 successor_0 = R_successor_0.read(ba);
 		successor += successor_0;
 		etiss_uint32 predecessor = 0;
 		static BitArrayRange R_predecessor_0 (27,24);
 		etiss_uint32 predecessor_0 = R_predecessor_0.read(ba);
 		predecessor += predecessor_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fence\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fence_i_predecessor_successor(
    ISA32, "fence.i", (uint32_t)0x100f, (uint32_t)0xf00fffff,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 successor = 0;
        static BitArrayRange R_successor_0(23, 20);
        etiss_uint32 successor_0 = R_successor_0.read(ba);
        successor += successor_0;
        etiss_uint32 predecessor = 0;
        static BitArrayRange R_predecessor_0(27, 24);
        etiss_uint32 predecessor_0 = R_predecessor_0.read(ba);
        predecessor += predecessor_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//fence.i\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2(ISA32, "mul", (uint32_t)0x2000033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//mul\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                    "etiss_uint32 mul_result = 0;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "mul_result = (*((RISCV*)cpu)->R[" +
                                                    toString(rs1) + "] * *((RISCV*)cpu)->R[" + toString(rs2) +
                                                    "]);\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"mul_result = %#x\\n\",mul_result); \n"
#endif
                                                    "etiss_int32 cast_0 = mul_result; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                    "}\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) +
                                                    "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulh_rd_rs1_rs2(ISA32, "mulh", (uint32_t)0x2001033, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs2 = 0;
                                                 static BitArrayRange R_rs2_0(24, 20);
                                                 etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                 rs2 += rs2_0;
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//mulh\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_int64 mul_result = 0;\n"

                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                     toString(rs2) +
                                                     "]; \n"
                                                     "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                     "{\n"
                                                     "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                     "}\n"
                                                     "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                                                     toString(rs1) +
                                                     "]; \n"
                                                     "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                                                     "{\n"
                                                     "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                                                     "}\n"
                                                     "mul_result = ((etiss_int64)cast_1 * (etiss_int64)cast_0);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"mul_result = %#lx\\n\",mul_result); \n"
#endif
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     "] = (mul_result & 0xffffffff00000000)>>32;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 4)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulu_rd_rs1_rs2(ISA32, "mulu", (uint32_t)0x2003033, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs2 = 0;
                                                 static BitArrayRange R_rs2_0(24, 20);
                                                 etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                 rs2 += rs2_0;
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//mulu\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_uint64 mul_result = 0;\n"

                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "mul_result = ((etiss_uint64)*((RISCV*)cpu)->R[" +
                                                     toString(rs1) + "] * (etiss_uint64)*((RISCV*)cpu)->R[" +
                                                     toString(rs2) +
                                                     "]);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"mul_result = %#lx\\n\",mul_result); \n"
#endif
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     "] = (mul_result & 0xffffffff00000000)>>32;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 4)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulsu_rd_rs1_rs2(
    ISA32, "mulsu", (uint32_t)0x2002033, (uint32_t)0xfe00707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//mulsu\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint64 mul_result = 0;\n"

                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "]; \n"
                          "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                          "{\n"
                          "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                          "}\n"
                          "mul_result = ((etiss_int64)cast_0 * (etiss_uint64)*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "]);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mul_result = %#lx\\n\",mul_result); \n"
#endif
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = (mul_result & 0xffffffff00000000)>>32;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition div_rd_rs1_rs2(ISA32, "div", (uint32_t)0x2004033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//div\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                    "etiss_int32 quotient = 0;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "if(*((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "] == 0)\n"
                                                    "{\n"
                                                    "quotient = 4294967295;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"quotient = %#x\\n\",quotient); \n"
#endif
                                                    "}\n"

                                                    "else\n"
                                                    "{\n"
                                                    "if((*((RISCV*)cpu)->R[" +
                                                    toString(rs1) + "] == 2147483648) && (*((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "] == 4294967295))\n"
                                                    "{\n"
                                                    "quotient = 2147483648;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"quotient = %#x\\n\",quotient); \n"
#endif
                                                    "}\n"

                                                    "else\n"
                                                    "{\n"
                                                    "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                    "}\n"
                                                    "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                                                    toString(rs1) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                                                    "}\n"
                                                    "quotient = ((etiss_int32)cast_1 / (etiss_int32)cast_0);\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"quotient = %#x\\n\",quotient); \n"
#endif
                                                    "}\n"
                                                    "}\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) +
                                                    "] = quotient;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition divu_rd_rs1_rs2(ISA32, "divu", (uint32_t)0x2005033, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs2 = 0;
                                                 static BitArrayRange R_rs2_0(24, 20);
                                                 etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                 rs2 += rs2_0;
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//divu\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_int32 quotient = 0;\n"

                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "if(*((RISCV*)cpu)->R[" +
                                                     toString(rs2) +
                                                     "] == 0)\n"
                                                     "{\n"
                                                     "quotient = 4294967295;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"quotient = %#x\\n\",quotient); \n"
#endif
                                                     "}\n"

                                                     "else\n"
                                                     "{\n"
                                                     "quotient = (*((RISCV*)cpu)->R[" +
                                                     toString(rs1) + "] / *((RISCV*)cpu)->R[" + toString(rs2) +
                                                     "]);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"quotient = %#x\\n\",quotient); \n"
#endif
                                                     "}\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     "] = quotient;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 4)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition rem_rd_rs1_rs2(ISA32, "rem", (uint32_t)0x2006033, (uint32_t)0xfe00707f,
                                            [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                etiss_uint32 rs2 = 0;
                                                static BitArrayRange R_rs2_0(24, 20);
                                                etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                rs2 += rs2_0;
                                                etiss_uint32 rs1 = 0;
                                                static BitArrayRange R_rs1_0(19, 15);
                                                etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                rs1 += rs1_0;
                                                etiss_uint32 rd = 0;
                                                static BitArrayRange R_rd_0(11, 7);
                                                etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                rd += rd_0;
                                                CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                partInit.code() =
                                                    std::string("//rem\n") +
                                                    "etiss_uint32 exception = 0;\n"
                                                    "etiss_uint32 temp = 0;\n"
                                                    "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                    "etiss_uint32 remainder = 0;\n"

                                                    "if(" +
                                                    toString(rd) +
                                                    " != 0)\n"
                                                    "{\n"
                                                    "if(*((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "] == 0)\n"
                                                    "{\n"
                                                    "remainder = *((RISCV*)cpu)->R[" +
                                                    toString(rs1) +
                                                    "];\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"remainder = %#x\\n\",remainder); \n"
#endif
                                                    "}\n"

                                                    "else\n"
                                                    "{\n"
                                                    "if((*((RISCV*)cpu)->R[" +
                                                    toString(rs1) + "] == 2147483648) && (*((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "] == 4294967295))\n"
                                                    "{\n"
                                                    "remainder = 0;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"remainder = %#x\\n\",remainder); \n"
#endif
                                                    "}\n"

                                                    "else\n"
                                                    "{\n"
                                                    "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                    toString(rs2) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                    "}\n"
                                                    "etiss_int32 cast_1 = *((RISCV*)cpu)->R[" +
                                                    toString(rs1) +
                                                    "]; \n"
                                                    "if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
                                                    "{\n"
                                                    "cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
                                                    "}\n"
                                                    "remainder = ((etiss_int32)cast_1 % (etiss_int32)cast_0);\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"remainder = %#x\\n\",remainder); \n"
#endif
                                                    "}\n"
                                                    "}\n"
                                                    "*((RISCV*)cpu)->R[" +
                                                    toString(rd) +
                                                    "] = remainder;\n"
#if RISCV_DEBUG_CALL
                                                    "printf(\"*((RISCV*)cpu)->R[" +
                                                    toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                    "]); \n"
#endif
                                                    "}\n"

                                                    "cpu->instructionPointer = " +
                                                    toString((uint32_t)(ic.current_address_ + 4)) +
                                                    "ULL; \n"

                                                    "return exception; \n";
                                                return true;
                                            },
                                            0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition remu_rd_rs1_rs2(ISA32, "remu", (uint32_t)0x2007033, (uint32_t)0xfe00707f,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rs2 = 0;
                                                 static BitArrayRange R_rs2_0(24, 20);
                                                 etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                 rs2 += rs2_0;
                                                 etiss_uint32 rs1 = 0;
                                                 static BitArrayRange R_rs1_0(19, 15);
                                                 etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                 rs1 += rs1_0;
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rs2], 32);
                                                 partInit.getRegisterDependencies().add(reg_name[rs1], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//remu\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_uint32 remainder = 0;\n"

                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "if(*((RISCV*)cpu)->R[" +
                                                     toString(rs2) +
                                                     "] == 0)\n"
                                                     "{\n"
                                                     "remainder = *((RISCV*)cpu)->R[" +
                                                     toString(rs1) +
                                                     "];\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"remainder = %#x\\n\",remainder); \n"
#endif
                                                     "}\n"

                                                     "else\n"
                                                     "{\n"
                                                     "remainder = (*((RISCV*)cpu)->R[" +
                                                     toString(rs1) + "] % *((RISCV*)cpu)->R[" + toString(rs2) +
                                                     "]);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"remainder = %#x\\n\",remainder); \n"
#endif
                                                     "}\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     "] = remainder;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 4)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi4spn_rd_imm(
    ISA16, "c.addi4spn", (uint16_t)0x0, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(4, 2);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(12, 5);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[2], 32);
        partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.addi4spn\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm = 0;\n"
                          "etiss_uint16 sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "sign_extended_imm = ((_i_imm & 0x1) << 3) + ((_i_imm & 0x2)>>1 << 2) + ((_i_imm & 0x3c)>>2 "
                          "<< 6) + ((_i_imm & 0xc0)>>6 << 4);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          " + 8] = sign_extended_imm + *((RISCV*)cpu)->R[2];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          " + 8]); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi_rd_imm(ISA16, "c.addi", (uint16_t)0x1, (uint16_t)0xe003,
                                           [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                               etiss_uint32 rd = 0;
                                               static BitArrayRange R_rd_0(11, 7);
                                               etiss_uint32 rd_0 = R_rd_0.read(ba);
                                               rd += rd_0;
                                               etiss_uint32 imm2 = 0;
                                               static BitArrayRange R_imm2_0(12, 12);
                                               etiss_uint32 imm2_0 = R_imm2_0.read(ba);
                                               imm2 += imm2_0;
                                               etiss_uint32 imm1 = 0;
                                               static BitArrayRange R_imm1_0(6, 2);
                                               etiss_uint32 imm1_0 = R_imm1_0.read(ba);
                                               imm1 += imm1_0;
                                               CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                               partInit.getRegisterDependencies().add(reg_name[rd], 32);
                                               partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                               partInit.getAffectedRegisters().add("instructionPointer", 32);
                                               partInit.code() =
                                                   std::string("//c.addi\n") +
                                                   "etiss_uint32 exception = 0;\n"
                                                   "etiss_uint32 temp = 0;\n"
                                                   "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                   "etiss_uint8 _i_imm1 = 0;\n"
                                                   "etiss_uint8 _i_imm2 = 0;\n"
                                                   "etiss_int32 sign_extended_imm = 0;\n"
                                                   "etiss_int32 sign_extender = 0;\n"

                                                   "_i_imm1 = " +
                                                   toString(imm1) +
                                                   ";\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                                                   "_i_imm2 = " +
                                                   toString(imm2) +
                                                   ";\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                                                   "if(_i_imm2 == 1)\n"
                                                   "{\n"
                                                   "sign_extender = 4294967264;\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                                                   "}\n"

                                                   "else\n"
                                                   "{\n"
                                                   "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                                                   "}\n"
                                                   "sign_extended_imm = sign_extender + _i_imm1;\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                                                   "if(" +
                                                   toString(rd) +
                                                   " != 0)\n"
                                                   "{\n"
                                                   "*((RISCV*)cpu)->R[" +
                                                   toString(rd) + "] = sign_extended_imm + *((RISCV*)cpu)->R[" +
                                                   toString(rd) +
                                                   "];\n"
#if RISCV_DEBUG_CALL
                                                   "printf(\"*((RISCV*)cpu)->R[" +
                                                   toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                   "]); \n"
#endif
                                                   "}\n"

                                                   "cpu->instructionPointer = " +
                                                   toString((uint32_t)(ic.current_address_ + 2)) +
                                                   "ULL; \n"

                                                   "return exception; \n";
                                               return true;
                                           },
                                           0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_slli_rd_shamt(ISA16, "c.slli", (uint16_t)0x2, (uint16_t)0xe003,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(11, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm2 = 0;
                                                 static BitArrayRange R_imm2_0(12, 12);
                                                 etiss_uint32 imm2_0 = R_imm2_0.read(ba);
                                                 imm2 += imm2_0;
                                                 etiss_uint32 imm1 = 0;
                                                 static BitArrayRange R_imm1_0(6, 2);
                                                 etiss_uint32 imm1_0 = R_imm1_0.read(ba);
                                                 imm1 += imm1_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//c.slli\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_uint32 R = 0; \n"
                                                     "for ( int i = 0; i< 32 ; i++)\n"
                                                     "{\n"
                                                     "R ^= ((-*((RISCV*)cpu)->R[i])^R) & (1 << i ); \n"
                                                     "}\n"
                                                     "etiss_uint8 _i_imm1 = 0;\n"
                                                     "etiss_uint8 _i_imm2 = 0;\n"

                                                     "_i_imm1 = " +
                                                     toString(imm1) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                                                     "_i_imm2 = " +
                                                     toString(imm2) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                                                     "if(" +
                                                     toString(rd) +
                                                     " != 0)\n"
                                                     "{\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = (*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "] << _i_imm1);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                     "]); \n"
#endif
                                                     "}\n"

                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 2)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lw_rd_rs1_imm(
    ISA16, "c.lw", (uint16_t)0x4000, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(9, 7);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(4, 2);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(12, 10);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(6, 5);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1 + 8], 32);
        partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.lw\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_uint32 o_data = 0;\n"
                          "etiss_uint8 sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "sign_extended_imm = (_i_imm2 << 3) + ((_i_imm1 & 0x2)>>1 << 2) + ((_i_imm1 & 0x1) << 6);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          " + 8] + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif

                // FIXME: Manual edit.
                "exception = (*(system->dread))(system->handle, cpu, mem_addr, tmpbuf, 4);\n"
                "o_data = temp;\n"

#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          " + 8] = o_data;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          " + 8]); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_li_rd_imm(ISA16, "c.li", (uint16_t)0x4001, (uint16_t)0xe003,
                                         [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                             etiss_uint32 rd = 0;
                                             static BitArrayRange R_rd_0(11, 7);
                                             etiss_uint32 rd_0 = R_rd_0.read(ba);
                                             rd += rd_0;
                                             etiss_uint32 imm2 = 0;
                                             static BitArrayRange R_imm2_0(12, 12);
                                             etiss_uint32 imm2_0 = R_imm2_0.read(ba);
                                             imm2 += imm2_0;
                                             etiss_uint32 imm1 = 0;
                                             static BitArrayRange R_imm1_0(6, 2);
                                             etiss_uint32 imm1_0 = R_imm1_0.read(ba);
                                             imm1 += imm1_0;
                                             CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                             partInit.getAffectedRegisters().add(reg_name[rd], 32);
                                             partInit.getAffectedRegisters().add("instructionPointer", 32);
                                             partInit.code() =
                                                 std::string("//c.li\n") +
                                                 "etiss_uint32 exception = 0;\n"
                                                 "etiss_uint32 temp = 0;\n"
                                                 "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                 "etiss_uint8 _i_imm1 = 0;\n"
                                                 "etiss_uint8 _i_imm2 = 0;\n"
                                                 "etiss_int32 sign_extended_imm = 0;\n"
                                                 "etiss_int32 sign_extender = 0;\n"

                                                 "_i_imm1 = " +
                                                 toString(imm1) +
                                                 ";\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                                                 "_i_imm2 = " +
                                                 toString(imm2) +
                                                 ";\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                                                 "if(_i_imm2 == 1)\n"
                                                 "{\n"
                                                 "sign_extender = 4294967264;\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                                                 "}\n"

                                                 "else\n"
                                                 "{\n"
                                                 "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                                                 "}\n"
                                                 "sign_extended_imm = sign_extender + _i_imm1;\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                                                 "if(" +
                                                 toString(rd) +
                                                 " != 0)\n"
                                                 "{\n"
                                                 "*((RISCV*)cpu)->R[" +
                                                 toString(rd) +
                                                 "] = sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"*((RISCV*)cpu)->R[" +
                                                 toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                 "]); \n"
#endif
                                                 "}\n"

                                                 "cpu->instructionPointer = " +
                                                 toString((uint32_t)(ic.current_address_ + 2)) +
                                                 "ULL; \n"

                                                 "return exception; \n";
                                             return true;
                                         },
                                         0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lwsp_rd_imm(
    ISA16, "c.lwsp", (uint16_t)0x4002, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(12, 12);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(6, 2);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[2], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.lwsp\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_uint32 o_data = 0;\n"
                          "etiss_uint8 sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "sign_extended_imm = ((_i_imm1 & 0x3) << 6) + ((_i_imm1 & 0x1c)>>2 << 2) + (_i_imm2 << 5);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[2] + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_3;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
                          "o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_2;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
                          "o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
                          "o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
                          "o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = o_data;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sw_rs1_rs2_imm(
    ISA16, "c.sw", (uint16_t)0xc000, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(4, 2);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(9, 7);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(12, 10);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(6, 5);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2 + 8], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1 + 8], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.sw\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_uint8 sign_extended_imm = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "sign_extended_imm = (_i_imm2 << 3) + ((_i_imm1 & 0x2)>>1 << 2) + ((_i_imm1 & 0x1) << 6);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          " + 8] + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif

                // FIXME: Manual edit.
                "temp = (*((RISCV*)cpu)->R[" + toString(rs2) + " + 8]);\n"
                "exception = (*(system->dwrite))(system->handle, cpu, mem_addr, tmpbuf, 4);\n"

                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_beqz_rs1_imm(
    ISA16, "c.beqz", (uint16_t)0xc001, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(9, 7);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(12, 10);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(6, 2);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1 + 8], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.beqz\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 sign_extended_imm = 0;\n"
                          "etiss_int32 sign_extender = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x4)>>2 == 1)\n"
                          "{\n"
                          "sign_extender = 4294967040;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"
                          "sign_extended_imm = sign_extender + ((_i_imm2 & 0x3) << 3) + ((_i_imm1 & 0x6)>>1 << 1) + "
                          "((_i_imm1 & 0x1) << 5) + ((_i_imm1 & 0x18)>>3 << 6);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          " + 8] == 0)\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_swsp_rs2_imm(
    ISA16, "c.swsp", (uint16_t)0xc002, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(6, 2);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(12, 7);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.swsp\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "sign_extended_imm = ((_i_imm & 0x3) << 6) + ((_i_imm & 0x3c)>>2 << 2);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[2] + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_3;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
                          "M_mem_addr_3 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff000000)>>24;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_3 = %#x\\n\",M_mem_addr_3); \n"
#endif
                          " etiss_uint8 M_mem_addr_2;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
                          "M_mem_addr_2 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff0000)>>16;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_2 = %#x\\n\",M_mem_addr_2); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "M_mem_addr_1 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff00)>>8;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_1 = %#x\\n\",M_mem_addr_1); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "M_mem_addr_0 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff);\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_0 = %#x\\n\",M_mem_addr_0); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);

static InstructionDefinition c_fswsp_rs2_imm(
    ISA16, "c.fswsp", (uint16_t)0xe002, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(6, 2);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(12, 7);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.swsp\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm = 0;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint8 sign_extended_imm = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "sign_extended_imm = ((_i_imm & 0x3) << 6) + ((_i_imm & 0x3c)>>2 << 2);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "mem_addr = *((RISCV*)cpu)->R[2] + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_3;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
                          "M_mem_addr_3 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff000000)>>24;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_3 = %#x\\n\",M_mem_addr_3); \n"
#endif
                          " etiss_uint8 M_mem_addr_2;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
                          "M_mem_addr_2 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff0000)>>16;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_2 = %#x\\n\",M_mem_addr_2); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "M_mem_addr_1 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff00)>>8;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_1 = %#x\\n\",M_mem_addr_1); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "M_mem_addr_0 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff);\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_0 = %#x\\n\",M_mem_addr_0); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);

//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_jal_imm(
    ISA16, "c.jal", (uint16_t)0x2001, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(12, 2);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add(reg_name[1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.jal\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 sign_extended_imm = 0;\n"
                          "etiss_int32 sign_extender = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x400)>>10 == 1)\n"
                          "{\n"
                          "sign_extender = 4294965248;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"
                          "sign_extended_imm = sign_extender + ((_i_imm & 0x1) << 5) + ((_i_imm & 0xe)>>1 << 1) + "
                          "((_i_imm & 0x10)>>4 << 7) + ((_i_imm & 0x20)>>5 << 6) + ((_i_imm & 0x40)>>6 << 10) + "
                          "((_i_imm & 0x180)>>7 << 8) + ((_i_imm & 0x200)>>9 << 4);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "*((RISCV*)cpu)->R[1] = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + 2;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[1] = %#x\\n\",*((RISCV*)cpu)->R[1]); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lui_rd_imm(
 		ISA16,
 		"c.lui",
 		(uint16_t)0x6001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 imm2 = 0;
 		static BitArrayRange R_imm2_0 (12,12);
 		etiss_uint32 imm2_0 = R_imm2_0.read(ba);
 		imm2 += imm2_0;
 		etiss_uint32 imm1 = 0;
 		static BitArrayRange R_imm1_0 (6,2);
 		etiss_uint32 imm1_0 = R_imm1_0.read(ba);
 		imm1 += imm1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
 		partInit.getAffectedRegisters().add(reg_name[2],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.lui\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_int32 sign_extended_imm_16sp = 0;\n"
 			"etiss_int32 sign_extender_16sp = 0;\n"
 			"etiss_uint8 _i_imm1 = 0;\n"
 			"etiss_uint8 _i_imm2 = 0;\n"
 			"etiss_int32 sign_extended_imm = 0;\n"
 			"etiss_int32 sign_extender = 0;\n"
 			
			"_i_imm1 = " + toString(imm1) + ";\n"
			#if RISCV_DEBUG_CALL
			"printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
			#endif	
			"_i_imm2 = " + toString(imm2) + ";\n"
			#if RISCV_DEBUG_CALL
			"printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
			#endif	
			"if(" + toString(rd) + " == 2)\n"
			"{\n"
				"if(_i_imm2 == 1)\n"
				"{\n"
					"sign_extender_16sp = 4294966784;\n"
					#if RISCV_DEBUG_CALL
					"printf(\"sign_extender_16sp = %#x\\n\",sign_extender_16sp); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"sign_extender_16sp = 0;\n"
					#if RISCV_DEBUG_CALL
					"printf(\"sign_extender_16sp = %#x\\n\",sign_extender_16sp); \n"
					#endif	
				"}\n"
				"sign_extended_imm_16sp = sign_extender_16sp + ((_i_imm1 & 0x1) << 5) + ((_i_imm1 & 0x6)>>1 << 7) + ((_i_imm1 & 0x8)>>3 << 6) + ((_i_imm1 & 0x10)>>4 << 4);\n"
				#if RISCV_DEBUG_CALL
				"printf(\"sign_extended_imm_16sp = %#x\\n\",sign_extended_imm_16sp); \n"
				#endif	
				"*((RISCV*)cpu)->R[2] = sign_extended_imm_16sp + *((RISCV*)cpu)->R[2];\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[2] = %#x\\n\",*((RISCV*)cpu)->R[2]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"if(_i_imm2 == 1)\n"
					"{\n"
						"sign_extender = 4294836224;\n"
						#if RISCV_DEBUG_CALL
						"printf(\"sign_extender = %#x\\n\",sign_extender); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"sign_extender = 0;\n"
						#if RISCV_DEBUG_CALL
						"printf(\"sign_extender = %#x\\n\",sign_extender); \n"
						#endif	
					"}\n"
					"sign_extended_imm = sign_extender + (_i_imm1 << 12);\n"
					#if RISCV_DEBUG_CALL
					"printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
					#endif	
					"*((RISCV*)cpu)->R[" + toString(rd) + "] = sign_extended_imm;\n"
					#if RISCV_DEBUG_CALL
					"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
			"}\n"
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_srli_rd_shamt(ISA16, "c.srli", (uint16_t)0x8001, (uint16_t)0xec03,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(9, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm2 = 0;
                                                 static BitArrayRange R_imm2_0(12, 12);
                                                 etiss_uint32 imm2_0 = R_imm2_0.read(ba);
                                                 imm2 += imm2_0;
                                                 etiss_uint32 imm1 = 0;
                                                 static BitArrayRange R_imm1_0(6, 2);
                                                 etiss_uint32 imm1_0 = R_imm1_0.read(ba);
                                                 imm1 += imm1_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//c.srli\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_uint32 R = 0; \n"
                                                     "for ( int i = 0; i< 32 ; i++)\n"
                                                     "{\n"
                                                     "R ^= ((-*((RISCV*)cpu)->R[i])^R) & (1 << i ); \n"
                                                     "}\n"
                                                     "etiss_uint8 _i_imm1 = 0;\n"
                                                     "etiss_uint8 _i_imm2 = 0;\n"

                                                     "_i_imm1 = " +
                                                     toString(imm1) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                                                     "_i_imm2 = " +
                                                     toString(imm2) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) + " + 8] = (*((RISCV*)cpu)->R[" + toString(rd) +
                                                     " + 8] >> _i_imm1);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     " + 8]); \n"
#endif
                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 2)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_srai_rd_shamt(ISA16, "c.srai", (uint16_t)0x8401, (uint16_t)0xec03,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(9, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm2 = 0;
                                                 static BitArrayRange R_imm2_0(12, 12);
                                                 etiss_uint32 imm2_0 = R_imm2_0.read(ba);
                                                 imm2 += imm2_0;
                                                 etiss_uint32 imm1 = 0;
                                                 static BitArrayRange R_imm1_0(6, 2);
                                                 etiss_uint32 imm1_0 = R_imm1_0.read(ba);
                                                 imm1 += imm1_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//c.srai\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_uint8 _i_imm1 = 0;\n"
                                                     "etiss_uint8 _i_imm2 = 0;\n"

                                                     "_i_imm1 = " +
                                                     toString(imm1) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                                                     "_i_imm2 = " +
                                                     toString(imm2) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                                                     "etiss_int32 cast_0 = *((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     " + 8]; \n"
                                                     "if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
                                                     "{\n"
                                                     "cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
                                                     "}\n"
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     " + 8] = ((etiss_int32)cast_0 >> _i_imm1);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     " + 8]); \n"
#endif
                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 2)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_andi_rd_shamt(ISA16, "c.andi", (uint16_t)0x8801, (uint16_t)0xec03,
                                             [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                 etiss_uint32 rd = 0;
                                                 static BitArrayRange R_rd_0(9, 7);
                                                 etiss_uint32 rd_0 = R_rd_0.read(ba);
                                                 rd += rd_0;
                                                 etiss_uint32 imm2 = 0;
                                                 static BitArrayRange R_imm2_0(12, 12);
                                                 etiss_uint32 imm2_0 = R_imm2_0.read(ba);
                                                 imm2 += imm2_0;
                                                 etiss_uint32 imm1 = 0;
                                                 static BitArrayRange R_imm1_0(6, 2);
                                                 etiss_uint32 imm1_0 = R_imm1_0.read(ba);
                                                 imm1 += imm1_0;
                                                 CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                 partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                                 partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                                 partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                 partInit.code() =
                                                     std::string("//c.andi\n") +
                                                     "etiss_uint32 exception = 0;\n"
                                                     "etiss_uint32 temp = 0;\n"
                                                     "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                     "etiss_uint8 _i_imm1 = 0;\n"
                                                     "etiss_uint8 _i_imm2 = 0;\n"
                                                     "etiss_int32 sign_extended_imm = 0;\n"
                                                     "etiss_int32 sign_extender = 0;\n"

                                                     "_i_imm1 = " +
                                                     toString(imm1) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                                                     "_i_imm2 = " +
                                                     toString(imm2) +
                                                     ";\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                                                     "if(_i_imm2 == 1)\n"
                                                     "{\n"
                                                     "sign_extender = 4294967264;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                                                     "}\n"

                                                     "else\n"
                                                     "{\n"
                                                     "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                                                     "}\n"
                                                     "sign_extended_imm = sign_extender + _i_imm1;\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                                                     "*((RISCV*)cpu)->R[" +
                                                     toString(rd) + " + 8] = (*((RISCV*)cpu)->R[" + toString(rd) +
                                                     " + 8] & sign_extended_imm);\n"
#if RISCV_DEBUG_CALL
                                                     "printf(\"*((RISCV*)cpu)->R[" +
                                                     toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" +
                                                     toString(rd) +
                                                     " + 8]); \n"
#endif
                                                     "cpu->instructionPointer = " +
                                                     toString((uint32_t)(ic.current_address_ + 2)) +
                                                     "ULL; \n"

                                                     "return exception; \n";
                                                 return true;
                                             },
                                             0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sub_rd_rs2(ISA16, "c.sub", (uint16_t)0x8c01, (uint16_t)0xfc63,
                                          [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                              etiss_uint32 rs2 = 0;
                                              static BitArrayRange R_rs2_0(4, 2);
                                              etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                              rs2 += rs2_0;
                                              etiss_uint32 rd = 0;
                                              static BitArrayRange R_rd_0(9, 7);
                                              etiss_uint32 rd_0 = R_rd_0.read(ba);
                                              rd += rd_0;
                                              CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                              partInit.getRegisterDependencies().add(reg_name[rs2 + 8], 32);
                                              partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                              partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                              partInit.getAffectedRegisters().add("instructionPointer", 32);
                                              partInit.code() =
                                                  std::string("//c.sub\n") +
                                                  "etiss_uint32 exception = 0;\n"
                                                  "etiss_uint32 temp = 0;\n"
                                                  "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                  "*((RISCV*)cpu)->R[" +
                                                  toString(rd) + " + 8] = *((RISCV*)cpu)->R[" + toString(rd) +
                                                  " + 8] - *((RISCV*)cpu)->R[" + toString(rs2) +
                                                  " + 8];\n"
#if RISCV_DEBUG_CALL
                                                  "printf(\"*((RISCV*)cpu)->R[" +
                                                  toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                  " + 8]); \n"
#endif
                                                  "cpu->instructionPointer = " +
                                                  toString((uint32_t)(ic.current_address_ + 2)) +
                                                  "ULL; \n"

                                                  "return exception; \n";
                                              return true;
                                          },
                                          0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_xor_rd_rs2(ISA16, "c.xor", (uint16_t)0x8c21, (uint16_t)0xfc63,
                                          [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                              etiss_uint32 rs2 = 0;
                                              static BitArrayRange R_rs2_0(4, 2);
                                              etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                              rs2 += rs2_0;
                                              etiss_uint32 rd = 0;
                                              static BitArrayRange R_rd_0(9, 7);
                                              etiss_uint32 rd_0 = R_rd_0.read(ba);
                                              rd += rd_0;
                                              CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                              partInit.getRegisterDependencies().add(reg_name[rs2 + 8], 32);
                                              partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                              partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                              partInit.getAffectedRegisters().add("instructionPointer", 32);
                                              partInit.code() =
                                                  std::string("//c.xor\n") +
                                                  "etiss_uint32 exception = 0;\n"
                                                  "etiss_uint32 temp = 0;\n"
                                                  "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                  "*((RISCV*)cpu)->R[" +
                                                  toString(rd) + " + 8] = (*((RISCV*)cpu)->R[" + toString(rs2) +
                                                  " + 8] ^ *((RISCV*)cpu)->R[" + toString(rd) +
                                                  " + 8]);\n"
#if RISCV_DEBUG_CALL
                                                  "printf(\"*((RISCV*)cpu)->R[" +
                                                  toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                  " + 8]); \n"
#endif
                                                  "cpu->instructionPointer = " +
                                                  toString((uint32_t)(ic.current_address_ + 2)) +
                                                  "ULL; \n"

                                                  "return exception; \n";
                                              return true;
                                          },
                                          0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_or_rd_rs2(ISA16, "c.or", (uint16_t)0x8c41, (uint16_t)0xfc63,
                                         [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                             etiss_uint32 rs2 = 0;
                                             static BitArrayRange R_rs2_0(4, 2);
                                             etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                             rs2 += rs2_0;
                                             etiss_uint32 rd = 0;
                                             static BitArrayRange R_rd_0(9, 7);
                                             etiss_uint32 rd_0 = R_rd_0.read(ba);
                                             rd += rd_0;
                                             CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                             partInit.getRegisterDependencies().add(reg_name[rs2 + 8], 32);
                                             partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                             partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                             partInit.getAffectedRegisters().add("instructionPointer", 32);
                                             partInit.code() =
                                                 std::string("//c.or\n") +
                                                 "etiss_uint32 exception = 0;\n"
                                                 "etiss_uint32 temp = 0;\n"
                                                 "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                 "*((RISCV*)cpu)->R[" +
                                                 toString(rd) + " + 8] = (*((RISCV*)cpu)->R[" + toString(rs2) +
                                                 " + 8] | *((RISCV*)cpu)->R[" + toString(rd) +
                                                 " + 8]);\n"
#if RISCV_DEBUG_CALL
                                                 "printf(\"*((RISCV*)cpu)->R[" +
                                                 toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                 " + 8]); \n"
#endif
                                                 "cpu->instructionPointer = " +
                                                 toString((uint32_t)(ic.current_address_ + 2)) +
                                                 "ULL; \n"

                                                 "return exception; \n";
                                             return true;
                                         },
                                         0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_and_rd_rs2(ISA16, "c.and", (uint16_t)0x8c61, (uint16_t)0xfc63,
                                          [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                              etiss_uint32 rs2 = 0;
                                              static BitArrayRange R_rs2_0(4, 2);
                                              etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                              rs2 += rs2_0;
                                              etiss_uint32 rd = 0;
                                              static BitArrayRange R_rd_0(9, 7);
                                              etiss_uint32 rd_0 = R_rd_0.read(ba);
                                              rd += rd_0;
                                              CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                              partInit.getRegisterDependencies().add(reg_name[rs2 + 8], 32);
                                              partInit.getRegisterDependencies().add(reg_name[rd + 8], 32);
                                              partInit.getAffectedRegisters().add(reg_name[rd + 8], 32);
                                              partInit.getAffectedRegisters().add("instructionPointer", 32);
                                              partInit.code() =
                                                  std::string("//c.and\n") +
                                                  "etiss_uint32 exception = 0;\n"
                                                  "etiss_uint32 temp = 0;\n"
                                                  "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                  "*((RISCV*)cpu)->R[" +
                                                  toString(rd) + " + 8] = (*((RISCV*)cpu)->R[" + toString(rs2) +
                                                  " + 8] & *((RISCV*)cpu)->R[" + toString(rd) +
                                                  " + 8]);\n"
#if RISCV_DEBUG_CALL
                                                  "printf(\"*((RISCV*)cpu)->R[" +
                                                  toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                                                  " + 8]); \n"
#endif
                                                  "cpu->instructionPointer = " +
                                                  toString((uint32_t)(ic.current_address_ + 2)) +
                                                  "ULL; \n"

                                                  "return exception; \n";
                                              return true;
                                          },
                                          0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_j_imm(
    ISA16, "c.j", (uint16_t)0xa001, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 imm = 0;
        static BitArrayRange R_imm_0(12, 2);
        etiss_uint32 imm_0 = R_imm_0.read(ba);
        imm += imm_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.j\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint16 _i_imm = 0;\n"
                          "etiss_int32 sign_extended_imm = 0;\n"
                          "etiss_int32 sign_extender = 0;\n"

                          "_i_imm = " +
                          toString(imm) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm = %#x\\n\",_i_imm); \n"
#endif
                          "if((_i_imm & 0x400)>>10 == 1)\n"
                          "{\n"
                          "sign_extender = 4294965248;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"
                          "sign_extended_imm = sign_extender + ((_i_imm & 0x1) << 5) + ((_i_imm & 0xe)>>1 << 1) + "
                          "((_i_imm & 0x10)>>4 << 7) + ((_i_imm & 0x20)>>5 << 6) + ((_i_imm & 0x40)>>6 << 10) + "
                          "((_i_imm & 0x180)>>7 << 8) + ((_i_imm & 0x200)>>9 << 4);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_bnez_rs1_imm(
    ISA16, "c.bnez", (uint16_t)0xe001, (uint16_t)0xe003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(9, 7);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 imm2 = 0;
        static BitArrayRange R_imm2_0(12, 10);
        etiss_uint32 imm2_0 = R_imm2_0.read(ba);
        imm2 += imm2_0;
        etiss_uint32 imm1 = 0;
        static BitArrayRange R_imm1_0(6, 2);
        etiss_uint32 imm1_0 = R_imm1_0.read(ba);
        imm1 += imm1_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1 + 8], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.bnez\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint8 _i_imm1 = 0;\n"
                          "etiss_uint8 _i_imm2 = 0;\n"
                          "etiss_int32 sign_extended_imm = 0;\n"
                          "etiss_int32 sign_extender = 0;\n"

                          "_i_imm1 = " +
                          toString(imm1) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm1 = %#x\\n\",_i_imm1); \n"
#endif
                          "_i_imm2 = " +
                          toString(imm2) +
                          ";\n"
#if RISCV_DEBUG_CALL
                          "printf(\"_i_imm2 = %#x\\n\",_i_imm2); \n"
#endif
                          "if((_i_imm2 & 0x4)>>2 == 1)\n"
                          "{\n"
                          "sign_extender = 4294967040;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "sign_extender = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extender = %#x\\n\",sign_extender); \n"
#endif
                          "}\n"
                          "sign_extended_imm = sign_extender + ((_i_imm2 & 0x3) << 3) + ((_i_imm1 & 0x6)>>1 << 1) + "
                          "((_i_imm1 & 0x1) << 5) + ((_i_imm1 & 0x18)>>3 << 6);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"sign_extended_imm = %#x\\n\",sign_extended_imm); \n"
#endif
                          "if(*((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          " + 8] != 0)\n"
                          "{\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + sign_extended_imm;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_mv_rd_rs2(
    ISA16, "c.mv", (uint16_t)0x8002, (uint16_t)0xf003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(6, 2);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rd], 32);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.mv\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                          "if(" +
                          toString(rs2) +
                          " == 0)\n"
                          "{\n"
                          "cpu->instructionPointer = *((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = *((RISCV*)cpu)->R[" + toString(rs2) +
                          "];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_add_rd_rs2(
    ISA16, "c.add", (uint16_t)0x9002, (uint16_t)0xf003,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(6, 2);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rd], 32);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add(reg_name[1], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//c.add\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                          "if(" +
                          toString(rs2) +
                          " == 0)\n"
                          "{\n"
                          "if(" + toString(rd) + " == 0){\n"
                          "return ETISS_RETURNCODE_CPUFINISHED;\n"
                          "} else {\n"
                          "*((RISCV*)cpu)->R[1] = " +
                          toString((uint32_t)ic.current_address_) +
                          "ULL  + 2;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[1] = %#x\\n\",*((RISCV*)cpu)->R[1]); \n"
#endif
                          "cpu->instructionPointer = *((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "}}\n"

                          "else\n"
                          "{\n"
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = *((RISCV*)cpu)->R[" + toString(rs2) + "] + *((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          // Explicit assignment to PC
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 2)) +
                          "ULL; \n"
                          "}\n"
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lr_w_rd_rs1(
    ISA32, "lr.w", (uint32_t)0x1000202f, (uint32_t)0xf9f0707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 aq = 0;
        static BitArrayRange R_aq_0(26, 26);
        etiss_uint32 aq_0 = R_aq_0.read(ba);
        aq += aq_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 rl = 0;
        static BitArrayRange R_rl_0(25, 25);
        etiss_uint32 rl_0 = R_rl_0.read(ba);
        rl += rl_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//lr.w\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint32 mem_addr = 0;\n"
                          "etiss_uint32 o_data = 0;\n"

                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_3;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
                          "o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_2;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
                          "o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
                          "o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
                          "o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"o_data = %#x\\n\",o_data); \n"
#endif
                          "if(" +
                          toString(rd) +
                          " != 0)\n"
                          "{\n"
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = o_data;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "}\n"

                          "else\n"
                          "{\n"
                          "}\n"
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sc_w_rd_rs1_rs2(
    ISA32, "sc.w", (uint32_t)0x1800202f, (uint32_t)0xf800707f,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        etiss_uint32 aq = 0;
        static BitArrayRange R_aq_0(26, 26);
        etiss_uint32 aq_0 = R_aq_0.read(ba);
        aq += aq_0;
        etiss_uint32 rs2 = 0;
        static BitArrayRange R_rs2_0(24, 20);
        etiss_uint32 rs2_0 = R_rs2_0.read(ba);
        rs2 += rs2_0;
        etiss_uint32 rs1 = 0;
        static BitArrayRange R_rs1_0(19, 15);
        etiss_uint32 rs1_0 = R_rs1_0.read(ba);
        rs1 += rs1_0;
        etiss_uint32 rd = 0;
        static BitArrayRange R_rd_0(11, 7);
        etiss_uint32 rd_0 = R_rd_0.read(ba);
        rd += rd_0;
        etiss_uint32 rl = 0;
        static BitArrayRange R_rl_0(25, 25);
        etiss_uint32 rl_0 = R_rl_0.read(ba);
        rl += rl_0;
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getRegisterDependencies().add(reg_name[rs2], 32);
        partInit.getRegisterDependencies().add(reg_name[rs1], 32);
        partInit.getAffectedRegisters().add(reg_name[rd], 32);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//sc.w\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                          "etiss_uint32 mem_addr = 0;\n"

                          "mem_addr = *((RISCV*)cpu)->R[" +
                          toString(rs1) +
                          "];\n"
#if RISCV_DEBUG_CALL
                          "printf(\"mem_addr = %#x\\n\",mem_addr); \n"
#endif
                          " etiss_uint8 M_mem_addr_3;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
                          "M_mem_addr_3 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff000000)>>24;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_3 = %#x\\n\",M_mem_addr_3); \n"
#endif
                          " etiss_uint8 M_mem_addr_2;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
                          "M_mem_addr_2 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff0000)>>16;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_2 = %#x\\n\",M_mem_addr_2); \n"
#endif
                          " etiss_uint8 M_mem_addr_1;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
                          "M_mem_addr_1 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff00)>>8;\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_1 = %#x\\n\",M_mem_addr_1); \n"
#endif
                          " etiss_uint8 M_mem_addr_0;\n"
                          " tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
                          "M_mem_addr_0 = (*((RISCV*)cpu)->R[" +
                          toString(rs2) +
                          "] & 0xff);\n"
                          "exception = (*(system->dwrite))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"M_mem_addr_0 = %#x\\n\",M_mem_addr_0); \n"
#endif
                          "*((RISCV*)cpu)->R[" +
                          toString(rd) +
                          "] = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->R[" +
                          toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) +
                          "]); \n"
#endif
                          "cpu->instructionPointer = " +
                          toString((uint32_t)(ic.current_address_ + 4)) +
                          "ULL; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoswap_w_rd_rs1_rs2(
 		ISA32,
 		"amoswap.w",
 		(uint32_t)0x800202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
 		partInit.getAffectedRegisters().add(reg_name[rs2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoswap.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (*((RISCV*)cpu)->R[" + toString(rs2) + "] & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (*((RISCV*)cpu)->R[" + toString(rs2) + "] & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (*((RISCV*)cpu)->R[" + toString(rs2) + "] & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (*((RISCV*)cpu)->R[" + toString(rs2) + "] & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
			"*((RISCV*)cpu)->R[" + toString(rs2) + "] = o_data;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"*((RISCV*)cpu)->R[" + toString(rs2) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rs2) + "]); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoadd_w_rd_rs1_rs2(
 		ISA32,
 		"amoadd.w",
 		(uint32_t)0x202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoadd.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = o_data + *((RISCV*)cpu)->R[" + toString(rs2) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoxor_w_rd_rs1_rs2(
 		ISA32,
 		"amoxor.w",
 		(uint32_t)0x2000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoxor.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = (o_data ^ *((RISCV*)cpu)->R[" + toString(rs2) + "]);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoand_w_rd_rs1_rs2(
 		ISA32,
 		"amoand.w",
 		(uint32_t)0x6000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoand.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = (o_data & *((RISCV*)cpu)->R[" + toString(rs2) + "]);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoor_w_rd_rs1_rs2(
 		ISA32,
 		"amoor.w",
 		(uint32_t)0x4000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoor.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = (o_data | *((RISCV*)cpu)->R[" + toString(rs2) + "]);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomin_w_rd_rs1_rs2(
 		ISA32,
 		"amomin.w",
 		(uint32_t)0x8000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amomin.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = o_data;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"etiss_int32 cast_0 = *((RISCV*)cpu)->R[" + toString(rs2) + "]; \n"
			"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
			"}\n"
			"etiss_int32 cast_1 = o_data; \n"
			"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
			"}\n"
			"if((etiss_int32)cast_1 > (etiss_int32)cast_0)\n"
			"{\n"
				"result = *((RISCV*)cpu)->R[" + toString(rs2) + "];\n"
				#if RISCV_DEBUG_CALL
				"printf(\"result = %#x\\n\",result); \n"
				#endif	
			"}\n"
			
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomax_w_rd_rs1_rs2(
 		ISA32,
 		"amomax.w",
 		(uint32_t)0xa000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amomax.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = o_data;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"etiss_int32 cast_0 = *((RISCV*)cpu)->R[" + toString(rs2) + "]; \n"
			"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
			"}\n"
			"etiss_int32 cast_1 = o_data; \n"
			"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
			"}\n"
			"if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
			"{\n"
				"result = *((RISCV*)cpu)->R[" + toString(rs2) + "];\n"
				#if RISCV_DEBUG_CALL
				"printf(\"result = %#x\\n\",result); \n"
				#endif	
			"}\n"
			
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amominu_w_rd_rs1_rs2(
 		ISA32,
 		"amominu.w",
 		(uint32_t)0xc000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amominu.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = o_data;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"if((etiss_uint32)o_data > (etiss_uint32)*((RISCV*)cpu)->R[" + toString(rs2) + "])\n"
			"{\n"
				"result = *((RISCV*)cpu)->R[" + toString(rs2) + "];\n"
				#if RISCV_DEBUG_CALL
				"printf(\"result = %#x\\n\",result); \n"
				#endif	
			"}\n"
			
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomaxu_w_rd_rs1_rs2(
 		ISA32,
 		"amomaxu.w",
 		(uint32_t)0xe000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amomaxu.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
 			"etiss_uint32 result = 0;\n"
 			"etiss_uint32 mem_addr = 0;\n"
 			"etiss_uint32 mem_addr_ = 0;\n"
 			"etiss_uint32 o_data = 0;\n"
 			
			"mem_addr = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr = %#x\\n\",mem_addr); \n"
			#endif	
			" etiss_uint8 M_mem_addr_3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_3;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 3,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_3)<<24) ^ (o_data & 0xff000000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_2;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 2,tmpbuf,1);\n"
			"o_data^=((etiss_uint32)(M_mem_addr_2)<<16) ^ (o_data & 0xff0000);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_1;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 1,tmpbuf,1);\n"
			"o_data^=((etiss_uint16)(M_mem_addr_1)<<8) ^ (o_data & 0xff00);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			" etiss_uint8 M_mem_addr_0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr_0;\n"
			"exception = (*(system->dread))(system->handle,cpu,mem_addr + 0,tmpbuf,1);\n"
			"o_data^=((etiss_uint8)(M_mem_addr_0)) ^ (o_data & 0xff);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"o_data = %#x\\n\",o_data); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RISCV*)cpu)->R[" + toString(rd) + "] = o_data;\n"
				#if RISCV_DEBUG_CALL
				"printf(\"*((RISCV*)cpu)->R[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->R[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			"}\n"
			"result = o_data;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"result = %#x\\n\",result); \n"
			#endif	
			"if((etiss_uint32)o_data < (etiss_uint32)*((RISCV*)cpu)->R[" + toString(rs2) + "])\n"
			"{\n"
				"result = *((RISCV*)cpu)->R[" + toString(rs2) + "];\n"
				#if RISCV_DEBUG_CALL
				"printf(\"result = %#x\\n\",result); \n"
				#endif	
			"}\n"
			
			"mem_addr_ = *((RISCV*)cpu)->R[" + toString(rs1) + "];\n"
			#if RISCV_DEBUG_CALL
			"printf(\"mem_addr_ = %#x\\n\",mem_addr_); \n"
			#endif	
			" etiss_uint8 M_mem_addr__3;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__3;\n"
			"M_mem_addr__3 = (result & 0xff000000)>>24;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 3,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__3 = %#x\\n\",M_mem_addr__3); \n"
			#endif	
			" etiss_uint8 M_mem_addr__2;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__2;\n"
			"M_mem_addr__2 = (result & 0xff0000)>>16;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 2,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__2 = %#x\\n\",M_mem_addr__2); \n"
			#endif	
			" etiss_uint8 M_mem_addr__1;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__1;\n"
			"M_mem_addr__1 = (result & 0xff00)>>8;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 1,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__1 = %#x\\n\",M_mem_addr__1); \n"
			#endif	
			" etiss_uint8 M_mem_addr__0;\n"
			" tmpbuf = (etiss_uint8 *)&M_mem_addr__0;\n"
			"M_mem_addr__0 = (result & 0xff);\n"
			"exception = (*(system->dwrite))(system->handle,cpu,mem_addr_ + 0,tmpbuf,1);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"M_mem_addr__0 = %#x\\n\",M_mem_addr__0); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ecall_(ISA32, "ecall", (uint32_t)0x73, (uint32_t)0xffffffff,
                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                        partInit.getAffectedRegisters().add("instructionPointer", 32);
                                        partInit.code() = std::string("//ecall\n") +
                                                          "etiss_uint32 exception = 0;\n"
                                                          "etiss_uint32 temp = 0;\n"
                                                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
                                                          // Manully modified
                                                          "exception = ETISS_RETURNCODE_SYSCALL; \n"
                                                          "cpu->instructionPointer = " +
                                                          toString((uint32_t)(ic.current_address_ + 4)) +
                                                          "ULL; \n"

                                                          "return exception; \n";
                                        return true;
                                    },
                                    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ebreak_(ISA32, "ebreak", (uint32_t)0x100073, (uint32_t)0xffffffff,
                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                         partInit.getAffectedRegisters().add("instructionPointer", 32);
                                         partInit.code() = std::string("//ebreak\n") +
                                                           "etiss_uint32 exception = 0;\n"
                                                           "etiss_uint32 temp = 0;\n"
                                                           "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                           "return ETISS_RETURNCODE_CPUFINISHED; \n"

                                                           "cpu->instructionPointer = " +
                                                           toString((uint32_t)(ic.current_address_ + 4)) +
                                                           "ULL; \n"

                                                           "return exception; \n";
                                         return true;
                                     },
                                     0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mret_(
    ISA32, "mret", (uint32_t)0x30200073, (uint32_t)0xffffffff,
    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
        partInit.getAffectedRegisters().add("instructionPointer", 32);
        partInit.code() = std::string("//mret\n") +
                          "etiss_uint32 exception = 0;\n"
                          "etiss_uint32 temp = 0;\n"
                          "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                          "cpu->instructionPointer = ((RISCV*)cpu)->MEPC;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif
                          "((RISCV*)cpu)->MEPC = 0;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"((RISCV*)cpu)->MEPC = %#x\\n\",((RISCV*)cpu)->MEPC); \n"
#endif
                          "*((RISCV*)cpu)->MSTATUS^=((etiss_uint32)((*((RISCV*)cpu)->MSTATUS & 0xf0)>>4)) ^ "
                          "(*((RISCV*)cpu)->MSTATUS & 0xf);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
                          "*((RISCV*)cpu)->MSTATUS^=((etiss_uint32)(0)<<4) ^ (*((RISCV*)cpu)->MSTATUS & 0xf0);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
                          "((RISCV*)cpu)->PRIVLV = (*((RISCV*)cpu)->MSTATUS & 0x1800)>>11;\n"
#if RISCV_DEBUG_CALL
                          "printf(\"((RISCV*)cpu)->PRIVLV = %#x\\n\",((RISCV*)cpu)->PRIVLV); \n"
#endif
                          "*((RISCV*)cpu)->MSTATUS^=((etiss_uint32)(0)<<11) ^ (*((RISCV*)cpu)->MSTATUS & 0x1800);\n"
#if RISCV_DEBUG_CALL
                          "printf(\"*((RISCV*)cpu)->MSTATUS = %#x\\n\",*((RISCV*)cpu)->MSTATUS); \n"
#endif
                          "cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"

                          "return exception; \n";
        return true;
    },
    0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
// The encoding with operation code 0x30200073 and operation mask 0xffffffff was implemented already
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sfence_vma_rs1_rs2(ISA32, "sfence.vma", (uint32_t)0x12000073, (uint32_t)0xfe007fff,
                                                [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                                    etiss_uint32 rs2 = 0;
                                                    static BitArrayRange R_rs2_0(24, 20);
                                                    etiss_uint32 rs2_0 = R_rs2_0.read(ba);
                                                    rs2 += rs2_0;
                                                    etiss_uint32 rs1 = 0;
                                                    static BitArrayRange R_rs1_0(19, 15);
                                                    etiss_uint32 rs1_0 = R_rs1_0.read(ba);
                                                    rs1 += rs1_0;
                                                    CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                                    partInit.getAffectedRegisters().add("instructionPointer", 32);
                                                    partInit.code() = std::string("//sfence.vma\n") +
                                                                      "etiss_uint32 exception = 0;\n"
                                                                      "etiss_uint32 temp = 0;\n"
                                                                      "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                                      "cpu->instructionPointer = " +
                                                                      toString((uint32_t)(ic.current_address_ + 4)) +
                                                                      "ULL; \n"

                                                                      "return exception; \n";
                                                    return true;
                                                },
                                                0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition wfi_(ISA32, "wfi", (uint32_t)0x10500073, (uint32_t)0xffffffff,
                                  [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                      CodePart &partInit = cs.append(CodePart::INITIALREQUIRED);
                                      partInit.getAffectedRegisters().add("instructionPointer", 32);
                                      partInit.code() = std::string("//wfi\n") +
                                                        "etiss_uint32 exception = 0;\n"
                                                        "etiss_uint32 temp = 0;\n"
                                                        "etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"

                                                        "cpu->instructionPointer = " +
                                                        toString((uint32_t)(ic.current_address_ + 4)) +
                                                        "ULL; \n"

                                                        "return exception; \n";
                                      return true;
                                  },
                                  0, nullptr);
//-------------------------------------------------------------------------------------------------------------------
