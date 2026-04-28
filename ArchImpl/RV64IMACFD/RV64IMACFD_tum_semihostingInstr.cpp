// clang-format off
/**
 * Generated on Mon, 27 Apr 2026 10:48:13 +0000.
 *
 * This file contains the instruction behavior models of the tum_semihosting
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// EBREAK ----------------------------------------------------------------------
static InstructionDefinition ebreak_ (
	ISA32_RV64IMACFD,
	"ebreak",
	(uint64_t) 0x100073,
	(uint64_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//EBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 183);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7418);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7328);\n";
cp.code() += "if (etiss_semihost_enabled()) { // conditional\n";
cp.code() += "etiss_coverage_count(1, 7329);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7413);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 pc_m4 = " + std::to_string((etiss_uint64)((ic.current_address_ - 4ULL))) + "ULL;\n";
cp.code() += "etiss_coverage_count(6, 7337, 7336, 7333, 7331, 7332, 7334);\n";
cp.code() += "etiss_uint64 pc_p4 = " + std::to_string((etiss_uint64)((ic.current_address_ + 4ULL))) + "ULL;\n";
cp.code() += "etiss_coverage_count(6, 7345, 7344, 7341, 7339, 7340, 7342);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, pc_m4, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 pre = (etiss_uint32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 7355, 7354, 7352, 7350, 7348, 7349);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_) + "ULL, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 ebreak = (etiss_uint32)(mem_val_1);\n";
cp.code() += "etiss_coverage_count(6, 7365, 7364, 7362, 7360, 7358, 7359);\n";
cp.code() += "etiss_uint32 mem_val_2;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, pc_p4, (etiss_uint8*)&mem_val_2, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 post = (etiss_uint32)(mem_val_2);\n";
cp.code() += "etiss_coverage_count(6, 7375, 7374, 7372, 7370, 7368, 7369);\n";
cp.code() += "etiss_coverage_count(1, 7376);\n";
cp.code() += "if (pre == 32509971ULL && ebreak == 1048691ULL && post == 1081102355ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(11, 7387, 7383, 7379, 7377, 7378, 7382, 7380, 7381, 7386, 7384, 7385);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7408);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 operation = *((RV64IMACFD*)cpu)->X[10ULL];\n";
cp.code() += "etiss_coverage_count(3, 7392, 7391, 7390);\n";
cp.code() += "etiss_uint64 parameter = *((RV64IMACFD*)cpu)->X[11ULL];\n";
cp.code() += "etiss_coverage_count(3, 7397, 7396, 7395);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[10ULL] = (etiss_int64)(etiss_semihost(cpu, system, plugin_pointers, 64ULL, operation, parameter));\n";
cp.code() += "etiss_coverage_count(7, 7407, 7400, 7399, 7406, 7404, 7402, 7403);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7412);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 3LL);\n";
cp.code() += "etiss_coverage_count(2, 7411, 7409);\n";
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
cp.code() += "etiss_coverage_count(1, 7417);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 3LL);\n";
cp.code() += "etiss_coverage_count(2, 7416, 7414);\n";
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
// clang-format on
