/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the instruction behavior models of the tum_semihosting
 * instruction set for the XIsaacCore core architecture.
 */

#include "XIsaacCoreArch.h"
#include "XIsaacCoreFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// EBREAK ----------------------------------------------------------------------
static InstructionDefinition ebreak_ (
	ISA32_XIsaacCore,
	"ebreak",
	(uint32_t) 0x100073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//EBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 184);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2290);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2219);\n";
cp.code() += "if (etiss_semihost_enabled()) { // conditional\n";
cp.code() += "etiss_coverage_count(1, 2220);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2285);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_ - 4ULL) + "ULL, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 pre = (etiss_uint32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 2229, 2228, 2226, 2225, 2223, 2224);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_ + 0LL) + "LL, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 ebreak = (etiss_uint32)(mem_val_1);\n";
cp.code() += "etiss_coverage_count(6, 2238, 2237, 2235, 2234, 2232, 2233);\n";
cp.code() += "etiss_uint32 mem_val_2;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_ + 4ULL) + "ULL, (etiss_uint8*)&mem_val_2, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 post = (etiss_uint32)(mem_val_2);\n";
cp.code() += "etiss_coverage_count(6, 2247, 2246, 2244, 2243, 2241, 2242);\n";
cp.code() += "etiss_coverage_count(1, 2248);\n";
cp.code() += "if (pre == 32509971ULL && ebreak == 1048691ULL && post == 1081102355ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(11, 2259, 2255, 2251, 2249, 2250, 2254, 2252, 2253, 2258, 2256, 2257);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2280);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 operation = *((XIsaacCore*)cpu)->X[10ULL];\n";
cp.code() += "etiss_coverage_count(3, 2264, 2263, 2262);\n";
cp.code() += "etiss_uint32 parameter = *((XIsaacCore*)cpu)->X[11ULL];\n";
cp.code() += "etiss_coverage_count(3, 2269, 2268, 2267);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[10ULL] = (etiss_int32)(etiss_semihost(cpu, system, plugin_pointers, 32ULL, operation, parameter));\n";
cp.code() += "etiss_coverage_count(7, 2279, 2272, 2271, 2278, 2276, 2274, 2275);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2284);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, 3LL);\n";
cp.code() += "etiss_coverage_count(2, 2283, 2281);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2289);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, 3LL);\n";
cp.code() += "etiss_coverage_count(2, 2288, 2286);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//EBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
ss << "ebreak" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
