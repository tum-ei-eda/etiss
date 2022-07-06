/**
 * Generated on Thu, 12 May 2022 16:30:21 +0200.
 *
 * This file contains the architecture class for the RV32IMACFDPV core architecture.
 */

/*********************************************************************************************************************************

* Modification guidelines:

	 1. The initial value of SP register should be initialized by ctr0.S/board.S. If not, it could be initialized
		 through utility class etiss::VirtualStruct::Field.

	 2. Debug mode print out all assignment results. GDB in 8 is prefered.

	 3. Manually copy the content in bracket ["return ETISS_RETURNCODE_CPUFINISHED; \n"] to terminating instruction,
		 otherwise the emulation can not be ended.

	 4. If subset of encoding error occurs, it means the format of the encoding in the input model was not appropriate

	 5. If the PC register points to wrong address, please notice that some assembly may cause branch operation
		 implicitly such as "MOV Rd Rn" in ARMv6-M

	 6. If a variable is the result of dynamic slicing such as, var_1 = var_2<Hshift-1..Lshift-2>, the size would be
		 calculated during process (if possible), otherwise it is assumed to be the register size. Problems may occur when
		 var_1 encounters bit manipulation such as "~" due to bit expansion. To change the nml model with explicit slicing
		 e.g var_1 = val_2<3..0> or avoid bit manipulation for dynamic sliced variable. Otherwise, you have to manually
		 correct it.

	 7. Implementation dependent functionalities such as exception handling should be manully added. Corresponding interfaces
		 are provided in RV32IMACFDPVArchSpecificImp.h

	 8. RV32IMACFDPVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

#define RV32IMACFDPV_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

RV32IMACFDPVArch::RV32IMACFDPVArch():CPUArch("RV32IMACFDPV")
{
	headers_.insert("Arch/RV32IMACFDPV/RV32IMACFDPV.h");
}

const std::set<std::string> & RV32IMACFDPVArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV32IMACFDPVArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV32IMACFDPV() ;
	resetCPU (ret, 0);
	return ret;
}

void RV32IMACFDPVArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV32IMACFDPV));
	RV32IMACFDPV * rv32imacfdpvcpu = (RV32IMACFDPV *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv32imacfdpvcpu->ins_X[i] = 0;
		rv32imacfdpvcpu->X[i] = &rv32imacfdpvcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv32imacfdpvcpu->ins_CSR[i] = 0;
		rv32imacfdpvcpu->CSR[i] = &rv32imacfdpvcpu->ins_CSR[i];
	}

	rv32imacfdpvcpu->ZERO = 0;
	rv32imacfdpvcpu->RA = 0;
	rv32imacfdpvcpu->SP = 0;
	rv32imacfdpvcpu->GP = 0;
	rv32imacfdpvcpu->TP = 0;
	rv32imacfdpvcpu->T0 = 0;
	rv32imacfdpvcpu->T1 = 0;
	rv32imacfdpvcpu->T2 = 0;
	rv32imacfdpvcpu->S0 = 0;
	rv32imacfdpvcpu->S1 = 0;
	rv32imacfdpvcpu->A0 = 0;
	rv32imacfdpvcpu->A1 = 0;
	rv32imacfdpvcpu->A2 = 0;
	rv32imacfdpvcpu->A3 = 0;
	rv32imacfdpvcpu->A4 = 0;
	rv32imacfdpvcpu->A5 = 0;
	rv32imacfdpvcpu->A6 = 0;
	rv32imacfdpvcpu->A7 = 0;
	rv32imacfdpvcpu->S2 = 0;
	rv32imacfdpvcpu->S3 = 0;
	rv32imacfdpvcpu->S4 = 0;
	rv32imacfdpvcpu->S5 = 0;
	rv32imacfdpvcpu->S6 = 0;
	rv32imacfdpvcpu->S7 = 0;
	rv32imacfdpvcpu->S8 = 0;
	rv32imacfdpvcpu->S9 = 0;
	rv32imacfdpvcpu->S10 = 0;
	rv32imacfdpvcpu->S11 = 0;
	rv32imacfdpvcpu->T3 = 0;
	rv32imacfdpvcpu->T4 = 0;
	rv32imacfdpvcpu->T5 = 0;
	rv32imacfdpvcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv32imacfdpvcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv32imacfdpvcpu->RES[i] = 0;
	}
	rv32imacfdpvcpu->PRIV = 0;
	rv32imacfdpvcpu->DPC = 0;
	rv32imacfdpvcpu->FCSR = 0;
	rv32imacfdpvcpu->VXSAT_CSR__ = 0;
	rv32imacfdpvcpu->VXSAT_CSR_ = 0;
	rv32imacfdpvcpu->VSTART_CSR = 0;
	rv32imacfdpvcpu->VXSAT_CSR = 0;
	rv32imacfdpvcpu->VXRM_CSR = 0;
	rv32imacfdpvcpu->VCSR_CSR = 0;
	rv32imacfdpvcpu->VL_CSR = 0;
	rv32imacfdpvcpu->VTYPE_CSR = 0;
	rv32imacfdpvcpu->VLENB_CSR = 0;
	for (int i = 0; i < 32; ++i) {
		rv32imacfdpvcpu->F[i] = 0;
	}
	for (int i = 0; i < 32768; ++i) {
		rv32imacfdpvcpu->V[i] = 0;
	}
	rv32imacfdpvcpu->RES_ADDR = 0;

 	rv32imacfdpvcpu->X[0] = &rv32imacfdpvcpu->ZERO;
 	rv32imacfdpvcpu->X[1] = &rv32imacfdpvcpu->RA;
 	rv32imacfdpvcpu->X[2] = &rv32imacfdpvcpu->SP;
 	rv32imacfdpvcpu->X[3] = &rv32imacfdpvcpu->GP;
 	rv32imacfdpvcpu->X[4] = &rv32imacfdpvcpu->TP;
 	rv32imacfdpvcpu->X[5] = &rv32imacfdpvcpu->T0;
 	rv32imacfdpvcpu->X[6] = &rv32imacfdpvcpu->T1;
 	rv32imacfdpvcpu->X[7] = &rv32imacfdpvcpu->T2;
 	rv32imacfdpvcpu->X[8] = &rv32imacfdpvcpu->S0;
 	rv32imacfdpvcpu->X[9] = &rv32imacfdpvcpu->S1;
 	rv32imacfdpvcpu->X[10] = &rv32imacfdpvcpu->A0;
 	rv32imacfdpvcpu->X[11] = &rv32imacfdpvcpu->A1;
 	rv32imacfdpvcpu->X[12] = &rv32imacfdpvcpu->A2;
 	rv32imacfdpvcpu->X[13] = &rv32imacfdpvcpu->A3;
 	rv32imacfdpvcpu->X[14] = &rv32imacfdpvcpu->A4;
 	rv32imacfdpvcpu->X[15] = &rv32imacfdpvcpu->A5;
 	rv32imacfdpvcpu->X[16] = &rv32imacfdpvcpu->A6;
 	rv32imacfdpvcpu->X[17] = &rv32imacfdpvcpu->A7;
 	rv32imacfdpvcpu->X[18] = &rv32imacfdpvcpu->S2;
 	rv32imacfdpvcpu->X[19] = &rv32imacfdpvcpu->S3;
 	rv32imacfdpvcpu->X[20] = &rv32imacfdpvcpu->S4;
 	rv32imacfdpvcpu->X[21] = &rv32imacfdpvcpu->S5;
 	rv32imacfdpvcpu->X[22] = &rv32imacfdpvcpu->S6;
 	rv32imacfdpvcpu->X[23] = &rv32imacfdpvcpu->S7;
 	rv32imacfdpvcpu->X[24] = &rv32imacfdpvcpu->S8;
 	rv32imacfdpvcpu->X[25] = &rv32imacfdpvcpu->S9;
 	rv32imacfdpvcpu->X[26] = &rv32imacfdpvcpu->S10;
 	rv32imacfdpvcpu->X[27] = &rv32imacfdpvcpu->S11;
 	rv32imacfdpvcpu->X[28] = &rv32imacfdpvcpu->T3;
 	rv32imacfdpvcpu->X[29] = &rv32imacfdpvcpu->T4;
 	rv32imacfdpvcpu->X[30] = &rv32imacfdpvcpu->T5;
 	rv32imacfdpvcpu->X[31] = &rv32imacfdpvcpu->T6;
 	rv32imacfdpvcpu->CSR[3] = &rv32imacfdpvcpu->FCSR;
 	rv32imacfdpvcpu->CSR[9] = &rv32imacfdpvcpu->VXSAT_CSR__;
 	rv32imacfdpvcpu->CSR[9] = &rv32imacfdpvcpu->VXSAT_CSR_;
 	rv32imacfdpvcpu->CSR[8] = &rv32imacfdpvcpu->VSTART_CSR;
 	rv32imacfdpvcpu->CSR[9] = &rv32imacfdpvcpu->VXSAT_CSR;
 	rv32imacfdpvcpu->CSR[10] = &rv32imacfdpvcpu->VXRM_CSR;
 	rv32imacfdpvcpu->CSR[15] = &rv32imacfdpvcpu->VCSR_CSR;
 	rv32imacfdpvcpu->CSR[3104] = &rv32imacfdpvcpu->VL_CSR;
 	rv32imacfdpvcpu->CSR[3105] = &rv32imacfdpvcpu->VTYPE_CSR;
 	rv32imacfdpvcpu->CSR[3106] = &rv32imacfdpvcpu->VLENB_CSR;

 	rv32imacfdpvcpu->PRIV = 3;
 	rv32imacfdpvcpu->DPC = 0;
 	*rv32imacfdpvcpu->CSR[0] = 11;
	*rv32imacfdpvcpu->CSR[256] = 11;
	*rv32imacfdpvcpu->CSR[768] = 1536;
	*rv32imacfdpvcpu->CSR[769] = 1075056941;
	*rv32imacfdpvcpu->CSR[3088] = 3;
	*rv32imacfdpvcpu->CSR[772] = 4294966203;
	*rv32imacfdpvcpu->CSR[260] = 4294964019;
	*rv32imacfdpvcpu->CSR[4] = 4294963473;
	*rv32imacfdpvcpu->CSR[3105] = 2147483648;
	*rv32imacfdpvcpu->CSR[3104] = 0;
	*rv32imacfdpvcpu->CSR[3106] = 128;
 	rv32imacfdpvcpu->RES_ADDR = -1;
}

void RV32IMACFDPVArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV32IMACFDPV *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMACFDPVArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV32IMACFDPVArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV32IMACFDPV.h)
*/
const std::set<std::string> & RV32IMACFDPVArch::getHeaders() const
{
	return headers_ ;
}

void RV32IMACFDPVArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDPV/RV32IMACFDPV.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDPV/RV32IMACFDPVFuncs.h\"\n");
	cb.functionglobalCode().insert("((RV32IMACFDPV*)cpu)->exception = 0;\n");
	cb.functionglobalCode().insert("((RV32IMACFDPV*)cpu)->exception_pending = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV32IMACFDPVArch::getGDBCore()
{
	return gdbcore_;
}

const char * const reg_name[] =
{
	"X0",
	"X1",
	"X2",
	"X3",
	"X4",
	"X5",
	"X6",
	"X7",
	"X8",
	"X9",
	"X10",
	"X11",
	"X12",
	"X13",
	"X14",
	"X15",
	"X16",
	"X17",
	"X18",
	"X19",
	"X20",
	"X21",
	"X22",
	"X23",
	"X24",
	"X25",
	"X26",
	"X27",
	"X28",
	"X29",
	"X30",
	"X31",
};

etiss::instr::InstructionGroup ISA16_RV32IMACFDPV("ISA16_RV32IMACFDPV", 16);
etiss::instr::InstructionClass ISA16_RV32IMACFDPVClass(1, "ISA16_RV32IMACFDPV", 16, ISA16_RV32IMACFDPV);
etiss::instr::InstructionGroup ISA32_RV32IMACFDPV("ISA32_RV32IMACFDPV", 32);
etiss::instr::InstructionClass ISA32_RV32IMACFDPVClass(1, "ISA32_RV32IMACFDPV", 32, ISA32_RV32IMACFDPV);

etiss::instr::InstructionCollection RV32IMACFDPVISA("RV32IMACFDPVISA", ISA16_RV32IMACFDPVClass, ISA32_RV32IMACFDPVClass);