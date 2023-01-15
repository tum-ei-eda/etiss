/**
 * Generated on Thu, 12 May 2022 16:30:21 +0200.
 *
 * This file contains the instruction behavior models of the RV32V
 * instruction set for the RV32IMACFDPV core architecture.
 */

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// VSETVLI ---------------------------------------------------------------------
static InstructionDefinition vsetvli_rd_rs1_zimm (
	ISA32_RV32IMACFDPV,
	"vsetvli",
	(uint32_t) 0x007057,
	(uint32_t) 0x8000707f,
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
etiss_uint16 zimm = 0;
static BitArrayRange R_zimm_0(30, 20);
zimm += R_zimm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSETVLI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "if (!((*((RV32IMACFDPV*)cpu)->CSR[768U] & 1536U))) {\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint8 sew = (vtype_extractSEW(" + std::to_string(zimm) + ")) & 0x7;\n";
partInit.code() += "etiss_uint8 lmul = (vtype_extractLMUL(" + std::to_string(zimm) + ")) & 0x7;\n";
partInit.code() += "etiss_uint8 vta = (vtype_extractTA(" + std::to_string(zimm) + ")) & 0x1;\n";
partInit.code() += "etiss_uint8 vma = (vtype_extractMA(" + std::to_string(zimm) + ")) & 0x1;\n";
partInit.code() += "etiss_uint32 _vlmax = 0U;\n";
partInit.code() += "etiss_uint32 _illmask = 0U;\n";
partInit.code() += "etiss_uint32 vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "if (lmul & 4U) {\n";
partInit.code() += "_illmask = 2147483648U;\n";
partInit.code() += "if (lmul == 6U) {\n";
partInit.code() += "_vlmax = vlen / (8U << sew) / 4U;\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 7U) {\n";
partInit.code() += "_vlmax = vlen / (8U << sew) / 2U;\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "_vlmax = vlen / (8U << sew) / 8U;\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "_illmask = 0U;\n";
partInit.code() += "if (lmul == 0U) {\n";
partInit.code() += "_vlmax = vlen / (8U << sew);\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 1U) {\n";
partInit.code() += "_vlmax = vlen / (8U << sew) * 2U;\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 2U) {\n";
partInit.code() += "_vlmax = vlen / (8U << sew) * 4U;\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 3U) {\n";
partInit.code() += "_vlmax = vlen / (8U << sew) * 8U;\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 _avl = 0U;\n";
if (rs1 != 0U) {
partInit.code() += "_avl = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
} else if (rd != 0U) {
partInit.code() += "_avl = -1;\n";
} else {
partInit.code() += "_avl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
}
partInit.code() += "etiss_uint32 _vl = 0U;\n";
partInit.code() += "if (_avl <= _vlmax) {\n";
partInit.code() += "_vl = _avl;\n";
partInit.code() += "}\n";
partInit.code() += " else if (_avl >= (2U * _vlmax)) {\n";
partInit.code() += "_vl = _vlmax;\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "_vl = ((_avl % 2U)) ? (_avl / 2U + 1U) : (_avl / 2U);\n";
partInit.code() += "}\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(3104) + "] = _vl;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(3105) + "] = _illmask | " + std::to_string(zimm) + ";\n";
if (rd != 0U) {
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = _vl;\n";
}
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint16 zimm = 0;
static BitArrayRange R_zimm_0(30, 20);
zimm += R_zimm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vsetvli" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | zimm=" + std::to_string(zimm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSETVL ----------------------------------------------------------------------
static InstructionDefinition vsetvl_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"vsetvl",
	(uint32_t) 0x80007057,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSETVL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint16 zimm = (*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "]) & 0x7ff;\n";
partInit.code() += "etiss_uint8 sew = (vtype_extractSEW(zimm)) & 0x7;\n";
partInit.code() += "etiss_uint8 lmul = (vtype_extractLMUL(zimm)) & 0x7;\n";
partInit.code() += "etiss_uint8 vta = (vtype_extractTA(zimm)) & 0x1;\n";
partInit.code() += "etiss_uint8 vma = (vtype_extractMA(zimm)) & 0x1;\n";
partInit.code() += "etiss_uint32 _vlmax = 0U;\n";
partInit.code() += "etiss_uint32 _illmask = 0U;\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "if (lmul & 4U) {\n";
partInit.code() += "_illmask = 2147483648U;\n";
partInit.code() += "if (lmul == 6U) {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew) / 4U;\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 7U) {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew) / 2U;\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew) / 8U;\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "_illmask = 0U;\n";
partInit.code() += "if (lmul == 0U) {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew);\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 1U) {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew) * 2U;\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 2U) {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew) * 4U;\n";
partInit.code() += "}\n";
partInit.code() += " else if (lmul == 3U) {\n";
partInit.code() += "_vlmax = _vlen / (8U << sew) * 8U;\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 _avl = 0U;\n";
if (rs1 != 0U) {
partInit.code() += "_avl = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
} else if (rd != 0U) {
partInit.code() += "_avl = -1;\n";
} else {
partInit.code() += "_avl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
}
partInit.code() += "etiss_uint32 _vl = 0U;\n";
partInit.code() += "if (_avl <= _vlmax) {\n";
partInit.code() += "_vl = _avl;\n";
partInit.code() += "}\n";
partInit.code() += " else if (_avl >= (2U * _vlmax)) {\n";
partInit.code() += "_vl = _vlmax;\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "_vl = ((_avl % 2U)) ? (_avl / 2U + 1U) : (_avl / 2U);\n";
partInit.code() += "}\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(3104) + "] = _vl;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(3105) + "] = _illmask | zimm;\n";
if (rd != 0U) {
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = _vl;\n";
}
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vsetvl" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VLE8_U ----------------------------------------------------------------------
static InstructionDefinition vle8_u_vd_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vle8_u",
	(uint32_t) 0x000007,
	(uint32_t) 0xfdf0707f,
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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VLE8_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 0U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vload_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vd) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vle8_u" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VLE16_U ---------------------------------------------------------------------
static InstructionDefinition vle16_u_vd_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vle16_u",
	(uint32_t) 0x005007,
	(uint32_t) 0xfdf0707f,
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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VLE16_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 5U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vload_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vd) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vle16_u" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VLE32_U ---------------------------------------------------------------------
static InstructionDefinition vle32_u_vd_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vle32_u",
	(uint32_t) 0x006007,
	(uint32_t) 0xfdf0707f,
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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VLE32_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 6U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vload_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vd) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vle32_u" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VLE64_U ---------------------------------------------------------------------
static InstructionDefinition vle64_u_vd_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vle64_u",
	(uint32_t) 0x007007,
	(uint32_t) 0xfdf0707f,
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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VLE64_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 7U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vload_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vd) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vle64_u" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VLSEGE16 --------------------------------------------------------------------
static InstructionDefinition vlsege16_vd_rs1_vm_nf (
	ISA32_RV32IMACFDPV,
	"vlsege16",
	(uint32_t) 0x005007,
	(uint32_t) 0x1df0707f,
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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;
etiss_uint8 nf = 0;
static BitArrayRange R_nf_0(31, 29);
nf += R_nf_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VLSEGE16\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;
etiss_uint8 nf = 0;
static BitArrayRange R_nf_0(31, 29);
nf += R_nf_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vlsege16" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + " | nf=" + std::to_string(nf) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSE8_U ----------------------------------------------------------------------
static InstructionDefinition vse8_u_vs3_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vse8_u",
	(uint32_t) 0x000027,
	(uint32_t) 0xfdf0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSE8_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 0U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vstore_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vs3) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vse8_u" << " # " << ba << (" [vs3=" + std::to_string(vs3) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSE16_U ---------------------------------------------------------------------
static InstructionDefinition vse16_u_vs3_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vse16_u",
	(uint32_t) 0x005027,
	(uint32_t) 0xfdf0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSE16_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 5U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vstore_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vs3) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vse16_u" << " # " << ba << (" [vs3=" + std::to_string(vs3) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSE32_U ---------------------------------------------------------------------
static InstructionDefinition vse32_u_vs3_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vse32_u",
	(uint32_t) 0x006027,
	(uint32_t) 0xfdf0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSE32_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 6U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vstore_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vs3) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vse32_u" << " # " << ba << (" [vs3=" + std::to_string(vs3) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSE64_U ---------------------------------------------------------------------
static InstructionDefinition vse64_u_vs3_rs1_vm (
	ISA32_RV32IMACFDPV,
	"vse64_u",
	(uint32_t) 0x007027,
	(uint32_t) 0xfdf0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSE64_U\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _eew = vcfg_concatEEW(0U, 7U);\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = etiss_vstore_encoded_unitstride(cpu, system, plugin_pointers, ((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", _eew, " + std::to_string(vs3) + ", _vstart, _vlen, _vl, (etiss_uint64)(*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "]));\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vse64_u" << " # " << ba << (" [vs3=" + std::to_string(vs3) + " | rs1=" + std::to_string(rs1) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSR_V -----------------------------------------------------------------------
static InstructionDefinition vsr_v_vs3_rs1_nf (
	ISA32_RV32IMACFDPV,
	"vsr_v",
	(uint32_t) 0x2800027,
	(uint32_t) 0x1ff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 nf = 0;
static BitArrayRange R_nf_0(31, 29);
nf += R_nf_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSR_V\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vs3 = 0;
static BitArrayRange R_vs3_0(11, 7);
vs3 += R_vs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 nf = 0;
static BitArrayRange R_nf_0(31, 29);
nf += R_nf_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vsr_v" << " # " << ba << (" [vs3=" + std::to_string(vs3) + " | rs1=" + std::to_string(rs1) + " | nf=" + std::to_string(nf) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VADD_VV ---------------------------------------------------------------------
static InstructionDefinition vadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vadd_vv",
	(uint32_t) 0x000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VADD_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vadd_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VADD_VI ---------------------------------------------------------------------
static InstructionDefinition vadd_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vadd_vi",
	(uint32_t) 0x003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VADD_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vadd_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vadd_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMVR_V ----------------------------------------------------------------------
static InstructionDefinition vmvr_v_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmvr_v",
	(uint32_t) 0x9c003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMVR_V\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmvr_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VADD_VX ---------------------------------------------------------------------
static InstructionDefinition vadd_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vadd_vx",
	(uint32_t) 0x004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VADD_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vadd_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vadd_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSUB_VV ---------------------------------------------------------------------
static InstructionDefinition vsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsub_vv",
	(uint32_t) 0x8000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSUB_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsub_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSUB_VX ---------------------------------------------------------------------
static InstructionDefinition vsub_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsub_vx",
	(uint32_t) 0x8004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSUB_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsub_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsub_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VREDSUM ---------------------------------------------------------------------
static InstructionDefinition vredsum_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vredsum",
	(uint32_t) 0x002057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VREDSUM\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vredsum" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADDU_VV -------------------------------------------------------------------
static InstructionDefinition vwaddu_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwaddu_vv",
	(uint32_t) 0xc0002057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADDU_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwaddu_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwaddu_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADDU_VX -------------------------------------------------------------------
static InstructionDefinition vwaddu_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwaddu_vx",
	(uint32_t) 0xc0004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADDU_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwaddu_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwaddu_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADD_VV --------------------------------------------------------------------
static InstructionDefinition vwadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwadd_vv",
	(uint32_t) 0xc4002057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADD_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwadd_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADD_VX --------------------------------------------------------------------
static InstructionDefinition vwadd_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwadd_vx",
	(uint32_t) 0xc4006057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADD_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwadd_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwadd_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWMACC_VV -------------------------------------------------------------------
static InstructionDefinition vwmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwmacc_vv",
	(uint32_t) 0xf4002057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWMACC_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwaddu_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWMACC_VX -------------------------------------------------------------------
static InstructionDefinition vwmacc_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwmacc_vx",
	(uint32_t) 0xf4004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWMACC_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwaddu_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwmacc_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUBU_VV -------------------------------------------------------------------
static InstructionDefinition vwsubu_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsubu_vv",
	(uint32_t) 0xc8000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUBU_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsubu_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsubu_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUBU_VX -------------------------------------------------------------------
static InstructionDefinition vwsubu_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsubu_vx",
	(uint32_t) 0xc8004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUBU_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsubu_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsubu_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUB_VV --------------------------------------------------------------------
static InstructionDefinition vwsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsub_vv",
	(uint32_t) 0xcc002057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUB_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsub_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUB_VX --------------------------------------------------------------------
static InstructionDefinition vwsub_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsub_vx",
	(uint32_t) 0xcc004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUB_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsub_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsub_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADDU_W_VV -----------------------------------------------------------------
static InstructionDefinition vwaddu_w_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwaddu_w_vv",
	(uint32_t) 0xd0000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADDU_W_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwaddu_w_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwaddu_w_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADDU_W_VX -----------------------------------------------------------------
static InstructionDefinition vwaddu_w_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwaddu_w_vx",
	(uint32_t) 0xd0004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADDU_W_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwaddu_w_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwaddu_w_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADD_W_VV ------------------------------------------------------------------
static InstructionDefinition vwadd_w_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwadd_w_vv",
	(uint32_t) 0xd4000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADD_W_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwadd_w_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwadd_w_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWADD_W_VX ------------------------------------------------------------------
static InstructionDefinition vwadd_w_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwadd_w_vx",
	(uint32_t) 0xd4004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWADD_W_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwadd_w_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwadd_w_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUBU_W_VV -----------------------------------------------------------------
static InstructionDefinition vwsubu_w_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsubu_w_vv",
	(uint32_t) 0xd8000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUBU_W_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsubu_w_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsubu_w_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUBU_W_VX -----------------------------------------------------------------
static InstructionDefinition vwsubu_w_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsubu_w_vx",
	(uint32_t) 0xd8004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUBU_W_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsubu_w_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsubu_w_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUB_W_VV ------------------------------------------------------------------
static InstructionDefinition vwsub_w_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsub_w_vv",
	(uint32_t) 0xdc000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUB_W_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsub_w_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsub_w_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VWSUB_W_VX ------------------------------------------------------------------
static InstructionDefinition vwsub_w_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vwsub_w_vx",
	(uint32_t) 0xdc004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VWSUB_W_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vwsub_w_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vwsub_w_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VAND_VV ---------------------------------------------------------------------
static InstructionDefinition vand_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vand_vv",
	(uint32_t) 0x24000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VAND_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vand_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vand_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VAND_VI ---------------------------------------------------------------------
static InstructionDefinition vand_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vand_vi",
	(uint32_t) 0x24003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VAND_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vand_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vand_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VAND_VX ---------------------------------------------------------------------
static InstructionDefinition vand_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vand_vx",
	(uint32_t) 0x24004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VAND_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vand_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vand_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VOR_VV ----------------------------------------------------------------------
static InstructionDefinition vor_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vor_vv",
	(uint32_t) 0x28000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VOR_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vor_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vor_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VOR_VI ----------------------------------------------------------------------
static InstructionDefinition vor_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vor_vi",
	(uint32_t) 0x28003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VOR_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vor_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vor_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VOR_VX ----------------------------------------------------------------------
static InstructionDefinition vor_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vor_vx",
	(uint32_t) 0x28004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VOR_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vor_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vor_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VXOR_VV ---------------------------------------------------------------------
static InstructionDefinition vxor_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vxor_vv",
	(uint32_t) 0x2c000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VXOR_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vxor_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vxor_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VXOR_VI ---------------------------------------------------------------------
static InstructionDefinition vxor_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vxor_vi",
	(uint32_t) 0x2c003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VXOR_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vxor_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vxor_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VXOR_VX ---------------------------------------------------------------------
static InstructionDefinition vxor_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vxor_vx",
	(uint32_t) 0x2c004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VXOR_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vxor_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vxor_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLL_VV ---------------------------------------------------------------------
static InstructionDefinition vsll_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsll_vv",
	(uint32_t) 0x94000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLL_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsll_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsll_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLL_VI ---------------------------------------------------------------------
static InstructionDefinition vsll_vi_vd_uimm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsll_vi",
	(uint32_t) 0x94003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLL_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsll_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(uimm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vsll_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | uimm5=" + std::to_string(uimm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLL_VX ---------------------------------------------------------------------
static InstructionDefinition vsll_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsll_vx",
	(uint32_t) 0x94004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLL_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsll_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsll_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSRL_VV ---------------------------------------------------------------------
static InstructionDefinition vsrl_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsrl_vv",
	(uint32_t) 0xa0000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSRL_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsrl_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsrl_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSRL_VI ---------------------------------------------------------------------
static InstructionDefinition vsrl_vi_vd_uimm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsrl_vi",
	(uint32_t) 0xa0003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSRL_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsrl_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(uimm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vsrl_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | uimm5=" + std::to_string(uimm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSRL_VX ---------------------------------------------------------------------
static InstructionDefinition vsrl_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsrl_vx",
	(uint32_t) 0xa0004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSRL_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsrl_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsrl_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSRA_VV ---------------------------------------------------------------------
static InstructionDefinition vsra_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsra_vv",
	(uint32_t) 0xa4000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSRA_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsra_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsra_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSRA_VI ---------------------------------------------------------------------
static InstructionDefinition vsra_vi_vd_uimm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsra_vi",
	(uint32_t) 0xa4003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSRA_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsra_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(uimm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vsra_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | uimm5=" + std::to_string(uimm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSRA_VX ---------------------------------------------------------------------
static InstructionDefinition vsra_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vsra_vx",
	(uint32_t) 0xa4004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSRA_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vsra_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vsra_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSEQ_VV --------------------------------------------------------------------
static InstructionDefinition vmseq_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmseq_vv",
	(uint32_t) 0x60000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSEQ_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmseq_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmseq_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSSEQ_VI -------------------------------------------------------------------
static InstructionDefinition vmsseq_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsseq_vi",
	(uint32_t) 0x60003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSSEQ_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmseq_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmsseq_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSEQ_VX --------------------------------------------------------------------
static InstructionDefinition vmseq_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmseq_vx",
	(uint32_t) 0x60004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSEQ_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmseq_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmseq_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSNE_VV --------------------------------------------------------------------
static InstructionDefinition vmsne_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsne_vv",
	(uint32_t) 0x64000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSNE_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsne_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsne_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSNE_VI --------------------------------------------------------------------
static InstructionDefinition vmsne_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsne_vi",
	(uint32_t) 0x64003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSNE_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsne_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmsne_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSNE_VX --------------------------------------------------------------------
static InstructionDefinition vmsne_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsne_vx",
	(uint32_t) 0x64004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSNE_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsne_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsne_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLTU_VV -------------------------------------------------------------------
static InstructionDefinition vmsltu_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsltu_vv",
	(uint32_t) 0x68000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLTU_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsltu_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsltu_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLTU_VX -------------------------------------------------------------------
static InstructionDefinition vmsltu_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsltu_vx",
	(uint32_t) 0x68004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLTU_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsltu_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsltu_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLT_VV --------------------------------------------------------------------
static InstructionDefinition vmslt_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmslt_vv",
	(uint32_t) 0x6c000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLT_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmslt_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmslt_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLT_VX --------------------------------------------------------------------
static InstructionDefinition vmslt_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmslt_vx",
	(uint32_t) 0x6c004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLT_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmslt_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmslt_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLEU_VV -------------------------------------------------------------------
static InstructionDefinition vmsleu_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsleu_vv",
	(uint32_t) 0x70000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLEU_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsleu_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsleu_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLEU_VI -------------------------------------------------------------------
static InstructionDefinition vmsleu_vi_vd_uimm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsleu_vi",
	(uint32_t) 0x70003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLEU_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsleu_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(uimm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 uimm5 = 0;
static BitArrayRange R_uimm5_0(19, 15);
uimm5 += R_uimm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmsleu_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | uimm5=" + std::to_string(uimm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLEU_VX -------------------------------------------------------------------
static InstructionDefinition vmsleu_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsleu_vx",
	(uint32_t) 0x70004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLEU_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsleu_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsleu_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLE_VV --------------------------------------------------------------------
static InstructionDefinition vmsle_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsle_vv",
	(uint32_t) 0x74000057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLE_VV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsle_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs1) + ", " + std::to_string(vs2) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsle_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLE_VI --------------------------------------------------------------------
static InstructionDefinition vmsle_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsle_vi",
	(uint32_t) 0x74003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLE_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsle_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmsle_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSLE_VX --------------------------------------------------------------------
static InstructionDefinition vmsle_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsle_vx",
	(uint32_t) 0x74004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSLE_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsle_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsle_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSGTU_VX -------------------------------------------------------------------
static InstructionDefinition vmsgtu_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsgtu_vx",
	(uint32_t) 0x78004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSGTU_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsgtu_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsgtu_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMSGT_VX --------------------------------------------------------------------
static InstructionDefinition vmsgt_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vmsgt_vx",
	(uint32_t) 0x7c004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMSGT_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmsgt_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmsgt_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMV_V_V ---------------------------------------------------------------------
static InstructionDefinition vmv_v_v_vd_vs1 (
	ISA32_RV32IMACFDPV,
	"vmv_v_v",
	(uint32_t) 0x5e000057,
	(uint32_t) 0xfff0707f,
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

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMV_V_V\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmv_vv(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vd) + ", " + std::to_string(vs1) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmv_v_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMV_V_I ---------------------------------------------------------------------
static InstructionDefinition vmv_v_i_vd_simm5 (
	ISA32_RV32IMACFDPV,
	"vmv_v_i",
	(uint32_t) 0x5e003057,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMV_V_I\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmv_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vd) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmv_v_i" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMV_V_X ---------------------------------------------------------------------
static InstructionDefinition vmv_v_x_vd_rs1 (
	ISA32_RV32IMACFDPV,
	"vmv_v_x",
	(uint32_t) 0x5e004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMV_V_X\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmv_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vd) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmv_v_x" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMV_X_S ---------------------------------------------------------------------
static InstructionDefinition vmv_x_s_rd_vs2 (
	ISA32_RV32IMACFDPV,
	"vmv_x_s",
	(uint32_t) 0x42004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMV_X_S\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 ret = vmv_xs(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(rd) + ", " + std::to_string(vs2) + ", _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
}
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmv_x_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | vs2=" + std::to_string(vs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMV_S_X ---------------------------------------------------------------------
static InstructionDefinition vmv_s_x_vd_rs1 (
	ISA32_RV32IMACFDPV,
	"vmv_s_x",
	(uint32_t) 0x42006057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VMV_S_X\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vmv_sx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vd) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vmv_s_x" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLIDEUP_VI -----------------------------------------------------------------
static InstructionDefinition vslideup_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vslideup_vi",
	(uint32_t) 0x38003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLIDEUP_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vslideup_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vslideup_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLIDEUP_VX -----------------------------------------------------------------
static InstructionDefinition vslideup_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vslideup_vx",
	(uint32_t) 0x38004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLIDEUP_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vslideup_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vslideup_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLIDEDOWN_VI ---------------------------------------------------------------
static InstructionDefinition vslidedown_vi_vd_simm5_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vslidedown_vi",
	(uint32_t) 0x3c003057,
	(uint32_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLIDEDOWN_VI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vslidedown_vi(((RV32IMACFDPV*)cpu)->V, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(simm5) + ", _vstart, _vlen, _vl);\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 simm5 = 0;
static BitArrayRange R_simm5_0(19, 15);
simm5 += R_simm5_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vslidedown_vi" << " # " << ba << (" [vd=" + std::to_string(vd) + " | simm5=" + std::to_string(simm5) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLIDEDOWN_VX ---------------------------------------------------------------
static InstructionDefinition vslidedown_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vslidedown_vx",
	(uint32_t) 0x3c004057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLIDEDOWN_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vslidedown_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vslidedown_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLIDE1UP_VX ----------------------------------------------------------------
static InstructionDefinition vslide1up_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vslide1up_vx",
	(uint32_t) 0x38006057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLIDE1UP_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vslide1up_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vslide1up_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VSLIDE1DOWN_VX --------------------------------------------------------------
static InstructionDefinition vslide1down_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDPV,
	"vslide1down_vx",
	(uint32_t) 0x3c006057,
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//VSLIDE1DOWN_VX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 _vtype = *((RV32IMACFDPV*)cpu)->CSR[3105U];\n";
partInit.code() += "etiss_uint32 _vstart = *((RV32IMACFDPV*)cpu)->CSR[8U];\n";
partInit.code() += "etiss_uint32 _vl = *((RV32IMACFDPV*)cpu)->CSR[3104U];\n";
partInit.code() += "etiss_uint32 _vlen = *((RV32IMACFDPV*)cpu)->CSR[3106U] * 8U;\n";
partInit.code() += "etiss_uint32 ret = vslide1down_vx(((RV32IMACFDPV*)cpu)->V, *((RV32IMACFDPV*)cpu)->X, _vtype, " + std::to_string(vm) + ", " + std::to_string(vd) + ", " + std::to_string(vs2) + ", " + std::to_string(rs1) + ", _vstart, _vlen, _vl, " + std::to_string(32) + ");\n";
partInit.code() += "if (ret != 0U) {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = ret >> 8U;\n";
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->CSR[" + std::to_string(8) + "] = 0U;\n";
partInit.code() += "}\n";
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
ss << "vslide1down_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
