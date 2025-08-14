/**
 * Generated on Thu, 14 Aug 2025 12:04:42 +0200.
 *
 * This file contains the instruction behavior models of the dotprod
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// DOTP ------------------------------------------------------------------------
static InstructionDefinition dotp_rd_rs1_rs2 (
	ISA32_RV32IMACFD,
	"dotp",
	(uint32_t) 0x1200000b,
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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//DOTP\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = 0ULL;\n";
etiss_int32 i = 0ULL;
while (i < 32ULL) {
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int16 prod = (etiss_int32)(etiss_int8)((((*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1) + "ULL]) >> (" + std::to_string(i) + "LL)) & ((1 << ((" + std::to_string(i + 7ULL) + "LL) - (" + std::to_string(i) + "LL) + 1)) - 1))) * (etiss_int32)(etiss_int8)((((*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (" + std::to_string(i) + "LL)) & ((1 << ((" + std::to_string(i + 7ULL) + "LL) - (" + std::to_string(i) + "LL) + 1)) - 1)));\n";
cp.code() += "res = res + prod;\n";
cp.code() += "} // block\n";
} // block
i = i + 8ULL;
}
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "dotp" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
