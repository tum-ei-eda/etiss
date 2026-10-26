// clang-format off
/**
 * Generated on Mon, 26 Oct 2026 08:39:20 +0000.
 *
 * This file contains the instruction behavior models of the RV64I
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// LWU -------------------------------------------------------------------------
static InstructionDefinition lwu_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"lwu",
	(uint64_t) 0x006003,
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

		cp.code() = std::string("//LWU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 184);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8311);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = (etiss_uint64)((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL));\n";
cp.code() += "etiss_coverage_count(9, 8284, 8283, 8280, 8276, 8275, 8273, 8279, 8277, 8281);\n";
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
cp.code() += "etiss_coverage_count(6, 8294, 8293, 8291, 8289, 8287, 8288);\n";
cp.code() += "etiss_coverage_count(1, 8295);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8301, 8298, 8296, 8299, 8300);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 8310, 8306, 8305, 8303, 8309, 8307);\n";
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

		cp.code() = std::string("//LWU\n");

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
ss << "lwu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// LD --------------------------------------------------------------------------
static InstructionDefinition ld_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"ld",
	(uint64_t) 0x003003,
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

		cp.code() = std::string("//LD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 185);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8351);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = (etiss_uint64)((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL));\n";
cp.code() += "etiss_coverage_count(9, 8324, 8323, 8320, 8317, 8316, 8314, 8319, 8318, 8321);\n";
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
cp.code() += "etiss_int64 res = (etiss_int64)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 8334, 8333, 8331, 8329, 8327, 8328);\n";
cp.code() += "etiss_coverage_count(1, 8335);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8341, 8338, 8336, 8339, 8340);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 8350, 8346, 8345, 8343, 8349, 8347);\n";
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

		cp.code() = std::string("//LD\n");

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
ss << "ld" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SD --------------------------------------------------------------------------
static InstructionDefinition sd_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sd",
	(uint64_t) 0x003023,
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

		cp.code() = std::string("//SD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 186);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8379);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = (etiss_uint64)((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL));\n";
cp.code() += "etiss_coverage_count(9, 8364, 8363, 8360, 8357, 8356, 8354, 8359, 8358, 8361);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(9, 8378, 8370, 8368, 8366, 8367, 8377, 8375, 8374, 8372);\n";
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

		cp.code() = std::string("//SD\n");

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
ss << "sd" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLLI ------------------------------------------------------------------------
static InstructionDefinition slli_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"slli",
	(uint64_t) 0x001013,
	(uint64_t) 0xfc00707f,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(25, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 187);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 8380);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8386, 8383, 8381, 8384, 8385);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] << " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 8399, 8391, 8390, 8388, 8398, 8396, 8395, 8393, 8397);\n";
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
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(25, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "slli" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRLI ------------------------------------------------------------------------
static InstructionDefinition srli_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"srli",
	(uint64_t) 0x005013,
	(uint64_t) 0xfc00707f,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(25, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 188);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 8400);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8406, 8403, 8401, 8404, 8405);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 8419, 8411, 8410, 8408, 8418, 8416, 8415, 8413, 8417);\n";
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
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(25, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "srli" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRAI ------------------------------------------------------------------------
static InstructionDefinition srai_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"srai",
	(uint64_t) 0x40005013,
	(uint64_t) 0xfc00707f,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(25, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRAI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 189);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 8420);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8426, 8423, 8421, 8424, 8425);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) >> " + std::to_string(shamt) + "ULL));\n";
cp.code() += "etiss_coverage_count(13, 8444, 8431, 8430, 8428, 8443, 8440, 8437, 8436, 8435, 8433, 8438, 8439, 8441);\n";
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
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(25, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "srai" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ADDIW -----------------------------------------------------------------------
static InstructionDefinition addiw_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"addiw",
	(uint64_t) 0x00001b,
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

		cp.code() = std::string("//ADDIW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 190);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8477);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8445);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8451, 8448, 8446, 8449, 8450);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8476);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = (etiss_int32)((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL));\n";
cp.code() += "etiss_coverage_count(9, 8464, 8463, 8460, 8457, 8456, 8454, 8459, 8458, 8461);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int64)(res));\n";
cp.code() += "etiss_coverage_count(7, 8475, 8469, 8468, 8466, 8474, 8472, 8470);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "addiw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLLIW -----------------------------------------------------------------------
static InstructionDefinition slliw_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"slliw",
	(uint64_t) 0x00101b,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLLIW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 191);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8508);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8478);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8484, 8481, 8479, 8482, 8483);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8507);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 sh_val = ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) << " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 8496, 8495, 8492, 8490, 8489, 8487, 8493, 8494);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(sh_val));\n";
cp.code() += "etiss_coverage_count(7, 8506, 8501, 8500, 8498, 8505, 8503, 8502);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "slliw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRLIW -----------------------------------------------------------------------
static InstructionDefinition srliw_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"srliw",
	(uint64_t) 0x00501b,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRLIW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 192);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8539);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8509);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8515, 8512, 8510, 8513, 8514);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8538);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 sh_val = ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 8527, 8526, 8523, 8521, 8520, 8518, 8524, 8525);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(sh_val));\n";
cp.code() += "etiss_coverage_count(7, 8537, 8532, 8531, 8529, 8536, 8534, 8533);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "srliw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRAIW -----------------------------------------------------------------------
static InstructionDefinition sraiw_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"sraiw",
	(uint64_t) 0x4000501b,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRAIW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 193);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8569);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8540);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8546, 8543, 8541, 8544, 8545);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8568);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 sh_val = ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 8558, 8557, 8554, 8552, 8551, 8549, 8555, 8556);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(sh_val);\n";
cp.code() += "etiss_coverage_count(6, 8567, 8563, 8562, 8560, 8566, 8564);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sraiw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ADDW ------------------------------------------------------------------------
static InstructionDefinition addw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"addw",
	(uint64_t) 0x00003b,
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

		cp.code() = std::string("//ADDW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 194);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8607);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8570);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8576, 8573, 8571, 8574, 8575);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8606);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = (etiss_int32)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) + (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(12, 8596, 8595, 8592, 8584, 8582, 8581, 8579, 8591, 8589, 8588, 8586, 8593);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 8605, 8601, 8600, 8598, 8604, 8602);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "addw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SUBW ------------------------------------------------------------------------
static InstructionDefinition subw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"subw",
	(uint64_t) 0x4000003b,
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

		cp.code() = std::string("//SUBW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 195);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8645);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8608);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8614, 8611, 8609, 8612, 8613);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8644);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = (etiss_int32)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) - (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(12, 8634, 8633, 8630, 8622, 8620, 8619, 8617, 8629, 8627, 8626, 8624, 8631);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 8643, 8639, 8638, 8636, 8642, 8640);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "subw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLLW ------------------------------------------------------------------------
static InstructionDefinition sllw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sllw",
	(uint64_t) 0x00103b,
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

		cp.code() = std::string("//SLLW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 196);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8689);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8646);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8652, 8649, 8647, 8650, 8651);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8688);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 count = (etiss_uint32)(((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) & 31ULL));\n";
cp.code() += "etiss_coverage_count(9, 8665, 8664, 8661, 8659, 8658, 8657, 8655, 8660, 8662);\n";
cp.code() += "etiss_uint32 sh_val = ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) << count;\n";
cp.code() += "etiss_coverage_count(8, 8677, 8676, 8673, 8671, 8670, 8668, 8674, 8675);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(sh_val));\n";
cp.code() += "etiss_coverage_count(7, 8687, 8682, 8681, 8679, 8686, 8684, 8683);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sllw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRLW ------------------------------------------------------------------------
static InstructionDefinition srlw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"srlw",
	(uint64_t) 0x00503b,
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

		cp.code() = std::string("//SRLW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 197);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8733);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8690);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8696, 8693, 8691, 8694, 8695);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8732);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 count = (etiss_uint32)(((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) & 31ULL));\n";
cp.code() += "etiss_coverage_count(9, 8709, 8708, 8705, 8703, 8702, 8701, 8699, 8704, 8706);\n";
cp.code() += "etiss_uint32 sh_val = ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) >> count;\n";
cp.code() += "etiss_coverage_count(8, 8721, 8720, 8717, 8715, 8714, 8712, 8718, 8719);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(sh_val));\n";
cp.code() += "etiss_coverage_count(7, 8731, 8726, 8725, 8723, 8730, 8728, 8727);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "srlw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRAW ------------------------------------------------------------------------
static InstructionDefinition sraw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sraw",
	(uint64_t) 0x4000503b,
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

		cp.code() = std::string("//SRAW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 198);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8776);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8734);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8740, 8737, 8735, 8738, 8739);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8775);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 count = (etiss_uint32)(((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) & 31ULL));\n";
cp.code() += "etiss_coverage_count(9, 8753, 8752, 8749, 8747, 8746, 8745, 8743, 8748, 8750);\n";
cp.code() += "etiss_int32 sh_val = ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) >> count;\n";
cp.code() += "etiss_coverage_count(8, 8765, 8764, 8761, 8759, 8758, 8756, 8762, 8763);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(sh_val);\n";
cp.code() += "etiss_coverage_count(6, 8774, 8770, 8769, 8767, 8773, 8771);\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sraw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
