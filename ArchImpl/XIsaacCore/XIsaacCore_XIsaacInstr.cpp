/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the instruction behavior models of the XIsaac
 * instruction set for the XIsaacCore core architecture.
 */

#include "XIsaacCoreArch.h"
#include "XIsaacCoreFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// CUSTOM0 ---------------------------------------------------------------------
static InstructionDefinition custom0_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"custom0",
	(uint32_t) 0x00007b,
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

		cp.code() = std::string("//CUSTOM0\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 185);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6963);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 rs1_val = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 6922, 6921, 6920);\n";
cp.code() += "etiss_uint32 rs2_val = *((XIsaacCore*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 6927, 6926, 6925);\n";
cp.code() += "etiss_uint32 outp0 = (etiss_uint32)(((((etiss_int32)(((etiss_uint32)(((((etiss_int32)((rs1_val)) + (etiss_int32)((rs2_val)))))))) + 1LL))));\n";
cp.code() += "etiss_coverage_count(20, 6957, 6956, 6951, 6945, 6942, 6937, 6932, 6929, 6930, 6936, 6933, 6934, 6938, 6939, 6940, 6943, 6946, 6952, 6953, 6954);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd) + "ULL] = outp0;\n";
cp.code() += "etiss_coverage_count(4, 6962, 6960, 6959, 6961);\n";
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
ss << "custom0" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CUSTOM1 ---------------------------------------------------------------------
static InstructionDefinition custom1_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"custom1",
	(uint32_t) 0x200007b,
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

		cp.code() = std::string("//CUSTOM1\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 186);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7009);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 rs2_val = *((XIsaacCore*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 6968, 6967, 6966);\n";
cp.code() += "etiss_uint32 rs1_val = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 6973, 6972, 6971);\n";
cp.code() += "etiss_uint32 outp0 = (etiss_uint32)(((((etiss_int32)((rs1_val)) + (etiss_int32)(((etiss_uint32)(((((etiss_uint32)((rs2_val)) & 127ULL))))))))));\n";
cp.code() += "etiss_coverage_count(20, 7003, 7002, 6997, 6978, 6975, 6976, 6996, 6993, 6988, 6982, 6979, 6980, 6983, 6989, 6990, 6991, 6994, 6998, 6999, 7000);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd) + "ULL] = outp0;\n";
cp.code() += "etiss_coverage_count(4, 7008, 7006, 7005, 7007);\n";
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
ss << "custom1" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
