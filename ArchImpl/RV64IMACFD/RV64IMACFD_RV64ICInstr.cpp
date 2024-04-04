/**
 * Generated on Thu, 04 Apr 2024 12:50:47 +0200.
 *
 * This file contains the instruction behavior models of the RV64IC
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// CADDIW ----------------------------------------------------------------------
static InstructionDefinition caddiw_imm_rs1 (
	ISA16_RV64IMACFD,
	"caddiw",
	(uint16_t) 0x2001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CADDIW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 206);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 7412);\n";
if ((rs1 % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 7409, 7407, 7410, 7411, 7430);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] = (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) + " + std::to_string(((etiss_int8)(((etiss_int8)imm) << (2)) >> (2))) + "LL;\n";
cp.code() += "etiss_coverage_count(11, 7429, 7417, 7416, 7414, 7428, 7424, 7422, 7421, 7419, 7427, 7425);\n";
} // conditional
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
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "caddiw" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRLI -----------------------------------------------------------------------
static InstructionDefinition csrli_nzuimm_rs1 (
	ISA16_RV64IMACFD,
	"csrli",
	(uint16_t) 0x8001,
	(uint16_t) 0xec03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 nzuimm = 0;
static BitArrayRange R_nzuimm_0(6, 2);
nzuimm += R_nzuimm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_nzuimm_5(12, 12);
nzuimm += R_nzuimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 199);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7444);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] >> " + std::to_string(nzuimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(11, 7443, 7435, 7434, 7432, 7433, 7442, 7440, 7439, 7437, 7438, 7441);\n";
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
etiss_uint8 nzuimm = 0;
static BitArrayRange R_nzuimm_0(6, 2);
nzuimm += R_nzuimm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_nzuimm_5(12, 12);
nzuimm += R_nzuimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrli" << " # " << ba << (" [nzuimm=" + std::to_string(nzuimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRAI -----------------------------------------------------------------------
static InstructionDefinition csrai_shamt_rs1 (
	ISA16_RV64IMACFD,
	"csrai",
	(uint16_t) 0x8401,
	(uint16_t) 0xec03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_shamt_5(12, 12);
shamt += R_shamt_5.read(ba) << 5;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRAI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 200);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7461);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] = ((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL])) >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(13, 7460, 7449, 7448, 7446, 7447, 7459, 7456, 7454, 7453, 7451, 7452, 7457, 7458);\n";
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_shamt_5(12, 12);
shamt += R_shamt_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrai" << " # " << ba << (" [shamt=" + std::to_string(shamt) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSLLI -----------------------------------------------------------------------
static InstructionDefinition cslli_shamt_rs1 (
	ISA16_RV64IMACFD,
	"cslli",
	(uint16_t) 0x02,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_shamt_5(12, 12);
shamt += R_shamt_5.read(ba) << 5;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSLLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 201);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7478);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7464);\n";
if (rs1 == 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7462, 7463, 7468);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 7467, 7465);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
} // conditional
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1) + "ULL] << " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 7477, 7471, 7470, 7476, 7474, 7473, 7475);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CSLLI\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_shamt_5(12, 12);
shamt += R_shamt_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cslli" << " # " << ba << (" [shamt=" + std::to_string(shamt) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CLD -------------------------------------------------------------------------
static InstructionDefinition cld_rd_uimm_rs1 (
	ISA16_RV64IMACFD,
	"cld",
	(uint16_t) 0x6000,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(6, 5);
uimm += R_uimm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CLD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 202);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7499);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 7487, 7486, 7484, 7483, 7481, 7482, 7485);\n";
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
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = (etiss_int64)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(8, 7498, 7492, 7491, 7489, 7490, 7497, 7495, 7494);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CLD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(6, 5);
uimm += R_uimm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cld" << " # " << ba << (" [rd=" + std::to_string(rd) + " | uimm=" + std::to_string(uimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSD -------------------------------------------------------------------------
static InstructionDefinition csd_rs2_uimm_rs1 (
	ISA16_RV64IMACFD,
	"csd",
	(uint16_t) 0xe000,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(6, 5);
uimm += R_uimm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 203);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7520);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 7508, 7507, 7505, 7504, 7502, 7503, 7506);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 7519, 7511, 7510, 7518, 7516, 7515, 7513, 7514);\n";
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

		cp.code() = std::string("//CSD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(6, 5);
uimm += R_uimm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csd" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | uimm=" + std::to_string(uimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSUBW -----------------------------------------------------------------------
static InstructionDefinition csubw_rs2_rd (
	ISA16_RV64IMACFD,
	"csubw",
	(uint16_t) 0x9c01,
	(uint16_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSUBW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 204);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7548);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL]) - (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(12, 7537, 7536, 7528, 7526, 7525, 7523, 7524, 7535, 7533, 7532, 7530, 7531);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = (etiss_uint64)((etiss_int32)(res));\n";
cp.code() += "etiss_coverage_count(8, 7547, 7542, 7541, 7539, 7540, 7546, 7544, 7543);\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csubw" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CADDW -----------------------------------------------------------------------
static InstructionDefinition caddw_rs2_rd (
	ISA16_RV64IMACFD,
	"caddw",
	(uint16_t) 0x9c21,
	(uint16_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CADDW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 205);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7576);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL]) + (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(12, 7565, 7564, 7556, 7554, 7553, 7551, 7552, 7563, 7561, 7560, 7558, 7559);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = (etiss_uint64)((etiss_int32)(res));\n";
cp.code() += "etiss_coverage_count(8, 7575, 7570, 7569, 7567, 7568, 7574, 7572, 7571);\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "caddw" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CLDSP -----------------------------------------------------------------------
static InstructionDefinition cldsp_uimm_rd (
	ISA16_RV64IMACFD,
	"cldsp",
	(uint16_t) 0x6002,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint16 uimm = 0;
static BitArrayRange R_uimm_6(4, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_3(6, 5);
uimm += R_uimm_3.read(ba) << 3;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CLDSP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 207);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7603);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[2ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 7583, 7582, 7580, 7579, 7581);\n";
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
cp.code() += "etiss_int64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 7588, 7587, 7586);\n";
cp.code() += "etiss_coverage_count(1, 7591);\n";
if (rd % 32ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 7589, 7602);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 7598, 7596, 7595, 7593, 7597);\n";
} // conditional
else { // conditional
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 7601, 7599, 7600);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CLDSP\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 uimm = 0;
static BitArrayRange R_uimm_6(4, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_3(6, 5);
uimm += R_uimm_3.read(ba) << 3;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cldsp" << " # " << ba << (" [uimm=" + std::to_string(uimm) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSDSP -----------------------------------------------------------------------
static InstructionDefinition csdsp_rs2_uimm (
	ISA16_RV64IMACFD,
	"csdsp",
	(uint16_t) 0xe002,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint16 uimm = 0;
static BitArrayRange R_uimm_6(9, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSDSP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 208);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 2) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7622);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[2ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 7610, 7609, 7607, 7606, 7608);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 7621, 7613, 7612, 7620, 7618, 7617, 7615);\n";
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

		cp.code() = std::string("//CSDSP\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint16 uimm = 0;
static BitArrayRange R_uimm_6(9, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csdsp" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | uimm=" + std::to_string(uimm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
