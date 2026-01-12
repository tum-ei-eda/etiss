/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the instruction behavior models of the RV32F
 * instruction set for the XIsaacCore core architecture.
 */

#include "XIsaacCoreArch.h"
#include "XIsaacCoreFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// FLW -------------------------------------------------------------------------
static InstructionDefinition flw_rd_rs1_imm (
	ISA32_XIsaacCore,
	"flw",
	(uint32_t) 0x002007,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FLW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 89);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3477);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 3444, 3443, 3439, 3438, 3436, 3442, 3440);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 res = (etiss_uint32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 3451, 3450, 3448, 3447);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3476);\n";
cp.code() += "{ // block\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3475, 3463, 3462, 3474, 3473, 3471);\n";
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
	ISA32_XIsaacCore,
	"fsw",
	(uint32_t) 0x002027,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 90);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3498);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 3488, 3487, 3483, 3482, 3480, 3486, 3484);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint32)(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(6, 3497, 3491, 3490, 3496, 3494, 3493);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_XIsaacCore,
	"fmadd_s",
	(uint32_t) 0x000043,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMADD_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 91);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3569);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3553);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fmadd_s(unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]), unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]), unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs3) + "ULL]), 0LL, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 3537, 3536, 3524, 3523, 3522, 3528, 3527, 3526, 3532, 3531, 3530, 3533, 3535, 3534);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3552, 3540, 3539, 3551, 3550, 3548);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3556, 3555);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3568, 3557, 3567, 3561, 3558, 3562, 3565, 3563, 3566);\n";
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
	ISA32_XIsaacCore,
	"fmsub_s",
	(uint32_t) 0x000047,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMSUB_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 92);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3640);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3624);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fmadd_s(unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]), unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]), unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs3) + "ULL]), 1ULL, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 3608, 3607, 3595, 3594, 3593, 3599, 3598, 3597, 3603, 3602, 3601, 3604, 3606, 3605);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3623, 3611, 3610, 3622, 3621, 3619);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3627, 3626);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3639, 3628, 3638, 3632, 3629, 3633, 3636, 3634, 3637);\n";
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
	ISA32_XIsaacCore,
	"fnmadd_s",
	(uint32_t) 0x00004f,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FNMADD_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 93);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3720);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3704);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3667, 3666, 3665, 3664);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3673, 3672, 3671, 3670);\n";
cp.code() += "etiss_uint32 frs3 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3679, 3678, 3677, 3676);\n";
cp.code() += "etiss_uint32 res = fmadd_s(frs1, frs2, frs3, 2ULL, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(8, 3688, 3687, 3681, 3682, 3683, 3684, 3686, 3685);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3703, 3691, 3690, 3702, 3701, 3699);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3707, 3706);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3719, 3708, 3718, 3712, 3709, 3713, 3716, 3714, 3717);\n";
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
	ISA32_XIsaacCore,
	"fnmsub_s",
	(uint32_t) 0x00004b,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FNMSUB_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 94);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3800);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3784);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3747, 3746, 3745, 3744);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3753, 3752, 3751, 3750);\n";
cp.code() += "etiss_uint32 frs3 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3759, 3758, 3757, 3756);\n";
cp.code() += "etiss_uint32 res = fmadd_s(frs1, frs2, frs3, 3ULL, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(8, 3768, 3767, 3761, 3762, 3763, 3764, 3766, 3765);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3783, 3771, 3770, 3782, 3781, 3779);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3787, 3786);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3799, 3788, 3798, 3792, 3789, 3793, 3796, 3794, 3797);\n";
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
	ISA32_XIsaacCore,
	"fadd_s",
	(uint32_t) 0x000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FADD_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 95);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3868);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3852);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3823, 3822, 3821, 3820);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3829, 3828, 3827, 3826);\n";
cp.code() += "etiss_uint32 res = fadd_s(frs1, frs2, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3836, 3835, 3831, 3832, 3834, 3833);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3851, 3839, 3838, 3850, 3849, 3847);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3855, 3854);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3867, 3856, 3866, 3860, 3857, 3861, 3864, 3862, 3865);\n";
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
	ISA32_XIsaacCore,
	"fsub_s",
	(uint32_t) 0x8000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSUB_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 96);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3936);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3920);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3891, 3890, 3889, 3888);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3897, 3896, 3895, 3894);\n";
cp.code() += "etiss_uint32 res = fsub_s(frs1, frs2, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3904, 3903, 3899, 3900, 3902, 3901);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3919, 3907, 3906, 3918, 3917, 3915);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3923, 3922);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 3935, 3924, 3934, 3928, 3925, 3929, 3932, 3930, 3933);\n";
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
	ISA32_XIsaacCore,
	"fmul_s",
	(uint32_t) 0x10000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMUL_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 97);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4004);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3988);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3959, 3958, 3957, 3956);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 3965, 3964, 3963, 3962);\n";
cp.code() += "etiss_uint32 res = fmul_s(frs1, frs2, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 3972, 3971, 3967, 3968, 3970, 3969);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 3987, 3975, 3974, 3986, 3985, 3983);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 3991, 3990);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4003, 3992, 4002, 3996, 3993, 3997, 4000, 3998, 4001);\n";
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
	ISA32_XIsaacCore,
	"fdiv_s",
	(uint32_t) 0x18000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FDIV_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 98);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4072);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4056);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4027, 4026, 4025, 4024);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4033, 4032, 4031, 4030);\n";
cp.code() += "etiss_uint32 res = fdiv_s(frs1, frs2, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(6, 4040, 4039, 4035, 4036, 4038, 4037);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4055, 4043, 4042, 4054, 4053, 4051);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4059, 4058);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4071, 4060, 4070, 4064, 4061, 4065, 4068, 4066, 4069);\n";
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
	ISA32_XIsaacCore,
	"fsqrt_s",
	(uint32_t) 0x58000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSQRT_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 99);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4130);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4114);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4092, 4091, 4090, 4089);\n";
cp.code() += "etiss_uint32 res = fsqrt_s(frs1, XIsaacCore_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(5, 4098, 4097, 4094, 4096, 4095);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4113, 4101, 4100, 4112, 4111, 4109);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4117, 4116);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4129, 4118, 4128, 4122, 4119, 4123, 4126, 4124, 4127);\n";
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
	ISA32_XIsaacCore,
	"fsgnj_s",
	(uint32_t) 0x20000053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSGNJ_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 100);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4189);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4188);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4157, 4156, 4155, 4154);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4163, 4162, 4161, 4160);\n";
cp.code() += "etiss_uint32 res = ((((((frs2) >> (31ULL)) & 1ULL)) << 31) | ((((frs1) >> (0LL)) & 2147483647ULL)));\n";
cp.code() += "etiss_coverage_count(10, 4174, 4173, 4168, 4165, 4166, 4167, 4172, 4169, 4170, 4171);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4187, 4177, 4176, 4186, 4185, 4183);\n";
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
	ISA32_XIsaacCore,
	"fsgnjn_s",
	(uint32_t) 0x20001053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSGNJN_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 101);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4250);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4249);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4217, 4216, 4215, 4214);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4223, 4222, 4221, 4220);\n";
cp.code() += "etiss_uint32 res = (((~((((frs2) >> (31ULL)) & 1ULL))) << 31) | ((((frs1) >> (0LL)) & 2147483647ULL)));\n";
cp.code() += "etiss_coverage_count(11, 4235, 4234, 4229, 4228, 4225, 4226, 4227, 4233, 4230, 4231, 4232);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4248, 4238, 4237, 4247, 4246, 4244);\n";
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
	ISA32_XIsaacCore,
	"fsgnjx_s",
	(uint32_t) 0x20002053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSGNJX_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 102);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4305);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4304);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4274, 4273, 4272, 4271);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4280, 4279, 4278, 4277);\n";
cp.code() += "etiss_uint32 res = frs1 ^ (frs2 & 2147483648ULL);\n";
cp.code() += "etiss_coverage_count(7, 4288, 4287, 4282, 4285, 4283, 4284, 4286);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4303, 4291, 4290, 4302, 4301, 4299);\n";
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
	ISA32_XIsaacCore,
	"fmin_s",
	(uint32_t) 0x28000053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMIN_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 103);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4371);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4355);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4327, 4326, 4325, 4324);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4333, 4332, 4331, 4330);\n";
cp.code() += "etiss_uint32 res = fsel_s(frs1, frs2, 0LL);\n";
cp.code() += "etiss_coverage_count(5, 4339, 4338, 4335, 4336, 4337);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4354, 4342, 4341, 4353, 4352, 4350);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4358, 4357);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4370, 4359, 4369, 4363, 4360, 4364, 4367, 4365, 4368);\n";
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
	ISA32_XIsaacCore,
	"fmax_s",
	(uint32_t) 0x28001053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMAX_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 104);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4437);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4421);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4393, 4392, 4391, 4390);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4399, 4398, 4397, 4396);\n";
cp.code() += "etiss_uint32 res = fsel_s(frs1, frs2, 1ULL);\n";
cp.code() += "etiss_coverage_count(5, 4405, 4404, 4401, 4402, 4403);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4420, 4408, 4407, 4419, 4418, 4416);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4424, 4423);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4436, 4425, 4435, 4429, 4426, 4430, 4433, 4431, 4434);\n";
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
	ISA32_XIsaacCore,
	"fcvt_w_s",
	(uint32_t) 0xc0000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_W_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 105);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4495);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4440, 4439);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4465);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4458, 4457, 4456, 4455);\n";
cp.code() += "res = fcvt_s(frs1, 0LL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 4464, 4459, 4463, 4460, 4461, 4462);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4466);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4472, 4469, 4467, 4470, 4471);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4479, 4477, 4476, 4474, 4478);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4482, 4481);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4494, 4483, 4493, 4487, 4484, 4488, 4491, 4489, 4492);\n";
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
	ISA32_XIsaacCore,
	"fcvt_wu_s",
	(uint32_t) 0xc0100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_WU_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 106);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4556);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4498, 4497);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4523);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4516, 4515, 4514, 4513);\n";
cp.code() += "res = fcvt_s(frs1, 1ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 4522, 4517, 4521, 4518, 4519, 4520);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4524);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4530, 4527, 4525, 4528, 4529);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((etiss_int32)(res));\n";
cp.code() += "etiss_coverage_count(7, 4540, 4535, 4534, 4532, 4539, 4537, 4536);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4543, 4542);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4555, 4544, 4554, 4548, 4545, 4549, 4552, 4550, 4553);\n";
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
	ISA32_XIsaacCore,
	"feq_s",
	(uint32_t) 0xa0002053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FEQ_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 107);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4622);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4559, 4558);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4592);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4579, 4578, 4577, 4576);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4585, 4584, 4583, 4582);\n";
cp.code() += "res = fcmp_s(frs1, frs2, 0LL);\n";
cp.code() += "etiss_coverage_count(6, 4591, 4586, 4590, 4587, 4588, 4589);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4593);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4599, 4596, 4594, 4597, 4598);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4606, 4604, 4603, 4601, 4605);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4609, 4608);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4621, 4610, 4620, 4614, 4611, 4615, 4618, 4616, 4619);\n";
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
	ISA32_XIsaacCore,
	"flt_s",
	(uint32_t) 0xa0001053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FLT_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 108);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4688);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4625, 4624);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4658);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4645, 4644, 4643, 4642);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4651, 4650, 4649, 4648);\n";
cp.code() += "res = fcmp_s(frs1, frs2, 2ULL);\n";
cp.code() += "etiss_coverage_count(6, 4657, 4652, 4656, 4653, 4654, 4655);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4659);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4665, 4662, 4660, 4663, 4664);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4672, 4670, 4669, 4667, 4671);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4675, 4674);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4687, 4676, 4686, 4680, 4677, 4681, 4684, 4682, 4685);\n";
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
	ISA32_XIsaacCore,
	"fle_s",
	(uint32_t) 0xa0000053,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FLE_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 109);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4754);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4691, 4690);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4724);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 frs1 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4711, 4710, 4709, 4708);\n";
cp.code() += "etiss_uint32 frs2 = unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(4, 4717, 4716, 4715, 4714);\n";
cp.code() += "res = fcmp_s(frs1, frs2, 1ULL);\n";
cp.code() += "etiss_coverage_count(6, 4723, 4718, 4722, 4719, 4720, 4721);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 4725);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4731, 4728, 4726, 4729, 4730);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4738, 4736, 4735, 4733, 4737);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 4741, 4740);\n";
cp.code() += "((XIsaacCore*)cpu)->FCSR = (((XIsaacCore*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 4753, 4742, 4752, 4746, 4743, 4747, 4750, 4748, 4751);\n";
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
	ISA32_XIsaacCore,
	"fclass_s",
	(uint32_t) 0xe0001053,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCLASS_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 110);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4789);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 4757, 4756);\n";
cp.code() += "res = fclass_s(unbox_s(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]));\n";
cp.code() += "etiss_coverage_count(6, 4774, 4768, 4773, 4772, 4771, 4770);\n";
cp.code() += "etiss_coverage_count(1, 4775);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4781, 4778, 4776, 4779, 4780);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 4788, 4786, 4785, 4783, 4787);\n";
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
	ISA32_XIsaacCore,
	"fcvt_s_w",
	(uint32_t) 0xd0000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_S_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 111);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4834);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4833);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fcvt_s((etiss_uint32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 2ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 4817, 4816, 4813, 4812, 4811, 4809, 4814, 4815);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4832, 4820, 4819, 4831, 4830, 4828);\n";
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
	ISA32_XIsaacCore,
	"fcvt_s_wu",
	(uint32_t) 0xd0100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_S_WU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 112);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4879);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4878);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fcvt_s((etiss_uint32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 3ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 4862, 4861, 4858, 4857, 4856, 4854, 4859, 4860);\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 4877, 4865, 4864, 4876, 4875, 4873);\n";
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
	ISA32_XIsaacCore,
	"fmv_x_w",
	(uint32_t) 0xe0000053,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMV_X_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 113);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4900);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 4880);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 4886, 4883, 4881, 4884, 4885);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((etiss_int32)(((XIsaacCore*)cpu)->F[" + std::to_string(rs1) + "ULL]));\n";
cp.code() += "etiss_coverage_count(8, 4899, 4891, 4890, 4888, 4898, 4896, 4894, 4893);\n";
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
	ISA32_XIsaacCore,
	"fmv_w_x",
	(uint32_t) 0xf0000053,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMV_W_X\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 114);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 4934);\n";
cp.code() += "{ // block\n";
{ // block
cp.code() += "etiss_coverage_count(1, 4933);\n";
cp.code() += "{ // block\n";
cp.code() += "((XIsaacCore*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL | (etiss_uint64)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 4932, 4916, 4915, 4931, 4930, 4928, 4927, 4925);\n";
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
