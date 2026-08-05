// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
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
cp.code() += "etiss_coverage_count(1, 27237);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrs1 = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27210, 27209, 27208, 27206);\n";
cp.code() += "etiss_coverage_count(1, 27211);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27217, 27214, 27212, 27215, 27216);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27232);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27221, 27220, 27219);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrs1);\n";
cp.code() += "etiss_coverage_count(3, 27224, 27222, 27223);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27231, 27229, 27228, 27226, 27230);\n";
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 27236);\n";
cp.code() += "{ // block\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrs1);\n";
cp.code() += "etiss_coverage_count(3, 27235, 27233, 27234);\n";
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
cp.code() += "etiss_coverage_count(1, 27272);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27241, 27240, 27239);\n";
cp.code() += "etiss_uint32 xrs1 = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27248, 27247, 27246, 27244);\n";
cp.code() += "etiss_coverage_count(1, 27249);\n";
if (rs1 != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27252, 27250, 27251);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd | xrs1);\n";
cp.code() += "etiss_coverage_count(5, 27257, 27253, 27256, 27254, 27255);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27258);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27264, 27261, 27259, 27262, 27263);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27271, 27269, 27268, 27266, 27270);\n";
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
cp.code() += "etiss_coverage_count(1, 27308);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27276, 27275, 27274);\n";
cp.code() += "etiss_uint32 xrs1 = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27283, 27282, 27281, 27279);\n";
cp.code() += "etiss_coverage_count(1, 27284);\n";
if (rs1 != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27287, 27285, 27286);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd & ~(xrs1));\n";
cp.code() += "etiss_coverage_count(6, 27293, 27288, 27292, 27289, 27291, 27290);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27294);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27300, 27297, 27295, 27298, 27299);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27307, 27305, 27304, 27302, 27306);\n";
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
cp.code() += "etiss_coverage_count(1, 27332);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27312, 27311, 27310);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, " + std::to_string((etiss_uint32)(zimm)) + "ULL);\n";
cp.code() += "etiss_coverage_count(4, 27317, 27313, 27316, 27314);\n";
cp.code() += "etiss_coverage_count(1, 27318);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27324, 27321, 27319, 27322, 27323);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27331, 27329, 27328, 27326, 27330);\n";
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
cp.code() += "etiss_coverage_count(1, 27362);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27336, 27335, 27334);\n";
cp.code() += "etiss_coverage_count(1, 27337);\n";
if (zimm != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27340, 27338, 27339);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd | " + std::to_string((etiss_uint32)(zimm)) + "ULL);\n";
cp.code() += "etiss_coverage_count(6, 27347, 27341, 27346, 27342, 27345, 27343);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27348);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27354, 27351, 27349, 27352, 27353);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27361, 27359, 27358, 27356, 27360);\n";
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
cp.code() += "etiss_coverage_count(1, 27394);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 xrd = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(3, 27366, 27365, 27364);\n";
cp.code() += "etiss_coverage_count(1, 27367);\n";
if (zimm != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 27370, 27368, 27369);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd & " + std::to_string(~(((etiss_uint32)(zimm)))) + "ULL);\n";
cp.code() += "etiss_coverage_count(8, 27379, 27371, 27378, 27372, 27377, 27375, 27373, 27376);\n";
} // conditional
cp.code() += "etiss_coverage_count(1, 27380);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27386, 27383, 27381, 27384, 27385);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(5, 27393, 27391, 27390, 27388, 27392);\n";
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
