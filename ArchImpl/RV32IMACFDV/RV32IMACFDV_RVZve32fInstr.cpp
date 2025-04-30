/**
 * Generated on Wed, 30 Apr 2025 13:39:25 +0000.
 *
 * This file contains the instruction behavior models of the RVZve32f
 * instruction set for the RV32IMACFDV core architecture.
 */

#include "RV32IMACFDVArch.h"
#include "RV32IMACFDVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// VFADD_VV --------------------------------------------------------------------
static InstructionDefinition vfadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfadd_vv",
	(uint32_t) 0x001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFADD_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfadd_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFADD_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFADD_VF --------------------------------------------------------------------
static InstructionDefinition vfadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfadd_vf",
	(uint32_t) 0x005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFADD_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfadd_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFADD_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSUB_VV --------------------------------------------------------------------
static InstructionDefinition vfsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsub_vv",
	(uint32_t) 0x8001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSUB_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsub_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSUB_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSUB_VF --------------------------------------------------------------------
static InstructionDefinition vfsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsub_vf",
	(uint32_t) 0x8005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSUB_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsub_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSUB_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFRSUB_VF -------------------------------------------------------------------
static InstructionDefinition vfrsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfrsub_vf",
	(uint32_t) 0x9c005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFRSUB_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfrsub_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFRSUB_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_VV -------------------------------------------------------------------
static InstructionDefinition vfwadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwadd_vv",
	(uint32_t) 0xc0001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwadd_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_VF -------------------------------------------------------------------
static InstructionDefinition vfwadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwadd_vf",
	(uint32_t) 0xc0005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwadd_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_VV -------------------------------------------------------------------
static InstructionDefinition vfwsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwsub_vv",
	(uint32_t) 0xc8001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwsub_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_VF -------------------------------------------------------------------
static InstructionDefinition vfwsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwsub_vf",
	(uint32_t) 0xc8005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwsub_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_WV -------------------------------------------------------------------
static InstructionDefinition vfwadd_wv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwadd_wv",
	(uint32_t) 0xd0001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_WV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwadd_wv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_WV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_wv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_WF -------------------------------------------------------------------
static InstructionDefinition vfwadd_wf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwadd_wf",
	(uint32_t) 0xd0005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_WF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwadd_wf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_WF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_wf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_WV -------------------------------------------------------------------
static InstructionDefinition vfwsub_wv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwsub_wv",
	(uint32_t) 0xd8001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_WV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwsub_wv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_WV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_wv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_WF -------------------------------------------------------------------
static InstructionDefinition vfwsub_wf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwsub_wf",
	(uint32_t) 0xd8005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_WF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwsub_wf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_WF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_wf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMUL_VV --------------------------------------------------------------------
static InstructionDefinition vfmul_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmul_vv",
	(uint32_t) 0x90001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMUL_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmul_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMUL_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmul_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMUL_VF --------------------------------------------------------------------
static InstructionDefinition vfmul_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmul_vf",
	(uint32_t) 0x90005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMUL_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmul_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMUL_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmul_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFDIV_VV --------------------------------------------------------------------
static InstructionDefinition vfdiv_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfdiv_vv",
	(uint32_t) 0x80001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFDIV_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfdiv_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFDIV_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfdiv_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFDIV_VF --------------------------------------------------------------------
static InstructionDefinition vfdiv_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfdiv_vf",
	(uint32_t) 0x80005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFDIV_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfdiv_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFDIV_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfdiv_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFRDIV_VF -------------------------------------------------------------------
static InstructionDefinition vfrdiv_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfrdiv_vf",
	(uint32_t) 0x84005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFRDIV_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfrdiv_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFRDIV_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrdiv_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMUL_VV -------------------------------------------------------------------
static InstructionDefinition vfwmul_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwmul_vv",
	(uint32_t) 0xe0001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMUL_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwmul_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMUL_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmul_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMUL_VF -------------------------------------------------------------------
static InstructionDefinition vfwmul_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwmul_vf",
	(uint32_t) 0xe0005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMUL_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwmul_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMUL_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmul_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMACC_VV -------------------------------------------------------------------
static InstructionDefinition vfmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmacc_vv",
	(uint32_t) 0xb0001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMACC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmacc_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMACC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMACC_VF -------------------------------------------------------------------
static InstructionDefinition vfmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmacc_vf",
	(uint32_t) 0xb0005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMACC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmacc_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMACC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMACC_VV ------------------------------------------------------------------
static InstructionDefinition vfnmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmacc_vv",
	(uint32_t) 0xb4001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMACC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmacc_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMACC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMACC_VF ------------------------------------------------------------------
static InstructionDefinition vfnmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmacc_vf",
	(uint32_t) 0xb4005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMACC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmacc_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMACC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSAC_VV -------------------------------------------------------------------
static InstructionDefinition vfmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmsac_vv",
	(uint32_t) 0xb8001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSAC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmsac_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSAC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSAC_VF -------------------------------------------------------------------
static InstructionDefinition vfmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmsac_vf",
	(uint32_t) 0xb8005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSAC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmsac_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSAC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSAC_VV ------------------------------------------------------------------
static InstructionDefinition vfnmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmsac_vv",
	(uint32_t) 0xbc001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSAC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmsac_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSAC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSAC_VF ------------------------------------------------------------------
static InstructionDefinition vfnmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmsac_vf",
	(uint32_t) 0xbc005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSAC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmsac_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSAC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMADD_VV -------------------------------------------------------------------
static InstructionDefinition vfmadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmadd_vv",
	(uint32_t) 0xa0001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMADD_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmadd_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMADD_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMADD_VF -------------------------------------------------------------------
static InstructionDefinition vfmadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmadd_vf",
	(uint32_t) 0xa0005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMADD_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmadd_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMADD_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMADD_VV ------------------------------------------------------------------
static InstructionDefinition vfnmadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmadd_vv",
	(uint32_t) 0xa4001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMADD_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmadd_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMADD_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMADD_VF ------------------------------------------------------------------
static InstructionDefinition vfnmadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmadd_vf",
	(uint32_t) 0xa4005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMADD_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmadd_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMADD_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSUB_VV -------------------------------------------------------------------
static InstructionDefinition vfmsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmsub_vv",
	(uint32_t) 0xa8001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSUB_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmsub_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSUB_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSUB_VF -------------------------------------------------------------------
static InstructionDefinition vfmsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmsub_vf",
	(uint32_t) 0xa8005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSUB_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmsub_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSUB_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSUB_VV ------------------------------------------------------------------
static InstructionDefinition vfnmsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmsub_vv",
	(uint32_t) 0xac001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSUB_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmsub_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSUB_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSUB_VF ------------------------------------------------------------------
static InstructionDefinition vfnmsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfnmsub_vf",
	(uint32_t) 0xac005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSUB_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfnmsub_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSUB_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMACC_VV ------------------------------------------------------------------
static InstructionDefinition vfwmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwmacc_vv",
	(uint32_t) 0xf0001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMACC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwmacc_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMACC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMACC_VF ------------------------------------------------------------------
static InstructionDefinition vfwmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwmacc_vf",
	(uint32_t) 0xf0005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMACC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwmacc_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMACC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMACC_VV -----------------------------------------------------------------
static InstructionDefinition vfwnmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwnmacc_vv",
	(uint32_t) 0xf4001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMACC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwnmacc_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMACC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMACC_VF -----------------------------------------------------------------
static InstructionDefinition vfwnmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwnmacc_vf",
	(uint32_t) 0xf4005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMACC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwnmacc_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMACC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMSAC_VV ------------------------------------------------------------------
static InstructionDefinition vfwmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwmsac_vv",
	(uint32_t) 0xf8001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMSAC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwmsac_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMSAC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMSAC_VF ------------------------------------------------------------------
static InstructionDefinition vfwmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwmsac_vf",
	(uint32_t) 0xf8005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMSAC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwmsac_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMSAC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMSAC_VV -----------------------------------------------------------------
static InstructionDefinition vfwnmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwnmsac_vv",
	(uint32_t) 0xfc001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwnmsac_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMSAC_VF -----------------------------------------------------------------
static InstructionDefinition vfwnmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwnmsac_vf",
	(uint32_t) 0xfc005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwnmsac_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSQRT_V --------------------------------------------------------------------
static InstructionDefinition vfsqrt_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsqrt_v",
	(uint32_t) 0x4c001057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSQRT_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsqrt_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSQRT_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsqrt_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFRSQRT7_V ------------------------------------------------------------------
static InstructionDefinition vfrsqrt7_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfrsqrt7_v",
	(uint32_t) 0x4c021057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFRSQRT7_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfrsqrt7_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFRSQRT7_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrsqrt7_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREC7_V --------------------------------------------------------------------
static InstructionDefinition vfrec7_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfrec7_v",
	(uint32_t) 0x4c029057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREC7_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfrec7_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREC7_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrec7_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMIN_VV --------------------------------------------------------------------
static InstructionDefinition vfmin_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmin_vv",
	(uint32_t) 0x10001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMIN_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmin_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMIN_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmin_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMIN_VF --------------------------------------------------------------------
static InstructionDefinition vfmin_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmin_vf",
	(uint32_t) 0x10005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMIN_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmin_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMIN_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmin_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMAX_VV --------------------------------------------------------------------
static InstructionDefinition vfmax_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmax_vv",
	(uint32_t) 0x18001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMAX_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmax_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMAX_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmax_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMAX_VF --------------------------------------------------------------------
static InstructionDefinition vfmax_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfmax_vf",
	(uint32_t) 0x18005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMAX_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfmax_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMAX_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmax_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJ_VV -------------------------------------------------------------------
static InstructionDefinition vfsgnj_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsgnj_vv",
	(uint32_t) 0x20001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJ_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsgnj_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJ_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnj_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJ_VF -------------------------------------------------------------------
static InstructionDefinition vfsgnj_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsgnj_vf",
	(uint32_t) 0x20005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJ_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsgnj_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJ_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnj_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJN_VV ------------------------------------------------------------------
static InstructionDefinition vfsgnjn_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsgnjn_vv",
	(uint32_t) 0x24001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJN_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsgnjn_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJN_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjn_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJN_VF ------------------------------------------------------------------
static InstructionDefinition vfsgnjn_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsgnjn_vf",
	(uint32_t) 0x24005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJN_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsgnjn_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJN_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjn_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJX_VV ------------------------------------------------------------------
static InstructionDefinition vfsgnjx_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsgnjx_vv",
	(uint32_t) 0x28001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJX_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsgnjx_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJX_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjx_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJX_VF ------------------------------------------------------------------
static InstructionDefinition vfsgnjx_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfsgnjx_vf",
	(uint32_t) 0x28005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJX_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfsgnjx_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJX_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjx_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFEQ_VV --------------------------------------------------------------------
static InstructionDefinition vmfeq_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfeq_vv",
	(uint32_t) 0x60001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFEQ_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfeq_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFEQ_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfeq_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFEQ_VF --------------------------------------------------------------------
static InstructionDefinition vmfeq_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfeq_vf",
	(uint32_t) 0x60005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFEQ_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfeq_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFEQ_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfeq_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFNE_VV --------------------------------------------------------------------
static InstructionDefinition vmfne_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfne_vv",
	(uint32_t) 0x70001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFNE_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfne_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFNE_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfne_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFNE_VF --------------------------------------------------------------------
static InstructionDefinition vmfne_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfne_vf",
	(uint32_t) 0x70005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFNE_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfne_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFNE_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfne_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLT_VV --------------------------------------------------------------------
static InstructionDefinition vmflt_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmflt_vv",
	(uint32_t) 0x6c001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLT_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmflt_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLT_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmflt_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLT_VF --------------------------------------------------------------------
static InstructionDefinition vmflt_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmflt_vf",
	(uint32_t) 0x6c005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLT_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmflt_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLT_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmflt_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLE_VV --------------------------------------------------------------------
static InstructionDefinition vmfle_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfle_vv",
	(uint32_t) 0x64001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLE_VV\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfle_vv(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLE_VV\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfle_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLE_VF --------------------------------------------------------------------
static InstructionDefinition vmfle_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfle_vf",
	(uint32_t) 0x64005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLE_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfle_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLE_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfle_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFGT_VF --------------------------------------------------------------------
static InstructionDefinition vmfgt_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfgt_vf",
	(uint32_t) 0x74005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFGT_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfgt_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFGT_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfgt_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFGE_VF --------------------------------------------------------------------
static InstructionDefinition vmfge_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vmfge_vf",
	(uint32_t) 0x7c005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFGE_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vmfge_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFGE_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfge_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCLASS_V -------------------------------------------------------------------
static InstructionDefinition vfclass_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfclass_v",
	(uint32_t) 0x4c081057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCLASS_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfclass_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCLASS_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfclass_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMERGE_VFM -----------------------------------------------------------------
static InstructionDefinition vfmerge_vfm_vd_rs1_vs2 (
	ISA32_RV32IMACFDV,
	"vfmerge_vfm",
	(uint32_t) 0x5c005057,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMERGE_VFM\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 ret = vfmerge_vfm(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMERGE_VFM\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmerge_vfm" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMV_V_F --------------------------------------------------------------------
static InstructionDefinition vfmv_v_f_vd_rs1 (
	ISA32_RV32IMACFDV,
	"vfmv_v_f",
	(uint32_t) 0x5e005057,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMV_V_F\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 ret = vfmv_v_f(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMV_V_F\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmv_v_f" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_XU_F_V ----------------------------------------------------------------
static InstructionDefinition vfcvt_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfcvt_xu_f_v",
	(uint32_t) 0x48001057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_XU_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfcvt_xu_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_XU_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_X_F_V -----------------------------------------------------------------
static InstructionDefinition vfcvt_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfcvt_x_f_v",
	(uint32_t) 0x48009057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_X_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfcvt_x_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_X_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_RTZ_XU_F_V ------------------------------------------------------------
static InstructionDefinition vfcvt_rtz_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfcvt_rtz_xu_f_v",
	(uint32_t) 0x48031057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_XU_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfcvt_rtz_xu_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_XU_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_rtz_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_RTZ_X_F_V -------------------------------------------------------------
static InstructionDefinition vfcvt_rtz_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfcvt_rtz_x_f_v",
	(uint32_t) 0x48039057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_X_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfcvt_rtz_x_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_X_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_rtz_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_F_XU_V ----------------------------------------------------------------
static InstructionDefinition vfcvt_f_xu_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfcvt_f_xu_v",
	(uint32_t) 0x48011057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_F_XU_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfcvt_f_xu_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_F_XU_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_f_xu_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_F_X_V -----------------------------------------------------------------
static InstructionDefinition vfcvt_f_x_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfcvt_f_x_v",
	(uint32_t) 0x48019057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_F_X_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfcvt_f_x_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_F_X_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_f_x_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_XU_F_V ---------------------------------------------------------------
static InstructionDefinition vfwcvt_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_xu_f_v",
	(uint32_t) 0x48041057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_XU_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_xu_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_XU_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_X_F_V ----------------------------------------------------------------
static InstructionDefinition vfwcvt_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_x_f_v",
	(uint32_t) 0x48049057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_X_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_x_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_X_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_RTZ_XU_F_V -----------------------------------------------------------
static InstructionDefinition vfwcvt_rtz_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_rtz_xu_f_v",
	(uint32_t) 0x48071057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_XU_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_rtz_xu_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_XU_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_rtz_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_RTZ_X_F_V ------------------------------------------------------------
static InstructionDefinition vfwcvt_rtz_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_rtz_x_f_v",
	(uint32_t) 0x48079057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_X_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_rtz_x_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_X_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_rtz_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_F_XU_V ---------------------------------------------------------------
static InstructionDefinition vfwcvt_f_xu_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_f_xu_v",
	(uint32_t) 0x48051057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_F_XU_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_xu_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_F_XU_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_f_xu_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_F_X_V ----------------------------------------------------------------
static InstructionDefinition vfwcvt_f_x_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_f_x_v",
	(uint32_t) 0x48059057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_F_X_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_x_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_F_X_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_f_x_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_F_F_V ----------------------------------------------------------------
static InstructionDefinition vfwcvt_f_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwcvt_f_f_v",
	(uint32_t) 0x48061057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_F_F_V\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_f_v(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_F_F_V\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_f_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_XU_F_W ---------------------------------------------------------------
static InstructionDefinition vnfcvt_xu_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_xu_f_w",
	(uint32_t) 0x48081057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_XU_F_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_xu_f_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_XU_F_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_xu_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_X_F_W ----------------------------------------------------------------
static InstructionDefinition vnfcvt_x_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_x_f_w",
	(uint32_t) 0x48089057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_X_F_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_x_f_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_X_F_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_x_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_RTZ_XU_F_W -----------------------------------------------------------
static InstructionDefinition vnfcvt_rtz_xu_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_rtz_xu_f_w",
	(uint32_t) 0x480b1057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_XU_F_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_rtz_xu_f_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_XU_F_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_rtz_xu_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_RTZ_X_F_W ------------------------------------------------------------
static InstructionDefinition vnfcvt_rtz_x_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_rtz_x_f_w",
	(uint32_t) 0x480b9057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_X_F_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_rtz_x_f_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_X_F_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_rtz_x_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_F_XU_W ---------------------------------------------------------------
static InstructionDefinition vnfcvt_f_xu_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_f_xu_w",
	(uint32_t) 0x48091057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_F_XU_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_xu_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_F_XU_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_f_xu_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_F_X_W ----------------------------------------------------------------
static InstructionDefinition vnfcvt_f_x_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_f_x_w",
	(uint32_t) 0x48099057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_F_X_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_x_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_F_X_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_f_x_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_F_F_W ----------------------------------------------------------------
static InstructionDefinition vnfcvt_f_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_f_f_w",
	(uint32_t) 0x480a1057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_F_F_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_f_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_F_F_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_f_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_ROD_F_F_W ------------------------------------------------------------
static InstructionDefinition vnfcvt_rod_f_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV,
	"vnfcvt_rod_f_f_w",
	(uint32_t) 0x480a9057,
	(uint32_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_ROD_F_F_W\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfncvt_rod_f_f_w(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_ROD_F_F_W\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_rod_f_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDOSUM_VS ----------------------------------------------------------------
static InstructionDefinition vfredosum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfredosum_vs",
	(uint32_t) 0xc001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDOSUM_VS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfredosum_vs(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDOSUM_VS\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredosum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDUSUM_VS ----------------------------------------------------------------
static InstructionDefinition vfredusum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfredusum_vs",
	(uint32_t) 0x4001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDUSUM_VS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfredusum_vs(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDUSUM_VS\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredusum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDMAX_VS -----------------------------------------------------------------
static InstructionDefinition vfredmax_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfredmax_vs",
	(uint32_t) 0x1c001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDMAX_VS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfredmax_vs(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDMAX_VS\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredmax_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDMIN_VS -----------------------------------------------------------------
static InstructionDefinition vfredmin_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfredmin_vs",
	(uint32_t) 0x14001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDMIN_VS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfredmin_vs(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDMIN_VS\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredmin_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWREDOSUM_VS ---------------------------------------------------------------
static InstructionDefinition vfwredosum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwredosum_vs",
	(uint32_t) 0xcc001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWREDOSUM_VS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwredosum_vs(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWREDOSUM_VS\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwredosum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWREDUSUM_VS ---------------------------------------------------------------
static InstructionDefinition vfwredusum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfwredusum_vs",
	(uint32_t) 0xc4001057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWREDUSUM_VS\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 _rounding_mode = *((RV32IMACFDV*)cpu)->CSR[2LL];\n";
cp.code() += "etiss_uint32 ret = vfwredusum_vs(((RV32IMACFDV*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV32IMACFDV*)cpu)->FCSR = (((RV32IMACFDV*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWREDUSUM_VS\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwredusum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMV_F_S --------------------------------------------------------------------
static InstructionDefinition vfmv_f_s_rd_vs2 (
	ISA32_RV32IMACFDV,
	"vfmv_f_s",
	(uint32_t) 0x42001057,
	(uint32_t) 0xfe0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMV_F_S\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 ret = vfmv_f_s(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(rd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, 64ULL);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
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

		cp.code() = std::string("//VFMV_F_S\n");

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
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmv_f_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | vs2=" + std::to_string(vs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMV_S_F --------------------------------------------------------------------
static InstructionDefinition vfmv_s_f_vd_rs1 (
	ISA32_RV32IMACFDV,
	"vfmv_s_f",
	(uint32_t) 0x42005057,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMV_S_F\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 ret = vfmv_s_f(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
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

		cp.code() = std::string("//VFMV_S_F\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmv_s_f" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSLIDE1UP_VX ---------------------------------------------------------------
static InstructionDefinition vfslide1up_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfslide1up_vx",
	(uint32_t) 0x38005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSLIDE1UP_VX\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 ret = vfslide1up_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
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

		cp.code() = std::string("//VFSLIDE1UP_VX\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfslide1up_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSLIDE1DOWN_VF -------------------------------------------------------------
static InstructionDefinition vfslide1down_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV,
	"vfslide1down_vf",
	(uint32_t) 0x3c005057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSLIDE1DOWN_VF\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_uint32 ret = vfslide1down_vf(((RV32IMACFDV*)cpu)->V, *((RV32IMACFDV*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 64ULL);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV*)cpu)->CSR[8ULL] = 0LL;\n";
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

		cp.code() = std::string("//VFSLIDE1DOWN_VF\n");

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
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfslide1down_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
