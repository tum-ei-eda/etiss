// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
 *
 * This file contains the instruction behavior models of the XCoreVMac
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_MULUN --------------------------------------------------------------------
static InstructionDefinition cv_mulun_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulun",
	(uint64_t) 0x00505b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULUN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 443);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26510);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26497, 26496, 26493, 26485, 26484, 26481, 26480, 26482, 26483, 26492, 26491, 26488, 26487, 26489, 26490, 26494, 26495);\n";
cp.code() += "etiss_coverage_count(1, 26498);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26501, 26499, 26500);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26509, 26504, 26503, 26508, 26505, 26506, 26507);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulun" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULHHUN ------------------------------------------------------------------
static InstructionDefinition cv_mulhhun_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulhhun",
	(uint64_t) 0x4000505b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULHHUN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 444);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26543);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26530, 26529, 26526, 26518, 26517, 26514, 26513, 26515, 26516, 26525, 26524, 26521, 26520, 26522, 26523, 26527, 26528);\n";
cp.code() += "etiss_coverage_count(1, 26531);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26534, 26532, 26533);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26542, 26537, 26536, 26541, 26538, 26539, 26540);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulhhun" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULSN --------------------------------------------------------------------
static InstructionDefinition cv_mulsn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulsn",
	(uint64_t) 0x00405b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULSN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 445);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26576);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26563, 26562, 26559, 26551, 26550, 26547, 26546, 26548, 26549, 26558, 26557, 26554, 26553, 26555, 26556, 26560, 26561);\n";
cp.code() += "etiss_coverage_count(1, 26564);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26567, 26565, 26566);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26575, 26570, 26569, 26574, 26571, 26572, 26573);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulsn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULHHSN ------------------------------------------------------------------
static InstructionDefinition cv_mulhhsn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulhhsn",
	(uint64_t) 0x4000405b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULHHSN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 446);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26609);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26596, 26595, 26592, 26584, 26583, 26580, 26579, 26581, 26582, 26591, 26590, 26587, 26586, 26588, 26589, 26593, 26594);\n";
cp.code() += "etiss_coverage_count(1, 26597);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26600, 26598, 26599);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26608, 26603, 26602, 26607, 26604, 26605, 26606);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulhhsn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULURN -------------------------------------------------------------------
static InstructionDefinition cv_mulurn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulurn",
	(uint64_t) 0x8000505b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULURN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 447);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26653);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26626, 26625, 26617, 26616, 26613, 26612, 26614, 26615, 26624, 26623, 26620, 26619, 26621, 26622);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26634, 26633, 26628, 26631, 26629, 26630, 26632);\n";
cp.code() += "etiss_uint32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26639, 26638, 26636, 26637);\n";
cp.code() += "etiss_uint32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26644, 26643, 26641, 26642);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26652, 26647, 26646, 26651, 26648, 26649, 26650);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulurn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULHHURN -----------------------------------------------------------------
static InstructionDefinition cv_mulhhurn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulhhurn",
	(uint64_t) 0xc000505b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULHHURN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 448);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26697);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26670, 26669, 26661, 26660, 26657, 26656, 26658, 26659, 26668, 26667, 26664, 26663, 26665, 26666);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26678, 26677, 26672, 26675, 26673, 26674, 26676);\n";
cp.code() += "etiss_uint32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26683, 26682, 26680, 26681);\n";
cp.code() += "etiss_uint32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26688, 26687, 26685, 26686);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26696, 26691, 26690, 26695, 26692, 26693, 26694);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulhhurn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULSRN -------------------------------------------------------------------
static InstructionDefinition cv_mulsrn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulsrn",
	(uint64_t) 0x8000405b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULSRN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 449);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26741);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26714, 26713, 26705, 26704, 26701, 26700, 26702, 26703, 26712, 26711, 26708, 26707, 26709, 26710);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26722, 26721, 26716, 26719, 26717, 26718, 26720);\n";
cp.code() += "etiss_int32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26727, 26726, 26724, 26725);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26732, 26731, 26729, 26730);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26740, 26735, 26734, 26739, 26736, 26737, 26738);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulsrn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MULHHSRN -----------------------------------------------------------------
static InstructionDefinition cv_mulhhsrn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_mulhhsrn",
	(uint64_t) 0xc000405b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MULHHSRN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 450);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26785);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26758, 26757, 26749, 26748, 26745, 26744, 26746, 26747, 26756, 26755, 26752, 26751, 26753, 26754);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26766, 26765, 26760, 26763, 26761, 26762, 26764);\n";
cp.code() += "etiss_int32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26771, 26770, 26768, 26769);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26776, 26775, 26773, 26774);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26784, 26779, 26778, 26783, 26780, 26781, 26782);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_mulhhsrn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACUN --------------------------------------------------------------------
static InstructionDefinition cv_macun_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_macun",
	(uint64_t) 0x00705b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACUN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 451);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26823);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26810, 26809, 26806, 26801, 26793, 26792, 26789, 26788, 26790, 26791, 26800, 26799, 26796, 26795, 26797, 26798, 26805, 26804, 26803, 26807, 26808);\n";
cp.code() += "etiss_coverage_count(1, 26811);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26814, 26812, 26813);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26822, 26817, 26816, 26821, 26818, 26819, 26820);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_macun" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACHHUN ------------------------------------------------------------------
static InstructionDefinition cv_machhun_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_machhun",
	(uint64_t) 0x4000705b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACHHUN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 452);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26861);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26848, 26847, 26844, 26839, 26831, 26830, 26827, 26826, 26828, 26829, 26838, 26837, 26834, 26833, 26835, 26836, 26843, 26842, 26841, 26845, 26846);\n";
cp.code() += "etiss_coverage_count(1, 26849);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26852, 26850, 26851);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26860, 26855, 26854, 26859, 26856, 26857, 26858);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_machhun" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACSN --------------------------------------------------------------------
static InstructionDefinition cv_macsn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_macsn",
	(uint64_t) 0x8000105b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACSN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 453);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26899);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26886, 26885, 26882, 26877, 26869, 26868, 26865, 26864, 26866, 26867, 26876, 26875, 26872, 26871, 26873, 26874, 26881, 26880, 26879, 26883, 26884);\n";
cp.code() += "etiss_coverage_count(1, 26887);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26890, 26888, 26889);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26898, 26893, 26892, 26897, 26894, 26895, 26896);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_macsn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACHHSN ------------------------------------------------------------------
static InstructionDefinition cv_machhsn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_machhsn",
	(uint64_t) 0xc000105b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACHHSN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 454);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26937);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26924, 26923, 26920, 26915, 26907, 26906, 26903, 26902, 26904, 26905, 26914, 26913, 26910, 26909, 26911, 26912, 26919, 26918, 26917, 26921, 26922);\n";
cp.code() += "etiss_coverage_count(1, 26925);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26928, 26926, 26927);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26936, 26931, 26930, 26935, 26932, 26933, 26934);\n";
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_machhsn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACURN -------------------------------------------------------------------
static InstructionDefinition cv_macurn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_macurn",
	(uint64_t) 0x8000605b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACURN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 455);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26988);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 product = (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL))) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)));\n";
cp.code() += "etiss_coverage_count(16, 26956, 26955, 26946, 26944, 26941, 26940, 26942, 26943, 26945, 26954, 26952, 26949, 26948, 26950, 26951, 26953);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26964, 26963, 26958, 26961, 26959, 26960, 26962);\n";
cp.code() += "etiss_uint64 sum = product + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 26974, 26973, 26971, 26966, 26970, 26969, 26968, 26972);\n";
cp.code() += "etiss_uint64 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26979, 26978, 26976, 26977);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26987, 26982, 26981, 26986, 26983, 26984, 26985);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_macurn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACHHURN -----------------------------------------------------------------
static InstructionDefinition cv_machhurn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_machhurn",
	(uint64_t) 0xc000605b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACHHURN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 456);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27039);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 product = (etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL))) * (etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)));\n";
cp.code() += "etiss_coverage_count(16, 27007, 27006, 26997, 26995, 26992, 26991, 26993, 26994, 26996, 27005, 27003, 27000, 26999, 27001, 27002, 27004);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 27015, 27014, 27009, 27012, 27010, 27011, 27013);\n";
cp.code() += "etiss_uint64 sum = product + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 27025, 27024, 27022, 27017, 27021, 27020, 27019, 27023);\n";
cp.code() += "etiss_uint64 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 27030, 27029, 27027, 27028);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 27038, 27033, 27032, 27037, 27034, 27035, 27036);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_machhurn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACSRN -------------------------------------------------------------------
static InstructionDefinition cv_macsrn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_macsrn",
	(uint64_t) 0x8000705b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACSRN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 457);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27088);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 27056, 27055, 27047, 27046, 27043, 27042, 27044, 27045, 27054, 27053, 27050, 27049, 27051, 27052);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 27064, 27063, 27058, 27061, 27059, 27060, 27062);\n";
cp.code() += "etiss_int32 sum = product + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 27074, 27073, 27071, 27066, 27070, 27069, 27068, 27072);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 27079, 27078, 27076, 27077);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 27087, 27082, 27081, 27086, 27083, 27084, 27085);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_macsrn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MACHHSRN -----------------------------------------------------------------
static InstructionDefinition cv_machhsrn_rd_rs1_rs2_Is3 (
	ISA32_RV32IMXCoreV,
	"cv_machhsrn",
	(uint64_t) 0xc000705b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_MACHHSRN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 458);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27137);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 27105, 27104, 27096, 27095, 27092, 27091, 27093, 27094, 27103, 27102, 27099, 27098, 27100, 27101);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 27113, 27112, 27107, 27110, 27108, 27109, 27111);\n";
cp.code() += "etiss_int32 sum = product + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 27123, 27122, 27120, 27115, 27119, 27118, 27117, 27121);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 27128, 27127, 27125, 27126);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 27136, 27131, 27130, 27135, 27132, 27133, 27134);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
etiss_uint8 Is3 = 0;
static BitArrayRange R_Is3_0(29, 25);
Is3 += R_Is3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_machhsrn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Is3=" + std::to_string(Is3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
