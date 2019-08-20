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
#include <type_traits>

#include "OR1KCommonLocal.hpp"

static void l_addsubX(std::string in1, std::string in2, std::string out, CodeSet &codeset, bool add, bool cy)
{
    // add/sub
    {
        CodePart &part = codeset.append(CodePart::INITIALREQUIRED);
        part.getCode() = "\t\tetiss_uint64 a = (uint32_t) " + in1 + ";\n\t\tetiss_uint64 b = (uint32_t) " + in2 +
                         ";\n\t\tetiss_uint64 d = a " + (add ? "+" : "-") + " b;" + out + " = (etiss_uint32)d;\n";
        if (cy)
        {
            part.getRegisterDependencies().add("SR", 32, OR1K_SR_CY);
            part.getCode() = part.getCode() + "\t\tif (((*((OR1K*)cpu)->SR)&OR1K_SR_CY) != 0) {" + out + " = " + out +
                             " " + (add ? "+" : "-") + " 1; d = d " + (add ? "+" : "-") + "1 ;}";
        }
    }

    // carry
    {
        CodePart &part = codeset.append(CodePart::OPTIONALMIDDLE);
        part.getAffectedRegisters().add("SR", 32, OR1K_SR_CY);
        part.getCode() = "\t\tif (unlikely(d != (uint64_t)((uint32_t)(" + out +
                         ")))) (*((OR1K*)cpu)->SR) |= OR1K_SR_CY; else (*((OR1K*)cpu)->SR) &= ~OR1K_SR_CY;";
    }

    // overflow
    {
        CodePart &part = codeset.append(CodePart::OPTIONALMIDDLE);
        part.getAffectedRegisters().add("SR", 32, OR1K_SR_OV);
        part.getCode() = std::string("\t\tif (unlikely(((a&(1<<31)) ") + (add ? "==" : "!=") +
                         " (b&(1<<31))) && ((a&(1<<31)) != (d&(1<<31))))) (*((OR1K*)cpu)->SR) |= OR1K_SR_OV; else "
                         "(*((OR1K*)cpu)->SR) &= ~OR1K_SR_OV;";
    }

    // exception

    CodePart &part = codeset.append(CodePart::APPENDEDRETURNINGREQUIRED);
    part.getAffectedRegisters().add("SR", 32, OR1K_SR_OV);
    part.getAffectedRegisters().add("SR", 32, OR1K_SR_CY);
    part.getRegisterDependencies().add("NPC", 32);
    part.getRegisterDependencies().add("PPC", 32);
    part.getRegisterDependencies().add("instructionPointer", 32);
    std::stringstream ss;

    ss << "\t\tif (unlikely((*((OR1K*)cpu)->SR)&OR1K_SR_OVE)){\n"
          "\t\t\tif (unlikely((*((OR1K*)cpu)->AECR) & (OR1K_AECR_CYADDE | OR1K_AECR_OVADDE))){\n"
          "\t\t\t\tif (((a&(1<<31)) == (b&(1<<31))) && ((a&(1<<31)) != (d&(1<<31)))) (*((OR1K*)cpu)->SR) |= "
          "OR1K_SR_OV; else (*((OR1K*)cpu)->SR) &= ~OR1K_SR_OV;\n"
          "\t\t\t\tif (d != (" +
              out +
              ")) (*((OR1K*)cpu)->SR) |= OR1K_SR_CY; else (*((OR1K*)cpu)->SR) &= ~OR1K_SR_CY;\n"
              "\t\t\t\tif ((*((OR1K*)cpu)->SR) & (OR1K_SR_CY | OR1K_SR_OV)) return OR1K_RANGEEXCEPTION;\n"
              "\t\t\t}\n"
              "\t\t}";
    part.getCode() = ss.str();
}

template <char op>
static bool simple_op_rDAB(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{
    unsigned irD = rd.read(ba);
    unsigned irA = ra.read(ba);
    unsigned irB = rb.read(ba);
    CodePart &part = cs.append(CodePart::INITIALREQUIRED);
    part.getRegisterDependencies().add(reg_name[irA], 32);
    part.getRegisterDependencies().add(reg_name[irB], 32);
    part.getAffectedRegisters().add(reg_name[irD], 32);
    part.code() = std::string(reg[irD]) + " = " + reg[irA] + op + reg[irB] + ";";

    update_pc<false, false>(ba, cs, ic);

    return true;
}
template <char op, bool sig>
static bool simple_op_rDAI(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{
    typedef typename std::conditional<sig, int16_t, uint16_t>::type IMMT;
    unsigned irD = rd.read(ba);
    unsigned irA = ra.read(ba);
    IMMT irI = immediate.read(ba);
    CodePart &part = cs.append(CodePart::INITIALREQUIRED);
    part.getRegisterDependencies().add(reg_name[irA], 32);
    part.getAffectedRegisters().add(reg_name[irD], 32);
    part.code() = std::string(reg[irD]) + " = " + reg[irA] + op + " " + toString(irI) + ";";

    update_pc<false, false>(ba, cs, ic);

    return true;
}

template <bool right, bool sig, bool imm>
static bool shift(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{
    unsigned irD = rd.read(ba);
    unsigned irA = ra.read(ba);
    unsigned irB = rb.read(ba);
    uint16_t imme = (uint16_t)(immediate.read(ba) & 0x1f);
    CodePart &part = cs.append(CodePart::INITIALREQUIRED);
    part.getRegisterDependencies().add(reg_name[irA], 32);
    part.getRegisterDependencies().add(reg_name[irB], 32);
    part.getAffectedRegisters().add(reg_name[irD], 32);
    part.code() = std::string(reg[irD]) + " = ((" + (sig ? "etiss_int32)" : "etiss_uint32)") + reg[irA] +
                  (right ? ")>>(" : ")<<(") + (imm ? toString(imme) : (std::string(reg[irB]) + "&0x1f")) + ");";

    update_pc<false, false>(ba, cs, ic);

    return true;
}

template <typename T, bool swap = (ETISS_ENDIANNESS != ETISS_BIG_ENDIAN)>
static bool loadinstr(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{

    std::stringstream ss;
    ss << "etiss_uint32 * or1k_rD = &" << reg[rd.read(ba)] << ";";
    ss << "etiss_uint8 * or1k_buf = (etiss_uint8 *)or1k_rD;\n"
          "etiss_int32 or1k_exception = (*(system->dread))(system->handle,cpu,("
       << reg[ra.read(ba)] << "+" << (int16_t)immediate.read(ba) << "),or1k_buf," << sizeof(T) << ");\n";
    if (swap)
    {
        if (sizeof(T) >= 2)
            ss << "etiss_uint8 or1k_tmpswap;\n";
        for (unsigned i = 0; i < (sizeof(T) >> 1); i++)
        {
            ss << "or1k_tmpswap = or1k_buf[" << i << "]; or1k_buf[" << i << "] = or1k_buf[" << (sizeof(T) - 1 - i)
               << "]; or1k_buf[" << (sizeof(T) - 1 - i) << "] = or1k_tmpswap;";
        }
    }
    if (std::is_signed<T>::value)
    {
        if (sizeof(T) == 1)
        {
            ss << "*or1k_rD = (int8_t) (*or1k_rD);";
        }
        if (sizeof(T) == 2)
        {
            ss << "*or1k_rD = (int16_t)(*or1k_rD);";
        }
    }
    else
    {
        if (sizeof(T) == 1)
        {
            ss << "*or1k_rD = (uint8_t) (*or1k_rD);";
        }
        if (sizeof(T) == 2)
        {
            ss << "*or1k_rD = (uint16_t)(*or1k_rD);";
        }
    }
    CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
    cp.code() = ss.str();
    cp.getAffectedRegisters().add(reg_name[rd.read(ba)], 32);
    cp.getRegisterDependencies().add(reg_name[ra.read(ba)], 32);
    cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() = "if (or1k_exception != 0) \n\treturn or1k_exception;";
    update_pc<false, false>(ba, cs, ic);
    return true;
}

template <typename T, bool swap = (ETISS_ENDIANNESS != ETISS_BIG_ENDIAN)>
static bool storeinstr(BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic)
{

    BitArrayRange immp1(25, 21);
    BitArrayRange immp2(10, 0);
    std::stringstream ss;
    ss << "etiss_uint32 or1k_rB = " << reg[rb.read(ba)] << ";";
    ss << "etiss_uint8 * or1k_buf = (etiss_uint8 *)&or1k_rB;\n";
    if (swap)
    {
        if (sizeof(T) >= 2)
            ss << "etiss_uint8 or1k_tmpswap;";
        for (unsigned i = 0; i < (sizeof(T) >> 1); i++)
        {
            ss << "or1k_tmpswap = or1k_buf[" << i << "]; or1k_buf[" << i << "] = or1k_buf[" << (sizeof(T) - 1 - i)
               << "]; or1k_buf[" << (sizeof(T) - 1 - i) << "] = or1k_tmpswap;";
        }
    }
    ss << "etiss_int32 or1k_exception = (*(system->dwrite))(system->handle,cpu,(" << reg[ra.read(ba)] << "+"
       << toString((int16_t)((immp1.read(ba) << 11) | immp2.read(ba))) << "),or1k_buf," << sizeof(T) << ");\n";
    CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
    cp.code() = ss.str();
    cp.getAffectedRegisters().add(reg_name[rd.read(ba)], 32);
    cp.getRegisterDependencies().add(reg_name[ra.read(ba)], 32);
    cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() = "if (or1k_exception != 0) \n\treturn or1k_exception;";
    update_pc<false, false>(ba, cs, ic);
    return true;
}

InstructionGroup ORBIS32_I("ORBIS32_I", 32);

static InstructionDefinition l_add(ORBIS32_I,

                                   "l.add",

                                   parse_i32("6x38 15x0 1x0 2x0 4x0 4x0"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       l_addsubX(reg[ra.read(ba)], reg[rb.read(ba)], reg[rd.read(ba)], cs, true, false);
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_addc(ORBIS32_I,

                                    "l.addc",

                                    parse_i32("6x38 15x0 1x0 2x0 4x0 4x1"),

                                    parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        l_addsubX(reg[ra.read(ba)], reg[rb.read(ba)], reg[rd.read(ba)], cs, true, true);
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_addi(ORBIS32_I,

                                    "l.addi",

                                    parse_i32("6x27 10x0 16x0"),

                                    parse_i32("6xFF 10x0 16x0"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        l_addsubX(reg[ra.read(ba)], toString((int16_t)immediate.read(ba)),
                                                  reg[rd.read(ba)], cs, true, false);
                                        update_pc<false, false>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAI<true>

);

static InstructionDefinition l_addic(ORBIS32_I,

                                     "l.addic",

                                     parse_i32("6x28 10x0 16x0"),

                                     parse_i32("6xFF 10x0 16x0"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         l_addsubX(reg[ra.read(ba)], toString((int16_t)immediate.read(ba)),
                                                   reg[rd.read(ba)], cs, true, true);
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_and(ORBIS32_I,

                                   "l.and",

                                   parse_i32("6x38 15x0 1x0 2x0 4x0 4x3"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   simple_op_rDAB<'&'>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_andi(ORBIS32_I,

                                    "l.andi",

                                    parse_i32("6x29 10x0 16x0"),

                                    parse_i32("6xFF 10x0 16x0"),

                                    simple_op_rDAI<'&', false>,

                                    0,

                                    or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_bf(ORBIS32_I,

                                  "l.bf",

                                  parse_i32("6x4 26x0"),

                                  parse_i32("6xFF 26x0"),

                                  [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                      std::stringstream ss;
                                      ss << "	if (*(((OR1K*)cpu)->SR) & OR1K_SR_F){";
                                      ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)("
                                         << ic.current_address_ << "ULL + "
                                         << (uint32_t)(((int32_t)((int16_t)immediate.read(ba))) << 2) << "ULL);";
                                      ss << "	}else{";
                                      ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)("
                                         << ic.current_address_ << "ULL + 8);";
                                      ss << "}";
                                      CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                      cp.getRegisterDependencies().add("SR", 32, OR1K_SR_F);
                                      cp.code() = ss.str();
                                      update_pc<true, true>(ba, cs, ic);
                                      return true;
                                  },

                                  0,

                                  or1k_asm_print_rDAB

);

static InstructionDefinition l_bnf(ORBIS32_I,

                                   "l.bnf",

                                   parse_i32("6x3 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       std::stringstream ss;
                                       ss << "	if ((*(((OR1K*)cpu)->SR) & OR1K_SR_F)==0){";
                                       ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)("
                                          << ic.current_address_ << "ULL + "
                                          << (uint32_t)(((int32_t)((int16_t)immediate.read(ba))) << 2) << ");";
                                       ss << "	}else{";
                                       ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)("
                                          << ic.current_address_ << "ULL + 8);";
                                       ss << "}";
                                       CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                       cp.getRegisterDependencies().add("SR", 32, OR1K_SR_F);
                                       cp.code() = ss.str();
                                       update_pc<true, true>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_j(ORBIS32_I,

                                 "l.j",

                                 parse_i32("6x0 26x0"),

                                 parse_i32("6xFF 26x0"),

                                 [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                     uint32_t jaddr =
                                         (uint32_t)(ic.current_address_ + ((((int32_t)limmediate.read(ba)) << 6) >> 4));
                                     std::stringstream ss;
                                     ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)" +
                                               toString(jaddr) + "ULL;";
                                     CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                     cp.code() = ss.str();
                                     update_pc<true, true>(ba, cs, ic);
                                     return true;
                                 },

                                 0,

                                 or1k_asm_print_rDAB

);

static InstructionDefinition l_jal(ORBIS32_I,

                                   "l.jal",

                                   parse_i32("6x1 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       uint32_t jaddr = (uint32_t)(ic.current_address_ +
                                                                   ((((int32_t)limmediate.read(ba)) << 6) >> 4));
                                       std::stringstream ss;
                                       ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)" +
                                                 toString(jaddr) + "ULL;";
                                       ss << "		((OR1K*)cpu)->R[9] = " + toString(ic.current_address_ + 8) + ";";
                                       CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                       cp.code() = ss.str();
                                       update_pc<true, true>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_jalr(ORBIS32_I,

                                    "l.jalr",

                                    parse_i32("6x12 26x0"),

                                    parse_i32("6xFF 26x0"),

                                    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                        std::stringstream ss;
                                        ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)("
                                           << reg[rb.read(ba)] << ");";
                                        ss << "		((OR1K*)cpu)->R[9] = " + toString(ic.current_address_ + 8) +
                                                  ";";
                                        CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                        cp.getRegisterDependencies().add(reg_name[rb.read(ba)], 32);
                                        cp.code() = ss.str();
                                        update_pc<true, true>(ba, cs, ic);
                                        return true;
                                    },

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_jr(ORBIS32_I,

                                  "l.jr",

                                  parse_i32("6x11 26x0"),

                                  parse_i32("6xFF 26x0"),

                                  [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                      std::stringstream ss;
                                      ss << "		((OR1K*)cpu)->instructionPointer_delayed = (uint32_t)("
                                         << reg[rb.read(ba)] << ");";
                                      CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                      cp.getRegisterDependencies().add(reg_name[rb.read(ba)], 32);
                                      cp.code() = ss.str();
                                      update_pc<true, true>(ba, cs, ic);
                                      return true;
                                  },

                                  0,

                                  or1k_asm_print_rDAB

);

static InstructionDefinition l_lbs(ORBIS32_I,

                                   "l.lbs",

                                   parse_i32("6x24 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   loadinstr<int8_t>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_lbz(ORBIS32_I,

                                   "l.lbz",

                                   parse_i32("6x23 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   loadinstr<uint8_t>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_lhs(ORBIS32_I,

                                   "l.lhs",

                                   parse_i32("6x26 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   loadinstr<int16_t>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_lhz(ORBIS32_I,

                                   "l.lhz",

                                   parse_i32("6x25 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   loadinstr<uint16_t>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_lws(ORBIS32_I,

                                   "l.lws",

                                   parse_i32("6x22 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   loadinstr<int32_t>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_lwz(ORBIS32_I,

                                   "l.lwz",

                                   parse_i32("6x21 26x0"),

                                   parse_i32("6xFF 26x0"),

                                   loadinstr<int32_t>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_mfspr(ORBIS32_I,

                                     "l.mfspr",

                                     parse_i32("6x2d 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                         /// TODO add spr register
                                         // cp.getAffectedRegisters().add()
                                         cp.code() = std::string(reg[rd.read(ba)]) + " = OR1KArch_mfspr((OR1K*)cpu," +
                                                     reg[ra.read(ba)] + "|" + toString(immediate.read(ba)) + ");";
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_movhi(ORBIS32_I,

                                     "l.movhi",

                                     parse_i32("6x6 5x0 4x0 1x0 16x0"),

                                     parse_i32("6xFF 5x0 4x0 1xF 16x0"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                         cp.code() = std::string(reg[rd.read(ba)]) + " = (etiss_uint32) " +
                                                     toString(((uint32_t)immediate.read(ba)) << 16) + ";";
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_mtspr(ORBIS32_I,

                                     "l.mtspr",

                                     parse_i32("6x30 26x0"),

                                     parse_i32("6xFF 26x0"),

                                     [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                         CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
                                         /// TODO add spr register
                                         // cp.getAffectedRegisters().add()
                                         cp.getRegisterDependencies().add(reg_name[ra.read(ba)], 32);
                                         cp.getRegisterDependencies().add(reg_name[rb.read(ba)], 32);
                                         BitArrayRange immp1(25, 21);
                                         BitArrayRange immp2(10, 0);
                                         cp.code() = std::string("OR1KArch_mtspr((OR1K*)cpu,") + reg[ra.read(ba)] +
                                                     "|" + toString((immp1.read(ba) << 11) | immp2.read(ba)) + ", " +
                                                     reg[rb.read(ba)] + " );";
                                         update_pc<false, false>(ba, cs, ic);
                                         return true;
                                     },

                                     0,

                                     or1k_asm_print_rDAI<false>

);

// @see or1k-support.h of newlib for possible changes
#define NOP_NOP 0x0000    /* Normal nop instruction */
#define NOP_EXIT 0x0001   /* End of simulation */
#define NOP_REPORT 0x0002 /* Simple report */
/*#define NOP_PRINTF 0x0003 Simprintf instruction (obsolete)*/
#define NOP_PUTC 0x0004         /* JPB: Simputc instruction */
#define NOP_CNT_RESET 0x0005    /* Reset statistics counters */
#define NOP_GET_TICKS 0x0006    /* JPB: Get # ticks running */
#define NOP_GET_PS 0x0007       /* JPB: Get picosecs/cycle */
#define NOP_REPORT_FIRST 0x0400 /* Report with number */
#define NOP_REPORT_LAST 0x03ff  /* Report with number */

static BitArrayRange l_nop_param(23, 0);
static InstructionDefinition l_nop(ORBIS32_I,

                                   "l.nop",

                                   parse_i32("8x15 24x0"),

                                   parse_i32("8xFF 24x0"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       uint32_t nopcode = l_nop_param.read(ba);

                                       if (nopcode != NOP_NOP)
                                       {
                                           if (nopcode == NOP_EXIT)
                                           {
                                               cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() =
                                                   "return ETISS_RETURNCODE_CPUFINISHED ;";
                                           }
                                           if (nopcode == NOP_REPORT)
                                           {
                                               cs.append(CodePart::INITIALREQUIRED).code() =
                                                   std::string("OR1K_report((uint32_t)") + reg[3] + " );";
                                           }
                                           if (nopcode == NOP_PUTC)
                                           {
                                               cs.append(CodePart::INITIALREQUIRED).code() =
                                                   std::string("OR1K_printchar((char)") + reg[3] + " );";
                                           }
                                           if (nopcode == NOP_GET_PS)
                                           {
                                               cs.append(CodePart::INITIALREQUIRED).code() =
                                                   std::string(reg[11]) + " = (etiss_uint32) (cpu->cpuCycleTime_ps);";
                                           }
                                       }

                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_or(ORBIS32_I,

                                  "l.or",

                                  parse_i32("6x38 15x0 1x0 2x0 4x0 4x4"),

                                  parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                  simple_op_rDAB<'|'>,

                                  0,

                                  or1k_asm_print_rDAB

);

static InstructionDefinition l_ori(ORBIS32_I,

                                   "l.ori",

                                   parse_i32("6x2a 10x0 16x0"),

                                   parse_i32("6xFF 10x0 16x0"),

                                   simple_op_rDAI<'|', false>,

                                   0,

                                   or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_rfe(
    ORBIS32_I,

    "l.rfe",

    parse_i32("6x9 26x0"),

    parse_i32("6xFF 26x0"),

    [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
        std::stringstream ss;
        ss << "		((OR1K*)cpu)->instructionPointer_delayed = ((OR1K*)cpu)->EPCR_16[0];\n";
        ss << "		*((OR1K*)cpu)->SR = ((OR1K*)cpu)->ESR_16[0];";
        CodePart &cp = cs.append(CodePart::INITIALREQUIRED);
        cp.getRegisterDependencies().add(reg_name[rb.read(ba)], 32);
        cp.code() = ss.str();
        update_pc<true, false>(ba, cs, ic);
        return true;
    },

    0,

    or1k_asm_print_rDAB

);

static InstructionDefinition l_sb(ORBIS32_I,

                                  "l.sb",

                                  parse_i32("6x36 26x0"),

                                  parse_i32("6xFF 26x0"),

                                  storeinstr<int8_t>,

                                  0,

                                  or1k_asm_print_rDAB

);

static InstructionDefinition l_sfeq(ORBIS32_I,

                                    "l.sfeq",

                                    parse_i32("11x720 21x0"),

                                    parse_i32("11xFFF 21x0"),

                                    l_sf<true, false, '=', '='>,

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_sfges(ORBIS32_I,

                                     "l.sfges",

                                     parse_i32("11x72b 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<true, false, '>', '='>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfgeu(ORBIS32_I,

                                     "l.sfgeu",

                                     parse_i32("11x723 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<false, false, '>', '='>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfgts(ORBIS32_I,

                                     "l.sfgts",

                                     parse_i32("11x72a 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<true, false, '>'>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfgtu(ORBIS32_I,

                                     "l.sfgtu",

                                     parse_i32("11x722 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<false, false, '>'>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfles(ORBIS32_I,

                                     "l.sfles",

                                     parse_i32("11x72d 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<true, false, '<', '='>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfleu(ORBIS32_I,

                                     "l.sfleu",

                                     parse_i32("11x725 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<false, false, '<', '='>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sflts(ORBIS32_I,

                                     "l.sflts",

                                     parse_i32("11x72c 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<true, false, '<'>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfltu(ORBIS32_I,

                                     "l.sfltu",

                                     parse_i32("11x724 21x0"),

                                     parse_i32("11xFFF 21x0"),

                                     l_sf<false, false, '<'>,

                                     0,

                                     or1k_asm_print_rDAB

);

static InstructionDefinition l_sfne(ORBIS32_I,

                                    "l.sfne",

                                    parse_i32("11x721 21x0"),

                                    parse_i32("11xFFF 21x0"),

                                    l_sf<true, false, '!', '='>,

                                    0,

                                    or1k_asm_print_rDAB

);

static InstructionDefinition l_sh(ORBIS32_I,

                                  "l.sh",

                                  parse_i32("6x37 26x0"),

                                  parse_i32("6xFF 26x0"),

                                  storeinstr<int16_t>,

                                  0,

                                  or1k_asm_print_rDAB

);

static InstructionDefinition l_sll(ORBIS32_I,

                                   "l.sll",

                                   parse_i32("6x38 15x0 1x0 4x0 2x0 4x8"),

                                   parse_i32("6xFF 15x0 1x0 4xF 2x0 4xF"),

                                   shift<false, false, false>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_slli(ORBIS32_I,

                                    "l.slli",

                                    parse_i32("6x2e 10x0 8x0 2x0 6x0"),

                                    parse_i32("6xFF 10x0 8x0 2xF 6x0"),

                                    shift<false, false, true>,

                                    0,

                                    or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_sra(ORBIS32_I,

                                   "l.sra",

                                   parse_i32("6x38 15x0 1x0 4x2 2x0 4x8"),

                                   parse_i32("6xFF 15x0 1x0 4xF 2x0 4xF"),

                                   shift<true, true, false>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_srai(ORBIS32_I,

                                    "l.srai",

                                    parse_i32("6x2e 10x0 8x0 2x2 6x0"),

                                    parse_i32("6xFF 10x0 8x0 2xF 6x0"),

                                    shift<true, true, true>,

                                    0,

                                    or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_srl(ORBIS32_I,

                                   "l.srl",

                                   parse_i32("6x38 15x0 1x0 4x1 2x0 4x8"),

                                   parse_i32("6xFF 15x0 1x0 4xF 2x0 4xF"),

                                   shift<true, false, false>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_srli(ORBIS32_I,

                                    "l.srli",

                                    parse_i32("6x2e 10x0 8x0 2x1 6x0"),

                                    parse_i32("6xFF 10x0 8x0 2xF 6x0"),

                                    shift<true, false, true>,

                                    0,

                                    or1k_asm_print_rDAI<false>

);

static InstructionDefinition l_sub(ORBIS32_I,

                                   "l.sub",

                                   parse_i32("6x38 15x0 1x0 2x0 4x0 4x2"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       l_addsubX(std::string("(((OR1K*)cpu)->R[") + toString(ra.read(ba)) + "])",
                                                 std::string("(((OR1K*)cpu)->R[") + toString(rb.read(ba)) + "])",
                                                 std::string("(((OR1K*)cpu)->R[") + toString(rd.read(ba)) + "])", cs,
                                                 false, false);
                                       update_pc<false, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_sw(ORBIS32_I,

                                  "l.sw",

                                  parse_i32("6x35 26x0"),

                                  parse_i32("6xFF 26x0"),

                                  storeinstr<int32_t>,

                                  0,

                                  or1k_asm_print_rDAB

);

static InstructionDefinition l_sys(ORBIS32_I,

                                   "l.sys",

                                   parse_i32("16x2000 16x0"),

                                   parse_i32("16xFFFF 16x0"),

                                   [](BitArray &ba, etiss::CodeSet &cs, InstructionContext &ic) {
                                       cs.append(CodePart("return OR1K_SYSTEMCALLEXCEPTION +" +
                                                          toString(immediate.read(ba) & 0x0000FFFF) + ";"),
                                                 CodePart::APPENDEDRETURNINGREQUIRED);
                                       update_pc<true, false>(ba, cs, ic);
                                       return true;
                                   },

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_xor(ORBIS32_I,

                                   "l.xor",

                                   parse_i32("6x38 15x0 1x0 2x0 4x0 4x5"),

                                   parse_i32("6xFF 15x0 1x0 2xF 4x0 4xF"),

                                   simple_op_rDAB<'^'>,

                                   0,

                                   or1k_asm_print_rDAB

);

static InstructionDefinition l_xori(ORBIS32_I,

                                    "l.xori",

                                    parse_i32("6x2b 10x0 16x0"),

                                    parse_i32("6xFF 10x0 16x0"),

                                    simple_op_rDAI<'^', true>,

                                    0,

                                    or1k_asm_print_rDAI<true>

);
