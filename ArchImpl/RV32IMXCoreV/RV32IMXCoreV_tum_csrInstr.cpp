// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
 *
 * This file contains the instruction behavior models of the tum_csr
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CSRRW -----------------------------------------------------------------------
static InstructionDefinition csrrw_rd_rs1_csr (
	ISA32_RV32IMXCoreV,
	"csrrw",
	(uint64_t) 0x001073,
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 467);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27239);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrs1 = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27212, 27211, 27210, 27208);\n";
cp.code() += "etiss_coverage_count(1, 27213);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27219, 27216, 27214, 27217, 27218);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27234);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27223, 27222, 27221);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrs1);\n";
cp.code() += "etiss_coverage_count(3, 27226, 27224, 27225);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27233, 27231, 27230, 27228, 27232);\n";
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 27238);\n";
cp.code() += "{ // block\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrs1);\n";
cp.code() += "etiss_coverage_count(3, 27237, 27235, 27236);\n";
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrrw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | csr=" + std::to_string(csr) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRRS -----------------------------------------------------------------------
static InstructionDefinition csrrs_rd_rs1_csr (
	ISA32_RV32IMXCoreV,
	"csrrs",
	(uint64_t) 0x002073,
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 468);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27274);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27243, 27242, 27241);\n";
cp.code() += "etiss_uint32 xrs1 = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27250, 27249, 27248, 27246);\n";
cp.code() += "etiss_coverage_count(1, 27251);\n";
if (rs1 != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27254, 27252, 27253);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd | xrs1);\n";
cp.code() += "etiss_coverage_count(5, 27259, 27255, 27258, 27256, 27257);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27260);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27266, 27263, 27261, 27264, 27265);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27273, 27271, 27270, 27268, 27272);\n";
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrrs" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | csr=" + std::to_string(csr) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRRC -----------------------------------------------------------------------
static InstructionDefinition csrrc_rd_rs1_csr (
	ISA32_RV32IMXCoreV,
	"csrrc",
	(uint64_t) 0x003073,
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRC\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 469);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27310);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27278, 27277, 27276);\n";
cp.code() += "etiss_uint32 xrs1 = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27285, 27284, 27283, 27281);\n";
cp.code() += "etiss_coverage_count(1, 27286);\n";
if (rs1 != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27289, 27287, 27288);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd & ~(xrs1));\n";
cp.code() += "etiss_coverage_count(6, 27295, 27290, 27294, 27291, 27293, 27292);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27296);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27302, 27299, 27297, 27300, 27301);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27309, 27307, 27306, 27304, 27308);\n";
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrrc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | csr=" + std::to_string(csr) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRRWI ----------------------------------------------------------------------
static InstructionDefinition csrrwi_rd_zimm_csr (
	ISA32_RV32IMXCoreV,
	"csrrwi",
	(uint64_t) 0x005073,
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
etiss_uint8 zimm = 0;
static BitArrayRange R_zimm_0(19, 15);
zimm += R_zimm_0.read(ba) << 0;
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRWI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 470);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27334);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27314, 27313, 27312);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, " + std::to_string((etiss_uint32)(zimm)) + "ULL);\n";
cp.code() += "etiss_coverage_count(4, 27319, 27315, 27318, 27316);\n";
cp.code() += "etiss_coverage_count(1, 27320);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27326, 27323, 27321, 27324, 27325);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27333, 27331, 27330, 27328, 27332);\n";
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
etiss_uint8 zimm = 0;
static BitArrayRange R_zimm_0(19, 15);
zimm += R_zimm_0.read(ba) << 0;
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrrwi" << " # " << ba << (" [rd=" + std::to_string(rd) + " | zimm=" + std::to_string(zimm) + " | csr=" + std::to_string(csr) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRRSI ----------------------------------------------------------------------
static InstructionDefinition csrrsi_rd_zimm_csr (
	ISA32_RV32IMXCoreV,
	"csrrsi",
	(uint64_t) 0x006073,
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
etiss_uint8 zimm = 0;
static BitArrayRange R_zimm_0(19, 15);
zimm += R_zimm_0.read(ba) << 0;
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRSI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 471);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27364);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27338, 27337, 27336);\n";
cp.code() += "etiss_coverage_count(1, 27339);\n";
if (zimm != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27342, 27340, 27341);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd | " + std::to_string((etiss_uint32)(zimm)) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 27349, 27343, 27348, 27344, 27347, 27345);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27350);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27356, 27353, 27351, 27354, 27355);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27363, 27361, 27360, 27358, 27362);\n";
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
etiss_uint8 zimm = 0;
static BitArrayRange R_zimm_0(19, 15);
zimm += R_zimm_0.read(ba) << 0;
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrrsi" << " # " << ba << (" [rd=" + std::to_string(rd) + " | zimm=" + std::to_string(zimm) + " | csr=" + std::to_string(csr) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRRCI ----------------------------------------------------------------------
static InstructionDefinition csrrci_rd_zimm_csr (
	ISA32_RV32IMXCoreV,
	"csrrci",
	(uint64_t) 0x007073,
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
etiss_uint8 zimm = 0;
static BitArrayRange R_zimm_0(19, 15);
zimm += R_zimm_0.read(ba) << 0;
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRCI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 472);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27396);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27368, 27367, 27366);\n";
cp.code() += "etiss_coverage_count(1, 27369);\n";
if (zimm != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27372, 27370, 27371);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd & " + std::to_string(~(((etiss_uint32)(zimm)))) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 27381, 27373, 27380, 27374, 27379, 27377, 27375, 27378);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27382);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27388, 27385, 27383, 27386, 27387);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27395, 27393, 27392, 27390, 27394);\n";
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
etiss_uint8 zimm = 0;
static BitArrayRange R_zimm_0(19, 15);
zimm += R_zimm_0.read(ba) << 0;
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrrci" << " # " << ba << (" [rd=" + std::to_string(rd) + " | zimm=" + std::to_string(zimm) + " | csr=" + std::to_string(csr) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
