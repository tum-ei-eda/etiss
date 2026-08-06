// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
 *
 * This file contains the instruction behavior models of the XCoreVSimd
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_ADD_H --------------------------------------------------------------------
static InstructionDefinition cv_add_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_h",
	(uint64_t) 0x00007b,
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

		cp.code() = std::string("//CV_ADD_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 149);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6690);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6637);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 6640, 6638, 6639);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 6689);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 6664);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 6688);\n";
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
ss << "cv_add_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_add_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_sc_h",
	(uint64_t) 0x00407b,
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

		cp.code() = std::string("//CV_ADD_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 150);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6744);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6691);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 6694, 6692, 6693);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 6743);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 6718);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 6742);\n";
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
ss << "cv_add_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_add_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_add_sci_h",
	(uint64_t) 0x00607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ADD_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 151);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6798);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6745);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 6748, 6746, 6747);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 6797);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 6772);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 6796);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_add_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_B --------------------------------------------------------------------
static InstructionDefinition cv_add_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_b",
	(uint64_t) 0x00107b,
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

		cp.code() = std::string("//CV_ADD_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 152);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6900);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6799);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 6802, 6800, 6801);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 6899);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 6826);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 6850);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 6874);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 6898);\n";
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
ss << "cv_add_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_add_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_sc_b",
	(uint64_t) 0x00507b,
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

		cp.code() = std::string("//CV_ADD_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 153);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7002);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6901);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 6904, 6902, 6903);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7001);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 6928);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 6952);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 6976);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7000);\n";
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
ss << "cv_add_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_add_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_add_sci_b",
	(uint64_t) 0x00707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ADD_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 154);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7104);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7003);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7006, 7004, 7005);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7103);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 7030);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 7054);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 7078);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7102);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_add_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_H --------------------------------------------------------------------
static InstructionDefinition cv_sub_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_h",
	(uint64_t) 0x800007b,
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

		cp.code() = std::string("//CV_SUB_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 155);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7158);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7105);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7108, 7106, 7107);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7157);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 7132);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 7156);\n";
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
ss << "cv_sub_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_sub_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_sc_h",
	(uint64_t) 0x800407b,
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

		cp.code() = std::string("//CV_SUB_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 156);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7212);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7159);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7162, 7160, 7161);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7211);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 7186);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 7210);\n";
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
ss << "cv_sub_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_sub_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sub_sci_h",
	(uint64_t) 0x800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SUB_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 157);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7266);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7213);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7216, 7214, 7215);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7265);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) - " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 7240);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) - " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 7264);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sub_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_B --------------------------------------------------------------------
static InstructionDefinition cv_sub_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_b",
	(uint64_t) 0x800107b,
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

		cp.code() = std::string("//CV_SUB_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 158);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7368);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7267);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7270, 7268, 7269);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7367);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 7294);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 7318);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 7342);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7366);\n";
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
ss << "cv_sub_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_sub_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_sc_b",
	(uint64_t) 0x800507b,
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

		cp.code() = std::string("//CV_SUB_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 159);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7470);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7369);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7372, 7370, 7371);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7469);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 7396);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 7420);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 7444);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7468);\n";
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
ss << "cv_sub_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_sub_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sub_sci_b",
	(uint64_t) 0x800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SUB_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 160);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7572);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7471);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7474, 7472, 7473);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7571);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) - " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 7498);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) - " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 7522);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) - " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 7546);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) - " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7570);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sub_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVG_H --------------------------------------------------------------------
static InstructionDefinition cv_avg_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avg_h",
	(uint64_t) 0x1000007b,
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

		cp.code() = std::string("//CV_AVG_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 161);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7634);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7573);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7576, 7574, 7575);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7633);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 7604);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 7632);\n";
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
ss << "cv_avg_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVG_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_avg_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avg_sc_h",
	(uint64_t) 0x1000407b,
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

		cp.code() = std::string("//CV_AVG_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 162);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7696);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7635);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7638, 7636, 7637);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7695);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 7666);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 7694);\n";
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
ss << "cv_avg_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVG_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_avg_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_avg_sci_h",
	(uint64_t) 0x1000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_AVG_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 163);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7758);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7697);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7700, 7698, 7699);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7757);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 7728);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 7756);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_avg_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVG_B --------------------------------------------------------------------
static InstructionDefinition cv_avg_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avg_b",
	(uint64_t) 0x1000107b,
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

		cp.code() = std::string("//CV_AVG_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 164);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7876);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7759);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7762, 7760, 7761);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7875);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 7790);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) >> 1ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 7818);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) >> 1ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 7846);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) >> 1ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7874);\n";
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
ss << "cv_avg_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVG_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_avg_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avg_sc_b",
	(uint64_t) 0x1000507b,
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

		cp.code() = std::string("//CV_AVG_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 165);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7994);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7877);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7880, 7878, 7879);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7993);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 7908);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 7936);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 7964);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 7992);\n";
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
ss << "cv_avg_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVG_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_avg_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_avg_sci_b",
	(uint64_t) 0x1000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_AVG_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 166);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8112);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7995);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 7998, 7996, 7997);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8111);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) >> 1ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 8026);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) >> 1ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 8054);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) >> 1ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 8082);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) >> 1ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 8110);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_avg_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVGU_H -------------------------------------------------------------------
static InstructionDefinition cv_avgu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avgu_h",
	(uint64_t) 0x1800007b,
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

		cp.code() = std::string("//CV_AVGU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 167);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8174);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8113);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8116, 8114, 8115);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8173);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 8144);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 8172);\n";
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
ss << "cv_avgu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVGU_SC_H ----------------------------------------------------------------
static InstructionDefinition cv_avgu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avgu_sc_h",
	(uint64_t) 0x1800407b,
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

		cp.code() = std::string("//CV_AVGU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 168);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8236);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8175);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8178, 8176, 8177);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8235);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 8206);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 8234);\n";
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
ss << "cv_avgu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVGU_SCI_H ---------------------------------------------------------------
static InstructionDefinition cv_avgu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_avgu_sci_h",
	(uint64_t) 0x1800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_AVGU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 169);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8294);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8237);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8240, 8238, 8239);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8293);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + " + std::to_string(((etiss_uint16)(Imm6))) + "ULL)) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 8266);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + " + std::to_string(((etiss_uint16)(Imm6))) + "ULL)) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 8292);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_avgu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVGU_B -------------------------------------------------------------------
static InstructionDefinition cv_avgu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avgu_b",
	(uint64_t) 0x1800107b,
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

		cp.code() = std::string("//CV_AVGU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 170);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8412);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8295);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8298, 8296, 8297);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8411);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 8326);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) >> 1ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 8354);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) >> 1ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 8382);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) >> 1ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 8410);\n";
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
ss << "cv_avgu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVGU_SC_B ----------------------------------------------------------------
static InstructionDefinition cv_avgu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_avgu_sc_b",
	(uint64_t) 0x1800507b,
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

		cp.code() = std::string("//CV_AVGU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 171);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8530);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8413);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8416, 8414, 8415);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8529);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 8444);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 8472);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 8500);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) >> 1ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 8528);\n";
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
ss << "cv_avgu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AVGU_SCI_B ---------------------------------------------------------------
static InstructionDefinition cv_avgu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_avgu_sci_b",
	(uint64_t) 0x1800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_AVGU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 172);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8640);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8531);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8534, 8532, 8533);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8639);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) + " + std::to_string(((etiss_uint8)(Imm6))) + "ULL)) >> 1ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 8560);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)(Imm6))) + "ULL)) >> 1ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 8586);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)(Imm6))) + "ULL)) >> 1ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 8612);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((etiss_uint8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) + " + std::to_string(((etiss_uint8)(Imm6))) + "ULL)) >> 1ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 8638);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_avgu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN_H --------------------------------------------------------------------
static InstructionDefinition cv_min_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_min_h",
	(uint64_t) 0x2000007b,
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

		cp.code() = std::string("//CV_MIN_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 173);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8718);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8641);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8644, 8642, 8643);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8717);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 8680);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 8716);\n";
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
ss << "cv_min_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_min_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_min_sc_h",
	(uint64_t) 0x2000407b,
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

		cp.code() = std::string("//CV_MIN_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 174);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8796);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8719);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8722, 8720, 8721);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8795);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 8758);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 8794);\n";
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
ss << "cv_min_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_min_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_min_sci_h",
	(uint64_t) 0x2000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MIN_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 175);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8874);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8797);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8800, 8798, 8799);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8873);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 8836);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 8872);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_min_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN_B --------------------------------------------------------------------
static InstructionDefinition cv_min_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_min_b",
	(uint64_t) 0x2000107b,
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

		cp.code() = std::string("//CV_MIN_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 176);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9024);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8875);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 8878, 8876, 8877);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9023);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 8914);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 8950);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 8986);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 9022);\n";
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
ss << "cv_min_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_min_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_min_sc_b",
	(uint64_t) 0x2000507b,
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

		cp.code() = std::string("//CV_MIN_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 177);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9174);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9025);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9028, 9026, 9027);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9173);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 9064);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 9100);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 9136);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 9172);\n";
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
ss << "cv_min_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_min_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_min_sci_b",
	(uint64_t) 0x2000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MIN_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 178);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9324);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9175);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9178, 9176, 9177);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9323);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 9214);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 9250);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 9286);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 9322);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_min_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU_H -------------------------------------------------------------------
static InstructionDefinition cv_minu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_minu_h",
	(uint64_t) 0x2800007b,
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

		cp.code() = std::string("//CV_MINU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 179);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9402);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9325);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9328, 9326, 9327);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9401);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 9364);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 9400);\n";
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
ss << "cv_minu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU_SC_H ----------------------------------------------------------------
static InstructionDefinition cv_minu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_minu_sc_h",
	(uint64_t) 0x2800407b,
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

		cp.code() = std::string("//CV_MINU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 180);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9480);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9403);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9406, 9404, 9405);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9479);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 9442);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 9478);\n";
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
ss << "cv_minu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU_SCI_H ---------------------------------------------------------------
static InstructionDefinition cv_minu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_minu_sci_h",
	(uint64_t) 0x2800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MINU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 181);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9550);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9481);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9484, 9482, 9483);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9549);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)(Imm6))) + "ULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 9516);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)(Imm6))) + "ULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 9548);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_minu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU_B -------------------------------------------------------------------
static InstructionDefinition cv_minu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_minu_b",
	(uint64_t) 0x2800107b,
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

		cp.code() = std::string("//CV_MINU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 182);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9700);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9551);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9554, 9552, 9553);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9699);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 9590);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 9626);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 9662);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 9698);\n";
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
ss << "cv_minu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU_SC_B ----------------------------------------------------------------
static InstructionDefinition cv_minu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_minu_sc_b",
	(uint64_t) 0x2800507b,
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

		cp.code() = std::string("//CV_MINU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 183);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9850);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9701);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9704, 9702, 9703);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9849);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 9740);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 9776);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 9812);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 9848);\n";
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
ss << "cv_minu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU_SCI_B ---------------------------------------------------------------
static InstructionDefinition cv_minu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_minu_sci_b",
	(uint64_t) 0x2800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MINU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 184);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9984);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9851);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9854, 9852, 9853);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9983);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 9886);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 9918);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 9950);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 9982);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_minu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX_H --------------------------------------------------------------------
static InstructionDefinition cv_max_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_max_h",
	(uint64_t) 0x3000007b,
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

		cp.code() = std::string("//CV_MAX_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 185);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10062);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9985);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 9988, 9986, 9987);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10061);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 10024);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 10060);\n";
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
ss << "cv_max_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_max_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_max_sc_h",
	(uint64_t) 0x3000407b,
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

		cp.code() = std::string("//CV_MAX_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 186);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10140);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10063);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10066, 10064, 10065);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10139);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 10102);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 10138);\n";
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
ss << "cv_max_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_max_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_max_sci_h",
	(uint64_t) 0x3000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MAX_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 187);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10218);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10141);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10144, 10142, 10143);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10217);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 10180);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 10216);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_max_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX_B --------------------------------------------------------------------
static InstructionDefinition cv_max_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_max_b",
	(uint64_t) 0x3000107b,
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

		cp.code() = std::string("//CV_MAX_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 188);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10368);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10219);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10222, 10220, 10221);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10367);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 10258);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 10294);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 10330);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 10366);\n";
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
ss << "cv_max_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_max_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_max_sc_b",
	(uint64_t) 0x3000507b,
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

		cp.code() = std::string("//CV_MAX_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 189);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10518);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10369);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10372, 10370, 10371);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10517);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 10408);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 10444);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 10480);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 10516);\n";
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
ss << "cv_max_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_max_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_max_sci_b",
	(uint64_t) 0x3000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MAX_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 190);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10668);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10519);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10522, 10520, 10521);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10667);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 10558);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 10594);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 10630);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 10666);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_max_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU_H -------------------------------------------------------------------
static InstructionDefinition cv_maxu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_maxu_h",
	(uint64_t) 0x3800007b,
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

		cp.code() = std::string("//CV_MAXU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 191);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10746);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10669);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10672, 10670, 10671);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10745);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 10708);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 10744);\n";
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
ss << "cv_maxu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU_SC_H ----------------------------------------------------------------
static InstructionDefinition cv_maxu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_maxu_sc_h",
	(uint64_t) 0x3800407b,
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

		cp.code() = std::string("//CV_MAXU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 192);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10824);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10747);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10750, 10748, 10749);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10823);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 10786);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 10822);\n";
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
ss << "cv_maxu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU_SCI_H ---------------------------------------------------------------
static InstructionDefinition cv_maxu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_maxu_sci_h",
	(uint64_t) 0x3800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MAXU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 193);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 10894);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10825);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10828, 10826, 10827);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 10893);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)(Imm6))) + "ULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 10860);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) : (" + std::to_string(((etiss_uint16)(Imm6))) + "ULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 10892);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_maxu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU_B -------------------------------------------------------------------
static InstructionDefinition cv_maxu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_maxu_b",
	(uint64_t) 0x3800107b,
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

		cp.code() = std::string("//CV_MAXU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 194);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11044);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 10895);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 10898, 10896, 10897);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11043);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 10934);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 10970);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11006);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11042);\n";
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
ss << "cv_maxu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU_SC_B ----------------------------------------------------------------
static InstructionDefinition cv_maxu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_maxu_sc_b",
	(uint64_t) 0x3800507b,
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

		cp.code() = std::string("//CV_MAXU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 195);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11194);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11045);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11048, 11046, 11047);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11193);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 11084);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 11120);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11156);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11192);\n";
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
ss << "cv_maxu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU_SCI_B ---------------------------------------------------------------
static InstructionDefinition cv_maxu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_maxu_sci_b",
	(uint64_t) 0x3800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MAXU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 196);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11328);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11195);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11198, 11196, 11197);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11327);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 11230);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 11262);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11294);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)) ? ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) : (" + std::to_string(((etiss_uint8)(Imm6))) + "ULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11326);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_maxu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRL_H --------------------------------------------------------------------
static InstructionDefinition cv_srl_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_srl_h",
	(uint64_t) 0x4000007b,
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

		cp.code() = std::string("//CV_SRL_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 197);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11378);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11329);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11332, 11330, 11331);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11377);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 11354);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 11376);\n";
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
ss << "cv_srl_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRL_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_srl_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_srl_sc_h",
	(uint64_t) 0x4000407b,
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

		cp.code() = std::string("//CV_SRL_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 198);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11428);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11379);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11382, 11380, 11381);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11427);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 11404);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 11426);\n";
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
ss << "cv_srl_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRL_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_srl_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_srl_sci_h",
	(uint64_t) 0x4000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SRL_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 199);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11474);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11429);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11432, 11430, 11431);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11473);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >> " + std::to_string((((etiss_uint16)(Imm6)))) + "ULL << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 11452);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >> " + std::to_string((((etiss_uint16)(Imm6)))) + "ULL << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 11472);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_srl_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRL_B --------------------------------------------------------------------
static InstructionDefinition cv_srl_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_srl_b",
	(uint64_t) 0x4000107b,
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

		cp.code() = std::string("//CV_SRL_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 200);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11568);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11475);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11478, 11476, 11477);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11567);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 11500);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 11522);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11544);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11566);\n";
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
ss << "cv_srl_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRL_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_srl_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_srl_sc_b",
	(uint64_t) 0x4000507b,
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

		cp.code() = std::string("//CV_SRL_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 201);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11662);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11569);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11572, 11570, 11571);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11661);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 11594);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 11616);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11638);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11660);\n";
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
ss << "cv_srl_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRL_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_srl_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_srl_sci_b",
	(uint64_t) 0x4000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SRL_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 202);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11748);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11663);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11666, 11664, 11665);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11747);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 11686);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 11706);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11726);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11746);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_srl_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRA_H --------------------------------------------------------------------
static InstructionDefinition cv_sra_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sra_h",
	(uint64_t) 0x4800007b,
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

		cp.code() = std::string("//CV_SRA_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 203);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11798);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11749);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11752, 11750, 11751);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11797);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 11774);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 11796);\n";
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
ss << "cv_sra_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRA_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_sra_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sra_sc_h",
	(uint64_t) 0x4800407b,
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

		cp.code() = std::string("//CV_SRA_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 204);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11848);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11799);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11802, 11800, 11801);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11847);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 11824);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 11846);\n";
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
ss << "cv_sra_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRA_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_sra_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sra_sci_h",
	(uint64_t) 0x4800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SRA_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 205);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11894);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11849);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11852, 11850, 11851);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11893);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >> " + std::to_string((((etiss_uint16)(Imm6)))) + "ULL << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 11872);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >> " + std::to_string((((etiss_uint16)(Imm6)))) + "ULL << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 11892);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sra_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRA_B --------------------------------------------------------------------
static InstructionDefinition cv_sra_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sra_b",
	(uint64_t) 0x4800107b,
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

		cp.code() = std::string("//CV_SRA_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 206);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 11988);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11895);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11898, 11896, 11897);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 11987);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 11920);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 11942);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 11964);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 11986);\n";
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
ss << "cv_sra_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRA_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_sra_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sra_sc_b",
	(uint64_t) 0x4800507b,
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

		cp.code() = std::string("//CV_SRA_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 207);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12082);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 11989);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 11992, 11990, 11991);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12081);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12014);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12036);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12058);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >> (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12080);\n";
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
ss << "cv_sra_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SRA_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_sra_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sra_sci_b",
	(uint64_t) 0x4800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SRA_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 208);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12168);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12083);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12086, 12084, 12085);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12167);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12106);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12126);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12146);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >> " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12166);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sra_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLL_H --------------------------------------------------------------------
static InstructionDefinition cv_sll_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sll_h",
	(uint64_t) 0x5000007b,
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

		cp.code() = std::string("//CV_SLL_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 209);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12218);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12169);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12172, 12170, 12171);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12217);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 12194);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) << ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 12216);\n";
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
ss << "cv_sll_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLL_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_sll_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sll_sc_h",
	(uint64_t) 0x5000407b,
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

		cp.code() = std::string("//CV_SLL_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 210);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12268);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12219);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12222, 12220, 12221);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12267);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 12244);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 12266);\n";
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
ss << "cv_sll_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLL_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_sll_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sll_sci_h",
	(uint64_t) 0x5000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SLL_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 211);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12314);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12269);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12272, 12270, 12271);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12313);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) << " + std::to_string((((etiss_uint16)(Imm6)))) + "ULL << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 12292);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) << " + std::to_string((((etiss_uint16)(Imm6)))) + "ULL << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 12312);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sll_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLL_B --------------------------------------------------------------------
static InstructionDefinition cv_sll_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sll_b",
	(uint64_t) 0x5000107b,
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

		cp.code() = std::string("//CV_SLL_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 212);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12408);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12315);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12318, 12316, 12317);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12407);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12340);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) << ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12362);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) << ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12384);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) << ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12406);\n";
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
ss << "cv_sll_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLL_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_sll_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sll_sc_b",
	(uint64_t) 0x5000507b,
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

		cp.code() = std::string("//CV_SLL_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 213);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12502);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12409);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12412, 12410, 12411);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12501);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12434);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12456);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12478);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) << (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12500);\n";
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
ss << "cv_sll_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLL_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_sll_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sll_sci_b",
	(uint64_t) 0x5000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SLL_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 214);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12588);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12503);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12506, 12504, 12505);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12587);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) << " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12526);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) << " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12546);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) << " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12566);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) << " + std::to_string((((etiss_uint8)(Imm6)))) + "ULL << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12586);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sll_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_OR_H ---------------------------------------------------------------------
static InstructionDefinition cv_or_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_or_h",
	(uint64_t) 0x5800007b,
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

		cp.code() = std::string("//CV_OR_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 215);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12642);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12589);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12592, 12590, 12591);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12641);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 12616);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) | (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 12640);\n";
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
ss << "cv_or_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_OR_SC_H ------------------------------------------------------------------
static InstructionDefinition cv_or_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_or_sc_h",
	(uint64_t) 0x5800407b,
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

		cp.code() = std::string("//CV_OR_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 216);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12696);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12643);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12646, 12644, 12645);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12695);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 12670);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 12694);\n";
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
ss << "cv_or_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_OR_SCI_H -----------------------------------------------------------------
static InstructionDefinition cv_or_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_or_sci_h",
	(uint64_t) 0x5800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_OR_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 217);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12750);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12697);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12700, 12698, 12699);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12749);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) | " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 12724);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) | " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 12748);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_or_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_OR_B ---------------------------------------------------------------------
static InstructionDefinition cv_or_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_or_b",
	(uint64_t) 0x5800107b,
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

		cp.code() = std::string("//CV_OR_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 218);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12852);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12751);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12754, 12752, 12753);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12851);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12778);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) | (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12802);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) | (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12826);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) | (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12850);\n";
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
ss << "cv_or_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_OR_SC_B ------------------------------------------------------------------
static InstructionDefinition cv_or_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_or_sc_b",
	(uint64_t) 0x5800507b,
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

		cp.code() = std::string("//CV_OR_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 219);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 12954);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12853);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12856, 12854, 12855);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 12953);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12880);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 12904);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 12928);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 12952);\n";
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
ss << "cv_or_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_OR_SCI_B -----------------------------------------------------------------
static InstructionDefinition cv_or_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_or_sci_b",
	(uint64_t) 0x5800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_OR_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 220);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13056);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 12955);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 12958, 12956, 12957);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13055);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) | " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 12982);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) | " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13006);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) | " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13030);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) | " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13054);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_or_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_XOR_H --------------------------------------------------------------------
static InstructionDefinition cv_xor_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_xor_h",
	(uint64_t) 0x6000007b,
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

		cp.code() = std::string("//CV_XOR_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 221);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13110);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13057);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13060, 13058, 13059);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13109);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 13084);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) ^ (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 13108);\n";
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
ss << "cv_xor_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_XOR_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_xor_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_xor_sc_h",
	(uint64_t) 0x6000407b,
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

		cp.code() = std::string("//CV_XOR_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 222);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13164);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13111);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13114, 13112, 13113);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13163);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 13138);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 13162);\n";
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
ss << "cv_xor_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_XOR_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_xor_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_xor_sci_h",
	(uint64_t) 0x6000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_XOR_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 223);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13218);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13165);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13168, 13166, 13167);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13217);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) ^ " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 13192);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) ^ " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 13216);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_xor_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_XOR_B --------------------------------------------------------------------
static InstructionDefinition cv_xor_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_xor_b",
	(uint64_t) 0x6000107b,
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

		cp.code() = std::string("//CV_XOR_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 224);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13320);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13219);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13222, 13220, 13221);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13319);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 13246);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) ^ (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13270);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) ^ (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13294);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) ^ (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13318);\n";
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
ss << "cv_xor_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_XOR_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_xor_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_xor_sc_b",
	(uint64_t) 0x6000507b,
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

		cp.code() = std::string("//CV_XOR_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 225);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13422);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13321);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13324, 13322, 13323);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13421);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 13348);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13372);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13396);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) ^ ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13420);\n";
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
ss << "cv_xor_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_XOR_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_xor_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_xor_sci_b",
	(uint64_t) 0x6000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_XOR_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 226);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13524);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13423);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13426, 13424, 13425);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13523);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) ^ " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 13450);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) ^ " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13474);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) ^ " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13498);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) ^ " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13522);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_xor_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AND_H --------------------------------------------------------------------
static InstructionDefinition cv_and_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_and_h",
	(uint64_t) 0x6800007b,
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

		cp.code() = std::string("//CV_AND_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 227);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13578);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13525);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13528, 13526, 13527);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13577);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 13552);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) & (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 13576);\n";
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
ss << "cv_and_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AND_SC_H -----------------------------------------------------------------
static InstructionDefinition cv_and_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_and_sc_h",
	(uint64_t) 0x6800407b,
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

		cp.code() = std::string("//CV_AND_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 228);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13632);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13579);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13582, 13580, 13581);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13631);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 13606);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 13630);\n";
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
ss << "cv_and_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AND_SCI_H ----------------------------------------------------------------
static InstructionDefinition cv_and_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_and_sci_h",
	(uint64_t) 0x6800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_AND_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 229);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13686);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13633);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13636, 13634, 13635);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13685);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) & " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 13660);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) & " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 13684);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_and_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AND_B --------------------------------------------------------------------
static InstructionDefinition cv_and_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_and_b",
	(uint64_t) 0x6800107b,
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

		cp.code() = std::string("//CV_AND_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 230);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13788);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13687);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13690, 13688, 13689);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13787);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 13714);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) & (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13738);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) & (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13762);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) & (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13786);\n";
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
ss << "cv_and_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AND_SC_B -----------------------------------------------------------------
static InstructionDefinition cv_and_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_and_sc_b",
	(uint64_t) 0x6800507b,
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

		cp.code() = std::string("//CV_AND_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 231);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13890);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13789);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13792, 13790, 13791);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13889);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 13816);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13840);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13864);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) & ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13888);\n";
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
ss << "cv_and_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_AND_SCI_B ----------------------------------------------------------------
static InstructionDefinition cv_and_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_and_sci_b",
	(uint64_t) 0x6800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_AND_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 232);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 13992);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13891);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13894, 13892, 13893);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 13991);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) & " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 13918);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) & " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 13942);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) & " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 13966);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) & " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 13990);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_and_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ABS_H --------------------------------------------------------------------
static InstructionDefinition cv_abs_h_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_abs_h",
	(uint64_t) 0x7000007b,
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

		cp.code() = std::string("//CV_ABS_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 233);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14072);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 13993);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 13996, 13994, 13995);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14071);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < 0LL)) ? ((((-(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)))) & 0xffffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 14033);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < 0LL)) ? ((((-((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)))) & 0xffffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 14070);\n";
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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_abs_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ABS_B --------------------------------------------------------------------
static InstructionDefinition cv_abs_b_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_abs_b",
	(uint64_t) 0x7000107b,
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

		cp.code() = std::string("//CV_ABS_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 234);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14226);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14073);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14076, 14074, 14075);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14225);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < 0LL)) ? ((((-(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)))) & 0xffULL)) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 14113);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < 0LL)) ? ((((-((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)))) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 14150);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < 0LL)) ? ((((-((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)))) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 14187);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < 0LL)) ? ((((-((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)))) & 0xffULL)) : ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 14224);\n";
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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_abs_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACT_H ----------------------------------------------------------------
static InstructionDefinition cv_extract_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_extract_h",
	(uint64_t) 0xb800007b,
	(uint64_t) 0xfdf0707f,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACT_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 235);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14255);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14227);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14230, 14228, 14229);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14254);\n";
cp.code() += "{ // block\n";
etiss_uint8 base = ((Imm6) & 0x1ULL) * 16ULL;
cp.code() += "etiss_coverage_count(7, 14237, 14236, 14234, 14232, 14233, 14233, 14235);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base) + "ULL)) & ((1 << ((" + std::to_string(base + 15ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1)))));\n";
cp.code() += "etiss_coverage_count(13, 14253, 14240, 14239, 14252, 14249, 14248, 14243, 14242, 14246, 14244, 14245, 14247, 14250);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extract_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACT_B ----------------------------------------------------------------
static InstructionDefinition cv_extract_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_extract_b",
	(uint64_t) 0xb800107b,
	(uint64_t) 0xfde0707f,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(20, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACT_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 236);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14285);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14256);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14259, 14257, 14258);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14284);\n";
cp.code() += "{ // block\n";
etiss_uint8 base = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 14267, 14266, 14264, 14261, 14262, 14263, 14265);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base) + "ULL)) & ((1 << ((" + std::to_string(base + 7ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1)))));\n";
cp.code() += "etiss_coverage_count(13, 14283, 14270, 14269, 14282, 14279, 14278, 14273, 14272, 14276, 14274, 14275, 14277, 14280);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(20, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extract_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACTU_H ---------------------------------------------------------------
static InstructionDefinition cv_extractu_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_extractu_h",
	(uint64_t) 0xb800207b,
	(uint64_t) 0xfdf0707f,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACTU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 237);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14313);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14286);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14289, 14287, 14288);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14312);\n";
cp.code() += "{ // block\n";
etiss_uint8 base = ((Imm6) & 0x1ULL) * 16ULL;
cp.code() += "etiss_coverage_count(7, 14296, 14295, 14293, 14291, 14292, 14292, 14294);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base) + "ULL)) & ((1 << ((" + std::to_string(base + 15ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1))));\n";
cp.code() += "etiss_coverage_count(12, 14311, 14299, 14298, 14310, 14307, 14302, 14301, 14305, 14303, 14304, 14306, 14308);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extractu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACTU_B ---------------------------------------------------------------
static InstructionDefinition cv_extractu_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_extractu_b",
	(uint64_t) 0xb800307b,
	(uint64_t) 0xfde0707f,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(20, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACTU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 238);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14342);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14314);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14317, 14315, 14316);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14341);\n";
cp.code() += "{ // block\n";
etiss_uint8 base = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 14325, 14324, 14322, 14319, 14320, 14321, 14323);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base) + "ULL)) & ((1 << ((" + std::to_string(base + 7ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1))));\n";
cp.code() += "etiss_coverage_count(12, 14340, 14328, 14327, 14339, 14336, 14331, 14330, 14334, 14332, 14333, 14335, 14337);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(20, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extractu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_INSERT_H -----------------------------------------------------------------
static InstructionDefinition cv_insert_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_insert_h",
	(uint64_t) 0xb800407b,
	(uint64_t) 0xfdf0707f,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_INSERT_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 239);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14370);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14343);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14346, 14344, 14345);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14369);\n";
cp.code() += "{ // block\n";
etiss_uint8 base = ((Imm6) & 0x1ULL) * 16ULL;
cp.code() += "etiss_coverage_count(7, 14353, 14352, 14350, 14348, 14349, 14349, 14351);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (~(((1 << ((" + std::to_string(base + 15ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1) << (" + std::to_string(base) + "ULL)))) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) << " + std::to_string(base) + "ULL) & (((1 << ((" + std::to_string(base + 15ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1) << (" + std::to_string(base) + "ULL))U));\n";
cp.code() += "etiss_coverage_count(1, 14368);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_insert_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_INSERT_B -----------------------------------------------------------------
static InstructionDefinition cv_insert_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_insert_b",
	(uint64_t) 0xb800507b,
	(uint64_t) 0xfde0707f,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(20, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_INSERT_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 240);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14399);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14371);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14374, 14372, 14373);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 14398);\n";
cp.code() += "{ // block\n";
etiss_uint8 base = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 14382, 14381, 14379, 14376, 14377, 14378, 14380);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (~(((1 << ((" + std::to_string(base + 7ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1) << (" + std::to_string(base) + "ULL)))) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) << " + std::to_string(base) + "ULL) & (((1 << ((" + std::to_string(base + 7ULL) + "ULL) - (" + std::to_string(base) + "ULL) + 1)) - 1) << (" + std::to_string(base) + "ULL))U));\n";
cp.code() += "etiss_coverage_count(1, 14397);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(20, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_insert_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUP_H ------------------------------------------------------------------
static InstructionDefinition cv_dotup_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotup_h",
	(uint64_t) 0x8000007b,
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

		cp.code() = std::string("//CV_DOTUP_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 241);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14445);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14400);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14403, 14401, 14402);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(35, 14444, 14406, 14405, 14443, 14439, 14421, 14413, 14412, 14409, 14408, 14410, 14411, 14420, 14419, 14416, 14415, 14417, 14418, 14422, 14437, 14429, 14428, 14425, 14424, 14426, 14427, 14436, 14435, 14432, 14431, 14433, 14434, 14438, 14440, 14441);\n";
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
ss << "cv_dotup_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUP_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_dotup_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotup_sc_h",
	(uint64_t) 0x8000407b,
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

		cp.code() = std::string("//CV_DOTUP_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 242);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14491);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14446);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14449, 14447, 14448);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(35, 14490, 14452, 14451, 14489, 14485, 14467, 14459, 14458, 14455, 14454, 14456, 14457, 14466, 14465, 14462, 14461, 14463, 14464, 14468, 14483, 14475, 14474, 14471, 14470, 14472, 14473, 14482, 14481, 14478, 14477, 14479, 14480, 14484, 14486, 14487);\n";
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
ss << "cv_dotup_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUP_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_dotup_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_dotup_sci_h",
	(uint64_t) 0x8000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_DOTUP_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 243);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14537);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14492);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14495, 14493, 14494);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * " + std::to_string((etiss_uint16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * " + std::to_string((etiss_uint16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL))));\n";
cp.code() += "etiss_coverage_count(35, 14536, 14498, 14497, 14535, 14531, 14513, 14505, 14504, 14501, 14500, 14502, 14503, 14512, 14510, 14507, 14506, 14508, 14511, 14514, 14529, 14521, 14520, 14517, 14516, 14518, 14519, 14528, 14526, 14523, 14522, 14524, 14527, 14530, 14532, 14533);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_dotup_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUP_B ------------------------------------------------------------------
static InstructionDefinition cv_dotup_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotup_b",
	(uint64_t) 0x8000107b,
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

		cp.code() = std::string("//CV_DOTUP_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 244);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14617);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14538);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14541, 14539, 14540);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(65, 14616, 14544, 14543, 14615, 14611, 14594, 14577, 14559, 14551, 14550, 14547, 14546, 14548, 14549, 14558, 14557, 14554, 14553, 14555, 14556, 14560, 14575, 14567, 14566, 14563, 14562, 14564, 14565, 14574, 14573, 14570, 14569, 14571, 14572, 14576, 14592, 14584, 14583, 14580, 14579, 14581, 14582, 14591, 14590, 14587, 14586, 14588, 14589, 14593, 14609, 14601, 14600, 14597, 14596, 14598, 14599, 14608, 14607, 14604, 14603, 14605, 14606, 14610, 14612, 14613);\n";
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
ss << "cv_dotup_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUP_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_dotup_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotup_sc_b",
	(uint64_t) 0x8000507b,
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

		cp.code() = std::string("//CV_DOTUP_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 245);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14697);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14618);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14621, 14619, 14620);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(65, 14696, 14624, 14623, 14695, 14691, 14674, 14657, 14639, 14631, 14630, 14627, 14626, 14628, 14629, 14638, 14637, 14634, 14633, 14635, 14636, 14640, 14655, 14647, 14646, 14643, 14642, 14644, 14645, 14654, 14653, 14650, 14649, 14651, 14652, 14656, 14672, 14664, 14663, 14660, 14659, 14661, 14662, 14671, 14670, 14667, 14666, 14668, 14669, 14673, 14689, 14681, 14680, 14677, 14676, 14678, 14679, 14688, 14687, 14684, 14683, 14685, 14686, 14690, 14692, 14693);\n";
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
ss << "cv_dotup_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUP_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_dotup_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_dotup_sci_b",
	(uint64_t) 0x8000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_DOTUP_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 246);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14777);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14698);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14701, 14699, 14700);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL))));\n";
cp.code() += "etiss_coverage_count(65, 14776, 14704, 14703, 14775, 14771, 14754, 14737, 14719, 14711, 14710, 14707, 14706, 14708, 14709, 14718, 14716, 14713, 14712, 14714, 14717, 14720, 14735, 14727, 14726, 14723, 14722, 14724, 14725, 14734, 14732, 14729, 14728, 14730, 14733, 14736, 14752, 14744, 14743, 14740, 14739, 14741, 14742, 14751, 14749, 14746, 14745, 14747, 14750, 14753, 14769, 14761, 14760, 14757, 14756, 14758, 14759, 14768, 14766, 14763, 14762, 14764, 14767, 14770, 14772, 14773);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_dotup_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUSP_H -----------------------------------------------------------------
static InstructionDefinition cv_dotusp_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotusp_h",
	(uint64_t) 0x8800007b,
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

		cp.code() = std::string("//CV_DOTUSP_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 247);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14823);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14778);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14781, 14779, 14780);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(35, 14822, 14784, 14783, 14821, 14817, 14799, 14791, 14790, 14787, 14786, 14788, 14789, 14798, 14797, 14794, 14793, 14795, 14796, 14800, 14815, 14807, 14806, 14803, 14802, 14804, 14805, 14814, 14813, 14810, 14809, 14811, 14812, 14816, 14818, 14819);\n";
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
ss << "cv_dotusp_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUSP_SC_H --------------------------------------------------------------
static InstructionDefinition cv_dotusp_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotusp_sc_h",
	(uint64_t) 0x8800407b,
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

		cp.code() = std::string("//CV_DOTUSP_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 248);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14869);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14824);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14827, 14825, 14826);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(35, 14868, 14830, 14829, 14867, 14863, 14845, 14837, 14836, 14833, 14832, 14834, 14835, 14844, 14843, 14840, 14839, 14841, 14842, 14846, 14861, 14853, 14852, 14849, 14848, 14850, 14851, 14860, 14859, 14856, 14855, 14857, 14858, 14862, 14864, 14865);\n";
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
ss << "cv_dotusp_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUSP_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_dotusp_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_dotusp_sci_h",
	(uint64_t) 0x8800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_DOTUSP_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 249);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14915);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14870);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14873, 14871, 14872);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL))));\n";
cp.code() += "etiss_coverage_count(35, 14914, 14876, 14875, 14913, 14909, 14891, 14883, 14882, 14879, 14878, 14880, 14881, 14890, 14888, 14885, 14884, 14886, 14889, 14892, 14907, 14899, 14898, 14895, 14894, 14896, 14897, 14906, 14904, 14901, 14900, 14902, 14905, 14908, 14910, 14911);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_dotusp_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUSP_B -----------------------------------------------------------------
static InstructionDefinition cv_dotusp_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotusp_b",
	(uint64_t) 0x8800107b,
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

		cp.code() = std::string("//CV_DOTUSP_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 250);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 14995);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14916);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14919, 14917, 14918);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(65, 14994, 14922, 14921, 14993, 14989, 14972, 14955, 14937, 14929, 14928, 14925, 14924, 14926, 14927, 14936, 14935, 14932, 14931, 14933, 14934, 14938, 14953, 14945, 14944, 14941, 14940, 14942, 14943, 14952, 14951, 14948, 14947, 14949, 14950, 14954, 14970, 14962, 14961, 14958, 14957, 14959, 14960, 14969, 14968, 14965, 14964, 14966, 14967, 14971, 14987, 14979, 14978, 14975, 14974, 14976, 14977, 14986, 14985, 14982, 14981, 14983, 14984, 14988, 14990, 14991);\n";
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
ss << "cv_dotusp_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUSP_SC_B --------------------------------------------------------------
static InstructionDefinition cv_dotusp_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotusp_sc_b",
	(uint64_t) 0x8800507b,
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

		cp.code() = std::string("//CV_DOTUSP_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 251);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15075);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 14996);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 14999, 14997, 14998);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(65, 15074, 15002, 15001, 15073, 15069, 15052, 15035, 15017, 15009, 15008, 15005, 15004, 15006, 15007, 15016, 15015, 15012, 15011, 15013, 15014, 15018, 15033, 15025, 15024, 15021, 15020, 15022, 15023, 15032, 15031, 15028, 15027, 15029, 15030, 15034, 15050, 15042, 15041, 15038, 15037, 15039, 15040, 15049, 15048, 15045, 15044, 15046, 15047, 15051, 15067, 15059, 15058, 15055, 15054, 15056, 15057, 15066, 15065, 15062, 15061, 15063, 15064, 15068, 15070, 15071);\n";
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
ss << "cv_dotusp_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTUSP_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_dotusp_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_dotusp_sci_b",
	(uint64_t) 0x8800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_DOTUSP_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 252);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15155);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15076);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15079, 15077, 15078);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL))));\n";
cp.code() += "etiss_coverage_count(65, 15154, 15082, 15081, 15153, 15149, 15132, 15115, 15097, 15089, 15088, 15085, 15084, 15086, 15087, 15096, 15094, 15091, 15090, 15092, 15095, 15098, 15113, 15105, 15104, 15101, 15100, 15102, 15103, 15112, 15110, 15107, 15106, 15108, 15111, 15114, 15130, 15122, 15121, 15118, 15117, 15119, 15120, 15129, 15127, 15124, 15123, 15125, 15128, 15131, 15147, 15139, 15138, 15135, 15134, 15136, 15137, 15146, 15144, 15141, 15140, 15142, 15145, 15148, 15150, 15151);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_dotusp_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTSP_H ------------------------------------------------------------------
static InstructionDefinition cv_dotsp_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotsp_h",
	(uint64_t) 0x9000007b,
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

		cp.code() = std::string("//CV_DOTSP_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 253);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15202);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15156);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15159, 15157, 15158);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int16)((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))));\n";
cp.code() += "etiss_coverage_count(36, 15201, 15162, 15161, 15200, 15197, 15195, 15177, 15169, 15168, 15165, 15164, 15166, 15167, 15176, 15175, 15172, 15171, 15173, 15174, 15178, 15193, 15185, 15184, 15181, 15180, 15182, 15183, 15192, 15191, 15188, 15187, 15189, 15190, 15194, 15196, 15198);\n";
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
ss << "cv_dotsp_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTSP_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_dotsp_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotsp_sc_h",
	(uint64_t) 0x9000407b,
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

		cp.code() = std::string("//CV_DOTSP_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 254);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15249);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15203);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15206, 15204, 15205);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int16)((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))));\n";
cp.code() += "etiss_coverage_count(36, 15248, 15209, 15208, 15247, 15244, 15242, 15224, 15216, 15215, 15212, 15211, 15213, 15214, 15223, 15222, 15219, 15218, 15220, 15221, 15225, 15240, 15232, 15231, 15228, 15227, 15229, 15230, 15239, 15238, 15235, 15234, 15236, 15237, 15241, 15243, 15245);\n";
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
ss << "cv_dotsp_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTSP_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_dotsp_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_dotsp_sci_h",
	(uint64_t) 0x9000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_DOTSP_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 255);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15296);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15250);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15253, 15251, 15252);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int16)((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))));\n";
cp.code() += "etiss_coverage_count(36, 15295, 15256, 15255, 15294, 15291, 15289, 15271, 15263, 15262, 15259, 15258, 15260, 15261, 15270, 15268, 15265, 15264, 15266, 15269, 15272, 15287, 15279, 15278, 15275, 15274, 15276, 15277, 15286, 15284, 15281, 15280, 15282, 15285, 15288, 15290, 15292);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_dotsp_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTSP_B ------------------------------------------------------------------
static InstructionDefinition cv_dotsp_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotsp_b",
	(uint64_t) 0x9000107b,
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

		cp.code() = std::string("//CV_DOTSP_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 256);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15377);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15297);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15300, 15298, 15299);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int8)((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))));\n";
cp.code() += "etiss_coverage_count(66, 15376, 15303, 15302, 15375, 15372, 15370, 15353, 15336, 15318, 15310, 15309, 15306, 15305, 15307, 15308, 15317, 15316, 15313, 15312, 15314, 15315, 15319, 15334, 15326, 15325, 15322, 15321, 15323, 15324, 15333, 15332, 15329, 15328, 15330, 15331, 15335, 15351, 15343, 15342, 15339, 15338, 15340, 15341, 15350, 15349, 15346, 15345, 15347, 15348, 15352, 15368, 15360, 15359, 15356, 15355, 15357, 15358, 15367, 15366, 15363, 15362, 15364, 15365, 15369, 15371, 15373);\n";
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
ss << "cv_dotsp_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTSP_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_dotsp_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_dotsp_sc_b",
	(uint64_t) 0x9000507b,
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

		cp.code() = std::string("//CV_DOTSP_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 257);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15458);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15378);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15381, 15379, 15380);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int8)((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))));\n";
cp.code() += "etiss_coverage_count(66, 15457, 15384, 15383, 15456, 15453, 15451, 15434, 15417, 15399, 15391, 15390, 15387, 15386, 15388, 15389, 15398, 15397, 15394, 15393, 15395, 15396, 15400, 15415, 15407, 15406, 15403, 15402, 15404, 15405, 15414, 15413, 15410, 15409, 15411, 15412, 15416, 15432, 15424, 15423, 15420, 15419, 15421, 15422, 15431, 15430, 15427, 15426, 15428, 15429, 15433, 15449, 15441, 15440, 15437, 15436, 15438, 15439, 15448, 15447, 15444, 15443, 15445, 15446, 15450, 15452, 15454);\n";
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
ss << "cv_dotsp_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_DOTSP_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_dotsp_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_dotsp_sci_b",
	(uint64_t) 0x9000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_DOTSP_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 258);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15539);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15459);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15462, 15460, 15461);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int8)((((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))));\n";
cp.code() += "etiss_coverage_count(66, 15538, 15465, 15464, 15537, 15534, 15532, 15515, 15498, 15480, 15472, 15471, 15468, 15467, 15469, 15470, 15479, 15477, 15474, 15473, 15475, 15478, 15481, 15496, 15488, 15487, 15484, 15483, 15485, 15486, 15495, 15493, 15490, 15489, 15491, 15494, 15497, 15513, 15505, 15504, 15501, 15500, 15502, 15503, 15512, 15510, 15507, 15506, 15508, 15511, 15514, 15530, 15522, 15521, 15518, 15517, 15519, 15520, 15529, 15527, 15524, 15523, 15525, 15528, 15531, 15533, 15535);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_dotsp_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUP_H -----------------------------------------------------------------
static InstructionDefinition cv_sdotup_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotup_h",
	(uint64_t) 0x9800007b,
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

		cp.code() = std::string("//CV_SDOTUP_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 259);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15589);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15540);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15543, 15541, 15542);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(38, 15588, 15546, 15545, 15587, 15583, 15566, 15549, 15548, 15564, 15556, 15555, 15552, 15551, 15553, 15554, 15563, 15562, 15559, 15558, 15560, 15561, 15565, 15581, 15573, 15572, 15569, 15568, 15570, 15571, 15580, 15579, 15576, 15575, 15577, 15578, 15582, 15584, 15585);\n";
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
ss << "cv_sdotup_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUP_SC_H --------------------------------------------------------------
static InstructionDefinition cv_sdotup_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotup_sc_h",
	(uint64_t) 0x9800407b,
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

		cp.code() = std::string("//CV_SDOTUP_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 260);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15639);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15590);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15593, 15591, 15592);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(38, 15638, 15596, 15595, 15637, 15633, 15616, 15599, 15598, 15614, 15606, 15605, 15602, 15601, 15603, 15604, 15613, 15612, 15609, 15608, 15610, 15611, 15615, 15631, 15623, 15622, 15619, 15618, 15620, 15621, 15630, 15629, 15626, 15625, 15627, 15628, 15632, 15634, 15635);\n";
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
ss << "cv_sdotup_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUP_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_sdotup_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sdotup_sci_h",
	(uint64_t) 0x9800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SDOTUP_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 261);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15689);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15640);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15643, 15641, 15642);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * " + std::to_string((etiss_uint16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * " + std::to_string((etiss_uint16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL))));\n";
cp.code() += "etiss_coverage_count(38, 15688, 15646, 15645, 15687, 15683, 15666, 15649, 15648, 15664, 15656, 15655, 15652, 15651, 15653, 15654, 15663, 15661, 15658, 15657, 15659, 15662, 15665, 15681, 15673, 15672, 15669, 15668, 15670, 15671, 15680, 15678, 15675, 15674, 15676, 15679, 15682, 15684, 15685);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sdotup_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUP_B -----------------------------------------------------------------
static InstructionDefinition cv_sdotup_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotup_b",
	(uint64_t) 0x9800107b,
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

		cp.code() = std::string("//CV_SDOTUP_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 262);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15773);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15690);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15693, 15691, 15692);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(68, 15772, 15696, 15695, 15771, 15767, 15750, 15733, 15716, 15699, 15698, 15714, 15706, 15705, 15702, 15701, 15703, 15704, 15713, 15712, 15709, 15708, 15710, 15711, 15715, 15731, 15723, 15722, 15719, 15718, 15720, 15721, 15730, 15729, 15726, 15725, 15727, 15728, 15732, 15748, 15740, 15739, 15736, 15735, 15737, 15738, 15747, 15746, 15743, 15742, 15744, 15745, 15749, 15765, 15757, 15756, 15753, 15752, 15754, 15755, 15764, 15763, 15760, 15759, 15761, 15762, 15766, 15768, 15769);\n";
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
ss << "cv_sdotup_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUP_SC_B --------------------------------------------------------------
static InstructionDefinition cv_sdotup_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotup_sc_b",
	(uint64_t) 0x9800507b,
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

		cp.code() = std::string("//CV_SDOTUP_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 263);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15857);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15774);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15777, 15775, 15776);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(68, 15856, 15780, 15779, 15855, 15851, 15834, 15817, 15800, 15783, 15782, 15798, 15790, 15789, 15786, 15785, 15787, 15788, 15797, 15796, 15793, 15792, 15794, 15795, 15799, 15815, 15807, 15806, 15803, 15802, 15804, 15805, 15814, 15813, 15810, 15809, 15811, 15812, 15816, 15832, 15824, 15823, 15820, 15819, 15821, 15822, 15831, 15830, 15827, 15826, 15828, 15829, 15833, 15849, 15841, 15840, 15837, 15836, 15838, 15839, 15848, 15847, 15844, 15843, 15845, 15846, 15850, 15852, 15853);\n";
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
ss << "cv_sdotup_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUP_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_sdotup_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sdotup_sci_b",
	(uint64_t) 0x9800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SDOTUP_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 264);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15941);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15858);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15861, 15859, 15860);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * " + std::to_string((etiss_uint8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "ULL))));\n";
cp.code() += "etiss_coverage_count(68, 15940, 15864, 15863, 15939, 15935, 15918, 15901, 15884, 15867, 15866, 15882, 15874, 15873, 15870, 15869, 15871, 15872, 15881, 15879, 15876, 15875, 15877, 15880, 15883, 15899, 15891, 15890, 15887, 15886, 15888, 15889, 15898, 15896, 15893, 15892, 15894, 15897, 15900, 15916, 15908, 15907, 15904, 15903, 15905, 15906, 15915, 15913, 15910, 15909, 15911, 15914, 15917, 15933, 15925, 15924, 15921, 15920, 15922, 15923, 15932, 15930, 15927, 15926, 15928, 15931, 15934, 15936, 15937);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sdotup_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUSP_H ----------------------------------------------------------------
static InstructionDefinition cv_sdotusp_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotusp_h",
	(uint64_t) 0xa000007b,
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

		cp.code() = std::string("//CV_SDOTUSP_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 265);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 15991);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15942);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15945, 15943, 15944);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(38, 15990, 15948, 15947, 15989, 15985, 15968, 15951, 15950, 15966, 15958, 15957, 15954, 15953, 15955, 15956, 15965, 15964, 15961, 15960, 15962, 15963, 15967, 15983, 15975, 15974, 15971, 15970, 15972, 15973, 15982, 15981, 15978, 15977, 15979, 15980, 15984, 15986, 15987);\n";
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
ss << "cv_sdotusp_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUSP_SC_H -------------------------------------------------------------
static InstructionDefinition cv_sdotusp_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotusp_sc_h",
	(uint64_t) 0xa000407b,
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

		cp.code() = std::string("//CV_SDOTUSP_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 266);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16041);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 15992);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 15995, 15993, 15994);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))));\n";
cp.code() += "etiss_coverage_count(38, 16040, 15998, 15997, 16039, 16035, 16018, 16001, 16000, 16016, 16008, 16007, 16004, 16003, 16005, 16006, 16015, 16014, 16011, 16010, 16012, 16013, 16017, 16033, 16025, 16024, 16021, 16020, 16022, 16023, 16032, 16031, 16028, 16027, 16029, 16030, 16034, 16036, 16037);\n";
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
ss << "cv_sdotusp_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUSP_SCI_H ------------------------------------------------------------
static InstructionDefinition cv_sdotusp_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sdotusp_sci_h",
	(uint64_t) 0xa000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SDOTUSP_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 267);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16091);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16042);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16045, 16043, 16044);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL))));\n";
cp.code() += "etiss_coverage_count(38, 16090, 16048, 16047, 16089, 16085, 16068, 16051, 16050, 16066, 16058, 16057, 16054, 16053, 16055, 16056, 16065, 16063, 16060, 16059, 16061, 16064, 16067, 16083, 16075, 16074, 16071, 16070, 16072, 16073, 16082, 16080, 16077, 16076, 16078, 16081, 16084, 16086, 16087);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sdotusp_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUSP_B ----------------------------------------------------------------
static InstructionDefinition cv_sdotusp_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotusp_b",
	(uint64_t) 0xa000107b,
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

		cp.code() = std::string("//CV_SDOTUSP_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 268);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16175);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16092);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16095, 16093, 16094);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(68, 16174, 16098, 16097, 16173, 16169, 16152, 16135, 16118, 16101, 16100, 16116, 16108, 16107, 16104, 16103, 16105, 16106, 16115, 16114, 16111, 16110, 16112, 16113, 16117, 16133, 16125, 16124, 16121, 16120, 16122, 16123, 16132, 16131, 16128, 16127, 16129, 16130, 16134, 16150, 16142, 16141, 16138, 16137, 16139, 16140, 16149, 16148, 16145, 16144, 16146, 16147, 16151, 16167, 16159, 16158, 16155, 16154, 16156, 16157, 16166, 16165, 16162, 16161, 16163, 16164, 16168, 16170, 16171);\n";
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
ss << "cv_sdotusp_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUSP_SC_B -------------------------------------------------------------
static InstructionDefinition cv_sdotusp_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotusp_sc_b",
	(uint64_t) 0xa000507b,
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

		cp.code() = std::string("//CV_SDOTUSP_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 269);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16259);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16176);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16179, 16177, 16178);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))));\n";
cp.code() += "etiss_coverage_count(68, 16258, 16182, 16181, 16257, 16253, 16236, 16219, 16202, 16185, 16184, 16200, 16192, 16191, 16188, 16187, 16189, 16190, 16199, 16198, 16195, 16194, 16196, 16197, 16201, 16217, 16209, 16208, 16205, 16204, 16206, 16207, 16216, 16215, 16212, 16211, 16213, 16214, 16218, 16234, 16226, 16225, 16222, 16221, 16223, 16224, 16233, 16232, 16229, 16228, 16230, 16231, 16235, 16251, 16243, 16242, 16239, 16238, 16240, 16241, 16250, 16249, 16246, 16245, 16247, 16248, 16252, 16254, 16255);\n";
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
ss << "cv_sdotusp_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTUSP_SCI_B ------------------------------------------------------------
static InstructionDefinition cv_sdotusp_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sdotusp_sci_b",
	(uint64_t) 0xa000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SDOTUSP_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 270);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16343);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16260);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16263, 16261, 16262);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL))));\n";
cp.code() += "etiss_coverage_count(68, 16342, 16266, 16265, 16341, 16337, 16320, 16303, 16286, 16269, 16268, 16284, 16276, 16275, 16272, 16271, 16273, 16274, 16283, 16281, 16278, 16277, 16279, 16282, 16285, 16301, 16293, 16292, 16289, 16288, 16290, 16291, 16300, 16298, 16295, 16294, 16296, 16299, 16302, 16318, 16310, 16309, 16306, 16305, 16307, 16308, 16317, 16315, 16312, 16311, 16313, 16316, 16319, 16335, 16327, 16326, 16323, 16322, 16324, 16325, 16334, 16332, 16329, 16328, 16330, 16333, 16336, 16338, 16339);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sdotusp_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTSP_H -----------------------------------------------------------------
static InstructionDefinition cv_sdotsp_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotsp_h",
	(uint64_t) 0xa800007b,
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

		cp.code() = std::string("//CV_SDOTSP_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 271);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16394);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16344);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16347, 16345, 16346);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))));\n";
cp.code() += "etiss_coverage_count(39, 16393, 16350, 16349, 16392, 16389, 16387, 16370, 16353, 16352, 16368, 16360, 16359, 16356, 16355, 16357, 16358, 16367, 16366, 16363, 16362, 16364, 16365, 16369, 16385, 16377, 16376, 16373, 16372, 16374, 16375, 16384, 16383, 16380, 16379, 16381, 16382, 16386, 16388, 16390);\n";
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
ss << "cv_sdotsp_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTSP_SC_H --------------------------------------------------------------
static InstructionDefinition cv_sdotsp_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotsp_sc_h",
	(uint64_t) 0xa800407b,
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

		cp.code() = std::string("//CV_SDOTSP_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 272);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16445);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16395);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16398, 16396, 16397);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) + ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))));\n";
cp.code() += "etiss_coverage_count(39, 16444, 16401, 16400, 16443, 16440, 16438, 16421, 16404, 16403, 16419, 16411, 16410, 16407, 16406, 16408, 16409, 16418, 16417, 16414, 16413, 16415, 16416, 16420, 16436, 16428, 16427, 16424, 16423, 16425, 16426, 16435, 16434, 16431, 16430, 16432, 16433, 16437, 16439, 16441);\n";
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
ss << "cv_sdotsp_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTSP_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_sdotsp_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sdotsp_sci_h",
	(uint64_t) 0xa800607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SDOTSP_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 273);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16496);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16446);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16449, 16447, 16448);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))));\n";
cp.code() += "etiss_coverage_count(39, 16495, 16452, 16451, 16494, 16491, 16489, 16472, 16455, 16454, 16470, 16462, 16461, 16458, 16457, 16459, 16460, 16469, 16467, 16464, 16463, 16465, 16468, 16471, 16487, 16479, 16478, 16475, 16474, 16476, 16477, 16486, 16484, 16481, 16480, 16482, 16485, 16488, 16490, 16492);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sdotsp_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTSP_B -----------------------------------------------------------------
static InstructionDefinition cv_sdotsp_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotsp_b",
	(uint64_t) 0xa800107b,
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

		cp.code() = std::string("//CV_SDOTSP_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 274);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16581);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16497);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16500, 16498, 16499);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))));\n";
cp.code() += "etiss_coverage_count(69, 16580, 16503, 16502, 16579, 16576, 16574, 16557, 16540, 16523, 16506, 16505, 16521, 16513, 16512, 16509, 16508, 16510, 16511, 16520, 16519, 16516, 16515, 16517, 16518, 16522, 16538, 16530, 16529, 16526, 16525, 16527, 16528, 16537, 16536, 16533, 16532, 16534, 16535, 16539, 16555, 16547, 16546, 16543, 16542, 16544, 16545, 16554, 16553, 16550, 16549, 16551, 16552, 16556, 16572, 16564, 16563, 16560, 16559, 16561, 16562, 16571, 16570, 16567, 16566, 16568, 16569, 16573, 16575, 16577);\n";
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
ss << "cv_sdotsp_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTSP_SC_B --------------------------------------------------------------
static InstructionDefinition cv_sdotsp_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sdotsp_sc_b",
	(uint64_t) 0xa800507b,
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

		cp.code() = std::string("//CV_SDOTSP_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 275);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16666);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16582);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16585, 16583, 16584);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))));\n";
cp.code() += "etiss_coverage_count(69, 16665, 16588, 16587, 16664, 16661, 16659, 16642, 16625, 16608, 16591, 16590, 16606, 16598, 16597, 16594, 16593, 16595, 16596, 16605, 16604, 16601, 16600, 16602, 16603, 16607, 16623, 16615, 16614, 16611, 16610, 16612, 16613, 16622, 16621, 16618, 16617, 16619, 16620, 16624, 16640, 16632, 16631, 16628, 16627, 16629, 16630, 16639, 16638, 16635, 16634, 16636, 16637, 16641, 16657, 16649, 16648, 16645, 16644, 16646, 16647, 16656, 16655, 16652, 16651, 16653, 16654, 16658, 16660, 16662);\n";
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
ss << "cv_sdotsp_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SDOTSP_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_sdotsp_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_sdotsp_sci_b",
	(uint64_t) 0xa800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SDOTSP_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 276);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16751);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16667);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16670, 16668, 16669);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + ((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL) + ((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) * " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))));\n";
cp.code() += "etiss_coverage_count(69, 16750, 16673, 16672, 16749, 16746, 16744, 16727, 16710, 16693, 16676, 16675, 16691, 16683, 16682, 16679, 16678, 16680, 16681, 16690, 16688, 16685, 16684, 16686, 16689, 16692, 16708, 16700, 16699, 16696, 16695, 16697, 16698, 16707, 16705, 16702, 16701, 16703, 16706, 16709, 16725, 16717, 16716, 16713, 16712, 16714, 16715, 16724, 16722, 16719, 16718, 16720, 16723, 16726, 16742, 16734, 16733, 16730, 16729, 16731, 16732, 16741, 16739, 16736, 16735, 16737, 16740, 16743, 16745, 16747);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sdotsp_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLE_H ----------------------------------------------------------------
static InstructionDefinition cv_shuffle_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_shuffle_h",
	(uint64_t) 0xc000007b,
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

		cp.code() = std::string("//CV_SHUFFLE_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 277);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16805);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16752);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16755, 16753, 16754);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 16804);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 base_lo = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x1ULL) * 16ULL;\n";
cp.code() += "etiss_coverage_count(8, 16764, 16763, 16761, 16759, 16758, 16760, 16760, 16762);\n";
cp.code() += "etiss_uint8 base_hi = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0x1ULL) * 16ULL;\n";
cp.code() += "etiss_coverage_count(8, 16773, 16772, 16770, 16768, 16767, 16769, 16769, 16771);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (base_lo)) & ((1 << ((base_lo + 15ULL) - (base_lo) + 1)) - 1)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 16788);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (base_hi)) & ((1 << ((base_hi + 15ULL) - (base_hi) + 1)) - 1)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 16803);\n";
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
ss << "cv_shuffle_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLE_SCI_H ------------------------------------------------------------
static InstructionDefinition cv_shuffle_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_shuffle_sci_h",
	(uint64_t) 0xc000607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SHUFFLE_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 278);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16855);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16806);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16809, 16807, 16808);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 16854);\n";
cp.code() += "{ // block\n";
etiss_uint8 base_lo = ((Imm6) & 0x1ULL) * 16ULL;
cp.code() += "etiss_coverage_count(7, 16816, 16815, 16813, 16811, 16812, 16812, 16814);\n";
etiss_uint8 base_hi = (((Imm6) >> (16ULL)) & 0x1ULL) * 16ULL;
cp.code() += "etiss_coverage_count(7, 16823, 16822, 16820, 16818, 16819, 16819, 16821);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base_lo) + "ULL)) & ((1 << ((" + std::to_string(base_lo + 15ULL) + "ULL) - (" + std::to_string(base_lo) + "ULL) + 1)) - 1)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 16838);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base_hi) + "ULL)) & ((1 << ((" + std::to_string(base_hi + 15ULL) + "ULL) - (" + std::to_string(base_hi) + "ULL) + 1)) - 1)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 16853);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_shuffle_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLE_B ----------------------------------------------------------------
static InstructionDefinition cv_shuffle_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_shuffle_b",
	(uint64_t) 0xc000107b,
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

		cp.code() = std::string("//CV_SHUFFLE_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 279);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 16961);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16856);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16859, 16857, 16858);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 16960);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 base0 = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 16869, 16868, 16866, 16863, 16862, 16864, 16865, 16867);\n";
cp.code() += "etiss_uint8 base1 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 16879, 16878, 16876, 16873, 16872, 16874, 16875, 16877);\n";
cp.code() += "etiss_uint8 base2 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 16889, 16888, 16886, 16883, 16882, 16884, 16885, 16887);\n";
cp.code() += "etiss_uint8 base3 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 16899, 16898, 16896, 16893, 16892, 16894, 16895, 16897);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (base0)) & ((1 << ((base0 + 7ULL) - (base0) + 1)) - 1)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 16914);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (base1)) & ((1 << ((base1 + 7ULL) - (base1) + 1)) - 1)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 16929);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (base2)) & ((1 << ((base2 + 7ULL) - (base2) + 1)) - 1)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 16944);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (base3)) & ((1 << ((base3 + 7ULL) - (base3) + 1)) - 1)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 16959);\n";
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
ss << "cv_shuffle_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLEI0_SCI_B ----------------------------------------------------------
static InstructionDefinition cv_shufflei0_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_shufflei0_sci_b",
	(uint64_t) 0xc000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SHUFFLEI0_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 280);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17049);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 16962);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 16965, 16963, 16964);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17048);\n";
cp.code() += "{ // block\n";
etiss_uint8 base0 = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 16973, 16972, 16970, 16967, 16968, 16969, 16971);\n";
etiss_uint8 base1 = (((Imm6) >> (2ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 16981, 16980, 16978, 16975, 16976, 16977, 16979);\n";
etiss_uint8 base2 = (((Imm6) >> (4ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 16989, 16988, 16986, 16983, 16984, 16985, 16987);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base0) + "ULL)) & ((1 << ((" + std::to_string(base0 + 7ULL) + "ULL) - (" + std::to_string(base0) + "ULL) + 1)) - 1)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17004);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base1) + "ULL)) & ((1 << ((" + std::to_string(base1 + 7ULL) + "ULL) - (" + std::to_string(base1) + "ULL) + 1)) - 1)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17019);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base2) + "ULL)) & ((1 << ((" + std::to_string(base2 + 7ULL) + "ULL) - (" + std::to_string(base2) + "ULL) + 1)) - 1)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17034);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17047);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_shufflei0_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLEI1_SCI_B ----------------------------------------------------------
static InstructionDefinition cv_shufflei1_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_shufflei1_sci_b",
	(uint64_t) 0xc800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SHUFFLEI1_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 281);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17137);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17050);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17053, 17051, 17052);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17136);\n";
cp.code() += "{ // block\n";
etiss_uint8 base0 = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17061, 17060, 17058, 17055, 17056, 17057, 17059);\n";
etiss_uint8 base1 = (((Imm6) >> (2ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17069, 17068, 17066, 17063, 17064, 17065, 17067);\n";
etiss_uint8 base2 = (((Imm6) >> (4ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17077, 17076, 17074, 17071, 17072, 17073, 17075);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base0) + "ULL)) & ((1 << ((" + std::to_string(base0 + 7ULL) + "ULL) - (" + std::to_string(base0) + "ULL) + 1)) - 1)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17092);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base1) + "ULL)) & ((1 << ((" + std::to_string(base1 + 7ULL) + "ULL) - (" + std::to_string(base1) + "ULL) + 1)) - 1)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17107);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base2) + "ULL)) & ((1 << ((" + std::to_string(base2 + 7ULL) + "ULL) - (" + std::to_string(base2) + "ULL) + 1)) - 1)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17122);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17135);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_shufflei1_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLEI2_SCI_B ----------------------------------------------------------
static InstructionDefinition cv_shufflei2_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_shufflei2_sci_b",
	(uint64_t) 0xd000707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SHUFFLEI2_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 282);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17225);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17138);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17141, 17139, 17140);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17224);\n";
cp.code() += "{ // block\n";
etiss_uint8 base0 = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17149, 17148, 17146, 17143, 17144, 17145, 17147);\n";
etiss_uint8 base1 = (((Imm6) >> (2ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17157, 17156, 17154, 17151, 17152, 17153, 17155);\n";
etiss_uint8 base2 = (((Imm6) >> (4ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17165, 17164, 17162, 17159, 17160, 17161, 17163);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base0) + "ULL)) & ((1 << ((" + std::to_string(base0 + 7ULL) + "ULL) - (" + std::to_string(base0) + "ULL) + 1)) - 1)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17180);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base1) + "ULL)) & ((1 << ((" + std::to_string(base1 + 7ULL) + "ULL) - (" + std::to_string(base1) + "ULL) + 1)) - 1)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17195);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base2) + "ULL)) & ((1 << ((" + std::to_string(base2 + 7ULL) + "ULL) - (" + std::to_string(base2) + "ULL) + 1)) - 1)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17210);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17223);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_shufflei2_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLEI3_SCI_B ----------------------------------------------------------
static InstructionDefinition cv_shufflei3_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_shufflei3_sci_b",
	(uint64_t) 0xd800707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SHUFFLEI3_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 283);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17313);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17226);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17229, 17227, 17228);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17312);\n";
cp.code() += "{ // block\n";
etiss_uint8 base0 = ((Imm6) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17237, 17236, 17234, 17231, 17232, 17233, 17235);\n";
etiss_uint8 base1 = (((Imm6) >> (2ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17245, 17244, 17242, 17239, 17240, 17241, 17243);\n";
etiss_uint8 base2 = (((Imm6) >> (4ULL)) & 0x3ULL) * 8ULL;
cp.code() += "etiss_coverage_count(7, 17253, 17252, 17250, 17247, 17248, 17249, 17251);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base0) + "ULL)) & ((1 << ((" + std::to_string(base0 + 7ULL) + "ULL) - (" + std::to_string(base0) + "ULL) + 1)) - 1)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17268);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base1) + "ULL)) & ((1 << ((" + std::to_string(base1 + 7ULL) + "ULL) - (" + std::to_string(base1) + "ULL) + 1)) - 1)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17283);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(base2) + "ULL)) & ((1 << ((" + std::to_string(base2 + 7ULL) + "ULL) - (" + std::to_string(base2) + "ULL) + 1)) - 1)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17298);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17311);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_shufflei3_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLE2_H ---------------------------------------------------------------
static InstructionDefinition cv_shuffle2_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_shuffle2_h",
	(uint64_t) 0xe000007b,
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

		cp.code() = std::string("//CV_SHUFFLE2_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 284);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17393);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17314);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17317, 17315, 17316);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17392);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 select_lo = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (1ULL)) & 0x1ULL);\n";
cp.code() += "etiss_coverage_count(6, 17324, 17323, 17321, 17320, 17322, 17322);\n";
cp.code() += "etiss_uint8 select_hi = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (17ULL)) & 0x1ULL);\n";
cp.code() += "etiss_coverage_count(6, 17331, 17330, 17328, 17327, 17329, 17329);\n";
cp.code() += "etiss_uint8 base_lo = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x1ULL) * 16ULL;\n";
cp.code() += "etiss_coverage_count(8, 17340, 17339, 17337, 17335, 17334, 17336, 17336, 17338);\n";
cp.code() += "etiss_uint8 base_hi = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0x1ULL) * 16ULL;\n";
cp.code() += "etiss_coverage_count(8, 17349, 17348, 17346, 17344, 17343, 17345, 17345, 17347);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((select_lo) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]))) >> (base_lo)) & ((1 << ((base_lo + 15ULL) - (base_lo) + 1)) - 1)) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 17370);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((((select_hi) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]))) >> (base_hi)) & ((1 << ((base_hi + 15ULL) - (base_hi) + 1)) - 1)) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 17391);\n";
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
ss << "cv_shuffle2_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SHUFFLE2_B ---------------------------------------------------------------
static InstructionDefinition cv_shuffle2_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_shuffle2_b",
	(uint64_t) 0xe000107b,
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

		cp.code() = std::string("//CV_SHUFFLE2_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 285);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17551);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17394);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17397, 17395, 17396);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17550);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 select0 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (2ULL)) & 0x1ULL);\n";
cp.code() += "etiss_coverage_count(6, 17404, 17403, 17401, 17400, 17402, 17402);\n";
cp.code() += "etiss_uint8 select1 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (10ULL)) & 0x1ULL);\n";
cp.code() += "etiss_coverage_count(6, 17411, 17410, 17408, 17407, 17409, 17409);\n";
cp.code() += "etiss_uint8 select2 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (18ULL)) & 0x1ULL);\n";
cp.code() += "etiss_coverage_count(6, 17418, 17417, 17415, 17414, 17416, 17416);\n";
cp.code() += "etiss_uint8 select3 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (26ULL)) & 0x1ULL);\n";
cp.code() += "etiss_coverage_count(6, 17425, 17424, 17422, 17421, 17423, 17423);\n";
cp.code() += "etiss_uint8 base0 = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 17435, 17434, 17432, 17429, 17428, 17430, 17431, 17433);\n";
cp.code() += "etiss_uint8 base1 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 17445, 17444, 17442, 17439, 17438, 17440, 17441, 17443);\n";
cp.code() += "etiss_uint8 base2 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 17455, 17454, 17452, 17449, 17448, 17450, 17451, 17453);\n";
cp.code() += "etiss_uint8 base3 = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0x3ULL) * 8ULL;\n";
cp.code() += "etiss_coverage_count(8, 17465, 17464, 17462, 17459, 17458, 17460, 17461, 17463);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((((((select0) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]))) >> (base0)) & ((1 << ((base0 + 7ULL) - (base0) + 1)) - 1)) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17486);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((((((select1) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]))) >> (base1)) & ((1 << ((base1 + 7ULL) - (base1) + 1)) - 1)) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17507);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((((((select2) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]))) >> (base2)) & ((1 << ((base2 + 7ULL) - (base2) + 1)) - 1)) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17528);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((((((select3) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]))) >> (base3)) & ((1 << ((base3 + 7ULL) - (base3) + 1)) - 1)) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17549);\n";
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
ss << "cv_shuffle2_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_PACK ---------------------------------------------------------------------
static InstructionDefinition cv_pack_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_pack",
	(uint64_t) 0xf000007b,
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

		cp.code() = std::string("//CV_PACK\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 286);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17583);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17552);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17555, 17553, 17554);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17582);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 17568);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 17581);\n";
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
ss << "cv_pack" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_PACK_H -------------------------------------------------------------------
static InstructionDefinition cv_pack_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_pack_h",
	(uint64_t) 0xf200007b,
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

		cp.code() = std::string("//CV_PACK_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 287);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17615);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17584);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17587, 17585, 17586);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17614);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 17600);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 17613);\n";
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
ss << "cv_pack_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_PACKHI_B -----------------------------------------------------------------
static InstructionDefinition cv_packhi_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_packhi_b",
	(uint64_t) 0xfa00107b,
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

		cp.code() = std::string("//CV_PACKHI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 288);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17647);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17616);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17619, 17617, 17618);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17646);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17632);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17645);\n";
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
ss << "cv_packhi_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_PACKLO_B -----------------------------------------------------------------
static InstructionDefinition cv_packlo_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_packlo_b",
	(uint64_t) 0xf800107b,
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

		cp.code() = std::string("//CV_PACKLO_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 289);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17679);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17648);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17651, 17649, 17650);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17678);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17664);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17677);\n";
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
ss << "cv_packlo_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPEQ_H ------------------------------------------------------------------
static InstructionDefinition cv_cmpeq_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpeq_h",
	(uint64_t) 0x400007b,
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

		cp.code() = std::string("//CV_CMPEQ_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 290);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17735);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17680);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17683, 17681, 17682);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17734);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 17708);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) == (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 17733);\n";
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
ss << "cv_cmpeq_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPEQ_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_cmpeq_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpeq_sc_h",
	(uint64_t) 0x400407b,
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

		cp.code() = std::string("//CV_CMPEQ_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 291);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17791);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17736);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17739, 17737, 17738);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17790);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 17764);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 17789);\n";
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
ss << "cv_cmpeq_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPEQ_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_cmpeq_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpeq_sci_h",
	(uint64_t) 0x400607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPEQ_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 292);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17847);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17792);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17795, 17793, 17794);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17846);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) == " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 17820);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) == " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 17845);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpeq_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPEQ_B ------------------------------------------------------------------
static InstructionDefinition cv_cmpeq_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpeq_b",
	(uint64_t) 0x400107b,
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

		cp.code() = std::string("//CV_CMPEQ_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 293);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 17953);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17848);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17851, 17849, 17850);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 17952);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17876);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) == (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 17901);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) == (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 17926);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) == (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 17951);\n";
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
ss << "cv_cmpeq_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPEQ_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_cmpeq_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpeq_sc_b",
	(uint64_t) 0x400507b,
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

		cp.code() = std::string("//CV_CMPEQ_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 294);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18059);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 17954);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 17957, 17955, 17956);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18058);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 17982);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 18007);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 18032);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) == ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 18057);\n";
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
ss << "cv_cmpeq_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPEQ_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_cmpeq_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpeq_sci_b",
	(uint64_t) 0x400707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPEQ_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 295);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18165);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18060);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18063, 18061, 18062);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18164);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) == " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 18088);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) == " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 18113);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) == " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 18138);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) == " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 18163);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpeq_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPNE_H ------------------------------------------------------------------
static InstructionDefinition cv_cmpne_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpne_h",
	(uint64_t) 0xc00007b,
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

		cp.code() = std::string("//CV_CMPNE_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 296);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18221);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18166);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18169, 18167, 18168);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18220);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 18194);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) != (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 18219);\n";
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
ss << "cv_cmpne_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPNE_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_cmpne_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpne_sc_h",
	(uint64_t) 0xc00407b,
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

		cp.code() = std::string("//CV_CMPNE_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 297);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18277);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18222);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18225, 18223, 18224);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18276);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 18250);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 18275);\n";
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
ss << "cv_cmpne_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPNE_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_cmpne_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpne_sci_h",
	(uint64_t) 0xc00607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPNE_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 298);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18333);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18278);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18281, 18279, 18280);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18332);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) != " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 18306);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) != " + std::to_string(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 18331);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpne_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPNE_B ------------------------------------------------------------------
static InstructionDefinition cv_cmpne_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpne_b",
	(uint64_t) 0xc00107b,
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

		cp.code() = std::string("//CV_CMPNE_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 299);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18439);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18334);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18337, 18335, 18336);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18438);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 18362);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) != (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 18387);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) != (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 18412);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) != (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 18437);\n";
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
ss << "cv_cmpne_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPNE_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_cmpne_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpne_sc_b",
	(uint64_t) 0xc00507b,
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

		cp.code() = std::string("//CV_CMPNE_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 300);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18545);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18440);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18443, 18441, 18442);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18544);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 18468);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 18493);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 18518);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) != ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 18543);\n";
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
ss << "cv_cmpne_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPNE_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_cmpne_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpne_sci_b",
	(uint64_t) 0xc00707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPNE_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 301);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18651);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18546);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18549, 18547, 18548);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18650);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL) != " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 18574);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL) != " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 18599);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL) != " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 18624);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL) != " + std::to_string(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2)))))) + "ULL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 18649);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpne_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGT_H ------------------------------------------------------------------
static InstructionDefinition cv_cmpgt_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgt_h",
	(uint64_t) 0x1400007b,
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

		cp.code() = std::string("//CV_CMPGT_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 302);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18711);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18652);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18655, 18653, 18654);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18710);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 18682);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 18709);\n";
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
ss << "cv_cmpgt_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGT_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_cmpgt_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgt_sc_h",
	(uint64_t) 0x1400407b,
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

		cp.code() = std::string("//CV_CMPGT_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 303);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18771);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18712);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18715, 18713, 18714);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18770);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 18742);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 18769);\n";
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
ss << "cv_cmpgt_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGT_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_cmpgt_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgt_sci_h",
	(uint64_t) 0x1400607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGT_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 304);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18831);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18772);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18775, 18773, 18774);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18830);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 18802);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 18829);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpgt_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGT_B ------------------------------------------------------------------
static InstructionDefinition cv_cmpgt_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgt_b",
	(uint64_t) 0x1400107b,
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

		cp.code() = std::string("//CV_CMPGT_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 305);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 18945);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18832);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18835, 18833, 18834);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 18944);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 18862);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 18889);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 18916);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 18943);\n";
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
ss << "cv_cmpgt_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGT_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_cmpgt_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgt_sc_b",
	(uint64_t) 0x1400507b,
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

		cp.code() = std::string("//CV_CMPGT_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 306);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19059);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 18946);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 18949, 18947, 18948);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19058);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 18976);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 19003);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 19030);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 19057);\n";
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
ss << "cv_cmpgt_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGT_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_cmpgt_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgt_sci_b",
	(uint64_t) 0x1400707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGT_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 307);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19173);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19060);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19063, 19061, 19062);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19172);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 19090);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 19117);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 19144);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 19171);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpgt_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGE_H ------------------------------------------------------------------
static InstructionDefinition cv_cmpge_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpge_h",
	(uint64_t) 0x1c00007b,
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

		cp.code() = std::string("//CV_CMPGE_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 308);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19233);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19174);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19177, 19175, 19176);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19232);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >= (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 19204);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >= (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 19231);\n";
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
ss << "cv_cmpge_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGE_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_cmpge_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpge_sc_h",
	(uint64_t) 0x1c00407b,
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

		cp.code() = std::string("//CV_CMPGE_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 309);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19293);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19234);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19237, 19235, 19236);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19292);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >= (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 19264);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >= (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 19291);\n";
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
ss << "cv_cmpge_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGE_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_cmpge_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpge_sci_h",
	(uint64_t) 0x1c00607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGE_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 310);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19353);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19294);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19297, 19295, 19296);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19352);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >= " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 19324);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >= " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 19351);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpge_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGE_B ------------------------------------------------------------------
static InstructionDefinition cv_cmpge_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpge_b",
	(uint64_t) 0x1c00107b,
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

		cp.code() = std::string("//CV_CMPGE_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 311);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19467);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19354);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19357, 19355, 19356);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19466);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 19384);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >= (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 19411);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >= (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 19438);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >= (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 19465);\n";
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
ss << "cv_cmpge_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGE_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_cmpge_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpge_sc_b",
	(uint64_t) 0x1c00507b,
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

		cp.code() = std::string("//CV_CMPGE_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 312);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19581);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19468);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19471, 19469, 19470);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19580);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 19498);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 19525);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 19552);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 19579);\n";
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
ss << "cv_cmpge_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGE_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_cmpge_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpge_sci_b",
	(uint64_t) 0x1c00707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGE_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 313);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19695);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19582);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19585, 19583, 19584);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19694);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 19612);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 19639);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 19666);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 19693);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpge_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLT_H ------------------------------------------------------------------
static InstructionDefinition cv_cmplt_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmplt_h",
	(uint64_t) 0x2400007b,
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

		cp.code() = std::string("//CV_CMPLT_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 314);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19755);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19696);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19699, 19697, 19698);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19754);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 19726);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 19753);\n";
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
ss << "cv_cmplt_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLT_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_cmplt_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmplt_sc_h",
	(uint64_t) 0x2400407b,
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

		cp.code() = std::string("//CV_CMPLT_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 315);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19815);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19756);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19759, 19757, 19758);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19814);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 19786);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 19813);\n";
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
ss << "cv_cmplt_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLT_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_cmplt_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmplt_sci_h",
	(uint64_t) 0x2400607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLT_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 316);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19875);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19816);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19819, 19817, 19818);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19874);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 19846);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 19873);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmplt_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLT_B ------------------------------------------------------------------
static InstructionDefinition cv_cmplt_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmplt_b",
	(uint64_t) 0x2400107b,
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

		cp.code() = std::string("//CV_CMPLT_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 317);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 19989);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19876);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19879, 19877, 19878);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 19988);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 19906);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 19933);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 19960);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 19987);\n";
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
ss << "cv_cmplt_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLT_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_cmplt_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmplt_sc_b",
	(uint64_t) 0x2400507b,
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

		cp.code() = std::string("//CV_CMPLT_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 318);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20103);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 19990);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 19993, 19991, 19992);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20102);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 20020);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 20047);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 20074);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 20101);\n";
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
ss << "cv_cmplt_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLT_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_cmplt_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmplt_sci_b",
	(uint64_t) 0x2400707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLT_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 319);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20217);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20104);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20107, 20105, 20106);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20216);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 20134);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 20161);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 20188);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 20215);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmplt_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLE_H ------------------------------------------------------------------
static InstructionDefinition cv_cmple_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmple_h",
	(uint64_t) 0x2c00007b,
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

		cp.code() = std::string("//CV_CMPLE_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 320);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20277);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20218);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20221, 20219, 20220);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20276);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) <= (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 20248);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) <= (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 20275);\n";
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
ss << "cv_cmple_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLE_SC_H ---------------------------------------------------------------
static InstructionDefinition cv_cmple_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmple_sc_h",
	(uint64_t) 0x2c00407b,
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

		cp.code() = std::string("//CV_CMPLE_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 321);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20337);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20278);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20281, 20279, 20280);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20336);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) <= (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 20308);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) <= (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 20335);\n";
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
ss << "cv_cmple_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLE_SCI_H --------------------------------------------------------------
static InstructionDefinition cv_cmple_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmple_sci_h",
	(uint64_t) 0x2c00607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLE_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 322);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20397);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20338);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20341, 20339, 20340);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20396);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) <= " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 20368);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) <= " + std::to_string((etiss_int16)(((etiss_uint16)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 20395);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmple_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLE_B ------------------------------------------------------------------
static InstructionDefinition cv_cmple_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmple_b",
	(uint64_t) 0x2c00107b,
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

		cp.code() = std::string("//CV_CMPLE_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 323);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20511);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20398);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20401, 20399, 20400);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20510);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) <= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 20428);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) <= (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 20455);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) <= (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 20482);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) <= (etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 20509);\n";
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
ss << "cv_cmple_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLE_SC_B ---------------------------------------------------------------
static InstructionDefinition cv_cmple_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmple_sc_b",
	(uint64_t) 0x2c00507b,
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

		cp.code() = std::string("//CV_CMPLE_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 324);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20625);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20512);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20515, 20513, 20514);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20624);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) <= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 20542);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) <= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 20569);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) <= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 20596);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) <= (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 20623);\n";
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
ss << "cv_cmple_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLE_SCI_B --------------------------------------------------------------
static InstructionDefinition cv_cmple_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmple_sci_b",
	(uint64_t) 0x2c00707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLE_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 325);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20739);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20626);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20629, 20627, 20628);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20738);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) <= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 20656);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) <= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 20683);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) <= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 20710);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_int8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) <= " + std::to_string((etiss_int8)(((etiss_uint8)((((etiss_int8)(((etiss_int8)Imm6) << (2)) >> (2))))))) + "LL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 20737);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmple_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGTU_H -----------------------------------------------------------------
static InstructionDefinition cv_cmpgtu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgtu_h",
	(uint64_t) 0x3400007b,
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

		cp.code() = std::string("//CV_CMPGTU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 326);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20799);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20740);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20743, 20741, 20742);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20798);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 20770);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 20797);\n";
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
ss << "cv_cmpgtu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGTU_SC_H --------------------------------------------------------------
static InstructionDefinition cv_cmpgtu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgtu_sc_h",
	(uint64_t) 0x3400407b,
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

		cp.code() = std::string("//CV_CMPGTU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 327);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20859);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20800);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20803, 20801, 20802);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20858);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 20830);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 20857);\n";
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
ss << "cv_cmpgtu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGTU_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_cmpgtu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgtu_sci_h",
	(uint64_t) 0x3400607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGTU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 328);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 20915);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20860);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20863, 20861, 20862);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 20914);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) > " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 20888);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) > " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 20913);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpgtu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGTU_B -----------------------------------------------------------------
static InstructionDefinition cv_cmpgtu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgtu_b",
	(uint64_t) 0x3400107b,
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

		cp.code() = std::string("//CV_CMPGTU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 329);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21029);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 20916);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 20919, 20917, 20918);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21028);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 20946);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 20973);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 21000);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 21027);\n";
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
ss << "cv_cmpgtu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGTU_SC_B --------------------------------------------------------------
static InstructionDefinition cv_cmpgtu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgtu_sc_b",
	(uint64_t) 0x3400507b,
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

		cp.code() = std::string("//CV_CMPGTU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 330);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21143);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21030);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21033, 21031, 21032);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21142);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 21060);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 21087);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 21114);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 21141);\n";
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
ss << "cv_cmpgtu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGTU_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_cmpgtu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgtu_sci_b",
	(uint64_t) 0x3400707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGTU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 331);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21249);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21144);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21147, 21145, 21146);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21248);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 21172);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 21197);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 21222);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) > " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 21247);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpgtu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGEU_H -----------------------------------------------------------------
static InstructionDefinition cv_cmpgeu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgeu_h",
	(uint64_t) 0x3c00007b,
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

		cp.code() = std::string("//CV_CMPGEU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 332);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21309);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21250);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21253, 21251, 21252);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21308);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >= (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 21280);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >= (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 21307);\n";
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
ss << "cv_cmpgeu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGEU_SC_H --------------------------------------------------------------
static InstructionDefinition cv_cmpgeu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgeu_sc_h",
	(uint64_t) 0x3c00407b,
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

		cp.code() = std::string("//CV_CMPGEU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 333);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21369);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21310);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21313, 21311, 21312);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21368);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >= (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 21340);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >= (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 21367);\n";
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
ss << "cv_cmpgeu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGEU_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_cmpgeu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgeu_sci_h",
	(uint64_t) 0x3c00607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGEU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 334);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21425);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21370);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21373, 21371, 21372);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21424);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) >= " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 21398);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) >= " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 21423);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpgeu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGEU_B -----------------------------------------------------------------
static InstructionDefinition cv_cmpgeu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgeu_b",
	(uint64_t) 0x3c00107b,
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

		cp.code() = std::string("//CV_CMPGEU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 335);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21539);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21426);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21429, 21427, 21428);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21538);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 21456);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >= (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 21483);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >= (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 21510);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >= (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 21537);\n";
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
ss << "cv_cmpgeu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGEU_SC_B --------------------------------------------------------------
static InstructionDefinition cv_cmpgeu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgeu_sc_b",
	(uint64_t) 0x3c00507b,
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

		cp.code() = std::string("//CV_CMPGEU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 336);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21653);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21540);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21543, 21541, 21542);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21652);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 21570);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 21597);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 21624);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 21651);\n";
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
ss << "cv_cmpgeu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPGEU_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_cmpgeu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpgeu_sci_b",
	(uint64_t) 0x3c00707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPGEU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 337);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21759);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21654);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21657, 21655, 21656);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21758);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) >= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 21682);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) >= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 21707);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) >= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 21732);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) >= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 21757);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpgeu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLTU_H -----------------------------------------------------------------
static InstructionDefinition cv_cmpltu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpltu_h",
	(uint64_t) 0x4400007b,
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

		cp.code() = std::string("//CV_CMPLTU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 338);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21819);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21760);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21763, 21761, 21762);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21818);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 21790);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 21817);\n";
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
ss << "cv_cmpltu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLTU_SC_H --------------------------------------------------------------
static InstructionDefinition cv_cmpltu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpltu_sc_h",
	(uint64_t) 0x4400407b,
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

		cp.code() = std::string("//CV_CMPLTU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 339);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21879);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21820);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21823, 21821, 21822);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21878);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 21850);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 21877);\n";
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
ss << "cv_cmpltu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLTU_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_cmpltu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpltu_sci_h",
	(uint64_t) 0x4400607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLTU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 340);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 21935);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21880);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21883, 21881, 21882);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 21934);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) < " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 21908);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) < " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 21933);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpltu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLTU_B -----------------------------------------------------------------
static InstructionDefinition cv_cmpltu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpltu_b",
	(uint64_t) 0x4400107b,
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

		cp.code() = std::string("//CV_CMPLTU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 341);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22049);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 21936);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 21939, 21937, 21938);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22048);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 21966);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 21993);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 22020);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 22047);\n";
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
ss << "cv_cmpltu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLTU_SC_B --------------------------------------------------------------
static InstructionDefinition cv_cmpltu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpltu_sc_b",
	(uint64_t) 0x4400507b,
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

		cp.code() = std::string("//CV_CMPLTU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 342);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22163);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22050);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22053, 22051, 22052);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22162);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 22080);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 22107);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 22134);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 22161);\n";
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
ss << "cv_cmpltu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLTU_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_cmpltu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpltu_sci_b",
	(uint64_t) 0x4400707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLTU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 343);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22269);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22164);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22167, 22165, 22166);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22268);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 22192);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 22217);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 22242);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) < " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 22267);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpltu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLEU_H -----------------------------------------------------------------
static InstructionDefinition cv_cmpleu_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpleu_h",
	(uint64_t) 0x4c00007b,
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

		cp.code() = std::string("//CV_CMPLEU_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 344);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22329);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22270);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22273, 22271, 22272);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22328);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) <= (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22300);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) <= (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 22327);\n";
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
ss << "cv_cmpleu_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLEU_SC_H --------------------------------------------------------------
static InstructionDefinition cv_cmpleu_sc_h_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpleu_sc_h",
	(uint64_t) 0x4c00407b,
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

		cp.code() = std::string("//CV_CMPLEU_SC_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 345);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22389);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22330);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22333, 22331, 22332);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22388);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) <= (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22360);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) <= (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)))))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 22387);\n";
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
ss << "cv_cmpleu_sc_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLEU_SCI_H -------------------------------------------------------------
static InstructionDefinition cv_cmpleu_sci_h_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpleu_sci_h",
	(uint64_t) 0x4c00607b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLEU_SCI_H\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 346);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22445);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22390);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22393, 22391, 22392);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22444);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) <= " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22418);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((etiss_uint16)(((etiss_int16)(((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) <= " + std::to_string((etiss_uint16)(((etiss_uint16)(Imm6)))) + "ULL)))) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 22443);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpleu_sci_h" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLEU_B -----------------------------------------------------------------
static InstructionDefinition cv_cmpleu_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpleu_b",
	(uint64_t) 0x4c00107b,
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

		cp.code() = std::string("//CV_CMPLEU_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 347);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22559);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22446);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22449, 22447, 22448);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22558);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) <= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 22476);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) <= (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (8ULL)) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 22503);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) <= (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 22530);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) <= (etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (24ULL)) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 22557);\n";
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
ss << "cv_cmpleu_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLEU_SC_B --------------------------------------------------------------
static InstructionDefinition cv_cmpleu_sc_b_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cmpleu_sc_b",
	(uint64_t) 0x4c00507b,
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

		cp.code() = std::string("//CV_CMPLEU_SC_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 348);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22673);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22560);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22563, 22561, 22562);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22672);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) <= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 22590);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) <= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 22617);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) <= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 22644);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) <= (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffULL)))))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 22671);\n";
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
ss << "cv_cmpleu_sc_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CMPLEU_SCI_B -------------------------------------------------------------
static InstructionDefinition cv_cmpleu_sci_b_rd_rs1_Imm6 (
	ISA32_RV32IMXCoreV,
	"cv_cmpleu_sci_b",
	(uint64_t) 0x4c00707b,
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CMPLEU_SCI_B\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 349);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22779);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22674);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22677, 22675, 22676);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22778);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709551360U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL)) <= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 0LL) & 255U));\n";
cp.code() += "etiss_coverage_count(1, 22702);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486335U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (8ULL)) & 0xffULL)) <= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 8ULL) & 65280U));\n";
cp.code() += "etiss_coverage_count(1, 22727);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073692839935U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffULL)) <= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 16ULL) & 16711680U));\n";
cp.code() += "etiss_coverage_count(1, 22752);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069431361535U)) | (((etiss_uint8)(((etiss_int8)(((etiss_uint8)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (24ULL)) & 0xffULL)) <= " + std::to_string((etiss_uint8)(((etiss_uint8)(Imm6)))) + "ULL)))) << 24ULL) & 4278190080U));\n";
cp.code() += "etiss_coverage_count(1, 22777);\n";
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
etiss_uint8 Imm6 = 0;
static BitArrayRange R_Imm6_1(24, 20);
Imm6 += R_Imm6_1.read(ba) << 1;
static BitArrayRange R_Imm6_0(25, 25);
Imm6 += R_Imm6_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cmpleu_sci_b" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Imm6=" + std::to_string(Imm6) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_R ----------------------------------------------------------------
static InstructionDefinition cv_cplxmul_r_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_r",
	(uint64_t) 0x5400007b,
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

		cp.code() = std::string("//CV_CPLXMUL_R\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 350);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22830);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22780);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22783, 22781, 22782);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22829);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 15ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22828);\n";
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
ss << "cv_cplxmul_r" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_R_DIV2 -----------------------------------------------------------
static InstructionDefinition cv_cplxmul_r_div2_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_r_div2",
	(uint64_t) 0x5400207b,
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

		cp.code() = std::string("//CV_CPLXMUL_R_DIV2\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 351);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22881);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22831);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22834, 22832, 22833);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22880);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 16ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22879);\n";
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
ss << "cv_cplxmul_r_div2" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_R_DIV4 -----------------------------------------------------------
static InstructionDefinition cv_cplxmul_r_div4_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_r_div4",
	(uint64_t) 0x5400407b,
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

		cp.code() = std::string("//CV_CPLXMUL_R_DIV4\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 352);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22932);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22882);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22885, 22883, 22884);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22931);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 17ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22930);\n";
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
ss << "cv_cplxmul_r_div4" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_R_DIV8 -----------------------------------------------------------
static InstructionDefinition cv_cplxmul_r_div8_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_r_div8",
	(uint64_t) 0x5400607b,
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

		cp.code() = std::string("//CV_CPLXMUL_R_DIV8\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 353);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22983);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22933);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22936, 22934, 22935);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22982);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 18ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 22981);\n";
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
ss << "cv_cplxmul_r_div8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_I ----------------------------------------------------------------
static InstructionDefinition cv_cplxmul_i_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_i",
	(uint64_t) 0x5600007b,
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

		cp.code() = std::string("//CV_CPLXMUL_I\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 354);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23034);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 22984);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 22987, 22985, 22986);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23033);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 15ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23032);\n";
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
ss << "cv_cplxmul_i" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_I_DIV2 -----------------------------------------------------------
static InstructionDefinition cv_cplxmul_i_div2_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_i_div2",
	(uint64_t) 0x5600207b,
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

		cp.code() = std::string("//CV_CPLXMUL_I_DIV2\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 355);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23085);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23035);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23038, 23036, 23037);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23084);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 16ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23083);\n";
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
ss << "cv_cplxmul_i_div2" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_I_DIV4 -----------------------------------------------------------
static InstructionDefinition cv_cplxmul_i_div4_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_i_div4",
	(uint64_t) 0x5600407b,
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

		cp.code() = std::string("//CV_CPLXMUL_I_DIV4\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 356);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23136);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23086);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23089, 23087, 23088);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23135);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 17ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23134);\n";
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
ss << "cv_cplxmul_i_div4" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXMUL_I_DIV8 -----------------------------------------------------------
static InstructionDefinition cv_cplxmul_i_div8_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_cplxmul_i_div8",
	(uint64_t) 0x5600607b,
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

		cp.code() = std::string("//CV_CPLXMUL_I_DIV8\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 357);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23187);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23137);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23140, 23138, 23139);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23186);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) - (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 18ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23185);\n";
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
ss << "cv_cplxmul_i_div8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CPLXCONJ -----------------------------------------------------------------
static InstructionDefinition cv_cplxconj_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_cplxconj",
	(uint64_t) 0x5c00007b,
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

		cp.code() = std::string("//CV_CPLXCONJ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 358);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23224);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23188);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23191, 23189, 23190);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23223);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23204);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((-((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23222);\n";
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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cplxconj" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBROTMJ -----------------------------------------------------------------
static InstructionDefinition cv_subrotmj_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subrotmj",
	(uint64_t) 0x6400007b,
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

		cp.code() = std::string("//CV_SUBROTMJ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 359);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23254);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23225);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23228, 23226, 23227);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23253);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | (((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23252);\n";
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
ss << "cv_subrotmj" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBROTMJ_DIV2 ------------------------------------------------------------
static InstructionDefinition cv_subrotmj_div2_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subrotmj_div2",
	(uint64_t) 0x6400207b,
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

		cp.code() = std::string("//CV_SUBROTMJ_DIV2\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 360);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23292);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23255);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23258, 23256, 23257);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23291);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23290);\n";
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
ss << "cv_subrotmj_div2" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBROTMJ_DIV4 ------------------------------------------------------------
static InstructionDefinition cv_subrotmj_div4_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subrotmj_div4",
	(uint64_t) 0x6400407b,
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

		cp.code() = std::string("//CV_SUBROTMJ_DIV4\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 361);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23330);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23293);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23296, 23294, 23295);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23329);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL))) >> 2ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23328);\n";
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
ss << "cv_subrotmj_div4" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBROTMJ_DIV8 ------------------------------------------------------------
static InstructionDefinition cv_subrotmj_div8_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subrotmj_div8",
	(uint64_t) 0x6400607b,
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

		cp.code() = std::string("//CV_SUBROTMJ_DIV8\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 362);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23368);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23331);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23334, 23332, 23333);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23367);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL))) & 0xffffULL))) >> 3ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23366);\n";
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
ss << "cv_subrotmj_div8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_DIV2 -----------------------------------------------------------------
static InstructionDefinition cv_add_div2_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_div2",
	(uint64_t) 0x6c00207b,
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

		cp.code() = std::string("//CV_ADD_DIV2\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 363);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23430);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23369);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23372, 23370, 23371);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23429);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23400);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23428);\n";
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
ss << "cv_add_div2" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_DIV4 -----------------------------------------------------------------
static InstructionDefinition cv_add_div4_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_div4",
	(uint64_t) 0x6c00407b,
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

		cp.code() = std::string("//CV_ADD_DIV4\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 364);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23492);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23431);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23434, 23432, 23433);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23491);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 2ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23462);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 2ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23490);\n";
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
ss << "cv_add_div4" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADD_DIV8 -----------------------------------------------------------------
static InstructionDefinition cv_add_div8_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_add_div8",
	(uint64_t) 0x6c00607b,
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

		cp.code() = std::string("//CV_ADD_DIV8\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 365);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23554);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23493);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23496, 23494, 23495);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23553);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 3ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23524);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) + (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 3ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23552);\n";
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
ss << "cv_add_div8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_DIV2 -----------------------------------------------------------------
static InstructionDefinition cv_sub_div2_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_div2",
	(uint64_t) 0x7400207b,
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

		cp.code() = std::string("//CV_SUB_DIV2\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 366);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23616);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23555);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23558, 23556, 23557);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23615);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23586);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 1ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23614);\n";
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
ss << "cv_sub_div2" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_DIV4 -----------------------------------------------------------------
static InstructionDefinition cv_sub_div4_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_div4",
	(uint64_t) 0x7400407b,
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

		cp.code() = std::string("//CV_SUB_DIV4\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 367);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23678);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23617);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23620, 23618, 23619);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23677);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 2ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23648);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 2ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23676);\n";
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
ss << "cv_sub_div4" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUB_DIV8 -----------------------------------------------------------------
static InstructionDefinition cv_sub_div8_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sub_div8",
	(uint64_t) 0x7400607b,
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

		cp.code() = std::string("//CV_SUB_DIV8\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 368);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23740);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23679);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23682, 23680, 23681);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23739);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744073709486080U)) | ((((((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL) - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> 3ULL)) & 0xffffULL) << 0LL) & 65535U));\n";
cp.code() += "etiss_coverage_count(1, 23710);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) & (18446744069414649855U)) | ((((((etiss_int16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL) - (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> 3ULL)) & 0xffffULL) << 16ULL) & 4294901760U));\n";
cp.code() += "etiss_coverage_count(1, 23738);\n";
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
ss << "cv_sub_div8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
