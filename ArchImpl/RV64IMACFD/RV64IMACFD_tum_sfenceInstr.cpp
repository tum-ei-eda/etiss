/**
 * Generated on Wed, 13 Sep 2023 17:04:56 +0200.
 *
 * This file contains the instruction behavior models of the tum_sfence
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
extern "C" {
#include "RV64IMACFDFuncs.h"
}

using namespace etiss;
using namespace etiss::instr;


// SFENCE_VMA ------------------------------------------------------------------
static InstructionDefinition sfence_vma_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sfence_vma",
	(uint32_t) 0x12000073,
	(uint32_t) 0xfe007fff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SFENCE_VMA\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->exception = ETISS_RETURNCODE_RELOADBLOCKS;\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "((RV64IMACFD*)cpu)->FENCE[2ULL] = " + std::to_string(rs1) + "ULL;\n";
cp.code() += "((RV64IMACFD*)cpu)->FENCE[3ULL] = " + std::to_string(rs2) + "ULL;\n";
cp.code() += "etiss_uint64 vaddr = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_uint64 asid = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
if (rs1 == 0ULL) { // conditional
{ // block
cp.code() += "{ // block\n";
if (rs2 == 0ULL) { // conditional
cp.code() += "evict_all(cpu, system, plugin_pointers);\n";
} // conditional
else { // conditional
cp.code() += "evict_asid(cpu, system, plugin_pointers, asid);\n";
} // conditional
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "{ // block\n";
if (rs2 == 0ULL) { // conditional
cp.code() += "evict_addr(cpu, system, plugin_pointers, vaddr);\n";
} // conditional
else { // conditional
cp.code() += "evict_addr_asid(cpu, system, plugin_pointers, vaddr, asid);\n";
} // conditional
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getRegisterDependencies().add(reg_name[rs1], 64);
		cp.getRegisterDependencies().add(reg_name[rs2], 64);
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//SFENCE_VMA\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sfence_vma" << " # " << ba << (" [rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
