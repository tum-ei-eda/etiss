/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the architecture class for the RV64IMACFDV core architecture.
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
		 are provided in RV64IMACFDVArchSpecificImp.h

	 8. RV64IMACFDVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV64IMACFDVArch.h"
#include "RV64IMACFDVFuncs.h"

#define RV64IMACFDV_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

RV64IMACFDVArch::RV64IMACFDVArch(unsigned int coreno):CPUArch("RV64IMACFDV"), coreno_(coreno)
{
	headers_.insert("Arch/RV64IMACFDV/RV64IMACFDV.h");
}

const std::set<std::string> & RV64IMACFDVArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV64IMACFDVArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV64IMACFDV() ;
	resetCPU (ret, 0);
	return ret;
}

void RV64IMACFDVArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV64IMACFDV));
	RV64IMACFDV * rv64imacfdvcpu = (RV64IMACFDV *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->nextPc = cpu->instructionPointer;
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv64imacfdvcpu->ins_X[i] = 0;
		rv64imacfdvcpu->X[i] = &rv64imacfdvcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv64imacfdvcpu->ins_CSR[i] = 0;
		rv64imacfdvcpu->CSR[i] = &rv64imacfdvcpu->ins_CSR[i];
	}
	for (int i = 0; i < 32; ++i) {
		rv64imacfdvcpu->ins_F[i] = 0;
		rv64imacfdvcpu->F[i] = &rv64imacfdvcpu->ins_F[i];
	}

	rv64imacfdvcpu->ZERO = 0;
	rv64imacfdvcpu->RA = 0;
	rv64imacfdvcpu->SP = 0;
	rv64imacfdvcpu->GP = 0;
	rv64imacfdvcpu->TP = 0;
	rv64imacfdvcpu->T0 = 0;
	rv64imacfdvcpu->T1 = 0;
	rv64imacfdvcpu->T2 = 0;
	rv64imacfdvcpu->S0 = 0;
	rv64imacfdvcpu->S1 = 0;
	rv64imacfdvcpu->A0 = 0;
	rv64imacfdvcpu->A1 = 0;
	rv64imacfdvcpu->A2 = 0;
	rv64imacfdvcpu->A3 = 0;
	rv64imacfdvcpu->A4 = 0;
	rv64imacfdvcpu->A5 = 0;
	rv64imacfdvcpu->A6 = 0;
	rv64imacfdvcpu->A7 = 0;
	rv64imacfdvcpu->S2 = 0;
	rv64imacfdvcpu->S3 = 0;
	rv64imacfdvcpu->S4 = 0;
	rv64imacfdvcpu->S5 = 0;
	rv64imacfdvcpu->S6 = 0;
	rv64imacfdvcpu->S7 = 0;
	rv64imacfdvcpu->S8 = 0;
	rv64imacfdvcpu->S9 = 0;
	rv64imacfdvcpu->S10 = 0;
	rv64imacfdvcpu->S11 = 0;
	rv64imacfdvcpu->T3 = 0;
	rv64imacfdvcpu->T4 = 0;
	rv64imacfdvcpu->T5 = 0;
	rv64imacfdvcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv64imacfdvcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv64imacfdvcpu->RES[i] = 0;
	}
	rv64imacfdvcpu->PRIV = 0;
	rv64imacfdvcpu->DPC = 0;
	rv64imacfdvcpu->VSTART_CSR = 0;
	rv64imacfdvcpu->VXSAT_CSR = 0;
	rv64imacfdvcpu->VXRM_CSR = 0;
	rv64imacfdvcpu->VCSR_CSR = 0;
	rv64imacfdvcpu->VL_CSR = 0;
	rv64imacfdvcpu->VTYPE_CSR = 0;
	rv64imacfdvcpu->VLENB_CSR = 0;
	rv64imacfdvcpu->FCSR = 0;
	rv64imacfdvcpu->FFLAGS = 0;
	rv64imacfdvcpu->FRM = 0;
	rv64imacfdvcpu->MSTATUS = 0;
	rv64imacfdvcpu->MIE = 0;
	rv64imacfdvcpu->MIP = 0;
	rv64imacfdvcpu->CYCLE = 0;
	rv64imacfdvcpu->CYCLEH = 0;
	rv64imacfdvcpu->TIME = 0;
	rv64imacfdvcpu->TIMEH = 0;
	rv64imacfdvcpu->INSTRET = 0;
	rv64imacfdvcpu->INSTRETH = 0;
	rv64imacfdvcpu->MVENDORID = 0;
	rv64imacfdvcpu->MARCHID = 0;
	rv64imacfdvcpu->MIMPID = 0;
	rv64imacfdvcpu->MHARTID = 0;
	rv64imacfdvcpu->MISA = 0;
	rv64imacfdvcpu->MEDELEG = 0;
	rv64imacfdvcpu->MIDELEG = 0;
	rv64imacfdvcpu->MTVEC = 0;
	rv64imacfdvcpu->MCOUNTEREN = 0;
	rv64imacfdvcpu->MSCRATCH = 0;
	rv64imacfdvcpu->MEPC = 0;
	rv64imacfdvcpu->MCAUSE = 0;
	rv64imacfdvcpu->MTVAL = 0;
	for (int i = 0; i < 4096; ++i) {
		rv64imacfdvcpu->V[i] = 0;
	}
	rv64imacfdvcpu->FT0 = 0;
	rv64imacfdvcpu->FT1 = 0;
	rv64imacfdvcpu->FT2 = 0;
	rv64imacfdvcpu->FT3 = 0;
	rv64imacfdvcpu->FT4 = 0;
	rv64imacfdvcpu->FT5 = 0;
	rv64imacfdvcpu->FT6 = 0;
	rv64imacfdvcpu->FT7 = 0;
	rv64imacfdvcpu->FS0 = 0;
	rv64imacfdvcpu->FS1 = 0;
	rv64imacfdvcpu->FA0 = 0;
	rv64imacfdvcpu->FA1 = 0;
	rv64imacfdvcpu->FA2 = 0;
	rv64imacfdvcpu->FA3 = 0;
	rv64imacfdvcpu->FA4 = 0;
	rv64imacfdvcpu->FA5 = 0;
	rv64imacfdvcpu->FA6 = 0;
	rv64imacfdvcpu->FA7 = 0;
	rv64imacfdvcpu->FS2 = 0;
	rv64imacfdvcpu->FS3 = 0;
	rv64imacfdvcpu->FS4 = 0;
	rv64imacfdvcpu->FS5 = 0;
	rv64imacfdvcpu->FS6 = 0;
	rv64imacfdvcpu->FS7 = 0;
	rv64imacfdvcpu->FS8 = 0;
	rv64imacfdvcpu->FS9 = 0;
	rv64imacfdvcpu->FS10 = 0;
	rv64imacfdvcpu->FS11 = 0;
	rv64imacfdvcpu->FT8 = 0;
	rv64imacfdvcpu->FT9 = 0;
	rv64imacfdvcpu->FT10 = 0;
	rv64imacfdvcpu->FT11 = 0;
	rv64imacfdvcpu->RES_ADDR = 0;

 	rv64imacfdvcpu->X[0] = &rv64imacfdvcpu->ZERO;
 	rv64imacfdvcpu->X[1] = &rv64imacfdvcpu->RA;
 	rv64imacfdvcpu->X[2] = &rv64imacfdvcpu->SP;
 	rv64imacfdvcpu->X[3] = &rv64imacfdvcpu->GP;
 	rv64imacfdvcpu->X[4] = &rv64imacfdvcpu->TP;
 	rv64imacfdvcpu->X[5] = &rv64imacfdvcpu->T0;
 	rv64imacfdvcpu->X[6] = &rv64imacfdvcpu->T1;
 	rv64imacfdvcpu->X[7] = &rv64imacfdvcpu->T2;
 	rv64imacfdvcpu->X[8] = &rv64imacfdvcpu->S0;
 	rv64imacfdvcpu->X[9] = &rv64imacfdvcpu->S1;
 	rv64imacfdvcpu->X[10] = &rv64imacfdvcpu->A0;
 	rv64imacfdvcpu->X[11] = &rv64imacfdvcpu->A1;
 	rv64imacfdvcpu->X[12] = &rv64imacfdvcpu->A2;
 	rv64imacfdvcpu->X[13] = &rv64imacfdvcpu->A3;
 	rv64imacfdvcpu->X[14] = &rv64imacfdvcpu->A4;
 	rv64imacfdvcpu->X[15] = &rv64imacfdvcpu->A5;
 	rv64imacfdvcpu->X[16] = &rv64imacfdvcpu->A6;
 	rv64imacfdvcpu->X[17] = &rv64imacfdvcpu->A7;
 	rv64imacfdvcpu->X[18] = &rv64imacfdvcpu->S2;
 	rv64imacfdvcpu->X[19] = &rv64imacfdvcpu->S3;
 	rv64imacfdvcpu->X[20] = &rv64imacfdvcpu->S4;
 	rv64imacfdvcpu->X[21] = &rv64imacfdvcpu->S5;
 	rv64imacfdvcpu->X[22] = &rv64imacfdvcpu->S6;
 	rv64imacfdvcpu->X[23] = &rv64imacfdvcpu->S7;
 	rv64imacfdvcpu->X[24] = &rv64imacfdvcpu->S8;
 	rv64imacfdvcpu->X[25] = &rv64imacfdvcpu->S9;
 	rv64imacfdvcpu->X[26] = &rv64imacfdvcpu->S10;
 	rv64imacfdvcpu->X[27] = &rv64imacfdvcpu->S11;
 	rv64imacfdvcpu->X[28] = &rv64imacfdvcpu->T3;
 	rv64imacfdvcpu->X[29] = &rv64imacfdvcpu->T4;
 	rv64imacfdvcpu->X[30] = &rv64imacfdvcpu->T5;
 	rv64imacfdvcpu->X[31] = &rv64imacfdvcpu->T6;
 	rv64imacfdvcpu->CSR[8] = &rv64imacfdvcpu->VSTART_CSR;
 	rv64imacfdvcpu->CSR[9] = &rv64imacfdvcpu->VXSAT_CSR;
 	rv64imacfdvcpu->CSR[10] = &rv64imacfdvcpu->VXRM_CSR;
 	rv64imacfdvcpu->CSR[15] = &rv64imacfdvcpu->VCSR_CSR;
 	rv64imacfdvcpu->CSR[3104] = &rv64imacfdvcpu->VL_CSR;
 	rv64imacfdvcpu->CSR[3105] = &rv64imacfdvcpu->VTYPE_CSR;
 	rv64imacfdvcpu->CSR[3106] = &rv64imacfdvcpu->VLENB_CSR;
 	rv64imacfdvcpu->CSR[3] = &rv64imacfdvcpu->FCSR;
 	rv64imacfdvcpu->CSR[1] = &rv64imacfdvcpu->FFLAGS;
 	rv64imacfdvcpu->CSR[2] = &rv64imacfdvcpu->FRM;
 	rv64imacfdvcpu->CSR[768] = &rv64imacfdvcpu->MSTATUS;
 	rv64imacfdvcpu->CSR[772] = &rv64imacfdvcpu->MIE;
 	rv64imacfdvcpu->CSR[836] = &rv64imacfdvcpu->MIP;
 	rv64imacfdvcpu->CSR[3072] = &rv64imacfdvcpu->CYCLE;
 	rv64imacfdvcpu->CSR[3200] = &rv64imacfdvcpu->CYCLEH;
 	rv64imacfdvcpu->CSR[3073] = &rv64imacfdvcpu->TIME;
 	rv64imacfdvcpu->CSR[3201] = &rv64imacfdvcpu->TIMEH;
 	rv64imacfdvcpu->CSR[3074] = &rv64imacfdvcpu->INSTRET;
 	rv64imacfdvcpu->CSR[3202] = &rv64imacfdvcpu->INSTRETH;
 	rv64imacfdvcpu->CSR[3857] = &rv64imacfdvcpu->MVENDORID;
 	rv64imacfdvcpu->CSR[3858] = &rv64imacfdvcpu->MARCHID;
 	rv64imacfdvcpu->CSR[3859] = &rv64imacfdvcpu->MIMPID;
 	rv64imacfdvcpu->CSR[3860] = &rv64imacfdvcpu->MHARTID;
 	rv64imacfdvcpu->CSR[769] = &rv64imacfdvcpu->MISA;
 	rv64imacfdvcpu->CSR[770] = &rv64imacfdvcpu->MEDELEG;
 	rv64imacfdvcpu->CSR[771] = &rv64imacfdvcpu->MIDELEG;
 	rv64imacfdvcpu->CSR[773] = &rv64imacfdvcpu->MTVEC;
 	rv64imacfdvcpu->CSR[774] = &rv64imacfdvcpu->MCOUNTEREN;
 	rv64imacfdvcpu->CSR[832] = &rv64imacfdvcpu->MSCRATCH;
 	rv64imacfdvcpu->CSR[833] = &rv64imacfdvcpu->MEPC;
 	rv64imacfdvcpu->CSR[834] = &rv64imacfdvcpu->MCAUSE;
 	rv64imacfdvcpu->CSR[835] = &rv64imacfdvcpu->MTVAL;
 	rv64imacfdvcpu->F[0] = &rv64imacfdvcpu->FT0;
 	rv64imacfdvcpu->F[1] = &rv64imacfdvcpu->FT1;
 	rv64imacfdvcpu->F[2] = &rv64imacfdvcpu->FT2;
 	rv64imacfdvcpu->F[3] = &rv64imacfdvcpu->FT3;
 	rv64imacfdvcpu->F[4] = &rv64imacfdvcpu->FT4;
 	rv64imacfdvcpu->F[5] = &rv64imacfdvcpu->FT5;
 	rv64imacfdvcpu->F[6] = &rv64imacfdvcpu->FT6;
 	rv64imacfdvcpu->F[7] = &rv64imacfdvcpu->FT7;
 	rv64imacfdvcpu->F[8] = &rv64imacfdvcpu->FS0;
 	rv64imacfdvcpu->F[9] = &rv64imacfdvcpu->FS1;
 	rv64imacfdvcpu->F[10] = &rv64imacfdvcpu->FA0;
 	rv64imacfdvcpu->F[11] = &rv64imacfdvcpu->FA1;
 	rv64imacfdvcpu->F[12] = &rv64imacfdvcpu->FA2;
 	rv64imacfdvcpu->F[13] = &rv64imacfdvcpu->FA3;
 	rv64imacfdvcpu->F[14] = &rv64imacfdvcpu->FA4;
 	rv64imacfdvcpu->F[15] = &rv64imacfdvcpu->FA5;
 	rv64imacfdvcpu->F[16] = &rv64imacfdvcpu->FA6;
 	rv64imacfdvcpu->F[17] = &rv64imacfdvcpu->FA7;
 	rv64imacfdvcpu->F[18] = &rv64imacfdvcpu->FS2;
 	rv64imacfdvcpu->F[19] = &rv64imacfdvcpu->FS3;
 	rv64imacfdvcpu->F[20] = &rv64imacfdvcpu->FS4;
 	rv64imacfdvcpu->F[21] = &rv64imacfdvcpu->FS5;
 	rv64imacfdvcpu->F[22] = &rv64imacfdvcpu->FS6;
 	rv64imacfdvcpu->F[23] = &rv64imacfdvcpu->FS7;
 	rv64imacfdvcpu->F[24] = &rv64imacfdvcpu->FS8;
 	rv64imacfdvcpu->F[25] = &rv64imacfdvcpu->FS9;
 	rv64imacfdvcpu->F[26] = &rv64imacfdvcpu->FS10;
 	rv64imacfdvcpu->F[27] = &rv64imacfdvcpu->FS11;
 	rv64imacfdvcpu->F[28] = &rv64imacfdvcpu->FT8;
 	rv64imacfdvcpu->F[29] = &rv64imacfdvcpu->FT9;
 	rv64imacfdvcpu->F[30] = &rv64imacfdvcpu->FT10;
 	rv64imacfdvcpu->F[31] = &rv64imacfdvcpu->FT11;

   	rv64imacfdvcpu->PRIV = 3ULL;
   	rv64imacfdvcpu->DPC = 0LL;
  	*rv64imacfdvcpu->CSR[0] = 11ULL;
 	*rv64imacfdvcpu->CSR[256] = 11ULL;
 	*rv64imacfdvcpu->CSR[768] = 1536ULL;
 	*rv64imacfdvcpu->CSR[769] = 9223372036856090925ULL;
 	*rv64imacfdvcpu->CSR[3088] = 3ULL;
 	*rv64imacfdvcpu->CSR[772] = 4294966203ULL;
 	*rv64imacfdvcpu->CSR[260] = 4294964019ULL;
 	*rv64imacfdvcpu->CSR[4] = 4294963473ULL;
 	*rv64imacfdvcpu->CSR[3105] = 9223372036854775808ULL;
 	*rv64imacfdvcpu->CSR[3104] = 0LL;
 	*rv64imacfdvcpu->CSR[3106] = 128ULL;
   	rv64imacfdvcpu->RES_ADDR = -1LL;

}

void RV64IMACFDVArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV64IMACFDV *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV64IMACFDVArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV64IMACFDVArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV64IMACFDV.h)
*/
const std::set<std::string> & RV64IMACFDVArch::getHeaders() const
{
	return headers_ ;
}

void RV64IMACFDVArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV64IMACFDV/RV64IMACFDV.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV64IMACFDV/RV64IMACFDVFuncs.h\"\n");
	cb.functionglobalCode().insert("cpu->exception = 0;\n");
	cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
	cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV64IMACFDVArch::getGDBCore()
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

etiss::instr::InstructionGroup ISA16_RV64IMACFDV("ISA16_RV64IMACFDV", 16);
etiss::instr::InstructionClass ISA16_RV64IMACFDVClass(1, "ISA16_RV64IMACFDV", 16, ISA16_RV64IMACFDV);
etiss::instr::InstructionGroup ISA32_RV64IMACFDV("ISA32_RV64IMACFDV", 32);
etiss::instr::InstructionClass ISA32_RV64IMACFDVClass(1, "ISA32_RV64IMACFDV", 32, ISA32_RV64IMACFDV);

etiss::instr::InstructionCollection RV64IMACFDVISA("RV64IMACFDVISA", ISA16_RV64IMACFDVClass, ISA32_RV64IMACFDVClass);