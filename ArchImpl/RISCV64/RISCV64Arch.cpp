// This file was generated on Mon Aug 03 15:02:40 CEST 2020
// If necessary please modify this file according to the instructions
// Contact: eda@tum

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
	 	are provided in RISCV64ArchSpecificImp.h 
 
	 8. RISCV64GDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.
 
 *********************************************************************************************************************************/

#include "RISCV64Arch.h"
#include "RISCV64ArchSpecificImp.h"

#define RISCV64_DEBUG_CALL 0
#define RISCV64_Pipeline1 0
#define RISCV64_Pipeline2 0
using namespace etiss ;
using namespace etiss::instr ;

// Debug
int32_t tlb_overlap_handler(int32_t fault, MMU *mmu, uint64_t vma, MM_ACCESS access)
{
    return etiss::RETURNCODE::NOERROR;
}

RISCV64Arch::RISCV64Arch():CPUArch("RISCV64") 
{
	headers_.insert("Arch/RISCV64/RISCV64.h");
}

const std::set<std::string> & RISCV64Arch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

ETISS_CPU * RISCV64Arch::newCPU()
{
    ETISS_CPU * ret = (ETISS_CPU *) new RISCV64() ;
    resetCPU (ret, 0);
    return ret;
}

void RISCV64Arch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
    memset (cpu, 0, sizeof(RISCV64));
    RISCV64 * riscv64cpu = (RISCV64 *) cpu;

    if (startpointer) cpu->instructionPointer = *startpointer;
    else cpu->instructionPointer = 0x0;   //  reference to manual
    cpu->mode = 1;
    cpu->cpuTime_ps = 0;
    cpu->cpuCycleTime_ps = 31250;
    #if RISCV64_Pipeline1 || RISCV64_Pipeline2
    //Initialize resources measurements
    cpu->resources[0] = "I_RAM";
    cpu->resources[1] = "IF";
    cpu->resources[2] = "ID";
    cpu->resources[3] = "Multiplier1";
    cpu->resources[4] = "ReadPorts";
    cpu->resources[5] = "ALU";
    cpu->resources[6] = "D_RAM";
    cpu->resources[7] = "WB";
    cpu->resources[8] = "Multiplier2";
    for(int i = 0; i < 9; i = i + 1){
    	cpu->resourceUsages[i] = 0;
    	cpu->cycles[i] = 0;
    }
    #endif
    
    // Instantiate the pointers in order to avoid segmentation fault
	for(int i = 0; i < 32; i ++)
	{
		riscv64cpu->ins_X[i] = 0;
		riscv64cpu->X[i] = & riscv64cpu->ins_X[i];
	}
	
    // Initialize the registers and state flags;
	riscv64cpu->ZERO = 0;
	riscv64cpu->X[0] = & (riscv64cpu->ZERO);
	riscv64cpu->RA = 0;
	riscv64cpu->X[1] = & (riscv64cpu->RA);
	riscv64cpu->SP = 0;
	riscv64cpu->X[2] = & (riscv64cpu->SP);
	riscv64cpu->GP = 0;
	riscv64cpu->X[3] = & (riscv64cpu->GP);
	riscv64cpu->TP = 0;
	riscv64cpu->X[4] = & (riscv64cpu->TP);
	riscv64cpu->T0 = 0;
	riscv64cpu->X[5] = & (riscv64cpu->T0);
	riscv64cpu->T1 = 0;
	riscv64cpu->X[6] = & (riscv64cpu->T1);
	riscv64cpu->T2 = 0;
	riscv64cpu->X[7] = & (riscv64cpu->T2);
	riscv64cpu->S0 = 0;
	riscv64cpu->X[8] = & (riscv64cpu->S0);
	riscv64cpu->S1 = 0;
	riscv64cpu->X[9] = & (riscv64cpu->S1);
	riscv64cpu->A0 = 0;
	riscv64cpu->X[10] = & (riscv64cpu->A0);
	riscv64cpu->A1 = 0;
	riscv64cpu->X[11] = & (riscv64cpu->A1);
	riscv64cpu->A2 = 0;
	riscv64cpu->X[12] = & (riscv64cpu->A2);
	riscv64cpu->A3 = 0;
	riscv64cpu->X[13] = & (riscv64cpu->A3);
	riscv64cpu->A4 = 0;
	riscv64cpu->X[14] = & (riscv64cpu->A4);
	riscv64cpu->A5 = 0;
	riscv64cpu->X[15] = & (riscv64cpu->A5);
	riscv64cpu->A6 = 0;
	riscv64cpu->X[16] = & (riscv64cpu->A6);
	riscv64cpu->A7 = 0;
	riscv64cpu->X[17] = & (riscv64cpu->A7);
	riscv64cpu->S2 = 0;
	riscv64cpu->X[18] = & (riscv64cpu->S2);
	riscv64cpu->S3 = 0;
	riscv64cpu->X[19] = & (riscv64cpu->S3);
	riscv64cpu->S4 = 0;
	riscv64cpu->X[20] = & (riscv64cpu->S4);
	riscv64cpu->S5 = 0;
	riscv64cpu->X[21] = & (riscv64cpu->S5);
	riscv64cpu->S6 = 0;
	riscv64cpu->X[22] = & (riscv64cpu->S6);
	riscv64cpu->S7 = 0;
	riscv64cpu->X[23] = & (riscv64cpu->S7);
	riscv64cpu->S8 = 0;
	riscv64cpu->X[24] = & (riscv64cpu->S8);
	riscv64cpu->S9 = 0;
	riscv64cpu->X[25] = & (riscv64cpu->S9);
	riscv64cpu->S10 = 0;
	riscv64cpu->X[26] = & (riscv64cpu->S10);
	riscv64cpu->S11 = 0;
	riscv64cpu->X[27] = & (riscv64cpu->S11);
	riscv64cpu->T3 = 0;
	riscv64cpu->X[28] = & (riscv64cpu->T3);
	riscv64cpu->T4 = 0;
	riscv64cpu->X[29] = & (riscv64cpu->T4);
	riscv64cpu->T5 = 0;
	riscv64cpu->X[30] = & (riscv64cpu->T5);
	riscv64cpu->T6 = 0;
	riscv64cpu->X[31] = & (riscv64cpu->T6);
	for (int i = 0; i<32 ;i++){
		riscv64cpu->F[i] = 0;
	}
	riscv64cpu->FCSR = 0;
	for (int i = 0; i<4096 ;i++){
		riscv64cpu->CSR[i] = 0;
	}
	riscv64cpu->CSR[0] = 15;								
	riscv64cpu->CSR[256] = 15;								
	riscv64cpu->CSR[768] = 15;								
	riscv64cpu->CSR[260] = 4294967295;								
	riscv64cpu->CSR[769] = 0x800000000014112D;
	riscv64cpu->CSR[3088] = 3;								
	for (int i = 0; i<4 ;i++){
		riscv64cpu->FENCE[i] = 0;
	}
	riscv64cpu->RES = 0;

	/* >>> manually added code section */
	riscv64cpu->CSR[0x304] = (0xFFFFFFFFFFFFFBBB);
		// MIE: enable all core-local and add. platform-specific interrupts
	riscv64cpu->CSR[0x104] = riscv64cpu->CSR[0x304] & (~(0x888));
		// SIE: enable all core-local and add. platform-specific interrupts (supervised)
	riscv64cpu->CSR[0x004] = riscv64cpu->CSR[0x304] & (~(0xAAA));
		// UIE: enable all core-local and add. platform-specific interrupts (user)
	/* <<< manually added code section */
}

void RISCV64Arch::deleteCPU(ETISS_CPU *cpu)
{
    delete (RISCV64 *) cpu ;
}


/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RISCV64Arch::getMaximumInstructionSizeInBytes()
{
    return 8;
}
/**
	@return 2
*/
unsigned RISCV64Arch::getInstructionSizeInBytes()
{
    return 2;
}
/**
	@brief required headers (RISCV64.h)
*/
const std::set<std::string> & RISCV64Arch::getHeaders() const
{
    return headers_ ;
}
		
void RISCV64Arch::initCodeBlock(etiss::CodeBlock & cb) const
{
    cb.fileglobalCode().insert("#include \"Arch/RISCV64/RISCV64.h\"\n");
}

etiss::plugin::gdb::GDBCore & RISCV64Arch::getGDBCore()
{
	
	return gdbcore_;
}

// Manually added
etiss::Plugin *RISCV64Arch::newTimer(ETISS_CPU *cpu)
{
    return (etiss::Plugin *)new RISCV64Timer();
}

// Manually added
void RISCV64Arch::deleteTimer(etiss::Plugin *timer)
{
    delete timer;
}

// Manually added
etiss::mm::MMU *RISCV64Arch::newMMU(ETISS_CPU *cpu)
{
    return (etiss::mm::MMU *)new RISCV64MMU(false);
}

static const char * const reg_name[] =
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////--//
static InstructionDefinition lui_rd_imm(
 		ISA32_RISCV64,
 		"lui",
 		(uint32_t)0x37,
 		(uint32_t) 0x7f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,12);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lui\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x80000000)>>31 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition auipc_rd_imm(
 		ISA32_RISCV64,
 		"auipc",
 		(uint32_t)0x17,
 		(uint32_t) 0x7f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,12);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//auipc\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x80000000)>>31 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition jal_rd_imm(
 		ISA32_RISCV64,
 		"jal",
 		(uint32_t)0x6f,
 		(uint32_t) 0x7f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_20 (31,31);
 		etiss_int64 imm_20 = R_imm_20.read(ba);
 		imm += imm_20<<20;
 		static BitArrayRange R_imm_1 (30,21);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (20,20);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		static BitArrayRange R_imm_12 (19,12);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//jal\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x100000)>>20 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4292870144;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"
"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"cpu->instructionPointer = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition jalr_rd_rs1_imm(
 		ISA32_RISCV64,
 		"jalr",
 		(uint32_t)0x67,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//jalr\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 new_pc = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"new_pc = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"new_pc = %#lx\\n\",new_pc); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"
"cpu->instructionPointer = (new_pc & ~1)&0xffffffffffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition beq_rs1_rs2_imm(
 		ISA32_RISCV64,
 		"beq",
 		(uint32_t)0x63,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//beq\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294959104;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(*((RISCV64*)cpu)->X[" + toString(rs1) + "] == *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lb_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"lb",
 		(uint32_t)0x3,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lb\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint8 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,1);\n"
	"etiss_int8 cast_1 = MEM_offs; \n"
	"if((etiss_int8)((etiss_uint8)cast_1 - 0x80) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint8)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sb_rs2_imm_rs1_(
 		ISA32_RISCV64,
 		"sb",
 		(uint32_t)0x23,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sb\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint8 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 1 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition addi_rd_rs1_imm(
 		ISA32_RISCV64,
 		"addi",
 		(uint32_t)0x13,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//addi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition addiw_rd_rs1_imm(
 		ISA32_RISCV64,
 		"addiw",
 		(uint32_t)0x1b,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//addiw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int32 res = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"res = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"etiss_int32 cast_1 = res; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bne_rs1_rs2_imm(
 		ISA32_RISCV64,
 		"bne",
 		(uint32_t)0x1063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//bne\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294959104;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(*((RISCV64*)cpu)->X[" + toString(rs1) + "] != *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lh_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"lh",
 		(uint32_t)0x1003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lh\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint16 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,2);\n"
	"etiss_int16 cast_1 = MEM_offs; \n"
	"if((etiss_int16)((etiss_uint16)cast_1 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint16)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sh_rs2_imm_rs1_(
 		ISA32_RISCV64,
 		"sh",
 		(uint32_t)0x1023,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sh\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint16 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,2);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 2 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fence_i_(
 		ISA32_RISCV64,
 		"fence_i",
 		(uint32_t)0x100f,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_uint64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fence_i\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV64*)cpu)->FENCE[1] = " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FENCE[1] = %#lx\\n\",((RISCV64*)cpu)->FENCE[1]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrw_rd_csr_rs1(
 		ISA32_RISCV64,
 		"csrrw",
 		(uint32_t)0x1073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint64 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//csrrw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_uint64 rs_val = 0;\n"
 			"etiss_uint64 csr_val = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
			"etiss_int32 ret = 0;\n"
 			
"rs_val = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"rs_val = %#lx\\n\",rs_val); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"csr_val = ((RISCV64*)cpu)->CSR[" + toString(csr) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"csr_val = %#lx\\n\",csr_val); \n"
	#endif	
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -9223372036846388805;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -9223372036853866189;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -9223372036853866479;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | (rs_val & writeMask))&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = rs_val;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
		// manualy added
		"if(" + toString(csr) + " == 384)\n"
		"{\n"
            "ret = ETISS_SIGNAL_MMU(cpu, rs_val); \n"
        "}\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = csr_val;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -9223372036846388805;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -9223372036853866189;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -9223372036853866479;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | (rs_val & writeMask))&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = rs_val;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif
		// manualy added
		"if(" + toString(csr) + " == 384)\n"
		"{\n"
            "ret = ETISS_SIGNAL_MMU(cpu, rs_val); \n"
        "}\n"	
	"}\n"
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		"if(ret) return ret; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition blt_rs1_rs2_imm(
 		ISA32_RISCV64,
 		"blt",
 		(uint32_t)0x4063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//blt\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294959104;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
"}\n"
"if((etiss_int64)cast_1 < (etiss_int64)cast_0)\n"
"{\n"
	"etiss_int64 cast_2 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_2 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lbu_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"lbu",
 		(uint32_t)0x4003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lbu\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint8 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,1);\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)MEM_offs;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition xori_rd_rs1_imm(
 		ISA32_RISCV64,
 		"xori",
 		(uint32_t)0x4013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//xori\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 ^ imm_extended);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bge_rs1_rs2_imm(
 		ISA32_RISCV64,
 		"bge",
 		(uint32_t)0x5063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//bge\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294959104;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
"}\n"
"if((etiss_int64)cast_1 >= (etiss_int64)cast_0)\n"
"{\n"
	"etiss_int64 cast_2 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_2 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lhu_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"lhu",
 		(uint32_t)0x5003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lhu\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint16 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,2);\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)MEM_offs;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrwi_rd_csr_zimm(
 		ISA32_RISCV64,
 		"csrrwi",
 		(uint32_t)0x5073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint64 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		etiss_uint64 zimm = 0;
 		static BitArrayRange R_zimm_0 (19,15);
 		etiss_uint64 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//csrrwi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
			"etiss_int32 ret = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((RISCV64*)cpu)->CSR[" + toString(csr) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
"{\n"
	"uAddr = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"uAddr = %#lx\\n\",uAddr); \n"
	#endif	
	"sAddr = 256;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sAddr = %#lx\\n\",sAddr); \n"
	#endif	
	"mAddr = 768;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"mAddr = %#lx\\n\",mAddr); \n"
	#endif	
	"writeMaskM = -9223372036846388805;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
	#endif	
	"writeMaskS = -9223372036853866189;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
	#endif	
	"writeMaskU = -9223372036853866479;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
	#endif	
"}\n"

"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
"{\n"
	"uAddr = 68;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"uAddr = %#lx\\n\",uAddr); \n"
	#endif	
	"sAddr = 324;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sAddr = %#lx\\n\",sAddr); \n"
	#endif	
	"mAddr = 836;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"mAddr = %#lx\\n\",mAddr); \n"
	#endif	
	"writeMaskM = 3003;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
	#endif	
	"writeMaskS = 819;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
	#endif	
	"writeMaskU = 273;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
	#endif	
"}\n"

"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
"{\n"
	"uAddr = 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"uAddr = %#lx\\n\",uAddr); \n"
	#endif	
	"sAddr = 260;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sAddr = %#lx\\n\",sAddr); \n"
	#endif	
	"mAddr = 772;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"mAddr = %#lx\\n\",mAddr); \n"
	#endif	
	"writeMaskM = 3003;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
	#endif	
	"writeMaskS = 819;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
	#endif	
	"writeMaskU = 273;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
	#endif	
"}\n"

"if(uAddr != sAddr)\n"
"{\n"
	"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
	"{\n"
		"writeMask = writeMaskM;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMask = %#lx\\n\",writeMask); \n"
		#endif	
	"}\n"
	
	"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
	"{\n"
		"writeMask = writeMaskS;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMask = %#lx\\n\",writeMask); \n"
		#endif	
	"}\n"
	
	"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
	"{\n"
		"writeMask = writeMaskU;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMask = %#lx\\n\",writeMask); \n"
		#endif	
	"}\n"
	
	"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | ((etiss_uint64)" + toString(zimm) + " & writeMask))&0xffffffffffffffff;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
	#endif	
	"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
	#endif	
	"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = (etiss_uint64)" + toString(zimm) + ";\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
	#endif	
	// manually added
	"if(" + toString(csr) + " == 384)\n"
	"{\n"
        "ret = ETISS_SIGNAL_MMU(cpu, ((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
    "}\n"
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		"if(ret) return ret; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bltu_rs1_rs2_imm(
 		ISA32_RISCV64,
 		"bltu",
 		(uint32_t)0x6063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//bltu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294959104;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(*((RISCV64*)cpu)->X[" + toString(rs1) + "] < *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ori_rd_rs1_imm(
 		ISA32_RISCV64,
 		"ori",
 		(uint32_t)0x6013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//ori\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 | imm_extended);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrsi_rd_csr_zimm(
 		ISA32_RISCV64,
 		"csrrsi",
 		(uint32_t)0x6073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint64 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		etiss_uint64 zimm = 0;
 		static BitArrayRange R_zimm_0 (19,15);
 		etiss_uint64 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//csrrsi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
			"etiss_int32 ret = 0;\n"
 			
"res = ((RISCV64*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(zimm) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -9223372036846388805;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -9223372036853866189;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -9223372036853866479;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | ((res | (etiss_uint64)" + toString(zimm) + ") & writeMask))&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = (res | (etiss_uint64)" + toString(zimm) + ");\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif
		// manualy added
		"if(" + toString(csr) + " == 384)\n"
		"{\n"
            "ret = ETISS_SIGNAL_MMU(cpu, ((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
        "}\n"	
	"}\n"
"}\n"

"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		"if(ret) return ret; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lwu_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"lwu",
 		(uint32_t)0x6003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lwu\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)MEM_offs;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bgeu_rs1_rs2_imm(
 		ISA32_RISCV64,
 		"bgeu",
 		(uint32_t)0x7063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//bgeu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294959104;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(*((RISCV64*)cpu)->X[" + toString(rs1) + "] >= *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition andi_rd_rs1_imm(
 		ISA32_RISCV64,
 		"andi",
 		(uint32_t)0x7013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//andi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 & imm_extended);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrci_rd_csr_zimm(
 		ISA32_RISCV64,
 		"csrrci",
 		(uint32_t)0x7073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint64 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		etiss_uint64 zimm = 0;
 		static BitArrayRange R_zimm_0 (19,15);
 		etiss_uint64 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//csrrci\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
			"etiss_int64 ret = 0;\n"
 			
"res = ((RISCV64*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(" + toString(zimm) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -9223372036846388805;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -9223372036853866189;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -9223372036853866479;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | ((res & ~(etiss_uint64)" + toString(zimm) + ") & writeMask))&0xffffffffffffffff&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = (res & ~(etiss_uint64)" + toString(zimm) + ")&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
		// manualy added
		"if(" + toString(csr) + " == 384)\n"
		"{\n"
            "ret = ETISS_SIGNAL_MMU(cpu, ((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
        "}\n"
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		"if(ret) return ret; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lw_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"lw",
 		(uint32_t)0x2003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
	"etiss_int32 cast_1 = MEM_offs; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sw_rs2_imm_rs1_(
 		ISA32_RISCV64,
 		"sw",
 		(uint32_t)0x2023,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slti_rd_rs1_imm(
 		ISA32_RISCV64,
 		"slti",
 		(uint32_t)0x2013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//slti\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = imm_extended; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
	"}\n"
	"if((etiss_int64)cast_1 < (etiss_int64)cast_0)\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrs_rd_csr_rs1(
 		ISA32_RISCV64,
 		"csrrs",
 		(uint32_t)0x2073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint64 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//csrrs\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 xrs1 = 0;\n"
 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_uint64 xrd = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
			"etiss_int32 ret = 0;\n"
 			
"xrd = ((RISCV64*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"xrd = %#lx\\n\",xrd); \n"
#endif	
"xrs1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"xrs1 = %#lx\\n\",xrs1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = xrd;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(" + toString(rs1) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -9223372036846388805;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -9223372036853866189;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -9223372036853866479;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | ((xrd | xrs1) & writeMask))&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = (xrd | xrs1);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif
		// manualy added
		"if(" + toString(csr) + " == 384)\n"
		"{\n"
            "ret = ETISS_SIGNAL_MMU(cpu, (xrd | xrs1)); \n"
        "}\n"
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		"if(ret) return ret; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition flw_rd_imm_xrs1_(
 		ISA32_RISCV64,
 		"flw",
 		(uint32_t)0x2007,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//flw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"res = MEM_offs;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsw_rs2_imm_xrs1_(
 		ISA32_RISCV64,
 		"fsw",
 		(uint32_t)0x2027,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sltiu_rd_rs1_imm(
 		ISA32_RISCV64,
 		"sltiu",
 		(uint32_t)0x3013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sltiu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 full_imm = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = imm_extended; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"full_imm = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"full_imm = %#lx\\n\",full_imm); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if((etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs1) + "] < (etiss_uint64)full_imm)\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrc_rd_csr_rs1(
 		ISA32_RISCV64,
 		"csrrc",
 		(uint32_t)0x3073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint64 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//csrrc\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 xrs1 = 0;\n"
 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_uint64 xrd = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
			"etiss_int32 ret = 0;\n"
 			
"xrd = ((RISCV64*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"xrd = %#lx\\n\",xrd); \n"
#endif	
"xrs1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"xrs1 = %#lx\\n\",xrs1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = xrd;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(" + toString(rs1) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -9223372036846388805;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -9223372036853866189;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -9223372036853866479;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"uAddr = %#lx\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"sAddr = %#lx\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"mAddr = %#lx\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV64*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV64*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"writeMask = %#lx\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV64*)cpu)->CSR[uAddr] = ((((RISCV64*)cpu)->CSR[uAddr] & ~writeMask) | ((xrd & ~xrs1) & writeMask))&0xffffffffffffffff&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[uAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[sAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[sAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV64*)cpu)->CSR[mAddr] = ((RISCV64*)cpu)->CSR[uAddr];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[mAddr] = %#lx\\n\",((RISCV64*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = (xrd & ~xrs1)&0xffffffffffffffff;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"((RISCV64*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
		// manualy added
		"if(" + toString(csr) + " == 384)\n"
		"{\n"
            "ret = ETISS_SIGNAL_MMU(cpu, ((RISCV64*)cpu)->CSR[" + toString(csr) + "]); \n"
        "}\n"
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		"if(ret) return ret; \n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ld_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"ld",
 		(uint32_t)0x3003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//ld\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint64 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
	"etiss_int64 cast_1 = MEM_offs; \n"
	"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sd_rs2_imm_rs1_(
 		ISA32_RISCV64,
 		"sd",
 		(uint32_t)0x3023,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sd\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"if(exception)\n"
		"{\n"
			// set stval and mtval in case of exception
			"((RISCV64*)cpu)->X[0x143] = offs;\n"
			"((RISCV64*)cpu)->X[0x343] = offs;\n"
			"return exception;\n"
		"}\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fld_rd_imm_rs1_(
 		ISA32_RISCV64,
 		"fld",
 		(uint32_t)0x3007,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fld\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"res = MEM_offs;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsd_rs2_imm_rs1_(
 		ISA32_RISCV64,
 		"fsd",
 		(uint32_t)0x3027,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsd\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"offs = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmadd_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fmadd.s",
 		(uint32_t)0x43,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmadd.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			"etiss_uint32 frs3 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], ((RISCV64*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)0, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)0, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmsub_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fmsub.s",
 		(uint32_t)0x47,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmsub.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			"etiss_uint32 frs3 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], ((RISCV64*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)1, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)1, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmadd_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fnmadd.s",
 		(uint32_t)0x4f,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fnmadd.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			"etiss_uint32 frs3 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], ((RISCV64*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)2, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)2, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmsub_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fnmsub.s",
 		(uint32_t)0x4b,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fnmsub.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			"etiss_uint32 frs3 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], ((RISCV64*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)3, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)3, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmadd_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fmadd.d",
 		(uint32_t)0x2000043,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmadd.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint64)0, choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmsub_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fmsub.d",
 		(uint32_t)0x2000047,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmsub.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint32)1, choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmadd_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fnmadd.d",
 		(uint32_t)0x200004f,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fnmadd.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint32)2, choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmsub_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV64,
 		"fnmsub.d",
 		(uint32_t)0x200004b,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint64 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fnmsub.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint32)3, choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slli_rd_rs1_shamt(
 		ISA32_RISCV64,
 		"slli",
 		(uint32_t)0x1013,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_0 (25,20);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//slli\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] << " + toString(shamt) + ");\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srli_rd_rs1_shamt(
 		ISA32_RISCV64,
 		"srli",
 		(uint32_t)0x5013,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_0 (25,20);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//srli\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] >> " + toString(shamt) + ");\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srai_rd_rs1_shamt(
 		ISA32_RISCV64,
 		"srai",
 		(uint32_t)0x40005013,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_0 (25,20);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//srai\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 >> " + toString(shamt) + ");\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition add_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"add",
 		(uint32_t)0x33,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//add\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = *((RISCV64*)cpu)->X[" + toString(rs1) + "] + *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition addw_(
 		ISA32_RISCV64,
 		"addw",
 		(uint32_t)0x3b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//addw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"res = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) + (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"etiss_int32 cast_0 = res; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sll_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sll",
 		(uint32_t)0x1033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sll\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {4, 5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {4, 5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] << (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 64 - 1));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slliw_rd_rs1_shamt(
 		ISA32_RISCV64,
 		"slliw",
 		(uint32_t)0x101b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_0 (24,20);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//slliw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"sh_val = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) << " + toString(shamt) + ");\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sh_val = %#x\\n\",sh_val); \n"
	#endif	
	"etiss_int32 cast_0 = sh_val; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sllw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sllw",
 		(uint32_t)0x103b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sllw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			"etiss_uint32 count = 0;\n"
 			"etiss_int32 mask = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"mask = 31;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"mask = %#x\\n\",mask); \n"
	#endif	
	"count = ((*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) & mask);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"count = %#x\\n\",count); \n"
	#endif	
	"sh_val = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) << count);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sh_val = %#x\\n\",sh_val); \n"
	#endif	
	"etiss_int32 cast_0 = sh_val; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slt_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"slt",
 		(uint32_t)0x2033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//slt\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 choose1 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
	"}\n"
	"if((etiss_int64)cast_1 < (etiss_int64)cast_0)\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sltu_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sltu",
 		(uint32_t)0x3033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sltu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 choose1 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if((etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs1) + "] < (etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition xor_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"xor",
 		(uint32_t)0x4033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//xor\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] ^ *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srl_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"srl",
 		(uint32_t)0x5033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//srl\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] >> (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 64 - 1));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srliw_rd_rs1_shamt(
 		ISA32_RISCV64,
 		"srliw",
 		(uint32_t)0x501b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_0 (24,20);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//srliw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"sh_val = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) >> " + toString(shamt) + ");\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sh_val = %#x\\n\",sh_val); \n"
	#endif	
	"etiss_int32 cast_0 = sh_val; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srlw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"srlw",
 		(uint32_t)0x503b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//srlw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			"etiss_uint32 count = 0;\n"
 			"etiss_int32 mask = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"mask = 31;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"mask = %#x\\n\",mask); \n"
	#endif	
	"count = ((*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) & mask);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"count = %#x\\n\",count); \n"
	#endif	
	"sh_val = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) >> count);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sh_val = %#x\\n\",sh_val); \n"
	#endif	
	"etiss_int32 cast_0 = sh_val; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition or_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"or",
 		(uint32_t)0x6033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//or\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] | *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition and_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"and",
 		(uint32_t)0x7033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//and\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition uret_(
 		ISA32_RISCV64,
 		"uret",
 		(uint32_t)0x200073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//uret\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

"etiss_int32 ret = 0;\n"
"if (((RISCV64*)cpu)->CSR[3088] != 0)\n"//check if PRVLVL will change, therefore leading to context-switch
"{\n"
	"((RISCV64*)cpu)->CSR[3088] = 0;\n"//PRIVLV=0
	"ret = -2;\n"//context-switch occured, flush etiss-translation-cache
"}\n" 			
"((RISCV64*)cpu)->CSR[0] ^= ((etiss_uint32)((((RISCV64*)cpu)->CSR[0] & 0x10)>>4)) ^ (((RISCV64*)cpu)->CSR[0] & 0x1);\n"//UIE=UPIE
"cpu->instructionPointer = ((RISCV64*)cpu)->CSR[65];\n"//PC=UEPC
"((RISCV64*)cpu)->CSR[768]= ((RISCV64*)cpu)->CSR[0];\n"//keep MSTATUS synchronous to USTATUS
"((RISCV64*)cpu)->CSR[256]=((RISCV64*)cpu)->CSR[0];\n"//keep SSTATUS synchronous to USTATUS
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return ret;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fadd_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fadd.s",
 		(uint32_t)0x53,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fadd.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fadd_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fadd_s(frs1, frs2, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sub_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sub",
 		(uint32_t)0x40000033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sub\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = *((RISCV64*)cpu)->X[" + toString(rs1) + "] - *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition subw_(
 		ISA32_RISCV64,
 		"subw",
 		(uint32_t)0x4000003b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//subw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"res = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) - (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"etiss_int32 cast_0 = res; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sra_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sra",
 		(uint32_t)0x40005033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sra\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 >> (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 64 - 1));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sraiw_rd_rs1_shamt(
 		ISA32_RISCV64,
 		"sraiw",
 		(uint32_t)0x4000501b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_0 (24,20);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sraiw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 sh_val = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"sh_val = ((etiss_int32)cast_0 >> " + toString(shamt) + ");\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sh_val = %#x\\n\",sh_val); \n"
	#endif	
	"etiss_int32 cast_1 = sh_val; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sraw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sraw",
 		(uint32_t)0x4000503b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sraw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			"etiss_uint32 count = 0;\n"
 			"etiss_int32 mask = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"mask = 31;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"mask = %#x\\n\",mask); \n"
	#endif	
	"count = ((*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) & mask);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"count = %#x\\n\",count); \n"
	#endif	
	"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"sh_val = ((etiss_int32)cast_0 >> count);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"sh_val = %#x\\n\",sh_val); \n"
	#endif	
	"etiss_int32 cast_1 = sh_val; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_d_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.s.d",
 		(uint32_t)0x40100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.s.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fconv_d2f(((RISCV64*)cpu)->F[" + toString(rs1) + "], (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"upper =  - 1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"upper = %#lx\\n\",upper); \n"
#endif	
"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fence_(
 		ISA32_RISCV64,
 		"fence",
 		(uint32_t)0xf,
 		(uint32_t) 0xf000707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 succ = 0;
 		static BitArrayRange R_succ_0 (23,20);
 		etiss_uint64 succ_0 = R_succ_0.read(ba);
 		succ += succ_0;
 		etiss_uint64 pred = 0;
 		static BitArrayRange R_pred_0 (27,24);
 		etiss_uint64 pred_0 = R_pred_0.read(ba);
 		pred += pred_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[0],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fence\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV64*)cpu)->FENCE[0] = ((" + toString(pred) + " << 4) | " + toString(succ) + ");\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FENCE[0] = %#lx\\n\",((RISCV64*)cpu)->FENCE[0]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ecall_(
 		ISA32_RISCV64,
 		"ecall",
 		(uint32_t)0x73,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//ecall\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"exception = ETISS_RETURNCODE_SYSCALL; \n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ebreak_(
 		ISA32_RISCV64,
 		"ebreak",
 		(uint32_t)0x100073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//ebreak\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"return ETISS_RETURNCODE_CPUFINISHED; \n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sret_(
 		ISA32_RISCV64,
 		"sret",
 		(uint32_t)0x10200073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sret\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

"etiss_int32 ret = 0;\n"
"if (((RISCV64*)cpu)->CSR[3088] != (((RISCV64*)cpu)->CSR[256] & 0x100)>>8)\n"//check if PRVLVL will change, therefore leading to context-switch
"{\n"
	"((RISCV64*)cpu)->CSR[3088] = (((RISCV64*)cpu)->CSR[256] & 0x100)>>8;\n"//PRIVLV=SPP
	"ret = -2;\n"//context-switch occured, flush etiss-translation-cache
"}\n" 			
"((RISCV64*)cpu)->CSR[256] ^= (((RISCV64*)cpu)->CSR[256] & 0x100);\n"//SPP=0
"((RISCV64*)cpu)->CSR[256] ^= ((etiss_uint32)((((RISCV64*)cpu)->CSR[256] & 0x20)>>4)) ^ (((RISCV64*)cpu)->CSR[256] & 0x2);\n"//SIE=SPIE
"cpu->instructionPointer = ((RISCV64*)cpu)->CSR[321];\n"//PC=SEPC
"((RISCV64*)cpu)->CSR[768]= ((RISCV64*)cpu)->CSR[256];\n"//keep MSTATUS synchronous to SSTATUS
"((RISCV64*)cpu)->CSR[0]=((RISCV64*)cpu)->CSR[256];\n"//keep USTATUS synchronous to SSTATUS
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return ret;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition wfi_(
 		ISA32_RISCV64,
 		"wfi",
 		(uint32_t)0x10500073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//wfi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"return ETISS_RETURNCODE_CPUFINISHED; \n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmul_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fmul.s",
 		(uint32_t)0x10000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmul.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fmul_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmul_s(frs1, frs2, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mret_(
 		ISA32_RISCV64,
 		"mret",
 		(uint32_t)0x30200073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//mret\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

"etiss_int32 ret = 0;\n"
"if (((RISCV64*)cpu)->CSR[3088] != (((RISCV64*)cpu)->CSR[768] & 0x1800)>>11)\n"//check if PRVLVL will change, therefore leading to context-switch
"{\n"
	"((RISCV64*)cpu)->CSR[3088] = (((RISCV64*)cpu)->CSR[768] & 0x1800)>>11;\n"//PRIVLV=MPP
	"ret = -2;\n"//context-switch occured, flush etiss-translation-cache
"}\n"		
"((RISCV64*)cpu)->CSR[768] ^= (((RISCV64*)cpu)->CSR[768] & 0x1800);\n"//MPP=0
"((RISCV64*)cpu)->CSR[768] ^= ((etiss_uint32)((((RISCV64*)cpu)->CSR[768] & 0x80)>>4)) ^ (((RISCV64*)cpu)->CSR[768] & 0x8);\n"//MIE=MPIE
"cpu->instructionPointer = ((RISCV64*)cpu)->CSR[833];\n"//PC=MEPC
"((RISCV64*)cpu)->CSR[0]= ((RISCV64*)cpu)->CSR[768];\n"//keep USTATUS synchronous to MSTATUS
"((RISCV64*)cpu)->CSR[256]=((RISCV64*)cpu)->CSR[768];\n"//keep SSTATUS synchronous to MSTATUS
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return ret;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sfence_vma_(
 		ISA32_RISCV64,
 		"sfence.vma",
 		(uint32_t)0x12000073,
 		(uint32_t) 0xfe007fff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[2],64);
  		partInit.getAffectedRegisters().add(reg_name[3],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sfence.vma\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV64*)cpu)->FENCE[2] = " + toString(rs1) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FENCE[2] = %#lx\\n\",((RISCV64*)cpu)->FENCE[2]); \n"
#endif	
"((RISCV64*)cpu)->FENCE[3] = " + toString(rs2) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FENCE[3] = %#lx\\n\",((RISCV64*)cpu)->FENCE[3]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		// manually added
		"ETISS_SIGNAL_TLB_FLUSH(cpu);\n" // signal tlb flush to MMU
		"return -2;\n" // return RELOADBLOCKS to flush translation cache
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmul_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fmul.d",
 		(uint32_t)0x12000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmul.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmul_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"mul",
 		(uint32_t)0x2000033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//mul\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {3}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {8}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"res = ((etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs1) + "] * (etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"mulw",
 		(uint32_t)0x200003b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//mulw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) * (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff)); \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulh_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"mulh",
 		(uint32_t)0x2001033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//mulh\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
	"}\n"
	"res = ((etiss_int64)cast_1 * (etiss_int64)cast_0);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)(res >> 64);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulhsu_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"mulhsu",
 		(uint32_t)0x2002033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//mulhsu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"res = ((etiss_int64)cast_0 * (etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)(res >> 64);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulhu_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"mulhu",
 		(uint32_t)0x2003033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//mulhu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"res = ((etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs1) + "] * (etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)(res >> 64);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition div_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"div",
 		(uint32_t)0x2004033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//div\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 XLM1 = 0;\n"
 			"etiss_int64 MMIN = 0;\n"
 			"etiss_int64 M1 = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV64*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"M1 =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"M1 = %#lx\\n\",M1); \n"
		#endif	
		"XLM1 = 64 - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"XLM1 = %#x\\n\",XLM1); \n"
		#endif	
		"ONE = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"ONE = %#lx\\n\",ONE); \n"
		#endif	
		"MMIN = (ONE << XLM1);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"MMIN = %#lx\\n\",MMIN); \n"
		#endif	
		"if((*((RISCV64*)cpu)->X[" + toString(rs1) + "] == MMIN) && (*((RISCV64*)cpu)->X[" + toString(rs2) + "] == M1))\n"
		"{\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = MMIN;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
		
		"else\n"
		"{\n"
			"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
			"}\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_1 / (etiss_int64)cast_0);\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition divw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"divw",
 		(uint32_t)0x200403b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//divw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 MMIN = 0;\n"
 			"etiss_int32 M1 = 0;\n"
 			"etiss_int32 ONE = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV64*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"M1 =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"M1 = %#x\\n\",M1); \n"
		#endif	
		"ONE = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"ONE = %#x\\n\",ONE); \n"
		#endif	
		"MMIN = (ONE << 31);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"MMIN = %#x\\n\",MMIN); \n"
		#endif	
		"if(((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) == MMIN) && ((*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) == M1))\n"
		"{\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ( - 1 << 31);\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
		
		"else\n"
		"{\n"
			"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff); \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"etiss_int64 cast_1 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
			"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
			"}\n"
			"etiss_int64 cast_2 = ((etiss_int64)cast_1 / (etiss_int64)cast_0); \n"
			"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
			"}\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_2;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition divu_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"divu",
 		(uint32_t)0x2005033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//divu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV64*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] / *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition divuw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"divuw",
 		(uint32_t)0x200503b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//divuw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if((*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) != 0)\n"
	"{\n"
		"etiss_int64 cast_0 = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) / (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff)); \n"
		"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
		"{\n"
			"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
		"}\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition rem_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"rem",
 		(uint32_t)0x2006033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//rem\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 XLM1 = 0;\n"
 			"etiss_int64 MMIN = 0;\n"
 			"etiss_int64 M1 = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV64*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"M1 =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"M1 = %#lx\\n\",M1); \n"
		#endif	
		"XLM1 = 64 - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"XLM1 = %#x\\n\",XLM1); \n"
		#endif	
		"ONE = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"ONE = %#lx\\n\",ONE); \n"
		#endif	
		"MMIN = (ONE << XLM1);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"MMIN = %#lx\\n\",MMIN); \n"
		#endif	
		"if((*((RISCV64*)cpu)->X[" + toString(rs1) + "] == MMIN) && (*((RISCV64*)cpu)->X[" + toString(rs2) + "] == M1))\n"
		"{\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = 0;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
		
		"else\n"
		"{\n"
			"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
			"}\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_1 % (etiss_int64)cast_0);\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition remw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"remw",
 		(uint32_t)0x200603b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//remw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 MMIN = 0;\n"
 			"etiss_int32 M1 = 0;\n"
 			"etiss_int32 ONE = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV64*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"M1 =  - 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"M1 = %#x\\n\",M1); \n"
		#endif	
		"ONE = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"ONE = %#x\\n\",ONE); \n"
		#endif	
		"MMIN = (ONE << 31);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"MMIN = %#x\\n\",MMIN); \n"
		#endif	
		"if(((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) == MMIN) && (*((RISCV64*)cpu)->X[" + toString(rs2) + "] == M1))\n"
		"{\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = 0;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
		
		"else\n"
		"{\n"
			"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff); \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"etiss_int64 cast_1 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
			"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
			"}\n"
			"etiss_int64 cast_2 = ((etiss_int64)cast_1 % (etiss_int64)cast_0); \n"
			"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
			"}\n"
			"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_2;\n"
			#if RISCV64_DEBUG_CALL
			"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
	"}\n"
	
	"else\n"
	"{\n"
		"etiss_int64 cast_3 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
		"if((etiss_int64)((etiss_uint64)cast_3 - 0x8000000000000000) > 0x0)\n"
		"{\n"
			"cast_3 =0x0 + (etiss_uint64)cast_3 ;\n"
		"}\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_3;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition remu_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"remu",
 		(uint32_t)0x2007033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//remu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV64*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] % *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition remuw_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"remuw",
 		(uint32_t)0x200703b,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//remuw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if((*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) != 0)\n"
	"{\n"
		"etiss_int64 cast_0 = ((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) % (*((RISCV64*)cpu)->X[" + toString(rs2) + "] & 0xffffffff)); \n"
		"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
		"{\n"
			"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
		"}\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"etiss_int64 cast_1 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
		"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
		"{\n"
			"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
		"}\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fadd_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fadd.d",
 		(uint32_t)0x2000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fadd.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fadd_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lr_w_rd_rs1(
 		ISA32_RISCV64,
 		"lr.w",
 		(uint32_t)0x1000202f,
 		(uint32_t) 0xf9f0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lr.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"offs = %#lx\\n\",offs); \n"
	#endif	
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
	"etiss_int32 cast_0 = MEM_offs; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
	"((RISCV64*)cpu)->RES = offs;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lr_d_rd_rs1(
 		ISA32_RISCV64,
 		"lr.d",
 		(uint32_t)0x1000302f,
 		(uint32_t) 0xf9f0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//lr.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"offs = %#lx\\n\",offs); \n"
	#endif	
	"etiss_uint64 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
	"etiss_int64 cast_0 = MEM_offs; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
	"((RISCV64*)cpu)->RES = offs;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sc_w_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sc.w",
 		(uint32_t)0x1800202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sc.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(offs == ((RISCV64*)cpu)->RES)\n"
"{\n"
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
	#endif	
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sc_d_rd_rs1_rs2(
 		ISA32_RISCV64,
 		"sc.d",
 		(uint32_t)0x1800302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//sc.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(offs == ((RISCV64*)cpu)->RES)\n"
"{\n"
	"etiss_uint64 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
	#endif	
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = 0;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV64*)cpu)->X[" + toString(rd) + "] = 1;\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoswap_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoswap.w",
 		(uint32_t)0x800202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoswap.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
	"etiss_int32 cast_0 = MEM_offs; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoswap_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoswap.d",
 		(uint32_t)0x800302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoswap.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint64 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
	"etiss_int64 cast_0 = MEM_offs; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoadd_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoadd.w",
 		(uint32_t)0x202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoadd.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = res1 + *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoadd_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoadd.d",
 		(uint32_t)0x302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoadd.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = res + *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoxor_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoxor.w",
 		(uint32_t)0x2000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoxor.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res1 ^ *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoxor_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoxor.d",
 		(uint32_t)0x2000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoxor.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res ^ *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoand_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoand.w",
 		(uint32_t)0x6000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoand.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res1 & *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoand_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoand.d",
 		(uint32_t)0x6000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoand.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res & *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoor_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoor.w",
 		(uint32_t)0x4000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoor.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res1 | *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoor_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amoor.d",
 		(uint32_t)0x4000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amoor.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res | *((RISCV64*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomin_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amomin.w",
 		(uint32_t)0x8000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amomin.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
"}\n"
"etiss_int64 cast_2 = res1; \n"
"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
"}\n"
"if((etiss_int64)cast_2 > (etiss_int64)cast_1)\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomin_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amomin.d",
 		(uint32_t)0x8000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amomin.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
"}\n"
"etiss_int64 cast_2 = res1; \n"
"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
"}\n"
"if((etiss_int64)cast_2 > (etiss_int64)cast_1)\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomax_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amomax.w",
 		(uint32_t)0xa000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amomax.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
"}\n"
"etiss_int64 cast_2 = res1; \n"
"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
"}\n"
"if((etiss_int64)cast_2 < (etiss_int64)cast_1)\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomax_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amomax.d",
 		(uint32_t)0xa000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amomax.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"etiss_int64 cast_1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
"}\n"
"etiss_int64 cast_2 = res; \n"
"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
"}\n"
"if((etiss_int64)cast_2 < (etiss_int64)cast_1)\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amominu_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amominu.w",
 		(uint32_t)0xc000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amominu.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(res1 > *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amominu_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amominu.d",
 		(uint32_t)0xc000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amominu.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(res > *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomaxu_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amomaxu.w",
 		(uint32_t)0xe000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amomaxu.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(res1 < *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomaxu_d_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV64,
 		"amomaxu.d",
 		(uint32_t)0xe000302f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint64 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint64 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//amomaxu.d\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res1 = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res1 = %#lx\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(res1 < *((RISCV64*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"choose1 = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res2 = %#lx\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsub_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsub.s",
 		(uint32_t)0x8000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsub.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fsub_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fsub_s(frs1, frs2, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fdiv_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fdiv.s",
 		(uint32_t)0x18000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fdiv.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fdiv_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fdiv_s(frs1, frs2, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsqrt_s_rd_frs1(
 		ISA32_RISCV64,
 		"fsqrt.s",
 		(uint32_t)0x58000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsqrt.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fsqrt_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
		#if RISCV64_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fsqrt_s(frs1, choose1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnj_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsgnj.s",
 		(uint32_t)0x20000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsgnj.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 2147483647) | (((RISCV64*)cpu)->F[" + toString(rs2) + "] & -2147483648));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = ((frs1 & 2147483647) | (frs2 & -2147483648));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjn_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsgnjn.s",
 		(uint32_t)0x20001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsgnjn.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 2147483647) | (~((RISCV64*)cpu)->F[" + toString(rs2) + "] & -2147483648))&0xffffffffffffffff;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = ((frs1 & 2147483647) | (~frs2 & -2147483648))&0xffffffff;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjx_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsgnjx.s",
 		(uint32_t)0x20002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsgnjx.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = (((RISCV64*)cpu)->F[" + toString(rs1) + "] ^ (((RISCV64*)cpu)->F[" + toString(rs2) + "] & -2147483648));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = (frs1 ^ (frs2 & -2147483648));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmin_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fmin.s",
 		(uint32_t)0x28000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmin.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fsel_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)0);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = fsel_s(frs1, frs2, (etiss_uint32)0);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmax_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fmax.s",
 		(uint32_t)0x28001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmax.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fsel_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = fsel_s(frs1, frs2, (etiss_uint32)1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_w_s_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.w.s",
 		(uint32_t)0xc0000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.w.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"etiss_int32 cast_0 = fcvt_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"etiss_int32 cast_1 = fcvt_s(frs1, (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_wu_s_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.wu.s",
 		(uint32_t)0xc0100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.wu.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"etiss_int32 cast_0 = fcvt_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"etiss_int32 cast_1 = fcvt_s(frs1, (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_l_s_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.l.s",
 		(uint32_t)0xc0200053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.l.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			
"res = fcvt_32_64(unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]), (etiss_uint32)0, (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"etiss_int64 cast_0 = res; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_lu_s_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.lu.s",
 		(uint32_t)0xc0300053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.lu.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			
"res = fcvt_32_64(unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]), (etiss_uint32)1, (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)res;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition feq_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"feq.s",
 		(uint32_t)0xa0002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//feq.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)0);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_s(frs1, frs2, (etiss_uint32)0);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition flt_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"flt.s",
 		(uint32_t)0xa0001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//flt.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)2);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_s(frs1, frs2, (etiss_uint32)2);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = fcmp_s((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffff), (etiss_uint32)2);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fle_s_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fle.s",
 		(uint32_t)0xa0000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fle.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_s(((RISCV64*)cpu)->F[" + toString(rs1) + "], ((RISCV64*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV64*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_s(frs1, frs2, (etiss_uint32)1);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fclass_s_rd_frs1(
 		ISA32_RISCV64,
 		"fclass.s",
 		(uint32_t)0xe0001053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fclass.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = fclass_s(unbox_s(((RISCV64*)cpu)->F[" + toString(rs1) + "]));\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmv_x_w_rd_frs1(
 		ISA32_RISCV64,
 		"fmv.x.w",
 		(uint32_t)0xe0000053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmv.x.w\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"etiss_int64 cast_0 = (((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffff); \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_w_rd_rs1(
 		ISA32_RISCV64,
 		"fcvt.s.w",
 		(uint32_t)0xd0000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.s.w\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fcvt_s((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"res = fcvt_s((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_wu_rd_rs1(
 		ISA32_RISCV64,
 		"fcvt.s.wu",
 		(uint32_t)0xd0100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.s.wu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = fcvt_s((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"res = fcvt_s((*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_l_rd_xrs1(
 		ISA32_RISCV64,
 		"fcvt.s.l",
 		(uint32_t)0xd0200053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.s.l\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fcvt_64_32(*((RISCV64*)cpu)->X[" + toString(rs1) + "], (etiss_uint32)2);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_lu_rd_xrs1(
 		ISA32_RISCV64,
 		"fcvt.s.lu",
 		(uint32_t)0xd0300053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.s.lu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fcvt_64_32(*((RISCV64*)cpu)->X[" + toString(rs1) + "], (etiss_uint32)3);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmv_w_x_rd_rs1(
 		ISA32_RISCV64,
 		"fmv.w.x",
 		(uint32_t)0xf0000053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmv.w.x\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 upper = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)(*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff));\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsub_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsub.d",
 		(uint32_t)0xa000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsub.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fsub_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fdiv_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fdiv.d",
 		(uint32_t)0x1a000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fdiv.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fdiv_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsqrt_d_rd_frs1(
 		ISA32_RISCV64,
 		"fsqrt.d",
 		(uint32_t)0x5a000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsqrt.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV64*)cpu)->FCSR & 0xff);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fsqrt_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnj_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsgnj.d",
 		(uint32_t)0x22000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsgnj.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_int64 MSK1 = 0;\n"
 			"etiss_int64 MSK2 = 0;\n"
 			
"ONE = 1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"ONE = %#lx\\n\",ONE); \n"
#endif	
"MSK1 = (ONE << 63);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MSK1 = %#lx\\n\",MSK1); \n"
#endif	
"MSK2 = MSK1 - 1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"MSK2 = %#lx\\n\",MSK2); \n"
#endif	
"res = (((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff) & MSK2) | ((((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff) & MSK1));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjn_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsgnjn.d",
 		(uint32_t)0x22001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsgnjn.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_int64 MSK1 = 0;\n"
 			"etiss_int64 MSK2 = 0;\n"
 			
"ONE = 1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"ONE = %#lx\\n\",ONE); \n"
#endif	
"MSK1 = (ONE << 63);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MSK1 = %#lx\\n\",MSK1); \n"
#endif	
"MSK2 = MSK1 - 1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"MSK2 = %#lx\\n\",MSK2); \n"
#endif	
"res = (((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff) & MSK2) | (~(((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff) & MSK1))&0xffffffffffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjx_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fsgnjx.d",
 		(uint32_t)0x22002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fsgnjx.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_int64 MSK1 = 0;\n"
 			
"ONE = 1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"ONE = %#lx\\n\",ONE); \n"
#endif	
"MSK1 = (ONE << 63);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MSK1 = %#lx\\n\",MSK1); \n"
#endif	
"res = ((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff) ^ ((((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff) & MSK1));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmin_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fmin.d",
 		(uint32_t)0x2a000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmin.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			
"res = fsel_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)0);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmax_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fmax.d",
 		(uint32_t)0x2a001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmax.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			
"res = fsel_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_s_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.d.s",
 		(uint32_t)0x42000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.d.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fconv_f2d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffff), (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition feq_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"feq.d",
 		(uint32_t)0xa2002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//feq.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)0);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition flt_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"flt.d",
 		(uint32_t)0xa2001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//flt.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)2);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fle_d_rd_frs1_frs2(
 		ISA32_RISCV64,
 		"fle.d",
 		(uint32_t)0xa2000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fle.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)fcmp_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)1);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fclass_d_rd_frs1(
 		ISA32_RISCV64,
 		"fclass.d",
 		(uint32_t)0xe2001053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fclass.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = fclass_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmv_x_d_rd_frs1(
 		ISA32_RISCV64,
 		"fmv.x.d",
 		(uint32_t)0xe2000053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmv.x.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"etiss_int64 cast_0 = ((RISCV64*)cpu)->F[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_w_d_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.w.d",
 		(uint32_t)0xc2000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.w.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"etiss_int32 cast_0 = fcvt_64_32((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_wu_d_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.wu.d",
 		(uint32_t)0xc2100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.wu.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"etiss_int32 cast_0 = fcvt_64_32((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_l_d_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.l.d",
 		(uint32_t)0xc2200053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.l.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"etiss_int64 cast_0 = fcvt_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_lu_d_rd_frs1(
 		ISA32_RISCV64,
 		"fcvt.lu.d",
 		(uint32_t)0xc2300053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.lu.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"etiss_int64 cast_0 = fcvt_d((((RISCV64*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV64_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV64*)cpu)->FCSR = (((RISCV64*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->FCSR = %#x\\n\",((RISCV64*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_w_rd_rs1(
 		ISA32_RISCV64,
 		"fcvt.d.w",
 		(uint32_t)0xd2000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.d.w\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = fcvt_32_64((etiss_int64)cast_0, (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_wu_rd_rs1(
 		ISA32_RISCV64,
 		"fcvt.d.wu",
 		(uint32_t)0xd2100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.d.wu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fcvt_32_64((etiss_uint64)(*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_l_rd_rs1(
 		ISA32_RISCV64,
 		"fcvt.d.l",
 		(uint32_t)0xd2200053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.d.l\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"res = fcvt_d((etiss_int64)cast_0, (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_lu_rd_rs1(
 		ISA32_RISCV64,
 		"fcvt.d.lu",
 		(uint32_t)0xd2300053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint64 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fcvt.d.lu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fcvt_d((etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs1) + "], (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmv_d_x_rd_rs1(
 		ISA32_RISCV64,
 		"fmv.d.x",
 		(uint32_t)0xf2000053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//fmv.d.x\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV64*)cpu)->F[" + toString(rd) + "] = (etiss_uint64)*((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi4spn_rd_imm(
 		ISA16_RISCV64,
 		"c.addi4spn",
 		(uint16_t)0x0,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 imm = 0;
 		static BitArrayRange R_imm_4 (12,11);
 		etiss_uint64 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_6 (10,7);
 		etiss_uint64 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_2 (6,6);
 		etiss_uint64 imm_2 = R_imm_2.read(ba);
 		imm += imm_2<<2;
 		static BitArrayRange R_imm_3 (5,5);
 		etiss_uint64 imm_3 = R_imm_3.read(ba);
 		imm += imm_3<<3;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.addi4spn\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(imm) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = *((RISCV64*)cpu)->X[2] + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi_rs1_imm(
 		ISA16_RISCV64,
 		"c.addi",
 		(uint16_t)0x1,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.addi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294967232;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rs1) + "] = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rs1) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rs1) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_nop_(
 		ISA16_RISCV64,
 		"c.nop",
 		(uint16_t)0x1,
 		(uint16_t) 0xffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.nop\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition dii_(
 		ISA16_RISCV64,
 		"dii",
 		(uint16_t)0x0,
 		(uint16_t) 0xffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//dii\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_slli_rs1_shamt(
 		ISA16_RISCV64,
 		"c.slli",
 		(uint16_t)0x2,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_5 (12,12);
 		etiss_uint64 shamt_5 = R_shamt_5.read(ba);
 		shamt += shamt_5<<5;
 		static BitArrayRange R_shamt_0 (6,2);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.slli\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rs1) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV64*)cpu)->X[" + toString(rs1) + "] = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] << " + toString(shamt) + ");\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rs1) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rs1) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lw_8_rd_uimm_8_rs1_(
 		ISA16_RISCV64,
 		"c.lw",
 		(uint16_t)0x4000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_2 (6,6);
 		etiss_uint64 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (5,5);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.lw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_li_rd_imm(
 		ISA16_RISCV64,
 		"c.li",
 		(uint16_t)0x4001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.li\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294967232;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV64*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lwsp_rd_sp_uimm(
 		ISA16_RISCV64,
 		"c.lwsp",
 		(uint16_t)0x4002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_5 (12,12);
 		etiss_uint64 uimm_5 = R_uimm_5.read(ba);
 		uimm += uimm_5<<5;
 		static BitArrayRange R_uimm_2 (6,4);
 		etiss_uint64 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (3,2);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.lwsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sw_8_rs2_uimm_8_rs1_(
 		ISA16_RISCV64,
 		"c.sw",
 		(uint16_t)0xc000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_2 (6,6);
 		etiss_uint64 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (5,5);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.sw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + " + 8];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_beqz_8_rs1_imm(
 		ISA16_RISCV64,
 		"c.beqz",
 		(uint16_t)0xc001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_8 (12,12);
 		etiss_int64 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_3 (11,10);
 		etiss_int64 imm_3 = R_imm_3.read(ba);
 		imm += imm_3<<3;
 		static BitArrayRange R_imm_6 (6,5);
 		etiss_int64 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_1 (4,3);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.beqz\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x100)>>8 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294966784;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(*((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] == 0)\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 2;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_swsp_rs2_uimm_sp_(
 		ISA16_RISCV64,
 		"c.swsp",
 		(uint16_t)0xc002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_2 (12,9);
 		etiss_uint64 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (8,7);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.swsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addiw_rs1_imm(
 		ISA16_RISCV64,
 		"c.addiw",
 		(uint16_t)0x2001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.addiw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int32 res = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294967232;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rs1) + " != 0)\n"
"{\n"
	"etiss_int64 cast_0 = (*((RISCV64*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"res = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"etiss_int32 cast_1 = res; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rs1) + "] = (etiss_int64)cast_1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rs1) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rs1) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fld_rd_uimm_8_rs1_(
 		ISA16_RISCV64,
 		"c.fld",
 		(uint16_t)0x2000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (6,5);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.fld\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"res = MEM_offs;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + " + 8] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + " + 8] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + " + 8]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + " + 8] = ((upper << 64) | res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + " + 8] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + " + 8]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fldsp_rd_uimm_x2_(
 		ISA16_RISCV64,
 		"c.fldsp",
 		(uint16_t)0x2002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_5 (12,12);
 		etiss_uint64 uimm_5 = R_uimm_5.read(ba);
 		uimm += uimm_5<<5;
 		static BitArrayRange R_uimm_3 (6,5);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (4,2);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.fldsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"res = MEM_offs;\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV64*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | (etiss_uint64)res);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV64*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lui_rd_imm(
 		ISA16_RISCV64,
 		"c.lui",
 		(uint16_t)0x6001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 imm = 0;
 		static BitArrayRange R_imm_17 (12,12);
 		etiss_uint64 imm_17 = R_imm_17.read(ba);
 		imm += imm_17<<17;
 		static BitArrayRange R_imm_12 (6,2);
 		etiss_int64 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.lui\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x20000)>>17 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294705152;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"if(imm_extended == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV64*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi16sp_imm(
 		ISA16_RISCV64,
 		"c.addi16sp",
 		(uint16_t)0x6101,
 		(uint16_t) 0xef83,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_9 (12,12);
 		etiss_int64 imm_9 = R_imm_9.read(ba);
 		imm += imm_9<<9;
 		static BitArrayRange R_imm_4 (6,6);
 		etiss_int64 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_6 (5,5);
 		etiss_int64 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_7 (4,3);
 		etiss_int64 imm_7 = R_imm_7.read(ba);
 		imm += imm_7<<7;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
  		partInit.getAffectedRegisters().add(reg_name[2],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.addi16sp\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x200)>>9 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294966272;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[2]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[2] = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[2] = %#lx\\n\",*((RISCV64*)cpu)->X[2]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_ld_8_rd_uimm_8_rs1_(
 		ISA16_RISCV64,
 		"c.ld",
 		(uint16_t)0x6000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (6,5);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.ld\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"etiss_int64 cast_0 = MEM_offs; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_ldsp_rd_uimm_sp_(
 		ISA16_RISCV64,
 		"c.ldsp",
 		(uint16_t)0x6002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_5 (12,12);
 		etiss_uint64 uimm_5 = R_uimm_5.read(ba);
 		uimm += uimm_5<<5;
 		static BitArrayRange R_uimm_3 (6,5);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (4,2);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.ldsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint64 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
	"etiss_int64 cast_0 = MEM_offs; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"*((RISCV64*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_srli_8_rs1_shamt(
 		ISA16_RISCV64,
 		"c.srli",
 		(uint16_t)0x8001,
 		(uint16_t) 0xec03,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_5 (12,12);
 		etiss_uint64 shamt_5 = R_shamt_5.read(ba);
 		shamt += shamt_5<<5;
 		static BitArrayRange R_shamt_0 (6,2);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rs1+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.srli\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rs1_idx = 0;\n"
 			
"rs1_idx = " + toString(rs1) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
#endif	
"*((RISCV64*)cpu)->X[rs1_idx] = (*((RISCV64*)cpu)->X[rs1_idx] >> " + toString(shamt) + ");\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rs1_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rs1_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_srai_8_rs1_shamt(
 		ISA16_RISCV64,
 		"c.srai",
 		(uint16_t)0x8401,
 		(uint16_t) 0xec03,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 shamt = 0;
 		static BitArrayRange R_shamt_5 (12,12);
 		etiss_uint64 shamt_5 = R_shamt_5.read(ba);
 		shamt += shamt_5<<5;
 		static BitArrayRange R_shamt_0 (6,2);
 		etiss_uint64 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rs1+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.srai\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rs1_idx = 0;\n"
 			
"rs1_idx = " + toString(rs1) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[rs1_idx]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[rs1_idx] = ((etiss_int64)cast_0 >> " + toString(shamt) + ");\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rs1_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rs1_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_andi_8_rs1_imm(
 		ISA16_RISCV64,
 		"c.andi",
 		(uint16_t)0x8801,
 		(uint16_t) 0xec03,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int64 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rs1+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.andi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int8 rs1_idx = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294967232;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"rs1_idx = " + toString(rs1) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
#endif	
"etiss_int64 cast_0 = *((RISCV64*)cpu)->X[rs1_idx]; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[rs1_idx] = ((etiss_int64)cast_0 & imm_extended);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rs1_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rs1_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sub_8_rd_8_rs2(
 		ISA16_RISCV64,
 		"c.sub",
 		(uint16_t)0x8c01,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.sub\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV64*)cpu)->X[rd_idx] = *((RISCV64*)cpu)->X[rd_idx] - *((RISCV64*)cpu)->X[" + toString(rs2) + " + 8];\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rd_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_xor_8_rd_8_rs2(
 		ISA16_RISCV64,
 		"c.xor",
 		(uint16_t)0x8c21,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.xor\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV64*)cpu)->X[rd_idx] = (*((RISCV64*)cpu)->X[rd_idx] ^ *((RISCV64*)cpu)->X[" + toString(rs2) + " + 8]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rd_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_or_8_rd_8_rs2(
 		ISA16_RISCV64,
 		"c.or",
 		(uint16_t)0x8c41,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.or\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV64*)cpu)->X[rd_idx] = (*((RISCV64*)cpu)->X[rd_idx] | *((RISCV64*)cpu)->X[" + toString(rs2) + " + 8]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rd_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_and_8_rd_8_rs2(
 		ISA16_RISCV64,
 		"c.and",
 		(uint16_t)0x8c61,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.and\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV64_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV64*)cpu)->X[rd_idx] = (*((RISCV64*)cpu)->X[rd_idx] & *((RISCV64*)cpu)->X[" + toString(rs2) + " + 8]);\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[rd_idx] = %#lx\\n\",*((RISCV64*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_mv_rd_rs2(
 		ISA16_RISCV64,
 		"c.mv",
 		(uint16_t)0x8002,
 		(uint16_t) 0xf003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.mv\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_jr_rs1(
 		ISA16_RISCV64,
 		"c.jr",
 		(uint16_t)0x8002,
 		(uint16_t) 0xf07f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.jr\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"cpu->instructionPointer = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_add_rd_rs2(
 		ISA16_RISCV64,
 		"c.add",
 		(uint16_t)0x9002,
 		(uint16_t) 0xf003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[rd],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.add\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV64*)cpu)->X[" + toString(rd) + "] = *((RISCV64*)cpu)->X[" + toString(rd) + "] + *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_jalr_rs1(
 		ISA16_RISCV64,
 		"c.jalr",
 		(uint16_t)0x9002,
 		(uint16_t) 0xf07f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[1],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.jalr\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV64*)cpu)->X[1] = " +toString((uint64_t)ic.current_address_)+"ULL  + 2;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[1] = %#lx\\n\",*((RISCV64*)cpu)->X[1]); \n"
#endif	
"cpu->instructionPointer = *((RISCV64*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_ebreak_(
 		ISA16_RISCV64,
 		"c.ebreak",
 		(uint16_t)0x9002,
 		(uint16_t) 0xffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.ebreak\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"return ETISS_RETURNCODE_CPUFINISHED; \n"
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_subw_8_rd_8_rd_8_rs2(
 		ISA16_RISCV64,
 		"c.subw",
 		(uint16_t)0x9c01,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.subw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
"res = (*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] & 0xffffffff) - (*((RISCV64*)cpu)->X[" + toString(rs2) + " + 8] & 0xffffffff);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"etiss_int32 cast_0 = res; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addw_8_rd_8_rd_8_rs2(
 		ISA16_RISCV64,
 		"c.addw",
 		(uint16_t)0x9c21,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.addw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
"res = (*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] & 0xffffffff) + (*((RISCV64*)cpu)->X[" + toString(rs2) + " + 8] & 0xffffffff);\n"
#if RISCV64_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"etiss_int32 cast_0 = res; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
#if RISCV64_DEBUG_CALL
"printf(\"*((RISCV64*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RISCV64*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_j_imm(
 		ISA16_RISCV64,
 		"c.j",
 		(uint16_t)0xa001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_11 (12,12);
 		etiss_int64 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		static BitArrayRange R_imm_4 (11,11);
 		etiss_int64 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_8 (10,9);
 		etiss_int64 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_10 (8,8);
 		etiss_int64 imm_10 = R_imm_10.read(ba);
 		imm += imm_10<<10;
 		static BitArrayRange R_imm_6 (7,7);
 		etiss_int64 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_7 (6,6);
 		etiss_int64 imm_7 = R_imm_7.read(ba);
 		imm += imm_7<<7;
 		static BitArrayRange R_imm_1 (5,3);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.j\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294963200;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"cpu->instructionPointer = (etiss_int64)cast_0 + imm_extended;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fsd_rs2_uimm_8_rs1_(
 		ISA16_RISCV64,
 		"c.fsd",
 		(uint16_t)0xa000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (6,5);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.fsd\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV64*)cpu)->F[" + toString(rs2) + " + 8] & 0xffffffffffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fsdsp_rs2_uimm_x2_(
 		ISA16_RISCV64,
 		"c.fsdsp",
 		(uint16_t)0xa002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (9,7);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.fsdsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV64*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_bnez_8_rs1_imm(
 		ISA16_RISCV64,
 		"c.bnez",
 		(uint16_t)0xe001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int64 imm = 0;
 		static BitArrayRange R_imm_8 (12,12);
 		etiss_int64 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_3 (11,10);
 		etiss_int64 imm_3 = R_imm_3.read(ba);
 		imm += imm_3<<3;
 		static BitArrayRange R_imm_6 (6,5);
 		etiss_int64 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_1 (4,3);
 		etiss_int64 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int64 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.bnez\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x100)>>8 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967295;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
	"imm_extended = (imm_extended << 32);\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
	"imm_extended = imm_extended + 4294966784;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
#endif	
"if(*((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] != 0)\n"
"{\n"
	"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 2;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"choose1 = %#lx\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV64_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sd_8_rs2_uimm_8_rs1_(
 		ISA16_RISCV64,
 		"c.sd",
 		(uint16_t)0xe000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (6,5);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],64);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.sd\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + " + 8];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sdsp_rs2_uimm_sp_(
 		ISA16_RISCV64,
 		"c.sdsp",
 		(uint16_t)0xe002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint64 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint64 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint64 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (9,7);
 		etiss_uint64 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],64);
 		partInit.getRegisterDependencies().add(reg_name[2],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//c.sdsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV64_Pipeline1
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV64_Pipeline2
			"etiss_uint32 resource_time [100] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
"offs = *((RISCV64*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV64_DEBUG_CALL
"printf(\"offs = %#lx\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV64*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV64_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV64*)cpu)->RES) && (offs < 8 + ((RISCV64*)cpu)->RES))\n"
"{\n"
	"((RISCV64*)cpu)->RES = 0;\n"
	#if RISCV64_DEBUG_CALL
	"printf(\"((RISCV64*)cpu)->RES = %#lx\\n\",((RISCV64*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------


