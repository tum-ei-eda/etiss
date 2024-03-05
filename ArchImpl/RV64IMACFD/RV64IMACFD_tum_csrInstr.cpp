/**
 * Generated on Tue, 05 Mar 2024 21:20:27 +0100.
 *
 * This file contains the instruction behavior models of the tum_csr
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// CSRRW -----------------------------------------------------------------------
static InstructionDefinition csrrw_rd_rs1_csr (
	ISA32_RV64IMACFD,
	"csrrw",
	(uint32_t) 0x001073,
	(uint32_t) 0x00707f,
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "etiss_coverage_count(1, 6540);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 6539, 6535, 6538);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9109);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrs1 = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 9083, 9082);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9088, 9087);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9103);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrd = RV64IMACFD_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(2, 9092, 9091);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrs1);\n";
cp.code() += "etiss_coverage_count(1, 9095);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(3, 9102, 9100, 9101);\n";
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 9107);\n";
cp.code() += "{ // block\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrs1);\n";
cp.code() += "etiss_coverage_count(1, 9106);\n";
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
	ISA32_RV64IMACFD,
	"csrrs",
	(uint32_t) 0x002073,
	(uint32_t) 0x00707f,
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "etiss_coverage_count(1, 6540);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 6539, 6535, 6538);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9142);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrd = RV64IMACFD_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(2, 9113, 9112);\n";
cp.code() += "etiss_uint64 xrs1 = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 9120, 9119);\n";
if (rs1 != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9122, 9121);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd | xrs1);\n";
cp.code() += "etiss_coverage_count(1, 9127);\n";
} // conditional
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9133, 9132);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(3, 9140, 9138, 9139);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
	ISA32_RV64IMACFD,
	"csrrc",
	(uint32_t) 0x003073,
	(uint32_t) 0x00707f,
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
etiss_uint16 csr = 0;
static BitArrayRange R_csr_0(31, 20);
csr += R_csr_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRC\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "etiss_coverage_count(1, 6540);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 6539, 6535, 6538);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9176);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrd = RV64IMACFD_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(2, 9146, 9145);\n";
cp.code() += "etiss_uint64 xrs1 = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 9153, 9152);\n";
if (rs1 != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9155, 9154);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd & ~(xrs1));\n";
cp.code() += "etiss_coverage_count(1, 9161);\n";
} // conditional
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9167, 9166);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(3, 9174, 9172, 9173);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
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
	ISA32_RV64IMACFD,
	"csrrwi",
	(uint32_t) 0x005073,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRWI\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "etiss_coverage_count(1, 6540);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 6539, 6535, 6538);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9198);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrd = RV64IMACFD_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(2, 9180, 9179);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, " + std::to_string((etiss_uint64)(zimm)) + "ULL);\n";
cp.code() += "etiss_coverage_count(1, 9184);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9189, 9188);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(3, 9196, 9194, 9195);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

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
	ISA32_RV64IMACFD,
	"csrrsi",
	(uint32_t) 0x006073,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRSI\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "etiss_coverage_count(1, 6540);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 6539, 6535, 6538);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9225);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrd = RV64IMACFD_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(2, 9202, 9201);\n";
if (zimm != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9204, 9203);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd | " + std::to_string((etiss_uint64)(zimm)) + "ULL);\n";
cp.code() += "etiss_coverage_count(1, 9210);\n";
} // conditional
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9216, 9215);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(3, 9223, 9221, 9222);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

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
	ISA32_RV64IMACFD,
	"csrrci",
	(uint32_t) 0x007073,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRRCI\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "etiss_coverage_count(1, 6540);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 6539, 6535, 6538);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9254);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 xrd = RV64IMACFD_csr_read(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL);\n";
cp.code() += "etiss_coverage_count(2, 9229, 9228);\n";
if (zimm != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9231, 9230);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, " + std::to_string(csr) + "ULL, xrd & " + std::to_string(~(((etiss_uint64)(zimm)))) + "ULL);\n";
cp.code() += "etiss_coverage_count(1, 9239);\n";
} // conditional
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 9245, 9244);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = xrd;\n";
cp.code() += "etiss_coverage_count(3, 9252, 9250, 9251);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

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
