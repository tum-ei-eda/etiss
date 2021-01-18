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

#include "OR1KArch.h"

#include "OR1KCommonLocal.hpp"

template <unsigned index>
static bool l_cust(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{
    switch (index)
    {
    case 1: // l.cust1
        cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() = "return ETISS_RETURNCODE_CPUFINISHED ;";
        break;
    case 2: // l.cust2 // get cpu time
        cs.append(CodePart::INITIALREQUIRED).code() =
            std::string(reg[rd.read(ba)]) + " = (etiss_uint32) (cpu->cpuTime_ps/1000000);";
        break;
    case 3: // l.cust3
        cs.append(CodePart::INITIALREQUIRED).code() = std::string("OR1K_printchar((char)") + reg[ra.read(ba)] + " );";
        break;
    case 4: // l.cust4
        cs.append(CodePart::INITIALREQUIRED).code() = "OR1K_printtime(cpu);";
        break;
    case 5: // l.cust5
        cs.append(CodePart::INITIALREQUIRED).code() = std::string(reg[rd.read(ba)]) + " = OR1K_reset_stopwatch(cpu),";
        break;
    default:
        // nop
        break;
    }
    update_pc<false, false>(ba, cs, ic);
    return true;
}

static void OR1K_l_mulX(const std::string rD, const std::string rA, const std::string rB, CodeSet &codeset)
{
    // op
    {
        CodePart &part = codeset.append(CodePart::INITIALREQUIRED);
        part.code() = "etiss_int32 OR1K_rA = (etiss_int32)" + rA + ";\n" + "etiss_int32 OR1K_rB = (etiss_int32)" + rB +
                      ";\n" + "etiss_int64 OR1K_result=OR1K_rA*OR1K_rB;\n" + rD + "= (etiss_uint32)OR1K_result;";
    }
    // flag
    {
        CodePart &part = codeset.append(CodePart::OPTIONALMIDDLE);
        part.getAffectedRegisters().add("SR", 32, OR1K_SR_OV);
        part.code() =
            std::string("etiss_int32 OR1K_high = OR1K_result >> 32; etiss_int32 OR1K_cy = OR1K_result >> 31;\n") +
            "*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & ~OR1K_SR_OV) | "
            "((((OR1K_cy==0)&&(OR1K_high==0))||((OR1K_cy==-1)&&(OR1K_high==-1)))?0:OR1K_SR_OV);";
    }
    // exception
    {
        CodePart &part = codeset.append(CodePart::APPENDEDRETURNINGREQUIRED);
        part.getAffectedRegisters().add("SR", 32, OR1K_SR_OV);
        std::stringstream ss;
        ss << "\t\tif (unlikely((*((OR1K*)cpu)->SR)&OR1K_SR_OVE)){\n";

        ss << "\t\t\tif (unlikely((*((OR1K*)cpu)->AECR) & OR1K_AECR_OVMULE)){\n";

        ss << "etiss_int32 OR1K_high_ = OR1K_result >> 32; etiss_int32 OR1K_cy_ = OR1K_result >> "
              "31;\n*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & ~OR1K_SR_OV) | "
              "((((OR1K_cy_==0)&&(OR1K_high_==0))||((OR1K_cy_==-1)&&(OR1K_high_==-1)))?0:OR1K_SR_OV);";
        ss << "\t\t\t\tif ((*((OR1K*)cpu)->SR) & OR1K_SR_OV) return OR1K_RANGEEXCEPTION;\n";

        ss << "\t\t\t}\n";

        ss << "\t\t}";
        part.code() = ss.str();
    }
}
static void OR1K_l_muluX(const std::string rD, const std::string rA, const std::string rB, CodeSet &codeset)
{
    // op
    {
        CodePart &part = codeset.append(CodePart::INITIALREQUIRED);
        part.code() = "etiss_uint32 OR1K_rA = (etiss_uint32)" + rA + ";\n" + "etiss_uint32 OR1K_rB = (etiss_uint32)" +
                      rB + ";\n" + "etiss_uint64 OR1K_result=OR1K_rA*OR1K_rB;\n" + rD + "= (etiss_uint32)OR1K_result;";
    }
    // flag
    {
        CodePart &part = codeset.append(CodePart::OPTIONALMIDDLE);
        part.getAffectedRegisters().add("SR", 32, OR1K_SR_CY);
        part.code() =
            "*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & ~OR1K_SR_CY) | (((OR1K_result>>32)!=0)?0:OR1K_SR_CY);";
    }
    // exception
    {
        CodePart &part = codeset.append(CodePart::APPENDEDRETURNINGREQUIRED);
        part.getAffectedRegisters().add("SR", 32, OR1K_SR_CY);
        std::stringstream ss;
        ss << "\t\tif (unlikely((*((OR1K*)cpu)->SR)&OR1K_SR_OVE)){\n";

        ss << "\t\t\tif (unlikely((*((OR1K*)cpu)->AECR) & OR1K_AECR_CYMULE)){\n";

        ss << "*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & ~OR1K_SR_CY) | (((OR1K_result>>32)!=0)?0:OR1K_SR_CY);";
        ss << "\t\t\t\tif ((*((OR1K*)cpu)->SR) & OR1K_SR_CY) return OR1K_RANGEEXCEPTION;\n";

        ss << "\t\t\t}\n";

        ss << "\t\t}";
        part.code() = ss.str();
    }
}

template <typename T>
static bool l_ext(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{
    std::string cast;
    const bool sig = std::is_signed<T>::value;
    cast = std::string("etiss_") + (sig ? "" : "u") + "int" + toString(sizeof(T) * 8);

    CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
    cp = std::string(reg[rd.read(ba)]) + " = (" + cast + ")" + reg[ra.read(ba)] + ";";
    cp.getRegisterDependencies().add(reg_name[ra.read(ba)], 32);
    cp.getAffectedRegisters().add(reg_name[rd.read(ba)], 32);
    update_pc<false, false>(ba, cs, ic);
    return true;
}

static std::string unknown_asm(BitArray &ba, Instruction &i)
{
    return i.name_;
}

InstructionGroup ORBIS32_II("ORBIS32_II", 32);

static InstructionDefinition l_cust1(ORBIS32_II,

                                     "l.cust1",

                                     parse_i32("6x1c 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<1>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cust2(ORBIS32_II,

                                     "l.cust2",

                                     parse_i32("6x1d 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<2>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cust3(ORBIS32_II,

                                     "l.cust3",

                                     parse_i32("6x1e 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<3>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cust4(ORBIS32_II,

                                     "l.cust4",

                                     parse_i32("6x1F 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<4>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cust5(ORBIS32_II,

                                     "l.cust5",

                                     parse_i32("6x3c 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<5>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cust7(ORBIS32_II,

                                     "l.cust7",

                                     parse_i32("6x3e 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<7>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cust8(ORBIS32_II,

                                     "l.cust8",

                                     parse_i32("6x3f 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     l_cust<8>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_cmov(ORBIS32_II,

                                    "l.cmov",

                                    parse_i32("6x38 15x0 1x0 2x0 4x0 4xe"),

                                    parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
                                            std::string(reg[rd.read(ba)]) + " = ((*((OR1K*)cpu)->SR)&OR1K_SR_F)?(" +
                                            reg[ra.read(ba)] + "):(" + reg[rb.read(ba)] + ");";
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAB

);
static InstructionDefinition l_csync(ORBIS32_II,

                                     "l.csync",

                                     parse_i32("32x23000000"),

                                     parse_i32("32xFFFFFFFF"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         // nop
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_div(
    ORBIS32_II,

    "l.div",

    parse_i32("6x38 15x0 1x0 2x3 4x0 4x9"),

    parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        unsigned irD = rd.read(ba);
        unsigned irA = ra.read(ba);
        unsigned irB = rb.read(ba);
        std::stringstream ss;
        ss << "etiss_int32 regb = (etiss_int32) " << reg[irB] << ";\n";
        ss << "if (regb != 0){\n";
        ss << reg[irD] << " = (etiss_uint32) ((etiss_int32) " << reg[irA] << " / regb);";
        ss << "}\n";
        ss << "*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & ~OR1K_SR_OV) | (regb==0?(OR1K_SR_OV):0);";
        CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
        cp.code() = ss.str();
        cp.getRegisterDependencies().add(reg_name[irA], 32);
        cp.getRegisterDependencies().add(reg_name[irB], 32);
        cp.getAffectedRegisters().add(reg_name[irD], 32);
        cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
            "if (regb == 0 && (*((OR1K*)cpu)->AECR & (1<<4)) && (*((OR1K*)cpu)->SR & (1<<12)) ) return "
            "OR1K_RANGEEXCEPTION;";

        update_pc<false, false>(ba, cs, ic);
        return true;
    },

    0,

    or1k_asm_print_rDAB

);

static InstructionDefinition l_divu(
    ORBIS32_II,

    "l.divu",

    parse_i32("6x38 15x0 1x0 2x3 4x0 4xa"),

    parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        unsigned irD = rd.read(ba);
        unsigned irA = ra.read(ba);
        unsigned irB = rb.read(ba);
        std::stringstream ss;

        ss << "etiss_uint32 regb = (etiss_uint32) " << reg[irB] << ";\n";
        ss << "if (regb != 0){\n";
        // Debug, report destination register value before l.divu operation
        // ss << "OR1K_report((uint32_t) " << reg[rd.read(ba)] << " );";

        ss << reg[irD] << " = (etiss_uint32) ((etiss_uint32) " << reg[irA] << " / regb);\n";

        // Debug, report destination and operand register id and values after l.divu operation
        // ss << "OR1K_report((uint32_t) " << toString(ra.read(ba)) << " );\n";
        // ss << "OR1K_report((uint32_t) " << toString(rb.read(ba)) << " );\n";
        // ss << "OR1K_report((uint32_t) " << toString(rd.read(ba)) << " );\n";
        // ss << "OR1K_report((uint32_t) " << reg[rd.read(ba)] << " );\n";
        // ss << "OR1K_report((uint32_t) " << reg[ra.read(ba)] << " );\n";
        // ss << "OR1K_report((uint32_t) " << reg[rb.read(ba)] << " );\n";
        ss << "}\n";

        // Debug report div by 0
        // ss << "else {\n";
        // ss << "OR1K_report((uint32_t) " << reg[rd.read(ba)] << " );\n";
        // ss << "}\n";

        ss << "*((OR1K*)cpu)->SR = ((*((OR1K*)cpu)->SR) & ~OR1K_SR_OV) | (regb==0?(OR1K_SR_OV):0);";
        CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
        cp.code() = ss.str();
        cp.getRegisterDependencies().add(reg_name[irA], 32);
        cp.getRegisterDependencies().add(reg_name[irB], 32);
        cp.getAffectedRegisters().add(reg_name[irD], 32);

        cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
            "if (regb == 0 && (*((OR1K*)cpu)->AECR & (1<<4)) && (*((OR1K*)cpu)->SR & (1<<12)) ) return "
            "OR1K_RANGEEXCEPTION;";

        update_pc<false, false>(ba, cs, ic);
        return true;
    },

    0,

    or1k_asm_print_rDAB

);

static InstructionDefinition l_extbs(ORBIS32_II,

                                     "l.extbs",

                                     parse_i32("6x38 10x0 6x0 4x1 2x0 4xc"),

                                     parse_i32("6xFF 10x0 6x0 4xF 2x0 4xF"),

                                     l_ext<int8_t>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_extbz(ORBIS32_II,

                                     "l.extbz",

                                     parse_i32("6x38 10x0 6x0 4x3 2x0 4xc"),

                                     parse_i32("6xFF 10x0 6x0 4xF 2x0 4xF"),

                                     l_ext<uint8_t>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_exths(ORBIS32_II,

                                     "l.exths",

                                     parse_i32("6x38 10x0 6x0 4x0 2x0 4xc"),

                                     parse_i32("6xFF 10x0 6x0 4xF 2x0 4xF"),

                                     l_ext<int16_t>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_exthz(ORBIS32_II,

                                     "l.exthz",

                                     parse_i32("6x38 10x0 6x0 4x2 2x0 4xc"),

                                     parse_i32("6xFF 10x0 6x0 4xF 2x0 4xF"),

                                     l_ext<uint16_t>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_extws(ORBIS32_II,

                                     "l.extws",

                                     parse_i32("6x38 10x0 6x0 4x0 2x0 4xd"),

                                     parse_i32("6xFF 10x0 6x0 4xF 2x0 4xF"),

                                     l_ext<int32_t>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_extwz(ORBIS32_II,

                                     "l.extwz",

                                     parse_i32("6x38 10x0 6x0 4x1 2x0 4xd"),

                                     parse_i32("6xFF 10x0 6x0 4xF 2x0 4xF"),

                                     l_ext<uint32_t>,

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_ff1(ORBIS32_II,

                                   "l.ff1",

                                   parse_i32("6x38 15x0 1x0 2x0 4x0 4xf"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
                                           std::string("etiss_uint32 or1k_ff1 = 1;\n") +
                                           "etiss_uint32 or1k_ra = " + reg[ra.read(ba)] +
                                           ";\n"
                                           "while (((or1k_ra&1)==0) && (or1k_ff1 < 32)){\n"
                                           "	or1k_ra = or1k_ra >> 1;\n"
                                           "	or1k_ff1++;\n"
                                           "}\n" +
                                           reg[rd.read(ba)] + " = (or1k_ff1==32)?0:or1k_ff1;";
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   unknown_asm

);

static InstructionDefinition l_fl1(ORBIS32_II,

                                   "l.fl1",

                                   parse_i32("6x38 15x0 1x0 2x1 4x0 4xf"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
                                           std::string("etiss_uint32 or1k_ff1 = 1;\n") +
                                           "etiss_uint32 or1k_ra = " + reg[ra.read(ba)] +
                                           ";\n"
                                           "while (((or1k_ra&0x80000000)==0) && (or1k_ff1 < 32)){\n"
                                           "	or1k_ra = or1k_ra << 1;\n"
                                           "	or1k_ff1++;\n"
                                           "}\n" +
                                           reg[rd.read(ba)] + " = 32-or1k_ff1 ;";
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   unknown_asm

);

static InstructionDefinition l_mac(ORBIS32_II,

                                   "l.mac",

                                   parse_i32("6x31 15x0 7x0 4x1"),

                                   parse_i32("6xFF 15x0 7x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                       part.code() = std::string("etiss_int64 OR1K_rA = (etiss_int32)") +
                                                     reg[ra.read(ba)] + ";\n" + "etiss_int64 OR1K_rB = (etiss_int32)" +
                                                     reg[rb.read(ba)] +
                                                     ";\n"
                                                     "OR1K_rB = OR1K_rA * OR1K_rB;\n"
                                                     "OR1K_rA = ((etiss_int64)(((etiss_uint64)*((OR1K*)cpu)->MACHI) << "
                                                     "32)) | ((etiss_uint64)(*((OR1K*)cpu)->MACLO));\n"
                                                     "etiss_int64 OR1K_result = OR1K_rA + OR1K_rB;\n"
                                                     "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                     "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                       // TODO signed overflow flag
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_maci(ORBIS32_II,

                                    "l.maci",

                                    parse_i32("6x13 10x0 16x0"),

                                    parse_i32("6xFF 10x0 16x0"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                        part.code() = std::string("etiss_int64 OR1K_rA = (etiss_int32)") +
                                                      reg[ra.read(ba)] + ";\n" + "etiss_int64 OR1K_rB = (etiss_int32)" +
                                                      toString((uint16_t)immediate.read(ba)) +
                                                      ";\n"
                                                      "OR1K_rB = OR1K_rA * OR1K_rB;\n"
                                                      "OR1K_rA = ((etiss_int64)(((etiss_uint64)*((OR1K*)cpu)->MACHI) "
                                                      "<< 32)) | ((etiss_uint64)(*((OR1K*)cpu)->MACLO));\n"
                                                      "etiss_int64 OR1K_result = OR1K_rA + OR1K_rB;\n"
                                                      "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                      "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                        // TODO signed overflow flag
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_macrc(ORBIS32_II,

                                     "l.maci",

                                     parse_i32("6x6 9x0 17x10000"),

                                     parse_i32("6xFF 9x0 17xFFFFF"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                         part.code() = std::string(reg[rd.read(ba)]) + " = *((OR1K*)cpu)->MACLO;\n"
                                                                                       "*((OR1K*)cpu)->MACHI =0;\n"
                                                                                       "*((OR1K*)cpu)->MACLO = 0;";
                                         // TODO signed overflow flag
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_macu(ORBIS32_II,

                                    "l.macu",

                                    parse_i32("6x31 15x0 7x0 4x3"),

                                    parse_i32("6xFF 15x0 7x0 4xF"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                        part.code() = std::string("etiss_uint64 OR1K_rA = (etiss_uint32)") +
                                                      reg[ra.read(ba)] + ";\n" +
                                                      "etiss_uint64 OR1K_rB = (etiss_uint32)" + reg[rb.read(ba)] +
                                                      ";\n"
                                                      "OR1K_rB = OR1K_rA * OR1K_rB;\n"
                                                      "OR1K_rA = ((etiss_uint64)(((etiss_uint64)*((OR1K*)cpu)->MACHI) "
                                                      "<< 32)) | ((etiss_uint64)(*((OR1K*)cpu)->MACLO));\n"
                                                      "etiss_uint64 OR1K_result = OR1K_rA + OR1K_rB;\n"
                                                      "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                      "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                        // TODO signed overflow flag
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_msb(ORBIS32_II,

                                   "l.msb",

                                   parse_i32("6x31 15x0 7x0 4x2"),

                                   parse_i32("6xFF 15x0 7x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                       part.code() = std::string("etiss_int64 OR1K_rA = (etiss_int32)") +
                                                     reg[ra.read(ba)] + ";\n" + "etiss_int64 OR1K_rB = (etiss_int32)" +
                                                     reg[rb.read(ba)] +
                                                     ";\n"
                                                     "OR1K_rB = OR1K_rA * OR1K_rB;\n"
                                                     "OR1K_rA = ((etiss_int64)(((etiss_uint64)*((OR1K*)cpu)->MACHI) << "
                                                     "32)) | ((etiss_uint64)(*((OR1K*)cpu)->MACLO));\n"
                                                     "etiss_int64 OR1K_result = OR1K_rA - OR1K_rB;\n"
                                                     "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                     "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                       // TODO signed overflow flag
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_msbu(ORBIS32_II,

                                    "l.msbu",

                                    parse_i32("6x31 15x0 7x0 4x4"),

                                    parse_i32("6xFF 15x0 7x0 4xF"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                        part.code() = std::string("etiss_uint64 OR1K_rA = (etiss_uint32)") +
                                                      reg[ra.read(ba)] + ";\n" +
                                                      "etiss_uint64 OR1K_rB = (etiss_uint32)" + reg[rb.read(ba)] +
                                                      ";\n"
                                                      "OR1K_rB = OR1K_rA * OR1K_rB;\n"
                                                      "OR1K_rA = ((etiss_uint64)(((etiss_uint64)*((OR1K*)cpu)->MACHI) "
                                                      "<< 32)) | ((etiss_uint64)(*((OR1K*)cpu)->MACLO));\n"
                                                      "etiss_uint64 OR1K_result = OR1K_rA - OR1K_rB;\n"
                                                      "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                      "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                        // TODO signed overflow flag
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_msync(ORBIS32_II,

                                     "l.msync",

                                     parse_i32("32x22000000"),

                                     parse_i32("32xFFFFFFFF"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         // nop
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_mul(ORBIS32_II,

                                   "l.mul",

                                   parse_i32("6x38 15x0 1x0 2x3 4x0 4x6"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       OR1K_l_mulX(reg[rd.read(ba)], reg[ra.read(ba)], reg[rb.read(ba)], cs);
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_muld(ORBIS32_II,

                                    "l.muld",

                                    parse_i32("6x38 15x0 1x0 2x3 4x0 4x7"),

                                    parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                        part.code() = std::string("etiss_int64 OR1K_rA = (etiss_int32)") +
                                                      reg[ra.read(ba)] + ";\n" + "etiss_int64 OR1K_rB = (etiss_int32)" +
                                                      reg[rb.read(ba)] +
                                                      ";\n"
                                                      "etiss_int64 OR1K_result = OR1K_rA * OR1K_rB;\n"
                                                      "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                      "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_muldu(ORBIS32_II,

                                     "l.muldu",

                                     parse_i32("6x38 15x0 1x0 2x3 4x0 4xc"),

                                     parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                         part.code() = std::string("etiss_uint64 OR1K_rA = (etiss_uint32)") +
                                                       reg[ra.read(ba)] + ";\n" +
                                                       "etiss_uint64 OR1K_rB = (etiss_uint32)" + reg[rb.read(ba)] +
                                                       ";\n"
                                                       "etiss_uint64 OR1K_result = OR1K_rA * OR1K_rB;\n"
                                                       "*((OR1K*)cpu)->MACHI = (etiss_uint32)(OR1K_result>>32);\n"
                                                       "*((OR1K*)cpu)->MACLO = (etiss_uint32)(OR1K_result);";
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_muli(ORBIS32_II,

                                    "l.muli",

                                    parse_i32("6x2c 10x0 16x0"),

                                    parse_i32("6xFF 10x0 16x0"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        OR1K_l_mulX(reg[rd.read(ba)], reg[ra.read(ba)],
                                                    toString((int16_t)immediate.read(ba)), cs);
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_mulu(ORBIS32_II,

                                    "l.mulu",

                                    parse_i32("6x38 15x0 1x0 2x3 4x0 4xb"),

                                    parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        OR1K_l_muluX(reg[rd.read(ba)], reg[ra.read(ba)], reg[rb.read(ba)], cs);
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_psync(ORBIS32_II,

                                     "l.psync",

                                     parse_i32("32x22800000"),

                                     parse_i32("32xFFFFFFFF"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         // nop
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     unknown_asm

);

static InstructionDefinition l_ror(ORBIS32_II,

                                   "l.ror",

                                   parse_i32("6x38 15x0 1x0 4x3 2x0 4x8"),

                                   parse_i32("6xFF 15x0 1x0 4xF 2x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                       part.code() = std::string(reg[rd.read(ba)]) + "= (" + reg[ra.read(ba)] + ">>(" +
                                                     reg[rb.read(ba)] + "&0x1F))|(" + reg[ra.read(ba)] + "<<(32-(" +
                                                     reg[rb.read(ba)] + "&0x1F)));";

                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   unknown_asm

);

static InstructionDefinition l_rori(ORBIS32_II,

                                    "l.rori",

                                    parse_i32("6x2e 10x0 8x0 2x3 6x0"),

                                    parse_i32("6xFF 10x0 8x0 2xF 6x0"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        BitArrayRange simm(4, 0);
                                        CodePart &part = cs.append(CodePart::INITIALREQUIRED);
                                        part.code() = std::string(reg[rd.read(ba)]) + "= (" + reg[ra.read(ba)] + ">>(" +
                                                      toString(simm.read(ba) & 0x1F) + "))|(" + reg[ra.read(ba)] +
                                                      "<<(32-(" + toString(simm.read(ba) & 0x1F) + ")));";

                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    unknown_asm

);

static InstructionDefinition l_sfeqi(ORBIS32_II,

                                     "l.sfeqi",

                                     parse_i32("11x5e0 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<true, true, '=', '='>,

                                     0,

                                     or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_sfgesi(ORBIS32_II,

                                      "l.sfgesi",

                                      parse_i32("11x5eb 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<true, true, '>', '='>,

                                      0,

                                      or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_sfgeui(ORBIS32_II,

                                      "l.sfgeui",

                                      parse_i32("11x5e3 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<false, true, '>', '='>,

                                      0,

                                      or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_sfgtsi(ORBIS32_II,

                                      "l.sfgtsi",

                                      parse_i32("11x5ea 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<true, true, '>'>,

                                      0,

                                      or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_sfgtui(ORBIS32_II,

                                      "l.sfgtui",

                                      parse_i32("11x5e2 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<false, true, '>'>,

                                      0,

                                      or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_sflesi(ORBIS32_II,

                                      "l.sflesi",

                                      parse_i32("11x5ed 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<true, true, '<', '='>,

                                      0,

                                      or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_sfleui(ORBIS32_II,

                                      "l.sfleui",

                                      parse_i32("11x5e5 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<false, true, '<', '='>,

                                      0,

                                      or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_sfltsi(ORBIS32_II,

                                      "l.sfltsi",

                                      parse_i32("11x5ec 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<true, true, '<'>,

                                      0,

                                      or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_sfltui(ORBIS32_II,

                                      "l.sfltui",

                                      parse_i32("11x5e4 21x0"),

                                      parse_i32("11xFFF 21x0"),

                                      l_sf<false, true, '<'>,

                                      0,

                                      or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_sfnei(ORBIS32_II,

                                     "l.sfnei",

                                     parse_i32("11x5e1 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<true, true, '!', '='>,

                                     0,

                                     or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_trap(ORBIS32_II,

                                    "l.trap",

                                    parse_i32("16x2100 16x0"),

                                    parse_i32("16xFFFF 16x0"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
                                            "return OR1K_TRAPEXCEPTION ;";
                                        update_pc<true, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    unknown_asm

);
