// clang-format off
/**
 * Generated on Wed, 28 Oct 2026 07:20:58 +0000.
 *
 * This file contains the instruction behavior models of the RV32D
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// FLD -------------------------------------------------------------------------
static InstructionDefinition fld_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"fld",
	(uint64_t) 0x003007,
	(uint64_t) 0x00707f,
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

		cp.code() = std::string("//FLD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 118);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5528);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = (etiss_uint64)((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL));\n";
cp.code() += "etiss_coverage_count(9, 5489, 5488, 5485, 5481, 5480, 5478, 5484, 5482, 5486);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint64 res = (etiss_uint64)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 5499, 5498, 5496, 5494, 5492, 5493);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5510, 5506, 5505, 5509, 5507);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//FLD\n");

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
ss << "fld" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSD -------------------------------------------------------------------------
static InstructionDefinition fsd_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsd",
	(uint64_t) 0x003027,
	(uint64_t) 0x00707f,
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

		cp.code() = std::string("//FSD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 119);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5555);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = (etiss_uint64)((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL));\n";
cp.code() += "etiss_coverage_count(9, 5542, 5541, 5538, 5534, 5533, 5531, 5537, 5535, 5539);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 5554, 5548, 5546, 5544, 5545, 5553, 5551, 5550);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
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

		cp.code() = std::string("//FSD\n");

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
ss << "fsd" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMADD_D ---------------------------------------------------------------------
static InstructionDefinition fmadd_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fmadd_d",
	(uint64_t) 0x2000043,
	(uint64_t) 0x600007f,
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

		cp.code() = std::string("//FMADD_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 120);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5625);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 0LL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 5576, 5575, 5561, 5559, 5558, 5566, 5564, 5563, 5571, 5569, 5568, 5572, 5574, 5573);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5587, 5583, 5582, 5586, 5584);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 5607, 5606);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 5624, 5608, 5623, 5620, 5614, 5609, 5615, 5618, 5616, 5619, 5621);\n";
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
ss << "fmadd_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMSUB_D ---------------------------------------------------------------------
static InstructionDefinition fmsub_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fmsub_d",
	(uint64_t) 0x2000047,
	(uint64_t) 0x600007f,
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

		cp.code() = std::string("//FMSUB_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 121);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5695);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 1ULL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 5646, 5645, 5631, 5629, 5628, 5636, 5634, 5633, 5641, 5639, 5638, 5642, 5644, 5643);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5657, 5653, 5652, 5656, 5654);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 5677, 5676);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 5694, 5678, 5693, 5690, 5684, 5679, 5685, 5688, 5686, 5689, 5691);\n";
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
ss << "fmsub_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FNMADD_D --------------------------------------------------------------------
static InstructionDefinition fnmadd_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fnmadd_d",
	(uint64_t) 0x200004f,
	(uint64_t) 0x600007f,
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

		cp.code() = std::string("//FNMADD_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 122);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5765);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 2ULL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 5716, 5715, 5701, 5699, 5698, 5706, 5704, 5703, 5711, 5709, 5708, 5712, 5714, 5713);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5727, 5723, 5722, 5726, 5724);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 5747, 5746);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 5764, 5748, 5763, 5760, 5754, 5749, 5755, 5758, 5756, 5759, 5761);\n";
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
ss << "fnmadd_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FNMSUB_D --------------------------------------------------------------------
static InstructionDefinition fnmsub_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fnmsub_d",
	(uint64_t) 0x200004b,
	(uint64_t) 0x600007f,
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

		cp.code() = std::string("//FNMSUB_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 123);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5835);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 3ULL, RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(14, 5786, 5785, 5771, 5769, 5768, 5776, 5774, 5773, 5781, 5779, 5778, 5782, 5784, 5783);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5797, 5793, 5792, 5796, 5794);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 5817, 5816);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 5834, 5818, 5833, 5830, 5824, 5819, 5825, 5828, 5826, 5829, 5831);\n";
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
ss << "fnmsub_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FADD_D ----------------------------------------------------------------------
static InstructionDefinition fadd_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fadd_d",
	(uint64_t) 0x2000053,
	(uint64_t) 0xfe00007f,
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

		cp.code() = std::string("//FADD_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 124);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5899);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fadd_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(10, 5850, 5849, 5841, 5839, 5838, 5846, 5844, 5843, 5848, 5847);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5861, 5857, 5856, 5860, 5858);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 5881, 5880);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 5898, 5882, 5897, 5894, 5888, 5883, 5889, 5892, 5890, 5893, 5895);\n";
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
ss << "fadd_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSUB_D ----------------------------------------------------------------------
static InstructionDefinition fsub_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsub_d",
	(uint64_t) 0xa000053,
	(uint64_t) 0xfe00007f,
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

		cp.code() = std::string("//FSUB_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 125);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 5963);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsub_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(10, 5914, 5913, 5905, 5903, 5902, 5910, 5908, 5907, 5912, 5911);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5925, 5921, 5920, 5924, 5922);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 5945, 5944);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 5962, 5946, 5961, 5958, 5952, 5947, 5953, 5956, 5954, 5957, 5959);\n";
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
ss << "fsub_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMUL_D ----------------------------------------------------------------------
static InstructionDefinition fmul_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmul_d",
	(uint64_t) 0x12000053,
	(uint64_t) 0xfe00007f,
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

		cp.code() = std::string("//FMUL_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 126);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6027);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmul_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(10, 5978, 5977, 5969, 5967, 5966, 5974, 5972, 5971, 5976, 5975);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 5989, 5985, 5984, 5988, 5986);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6009, 6008);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6026, 6010, 6025, 6022, 6016, 6011, 6017, 6020, 6018, 6021, 6023);\n";
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
ss << "fmul_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FDIV_D ----------------------------------------------------------------------
static InstructionDefinition fdiv_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fdiv_d",
	(uint64_t) 0x1a000053,
	(uint64_t) 0xfe00007f,
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

		cp.code() = std::string("//FDIV_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 127);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6091);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fdiv_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(10, 6042, 6041, 6033, 6031, 6030, 6038, 6036, 6035, 6040, 6039);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6053, 6049, 6048, 6052, 6050);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6073, 6072);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6090, 6074, 6089, 6086, 6080, 6075, 6081, 6084, 6082, 6085, 6087);\n";
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
ss << "fdiv_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSQRT_D ---------------------------------------------------------------------
static InstructionDefinition fsqrt_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fsqrt_d",
	(uint64_t) 0x5a000053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FSQRT_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 128);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6150);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsqrt_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), RV64IMACFD_get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(7, 6101, 6100, 6097, 6095, 6094, 6099, 6098);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6112, 6108, 6107, 6111, 6109);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6132, 6131);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6149, 6133, 6148, 6145, 6139, 6134, 6140, 6143, 6141, 6144, 6146);\n";
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
ss << "fsqrt_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJ_D ---------------------------------------------------------------------
static InstructionDefinition fsgnj_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnj_d",
	(uint64_t) 0x22000053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FSGNJ_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 129);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6194);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = ((((((*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]) >> (63ULL)) & 0x1ULL)) << 63) | (((*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]) & 0x7fffffffffffffffULL)));\n";
cp.code() += "etiss_coverage_count(12, 6165, 6164, 6157, 6154, 6153, 6155, 6156, 6163, 6160, 6159, 6161, 6162);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6176, 6172, 6171, 6175, 6173);\n";
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
ss << "fsgnj_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJN_D --------------------------------------------------------------------
static InstructionDefinition fsgnjn_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnjn_d",
	(uint64_t) 0x22001053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FSGNJN_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 130);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6239);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = (((~((((*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]) >> (63ULL)) & 0x1ULL))) << 63) | (((*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]) & 0x7fffffffffffffffULL)));\n";
cp.code() += "etiss_coverage_count(13, 6210, 6209, 6202, 6201, 6198, 6197, 6199, 6200, 6208, 6205, 6204, 6206, 6207);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6221, 6217, 6216, 6220, 6218);\n";
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
ss << "fsgnjn_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJX_D --------------------------------------------------------------------
static InstructionDefinition fsgnjx_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnjx_d",
	(uint64_t) 0x22002053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FSGNJX_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 131);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6287);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]) ^ ((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]) & 9223372036854775808ULL);\n";
cp.code() += "etiss_coverage_count(10, 6258, 6257, 6245, 6243, 6242, 6255, 6250, 6248, 6247, 6256);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6269, 6265, 6264, 6268, 6266);\n";
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
ss << "fsgnjx_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMIN_D ----------------------------------------------------------------------
static InstructionDefinition fmin_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmin_d",
	(uint64_t) 0x2a000053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FMIN_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 132);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6350);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsel_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), 0LL);\n";
cp.code() += "etiss_coverage_count(9, 6301, 6300, 6293, 6291, 6290, 6298, 6296, 6295, 6299);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6312, 6308, 6307, 6311, 6309);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6332, 6331);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6349, 6333, 6348, 6345, 6339, 6334, 6340, 6343, 6341, 6344, 6346);\n";
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
ss << "fmin_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMAX_D ----------------------------------------------------------------------
static InstructionDefinition fmax_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmax_d",
	(uint64_t) 0x2a001053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FMAX_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 133);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6413);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsel_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), 1ULL);\n";
cp.code() += "etiss_coverage_count(9, 6364, 6363, 6356, 6354, 6353, 6361, 6359, 6358, 6362);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6375, 6371, 6370, 6374, 6372);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6395, 6394);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6412, 6396, 6411, 6408, 6402, 6397, 6403, 6406, 6404, 6407, 6409);\n";
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
ss << "fmax_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_S_D --------------------------------------------------------------------
static InstructionDefinition fcvt_s_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_s_d",
	(uint64_t) 0x40100053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FCVT_S_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 134);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6437);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fconv_d2f(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(5, 6420, 6419, 6417, 6416, 6418);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)((-4294967296LL + res));\n";
cp.code() += "etiss_coverage_count(7, 6436, 6423, 6422, 6435, 6432, 6431, 6433);\n";
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
ss << "fcvt_s_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_S --------------------------------------------------------------------
static InstructionDefinition fcvt_d_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_s",
	(uint64_t) 0x42000053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FCVT_D_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 135);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6476);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fconv_f2d((etiss_uint32)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 6446, 6445, 6443, 6441, 6440, 6444);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 6458);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6457, 6453, 6452, 6456, 6454);\n";
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
ss << "fcvt_d_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FEQ_D -----------------------------------------------------------------------
static InstructionDefinition feq_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"feq_d",
	(uint64_t) 0xa2002053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FEQ_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 136);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6550);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 6479, 6478);\n";
cp.code() += "res = fcmp_d(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], *((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL], 0LL);\n";
cp.code() += "etiss_coverage_count(8, 6493, 6484, 6492, 6487, 6486, 6490, 6489, 6491);\n";
cp.code() += "etiss_coverage_count(1, 6513);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6519, 6516, 6514, 6517, 6518);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((res));\n";
cp.code() += "etiss_coverage_count(7, 6529, 6524, 6523, 6521, 6528, 6525, 6526);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6532, 6531);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6549, 6533, 6548, 6545, 6539, 6534, 6540, 6543, 6541, 6544, 6546);\n";
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
ss << "feq_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FLT_D -----------------------------------------------------------------------
static InstructionDefinition flt_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"flt_d",
	(uint64_t) 0xa2001053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FLT_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 137);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6624);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 6553, 6552);\n";
cp.code() += "res = fcmp_d(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], *((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL], 2ULL);\n";
cp.code() += "etiss_coverage_count(8, 6567, 6558, 6566, 6561, 6560, 6564, 6563, 6565);\n";
cp.code() += "etiss_coverage_count(1, 6587);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6593, 6590, 6588, 6591, 6592);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((res));\n";
cp.code() += "etiss_coverage_count(7, 6603, 6598, 6597, 6595, 6602, 6599, 6600);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6606, 6605);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6623, 6607, 6622, 6619, 6613, 6608, 6614, 6617, 6615, 6618, 6620);\n";
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
ss << "flt_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FLE_D -----------------------------------------------------------------------
static InstructionDefinition fle_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fle_d",
	(uint64_t) 0xa2000053,
	(uint64_t) 0xfe00707f,
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

		cp.code() = std::string("//FLE_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 138);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6698);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 6627, 6626);\n";
cp.code() += "res = fcmp_d(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], *((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL], 1ULL);\n";
cp.code() += "etiss_coverage_count(8, 6641, 6632, 6640, 6635, 6634, 6638, 6637, 6639);\n";
cp.code() += "etiss_coverage_count(1, 6661);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6667, 6664, 6662, 6665, 6666);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((res));\n";
cp.code() += "etiss_coverage_count(7, 6677, 6672, 6671, 6669, 6676, 6673, 6674);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6680, 6679);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6697, 6681, 6696, 6693, 6687, 6682, 6688, 6691, 6689, 6692, 6694);\n";
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
ss << "fle_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCLASS_D --------------------------------------------------------------------
static InstructionDefinition fclass_d_rd_rs1 (
	ISA32_RV64IMACFD,
	"fclass_d",
	(uint64_t) 0xe2001053,
	(uint64_t) 0xfff0707f,
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

		cp.code() = std::string("//FCLASS_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 139);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6714);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((fclass_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(10, 6713, 6703, 6702, 6700, 6712, 6709, 6708, 6706, 6705, 6710);\n";
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
ss << "fclass_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_W_D --------------------------------------------------------------------
static InstructionDefinition fcvt_w_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_w_d",
	(uint64_t) 0xc2000053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FCVT_W_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 140);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6783);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 6717, 6716);\n";
cp.code() += "res = (etiss_int32)(fcvt_64_32(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], 0LL, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(8, 6731, 6722, 6730, 6728, 6725, 6724, 6726, 6727);\n";
cp.code() += "etiss_coverage_count(1, 6747);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6753, 6750, 6748, 6751, 6752);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 6762, 6758, 6757, 6755, 6761, 6759);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6765, 6764);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6782, 6766, 6781, 6778, 6772, 6767, 6773, 6776, 6774, 6777, 6779);\n";
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
ss << "fcvt_w_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_WU_D -------------------------------------------------------------------
static InstructionDefinition fcvt_wu_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_wu_d",
	(uint64_t) 0xc2100053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FCVT_WU_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 141);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6852);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 6786, 6785);\n";
cp.code() += "res = fcvt_64_32(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], 1ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(7, 6798, 6791, 6797, 6794, 6793, 6795, 6796);\n";
cp.code() += "etiss_coverage_count(1, 6812);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6818, 6815, 6813, 6816, 6817);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(((etiss_uint64)((etiss_int32)(res))));\n";
cp.code() += "etiss_coverage_count(9, 6831, 6823, 6822, 6820, 6830, 6827, 6825, 6824, 6828);\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 6834, 6833);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (etiss_uint64)(((((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL)));\n";
cp.code() += "etiss_coverage_count(11, 6851, 6835, 6850, 6847, 6841, 6836, 6842, 6845, 6843, 6846, 6848);\n";
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
ss << "fcvt_wu_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_W --------------------------------------------------------------------
static InstructionDefinition fcvt_d_w_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_w",
	(uint64_t) 0xd2000053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FCVT_D_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 142);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6895);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)(fcvt_32_64((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 2ULL, " + std::to_string(rm) + "ULL));\n";
cp.code() += "etiss_coverage_count(9, 6866, 6865, 6863, 6860, 6858, 6857, 6855, 6861, 6862);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6877, 6873, 6872, 6876, 6874);\n";
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
ss << "fcvt_d_w" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_WU -------------------------------------------------------------------
static InstructionDefinition fcvt_d_wu_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_wu",
	(uint64_t) 0xd2100053,
	(uint64_t) 0xfff0007f,
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

		cp.code() = std::string("//FCVT_D_WU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 143);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6936);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fcvt_32_64((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 3ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 6907, 6906, 6903, 6901, 6900, 6898, 6904, 6905);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(5, 6918, 6914, 6913, 6917, 6915);\n";
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
ss << "fcvt_d_wu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
