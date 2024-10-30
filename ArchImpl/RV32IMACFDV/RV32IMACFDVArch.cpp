/**
 * Generated on Wed, 30 Oct 2024 10:46:47 +0100.
 *
 * This file contains the architecture class for the RV32IMACFDV core architecture.
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
		 are provided in RV32IMACFDVArchSpecificImp.h

	 8. RV32IMACFDVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMACFDVArch.h"
#include "RV32IMACFDVFuncs.h"

#define RV32IMACFDV_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

RV32IMACFDVArch::RV32IMACFDVArch(unsigned int coreno):CPUArch("RV32IMACFDV"), coreno_(coreno)
{
	headers_.insert("Arch/RV32IMACFDV/RV32IMACFDV.h");
}

const std::set<std::string> & RV32IMACFDVArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV32IMACFDVArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV32IMACFDV() ;
	resetCPU (ret, 0);
	return ret;
}

void RV32IMACFDVArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV32IMACFDV));
	RV32IMACFDV * rv32imacfdvcpu = (RV32IMACFDV *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->nextPc = cpu->instructionPointer;
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv32imacfdvcpu->ins_X[i] = 0;
		rv32imacfdvcpu->X[i] = &rv32imacfdvcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv32imacfdvcpu->ins_CSR[i] = 0;
		rv32imacfdvcpu->CSR[i] = &rv32imacfdvcpu->ins_CSR[i];
	}
	for (int i = 0; i < 32; ++i) {
		rv32imacfdvcpu->ins_F[i] = 0;
		rv32imacfdvcpu->F[i] = &rv32imacfdvcpu->ins_F[i];
	}

	rv32imacfdvcpu->ZERO = 0;
	rv32imacfdvcpu->RA = 0;
	rv32imacfdvcpu->SP = 0;
	rv32imacfdvcpu->GP = 0;
	rv32imacfdvcpu->TP = 0;
	rv32imacfdvcpu->T0 = 0;
	rv32imacfdvcpu->T1 = 0;
	rv32imacfdvcpu->T2 = 0;
	rv32imacfdvcpu->S0 = 0;
	rv32imacfdvcpu->S1 = 0;
	rv32imacfdvcpu->A0 = 0;
	rv32imacfdvcpu->A1 = 0;
	rv32imacfdvcpu->A2 = 0;
	rv32imacfdvcpu->A3 = 0;
	rv32imacfdvcpu->A4 = 0;
	rv32imacfdvcpu->A5 = 0;
	rv32imacfdvcpu->A6 = 0;
	rv32imacfdvcpu->A7 = 0;
	rv32imacfdvcpu->S2 = 0;
	rv32imacfdvcpu->S3 = 0;
	rv32imacfdvcpu->S4 = 0;
	rv32imacfdvcpu->S5 = 0;
	rv32imacfdvcpu->S6 = 0;
	rv32imacfdvcpu->S7 = 0;
	rv32imacfdvcpu->S8 = 0;
	rv32imacfdvcpu->S9 = 0;
	rv32imacfdvcpu->S10 = 0;
	rv32imacfdvcpu->S11 = 0;
	rv32imacfdvcpu->T3 = 0;
	rv32imacfdvcpu->T4 = 0;
	rv32imacfdvcpu->T5 = 0;
	rv32imacfdvcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv32imacfdvcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv32imacfdvcpu->RES[i] = 0;
	}
	rv32imacfdvcpu->PRIV = 0;
	rv32imacfdvcpu->DPC = 0;
	rv32imacfdvcpu->VSTART_CSR = 0;
	rv32imacfdvcpu->VXSAT_CSR = 0;
	rv32imacfdvcpu->VXRM_CSR = 0;
	rv32imacfdvcpu->VCSR_CSR = 0;
	rv32imacfdvcpu->VL_CSR = 0;
	rv32imacfdvcpu->VTYPE_CSR = 0;
	rv32imacfdvcpu->VLENB_CSR = 0;
	rv32imacfdvcpu->FCSR = 0;
	rv32imacfdvcpu->FFLAGS = 0;
	rv32imacfdvcpu->FRM = 0;
	rv32imacfdvcpu->MSTATUS = 0;
	rv32imacfdvcpu->MIE = 0;
	rv32imacfdvcpu->MIP = 0;
	rv32imacfdvcpu->CYCLE = 0;
	rv32imacfdvcpu->CYCLEH = 0;
	rv32imacfdvcpu->TIME = 0;
	rv32imacfdvcpu->TIMEH = 0;
	rv32imacfdvcpu->INSTRET = 0;
	rv32imacfdvcpu->INSTRETH = 0;
	rv32imacfdvcpu->MVENDORID = 0;
	rv32imacfdvcpu->MARCHID = 0;
	rv32imacfdvcpu->MIMPID = 0;
	rv32imacfdvcpu->MHARTID = 0;
	rv32imacfdvcpu->MISA = 0;
	rv32imacfdvcpu->MEDELEG = 0;
	rv32imacfdvcpu->MIDELEG = 0;
	rv32imacfdvcpu->MTVEC = 0;
	rv32imacfdvcpu->MCOUNTEREN = 0;
	rv32imacfdvcpu->MSCRATCH = 0;
	rv32imacfdvcpu->MEPC = 0;
	rv32imacfdvcpu->MCAUSE = 0;
	rv32imacfdvcpu->MTVAL = 0;
	for (int i = 0; i < 4096; ++i) {
		rv32imacfdvcpu->V[i] = 0;
	}
	rv32imacfdvcpu->FT0 = 0;
	rv32imacfdvcpu->FT1 = 0;
	rv32imacfdvcpu->FT2 = 0;
	rv32imacfdvcpu->FT3 = 0;
	rv32imacfdvcpu->FT4 = 0;
	rv32imacfdvcpu->FT5 = 0;
	rv32imacfdvcpu->FT6 = 0;
	rv32imacfdvcpu->FT7 = 0;
	rv32imacfdvcpu->FS0 = 0;
	rv32imacfdvcpu->FS1 = 0;
	rv32imacfdvcpu->FA0 = 0;
	rv32imacfdvcpu->FA1 = 0;
	rv32imacfdvcpu->FA2 = 0;
	rv32imacfdvcpu->FA3 = 0;
	rv32imacfdvcpu->FA4 = 0;
	rv32imacfdvcpu->FA5 = 0;
	rv32imacfdvcpu->FA6 = 0;
	rv32imacfdvcpu->FA7 = 0;
	rv32imacfdvcpu->FS2 = 0;
	rv32imacfdvcpu->FS3 = 0;
	rv32imacfdvcpu->FS4 = 0;
	rv32imacfdvcpu->FS5 = 0;
	rv32imacfdvcpu->FS6 = 0;
	rv32imacfdvcpu->FS7 = 0;
	rv32imacfdvcpu->FS8 = 0;
	rv32imacfdvcpu->FS9 = 0;
	rv32imacfdvcpu->FS10 = 0;
	rv32imacfdvcpu->FS11 = 0;
	rv32imacfdvcpu->FT8 = 0;
	rv32imacfdvcpu->FT9 = 0;
	rv32imacfdvcpu->FT10 = 0;
	rv32imacfdvcpu->FT11 = 0;
	rv32imacfdvcpu->RES_ADDR = 0;

 	rv32imacfdvcpu->X[0] = &rv32imacfdvcpu->ZERO;
 	rv32imacfdvcpu->X[1] = &rv32imacfdvcpu->RA;
 	rv32imacfdvcpu->X[2] = &rv32imacfdvcpu->SP;
 	rv32imacfdvcpu->X[3] = &rv32imacfdvcpu->GP;
 	rv32imacfdvcpu->X[4] = &rv32imacfdvcpu->TP;
 	rv32imacfdvcpu->X[5] = &rv32imacfdvcpu->T0;
 	rv32imacfdvcpu->X[6] = &rv32imacfdvcpu->T1;
 	rv32imacfdvcpu->X[7] = &rv32imacfdvcpu->T2;
 	rv32imacfdvcpu->X[8] = &rv32imacfdvcpu->S0;
 	rv32imacfdvcpu->X[9] = &rv32imacfdvcpu->S1;
 	rv32imacfdvcpu->X[10] = &rv32imacfdvcpu->A0;
 	rv32imacfdvcpu->X[11] = &rv32imacfdvcpu->A1;
 	rv32imacfdvcpu->X[12] = &rv32imacfdvcpu->A2;
 	rv32imacfdvcpu->X[13] = &rv32imacfdvcpu->A3;
 	rv32imacfdvcpu->X[14] = &rv32imacfdvcpu->A4;
 	rv32imacfdvcpu->X[15] = &rv32imacfdvcpu->A5;
 	rv32imacfdvcpu->X[16] = &rv32imacfdvcpu->A6;
 	rv32imacfdvcpu->X[17] = &rv32imacfdvcpu->A7;
 	rv32imacfdvcpu->X[18] = &rv32imacfdvcpu->S2;
 	rv32imacfdvcpu->X[19] = &rv32imacfdvcpu->S3;
 	rv32imacfdvcpu->X[20] = &rv32imacfdvcpu->S4;
 	rv32imacfdvcpu->X[21] = &rv32imacfdvcpu->S5;
 	rv32imacfdvcpu->X[22] = &rv32imacfdvcpu->S6;
 	rv32imacfdvcpu->X[23] = &rv32imacfdvcpu->S7;
 	rv32imacfdvcpu->X[24] = &rv32imacfdvcpu->S8;
 	rv32imacfdvcpu->X[25] = &rv32imacfdvcpu->S9;
 	rv32imacfdvcpu->X[26] = &rv32imacfdvcpu->S10;
 	rv32imacfdvcpu->X[27] = &rv32imacfdvcpu->S11;
 	rv32imacfdvcpu->X[28] = &rv32imacfdvcpu->T3;
 	rv32imacfdvcpu->X[29] = &rv32imacfdvcpu->T4;
 	rv32imacfdvcpu->X[30] = &rv32imacfdvcpu->T5;
 	rv32imacfdvcpu->X[31] = &rv32imacfdvcpu->T6;
 	rv32imacfdvcpu->CSR[8] = &rv32imacfdvcpu->VSTART_CSR;
 	rv32imacfdvcpu->CSR[9] = &rv32imacfdvcpu->VXSAT_CSR;
 	rv32imacfdvcpu->CSR[10] = &rv32imacfdvcpu->VXRM_CSR;
 	rv32imacfdvcpu->CSR[15] = &rv32imacfdvcpu->VCSR_CSR;
 	rv32imacfdvcpu->CSR[3104] = &rv32imacfdvcpu->VL_CSR;
 	rv32imacfdvcpu->CSR[3105] = &rv32imacfdvcpu->VTYPE_CSR;
 	rv32imacfdvcpu->CSR[3106] = &rv32imacfdvcpu->VLENB_CSR;
 	rv32imacfdvcpu->CSR[3] = &rv32imacfdvcpu->FCSR;
 	rv32imacfdvcpu->CSR[1] = &rv32imacfdvcpu->FFLAGS;
 	rv32imacfdvcpu->CSR[2] = &rv32imacfdvcpu->FRM;
 	rv32imacfdvcpu->CSR[768] = &rv32imacfdvcpu->MSTATUS;
 	rv32imacfdvcpu->CSR[772] = &rv32imacfdvcpu->MIE;
 	rv32imacfdvcpu->CSR[836] = &rv32imacfdvcpu->MIP;
 	rv32imacfdvcpu->CSR[3072] = &rv32imacfdvcpu->CYCLE;
 	rv32imacfdvcpu->CSR[3200] = &rv32imacfdvcpu->CYCLEH;
 	rv32imacfdvcpu->CSR[3073] = &rv32imacfdvcpu->TIME;
 	rv32imacfdvcpu->CSR[3201] = &rv32imacfdvcpu->TIMEH;
 	rv32imacfdvcpu->CSR[3074] = &rv32imacfdvcpu->INSTRET;
 	rv32imacfdvcpu->CSR[3202] = &rv32imacfdvcpu->INSTRETH;
 	rv32imacfdvcpu->CSR[3857] = &rv32imacfdvcpu->MVENDORID;
 	rv32imacfdvcpu->CSR[3858] = &rv32imacfdvcpu->MARCHID;
 	rv32imacfdvcpu->CSR[3859] = &rv32imacfdvcpu->MIMPID;
 	rv32imacfdvcpu->CSR[3860] = &rv32imacfdvcpu->MHARTID;
 	rv32imacfdvcpu->CSR[769] = &rv32imacfdvcpu->MISA;
 	rv32imacfdvcpu->CSR[770] = &rv32imacfdvcpu->MEDELEG;
 	rv32imacfdvcpu->CSR[771] = &rv32imacfdvcpu->MIDELEG;
 	rv32imacfdvcpu->CSR[773] = &rv32imacfdvcpu->MTVEC;
 	rv32imacfdvcpu->CSR[774] = &rv32imacfdvcpu->MCOUNTEREN;
 	rv32imacfdvcpu->CSR[832] = &rv32imacfdvcpu->MSCRATCH;
 	rv32imacfdvcpu->CSR[833] = &rv32imacfdvcpu->MEPC;
 	rv32imacfdvcpu->CSR[834] = &rv32imacfdvcpu->MCAUSE;
 	rv32imacfdvcpu->CSR[835] = &rv32imacfdvcpu->MTVAL;
 	rv32imacfdvcpu->F[0] = &rv32imacfdvcpu->FT0;
 	rv32imacfdvcpu->F[1] = &rv32imacfdvcpu->FT1;
 	rv32imacfdvcpu->F[2] = &rv32imacfdvcpu->FT2;
 	rv32imacfdvcpu->F[3] = &rv32imacfdvcpu->FT3;
 	rv32imacfdvcpu->F[4] = &rv32imacfdvcpu->FT4;
 	rv32imacfdvcpu->F[5] = &rv32imacfdvcpu->FT5;
 	rv32imacfdvcpu->F[6] = &rv32imacfdvcpu->FT6;
 	rv32imacfdvcpu->F[7] = &rv32imacfdvcpu->FT7;
 	rv32imacfdvcpu->F[8] = &rv32imacfdvcpu->FS0;
 	rv32imacfdvcpu->F[9] = &rv32imacfdvcpu->FS1;
 	rv32imacfdvcpu->F[10] = &rv32imacfdvcpu->FA0;
 	rv32imacfdvcpu->F[11] = &rv32imacfdvcpu->FA1;
 	rv32imacfdvcpu->F[12] = &rv32imacfdvcpu->FA2;
 	rv32imacfdvcpu->F[13] = &rv32imacfdvcpu->FA3;
 	rv32imacfdvcpu->F[14] = &rv32imacfdvcpu->FA4;
 	rv32imacfdvcpu->F[15] = &rv32imacfdvcpu->FA5;
 	rv32imacfdvcpu->F[16] = &rv32imacfdvcpu->FA6;
 	rv32imacfdvcpu->F[17] = &rv32imacfdvcpu->FA7;
 	rv32imacfdvcpu->F[18] = &rv32imacfdvcpu->FS2;
 	rv32imacfdvcpu->F[19] = &rv32imacfdvcpu->FS3;
 	rv32imacfdvcpu->F[20] = &rv32imacfdvcpu->FS4;
 	rv32imacfdvcpu->F[21] = &rv32imacfdvcpu->FS5;
 	rv32imacfdvcpu->F[22] = &rv32imacfdvcpu->FS6;
 	rv32imacfdvcpu->F[23] = &rv32imacfdvcpu->FS7;
 	rv32imacfdvcpu->F[24] = &rv32imacfdvcpu->FS8;
 	rv32imacfdvcpu->F[25] = &rv32imacfdvcpu->FS9;
 	rv32imacfdvcpu->F[26] = &rv32imacfdvcpu->FS10;
 	rv32imacfdvcpu->F[27] = &rv32imacfdvcpu->FS11;
 	rv32imacfdvcpu->F[28] = &rv32imacfdvcpu->FT8;
 	rv32imacfdvcpu->F[29] = &rv32imacfdvcpu->FT9;
 	rv32imacfdvcpu->F[30] = &rv32imacfdvcpu->FT10;
 	rv32imacfdvcpu->F[31] = &rv32imacfdvcpu->FT11;

   	rv32imacfdvcpu->PRIV = 3ULL;
   	rv32imacfdvcpu->DPC = 0LL;
  	*rv32imacfdvcpu->CSR[0] = 11ULL;
 	*rv32imacfdvcpu->CSR[256] = 11ULL;
 	*rv32imacfdvcpu->CSR[768] = 1536ULL;
 	*rv32imacfdvcpu->CSR[769] = 1075056941ULL;
 	*rv32imacfdvcpu->CSR[3088] = 3ULL;
 	*rv32imacfdvcpu->CSR[772] = 4294966203ULL;
 	*rv32imacfdvcpu->CSR[260] = 4294964019ULL;
 	*rv32imacfdvcpu->CSR[4] = 4294963473ULL;
 	*rv32imacfdvcpu->CSR[3105] = 2147483648ULL;
 	*rv32imacfdvcpu->CSR[3104] = 0LL;
 	*rv32imacfdvcpu->CSR[3106] = 128ULL;
   	rv32imacfdvcpu->RES_ADDR = -1LL;

}

void RV32IMACFDVArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV32IMACFDV *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMACFDVArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV32IMACFDVArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV32IMACFDV.h)
*/
const std::set<std::string> & RV32IMACFDVArch::getHeaders() const
{
	return headers_ ;
}

void RV32IMACFDVArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDV/RV32IMACFDV.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDV/RV32IMACFDVFuncs.h\"\n");
	cb.functionglobalCode().insert("cpu->exception = 0;\n");
	cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
	cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV32IMACFDVArch::getGDBCore()
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

etiss::instr::InstructionGroup ISA16_RV32IMACFDV("ISA16_RV32IMACFDV", 16);
etiss::instr::InstructionClass ISA16_RV32IMACFDVClass(1, "ISA16_RV32IMACFDV", 16, ISA16_RV32IMACFDV);
etiss::instr::InstructionGroup ISA32_RV32IMACFDV("ISA32_RV32IMACFDV", 32);
etiss::instr::InstructionClass ISA32_RV32IMACFDVClass(1, "ISA32_RV32IMACFDV", 32, ISA32_RV32IMACFDV);

etiss::instr::InstructionCollection RV32IMACFDVISA("RV32IMACFDVISA", ISA16_RV32IMACFDVClass, ISA32_RV32IMACFDVClass);