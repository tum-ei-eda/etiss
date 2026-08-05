// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
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
cp.code() += "etiss_coverage_count(1, 26508);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26495, 26494, 26491, 26483, 26482, 26479, 26478, 26480, 26481, 26490, 26489, 26486, 26485, 26487, 26488, 26492, 26493);\n";
cp.code() += "etiss_coverage_count(1, 26496);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26499, 26497, 26498);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26507, 26502, 26501, 26506, 26503, 26504, 26505);\n";
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
cp.code() += "etiss_coverage_count(1, 26541);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26528, 26527, 26524, 26516, 26515, 26512, 26511, 26513, 26514, 26523, 26522, 26519, 26518, 26520, 26521, 26525, 26526);\n";
cp.code() += "etiss_coverage_count(1, 26529);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26532, 26530, 26531);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26540, 26535, 26534, 26539, 26536, 26537, 26538);\n";
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
cp.code() += "etiss_coverage_count(1, 26574);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26561, 26560, 26557, 26549, 26548, 26545, 26544, 26546, 26547, 26556, 26555, 26552, 26551, 26553, 26554, 26558, 26559);\n";
cp.code() += "etiss_coverage_count(1, 26562);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26565, 26563, 26564);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26573, 26568, 26567, 26572, 26569, 26570, 26571);\n";
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
cp.code() += "etiss_coverage_count(1, 26607);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL))) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(17, 26594, 26593, 26590, 26582, 26581, 26578, 26577, 26579, 26580, 26589, 26588, 26585, 26584, 26586, 26587, 26591, 26592);\n";
cp.code() += "etiss_coverage_count(1, 26595);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26598, 26596, 26597);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26606, 26601, 26600, 26605, 26602, 26603, 26604);\n";
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
cp.code() += "etiss_coverage_count(1, 26651);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26624, 26623, 26615, 26614, 26611, 26610, 26612, 26613, 26622, 26621, 26618, 26617, 26619, 26620);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26632, 26631, 26626, 26629, 26627, 26628, 26630);\n";
cp.code() += "etiss_uint32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26637, 26636, 26634, 26635);\n";
cp.code() += "etiss_uint32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26642, 26641, 26639, 26640);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26650, 26645, 26644, 26649, 26646, 26647, 26648);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 26695);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26668, 26667, 26659, 26658, 26655, 26654, 26656, 26657, 26666, 26665, 26662, 26661, 26663, 26664);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26676, 26675, 26670, 26673, 26671, 26672, 26674);\n";
cp.code() += "etiss_uint32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26681, 26680, 26678, 26679);\n";
cp.code() += "etiss_uint32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26686, 26685, 26683, 26684);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26694, 26689, 26688, 26693, 26690, 26691, 26692);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 26739);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26712, 26711, 26703, 26702, 26699, 26698, 26700, 26701, 26710, 26709, 26706, 26705, 26707, 26708);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26720, 26719, 26714, 26717, 26715, 26716, 26718);\n";
cp.code() += "etiss_int32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26725, 26724, 26722, 26723);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26730, 26729, 26727, 26728);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26738, 26733, 26732, 26737, 26734, 26735, 26736);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 26783);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 26756, 26755, 26747, 26746, 26743, 26742, 26744, 26745, 26754, 26753, 26750, 26749, 26751, 26752);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26764, 26763, 26758, 26761, 26759, 26760, 26762);\n";
cp.code() += "etiss_int32 sum = product + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26769, 26768, 26766, 26767);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26774, 26773, 26771, 26772);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26782, 26777, 26776, 26781, 26778, 26779, 26780);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 26821);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26808, 26807, 26804, 26799, 26791, 26790, 26787, 26786, 26788, 26789, 26798, 26797, 26794, 26793, 26795, 26796, 26803, 26802, 26801, 26805, 26806);\n";
cp.code() += "etiss_coverage_count(1, 26809);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26812, 26810, 26811);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26820, 26815, 26814, 26819, 26816, 26817, 26818);\n";
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
cp.code() += "etiss_coverage_count(1, 26859);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 result = ((etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26846, 26845, 26842, 26837, 26829, 26828, 26825, 26824, 26826, 26827, 26836, 26835, 26832, 26831, 26833, 26834, 26841, 26840, 26839, 26843, 26844);\n";
cp.code() += "etiss_coverage_count(1, 26847);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26850, 26848, 26849);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26858, 26853, 26852, 26857, 26854, 26855, 26856);\n";
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
cp.code() += "etiss_coverage_count(1, 26897);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)) + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26884, 26883, 26880, 26875, 26867, 26866, 26863, 26862, 26864, 26865, 26874, 26873, 26870, 26869, 26871, 26872, 26879, 26878, 26877, 26881, 26882);\n";
cp.code() += "etiss_coverage_count(1, 26885);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26888, 26886, 26887);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26896, 26891, 26890, 26895, 26892, 26893, 26894);\n";
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
cp.code() += "etiss_coverage_count(1, 26935);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 result = ((etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)) + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL])) >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(21, 26922, 26921, 26918, 26913, 26905, 26904, 26901, 26900, 26902, 26903, 26912, 26911, 26908, 26907, 26909, 26910, 26917, 26916, 26915, 26919, 26920);\n";
cp.code() += "etiss_coverage_count(1, 26923);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26926, 26924, 26925);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((result) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26934, 26929, 26928, 26933, 26930, 26931, 26932);\n";
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
cp.code() += "etiss_coverage_count(1, 26986);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 product = (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL))) * (etiss_uint16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL)));\n";
cp.code() += "etiss_coverage_count(16, 26954, 26953, 26944, 26942, 26939, 26938, 26940, 26941, 26943, 26952, 26950, 26947, 26946, 26948, 26949, 26951);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 26962, 26961, 26956, 26959, 26957, 26958, 26960);\n";
cp.code() += "etiss_uint64 sum = product + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 26972, 26971, 26969, 26964, 26968, 26967, 26966, 26970);\n";
cp.code() += "etiss_uint64 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 26977, 26976, 26974, 26975);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 26985, 26980, 26979, 26984, 26981, 26982, 26983);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 27037);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 product = (etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL))) * (etiss_uint16)(((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL)));\n";
cp.code() += "etiss_coverage_count(16, 27005, 27004, 26995, 26993, 26990, 26989, 26991, 26992, 26994, 27003, 27001, 26998, 26997, 26999, 27000, 27002);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 27013, 27012, 27007, 27010, 27008, 27009, 27011);\n";
cp.code() += "etiss_uint64 sum = product + (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 27023, 27022, 27020, 27015, 27019, 27018, 27017, 27021);\n";
cp.code() += "etiss_uint64 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 27028, 27027, 27025, 27026);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 27036, 27031, 27030, 27035, 27032, 27033, 27034);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 27086);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL)) * (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 27054, 27053, 27045, 27044, 27041, 27040, 27042, 27043, 27052, 27051, 27048, 27047, 27049, 27050);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 27062, 27061, 27056, 27059, 27057, 27058, 27060);\n";
cp.code() += "etiss_int32 sum = product + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 27072, 27071, 27069, 27064, 27068, 27067, 27066, 27070);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 27077, 27076, 27074, 27075);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 27085, 27080, 27079, 27084, 27081, 27082, 27083);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
cp.code() += "etiss_coverage_count(1, 27135);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 product = (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (16ULL)) & 0xffffULL)) * (etiss_int16)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (16ULL)) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(14, 27103, 27102, 27094, 27093, 27090, 27089, 27091, 27092, 27101, 27100, 27097, 27096, 27098, 27099);\n";
etiss_uint32 powerOf2 = 1ULL << (Is3 - 1ULL);
cp.code() += "etiss_coverage_count(7, 27111, 27110, 27105, 27108, 27106, 27107, 27109);\n";
cp.code() += "etiss_int32 sum = product + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL]) + " + std::to_string(powerOf2) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 27121, 27120, 27118, 27113, 27117, 27116, 27115, 27119);\n";
cp.code() += "etiss_int32 rounded = sum >> " + std::to_string(Is3) + "ULL;\n";
cp.code() += "etiss_coverage_count(4, 27126, 27125, 27123, 27124);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = ((rounded) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(7, 27134, 27129, 27128, 27133, 27130, 27131, 27132);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
