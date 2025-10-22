/**
 * Generated on Wed, 22 Oct 2025 11:05:15 +0000.
 *
 * This file contains the instruction behavior models of the RV64A
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// AMOSWAPD --------------------------------------------------------------------
static InstructionDefinition amoswapd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoswapd",
	(uint32_t) 0x800302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOSWAPD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 226);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8465);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8432, 8431, 8430, 8428);\n";
cp.code() += "etiss_coverage_count(1, 8433);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8439, 8436, 8434, 8437, 8438);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int64)(mem_val_0)));\n";
cp.code() += "etiss_coverage_count(9, 8453, 8444, 8443, 8441, 8452, 8449, 8447, 8446, 8450);\n";
} // conditional
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 8464, 8456, 8455, 8463, 8461, 8460, 8458);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOSWAPD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoswapd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOADDD ---------------------------------------------------------------------
static InstructionDefinition amoaddd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoaddd",
	(uint32_t) 0x00302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOADDD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 227);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8506);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8472, 8471, 8470, 8468);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8477, 8476, 8475);\n";
cp.code() += "etiss_coverage_count(1, 8478);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8484, 8481, 8479, 8482, 8483);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 8491, 8489, 8488, 8486, 8490);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = res + *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 8500, 8499, 8493, 8498, 8497, 8495);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8505, 8503, 8502, 8504);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOADDD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoaddd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOXORD ---------------------------------------------------------------------
static InstructionDefinition amoxord_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoxord",
	(uint32_t) 0x2000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOXORD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 228);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8547);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8513, 8512, 8511, 8509);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8518, 8517, 8516);\n";
cp.code() += "etiss_coverage_count(1, 8519);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8525, 8522, 8520, 8523, 8524);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 8532, 8530, 8529, 8527, 8531);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = res ^ *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 8541, 8540, 8534, 8539, 8538, 8536);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8546, 8544, 8543, 8545);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOXORD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoxord" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOANDD ---------------------------------------------------------------------
static InstructionDefinition amoandd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoandd",
	(uint32_t) 0x6000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOANDD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 229);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8588);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8554, 8553, 8552, 8550);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8559, 8558, 8557);\n";
cp.code() += "etiss_coverage_count(1, 8560);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8566, 8563, 8561, 8564, 8565);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 8573, 8571, 8570, 8568, 8572);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = res & *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 8582, 8581, 8575, 8580, 8579, 8577);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8587, 8585, 8584, 8586);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOANDD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoandd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOORD ----------------------------------------------------------------------
static InstructionDefinition amoord_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoord",
	(uint32_t) 0x4000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOORD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 230);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8629);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8595, 8594, 8593, 8591);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8600, 8599, 8598);\n";
cp.code() += "etiss_coverage_count(1, 8601);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8607, 8604, 8602, 8605, 8606);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 8614, 8612, 8611, 8609, 8613);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = res | *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 8623, 8622, 8616, 8621, 8620, 8618);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8628, 8626, 8625, 8627);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOORD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoord" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMIND ---------------------------------------------------------------------
static InstructionDefinition amomind_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomind",
	(uint32_t) 0x8000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMIND\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 231);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8679);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8636, 8635, 8634, 8632);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int64 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8641, 8640, 8639);\n";
cp.code() += "etiss_coverage_count(1, 8642);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8648, 8645, 8643, 8646, 8647);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 8655, 8653, 8652, 8650, 8654);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = (res1 > (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 8673, 8672, 8665, 8657, 8664, 8662, 8661, 8659, 8670, 8669, 8667, 8671);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8678, 8676, 8675, 8677);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOMIND\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomind" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXD ---------------------------------------------------------------------
static InstructionDefinition amomaxd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomaxd",
	(uint32_t) 0xa000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMAXD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 232);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8729);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8686, 8685, 8684, 8682);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8691, 8690, 8689);\n";
cp.code() += "etiss_coverage_count(1, 8692);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8698, 8695, 8693, 8696, 8697);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(5, 8705, 8703, 8702, 8700, 8704);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = (res < (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res);\n";
cp.code() += "etiss_coverage_count(12, 8723, 8722, 8715, 8707, 8714, 8712, 8711, 8709, 8720, 8719, 8717, 8721);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8728, 8726, 8725, 8727);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOMAXD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomaxd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMINUD --------------------------------------------------------------------
static InstructionDefinition amominud_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amominud",
	(uint32_t) 0xc000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMINUD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 233);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8779);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8736, 8735, 8734, 8732);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint64 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8741, 8740, 8739);\n";
cp.code() += "etiss_coverage_count(1, 8742);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8748, 8745, 8743, 8746, 8747);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(res);\n";
cp.code() += "etiss_coverage_count(6, 8757, 8753, 8752, 8750, 8756, 8754);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = (res > *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res);\n";
cp.code() += "etiss_coverage_count(11, 8773, 8772, 8765, 8759, 8764, 8763, 8761, 8770, 8769, 8767, 8771);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8778, 8776, 8775, 8777);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOMINUD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amominud" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXUD --------------------------------------------------------------------
static InstructionDefinition amomaxud_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomaxud",
	(uint32_t) 0xe000302f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMAXUD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 234);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8829);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 8786, 8785, 8784, 8782);\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint64 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(3, 8791, 8790, 8789);\n";
cp.code() += "etiss_coverage_count(1, 8792);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8798, 8795, 8793, 8796, 8797);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(res1);\n";
cp.code() += "etiss_coverage_count(6, 8807, 8803, 8802, 8800, 8806, 8804);\n";
} // conditional
cp.code() += "etiss_uint64 res2 = (res1 < *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(11, 8823, 8822, 8815, 8809, 8814, 8813, 8811, 8820, 8819, 8817, 8821);\n";
cp.code() += "etiss_uint64 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(4, 8828, 8826, 8825, 8827);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//AMOMAXUD\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomaxud" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
