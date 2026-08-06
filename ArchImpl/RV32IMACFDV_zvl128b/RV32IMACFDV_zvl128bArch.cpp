/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the architecture class for the RV32IMACFDV_zvl128b core architecture.
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
         calculated during process (if possible), otherwise it is assumed to be the register size. Problems may occur
         when var_1 encounters bit manipulation such as "~" due to bit expansion. To change the nml model with explicit
         slicing e.g var_1 = val_2<3..0> or avoid bit manipulation for dynamic sliced variable. Otherwise, you have to
         manually correct it.

     7. Implementation dependent functionalities such as exception handling should be manully added. Corresponding
         interfaces are provided in RV32IMACFDV_zvl128bArchSpecificImp.h

     8. RV32IMACFDV_zvl128bGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMACFDV_zvl128bArch.h"
#include "RV32IMACFDV_zvl128bFuncs.h"

#define RV32IMACFDV_zvl128b_DEBUG_CALL 0
using namespace etiss;
using namespace etiss::instr;

RV32IMACFDV_zvl128bArch::RV32IMACFDV_zvl128bArch(unsigned int coreno) : CPUArch("RV32IMACFDV_zvl128b"), coreno_(coreno)
{
    headers_.insert("Arch/RV32IMACFDV_zvl128b/RV32IMACFDV_zvl128b.h");
}

const std::set<std::string> &RV32IMACFDV_zvl128bArch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

ETISS_CPU *RV32IMACFDV_zvl128bArch::newCPU()
{
    ETISS_CPU *ret = (ETISS_CPU *)new RV32IMACFDV_zvl128b();
    resetCPU(ret, 0);
    return ret;
}

void RV32IMACFDV_zvl128bArch::resetCPU(ETISS_CPU *cpu, etiss::uint64 *startpointer)
{
    memset(cpu, 0, sizeof(RV32IMACFDV_zvl128b));
    RV32IMACFDV_zvl128b *rv32imacfdv_zvl128bcpu = (RV32IMACFDV_zvl128b *)cpu;

    if (startpointer)
        cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
    else
        cpu->instructionPointer = 0x0; //  reference to manual
    cpu->nextPc = cpu->instructionPointer;
    cpu->mode = 1;
    cpu->cpuTime_ps = 0;
    cpu->cpuCycleTime_ps = 31250;

    for (int i = 0; i < 4096; ++i)
    {
        rv32imacfdv_zvl128bcpu->ins_CSR[i] = 0;
        rv32imacfdv_zvl128bcpu->CSR[i] = &rv32imacfdv_zvl128bcpu->ins_CSR[i];
    }
    for (int i = 0; i < 32; ++i)
    {
        rv32imacfdv_zvl128bcpu->ins_X[i] = 0;
        rv32imacfdv_zvl128bcpu->X[i] = &rv32imacfdv_zvl128bcpu->ins_X[i];
    }
    for (int i = 0; i < 32; ++i)
    {
        rv32imacfdv_zvl128bcpu->ins_F[i] = 0;
        rv32imacfdv_zvl128bcpu->F[i] = &rv32imacfdv_zvl128bcpu->ins_F[i];
    }

    for (int i = 0; i < 8; ++i)
    {
        rv32imacfdv_zvl128bcpu->FENCE[i] = 0;
    }
    for (int i = 0; i < 8; ++i)
    {
        rv32imacfdv_zvl128bcpu->RES[i] = 0;
    }
        rv32imacfdv_zvl128bcpu->VSTART_CSR = 0;
        rv32imacfdv_zvl128bcpu->VXSAT_CSR = 0;
        rv32imacfdv_zvl128bcpu->VXRM_CSR = 0;
        rv32imacfdv_zvl128bcpu->VCSR_CSR = 0;
        rv32imacfdv_zvl128bcpu->VL_CSR = 0;
        rv32imacfdv_zvl128bcpu->VTYPE_CSR = 0;
        rv32imacfdv_zvl128bcpu->VLENB_CSR = 0;
        rv32imacfdv_zvl128bcpu->FCSR = 0;
        rv32imacfdv_zvl128bcpu->FFLAGS = 0;
        rv32imacfdv_zvl128bcpu->FRM = 0;
        rv32imacfdv_zvl128bcpu->MSTATUS = 0;
        rv32imacfdv_zvl128bcpu->MIE = 0;
        rv32imacfdv_zvl128bcpu->MIP = 0;
        rv32imacfdv_zvl128bcpu->CYCLE = 0;
        rv32imacfdv_zvl128bcpu->CYCLEH = 0;
        rv32imacfdv_zvl128bcpu->MCYCLE = 0;
        rv32imacfdv_zvl128bcpu->MCYCLEH = 0;
        rv32imacfdv_zvl128bcpu->TIME = 0;
        rv32imacfdv_zvl128bcpu->TIMEH = 0;
        rv32imacfdv_zvl128bcpu->INSTRET = 0;
        rv32imacfdv_zvl128bcpu->INSTRETH = 0;
        rv32imacfdv_zvl128bcpu->MINSTRET = 0;
        rv32imacfdv_zvl128bcpu->MINSTRETH = 0;
        rv32imacfdv_zvl128bcpu->MVENDORID = 0;
        rv32imacfdv_zvl128bcpu->MARCHID = 0;
        rv32imacfdv_zvl128bcpu->MIMPID = 0;
        rv32imacfdv_zvl128bcpu->MHARTID = 0;
        rv32imacfdv_zvl128bcpu->MISA = 0;
        rv32imacfdv_zvl128bcpu->MEDELEG = 0;
        rv32imacfdv_zvl128bcpu->MIDELEG = 0;
        rv32imacfdv_zvl128bcpu->MTVEC = 0;
        rv32imacfdv_zvl128bcpu->MCOUNTEREN = 0;
        rv32imacfdv_zvl128bcpu->MSCRATCH = 0;
        rv32imacfdv_zvl128bcpu->MEPC = 0;
        rv32imacfdv_zvl128bcpu->MCAUSE = 0;
        rv32imacfdv_zvl128bcpu->MTVAL = 0;
    for (int i = 0; i < 512; ++i)
    {
        rv32imacfdv_zvl128bcpu->V[i] = 0;
    }
        rv32imacfdv_zvl128bcpu->ZERO = 0;
        rv32imacfdv_zvl128bcpu->RA = 0;
        rv32imacfdv_zvl128bcpu->SP = 0;
        rv32imacfdv_zvl128bcpu->GP = 0;
        rv32imacfdv_zvl128bcpu->TP = 0;
        rv32imacfdv_zvl128bcpu->T0 = 0;
        rv32imacfdv_zvl128bcpu->T1 = 0;
        rv32imacfdv_zvl128bcpu->T2 = 0;
        rv32imacfdv_zvl128bcpu->S0 = 0;
        rv32imacfdv_zvl128bcpu->S1 = 0;
        rv32imacfdv_zvl128bcpu->A0 = 0;
        rv32imacfdv_zvl128bcpu->A1 = 0;
        rv32imacfdv_zvl128bcpu->A2 = 0;
        rv32imacfdv_zvl128bcpu->A3 = 0;
        rv32imacfdv_zvl128bcpu->A4 = 0;
        rv32imacfdv_zvl128bcpu->A5 = 0;
        rv32imacfdv_zvl128bcpu->A6 = 0;
        rv32imacfdv_zvl128bcpu->A7 = 0;
        rv32imacfdv_zvl128bcpu->S2 = 0;
        rv32imacfdv_zvl128bcpu->S3 = 0;
        rv32imacfdv_zvl128bcpu->S4 = 0;
        rv32imacfdv_zvl128bcpu->S5 = 0;
        rv32imacfdv_zvl128bcpu->S6 = 0;
        rv32imacfdv_zvl128bcpu->S7 = 0;
        rv32imacfdv_zvl128bcpu->S8 = 0;
        rv32imacfdv_zvl128bcpu->S9 = 0;
        rv32imacfdv_zvl128bcpu->S10 = 0;
        rv32imacfdv_zvl128bcpu->S11 = 0;
        rv32imacfdv_zvl128bcpu->T3 = 0;
        rv32imacfdv_zvl128bcpu->T4 = 0;
        rv32imacfdv_zvl128bcpu->T5 = 0;
        rv32imacfdv_zvl128bcpu->T6 = 0;
            rv32imacfdv_zvl128bcpu->PRIV = 0;
            rv32imacfdv_zvl128bcpu->DPC = 0;
        rv32imacfdv_zvl128bcpu->FT0 = 0;
        rv32imacfdv_zvl128bcpu->FT1 = 0;
        rv32imacfdv_zvl128bcpu->FT2 = 0;
        rv32imacfdv_zvl128bcpu->FT3 = 0;
        rv32imacfdv_zvl128bcpu->FT4 = 0;
        rv32imacfdv_zvl128bcpu->FT5 = 0;
        rv32imacfdv_zvl128bcpu->FT6 = 0;
        rv32imacfdv_zvl128bcpu->FT7 = 0;
        rv32imacfdv_zvl128bcpu->FS0 = 0;
        rv32imacfdv_zvl128bcpu->FS1 = 0;
        rv32imacfdv_zvl128bcpu->FA0 = 0;
        rv32imacfdv_zvl128bcpu->FA1 = 0;
        rv32imacfdv_zvl128bcpu->FA2 = 0;
        rv32imacfdv_zvl128bcpu->FA3 = 0;
        rv32imacfdv_zvl128bcpu->FA4 = 0;
        rv32imacfdv_zvl128bcpu->FA5 = 0;
        rv32imacfdv_zvl128bcpu->FA6 = 0;
        rv32imacfdv_zvl128bcpu->FA7 = 0;
        rv32imacfdv_zvl128bcpu->FS2 = 0;
        rv32imacfdv_zvl128bcpu->FS3 = 0;
        rv32imacfdv_zvl128bcpu->FS4 = 0;
        rv32imacfdv_zvl128bcpu->FS5 = 0;
        rv32imacfdv_zvl128bcpu->FS6 = 0;
        rv32imacfdv_zvl128bcpu->FS7 = 0;
        rv32imacfdv_zvl128bcpu->FS8 = 0;
        rv32imacfdv_zvl128bcpu->FS9 = 0;
        rv32imacfdv_zvl128bcpu->FS10 = 0;
        rv32imacfdv_zvl128bcpu->FS11 = 0;
        rv32imacfdv_zvl128bcpu->FT8 = 0;
        rv32imacfdv_zvl128bcpu->FT9 = 0;
        rv32imacfdv_zvl128bcpu->FT10 = 0;
        rv32imacfdv_zvl128bcpu->FT11 = 0;
            rv32imacfdv_zvl128bcpu->RES_ADDR = 0;
        rv32imacfdv_zvl128bcpu->VSTART_CSR = 0;
        rv32imacfdv_zvl128bcpu->VXSAT_CSR = 0;
        rv32imacfdv_zvl128bcpu->VXRM_CSR = 0;
        rv32imacfdv_zvl128bcpu->VCSR_CSR = 0;
        rv32imacfdv_zvl128bcpu->VL_CSR = 0;
        rv32imacfdv_zvl128bcpu->VTYPE_CSR = 0;
        rv32imacfdv_zvl128bcpu->VLENB_CSR = 0;
        rv32imacfdv_zvl128bcpu->FCSR = 0;
        rv32imacfdv_zvl128bcpu->FFLAGS = 0;
        rv32imacfdv_zvl128bcpu->FRM = 0;
        rv32imacfdv_zvl128bcpu->MSTATUS = 0;
        rv32imacfdv_zvl128bcpu->MIE = 0;
        rv32imacfdv_zvl128bcpu->MIP = 0;
        rv32imacfdv_zvl128bcpu->CYCLE = 0;
        rv32imacfdv_zvl128bcpu->CYCLEH = 0;
        rv32imacfdv_zvl128bcpu->MCYCLE = 0;
        rv32imacfdv_zvl128bcpu->MCYCLEH = 0;
        rv32imacfdv_zvl128bcpu->TIME = 0;
        rv32imacfdv_zvl128bcpu->TIMEH = 0;
        rv32imacfdv_zvl128bcpu->INSTRET = 0;
        rv32imacfdv_zvl128bcpu->INSTRETH = 0;
        rv32imacfdv_zvl128bcpu->MINSTRET = 0;
        rv32imacfdv_zvl128bcpu->MINSTRETH = 0;
        rv32imacfdv_zvl128bcpu->MVENDORID = 0;
        rv32imacfdv_zvl128bcpu->MARCHID = 0;
        rv32imacfdv_zvl128bcpu->MIMPID = 0;
        rv32imacfdv_zvl128bcpu->MHARTID = 0;
        rv32imacfdv_zvl128bcpu->MISA = 0;
        rv32imacfdv_zvl128bcpu->MEDELEG = 0;
        rv32imacfdv_zvl128bcpu->MIDELEG = 0;
        rv32imacfdv_zvl128bcpu->MTVEC = 0;
        rv32imacfdv_zvl128bcpu->MCOUNTEREN = 0;
        rv32imacfdv_zvl128bcpu->MSCRATCH = 0;
        rv32imacfdv_zvl128bcpu->MEPC = 0;
        rv32imacfdv_zvl128bcpu->MCAUSE = 0;
        rv32imacfdv_zvl128bcpu->MTVAL = 0;
        rv32imacfdv_zvl128bcpu->ZERO = 0;
        rv32imacfdv_zvl128bcpu->RA = 0;
        rv32imacfdv_zvl128bcpu->SP = 0;
        rv32imacfdv_zvl128bcpu->GP = 0;
        rv32imacfdv_zvl128bcpu->TP = 0;
        rv32imacfdv_zvl128bcpu->T0 = 0;
        rv32imacfdv_zvl128bcpu->T1 = 0;
        rv32imacfdv_zvl128bcpu->T2 = 0;
        rv32imacfdv_zvl128bcpu->S0 = 0;
        rv32imacfdv_zvl128bcpu->S1 = 0;
        rv32imacfdv_zvl128bcpu->A0 = 0;
        rv32imacfdv_zvl128bcpu->A1 = 0;
        rv32imacfdv_zvl128bcpu->A2 = 0;
        rv32imacfdv_zvl128bcpu->A3 = 0;
        rv32imacfdv_zvl128bcpu->A4 = 0;
        rv32imacfdv_zvl128bcpu->A5 = 0;
        rv32imacfdv_zvl128bcpu->A6 = 0;
        rv32imacfdv_zvl128bcpu->A7 = 0;
        rv32imacfdv_zvl128bcpu->S2 = 0;
        rv32imacfdv_zvl128bcpu->S3 = 0;
        rv32imacfdv_zvl128bcpu->S4 = 0;
        rv32imacfdv_zvl128bcpu->S5 = 0;
        rv32imacfdv_zvl128bcpu->S6 = 0;
        rv32imacfdv_zvl128bcpu->S7 = 0;
        rv32imacfdv_zvl128bcpu->S8 = 0;
        rv32imacfdv_zvl128bcpu->S9 = 0;
        rv32imacfdv_zvl128bcpu->S10 = 0;
        rv32imacfdv_zvl128bcpu->S11 = 0;
        rv32imacfdv_zvl128bcpu->T3 = 0;
        rv32imacfdv_zvl128bcpu->T4 = 0;
        rv32imacfdv_zvl128bcpu->T5 = 0;
        rv32imacfdv_zvl128bcpu->T6 = 0;
        rv32imacfdv_zvl128bcpu->FT0 = 0;
        rv32imacfdv_zvl128bcpu->FT1 = 0;
        rv32imacfdv_zvl128bcpu->FT2 = 0;
        rv32imacfdv_zvl128bcpu->FT3 = 0;
        rv32imacfdv_zvl128bcpu->FT4 = 0;
        rv32imacfdv_zvl128bcpu->FT5 = 0;
        rv32imacfdv_zvl128bcpu->FT6 = 0;
        rv32imacfdv_zvl128bcpu->FT7 = 0;
        rv32imacfdv_zvl128bcpu->FS0 = 0;
        rv32imacfdv_zvl128bcpu->FS1 = 0;
        rv32imacfdv_zvl128bcpu->FA0 = 0;
        rv32imacfdv_zvl128bcpu->FA1 = 0;
        rv32imacfdv_zvl128bcpu->FA2 = 0;
        rv32imacfdv_zvl128bcpu->FA3 = 0;
        rv32imacfdv_zvl128bcpu->FA4 = 0;
        rv32imacfdv_zvl128bcpu->FA5 = 0;
        rv32imacfdv_zvl128bcpu->FA6 = 0;
        rv32imacfdv_zvl128bcpu->FA7 = 0;
        rv32imacfdv_zvl128bcpu->FS2 = 0;
        rv32imacfdv_zvl128bcpu->FS3 = 0;
        rv32imacfdv_zvl128bcpu->FS4 = 0;
        rv32imacfdv_zvl128bcpu->FS5 = 0;
        rv32imacfdv_zvl128bcpu->FS6 = 0;
        rv32imacfdv_zvl128bcpu->FS7 = 0;
        rv32imacfdv_zvl128bcpu->FS8 = 0;
        rv32imacfdv_zvl128bcpu->FS9 = 0;
        rv32imacfdv_zvl128bcpu->FS10 = 0;
        rv32imacfdv_zvl128bcpu->FS11 = 0;
        rv32imacfdv_zvl128bcpu->FT8 = 0;
        rv32imacfdv_zvl128bcpu->FT9 = 0;
        rv32imacfdv_zvl128bcpu->FT10 = 0;
        rv32imacfdv_zvl128bcpu->FT11 = 0;

    rv32imacfdv_zvl128bcpu->CSR[8] = &rv32imacfdv_zvl128bcpu->VSTART_CSR;
    rv32imacfdv_zvl128bcpu->CSR[9] = &rv32imacfdv_zvl128bcpu->VXSAT_CSR;
    rv32imacfdv_zvl128bcpu->CSR[10] = &rv32imacfdv_zvl128bcpu->VXRM_CSR;
    rv32imacfdv_zvl128bcpu->CSR[15] = &rv32imacfdv_zvl128bcpu->VCSR_CSR;
    rv32imacfdv_zvl128bcpu->CSR[3104] = &rv32imacfdv_zvl128bcpu->VL_CSR;
    rv32imacfdv_zvl128bcpu->CSR[3105] = &rv32imacfdv_zvl128bcpu->VTYPE_CSR;
    rv32imacfdv_zvl128bcpu->CSR[3106] = &rv32imacfdv_zvl128bcpu->VLENB_CSR;
    rv32imacfdv_zvl128bcpu->CSR[3] = &rv32imacfdv_zvl128bcpu->FCSR;
    rv32imacfdv_zvl128bcpu->CSR[1] = &rv32imacfdv_zvl128bcpu->FFLAGS;
    rv32imacfdv_zvl128bcpu->CSR[2] = &rv32imacfdv_zvl128bcpu->FRM;
    rv32imacfdv_zvl128bcpu->CSR[768] = &rv32imacfdv_zvl128bcpu->MSTATUS;
    rv32imacfdv_zvl128bcpu->CSR[772] = &rv32imacfdv_zvl128bcpu->MIE;
    rv32imacfdv_zvl128bcpu->CSR[836] = &rv32imacfdv_zvl128bcpu->MIP;
    rv32imacfdv_zvl128bcpu->CSR[3072] = &rv32imacfdv_zvl128bcpu->CYCLE;
    rv32imacfdv_zvl128bcpu->CSR[3200] = &rv32imacfdv_zvl128bcpu->CYCLEH;
    rv32imacfdv_zvl128bcpu->CSR[2816] = &rv32imacfdv_zvl128bcpu->MCYCLE;
    rv32imacfdv_zvl128bcpu->CSR[2944] = &rv32imacfdv_zvl128bcpu->MCYCLEH;
    rv32imacfdv_zvl128bcpu->CSR[3073] = &rv32imacfdv_zvl128bcpu->TIME;
    rv32imacfdv_zvl128bcpu->CSR[3201] = &rv32imacfdv_zvl128bcpu->TIMEH;
    rv32imacfdv_zvl128bcpu->CSR[3074] = &rv32imacfdv_zvl128bcpu->INSTRET;
    rv32imacfdv_zvl128bcpu->CSR[3202] = &rv32imacfdv_zvl128bcpu->INSTRETH;
    rv32imacfdv_zvl128bcpu->CSR[2818] = &rv32imacfdv_zvl128bcpu->MINSTRET;
    rv32imacfdv_zvl128bcpu->CSR[2946] = &rv32imacfdv_zvl128bcpu->MINSTRETH;
    rv32imacfdv_zvl128bcpu->CSR[3857] = &rv32imacfdv_zvl128bcpu->MVENDORID;
    rv32imacfdv_zvl128bcpu->CSR[3858] = &rv32imacfdv_zvl128bcpu->MARCHID;
    rv32imacfdv_zvl128bcpu->CSR[3859] = &rv32imacfdv_zvl128bcpu->MIMPID;
    rv32imacfdv_zvl128bcpu->CSR[3860] = &rv32imacfdv_zvl128bcpu->MHARTID;
    rv32imacfdv_zvl128bcpu->CSR[769] = &rv32imacfdv_zvl128bcpu->MISA;
    rv32imacfdv_zvl128bcpu->CSR[770] = &rv32imacfdv_zvl128bcpu->MEDELEG;
    rv32imacfdv_zvl128bcpu->CSR[771] = &rv32imacfdv_zvl128bcpu->MIDELEG;
    rv32imacfdv_zvl128bcpu->CSR[773] = &rv32imacfdv_zvl128bcpu->MTVEC;
    rv32imacfdv_zvl128bcpu->CSR[774] = &rv32imacfdv_zvl128bcpu->MCOUNTEREN;
    rv32imacfdv_zvl128bcpu->CSR[832] = &rv32imacfdv_zvl128bcpu->MSCRATCH;
    rv32imacfdv_zvl128bcpu->CSR[833] = &rv32imacfdv_zvl128bcpu->MEPC;
    rv32imacfdv_zvl128bcpu->CSR[834] = &rv32imacfdv_zvl128bcpu->MCAUSE;
    rv32imacfdv_zvl128bcpu->CSR[835] = &rv32imacfdv_zvl128bcpu->MTVAL;
    rv32imacfdv_zvl128bcpu->X[0] = &rv32imacfdv_zvl128bcpu->ZERO;
    rv32imacfdv_zvl128bcpu->X[1] = &rv32imacfdv_zvl128bcpu->RA;
    rv32imacfdv_zvl128bcpu->X[2] = &rv32imacfdv_zvl128bcpu->SP;
    rv32imacfdv_zvl128bcpu->X[3] = &rv32imacfdv_zvl128bcpu->GP;
    rv32imacfdv_zvl128bcpu->X[4] = &rv32imacfdv_zvl128bcpu->TP;
    rv32imacfdv_zvl128bcpu->X[5] = &rv32imacfdv_zvl128bcpu->T0;
    rv32imacfdv_zvl128bcpu->X[6] = &rv32imacfdv_zvl128bcpu->T1;
    rv32imacfdv_zvl128bcpu->X[7] = &rv32imacfdv_zvl128bcpu->T2;
    rv32imacfdv_zvl128bcpu->X[8] = &rv32imacfdv_zvl128bcpu->S0;
    rv32imacfdv_zvl128bcpu->X[9] = &rv32imacfdv_zvl128bcpu->S1;
    rv32imacfdv_zvl128bcpu->X[10] = &rv32imacfdv_zvl128bcpu->A0;
    rv32imacfdv_zvl128bcpu->X[11] = &rv32imacfdv_zvl128bcpu->A1;
    rv32imacfdv_zvl128bcpu->X[12] = &rv32imacfdv_zvl128bcpu->A2;
    rv32imacfdv_zvl128bcpu->X[13] = &rv32imacfdv_zvl128bcpu->A3;
    rv32imacfdv_zvl128bcpu->X[14] = &rv32imacfdv_zvl128bcpu->A4;
    rv32imacfdv_zvl128bcpu->X[15] = &rv32imacfdv_zvl128bcpu->A5;
    rv32imacfdv_zvl128bcpu->X[16] = &rv32imacfdv_zvl128bcpu->A6;
    rv32imacfdv_zvl128bcpu->X[17] = &rv32imacfdv_zvl128bcpu->A7;
    rv32imacfdv_zvl128bcpu->X[18] = &rv32imacfdv_zvl128bcpu->S2;
    rv32imacfdv_zvl128bcpu->X[19] = &rv32imacfdv_zvl128bcpu->S3;
    rv32imacfdv_zvl128bcpu->X[20] = &rv32imacfdv_zvl128bcpu->S4;
    rv32imacfdv_zvl128bcpu->X[21] = &rv32imacfdv_zvl128bcpu->S5;
    rv32imacfdv_zvl128bcpu->X[22] = &rv32imacfdv_zvl128bcpu->S6;
    rv32imacfdv_zvl128bcpu->X[23] = &rv32imacfdv_zvl128bcpu->S7;
    rv32imacfdv_zvl128bcpu->X[24] = &rv32imacfdv_zvl128bcpu->S8;
    rv32imacfdv_zvl128bcpu->X[25] = &rv32imacfdv_zvl128bcpu->S9;
    rv32imacfdv_zvl128bcpu->X[26] = &rv32imacfdv_zvl128bcpu->S10;
    rv32imacfdv_zvl128bcpu->X[27] = &rv32imacfdv_zvl128bcpu->S11;
    rv32imacfdv_zvl128bcpu->X[28] = &rv32imacfdv_zvl128bcpu->T3;
    rv32imacfdv_zvl128bcpu->X[29] = &rv32imacfdv_zvl128bcpu->T4;
    rv32imacfdv_zvl128bcpu->X[30] = &rv32imacfdv_zvl128bcpu->T5;
    rv32imacfdv_zvl128bcpu->X[31] = &rv32imacfdv_zvl128bcpu->T6;
    rv32imacfdv_zvl128bcpu->F[0] = &rv32imacfdv_zvl128bcpu->FT0;
    rv32imacfdv_zvl128bcpu->F[1] = &rv32imacfdv_zvl128bcpu->FT1;
    rv32imacfdv_zvl128bcpu->F[2] = &rv32imacfdv_zvl128bcpu->FT2;
    rv32imacfdv_zvl128bcpu->F[3] = &rv32imacfdv_zvl128bcpu->FT3;
    rv32imacfdv_zvl128bcpu->F[4] = &rv32imacfdv_zvl128bcpu->FT4;
    rv32imacfdv_zvl128bcpu->F[5] = &rv32imacfdv_zvl128bcpu->FT5;
    rv32imacfdv_zvl128bcpu->F[6] = &rv32imacfdv_zvl128bcpu->FT6;
    rv32imacfdv_zvl128bcpu->F[7] = &rv32imacfdv_zvl128bcpu->FT7;
    rv32imacfdv_zvl128bcpu->F[8] = &rv32imacfdv_zvl128bcpu->FS0;
    rv32imacfdv_zvl128bcpu->F[9] = &rv32imacfdv_zvl128bcpu->FS1;
    rv32imacfdv_zvl128bcpu->F[10] = &rv32imacfdv_zvl128bcpu->FA0;
    rv32imacfdv_zvl128bcpu->F[11] = &rv32imacfdv_zvl128bcpu->FA1;
    rv32imacfdv_zvl128bcpu->F[12] = &rv32imacfdv_zvl128bcpu->FA2;
    rv32imacfdv_zvl128bcpu->F[13] = &rv32imacfdv_zvl128bcpu->FA3;
    rv32imacfdv_zvl128bcpu->F[14] = &rv32imacfdv_zvl128bcpu->FA4;
    rv32imacfdv_zvl128bcpu->F[15] = &rv32imacfdv_zvl128bcpu->FA5;
    rv32imacfdv_zvl128bcpu->F[16] = &rv32imacfdv_zvl128bcpu->FA6;
    rv32imacfdv_zvl128bcpu->F[17] = &rv32imacfdv_zvl128bcpu->FA7;
    rv32imacfdv_zvl128bcpu->F[18] = &rv32imacfdv_zvl128bcpu->FS2;
    rv32imacfdv_zvl128bcpu->F[19] = &rv32imacfdv_zvl128bcpu->FS3;
    rv32imacfdv_zvl128bcpu->F[20] = &rv32imacfdv_zvl128bcpu->FS4;
    rv32imacfdv_zvl128bcpu->F[21] = &rv32imacfdv_zvl128bcpu->FS5;
    rv32imacfdv_zvl128bcpu->F[22] = &rv32imacfdv_zvl128bcpu->FS6;
    rv32imacfdv_zvl128bcpu->F[23] = &rv32imacfdv_zvl128bcpu->FS7;
    rv32imacfdv_zvl128bcpu->F[24] = &rv32imacfdv_zvl128bcpu->FS8;
    rv32imacfdv_zvl128bcpu->F[25] = &rv32imacfdv_zvl128bcpu->FS9;
    rv32imacfdv_zvl128bcpu->F[26] = &rv32imacfdv_zvl128bcpu->FS10;
    rv32imacfdv_zvl128bcpu->F[27] = &rv32imacfdv_zvl128bcpu->FS11;
    rv32imacfdv_zvl128bcpu->F[28] = &rv32imacfdv_zvl128bcpu->FT8;
    rv32imacfdv_zvl128bcpu->F[29] = &rv32imacfdv_zvl128bcpu->FT9;
    rv32imacfdv_zvl128bcpu->F[30] = &rv32imacfdv_zvl128bcpu->FT10;
    rv32imacfdv_zvl128bcpu->F[31] = &rv32imacfdv_zvl128bcpu->FT11;

    *rv32imacfdv_zvl128bcpu->CSR[0] = 11ULL;
    *rv32imacfdv_zvl128bcpu->CSR[256] = 11ULL;
    *rv32imacfdv_zvl128bcpu->CSR[768] = 1536ULL;
    *rv32imacfdv_zvl128bcpu->CSR[769] = 1075056941ULL;
    *rv32imacfdv_zvl128bcpu->CSR[3088] = 3ULL;
    *rv32imacfdv_zvl128bcpu->CSR[772] = 4294966203ULL;
    *rv32imacfdv_zvl128bcpu->CSR[260] = 4294964019ULL;
    *rv32imacfdv_zvl128bcpu->CSR[4] = 4294963473ULL;
    *rv32imacfdv_zvl128bcpu->CSR[3105] = 2147483648ULL;
    *rv32imacfdv_zvl128bcpu->CSR[3104] = 0LL;
    *rv32imacfdv_zvl128bcpu->CSR[3106] = 16ULL;
    rv32imacfdv_zvl128bcpu->PRIV = 3ULL;
    rv32imacfdv_zvl128bcpu->DPC = 0LL;
    rv32imacfdv_zvl128bcpu->RES_ADDR = -1LL;
}

void RV32IMACFDV_zvl128bArch::deleteCPU(ETISS_CPU *cpu)
{
    delete (RV32IMACFDV_zvl128b *)cpu;
}

/**
    @return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMACFDV_zvl128bArch::getMaximumInstructionSizeInBytes()
{
    return 8;
}

/**
    @return 2
*/
unsigned RV32IMACFDV_zvl128bArch::getInstructionSizeInBytes()
{
    return 2;
}

/**
    @brief required headers (RV32IMACFDV_zvl128b.h)
*/
const std::set<std::string> &RV32IMACFDV_zvl128bArch::getHeaders() const
{
    return headers_;
}

void RV32IMACFDV_zvl128bArch::initCodeBlock(etiss::CodeBlock &cb) const
{
    cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDV_zvl128b/RV32IMACFDV_zvl128b.h\"\n");
    cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDV_zvl128b/RV32IMACFDV_zvl128bFuncs.h\"\n");
    cb.functionglobalCode().insert("cpu->exception = 0;\n");
    cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
    cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore &RV32IMACFDV_zvl128bArch::getGDBCore()
{
    return gdbcore_;
}

// clang-format off
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
    "F0",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "F13",
    "F14",
    "F15",
    "F16",
    "F17",
    "F18",
    "F19",
    "F20",
    "F21",
    "F22",
    "F23",
    "F24",
    "F25",
    "F26",
    "F27",
    "F28",
    "F29",
    "F30",
    "F31",
};
// clang-format on

etiss::instr::InstructionGroup ISA16_RV32IMACFDV_zvl128b("ISA16_RV32IMACFDV_zvl128b", 16);
etiss::instr::InstructionClass ISA16_RV32IMACFDV_zvl128bClass(1, "ISA16_RV32IMACFDV_zvl128b", 16, ISA16_RV32IMACFDV_zvl128b);
etiss::instr::InstructionGroup ISA32_RV32IMACFDV_zvl128b("ISA32_RV32IMACFDV_zvl128b", 32);
etiss::instr::InstructionClass ISA32_RV32IMACFDV_zvl128bClass(1, "ISA32_RV32IMACFDV_zvl128b", 32, ISA32_RV32IMACFDV_zvl128b);

etiss::instr::InstructionCollection RV32IMACFDV_zvl128bISA("RV32IMACFDV_zvl128bISA", ISA16_RV32IMACFDV_zvl128bClass, ISA32_RV32IMACFDV_zvl128bClass);
