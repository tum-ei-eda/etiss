// This file was generated on Mon Aug 03 15:02:38 CEST 2020
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
	 	are provided in RISCVArchSpecificImp.h 
 
	 8. RISCVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.
 
 *********************************************************************************************************************************/

#include "RISCVArch.h"
#include "RISCVArchSpecificImp.h"

#define RISCV_DEBUG_CALL 0
#define RISCV_Pipeline1 0
#define RISCV_Pipeline2 0
using namespace etiss ;
using namespace etiss::instr ;

RISCVArch::RISCVArch():CPUArch("RISCV") 
{
	headers_.insert("Arch/RISCV/RISCV.h");
}

const std::set<std::string> & RISCVArch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

ETISS_CPU * RISCVArch::newCPU()
{
    ETISS_CPU * ret = (ETISS_CPU *) new RISCV() ;
    resetCPU (ret, 0);
    return ret;
}

void RISCVArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
    memset (cpu, 0, sizeof(RISCV));
    RISCV * riscvcpu = (RISCV *) cpu;

    if (startpointer) cpu->instructionPointer = *startpointer;
    else cpu->instructionPointer = 0x0;   //  reference to manual
    cpu->mode = 1;
    cpu->cpuTime_ps = 0;
    cpu->cpuCycleTime_ps = 31250;
    #if RISCV_Pipeline1 || RISCV_Pipeline2
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
		riscvcpu->ins_X[i] = 0;
		riscvcpu->X[i] = & riscvcpu->ins_X[i];
	}
	
    // Initialize the registers and state flags;
	riscvcpu->ZERO = 0;
	riscvcpu->X[0] = & (riscvcpu->ZERO);
	riscvcpu->RA = 0;
	riscvcpu->X[1] = & (riscvcpu->RA);
	riscvcpu->SP = 0;
	riscvcpu->X[2] = & (riscvcpu->SP);
	riscvcpu->GP = 0;
	riscvcpu->X[3] = & (riscvcpu->GP);
	riscvcpu->TP = 0;
	riscvcpu->X[4] = & (riscvcpu->TP);
	riscvcpu->T0 = 0;
	riscvcpu->X[5] = & (riscvcpu->T0);
	riscvcpu->T1 = 0;
	riscvcpu->X[6] = & (riscvcpu->T1);
	riscvcpu->T2 = 0;
	riscvcpu->X[7] = & (riscvcpu->T2);
	riscvcpu->S0 = 0;
	riscvcpu->X[8] = & (riscvcpu->S0);
	riscvcpu->S1 = 0;
	riscvcpu->X[9] = & (riscvcpu->S1);
	riscvcpu->A0 = 0;
	riscvcpu->X[10] = & (riscvcpu->A0);
	riscvcpu->A1 = 0;
	riscvcpu->X[11] = & (riscvcpu->A1);
	riscvcpu->A2 = 0;
	riscvcpu->X[12] = & (riscvcpu->A2);
	riscvcpu->A3 = 0;
	riscvcpu->X[13] = & (riscvcpu->A3);
	riscvcpu->A4 = 0;
	riscvcpu->X[14] = & (riscvcpu->A4);
	riscvcpu->A5 = 0;
	riscvcpu->X[15] = & (riscvcpu->A5);
	riscvcpu->A6 = 0;
	riscvcpu->X[16] = & (riscvcpu->A6);
	riscvcpu->A7 = 0;
	riscvcpu->X[17] = & (riscvcpu->A7);
	riscvcpu->S2 = 0;
	riscvcpu->X[18] = & (riscvcpu->S2);
	riscvcpu->S3 = 0;
	riscvcpu->X[19] = & (riscvcpu->S3);
	riscvcpu->S4 = 0;
	riscvcpu->X[20] = & (riscvcpu->S4);
	riscvcpu->S5 = 0;
	riscvcpu->X[21] = & (riscvcpu->S5);
	riscvcpu->S6 = 0;
	riscvcpu->X[22] = & (riscvcpu->S6);
	riscvcpu->S7 = 0;
	riscvcpu->X[23] = & (riscvcpu->S7);
	riscvcpu->S8 = 0;
	riscvcpu->X[24] = & (riscvcpu->S8);
	riscvcpu->S9 = 0;
	riscvcpu->X[25] = & (riscvcpu->S9);
	riscvcpu->S10 = 0;
	riscvcpu->X[26] = & (riscvcpu->S10);
	riscvcpu->S11 = 0;
	riscvcpu->X[27] = & (riscvcpu->S11);
	riscvcpu->T3 = 0;
	riscvcpu->X[28] = & (riscvcpu->T3);
	riscvcpu->T4 = 0;
	riscvcpu->X[29] = & (riscvcpu->T4);
	riscvcpu->T5 = 0;
	riscvcpu->X[30] = & (riscvcpu->T5);
	riscvcpu->T6 = 0;
	riscvcpu->X[31] = & (riscvcpu->T6);
	for (int i = 0; i<32 ;i++){
		riscvcpu->F[i] = 0;
	}
	riscvcpu->FCSR = 0;
	for (int i = 0; i<4096 ;i++){
		riscvcpu->CSR[i] = 0;
	}
	riscvcpu->CSR[0] = 15;								
	riscvcpu->CSR[256] = 15;								
	riscvcpu->CSR[768] = 15;								
	riscvcpu->CSR[260] = 4294967295;								
	riscvcpu->CSR[769] = 1315077;								
	riscvcpu->CSR[3088] = 3;								
	for (int i = 0; i<4 ;i++){
		riscvcpu->FENCE[i] = 0;
	}
	riscvcpu->RES = 0;

	/* >>> manually added code section */
	riscvcpu->CSR[0x304] = (0xFFFFFBBB);
		// MIE: enable all core-local and add. platform-specific interrupts
	riscvcpu->CSR[0x104] = riscvcpu->CSR[0x304] & (~(0x888));
		// SIE: enable all core-local and add. platform-specific interrupts (supervised)
	riscvcpu->CSR[0x004] = riscvcpu->CSR[0x304] & (~(0xAAA));
		// UIE: enable all core-local and add. platform-specific interrupts (user)
	/* <<< manually added code section */
}

void RISCVArch::deleteCPU(ETISS_CPU *cpu)
{
    delete (RISCV *) cpu ;
}


/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RISCVArch::getMaximumInstructionSizeInBytes()
{
    return 8;
}
/**
	@return 2
*/
unsigned RISCVArch::getInstructionSizeInBytes()
{
    return 2;
}
/**
	@brief required headers (RISCV.h)
*/
const std::set<std::string> & RISCVArch::getHeaders() const
{
    return headers_ ;
}
		
void RISCVArch::initCodeBlock(etiss::CodeBlock & cb) const
{
    cb.fileglobalCode().insert("#include \"Arch/RISCV/RISCV.h\"\n");
}

etiss::plugin::gdb::GDBCore & RISCVArch::getGDBCore()
{
	
	return gdbcore_;
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
 		ISA32_RISCV,
 		"lui",
 		(uint32_t)0x37,
 		(uint32_t) 0x7f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,12);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lui\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = " + toString(imm) + ";\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition auipc_rd_imm(
 		ISA32_RISCV,
 		"auipc",
 		(uint32_t)0x17,
 		(uint32_t) 0x7f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,12);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//auipc\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0 + " + toString(imm) + ";\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition jal_rd_imm(
 		ISA32_RISCV,
 		"jal",
 		(uint32_t)0x6f,
 		(uint32_t) 0x7f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_20 (31,31);
 		etiss_int32 imm_20 = R_imm_20.read(ba);
 		imm += imm_20<<20;
 		static BitArrayRange R_imm_1 (30,21);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (20,20);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		static BitArrayRange R_imm_12 (19,12);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//jal\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x100000)>>20 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4292870144;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"
"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"cpu->instructionPointer = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition jalr_rd_rs1_imm(
 		ISA32_RISCV,
 		"jalr",
 		(uint32_t)0x67,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//jalr\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 new_pc = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"new_pc = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"new_pc = %#x\\n\",new_pc); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"
"cpu->instructionPointer = (new_pc & ~1)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition beq_rs1_rs2_imm(
 		ISA32_RISCV,
 		"beq",
 		(uint32_t)0x63,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//beq\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294959104;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(*((RISCV*)cpu)->X[" + toString(rs1) + "] == *((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lb_rd_imm_rs1_(
 		ISA32_RISCV,
 		"lb",
 		(uint32_t)0x3,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lb\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
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
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sb_rs2_imm_rs1_(
 		ISA32_RISCV,
 		"sb",
 		(uint32_t)0x23,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sb\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint8 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,1);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 1 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition addi_rd_rs1_imm(
 		ISA32_RISCV,
 		"addi",
 		(uint32_t)0x13,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//addi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bne_rs1_rs2_imm(
 		ISA32_RISCV,
 		"bne",
 		(uint32_t)0x1063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//bne\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294959104;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(*((RISCV*)cpu)->X[" + toString(rs1) + "] != *((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lh_rd_imm_rs1_(
 		ISA32_RISCV,
 		"lh",
 		(uint32_t)0x1003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lh\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
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
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sh_rs2_imm_rs1_(
 		ISA32_RISCV,
 		"sh",
 		(uint32_t)0x1023,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sh\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint16 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,2);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 2 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fence_i_(
 		ISA32_RISCV,
 		"fence_i",
 		(uint32_t)0x100f,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_uint32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fence_i\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV*)cpu)->FENCE[1] = " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FENCE[1] = %#x\\n\",((RISCV*)cpu)->FENCE[1]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrw_rd_csr_rs1(
 		ISA32_RISCV,
 		"csrrw",
 		(uint32_t)0x1073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint32 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//csrrw\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 mAddr = 0;\n"
 			"etiss_int32 writeMask = 0;\n"
 			"etiss_int32 writeMaskU = 0;\n"
 			"etiss_int32 sAddr = 0;\n"
 			"etiss_int32 writeMaskS = 0;\n"
 			"etiss_int32 uAddr = 0;\n"
 			"etiss_uint32 rs_val = 0;\n"
 			"etiss_uint32 csr_val = 0;\n"
 			"etiss_int32 writeMaskM = 0;\n"
 			
"rs_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"rs_val = %#x\\n\",rs_val); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"csr_val = ((RISCV*)cpu)->CSR[" + toString(csr) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"csr_val = %#x\\n\",csr_val); \n"
	#endif	
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -2139096645;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -2146574029;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -2146574319;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | (rs_val & writeMask))&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV*)cpu)->CSR[" + toString(csr) + "] = rs_val;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = csr_val;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -2139096645;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -2146574029;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -2146574319;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | (rs_val & writeMask))&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV*)cpu)->CSR[" + toString(csr) + "] = rs_val;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
	"}\n"
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition blt_rs1_rs2_imm(
 		ISA32_RISCV,
 		"blt",
 		(uint32_t)0x4063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//blt\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294959104;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
"}\n"
"if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
"{\n"
	"etiss_int32 cast_2 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_2 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint32)cast_2 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_2 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lbu_rd_imm_rs1_(
 		ISA32_RISCV,
 		"lbu",
 		(uint32_t)0x4003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lbu\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint8 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,1);\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)MEM_offs;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition xori_rd_rs1_imm(
 		ISA32_RISCV,
 		"xori",
 		(uint32_t)0x4013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//xori\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_0 ^ imm_extended);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bge_rs1_rs2_imm(
 		ISA32_RISCV,
 		"bge",
 		(uint32_t)0x5063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//bge\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294959104;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
"}\n"
"if((etiss_int32)cast_1 >= (etiss_int32)cast_0)\n"
"{\n"
	"etiss_int32 cast_2 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_2 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint32)cast_2 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_2 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lhu_rd_imm_rs1_(
 		ISA32_RISCV,
 		"lhu",
 		(uint32_t)0x5003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lhu\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_uint16 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,2);\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)MEM_offs;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrwi_rd_csr_zimm(
 		ISA32_RISCV,
 		"csrrwi",
 		(uint32_t)0x5073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint32 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		etiss_uint32 zimm = 0;
 		static BitArrayRange R_zimm_0 (19,15);
 		etiss_uint32 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//csrrwi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 mAddr = 0;\n"
 			"etiss_int32 writeMask = 0;\n"
 			"etiss_int32 writeMaskU = 0;\n"
 			"etiss_int32 sAddr = 0;\n"
 			"etiss_int32 writeMaskS = 0;\n"
 			"etiss_int32 uAddr = 0;\n"
 			"etiss_int32 writeMaskM = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((RISCV*)cpu)->CSR[" + toString(csr) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
"{\n"
	"uAddr = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"uAddr = %#x\\n\",uAddr); \n"
	#endif	
	"sAddr = 256;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"sAddr = %#x\\n\",sAddr); \n"
	#endif	
	"mAddr = 768;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"mAddr = %#x\\n\",mAddr); \n"
	#endif	
	"writeMaskM = -2139096645;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
	#endif	
	"writeMaskS = -2146574029;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
	#endif	
	"writeMaskU = -2146574319;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
	#endif	
"}\n"

"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
"{\n"
	"uAddr = 68;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"uAddr = %#x\\n\",uAddr); \n"
	#endif	
	"sAddr = 324;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"sAddr = %#x\\n\",sAddr); \n"
	#endif	
	"mAddr = 836;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"mAddr = %#x\\n\",mAddr); \n"
	#endif	
	"writeMaskM = 3003;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
	#endif	
	"writeMaskS = 819;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
	#endif	
	"writeMaskU = 273;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
	#endif	
"}\n"

"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
"{\n"
	"uAddr = 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"uAddr = %#x\\n\",uAddr); \n"
	#endif	
	"sAddr = 260;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"sAddr = %#x\\n\",sAddr); \n"
	#endif	
	"mAddr = 772;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"mAddr = %#x\\n\",mAddr); \n"
	#endif	
	"writeMaskM = 3003;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
	#endif	
	"writeMaskS = 819;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
	#endif	
	"writeMaskU = 273;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
	#endif	
"}\n"

"if(uAddr != sAddr)\n"
"{\n"
	"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
	"{\n"
		"writeMask = writeMaskM;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMask = %#x\\n\",writeMask); \n"
		#endif	
	"}\n"
	
	"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
	"{\n"
		"writeMask = writeMaskS;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMask = %#x\\n\",writeMask); \n"
		#endif	
	"}\n"
	
	"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
	"{\n"
		"writeMask = writeMaskU;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMask = %#x\\n\",writeMask); \n"
		#endif	
	"}\n"
	
	"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | ((etiss_uint32)" + toString(zimm) + " & writeMask))&0xffffffff;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
	#endif	
	"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
	#endif	
	"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"((RISCV*)cpu)->CSR[" + toString(csr) + "] = (etiss_uint32)" + toString(zimm) + ";\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bltu_rs1_rs2_imm(
 		ISA32_RISCV,
 		"bltu",
 		(uint32_t)0x6063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//bltu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294959104;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(*((RISCV*)cpu)->X[" + toString(rs1) + "] < *((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ori_rd_rs1_imm(
 		ISA32_RISCV,
 		"ori",
 		(uint32_t)0x6013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//ori\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_0 | imm_extended);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrsi_rd_csr_zimm(
 		ISA32_RISCV,
 		"csrrsi",
 		(uint32_t)0x6073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint32 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		etiss_uint32 zimm = 0;
 		static BitArrayRange R_zimm_0 (19,15);
 		etiss_uint32 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//csrrsi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int32 mAddr = 0;\n"
 			"etiss_int32 writeMask = 0;\n"
 			"etiss_int32 writeMaskU = 0;\n"
 			"etiss_int32 sAddr = 0;\n"
 			"etiss_int32 writeMaskS = 0;\n"
 			"etiss_int32 uAddr = 0;\n"
 			"etiss_int32 writeMaskM = 0;\n"
 			
"res = ((RISCV*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(" + toString(zimm) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -2139096645;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -2146574029;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -2146574319;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | ((res | (etiss_uint32)" + toString(zimm) + ") & writeMask))&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV*)cpu)->CSR[" + toString(csr) + "] = (res | (etiss_uint32)" + toString(zimm) + ");\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
	"}\n"
"}\n"

"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition bgeu_rs1_rs2_imm(
 		ISA32_RISCV,
 		"bgeu",
 		(uint32_t)0x7063,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_12 (31,31);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		static BitArrayRange R_imm_5 (30,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_1 (11,8);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_11 (7,7);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//bgeu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294959104;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(*((RISCV*)cpu)->X[" + toString(rs1) + "] >= *((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition andi_rd_rs1_imm(
 		ISA32_RISCV,
 		"andi",
 		(uint32_t)0x7013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//andi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_0 & imm_extended);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrci_rd_csr_zimm(
 		ISA32_RISCV,
 		"csrrci",
 		(uint32_t)0x7073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint32 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		etiss_uint32 zimm = 0;
 		static BitArrayRange R_zimm_0 (19,15);
 		etiss_uint32 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//csrrci\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int32 mAddr = 0;\n"
 			"etiss_int32 writeMask = 0;\n"
 			"etiss_int32 writeMaskU = 0;\n"
 			"etiss_int32 sAddr = 0;\n"
 			"etiss_int32 writeMaskS = 0;\n"
 			"etiss_int32 uAddr = 0;\n"
 			"etiss_int32 writeMaskM = 0;\n"
 			
"res = ((RISCV*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(" + toString(zimm) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -2139096645;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -2146574029;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -2146574319;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | ((res & ~(etiss_uint32)" + toString(zimm) + ") & writeMask))&0xffffffff&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV*)cpu)->CSR[" + toString(csr) + "] = (res & ~(etiss_uint32)" + toString(zimm) + ")&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lw_rd_imm_rs1_(
 		ISA32_RISCV,
 		"lw",
 		(uint32_t)0x2003,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
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
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sw_rs2_imm_rs1_(
 		ISA32_RISCV,
 		"sw",
 		(uint32_t)0x2023,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slti_rd_rs1_imm(
 		ISA32_RISCV,
 		"slti",
 		(uint32_t)0x2013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//slti\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = imm_extended; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrs_rd_csr_rs1(
 		ISA32_RISCV,
 		"csrrs",
 		(uint32_t)0x2073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint32 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//csrrs\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 xrs1 = 0;\n"
 			"etiss_int32 mAddr = 0;\n"
 			"etiss_int32 writeMask = 0;\n"
 			"etiss_int32 writeMaskU = 0;\n"
 			"etiss_int32 sAddr = 0;\n"
 			"etiss_int32 writeMaskS = 0;\n"
 			"etiss_int32 uAddr = 0;\n"
 			"etiss_uint32 xrd = 0;\n"
 			"etiss_int32 writeMaskM = 0;\n"
 			
"xrd = ((RISCV*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"xrd = %#x\\n\",xrd); \n"
#endif	
"xrs1 = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"xrs1 = %#x\\n\",xrs1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = xrd;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(" + toString(rs1) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -2139096645;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -2146574029;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -2146574319;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | ((xrd | xrs1) & writeMask))&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV*)cpu)->CSR[" + toString(csr) + "] = (xrd | xrs1);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition flw_rd_imm_xrs1_(
 		ISA32_RISCV,
 		"flw",
 		(uint32_t)0x2007,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//flw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"res = MEM_offs;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsw_rs2_imm_xrs1_(
 		ISA32_RISCV,
 		"fsw",
 		(uint32_t)0x2027,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sltiu_rd_rs1_imm(
 		ISA32_RISCV,
 		"sltiu",
 		(uint32_t)0x3013,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sltiu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 full_imm = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = imm_extended; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"full_imm = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"full_imm = %#x\\n\",full_imm); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if((etiss_uint32)*((RISCV*)cpu)->X[" + toString(rs1) + "] < (etiss_uint32)full_imm)\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition csrrc_rd_csr_rs1(
 		ISA32_RISCV,
 		"csrrc",
 		(uint32_t)0x3073,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 csr = 0;
 		static BitArrayRange R_csr_0 (31,20);
 		etiss_uint32 csr_0 = R_csr_0.read(ba);
 		csr += csr_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//csrrc\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 xrs1 = 0;\n"
 			"etiss_int32 mAddr = 0;\n"
 			"etiss_int32 writeMask = 0;\n"
 			"etiss_int32 writeMaskU = 0;\n"
 			"etiss_int32 sAddr = 0;\n"
 			"etiss_int32 writeMaskS = 0;\n"
 			"etiss_int32 uAddr = 0;\n"
 			"etiss_uint32 xrd = 0;\n"
 			"etiss_int32 writeMaskM = 0;\n"
 			
"xrd = ((RISCV*)cpu)->CSR[" + toString(csr) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"xrd = %#x\\n\",xrd); \n"
#endif	
"xrs1 = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"xrs1 = %#x\\n\",xrs1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = xrd;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(" + toString(rs1) + " != 0)\n"
"{\n"
	"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
	"{\n"
		"uAddr = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 256;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 768;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = -2139096645;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = -2146574029;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = -2146574319;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
	"{\n"
		"uAddr = 68;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 324;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 836;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
	"{\n"
		"uAddr = 4;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"uAddr = %#x\\n\",uAddr); \n"
		#endif	
		"sAddr = 260;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"sAddr = %#x\\n\",sAddr); \n"
		#endif	
		"mAddr = 772;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"mAddr = %#x\\n\",mAddr); \n"
		#endif	
		"writeMaskM = 3003;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskM = %#x\\n\",writeMaskM); \n"
		#endif	
		"writeMaskS = 819;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskS = %#x\\n\",writeMaskS); \n"
		#endif	
		"writeMaskU = 273;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"writeMaskU = %#x\\n\",writeMaskU); \n"
		#endif	
	"}\n"
	
	"if(uAddr != sAddr)\n"
	"{\n"
		"if(((RISCV*)cpu)->CSR[3088] == 3)\n"
		"{\n"
			"writeMask = writeMaskM;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 1)\n"
		"{\n"
			"writeMask = writeMaskS;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"if(((RISCV*)cpu)->CSR[3088] == 0)\n"
		"{\n"
			"writeMask = writeMaskU;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"writeMask = %#x\\n\",writeMask); \n"
			#endif	
		"}\n"
		
		"((RISCV*)cpu)->CSR[uAddr] = ((((RISCV*)cpu)->CSR[uAddr] & ~writeMask) | ((xrd & ~xrs1) & writeMask))&0xffffffff&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[uAddr] = %#x\\n\",((RISCV*)cpu)->CSR[uAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[sAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[sAddr] = %#x\\n\",((RISCV*)cpu)->CSR[sAddr]); \n"
		#endif	
		"((RISCV*)cpu)->CSR[mAddr] = ((RISCV*)cpu)->CSR[uAddr];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[mAddr] = %#x\\n\",((RISCV*)cpu)->CSR[mAddr]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"((RISCV*)cpu)->CSR[" + toString(csr) + "] = (xrd & ~xrs1)&0xffffffff;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"((RISCV*)cpu)->CSR[" + toString(csr) + "] = %#x\\n\",((RISCV*)cpu)->CSR[" + toString(csr) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fld_rd_imm_rs1_(
 		ISA32_RISCV,
 		"fld",
 		(uint32_t)0x3007,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_0 (31,20);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fld\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"res = MEM_offs;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsd_rs2_imm_rs1_(
 		ISA32_RISCV,
 		"fsd",
 		(uint32_t)0x3027,
 		(uint32_t) 0x707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (31,25);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (11,7);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsd\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 offs = 0;\n"
 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"offs = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmadd_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fmadd.s",
 		(uint32_t)0x43,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmadd.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], ((RISCV*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)0, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)0, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmsub_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fmsub.s",
 		(uint32_t)0x47,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmsub.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], ((RISCV*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)1, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)1, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmadd_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fnmadd.s",
 		(uint32_t)0x4f,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fnmadd.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], ((RISCV*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)2, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)2, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmsub_s_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fnmsub.s",
 		(uint32_t)0x4b,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fnmsub.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fmadd_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], ((RISCV*)cpu)->F[" + toString(rs3) + "], (etiss_uint32)3, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"frs3 = unbox_s(((RISCV*)cpu)->F[" + toString(rs3) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs3 = %#x\\n\",frs3); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmadd_s(frs1, frs2, frs3, (etiss_uint32)3, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmadd_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fmadd.d",
 		(uint32_t)0x2000043,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmadd.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint64)0, choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmsub_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fmsub.d",
 		(uint32_t)0x2000047,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmsub.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint32)1, choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmadd_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fnmadd.d",
 		(uint32_t)0x200004f,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fnmadd.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint32)2, choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fnmsub_d_rd_frs1_frs2_frs3(
 		ISA32_RISCV,
 		"fnmsub.d",
 		(uint32_t)0x200004b,
 		(uint32_t) 0x600007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rs3 = 0;
 		static BitArrayRange R_rs3_0 (31,27);
 		etiss_uint32 rs3_0 = R_rs3_0.read(ba);
 		rs3 += rs3_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fnmsub.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmadd_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs3) + "] & 0xffffffffffffffff), (etiss_uint32)3, choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slli_rd_rs1_shamt(
 		ISA32_RISCV,
 		"slli",
 		(uint32_t)0x1013,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 shamt = 0;
 		static BitArrayRange R_shamt_0 (24,20);
 		etiss_uint32 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//slli\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 X = 0; \n"
 			"for ( int i = 0; i< 32 ; i++)\n"
 			"{\n"
 				"X ^= ((-*((RISCV*)cpu)->X[i])^X) & (1 << i ); \n"
 			"}\n"
 			
"if(" + toString(shamt) + " > 31)\n"
"{\n"
	"exception = ETISS_RETURNCODE_IBUS_READ_ERROR; \n"
"}\n"

"else\n"
"{\n"
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] << " + toString(shamt) + ");\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sll_rd_rs1_rs2(
 		ISA32_RISCV,
 		"sll",
 		(uint32_t)0x1033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sll\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {4, 5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {4, 5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 X = 0; \n"
 			"for ( int i = 0; i< 32 ; i++)\n"
 			"{\n"
 				"X ^= ((-*((RISCV*)cpu)->X[i])^X) & (1 << i ); \n"
 			"}\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] << (*((RISCV*)cpu)->X[" + toString(rs2) + "] & 32 - 1));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srli_rd_rs1_shamt(
 		ISA32_RISCV,
 		"srli",
 		(uint32_t)0x5013,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 shamt = 0;
 		static BitArrayRange R_shamt_0 (24,20);
 		etiss_uint32 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//srli\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 X = 0; \n"
 			"for ( int i = 0; i< 32 ; i++)\n"
 			"{\n"
 				"X ^= ((-*((RISCV*)cpu)->X[i])^X) & (1 << i ); \n"
 			"}\n"
 			
"if(" + toString(shamt) + " > 31)\n"
"{\n"
	"exception = ETISS_RETURNCODE_IBUS_READ_ERROR; \n"
"}\n"

"else\n"
"{\n"
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] >> " + toString(shamt) + ");\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srl_rd_rs1_rs2(
 		ISA32_RISCV,
 		"srl",
 		(uint32_t)0x5033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//srl\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 X = 0; \n"
 			"for ( int i = 0; i< 32 ; i++)\n"
 			"{\n"
 				"X ^= ((-*((RISCV*)cpu)->X[i])^X) & (1 << i ); \n"
 			"}\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] >> (*((RISCV*)cpu)->X[" + toString(rs2) + "] & 32 - 1));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition add_rd_rs1_rs2(
 		ISA32_RISCV,
 		"add",
 		(uint32_t)0x33,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//add\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = *((RISCV*)cpu)->X[" + toString(rs1) + "] + *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition slt_rd_rs1_rs2(
 		ISA32_RISCV,
 		"slt",
 		(uint32_t)0x2033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//slt\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 choose1 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"if((etiss_int32)cast_1 < (etiss_int32)cast_0)\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sltu_rd_rs1_rs2(
 		ISA32_RISCV,
 		"sltu",
 		(uint32_t)0x3033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sltu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 choose1 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if((etiss_uint32)*((RISCV*)cpu)->X[" + toString(rs1) + "] < (etiss_uint32)*((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
	"{\n"
		"choose1 = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition xor_rd_rs1_rs2(
 		ISA32_RISCV,
 		"xor",
 		(uint32_t)0x4033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//xor\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] ^ *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition or_rd_rs1_rs2(
 		ISA32_RISCV,
 		"or",
 		(uint32_t)0x6033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//or\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] | *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition and_rd_rs1_rs2(
 		ISA32_RISCV,
 		"and",
 		(uint32_t)0x7033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//and\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] & *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition uret_(
 		ISA32_RISCV,
 		"uret",
 		(uint32_t)0x200073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//uret\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV*)cpu)->CSR[3088] = 0;\n"//PRIVLV=0
"((RISCV*)cpu)->CSR[0] ^= ((etiss_uint32)((((RISCV*)cpu)->CSR[0] & 0x10)>>4)) ^ (((RISCV*)cpu)->CSR[0] & 0x1);\n"//UIE=UPIE
"cpu->instructionPointer = ((RISCV*)cpu)->CSR[65];\n"//PC=UEPC
"((RISCV*)cpu)->CSR[768]= ((RISCV*)cpu)->CSR[0];\n"//keep MSTATUS synchronous to USTATUS
"((RISCV*)cpu)->CSR[256]=((RISCV*)cpu)->CSR[0];\n"//keep SSTATUS synchronous to USTATUS
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fadd_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fadd.s",
 		(uint32_t)0x53,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fadd.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fadd_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fadd_s(frs1, frs2, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition srai_rd_rs1_shamt(
 		ISA32_RISCV,
 		"srai",
 		(uint32_t)0x40005013,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 shamt = 0;
 		static BitArrayRange R_shamt_0 (24,20);
 		etiss_uint32 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//srai\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(shamt) + " > 31)\n"
"{\n"
	"exception = ETISS_RETURNCODE_IBUS_READ_ERROR; \n"
"}\n"

"else\n"
"{\n"
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
		"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
		"{\n"
			"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
		"}\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_0 >> " + toString(shamt) + ");\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sra_rd_rs1_rs2(
 		ISA32_RISCV,
 		"sra",
 		(uint32_t)0x40005033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sra\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_0 >> (*((RISCV*)cpu)->X[" + toString(rs2) + "] & 32 - 1));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sub_rd_rs1_rs2(
 		ISA32_RISCV,
 		"sub",
 		(uint32_t)0x40000033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sub\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = *((RISCV*)cpu)->X[" + toString(rs1) + "] - *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_d_rd_frs1(
 		ISA32_RISCV,
 		"fcvt.s.d",
 		(uint32_t)0x40100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.s.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fconv_d2f(((RISCV*)cpu)->F[" + toString(rs1) + "], (" + toString(rm) + " & 0xff));\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"upper =  - 1;\n"
#if RISCV_DEBUG_CALL
"printf(\"upper = %#lx\\n\",upper); \n"
#endif	
"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fence_(
 		ISA32_RISCV,
 		"fence",
 		(uint32_t)0xf,
 		(uint32_t) 0xf000707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 succ = 0;
 		static BitArrayRange R_succ_0 (23,20);
 		etiss_uint32 succ_0 = R_succ_0.read(ba);
 		succ += succ_0;
 		etiss_uint32 pred = 0;
 		static BitArrayRange R_pred_0 (27,24);
 		etiss_uint32 pred_0 = R_pred_0.read(ba);
 		pred += pred_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[0],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fence\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV*)cpu)->FENCE[0] = ((" + toString(pred) + " << 4) | " + toString(succ) + ");\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FENCE[0] = %#x\\n\",((RISCV*)cpu)->FENCE[0]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ecall_(
 		ISA32_RISCV,
 		"ecall",
 		(uint32_t)0x73,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//ecall\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"exception = ETISS_RETURNCODE_SYSCALL; \n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition ebreak_(
 		ISA32_RISCV,
 		"ebreak",
 		(uint32_t)0x100073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//ebreak\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"return ETISS_RETURNCODE_CPUFINISHED; \n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sret_(
 		ISA32_RISCV,
 		"sret",
 		(uint32_t)0x10200073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sret\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV*)cpu)->CSR[3088] = (((RISCV*)cpu)->CSR[256] & 0x100)>>8;\n"//PRIVLV=SPP
"((RISCV*)cpu)->CSR[256] ^= (((RISCV*)cpu)->CSR[256] & 0x100);\n"//SPP=0
"((RISCV*)cpu)->CSR[256] ^= ((etiss_uint32)((((RISCV*)cpu)->CSR[256] & 0x20)>>4)) ^ (((RISCV*)cpu)->CSR[256] & 0x2);\n"//SIE=SPIE
"cpu->instructionPointer = ((RISCV*)cpu)->CSR[321];\n"//PC=SEPC
"((RISCV*)cpu)->CSR[768]= ((RISCV*)cpu)->CSR[256];\n"//keep MSTATUS synchronous to SSTATUS
"((RISCV*)cpu)->CSR[0]=((RISCV*)cpu)->CSR[256];\n"//keep USTATUS synchronous to SSTATUS
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition wfi_(
 		ISA32_RISCV,
 		"wfi",
 		(uint32_t)0x10500073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//wfi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"return ETISS_RETURNCODE_CPUFINISHED; \n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmul_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fmul.s",
 		(uint32_t)0x10000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmul.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fmul_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fmul_s(frs1, frs2, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mret_(
 		ISA32_RISCV,
 		"mret",
 		(uint32_t)0x30200073,
 		(uint32_t) 0xffffffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//mret\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV*)cpu)->CSR[3088] = (((RISCV*)cpu)->CSR[768] & 0x1800)>>11;\n"//PRIVLV=MPP
"((RISCV*)cpu)->CSR[768] ^= (((RISCV*)cpu)->CSR[768] & 0x1800);\n"//MPP=0
"((RISCV*)cpu)->CSR[768] ^= ((etiss_uint32)((((RISCV*)cpu)->CSR[768] & 0x80)>>4)) ^ (((RISCV*)cpu)->CSR[768] & 0x8);\n"//MIE=MPIE
"cpu->instructionPointer = ((RISCV*)cpu)->CSR[833];\n"//PC=MEPC
"((RISCV*)cpu)->CSR[0]= ((RISCV*)cpu)->CSR[768];\n"//keep USTATUS synchronous to MSTATUS
"((RISCV*)cpu)->CSR[256]=((RISCV*)cpu)->CSR[768];\n"//keep SSTATUS synchronous to MSTATUS
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sfence_vma_(
 		ISA32_RISCV,
 		"sfence.vma",
 		(uint32_t)0x12000073,
 		(uint32_t) 0xfe007fff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[2],32);
  		partInit.getAffectedRegisters().add(reg_name[3],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sfence.vma\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"((RISCV*)cpu)->FENCE[2] = " + toString(rs1) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FENCE[2] = %#x\\n\",((RISCV*)cpu)->FENCE[2]); \n"
#endif	
"((RISCV*)cpu)->FENCE[3] = " + toString(rs2) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FENCE[3] = %#x\\n\",((RISCV*)cpu)->FENCE[3]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmul_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fmul.d",
 		(uint32_t)0x12000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmul.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fmul_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2(
 		ISA32_RISCV,
 		"mul",
 		(uint32_t)0x2000033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//mul\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {3}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {8}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"res = ((etiss_uint64)*((RISCV*)cpu)->X[" + toString(rs1) + "] * (etiss_uint64)*((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulh_rd_rs1_rs2(
 		ISA32_RISCV,
 		"mulh",
 		(uint32_t)0x2001033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//mulh\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"res = ((etiss_int64)cast_1 * (etiss_int64)cast_0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)(res >> 32);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulhsu_rd_rs1_rs2(
 		ISA32_RISCV,
 		"mulhsu",
 		(uint32_t)0x2002033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//mulhsu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"res = ((etiss_int64)cast_0 * (etiss_uint64)*((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)(res >> 32);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition mulhu_rd_rs1_rs2(
 		ISA32_RISCV,
 		"mulhu",
 		(uint32_t)0x2003033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//mulhu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"res = ((etiss_uint64)*((RISCV*)cpu)->X[" + toString(rs1) + "] * (etiss_uint64)*((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#lx\\n\",res); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)(res >> 32);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition div_rd_rs1_rs2(
 		ISA32_RISCV,
 		"div",
 		(uint32_t)0x2004033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//div\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 XLM1 = 0;\n"
 			"etiss_int32 MMIN = 0;\n"
 			"etiss_int32 M1 = 0;\n"
 			"etiss_int32 ONE = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"M1 =  - 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"M1 = %#x\\n\",M1); \n"
		#endif	
		"XLM1 = 32 - 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"XLM1 = %#x\\n\",XLM1); \n"
		#endif	
		"ONE = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"ONE = %#x\\n\",ONE); \n"
		#endif	
		"MMIN = (ONE << XLM1);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"MMIN = %#x\\n\",MMIN); \n"
		#endif	
		"if((*((RISCV*)cpu)->X[" + toString(rs1) + "] == MMIN) && (*((RISCV*)cpu)->X[" + toString(rs2) + "] == M1))\n"
		"{\n"
			"*((RISCV*)cpu)->X[" + toString(rd) + "] = MMIN;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
		
		"else\n"
		"{\n"
			"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
			"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
			"}\n"
			"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
			"}\n"
			"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_1 / (etiss_int32)cast_0);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition divu_rd_rs1_rs2(
 		ISA32_RISCV,
 		"divu",
 		(uint32_t)0x2005033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//divu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] / *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition rem_rd_rs1_rs2(
 		ISA32_RISCV,
 		"rem",
 		(uint32_t)0x2006033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//rem\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 XLM1 = 0;\n"
 			"etiss_int32 MMIN = 0;\n"
 			"etiss_int32 M1 = 0;\n"
 			"etiss_int32 ONE = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"M1 =  - 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"M1 = %#x\\n\",M1); \n"
		#endif	
		"XLM1 = 32 - 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"XLM1 = %#x\\n\",XLM1); \n"
		#endif	
		"ONE = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"ONE = %#x\\n\",ONE); \n"
		#endif	
		"MMIN = (ONE << XLM1);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"MMIN = %#x\\n\",MMIN); \n"
		#endif	
		"if((*((RISCV*)cpu)->X[" + toString(rs1) + "] == MMIN) && (*((RISCV*)cpu)->X[" + toString(rs2) + "] == M1))\n"
		"{\n"
			"*((RISCV*)cpu)->X[" + toString(rd) + "] = 0;\n"
			#if RISCV_DEBUG_CALL
			"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
		
		"else\n"
		"{\n"
			"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
			"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
			"}\n"
			"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
			"}\n"
			"*((RISCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int32)cast_1 % (etiss_int32)cast_0);\n"
			#if RISCV_DEBUG_CALL
			"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
			#endif	
		"}\n"
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition remu_rd_rs1_rs2(
 		ISA32_RISCV,
 		"remu",
 		(uint32_t)0x2007033,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//remu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"if(*((RISCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] % *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fadd_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fadd.d",
 		(uint32_t)0x2000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fadd.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fadd_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition lr_w_rd_rs1(
 		ISA32_RISCV,
 		"lr.w",
 		(uint32_t)0x1000202f,
 		(uint32_t) 0xf9f0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//lr.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"offs = %#x\\n\",offs); \n"
	#endif	
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
	"etiss_int32 cast_0 = MEM_offs; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
	"((RISCV*)cpu)->RES = offs;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sc_w_rd_rs1_rs2(
 		ISA32_RISCV,
 		"sc.w",
 		(uint32_t)0x1800202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sc.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
"if(offs == ((RISCV*)cpu)->RES)\n"
"{\n"
	"etiss_uint32 MEM_offs;\n"
	"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
	"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
	#endif	
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"if(" + toString(rd) + " != 0)\n"
	"{\n"
		"*((RISCV*)cpu)->X[" + toString(rd) + "] = 1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
		#endif	
	"}\n"
	
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoswap_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amoswap.w",
 		(uint32_t)0x800202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoswap.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
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
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoadd_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amoadd.w",
 		(uint32_t)0x202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoadd.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = res1 + *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoxor_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amoxor.w",
 		(uint32_t)0x2000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoxor.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res1 ^ *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoand_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amoand.w",
 		(uint32_t)0x6000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoand.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res1 & *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amoor_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amoor.w",
 		(uint32_t)0x4000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amoor.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"res2 = (res1 | *((RISCV*)cpu)->X[" + toString(rs2) + "]);\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomin_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amomin.w",
 		(uint32_t)0x8000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amomin.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
"}\n"
"etiss_int32 cast_2 = res1; \n"
"if((etiss_int32)((etiss_uint32)cast_2 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_2 =0x0 + (etiss_uint32)cast_2 ;\n"
"}\n"
"if((etiss_int32)cast_2 > (etiss_int32)cast_1)\n"
"{\n"
	"choose1 = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomax_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amomax.w",
 		(uint32_t)0xa000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amomax.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"etiss_int32 cast_1 = *((RISCV*)cpu)->X[" + toString(rs2) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
"}\n"
"etiss_int32 cast_2 = res1; \n"
"if((etiss_int32)((etiss_uint32)cast_2 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_2 =0x0 + (etiss_uint32)cast_2 ;\n"
"}\n"
"if((etiss_int32)cast_2 < (etiss_int32)cast_1)\n"
"{\n"
	"choose1 = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amominu_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amominu.w",
 		(uint32_t)0xc000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amominu.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(res1 > *((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"choose1 = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition amomaxu_w_rd_rs1_rs2_aqu_aq_rel_rl_(
 		ISA32_RISCV,
 		"amomaxu.w",
 		(uint32_t)0xe000202f,
 		(uint32_t) 0xf800707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 aq = 0;
 		static BitArrayRange R_aq_0 (26,26);
 		etiss_uint32 aq_0 = R_aq_0.read(ba);
 		aq += aq_0;
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rl = 0;
 		static BitArrayRange R_rl_0 (25,25);
 		etiss_uint32 rl_0 = R_rl_0.read(ba);
 		rl += rl_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//amomaxu.w\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_int32 res1 = 0;\n"
 			"etiss_uint32 res2 = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res1 = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"res1 = %#x\\n\",res1); \n"
#endif	
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"if(res1 < *((RISCV*)cpu)->X[" + toString(rs2) + "])\n"
"{\n"
	"choose1 = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = res1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res2 = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"res2 = %#x\\n\",res2); \n"
#endif	
    									"tmpbuf = (etiss_uint8 *)&MEM_offs;\n" 									
"MEM_offs = res2;\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsub_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsub.s",
 		(uint32_t)0x8000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsub.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fsub_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fsub_s(frs1, frs2, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fdiv_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fdiv.s",
 		(uint32_t)0x18000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fdiv.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fdiv_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fdiv_s(frs1, frs2, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsqrt_s_rd_frs1(
 		ISA32_RISCV,
 		"fsqrt.s",
 		(uint32_t)0x58000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsqrt.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
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
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fsqrt_s(((RISCV*)cpu)->F[" + toString(rs1) + "], choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"if(" + toString(rm) + " < 7)\n"
	"{\n"
		"choose1 = (" + toString(rm) + " & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"res = fsqrt_s(frs1, choose1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnj_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsgnj.s",
 		(uint32_t)0x20000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsgnj.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((((RISCV*)cpu)->F[" + toString(rs1) + "] & 2147483647) | (((RISCV*)cpu)->F[" + toString(rs2) + "] & -2147483648));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = ((frs1 & 2147483647) | (frs2 & -2147483648));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjn_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsgnjn.s",
 		(uint32_t)0x20001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsgnjn.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((((RISCV*)cpu)->F[" + toString(rs1) + "] & 2147483647) | (~((RISCV*)cpu)->F[" + toString(rs2) + "] & -2147483648))&0xffffffffffffffff;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = ((frs1 & 2147483647) | (~frs2 & -2147483648))&0xffffffff;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjx_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsgnjx.s",
 		(uint32_t)0x20002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsgnjx.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = (((RISCV*)cpu)->F[" + toString(rs1) + "] ^ (((RISCV*)cpu)->F[" + toString(rs2) + "] & -2147483648));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = (frs1 ^ (frs2 & -2147483648));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmin_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fmin.s",
 		(uint32_t)0x28000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmin.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fsel_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = fsel_s(frs1, frs2, (etiss_uint32)0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmax_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fmax.s",
 		(uint32_t)0x28001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmax.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fsel_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"res = fsel_s(frs1, frs2, (etiss_uint32)1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_w_s_rd_frs1(
 		ISA32_RISCV,
 		"fcvt.w.s",
 		(uint32_t)0xc0000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.w.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"etiss_int32 cast_0 = fcvt_s(((RISCV*)cpu)->F[" + toString(rs1) + "], (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"etiss_int32 cast_1 = fcvt_s(frs1, (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_wu_s_rd_frs1(
 		ISA32_RISCV,
 		"fcvt.wu.s",
 		(uint32_t)0xc0100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.wu.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"etiss_int32 cast_0 = fcvt_s(((RISCV*)cpu)->F[" + toString(rs1) + "], (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"etiss_int32 cast_1 = fcvt_s(frs1, (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition feq_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"feq.s",
 		(uint32_t)0xa0002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//feq.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_s(frs1, frs2, (etiss_uint32)0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition flt_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"flt.s",
 		(uint32_t)0xa0001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//flt.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)2);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_s(frs1, frs2, (etiss_uint32)2);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"*((RISCV*)cpu)->X[" + toString(rd) + "] = fcmp_s((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffff), (etiss_uint32)2);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fle_s_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fle.s",
 		(uint32_t)0xa0000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fle.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 frs1 = 0;\n"
 			"etiss_uint32 frs2 = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_s(((RISCV*)cpu)->F[" + toString(rs1) + "], ((RISCV*)cpu)->F[" + toString(rs2) + "], (etiss_uint32)1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"frs1 = unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs1 = %#x\\n\",frs1); \n"
	#endif	
	"frs2 = unbox_s(((RISCV*)cpu)->F[" + toString(rs2) + "]);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"frs2 = %#x\\n\",frs2); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_s(frs1, frs2, (etiss_uint32)1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fclass_s_rd_frs1(
 		ISA32_RISCV,
 		"fclass.s",
 		(uint32_t)0xe0001053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fclass.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = fclass_s(unbox_s(((RISCV*)cpu)->F[" + toString(rs1) + "]));\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmv_x_w_rd_frs1(
 		ISA32_RISCV,
 		"fmv.x.w",
 		(uint32_t)0xe0000053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmv.x.w\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"etiss_int64 cast_0 = (((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffff); \n"
"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_w_rd_rs1(
 		ISA32_RISCV,
 		"fcvt.s.w",
 		(uint32_t)0xd0000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.s.w\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fcvt_s((*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"res = fcvt_s((*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_s_wu_rd_rs1(
 		ISA32_RISCV,
 		"fcvt.s.wu",
 		(uint32_t)0xd0100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.s.wu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = fcvt_s((*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"res = fcvt_s((*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"res = %#x\\n\",res); \n"
	#endif	
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmv_w_x_rd_rs1(
 		ISA32_RISCV,
 		"fmv.w.x",
 		(uint32_t)0xf0000053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmv.w.x\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 upper = 0;\n"
 			
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)(*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsub_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsub.d",
 		(uint32_t)0xa000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsub.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fsub_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fdiv_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fdiv.d",
 		(uint32_t)0x1a000053,
 		(uint32_t) 0xfe00007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fdiv.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fdiv_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsqrt_d_rd_frs1(
 		ISA32_RISCV,
 		"fsqrt.d",
 		(uint32_t)0x5a000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsqrt.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			"etiss_uint32 choose1 = 0;\n"
 			
"if(" + toString(rm) + " < 7)\n"
"{\n"
	"choose1 = (" + toString(rm) + " & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"choose1 = (((RISCV*)cpu)->FCSR & 0xff);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"res = fsqrt_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), choose1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnj_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsgnj.d",
 		(uint32_t)0x22000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsgnj.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_int64 MSK1 = 0;\n"
 			"etiss_int64 MSK2 = 0;\n"
 			
"ONE = 1;\n"
#if RISCV_DEBUG_CALL
"printf(\"ONE = %#lx\\n\",ONE); \n"
#endif	
"MSK1 = (ONE << 63);\n"
#if RISCV_DEBUG_CALL
"printf(\"MSK1 = %#lx\\n\",MSK1); \n"
#endif	
"MSK2 = MSK1 - 1;\n"
#if RISCV_DEBUG_CALL
"printf(\"MSK2 = %#lx\\n\",MSK2); \n"
#endif	
"res = (((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff) & MSK2) | ((((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff) & MSK1));\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjn_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsgnjn.d",
 		(uint32_t)0x22001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsgnjn.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_int64 MSK1 = 0;\n"
 			"etiss_int64 MSK2 = 0;\n"
 			
"ONE = 1;\n"
#if RISCV_DEBUG_CALL
"printf(\"ONE = %#lx\\n\",ONE); \n"
#endif	
"MSK1 = (ONE << 63);\n"
#if RISCV_DEBUG_CALL
"printf(\"MSK1 = %#lx\\n\",MSK1); \n"
#endif	
"MSK2 = MSK1 - 1;\n"
#if RISCV_DEBUG_CALL
"printf(\"MSK2 = %#lx\\n\",MSK2); \n"
#endif	
"res = (((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff) & MSK2) | (~(((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff) & MSK1))&0xffffffffffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fsgnjx_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fsgnjx.d",
 		(uint32_t)0x22002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fsgnjx.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_int64 MSK1 = 0;\n"
 			
"ONE = 1;\n"
#if RISCV_DEBUG_CALL
"printf(\"ONE = %#lx\\n\",ONE); \n"
#endif	
"MSK1 = (ONE << 63);\n"
#if RISCV_DEBUG_CALL
"printf(\"MSK1 = %#lx\\n\",MSK1); \n"
#endif	
"res = ((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff) ^ ((((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff) & MSK1));\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmin_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fmin.d",
 		(uint32_t)0x2a000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmin.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			
"res = fsel_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)0);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fmax_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fmax.d",
 		(uint32_t)0x2a001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fmax.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			"etiss_uint32 flags = 0;\n"
 			
"res = fsel_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)1);\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_s_rd_frs1(
 		ISA32_RISCV,
 		"fcvt.d.s",
 		(uint32_t)0x42000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.d.s\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fconv_f2d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffff), (" + toString(rm) + " & 0xff));\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition feq_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"feq.d",
 		(uint32_t)0xa2002053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//feq.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)0);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition flt_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"flt.d",
 		(uint32_t)0xa2001053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//flt.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)2);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fle_d_rd_frs1_frs2(
 		ISA32_RISCV,
 		"fle.d",
 		(uint32_t)0xa2000053,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fle.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint32)fcmp_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff), (etiss_uint32)1);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fclass_d_rd_frs1(
 		ISA32_RISCV,
 		"fclass.d",
 		(uint32_t)0xe2001053,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fclass.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = fclass_d((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff));\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_w_d_rd_frs1(
 		ISA32_RISCV,
 		"fcvt.w.d",
 		(uint32_t)0xc2000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.w.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"etiss_int32 cast_0 = fcvt_64_32((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (etiss_uint32)0, (" + toString(rm) + " & 0xff)); \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_wu_d_rd_frs1(
 		ISA32_RISCV,
 		"fcvt.wu.d",
 		(uint32_t)0xc2100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.wu.d\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 flags = 0;\n"
 			
"etiss_int32 cast_0 = fcvt_64_32((((RISCV*)cpu)->F[" + toString(rs1) + "] & 0xffffffffffffffff), (etiss_uint32)1, (" + toString(rm) + " & 0xff)); \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
"flags = fget_flags();\n"
#if RISCV_DEBUG_CALL
"printf(\"flags = %#x\\n\",flags); \n"
#endif	
"((RISCV*)cpu)->FCSR = (((RISCV*)cpu)->FCSR & ~31) + (flags & 0x1f)&0xffffffff;\n"
#if RISCV_DEBUG_CALL
"printf(\"((RISCV*)cpu)->FCSR = %#x\\n\",((RISCV*)cpu)->FCSR); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_w_rd_rs1(
 		ISA32_RISCV,
 		"fcvt.d.w",
 		(uint32_t)0xd2000053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.d.w\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"etiss_int32 cast_0 = (*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"res = fcvt_32_64((etiss_int64)cast_0, (etiss_uint32)2, (" + toString(rm) + " & 0xff));\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition fcvt_d_wu_rd_rs1(
 		ISA32_RISCV,
 		"fcvt.d.wu",
 		(uint32_t)0xd2100053,
 		(uint32_t) 0xfff0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 rm = 0;
 		static BitArrayRange R_rm_0 (14,12);
 		etiss_uint32 rm_0 = R_rm_0.read(ba);
 		rm += rm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//fcvt.d.wu\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"res = fcvt_32_64((etiss_uint64)(*((RISCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff), (etiss_uint32)3, (" + toString(rm) + " & 0xff));\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi4spn_rd_imm(
 		ISA16_RISCV,
 		"c.addi4spn",
 		(uint16_t)0x0,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 imm = 0;
 		static BitArrayRange R_imm_4 (12,11);
 		etiss_uint32 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_6 (10,7);
 		etiss_uint32 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_2 (6,6);
 		etiss_uint32 imm_2 = R_imm_2.read(ba);
 		imm += imm_2<<2;
 		static BitArrayRange R_imm_3 (5,5);
 		etiss_uint32 imm_3 = R_imm_3.read(ba);
 		imm += imm_3<<3;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.addi4spn\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"if(" + toString(imm) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV*)cpu)->X[" + toString(rd) + " + 8] = *((RISCV*)cpu)->X[2] + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi_rs1_imm(
 		ISA16_RISCV,
 		"c.addi",
 		(uint16_t)0x1,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.addi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967232;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[" + toString(rs1) + "]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[" + toString(rs1) + "] = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rs1) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rs1) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_nop_(
 		ISA16_RISCV,
 		"c.nop",
 		(uint16_t)0x1,
 		(uint16_t) 0xffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.nop\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition dii_(
 		ISA16_RISCV,
 		"dii",
 		(uint16_t)0x0,
 		(uint16_t) 0xffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//dii\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_slli_rs1_shamt(
 		ISA16_RISCV,
 		"c.slli",
 		(uint16_t)0x2,
 		(uint16_t) 0xf003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 shamt = 0;
 		static BitArrayRange R_shamt_0 (6,2);
 		etiss_uint32 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.slli\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 X = 0; \n"
 			"for ( int i = 0; i< 32 ; i++)\n"
 			"{\n"
 				"X ^= ((-*((RISCV*)cpu)->X[i])^X) & (1 << i ); \n"
 			"}\n"
 			
"if(" + toString(rs1) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV*)cpu)->X[" + toString(rs1) + "] = (*((RISCV*)cpu)->X[" + toString(rs1) + "] << " + toString(shamt) + ");\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rs1) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rs1) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lw_8_rd_uimm_8_rs1_(
 		ISA16_RISCV,
 		"c.lw",
 		(uint16_t)0x4000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_2 (6,6);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (5,5);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.lw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + " + 8] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_li_rd_imm(
 		ISA16_RISCV,
 		"c.li",
 		(uint16_t)0x4001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.li\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967232;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lwsp_rd_sp_uimm(
 		ISA16_RISCV,
 		"c.lwsp",
 		(uint16_t)0x4002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_5 (12,12);
 		etiss_uint32 uimm_5 = R_uimm_5.read(ba);
 		uimm += uimm_5<<5;
 		static BitArrayRange R_uimm_2 (6,4);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (3,2);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.lwsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"etiss_int32 cast_0 = MEM_offs; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[" + toString(rd) + "] = (etiss_int32)cast_0;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sw_8_rs2_uimm_8_rs1_(
 		ISA16_RISCV,
 		"c.sw",
 		(uint16_t)0xc000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_2 (6,6);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (5,5);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.sw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + " + 8];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_beqz_8_rs1_imm(
 		ISA16_RISCV,
 		"c.beqz",
 		(uint16_t)0xc001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_8 (12,12);
 		etiss_int32 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_3 (11,10);
 		etiss_int32 imm_3 = R_imm_3.read(ba);
 		imm += imm_3<<3;
 		static BitArrayRange R_imm_6 (6,5);
 		etiss_int32 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_1 (4,3);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.beqz\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x100)>>8 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294966784;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(*((RISCV*)cpu)->X[" + toString(rs1) + " + 8] == 0)\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_swsp_rs2_uimm_sp_(
 		ISA16_RISCV,
 		"c.swsp",
 		(uint16_t)0xc002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_2 (12,9);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (8,7);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.swsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_jal_imm(
 		ISA16_RISCV,
 		"c.jal",
 		(uint16_t)0x2001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_11 (12,12);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		static BitArrayRange R_imm_4 (11,11);
 		etiss_int32 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_8 (10,9);
 		etiss_int32 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_10 (8,8);
 		etiss_int32 imm_10 = R_imm_10.read(ba);
 		imm += imm_10<<10;
 		static BitArrayRange R_imm_6 (7,7);
 		etiss_int32 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_7 (6,6);
 		etiss_int32 imm_7 = R_imm_7.read(ba);
 		imm += imm_7<<7;
 		static BitArrayRange R_imm_1 (5,3);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.jal\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"*((RISCV*)cpu)->X[1] = " +toString((uint32_t)ic.current_address_)+"ULL  + 2;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[1] = %#x\\n\",*((RISCV*)cpu)->X[1]); \n"
#endif	
"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"cpu->instructionPointer = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fld_rd_uimm_8_rs1_(
 		ISA16_RISCV,
 		"c.fld",
 		(uint16_t)0x2000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (6,5);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.fld\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"res = MEM_offs;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + " + 8]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = ((upper << 64) | res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + " + 8]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fldsp_rd_uimm_x2_(
 		ISA16_RISCV,
 		"c.fldsp",
 		(uint16_t)0x2002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_5 (12,12);
 		etiss_uint32 uimm_5 = R_uimm_5.read(ba);
 		uimm += uimm_5<<5;
 		static BitArrayRange R_uimm_3 (6,5);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (4,2);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.fldsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_uint64 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,8);\n"
"res = MEM_offs;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#lx\\n\",res); \n"
#endif	
"if(64 == 64)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 64) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_lui_rd_imm(
 		ISA16_RISCV,
 		"c.lui",
 		(uint16_t)0x6001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint32 imm = 0;
 		static BitArrayRange R_imm_17 (12,12);
 		etiss_uint32 imm_17 = R_imm_17.read(ba);
 		imm += imm_17<<17;
 		static BitArrayRange R_imm_12 (6,2);
 		etiss_int32 imm_12 = R_imm_12.read(ba);
 		imm += imm_12<<12;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.lui\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x20000)>>17 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294705152;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(" + toString(rd) + " == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"if(imm_extended == 0)\n"
"{\n"
	"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
"}\n"

"*((RISCV*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_addi16sp_imm(
 		ISA16_RISCV,
 		"c.addi16sp",
 		(uint16_t)0x6101,
 		(uint16_t) 0xef83,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_9 (12,12);
 		etiss_int32 imm_9 = R_imm_9.read(ba);
 		imm += imm_9<<9;
 		static BitArrayRange R_imm_4 (6,6);
 		etiss_int32 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_6 (5,5);
 		etiss_int32 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_7 (4,3);
 		etiss_int32 imm_7 = R_imm_7.read(ba);
 		imm += imm_7<<7;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
  		partInit.getAffectedRegisters().add(reg_name[2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.addi16sp\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x200)>>9 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294966272;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[2]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[2] = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[2] = %#x\\n\",*((RISCV*)cpu)->X[2]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_flw_rd_uimm_8_rs1_(
 		ISA16_RISCV,
 		"c.flw",
 		(uint16_t)0x6000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_2 (6,6);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (5,5);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (4,2);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.flw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"res = MEM_offs;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + " + 8]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + " + 8] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + " + 8]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_flwsp_rd_uimm_x2_(
 		ISA16_RISCV,
 		"c.flwsp",
 		(uint16_t)0x6002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_5 (12,12);
 		etiss_uint32 uimm_5 = R_uimm_5.read(ba);
 		uimm += uimm_5<<5;
 		static BitArrayRange R_uimm_2 (6,4);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (3,2);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.flwsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			"etiss_uint32 res = 0;\n"
 			"etiss_int64 upper = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
"res = MEM_offs;\n"
#if RISCV_DEBUG_CALL
"printf(\"res = %#x\\n\",res); \n"
#endif	
"if(64 == 32)\n"
"{\n"
	"((RISCV*)cpu)->F[" + toString(rd) + "] = res;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"upper =  - 1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"upper = %#lx\\n\",upper); \n"
	#endif	
	"((RISCV*)cpu)->F[" + toString(rd) + "] = ((upper << 32) | (etiss_uint64)res);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->F[" + toString(rd) + "] = %#lx\\n\",((RISCV*)cpu)->F[" + toString(rd) + "]); \n"
	#endif	
"}\n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_srli_8_rs1_shamt(
 		ISA16_RISCV,
 		"c.srli",
 		(uint16_t)0x8001,
 		(uint16_t) 0xfc03,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 shamt = 0;
 		static BitArrayRange R_shamt_0 (6,2);
 		etiss_uint32 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.srli\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 X = 0; \n"
 			"for ( int i = 0; i< 32 ; i++)\n"
 			"{\n"
 				"X ^= ((-*((RISCV*)cpu)->X[i])^X) & (1 << i ); \n"
 			"}\n"
 			"etiss_int8 rs1_idx = 0;\n"
 			
"rs1_idx = " + toString(rs1) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
#endif	
"*((RISCV*)cpu)->X[rs1_idx] = (*((RISCV*)cpu)->X[rs1_idx] >> " + toString(shamt) + ");\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rs1_idx] = %#x\\n\",*((RISCV*)cpu)->X[rs1_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_srai_8_rs1_shamt(
 		ISA16_RISCV,
 		"c.srai",
 		(uint16_t)0x8401,
 		(uint16_t) 0xfc03,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 shamt = 0;
 		static BitArrayRange R_shamt_0 (6,2);
 		etiss_uint32 shamt_0 = R_shamt_0.read(ba);
 		shamt += shamt_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.srai\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rs1_idx = 0;\n"
 			
"rs1_idx = " + toString(rs1) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[rs1_idx]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[rs1_idx] = ((etiss_int32)cast_0 >> " + toString(shamt) + ");\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rs1_idx] = %#x\\n\",*((RISCV*)cpu)->X[rs1_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_sub_8_rd_8_rs2(
 		ISA16_RISCV,
 		"c.sub",
 		(uint16_t)0x8c01,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],32);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.sub\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV*)cpu)->X[rd_idx] = *((RISCV*)cpu)->X[rd_idx] - *((RISCV*)cpu)->X[" + toString(rs2) + " + 8];\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rd_idx] = %#x\\n\",*((RISCV*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_xor_8_rd_8_rs2(
 		ISA16_RISCV,
 		"c.xor",
 		(uint16_t)0x8c21,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],32);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.xor\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV*)cpu)->X[rd_idx] = (*((RISCV*)cpu)->X[rd_idx] ^ *((RISCV*)cpu)->X[" + toString(rs2) + " + 8]);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rd_idx] = %#x\\n\",*((RISCV*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_or_8_rd_8_rs2(
 		ISA16_RISCV,
 		"c.or",
 		(uint16_t)0x8c41,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],32);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.or\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV*)cpu)->X[rd_idx] = (*((RISCV*)cpu)->X[rd_idx] | *((RISCV*)cpu)->X[" + toString(rs2) + " + 8]);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rd_idx] = %#x\\n\",*((RISCV*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_and_8_rd_8_rs2(
 		ISA16_RISCV,
 		"c.and",
 		(uint16_t)0x8c61,
 		(uint16_t) 0xfc63,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (9,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rd+8],32);
 		partInit.getRegisterDependencies().add(reg_name[rs2+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rd+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.and\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
"rd_idx = " + toString(rd) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
#endif	
"*((RISCV*)cpu)->X[rd_idx] = (*((RISCV*)cpu)->X[rd_idx] & *((RISCV*)cpu)->X[" + toString(rs2) + " + 8]);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rd_idx] = %#x\\n\",*((RISCV*)cpu)->X[rd_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_mv_rd_rs2(
 		ISA16_RISCV,
 		"c.mv",
 		(uint16_t)0x8002,
 		(uint16_t) 0xf003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.mv\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_jr_rs1(
 		ISA16_RISCV,
 		"c.jr",
 		(uint16_t)0x8002,
 		(uint16_t) 0xf07f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.jr\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"cpu->instructionPointer = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_andi_8_rs1_imm(
 		ISA16_RISCV,
 		"c.andi",
 		(uint16_t)0x8801,
 		(uint16_t) 0xec03,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_5 (12,12);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		static BitArrayRange R_imm_0 (6,2);
 		etiss_int32 imm_0 = R_imm_0.read(ba);
 		imm += imm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
  		partInit.getAffectedRegisters().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.andi\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int8 rs1_idx = 0;\n"
 			
"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294967232;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"rs1_idx = " + toString(rs1) + " + 8;\n"
#if RISCV_DEBUG_CALL
"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
#endif	
"etiss_int32 cast_0 = *((RISCV*)cpu)->X[rs1_idx]; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"*((RISCV*)cpu)->X[rs1_idx] = ((etiss_int32)cast_0 & imm_extended);\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[rs1_idx] = %#x\\n\",*((RISCV*)cpu)->X[rs1_idx]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_add_rd_rs2(
 		ISA16_RISCV,
 		"c.add",
 		(uint16_t)0x9002,
 		(uint16_t) 0xf003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rd],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.add\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV*)cpu)->X[" + toString(rd) + "] = *((RISCV*)cpu)->X[" + toString(rd) + "] + *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
#endif	
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_jalr_rs1(
 		ISA16_RISCV,
 		"c.jalr",
 		(uint16_t)0x9002,
 		(uint16_t) 0xf07f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (11,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[1],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.jalr\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"*((RISCV*)cpu)->X[1] = " +toString((uint32_t)ic.current_address_)+"ULL  + 2;\n"
#if RISCV_DEBUG_CALL
"printf(\"*((RISCV*)cpu)->X[1] = %#x\\n\",*((RISCV*)cpu)->X[1]); \n"
#endif	
"cpu->instructionPointer = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_ebreak_(
 		ISA16_RISCV,
 		"c.ebreak",
 		(uint16_t)0x9002,
 		(uint16_t) 0xffff,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.ebreak\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
"return ETISS_RETURNCODE_CPUFINISHED; \n"
 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_j_imm(
 		ISA16_RISCV,
 		"c.j",
 		(uint16_t)0xa001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_11 (12,12);
 		etiss_int32 imm_11 = R_imm_11.read(ba);
 		imm += imm_11<<11;
 		static BitArrayRange R_imm_4 (11,11);
 		etiss_int32 imm_4 = R_imm_4.read(ba);
 		imm += imm_4<<4;
 		static BitArrayRange R_imm_8 (10,9);
 		etiss_int32 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_10 (8,8);
 		etiss_int32 imm_10 = R_imm_10.read(ba);
 		imm += imm_10<<10;
 		static BitArrayRange R_imm_6 (7,7);
 		etiss_int32 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_7 (6,6);
 		etiss_int32 imm_7 = R_imm_7.read(ba);
 		imm += imm_7<<7;
 		static BitArrayRange R_imm_1 (5,3);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.j\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			
"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294963200;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
"{\n"
	"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
"}\n"
"cpu->instructionPointer = (etiss_int32)cast_0 + imm_extended;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fsd_rs2_uimm_8_rs1_(
 		ISA16_RISCV,
 		"c.fsd",
 		(uint16_t)0xa000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (6,5);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.fsd\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV*)cpu)->F[" + toString(rs2) + " + 8] & 0xffffffffffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fsdsp_rs2_uimm_x2_(
 		ISA16_RISCV,
 		"c.fsdsp",
 		(uint16_t)0xa002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_6 (9,7);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.fsdsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint64 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffffffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 8 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_bnez_8_rs1_imm(
 		ISA16_RISCV,
 		"c.bnez",
 		(uint16_t)0xe001,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_int32 imm = 0;
 		static BitArrayRange R_imm_8 (12,12);
 		etiss_int32 imm_8 = R_imm_8.read(ba);
 		imm += imm_8<<8;
 		static BitArrayRange R_imm_3 (11,10);
 		etiss_int32 imm_3 = R_imm_3.read(ba);
 		imm += imm_3<<3;
 		static BitArrayRange R_imm_6 (6,5);
 		etiss_int32 imm_6 = R_imm_6.read(ba);
 		imm += imm_6<<6;
 		static BitArrayRange R_imm_1 (4,3);
 		etiss_int32 imm_1 = R_imm_1.read(ba);
 		imm += imm_1<<1;
 		static BitArrayRange R_imm_5 (2,2);
 		etiss_int32 imm_5 = R_imm_5.read(ba);
 		imm += imm_5<<5;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.bnez\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 imm_extended = 0;\n"
 			"etiss_int32 choose1 = 0;\n"
 			
"if((" + toString(imm) + " & 0x100)>>8 == 0)\n"
"{\n"
	"imm_extended = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"

"else\n"
"{\n"
	"imm_extended = 4294966784;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
	#endif	
"}\n"
"imm_extended = imm_extended + " + toString(imm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
#endif	
"if(*((RISCV*)cpu)->X[" + toString(rs1) + " + 8] != 0)\n"
"{\n"
	"etiss_int32 cast_0 = " +toString((uint32_t)ic.current_address_)+"ULL ; \n"
	"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
	"}\n"
	"choose1 = (etiss_int32)cast_0 + imm_extended;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
// Explicit assignment to PC
"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
"}\n"

"else\n"
"{\n"
	"choose1 = " +toString((uint32_t)ic.current_address_)+"ULL  + 2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"choose1 = %#x\\n\",choose1); \n"
	#endif	
"}\n"
"cpu->instructionPointer = choose1;\n"
#if RISCV_DEBUG_CALL
"printf(\"cpu->instructionPointer = %#lx\\n\",cpu->instructionPointer); \n"
#endif	
 			
		"cpu->instructionPointer = (uint32_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fsw_rs2_uimm_8_rs1_(
 		ISA16_RISCV,
 		"c.fsw",
 		(uint16_t)0xe000,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (4,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (9,7);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_3 (12,10);
 		etiss_uint32 uimm_3 = R_uimm_3.read(ba);
 		uimm += uimm_3<<3;
 		static BitArrayRange R_uimm_2 (6,6);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (5,5);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1+8],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.fsw\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV*)cpu)->F[" + toString(rs2) + " + 8] & 0xffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition c_fswsp_rs2_uimm_x2_(
 		ISA16_RISCV,
 		"c.fswsp",
 		(uint16_t)0xe002,
 		(uint16_t) 0xe003,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (6,2);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 uimm = 0;
 		static BitArrayRange R_uimm_2 (12,9);
 		etiss_uint32 uimm_2 = R_uimm_2.read(ba);
 		uimm += uimm_2<<2;
 		static BitArrayRange R_uimm_6 (8,7);
 		etiss_uint32 uimm_6 = R_uimm_6.read(ba);
 		uimm += uimm_6<<6;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[2],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//c.fswsp\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 offs = 0;\n"
 			
"offs = *((RISCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
#if RISCV_DEBUG_CALL
"printf(\"offs = %#x\\n\",offs); \n"
#endif	
    																																												"etiss_uint32 MEM_offs;\n"
"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
"MEM_offs = (((RISCV*)cpu)->F[" + toString(rs2) + "] & 0xffffffff);\n"
"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
#if RISCV_DEBUG_CALL
"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
#endif	
"if((offs + 4 > ((RISCV*)cpu)->RES) && (offs < 4 + ((RISCV*)cpu)->RES))\n"
"{\n"
	"((RISCV*)cpu)->RES = 0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"((RISCV*)cpu)->RES = %#x\\n\",((RISCV*)cpu)->RES); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 2 ))+"ULL; \n"
		
		"return exception;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition add8_rs2_rs1_rd(
 		ISA32_RISCV,
 		"add8",
 		(uint32_t)0x4800007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//add8\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 byte_1 = 0;\n"
 			"etiss_int8 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int8 byte_3 = 0;\n"
 			"etiss_int8 byte_4 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#x\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#x\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#x\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#x\\n\",rs2_3); \n"
	#endif	
	"byte_1 = rs1_0 + rs2_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#x\\n\",byte_1); \n"
	#endif	
	"byte_2 = rs1_1 + rs2_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#x\\n\",byte_2); \n"
	#endif	
	"byte_3 = rs1_2 + rs2_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#x\\n\",byte_3); \n"
	#endif	
	"byte_4 = rs1_3 + rs2_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#x\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((((byte_4 & 255) << 24) | ((byte_3 & 255) << 16)) | ((byte_2 & 255) << 8)) | (byte_1 & 255));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sub8_rs2_rs1_rd(
 		ISA32_RISCV,
 		"sub8",
 		(uint32_t)0x4a00007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sub8\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 byte_1 = 0;\n"
 			"etiss_int8 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int8 byte_3 = 0;\n"
 			"etiss_int8 byte_4 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#d\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#d\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#d\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#d\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#d\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#d\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#d\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#d\\n\",rs2_3); \n"
	#endif	
	"byte_1 = rs1_0 - rs2_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#d\\n\",byte_1); \n"
	#endif	
	"byte_2 = rs1_1 - rs2_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#d\\n\",byte_2); \n"
	#endif	
	"byte_3 = rs1_2 - rs2_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#d\\n\",byte_3); \n"
	#endif	
	"byte_4 = rs1_3 - rs2_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#d\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((((byte_4 & 255) << 24) | ((byte_3 & 255) << 16)) | ((byte_2 & 255) << 8)) | (byte_1 & 255));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition smaqa_rs2_rs1_rd(
 		ISA32_RISCV,
 		"smaqa",
 		(uint32_t)0xc800007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
 		partInit.getRegisterDependencies().add(reg_name[rd],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//smaqa\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 byte_1 = 0;\n"
 			"etiss_int32 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_uint32 rd_val = 0;\n"
 			"etiss_int32 byte_3 = 0;\n"
 			"etiss_int32 byte_4 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"rd_val = *((RISCV*)cpu)->X[" + toString(rd) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rd_val = %#x\\n\",rd_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#x\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#x\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#x\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#x\\n\",rs2_3); \n"
	#endif	
	"byte_1 = (rs1_0 * rs2_0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#x\\n\",byte_1); \n"
	#endif	
	"byte_2 = (rs1_1 * rs2_1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#x\\n\",byte_2); \n"
	#endif	
	"byte_3 = (rs1_2 * rs2_2);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#x\\n\",byte_3); \n"
	#endif	
	"byte_4 = (rs1_3 * rs2_3);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#x\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = rd_val + byte_1 + byte_2 + byte_3 + byte_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sll8_rs2_rs1_rd(
 		ISA32_RISCV,
 		"sll8",
 		(uint32_t)0x5c00007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//sll8\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 byte_1 = 0;\n"
 			"etiss_int8 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int8 byte_3 = 0;\n"
 			"etiss_int8 byte_4 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#x\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#x\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 7); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 7); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 7); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#x\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 7); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#x\\n\",rs2_3); \n"
	#endif	
	"byte_1 = (rs1_0 << rs2_0);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#x\\n\",byte_1); \n"
	#endif	
	"byte_2 = (rs1_1 << rs2_1);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#x\\n\",byte_2); \n"
	#endif	
	"byte_3 = (rs1_2 << rs2_2);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#x\\n\",byte_3); \n"
	#endif	
	"byte_4 = (rs1_3 << rs2_3);\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#x\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((((byte_4 & 255) << 24) | ((byte_3 & 255) << 16)) | ((byte_2 & 255) << 8)) | (byte_1 & 255));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition smin8_rs2_rs1_rd(
 		ISA32_RISCV,
 		"smin8",
 		(uint32_t)0x8800007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//smin8\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 byte_1 = 0;\n"
 			"etiss_int8 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int8 byte_3 = 0;\n"
 			"etiss_int8 byte_4 = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#x\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#x\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#x\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#x\\n\",rs2_3); \n"
	#endif	
	"if(rs1_0 < rs2_0)\n"
	"{\n"
		"choose1 = rs1_0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_1 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#x\\n\",byte_1); \n"
	#endif	
	"if(rs1_1 < rs2_1)\n"
	"{\n"
		"choose1 = rs1_1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_2 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#x\\n\",byte_2); \n"
	#endif	
	"if(rs1_2 < rs2_2)\n"
	"{\n"
		"choose1 = rs1_2;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_2;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_3 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#x\\n\",byte_3); \n"
	#endif	
	"if(rs1_3 < rs2_3)\n"
	"{\n"
		"choose1 = rs1_3;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_3;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_4 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#x\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((((byte_4 & 255) << 24) | ((byte_3 & 255) << 16)) | ((byte_2 & 255) << 8)) | (byte_1 & 255));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition smax8_rs2_rs1_rd(
 		ISA32_RISCV,
 		"smax8",
 		(uint32_t)0x8a00007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//smax8\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 byte_1 = 0;\n"
 			"etiss_int8 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int8 byte_3 = 0;\n"
 			"etiss_int8 byte_4 = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#x\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#x\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#x\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#x\\n\",rs2_3); \n"
	#endif	
	"if(rs1_0 > rs2_0)\n"
	"{\n"
		"choose1 = rs1_0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_1 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#x\\n\",byte_1); \n"
	#endif	
	"if(rs1_1 > rs2_1)\n"
	"{\n"
		"choose1 = rs1_1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_2 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#x\\n\",byte_2); \n"
	#endif	
	"if(rs1_2 > rs2_2)\n"
	"{\n"
		"choose1 = rs1_2;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_2;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_3 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#x\\n\",byte_3); \n"
	#endif	
	"if(rs1_3 > rs2_3)\n"
	"{\n"
		"choose1 = rs1_3;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_3;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_4 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#x\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((((byte_4 & 255) << 24) | ((byte_3 & 255) << 16)) | ((byte_2 & 255) << 8)) | (byte_1 & 255));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition smax16_rs2_rs1_rd(
 		ISA32_RISCV,
 		"smax16",
 		(uint32_t)0x8200007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//smax16\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int16 rs2_1 = 0;\n"
 			"etiss_int16 rs1_1 = 0;\n"
 			"etiss_int16 rs2_0 = 0;\n"
 			"etiss_int16 rs1_0 = 0;\n"
 			"etiss_int16 choose1 = 0;\n"
 			"etiss_int16 half_word_2 = 0;\n"
 			"etiss_int16 half_word_1 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int16 cast_0 = (rs1_val & 0xffff); \n"
	"if((etiss_int16)((etiss_uint16)cast_0 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint16)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int16)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int16 cast_1 = ((rs1_val >> 16) & 65535); \n"
	"if((etiss_int16)((etiss_uint16)cast_1 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_1 =0x0 + (etiss_uint16)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int16)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = (rs2_val & 0xffff); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs2_0 = (etiss_int16)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int16 cast_3 = ((rs2_val >> 16) & 65535); \n"
	"if((etiss_int16)((etiss_uint16)cast_3 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint16)cast_3 ;\n"
	"}\n"
	"rs2_1 = (etiss_int16)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"if(rs1_0 > rs2_0)\n"
	"{\n"
		"choose1 = rs1_0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"half_word_1 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"half_word_1 = %#x\\n\",half_word_1); \n"
	#endif	
	"if(rs1_1 > rs2_1)\n"
	"{\n"
		"choose1 = rs1_1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = rs2_1;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"half_word_2 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"half_word_2 = %#x\\n\",half_word_2); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((half_word_2 & 65535) << 16) | (half_word_1 & 65535));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition scmple8_rs2_rs1_rd(
 		ISA32_RISCV,
 		"scmple8",
 		(uint32_t)0x1e00007f,
 		(uint32_t) 0xfe00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint32 rs2 = 0;
 		static BitArrayRange R_rs2_0 (24,20);
 		etiss_uint32 rs2_0 = R_rs2_0.read(ba);
 		rs2 += rs2_0;
 		etiss_uint32 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint32 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint32 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint32 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs2],32);
 		partInit.getRegisterDependencies().add(reg_name[rs1],32);
  		partInit.getAffectedRegisters().add(reg_name[rd],32);
		partInit.getAffectedRegisters().add("instructionPointer",32);
 	partInit.code() = std::string("//scmple8\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RISCV_Pipeline1
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif
			#if RISCV_Pipeline2
			"etiss_uint32 resource_time [10] = {1, 1, 1, 3, 1, 1, 1, 1, 4};\n"
			"etiss_uint32 resources [4][2] = {{0, 1}, {2}, {5}, {6, 7}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources [4] = {2, 1, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 byte_1 = 0;\n"
 			"etiss_int8 byte_2 = 0;\n"
 			"etiss_uint32 rs2_val = 0;\n"
 			"etiss_int8 byte_3 = 0;\n"
 			"etiss_int8 byte_4 = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			"etiss_uint32 rs1_val = 0;\n"
 			"etiss_int8 rs1_2 = 0;\n"
 			"etiss_int8 rs2_1 = 0;\n"
 			"etiss_int8 rs1_1 = 0;\n"
 			"etiss_int8 rs2_0 = 0;\n"
 			"etiss_int8 rs1_0 = 0;\n"
 			"etiss_int8 rs2_3 = 0;\n"
 			"etiss_int8 rs1_3 = 0;\n"
 			"etiss_int8 rs2_2 = 0;\n"
 			
"if(" + toString(rd) + " != 0)\n"
"{\n"
	"rs1_val = *((RISCV*)cpu)->X[" + toString(rs1) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_val = %#x\\n\",rs1_val); \n"
	#endif	
	"rs2_val = *((RISCV*)cpu)->X[" + toString(rs2) + "];\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_val = %#x\\n\",rs2_val); \n"
	#endif	
	"etiss_int8 cast_0 = (rs1_val & 0xff); \n"
	"if((etiss_int8)((etiss_uint8)cast_0 - 0x80) > 0x0)\n"
	"{\n"
		"cast_0 =0x0 + (etiss_uint8)cast_0 ;\n"
	"}\n"
	"rs1_0 = (etiss_int8)cast_0;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_0 = %#x\\n\",rs1_0); \n"
	#endif	
	"etiss_int32 cast_1 = ((rs1_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_1 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_1 =0xff000000 + (etiss_uint32)cast_1 ;\n"
	"}\n"
	"rs1_1 = (etiss_int8)cast_1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_1 = %#x\\n\",rs1_1); \n"
	#endif	
	"etiss_int16 cast_2 = ((rs1_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_2 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_2 =0x0 + (etiss_uint16)cast_2 ;\n"
	"}\n"
	"rs1_2 = (etiss_int8)cast_2;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_2 = %#x\\n\",rs1_2); \n"
	#endif	
	"etiss_int8 cast_3 = ((rs1_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_3 - 0x80) > 0x0)\n"
	"{\n"
		"cast_3 =0x0 + (etiss_uint8)cast_3 ;\n"
	"}\n"
	"rs1_3 = (etiss_int8)cast_3;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs1_3 = %#x\\n\",rs1_3); \n"
	#endif	
	"etiss_int8 cast_4 = ((rs2_val & 0xff) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_4 - 0x80) > 0x0)\n"
	"{\n"
		"cast_4 =0x0 + (etiss_uint8)cast_4 ;\n"
	"}\n"
	"rs2_0 = (etiss_int8)cast_4;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_0 = %#x\\n\",rs2_0); \n"
	#endif	
	"etiss_int32 cast_5 = ((rs2_val >> 8) & 255); \n"
	"if((etiss_int32)((etiss_uint32)cast_5 - 0x800000) > 0x0)\n"
	"{\n"
		"cast_5 =0xff000000 + (etiss_uint32)cast_5 ;\n"
	"}\n"
	"rs2_1 = (etiss_int8)cast_5;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_1 = %#x\\n\",rs2_1); \n"
	#endif	
	"etiss_int16 cast_6 = ((rs2_val >> 16) & 255); \n"
	"if((etiss_int16)((etiss_uint16)cast_6 - 0x8000) > 0x0)\n"
	"{\n"
		"cast_6 =0x0 + (etiss_uint16)cast_6 ;\n"
	"}\n"
	"rs2_2 = (etiss_int8)cast_6;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_2 = %#x\\n\",rs2_2); \n"
	#endif	
	"etiss_int8 cast_7 = ((rs2_val >> 24) & 255); \n"
	"if((etiss_int8)((etiss_uint8)cast_7 - 0x80) > 0x0)\n"
	"{\n"
		"cast_7 =0x0 + (etiss_uint8)cast_7 ;\n"
	"}\n"
	"rs2_3 = (etiss_int8)cast_7;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"rs2_3 = %#x\\n\",rs2_3); \n"
	#endif	
	"if(rs1_0 <= rs2_0)\n"
	"{\n"
		"choose1 = 255;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_1 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_1 = %#x\\n\",byte_1); \n"
	#endif	
	"if(rs1_1 <= rs2_1)\n"
	"{\n"
		"choose1 = 255;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_2 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_2 = %#x\\n\",byte_2); \n"
	#endif	
	"if(rs1_2 <= rs2_2)\n"
	"{\n"
		"choose1 = 255;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_3 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_3 = %#x\\n\",byte_3); \n"
	#endif	
	"if(rs1_3 <= rs2_3)\n"
	"{\n"
		"choose1 = 255;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	
	"else\n"
	"{\n"
		"choose1 = 0;\n"
		#if RISCV_DEBUG_CALL
		"printf(\"choose1 = %#x\\n\",choose1); \n"
		#endif	
	"}\n"
	"byte_4 = choose1;\n"
	#if RISCV_DEBUG_CALL
	"printf(\"byte_4 = %#x\\n\",byte_4); \n"
	#endif	
	"*((RISCV*)cpu)->X[" + toString(rd) + "] = (((((byte_4 & 255) << 24) | ((byte_3 & 255) << 16)) | ((byte_2 & 255) << 8)) | (byte_1 & 255));\n"
	#if RISCV_DEBUG_CALL
	"printf(\"*((RISCV*)cpu)->X[" + toString(rd) + "] = %#x\\n\",*((RISCV*)cpu)->X[" + toString(rd) + "]); \n"
	#endif	
"}\n"

 			
		"cpu->instructionPointer = " +toString((uint32_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------

