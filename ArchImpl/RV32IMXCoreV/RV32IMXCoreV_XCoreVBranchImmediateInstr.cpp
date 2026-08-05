// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the instruction behavior models of the XCoreVBranchImmediate
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_BEQIMM -------------------------------------------------------------------
static InstructionDefinition cv_beqimm_imm_rs1_simm5 (
	ISA32_RV32IMXCoreV,
	"cv_beqimm",
	(uint64_t) 0x00600b,
	(uint64_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(24, 20);
simm5 += R_simm5_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BEQIMM\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 415);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25703);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25673);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(((etiss_int32)(((etiss_int32)((etiss_int8)(((etiss_int8)simm5) << (3)) >> (3))) << (0)) >> (0))) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(8, 25686, 25680, 25678, 25677, 25675, 25685, 25683, 25681);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25702);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25687);\n";
if (imm % 4ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 25690, 25688);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25694);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(3, 25693, 25691, 25692);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 25701);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25700, 25695, 25699, 25696, 25698, 25697);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
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

		cp.code() = std::string("//CV_BEQIMM\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(24, 20);
simm5 += R_simm5_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_beqimm" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | simm5=" + std::to_string(simm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_BNEIMM -------------------------------------------------------------------
static InstructionDefinition cv_bneimm_imm_rs1_simm5 (
	ISA32_RV32IMXCoreV,
	"cv_bneimm",
	(uint64_t) 0x00700b,
	(uint64_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(24, 20);
simm5 += R_simm5_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BNEIMM\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 416);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25734);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25704);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) != " + std::to_string(((etiss_int32)(((etiss_int32)((etiss_int8)(((etiss_int8)simm5) << (3)) >> (3))) << (0)) >> (0))) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(8, 25717, 25711, 25709, 25708, 25706, 25716, 25714, 25712);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25733);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25718);\n";
if (imm % 4ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 25721, 25719);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25725);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(3, 25724, 25722, 25723);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 25732);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25731, 25726, 25730, 25727, 25729, 25728);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
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

		cp.code() = std::string("//CV_BNEIMM\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(24, 20);
simm5 += R_simm5_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_bneimm" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | simm5=" + std::to_string(simm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
