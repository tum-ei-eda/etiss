/**
 * Generated on Wed, 06 Jul 2022 16:52:28 +0200.
 *
 * This file contains the instruction behavior models of the RV32Zbpo
 * instruction set for the RV32IMACFDPV core architecture.
 */

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// CLZ -------------------------------------------------------------------------
static InstructionDefinition clz_rd_rs1 (
	ISA32_RV32IMACFDPV,
	"clz",
	(uint32_t) 0x60001013,
	(uint32_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CLZ\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
etiss_uint32 count = 0U;
etiss_uint32 i = 32U;
while (i > 0U) {
i = i - 1U;
partInit.code() += "if ((((rs1_val) >> (" + std::to_string(i) + ")) & ((1 << ((i) - (i) + 1)) - 1)) == 0U) {\n";
count = count + 1U;
partInit.code() += "}\n";
partInit.code() += " else {\n";
i = 0U;
partInit.code() += "}\n";
}
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(count) + ";\n";
}
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
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "clz" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
