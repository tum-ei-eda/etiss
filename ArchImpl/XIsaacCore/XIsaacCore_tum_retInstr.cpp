/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the XIsaacCore core architecture.
 */

#include "XIsaacCoreArch.h"
#include "XIsaacCoreFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_XIsaacCore,
	"ecall",
	(uint32_t) 0x000073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ECALL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 169);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2218);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, 8LL + ((XIsaacCore*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 2217, 2213, 2216, 2215);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//ECALL\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "ecall" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MRET ------------------------------------------------------------------------
static InstructionDefinition mret_ (
	ISA32_XIsaacCore,
	"mret",
	(uint32_t) 0x30200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 167);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2352);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2291);\n";
cp.code() += "if (((XIsaacCore*)cpu)->PRIV < 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 2294, 2292);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 2297, 2295);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((XIsaacCore*)cpu)->CSR[833LL];\n";
cp.code() += "etiss_coverage_count(3, 2302, 2298, 2301);\n";
cp.code() += "etiss_uint32 s = XIsaacCore_csr_read(cpu, system, plugin_pointers, 768LL);\n";
cp.code() += "etiss_coverage_count(2, 2306, 2305);\n";
cp.code() += "etiss_uint32 prev_prv = XIsaacCore_get_field(s, 6144LL);\n";
cp.code() += "etiss_coverage_count(3, 2311, 2310, 2308);\n";
cp.code() += "etiss_coverage_count(1, 2312);\n";
cp.code() += "if (prev_prv != 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 2315, 2313);\n";
cp.code() += "s = XIsaacCore_set_field(s, 131072LL, 0LL);\n";
cp.code() += "etiss_coverage_count(5, 2321, 2316, 2320, 2317, 2319);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = XIsaacCore_set_field(s, 8LL, XIsaacCore_get_field(s, 128LL));\n";
cp.code() += "etiss_coverage_count(6, 2329, 2322, 2328, 2323, 2327, 2325);\n";
cp.code() += "s = XIsaacCore_set_field(s, 128LL, 1ULL);\n";
cp.code() += "etiss_coverage_count(5, 2335, 2330, 2334, 2331, 2333);\n";
cp.code() += "s = XIsaacCore_set_field(s, 6144LL, (XIsaacCore_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3LL));\n";
cp.code() += "etiss_coverage_count(7, 2345, 2336, 2344, 2337, 2343, 2340, 2339);\n";
cp.code() += "XIsaacCore_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(2, 2348, 2347);\n";
cp.code() += "((XIsaacCore*)cpu)->PRIV = (prev_prv) & 0x7;\n";
cp.code() += "etiss_coverage_count(3, 2351, 2349, 2350);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//MRET\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "mret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// WFI -------------------------------------------------------------------------
static InstructionDefinition wfi_ (
	ISA32_XIsaacCore,
	"wfi",
	(uint32_t) 0x10500073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//WFI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 170);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2353);\n";
cp.code() += "{ // block\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//WFI\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "wfi" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRET ------------------------------------------------------------------------
static InstructionDefinition sret_ (
	ISA32_XIsaacCore,
	"sret",
	(uint32_t) 0x10200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRET\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 168);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6442);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6388);\n";
cp.code() += "if (((XIsaacCore*)cpu)->PRIV < ((XIsaacCore_get_field(XIsaacCore_csr_read(cpu, system, plugin_pointers, 768LL), 4194304LL)) ? (3LL) : (1LL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 6398, 6389, 6396, 6393, 6391, 6397);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 6401, 6399);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((XIsaacCore*)cpu)->CSR[321LL];\n";
cp.code() += "etiss_coverage_count(3, 6406, 6402, 6405);\n";
cp.code() += "etiss_uint32 s = XIsaacCore_csr_read(cpu, system, plugin_pointers, 256LL);\n";
cp.code() += "etiss_coverage_count(2, 6410, 6409);\n";
cp.code() += "etiss_uint32 prev_prv = XIsaacCore_get_field(s, 256LL);\n";
cp.code() += "etiss_coverage_count(3, 6415, 6414, 6412);\n";
cp.code() += "s = XIsaacCore_set_field(s, 2LL, XIsaacCore_get_field(s, 32LL));\n";
cp.code() += "etiss_coverage_count(6, 6423, 6416, 6422, 6417, 6421, 6419);\n";
cp.code() += "s = XIsaacCore_set_field(s, 32LL, 1ULL);\n";
cp.code() += "etiss_coverage_count(5, 6429, 6424, 6428, 6425, 6427);\n";
cp.code() += "s = XIsaacCore_set_field(s, 256LL, 0LL);\n";
cp.code() += "etiss_coverage_count(4, 6435, 6430, 6434, 6431);\n";
cp.code() += "XIsaacCore_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(2, 6438, 6437);\n";
cp.code() += "((XIsaacCore*)cpu)->PRIV = (prev_prv) & 0x7;\n";
cp.code() += "etiss_coverage_count(3, 6441, 6439, 6440);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//SRET\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
