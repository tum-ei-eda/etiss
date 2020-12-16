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
#include "etiss/jit/fpu/softfloat.h"

using namespace etiss;

void OR1KArch_apply_fpu_flags(OR1K *cpu, unsigned flags)
{
    etiss_uint32 val = *(cpu->FPCSR) & 0xFFFFF007;
    if (flags & float_flag_invalid)
    {
        val |= OR1K_FPCSR_IVF;
    }
    if (flags & float_flag_divbyzero)
    {
        val |= OR1K_FPCSR_DZF;
    }
    if (val & float_flag_overflow)
    {
        val |= OR1K_FPCSR_OVF;
    }
    if (val & float_flag_underflow)
    {
        val |= OR1K_FPCSR_UNF;
    }
    if (val & float_flag_inexact)
    {
        val |= OR1K_FPCSR_IXF;
    }
    *(cpu->FPCSR) = val;
}

void fpu_append_exceptioncode(etiss::CodeSet &ret)
{
    CodePart &part = ret.append(CodePart::APPENDEDRETURNINGREQUIRED);
    part.code() = "	if ((*(((OR1K*)cpu)->FPCSR))&OR1K_FPCSR_FPEE){\n"
                  "		if (or1k_fpu_flags){"
                  "			return OR1K_FLOATINGPOINTEXCEPTION;"
                  "		}"
                  "	}";
}

void translate_fpu(const etiss::uint32 instr, etiss::CodeSet &ret)
{
    switch ((instr >> 26) & 0x3F)
    {
    case 0x32:
        switch ((instr >> 4) & 0x0F)
        {
        case 0x00:
            switch (instr & 0xFF)
            {
            case 0x00: // lf.add.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F) << "] = float32_add(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x01: // lf.sub.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F) << "] = float32_sub(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x02: // lf.mul.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F) << "] = float32_mul(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x03: // lf.div.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F) << "] = float32_div(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x04: // lf.itof.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F) << "] = int32_to_float32(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x05: // lf.ftoi.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F)
                   << "] = ((*((OR1K*)cpu)->FPCSR)&OR1K_FPCSR_RM_0)?float32_to_int32_round_to_zero(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],&or1k_fpu_flags):float32_to_int32(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x06: // lf.rem.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F) << "] = float32_rem(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags);\n";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x07: // lf.madd.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "	((OR1K*)cpu)->R[" << ((instr >> 21) & 0x1F)
                   << "] = "
                      "		float32 or1k_mulr = float32_mul(((OR1K*)cpu)->R["
                   << ((instr >> 16) & 0x1F) << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags);"
                      "		float64 or1k_r64 = float32_to_float64(or1k_mulr);"
                      "		or1k_f64 = ((etiss_uint64)(*((OR1K*)cpu)->FPMADDHI))<<32 | "
                      "((etiss_uint64)(*((OR1K*)cpu)->FPMADDLO));"
                      "		or1k_r64 = float64_add(or1k_r64,or1k_f64,&or1k_fpu_flags);"
                      "		*((OR1K*)cpu)->FPMADDLO = (etiss_uint32)or1k_r64;"
                      "		*((OR1K*)cpu)->FPMADDHI = (etiss_uint32)(or1k_r64>>32);";
                ss << "	OR1KArch_apply_fpu_flags(((OR1K*)cpu),or1k_fpu_flags);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();

                fpu_append_exceptioncode(ret);
            }
            break;
            case 0x08: // lf.sfeq.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "*((OR1K*)cpu)->SR = float32_eq(((OR1K*)cpu)->R[" << ((instr >> 16) & 0x1F)
                   << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags)"
                      "			?"
                      "		((*((OR1K*)cpu)->SR)|OR1K_SR_F)"
                      "		:"
                      "		((*((OR1K*)cpu)->SR)&~OR1K_SR_F);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();
            }
            break;
            case 0x09: // lf.sfne.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "*((OR1K*)cpu)->SR = float32_eq(((OR1K*)cpu)->R[" << ((instr >> 16) & 0x1F)
                   << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags)"
                      "			?"
                      "		((*((OR1K*)cpu)->SR)&~OR1K_SR_F)"
                      "		:"
                      "		((*((OR1K*)cpu)->SR)|OR1K_SR_F);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();
            }
            break;
            case 0x0A: // lf.sfgt.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "*((OR1K*)cpu)->SR = float32_lt(((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],((OR1K*)cpu)->R[" << ((instr >> 16) & 0x1F)
                   << "],&or1k_fpu_flags)"
                      "			?"
                      "		((*((OR1K*)cpu)->SR)|OR1K_SR_F)"
                      "		:"
                      "		((*((OR1K*)cpu)->SR)&~OR1K_SR_F);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();
            }
            break;
            case 0x0B: // lf.sfge.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "*((OR1K*)cpu)->SR = float32_le(((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],((OR1K*)cpu)->R[" << ((instr >> 16) & 0x1F)
                   << "],&or1k_fpu_flags)"
                      "			?"
                      "		((*((OR1K*)cpu)->SR)|OR1K_SR_F)"
                      "		:"
                      "		((*((OR1K*)cpu)->SR)&~OR1K_SR_F);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();
            }
            break;
            case 0x0C: // lf.sflt.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "*((OR1K*)cpu)->SR = float32_lt(((OR1K*)cpu)->R[" << ((instr >> 16) & 0x1F)
                   << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags)"
                      "			?"
                      "		((*((OR1K*)cpu)->SR)|OR1K_SR_F)"
                      "		:"
                      "		((*((OR1K*)cpu)->SR)&~OR1K_SR_F);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();
            }
            break;
            case 0x0D: // lf.sfle.s
            {
                std::stringstream ss;
                ss << "	unsigned or1k_fpu_flags = 0;\n";
                ss << "*((OR1K*)cpu)->SR = float32_le(((OR1K*)cpu)->R[" << ((instr >> 16) & 0x1F)
                   << "],((OR1K*)cpu)->R[" << ((instr >> 11) & 0x1F)
                   << "],&or1k_fpu_flags)"
                      "			?"
                      "		((*((OR1K*)cpu)->SR)|OR1K_SR_F)"
                      "		:"
                      "		((*((OR1K*)cpu)->SR)&~OR1K_SR_F);";
                CodePart &part = ret.append(CodePart::INITIALREQUIRED);
                part.code() = ss.str();
            }
            break;
            default:
                OR1KArch_translateInvalidInstruction(ret) std::cout << "OR1K TRANSLATION ERROR: unknown opcode2 0x"
                                                                    << std::hex << (instr & 0x0F) << std::dec
                                                                    << std::endl;
                break;
            }
            break;
        case 0x01:
            switch (instr & 0xFF)
            {
            case 0x00: // lf.add.d
            case 0x01: // lf.sub.d
            case 0x02: // lf.mul.d
            case 0x03: // lf.div.d
            case 0x04: // lf.itof.d
            case 0x05: // lf.ftoi.d
            case 0x06: // lf.rem.d
            case 0x07: // lf.madd.d
            case 0x08: // lf.sfeq.d
            case 0x09: // lf.sfne.d
            case 0x0A: // lf.sfgt.d
            case 0x0B: // lf.sfge.d
            case 0x0C: // lf.sflt.d
            case 0x0D: // lf.sfle.d
                OR1KArch_translateInvalidInstruction(ret) break;
            default:
                OR1KArch_translateInvalidInstruction(ret) break;
            }
            break;
        case 0x0e: // lf.cust1.d
            OR1KArch_translateInvalidInstruction(ret) break;
        case 0x0d: // lf.cust1.s
            // ignore
            break;
        default:
            OR1KArch_translateInvalidInstruction(ret) break;
        }
        break;
    default:
        OR1KArch_translateInvalidInstruction(ret) break;
    }
}
