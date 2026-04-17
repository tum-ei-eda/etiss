// clang-format off
/**
 * Generated on Fri, 17 Apr 2026 10:56:08 +0200.
 *
 * This file contains the instruction behavior models of the RV32F
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// FLW -------------------------------------------------------------------------
static InstructionDefinition flw_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"flw",
	(uint32_t) 0x002007,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FLW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 88);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3395);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 3359, 3358, 3354, 3353, 3351, 3357, 3355);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 res = (etiss_uint32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 3369, 3368, 3366, 3364, 3362, 3363);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3394);\n";
cp.code() += "{ // block\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3393, 3381, 3380, 3392, 3391, 3389);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//FLW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "flw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSW -------------------------------------------------------------------------
static InstructionDefinition fsw_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsw",
	(uint32_t) 0x002027,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 89);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3419);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 3406, 3405, 3401, 3400, 3398, 3404, 3402);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint32)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 3418, 3412, 3410, 3408, 3409, 3417, 3415, 3414);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//FSW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsw" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMADD_S ---------------------------------------------------------------------
static InstructionDefinition fmadd_s_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fmadd_s",
	(uint32_t) 0x000043,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMADD_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 90);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3490);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3474);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fmadd_s(unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 0LL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 3458, 3457, 3445, 3444, 3443, 3449, 3448, 3447, 3453, 3452, 3451, 3454, 3456, 3455);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3473, 3461, 3460, 3472, 3471, 3469);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3477, 3476);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3489, 3478, 3488, 3482, 3479, 3483, 3486, 3484, 3487);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmadd_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMSUB_S ---------------------------------------------------------------------
static InstructionDefinition fmsub_s_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fmsub_s",
	(uint32_t) 0x000047,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMSUB_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 91);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3561);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3545);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fmadd_s(unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 1ULL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 3529, 3528, 3516, 3515, 3514, 3520, 3519, 3518, 3524, 3523, 3522, 3525, 3527, 3526);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3544, 3532, 3531, 3543, 3542, 3540);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3548, 3547);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3560, 3549, 3559, 3553, 3550, 3554, 3557, 3555, 3558);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmsub_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FNMADD_S --------------------------------------------------------------------
static InstructionDefinition fnmadd_s_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fnmadd_s",
	(uint32_t) 0x00004f,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FNMADD_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 92);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3641);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3625);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3588, 3587, 3586, 3585);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3594, 3593, 3592, 3591);\n";
cp.code() += "etiss_uint32 frs3 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3600, 3599, 3598, 3597);\n";
cp.code() += "etiss_uint32 res = fmadd_s(frs1, frs2, frs3, 2ULL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(8, 3609, 3608, 3602, 3603, 3604, 3605, 3607, 3606);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3624, 3612, 3611, 3623, 3622, 3620);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3628, 3627);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3640, 3629, 3639, 3633, 3630, 3634, 3637, 3635, 3638);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fnmadd_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FNMSUB_S --------------------------------------------------------------------
static InstructionDefinition fnmsub_s_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fnmsub_s",
	(uint32_t) 0x00004b,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FNMSUB_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 93);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3721);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3705);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3668, 3667, 3666, 3665);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3674, 3673, 3672, 3671);\n";
cp.code() += "etiss_uint32 frs3 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3680, 3679, 3678, 3677);\n";
cp.code() += "etiss_uint32 res = fmadd_s(frs1, frs2, frs3, 3ULL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(8, 3689, 3688, 3682, 3683, 3684, 3685, 3687, 3686);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3704, 3692, 3691, 3703, 3702, 3700);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3708, 3707);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3720, 3709, 3719, 3713, 3710, 3714, 3717, 3715, 3718);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fnmsub_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FADD_S ----------------------------------------------------------------------
static InstructionDefinition fadd_s_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fadd_s",
	(uint32_t) 0x000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FADD_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 94);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3789);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3773);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3744, 3743, 3742, 3741);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3750, 3749, 3748, 3747);\n";
cp.code() += "etiss_uint32 res = fadd_s(frs1, frs2, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3757, 3756, 3752, 3753, 3755, 3754);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3772, 3760, 3759, 3771, 3770, 3768);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3776, 3775);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3788, 3777, 3787, 3781, 3778, 3782, 3785, 3783, 3786);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fadd_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSUB_S ----------------------------------------------------------------------
static InstructionDefinition fsub_s_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsub_s",
	(uint32_t) 0x8000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSUB_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 95);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3857);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3841);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3812, 3811, 3810, 3809);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3818, 3817, 3816, 3815);\n";
cp.code() += "etiss_uint32 res = fsub_s(frs1, frs2, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3825, 3824, 3820, 3821, 3823, 3822);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3840, 3828, 3827, 3839, 3838, 3836);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3844, 3843);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3856, 3845, 3855, 3849, 3846, 3850, 3853, 3851, 3854);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsub_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMUL_S ----------------------------------------------------------------------
static InstructionDefinition fmul_s_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmul_s",
	(uint32_t) 0x10000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMUL_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 96);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3925);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3909);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3880, 3879, 3878, 3877);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3886, 3885, 3884, 3883);\n";
cp.code() += "etiss_uint32 res = fmul_s(frs1, frs2, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3893, 3892, 3888, 3889, 3891, 3890);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3908, 3896, 3895, 3907, 3906, 3904);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3912, 3911);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3924, 3913, 3923, 3917, 3914, 3918, 3921, 3919, 3922);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmul_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FDIV_S ----------------------------------------------------------------------
static InstructionDefinition fdiv_s_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fdiv_s",
	(uint32_t) 0x18000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FDIV_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 97);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3993);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3977);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3948, 3947, 3946, 3945);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3954, 3953, 3952, 3951);\n";
cp.code() += "etiss_uint32 res = fdiv_s(frs1, frs2, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3961, 3960, 3956, 3957, 3959, 3958);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3976, 3964, 3963, 3975, 3974, 3972);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3980, 3979);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3992, 3981, 3991, 3985, 3982, 3986, 3989, 3987, 3990);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fdiv_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSQRT_S ---------------------------------------------------------------------
static InstructionDefinition fsqrt_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fsqrt_s",
	(uint32_t) 0x58000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSQRT_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 98);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4051);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4035);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4013, 4012, 4011, 4010);\n";
cp.code() += "etiss_uint32 res = fsqrt_s(frs1, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(5, 4019, 4018, 4015, 4017, 4016);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4034, 4022, 4021, 4033, 4032, 4030);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4038, 4037);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4050, 4039, 4049, 4043, 4040, 4044, 4047, 4045, 4048);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsqrt_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJ_S ---------------------------------------------------------------------
static InstructionDefinition fsgnj_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnj_s",
	(uint32_t) 0x20000053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSGNJ_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 99);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4110);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4109);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4078, 4077, 4076, 4075);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4084, 4083, 4082, 4081);\n";
cp.code() += "etiss_uint32 res = ((((((frs2) >> (31ULL)) & 0x1ULL)) << 31) | (((frs1) & 0x7fffffffULL)));\n";
cp.code() += "etiss_coverage_count(10, 4095, 4094, 4089, 4086, 4087, 4088, 4093, 4090, 4091, 4092);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4108, 4098, 4097, 4107, 4106, 4104);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsgnj_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJN_S --------------------------------------------------------------------
static InstructionDefinition fsgnjn_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnjn_s",
	(uint32_t) 0x20001053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSGNJN_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 100);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4171);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4170);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4138, 4137, 4136, 4135);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4144, 4143, 4142, 4141);\n";
cp.code() += "etiss_uint32 res = (((~((((frs2) >> (31ULL)) & 0x1ULL))) << 31) | (((frs1) & 0x7fffffffULL)));\n";
cp.code() += "etiss_coverage_count(11, 4156, 4155, 4150, 4149, 4146, 4147, 4148, 4154, 4151, 4152, 4153);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4169, 4159, 4158, 4168, 4167, 4165);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsgnjn_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJX_S --------------------------------------------------------------------
static InstructionDefinition fsgnjx_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnjx_s",
	(uint32_t) 0x20002053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSGNJX_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 101);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4226);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4225);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4195, 4194, 4193, 4192);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4201, 4200, 4199, 4198);\n";
cp.code() += "etiss_uint32 res = frs1 ^ (frs2 & 2147483648ULL);\n";
cp.code() += "etiss_coverage_count(7, 4209, 4208, 4203, 4206, 4204, 4205, 4207);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4224, 4212, 4211, 4223, 4222, 4220);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsgnjx_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMIN_S ----------------------------------------------------------------------
static InstructionDefinition fmin_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmin_s",
	(uint32_t) 0x28000053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMIN_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 102);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4292);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4276);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4248, 4247, 4246, 4245);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4254, 4253, 4252, 4251);\n";
cp.code() += "etiss_uint32 res = fsel_s(frs1, frs2, 0LL);\n";
cp.code() += "etiss_coverage_count(5, 4260, 4259, 4256, 4257, 4258);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4275, 4263, 4262, 4274, 4273, 4271);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4279, 4278);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4291, 4280, 4290, 4284, 4281, 4285, 4288, 4286, 4289);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmin_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMAX_S ----------------------------------------------------------------------
static InstructionDefinition fmax_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmax_s",
	(uint32_t) 0x28001053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMAX_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 103);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4358);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4342);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4314, 4313, 4312, 4311);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4320, 4319, 4318, 4317);\n";
cp.code() += "etiss_uint32 res = fsel_s(frs1, frs2, 1ULL);\n";
cp.code() += "etiss_coverage_count(5, 4326, 4325, 4322, 4323, 4324);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4341, 4329, 4328, 4340, 4339, 4337);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4345, 4344);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4357, 4346, 4356, 4350, 4347, 4351, 4354, 4352, 4355);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmax_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_W_S --------------------------------------------------------------------
static InstructionDefinition fcvt_w_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_w_s",
	(uint32_t) 0xc0000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_W_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 104);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4416);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4361, 4360);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4386);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4379, 4378, 4377, 4376);\n";
cp.code() += "res = fcvt_s(frs1, 0LL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 4385, 4380, 4384, 4381, 4382, 4383);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4387);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4393, 4390, 4388, 4391, 4392);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4400, 4398, 4397, 4395, 4399);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4403, 4402);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4415, 4404, 4414, 4408, 4405, 4409, 4412, 4410, 4413);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_w_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_WU_S -------------------------------------------------------------------
static InstructionDefinition fcvt_wu_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_wu_s",
	(uint32_t) 0xc0100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_WU_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 105);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4477);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4419, 4418);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4444);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4437, 4436, 4435, 4434);\n";
cp.code() += "res = fcvt_s(frs1, 1ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 4443, 4438, 4442, 4439, 4440, 4441);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4445);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4451, 4448, 4446, 4449, 4450);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(res));\n";
cp.code() += "etiss_coverage_count(7, 4461, 4456, 4455, 4453, 4460, 4458, 4457);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4464, 4463);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4476, 4465, 4475, 4469, 4466, 4470, 4473, 4471, 4474);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_wu_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FEQ_S -----------------------------------------------------------------------
static InstructionDefinition feq_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"feq_s",
	(uint32_t) 0xa0002053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FEQ_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 106);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4543);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4480, 4479);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4513);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4500, 4499, 4498, 4497);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4506, 4505, 4504, 4503);\n";
cp.code() += "res = fcmp_s(frs1, frs2, 0LL);\n";
cp.code() += "etiss_coverage_count(6, 4512, 4507, 4511, 4508, 4509, 4510);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4514);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4520, 4517, 4515, 4518, 4519);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4527, 4525, 4524, 4522, 4526);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4530, 4529);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4542, 4531, 4541, 4535, 4532, 4536, 4539, 4537, 4540);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "feq_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FLT_S -----------------------------------------------------------------------
static InstructionDefinition flt_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"flt_s",
	(uint32_t) 0xa0001053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FLT_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 107);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4609);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4546, 4545);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4579);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4566, 4565, 4564, 4563);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4572, 4571, 4570, 4569);\n";
cp.code() += "res = fcmp_s(frs1, frs2, 2ULL);\n";
cp.code() += "etiss_coverage_count(6, 4578, 4573, 4577, 4574, 4575, 4576);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4580);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4586, 4583, 4581, 4584, 4585);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4593, 4591, 4590, 4588, 4592);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4596, 4595);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4608, 4597, 4607, 4601, 4598, 4602, 4605, 4603, 4606);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "flt_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FLE_S -----------------------------------------------------------------------
static InstructionDefinition fle_s_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fle_s",
	(uint32_t) 0xa0000053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FLE_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 108);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4675);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4612, 4611);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4645);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4632, 4631, 4630, 4629);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4638, 4637, 4636, 4635);\n";
cp.code() += "res = fcmp_s(frs1, frs2, 1ULL);\n";
cp.code() += "etiss_coverage_count(6, 4644, 4639, 4643, 4640, 4641, 4642);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4646);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4652, 4649, 4647, 4650, 4651);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4659, 4657, 4656, 4654, 4658);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4662, 4661);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4674, 4663, 4673, 4667, 4664, 4668, 4671, 4669, 4672);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fle_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCLASS_S --------------------------------------------------------------------
static InstructionDefinition fclass_s_rd_rs1 (
	ISA32_RV64IMACFD,
	"fclass_s",
	(uint32_t) 0xe0001053,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCLASS_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 109);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4710);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4678, 4677);\n";
cp.code() += "res = fclass_s(unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]));\n";
cp.code() += "etiss_coverage_count(6, 4695, 4689, 4694, 4693, 4692, 4691);\n";
cp.code() += "etiss_coverage_count(1, 4696);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4702, 4699, 4697, 4700, 4701);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4709, 4707, 4706, 4704, 4708);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fclass_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_S_W --------------------------------------------------------------------
static InstructionDefinition fcvt_s_w_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_s_w",
	(uint32_t) 0xd0000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_S_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 110);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4755);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4754);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fcvt_s((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 2ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 4738, 4737, 4734, 4733, 4732, 4730, 4735, 4736);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4753, 4741, 4740, 4752, 4751, 4749);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_s_w" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_S_WU -------------------------------------------------------------------
static InstructionDefinition fcvt_s_wu_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_s_wu",
	(uint32_t) 0xd0100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_S_WU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 111);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4800);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4799);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fcvt_s((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 3ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 4783, 4782, 4779, 4778, 4777, 4775, 4780, 4781);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4798, 4786, 4785, 4797, 4796, 4794);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_s_wu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMV_X_W ---------------------------------------------------------------------
static InstructionDefinition fmv_x_w_rd_rs1 (
	ISA32_RV64IMACFD,
	"fmv_x_w",
	(uint32_t) 0xe0000053,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMV_X_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 112);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4821);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 4801);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4807, 4804, 4802, 4805, 4806);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]));\n";
cp.code() += "etiss_coverage_count(8, 4820, 4812, 4811, 4809, 4819, 4817, 4815, 4814);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmv_x_w" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMV_W_X ---------------------------------------------------------------------
static InstructionDefinition fmv_w_x_rd_rs1 (
	ISA32_RV64IMACFD,
	"fmv_w_x",
	(uint32_t) 0xf0000053,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMV_W_X\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 113);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4855);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4854);\n";
cp.code() += "{ // block\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 4853, 4837, 4836, 4852, 4851, 4849, 4848, 4846);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmv_w_x" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
