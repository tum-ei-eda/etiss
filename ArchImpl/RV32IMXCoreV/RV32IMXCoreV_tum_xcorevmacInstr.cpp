// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the instruction behavior models of the tum_xcorevmac
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_MAC ----------------------------------------------------------------------
static InstructionDefinition cv_mac_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_mac",
	(uint64_t) 0x9000302b,
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

		cp.code() = std::string("//CV_MAC\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 461);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27169);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 27136);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27142, 27139, 27137, 27140, 27141);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27168);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = RV32IMXCoreV_cv_mac((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]), (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(17, 27167, 27147, 27146, 27144, 27166, 27153, 27152, 27151, 27149, 27159, 27158, 27157, 27155, 27165, 27164, 27163, 27161);\n";
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
ss << "cv_mac" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MSU ----------------------------------------------------------------------
static InstructionDefinition cv_msu_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_msu",
	(uint64_t) 0x9200302b,
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

		cp.code() = std::string("//CV_MSU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 462);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27203);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 27170);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27176, 27173, 27171, 27174, 27175);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27202);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = RV32IMXCoreV_cv_msu((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]), (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(17, 27201, 27181, 27180, 27178, 27200, 27187, 27186, 27185, 27183, 27193, 27192, 27191, 27189, 27199, 27198, 27197, 27195);\n";
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
ss << "cv_msu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
