// This file was generated on Tue Nov 24 19:15:14 CET 2020
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
	 	are provided in RV64GCVArchSpecificImp.h 
 
	 8. RV64GCVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.
 
 *********************************************************************************************************************************/

#include "RV64GCVArch.h"
#include "RV64GCVArchSpecificImp.h"

#define RV64GCV_DEBUG_CALL 0
#define RV64GCV_Pipeline1cc 0
using namespace etiss ;
using namespace etiss::instr ;

RV64GCVArch::RV64GCVArch():CPUArch("RV64GCV") 
{
	headers_.insert("Arch/RV64GCV/RV64GCV.h");
}

const std::set<std::string> & RV64GCVArch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

ETISS_CPU * RV64GCVArch::newCPU()
{
    ETISS_CPU * ret = (ETISS_CPU *) new RV64GCV() ;
    resetCPU (ret, 0);
    return ret;
}

void RV64GCVArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
    memset (cpu, 0, sizeof(RV64GCV));
    RV64GCV * rv64gcvcpu = (RV64GCV *) cpu;

    if (startpointer) cpu->instructionPointer = *startpointer;
    else cpu->instructionPointer = 0x0;   //  reference to manual
    cpu->mode = 1;
    cpu->cpuTime_ps = 0;
    cpu->cpuCycleTime_ps = 31250;
    #if RV64GCV_Pipeline1cc
    //Initialize resources measurements
    cpu->resources[0] = "I_CACHE";
    cpu->resources[1] = "IF";
    cpu->resources[2] = "ID";
    cpu->resources[3] = "RegReadPorts";
    cpu->resources[4] = "VregReadPorts";
    cpu->resources[5] = "ALU_";
    cpu->resources[6] = "BRANCH_";
    cpu->resources[7] = "CSRBUF_";
    cpu->resources[8] = "MUL_";
    cpu->resources[9] = "VALU_";
    cpu->resources[10] = "LSU_";
    cpu->resources[11] = "VLSU_";
    cpu->resources[12] = "AMO_";
    cpu->resources[13] = "D_CACHE";
    cpu->resources[14] = "RegWritePorts";
    cpu->resources[15] = "VRegWritePorts";
    for(int i = 0; i < 16; i = i + 1){
    	cpu->resourceUsages[i] = 0;
    	cpu->cycles[i] = 0;
    }
    #endif
    
    // Instantiate the pointers in order to avoid segmentation fault
	for(int i = 0; i < 32; i ++)
	{
		rv64gcvcpu->ins_X[i] = 0;
		rv64gcvcpu->X[i] = & rv64gcvcpu->ins_X[i];
	}
	if(rv64gcvcpu->V == NULL){
		size_t _size = etiss::cfg().get<int>("CPUArch::V_LENGTH", 0);
		rv64gcvcpu->V = new etiss_uint8[ _size ];
	}
	
    // Initialize the registers and state flags;
	rv64gcvcpu->ZERO = 0;
	rv64gcvcpu->X[0] = & (rv64gcvcpu->ZERO);
	rv64gcvcpu->RA = 0;
	rv64gcvcpu->X[1] = & (rv64gcvcpu->RA);
	rv64gcvcpu->SP = 0;
	rv64gcvcpu->X[2] = & (rv64gcvcpu->SP);
	rv64gcvcpu->GP = 0;
	rv64gcvcpu->X[3] = & (rv64gcvcpu->GP);
	rv64gcvcpu->TP = 0;
	rv64gcvcpu->X[4] = & (rv64gcvcpu->TP);
	rv64gcvcpu->T0 = 0;
	rv64gcvcpu->X[5] = & (rv64gcvcpu->T0);
	rv64gcvcpu->T1 = 0;
	rv64gcvcpu->X[6] = & (rv64gcvcpu->T1);
	rv64gcvcpu->T2 = 0;
	rv64gcvcpu->X[7] = & (rv64gcvcpu->T2);
	rv64gcvcpu->S0 = 0;
	rv64gcvcpu->X[8] = & (rv64gcvcpu->S0);
	rv64gcvcpu->S1 = 0;
	rv64gcvcpu->X[9] = & (rv64gcvcpu->S1);
	rv64gcvcpu->A0 = 0;
	rv64gcvcpu->X[10] = & (rv64gcvcpu->A0);
	rv64gcvcpu->A1 = 0;
	rv64gcvcpu->X[11] = & (rv64gcvcpu->A1);
	rv64gcvcpu->A2 = 0;
	rv64gcvcpu->X[12] = & (rv64gcvcpu->A2);
	rv64gcvcpu->A3 = 0;
	rv64gcvcpu->X[13] = & (rv64gcvcpu->A3);
	rv64gcvcpu->A4 = 0;
	rv64gcvcpu->X[14] = & (rv64gcvcpu->A4);
	rv64gcvcpu->A5 = 0;
	rv64gcvcpu->X[15] = & (rv64gcvcpu->A5);
	rv64gcvcpu->A6 = 0;
	rv64gcvcpu->X[16] = & (rv64gcvcpu->A6);
	rv64gcvcpu->A7 = 0;
	rv64gcvcpu->X[17] = & (rv64gcvcpu->A7);
	rv64gcvcpu->S2 = 0;
	rv64gcvcpu->X[18] = & (rv64gcvcpu->S2);
	rv64gcvcpu->S3 = 0;
	rv64gcvcpu->X[19] = & (rv64gcvcpu->S3);
	rv64gcvcpu->S4 = 0;
	rv64gcvcpu->X[20] = & (rv64gcvcpu->S4);
	rv64gcvcpu->S5 = 0;
	rv64gcvcpu->X[21] = & (rv64gcvcpu->S5);
	rv64gcvcpu->S6 = 0;
	rv64gcvcpu->X[22] = & (rv64gcvcpu->S6);
	rv64gcvcpu->S7 = 0;
	rv64gcvcpu->X[23] = & (rv64gcvcpu->S7);
	rv64gcvcpu->S8 = 0;
	rv64gcvcpu->X[24] = & (rv64gcvcpu->S8);
	rv64gcvcpu->S9 = 0;
	rv64gcvcpu->X[25] = & (rv64gcvcpu->S9);
	rv64gcvcpu->S10 = 0;
	rv64gcvcpu->X[26] = & (rv64gcvcpu->S10);
	rv64gcvcpu->S11 = 0;
	rv64gcvcpu->X[27] = & (rv64gcvcpu->S11);
	rv64gcvcpu->T3 = 0;
	rv64gcvcpu->X[28] = & (rv64gcvcpu->T3);
	rv64gcvcpu->T4 = 0;
	rv64gcvcpu->X[29] = & (rv64gcvcpu->T4);
	rv64gcvcpu->T5 = 0;
	rv64gcvcpu->X[30] = & (rv64gcvcpu->T5);
	rv64gcvcpu->T6 = 0;
	rv64gcvcpu->X[31] = & (rv64gcvcpu->T6);
	for (int i = 0; i<4096 ;i++){
		rv64gcvcpu->CSR[i] = 0;
	}
	rv64gcvcpu->CSR[0] = 15;								
	rv64gcvcpu->CSR[256] = 15;								
	rv64gcvcpu->CSR[768] = 15;								
	rv64gcvcpu->CSR[260] = 4294967295;								
	rv64gcvcpu->CSR[769] = 1315077;								
	rv64gcvcpu->CSR[3088] = 3;								
	rv64gcvcpu->CSR[8] = 0;								
	rv64gcvcpu->CSR[9] = 0;								
	rv64gcvcpu->CSR[10] = 0;								
	rv64gcvcpu->CSR[15] = 0;								
	rv64gcvcpu->CSR[3104] = 0;								
	rv64gcvcpu->CSR[3105] = -9223372036854775808;								
	rv64gcvcpu->CSR[3106] = 128;								
	for (int i = 0; i<4 ;i++){
		rv64gcvcpu->FENCE[i] = 0;
	}
	rv64gcvcpu->RES = 0;
	for(size_t i = 0; i < etiss::cfg().get<int>("CPUArch::V_LENGTH", 0); ++i)
	{
		rv64gcvcpu->V[i] = 0;
	}	
}

void RV64GCVArch::deleteCPU(ETISS_CPU *cpu)
{
	delete[] ((RV64GCV *)cpu)->V;
    delete (RV64GCV *) cpu ;
}


/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV64GCVArch::getMaximumInstructionSizeInBytes()
{
    return 8;
}
/**
	@return 2
*/
unsigned RV64GCVArch::getInstructionSizeInBytes()
{
    return 2;
}
/**
	@brief required headers (RV64GCV.h)
*/
const std::set<std::string> & RV64GCVArch::getHeaders() const
{
    return headers_ ;
}
		
void RV64GCVArch::initCodeBlock(etiss::CodeBlock & cb) const
{
    cb.fileglobalCode().insert("#include \"Arch/RV64GCV/RV64GCV.h\"\n");
}

etiss::plugin::gdb::GDBCore & RV64GCVArch::getGDBCore()
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {14}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x80000000)>>31 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x80000000)>>31 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x100000)>>20 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4292870144;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 new_pc = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"new_pc = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"new_pc = %#lx\\n\",new_pc); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			"cpu->instructionPointer = (new_pc & ~1)&0xffffffffffffffff;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294959104;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(*((RV64GCV*)cpu)->X[" + toString(rs1) + "] == *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition sb_rs2_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint8 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,1);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 1 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
static InstructionDefinition addi_rd_rs1_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int32 res = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"res = (etiss_int32)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#x\\n\",res); \n"
				#endif	
				"etiss_int32 cast_1 = res; \n"
				"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294959104;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(*((RV64GCV*)cpu)->X[" + toString(rs1) + "] != *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition sh_rs2_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint16 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,2);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 2 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
static InstructionDefinition fence_i_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"((RV64GCV*)cpu)->FENCE[1] = " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->FENCE[1] = %#lx\\n\",((RV64GCV*)cpu)->FENCE[1]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
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
 			
			"rs_val = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rs_val = %#lx\\n\",rs_val); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"csr_val = ((RV64GCV*)cpu)->CSR[" + toString(csr) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"csr_val = %#lx\\n\",csr_val); \n"
				#endif	
				"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
				"{\n"
					"uAddr = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 256;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 768;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = -9223372036846388805;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = -9223372036853866189;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = -9223372036853866479;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
				"{\n"
					"uAddr = 68;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 324;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 836;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
				"{\n"
					"uAddr = 4;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 260;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 772;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(uAddr != sAddr)\n"
				"{\n"
					"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
					"{\n"
						"writeMask = writeMaskM;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
					"{\n"
						"writeMask = writeMaskS;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
					"{\n"
						"writeMask = writeMaskU;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | (rs_val & writeMask))&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = rs_val;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
					#endif	
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = csr_val;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
				"{\n"
					"uAddr = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 256;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 768;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = -9223372036846388805;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = -9223372036853866189;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = -9223372036853866479;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
				"{\n"
					"uAddr = 68;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 324;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 836;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
				"{\n"
					"uAddr = 4;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 260;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 772;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(uAddr != sAddr)\n"
				"{\n"
					"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
					"{\n"
						"writeMask = writeMaskM;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
					"{\n"
						"writeMask = writeMaskS;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
					"{\n"
						"writeMask = writeMaskU;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | (rs_val & writeMask))&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = rs_val;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
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
static InstructionDefinition blt_rs1_rs2_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294959104;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
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
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_uint8 MEM_offs;\n"
				"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
				"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,1);\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)MEM_offs;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition xori_rd_rs1_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 ^ imm_extended);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294959104;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
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
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_uint16 MEM_offs;\n"
				"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
				"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,2);\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)MEM_offs;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition csrrwi_rd_csr_zimm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 mAddr = 0;\n"
 			"etiss_int64 writeMask = 0;\n"
 			"etiss_int64 writeMaskU = 0;\n"
 			"etiss_int64 sAddr = 0;\n"
 			"etiss_int64 writeMaskS = 0;\n"
 			"etiss_int64 uAddr = 0;\n"
 			"etiss_int64 writeMaskM = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((RV64GCV*)cpu)->CSR[" + toString(csr) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
			"{\n"
				"uAddr = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"uAddr = %#lx\\n\",uAddr); \n"
				#endif	
				"sAddr = 256;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sAddr = %#lx\\n\",sAddr); \n"
				#endif	
				"mAddr = 768;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"mAddr = %#lx\\n\",mAddr); \n"
				#endif	
				"writeMaskM = -9223372036846388805;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
				#endif	
				"writeMaskS = -9223372036853866189;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
				#endif	
				"writeMaskU = -9223372036853866479;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
				#endif	
			"}\n"
			
			"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
			"{\n"
				"uAddr = 68;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"uAddr = %#lx\\n\",uAddr); \n"
				#endif	
				"sAddr = 324;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sAddr = %#lx\\n\",sAddr); \n"
				#endif	
				"mAddr = 836;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"mAddr = %#lx\\n\",mAddr); \n"
				#endif	
				"writeMaskM = 3003;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
				#endif	
				"writeMaskS = 819;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
				#endif	
				"writeMaskU = 273;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
				#endif	
			"}\n"
			
			"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
			"{\n"
				"uAddr = 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"uAddr = %#lx\\n\",uAddr); \n"
				#endif	
				"sAddr = 260;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sAddr = %#lx\\n\",sAddr); \n"
				#endif	
				"mAddr = 772;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"mAddr = %#lx\\n\",mAddr); \n"
				#endif	
				"writeMaskM = 3003;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
				#endif	
				"writeMaskS = 819;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
				#endif	
				"writeMaskU = 273;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
				#endif	
			"}\n"
			
			"if(uAddr != sAddr)\n"
			"{\n"
				"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
				"{\n"
					"writeMask = writeMaskM;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMask = %#lx\\n\",writeMask); \n"
					#endif	
				"}\n"
				
				"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
				"{\n"
					"writeMask = writeMaskS;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMask = %#lx\\n\",writeMask); \n"
					#endif	
				"}\n"
				
				"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
				"{\n"
					"writeMask = writeMaskU;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMask = %#lx\\n\",writeMask); \n"
					#endif	
				"}\n"
				
				"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | ((etiss_uint64)" + toString(zimm) + " & writeMask))&0xffffffffffffffff;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
				#endif	
				"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
				#endif	
				"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = (etiss_uint64)" + toString(zimm) + ";\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
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
static InstructionDefinition bltu_rs1_rs2_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294959104;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(*((RV64GCV*)cpu)->X[" + toString(rs1) + "] < *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 | imm_extended);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
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
 			
			"res = ((RV64GCV*)cpu)->CSR[" + toString(csr) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(zimm) + " != 0)\n"
			"{\n"
				"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
				"{\n"
					"uAddr = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 256;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 768;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = -9223372036846388805;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = -9223372036853866189;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = -9223372036853866479;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
				"{\n"
					"uAddr = 68;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 324;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 836;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
				"{\n"
					"uAddr = 4;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 260;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 772;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(uAddr != sAddr)\n"
				"{\n"
					"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
					"{\n"
						"writeMask = writeMaskM;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
					"{\n"
						"writeMask = writeMaskS;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
					"{\n"
						"writeMask = writeMaskU;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | ((res | (etiss_uint64)" + toString(zimm) + ") & writeMask))&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = (res | (etiss_uint64)" + toString(zimm) + ");\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
					#endif	
				"}\n"
			"}\n"
			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition lwu_rd_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_uint32 MEM_offs;\n"
				"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
				"exception = (*(system->dread))(system->handle,cpu,offs,tmpbuf,4);\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)MEM_offs;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition bgeu_rs1_rs2_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x1000)>>12 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294959104;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(*((RV64GCV*)cpu)->X[" + toString(rs1) + "] >= *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 4;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 & imm_extended);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
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
 			
			"res = ((RV64GCV*)cpu)->CSR[" + toString(csr) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(" + toString(zimm) + " != 0)\n"
			"{\n"
				"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
				"{\n"
					"uAddr = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 256;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 768;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = -9223372036846388805;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = -9223372036853866189;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = -9223372036853866479;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
				"{\n"
					"uAddr = 68;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 324;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 836;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
				"{\n"
					"uAddr = 4;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 260;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 772;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(uAddr != sAddr)\n"
				"{\n"
					"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
					"{\n"
						"writeMask = writeMaskM;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
					"{\n"
						"writeMask = writeMaskS;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
					"{\n"
						"writeMask = writeMaskU;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | ((res & ~(etiss_uint64)" + toString(zimm) + ") & writeMask))&0xffffffffffffffff&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = (res & ~(etiss_uint64)" + toString(zimm) + ")&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
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
static InstructionDefinition lw_rd_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition sw_rs2_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
static InstructionDefinition slti_rd_rs1_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = imm_extended; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
				"}\n"
				"if((etiss_int64)cast_1 < (etiss_int64)cast_0)\n"
				"{\n"
					"choose1 = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"choose1 = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7, 5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
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
 			
			"xrd = ((RV64GCV*)cpu)->CSR[" + toString(csr) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"xrd = %#lx\\n\",xrd); \n"
			#endif	
			"xrs1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"xrs1 = %#lx\\n\",xrs1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = xrd;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(" + toString(rs1) + " != 0)\n"
			"{\n"
				"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
				"{\n"
					"uAddr = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 256;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 768;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = -9223372036846388805;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = -9223372036853866189;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = -9223372036853866479;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
				"{\n"
					"uAddr = 68;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 324;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 836;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
				"{\n"
					"uAddr = 4;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 260;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 772;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(uAddr != sAddr)\n"
				"{\n"
					"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
					"{\n"
						"writeMask = writeMaskM;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
					"{\n"
						"writeMask = writeMaskS;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
					"{\n"
						"writeMask = writeMaskU;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | ((xrd | xrs1) & writeMask))&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = (xrd | xrs1);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
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
static InstructionDefinition sltiu_rd_rs1_imm(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 full_imm = 0;\n"
 			"etiss_int8 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = imm_extended; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"full_imm = (etiss_int64)cast_0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"full_imm = %#lx\\n\",full_imm); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if((etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs1) + "] < (etiss_uint64)full_imm)\n"
				"{\n"
					"choose1 = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"choose1 = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7, 5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
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
 			
			"xrd = ((RV64GCV*)cpu)->CSR[" + toString(csr) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"xrd = %#lx\\n\",xrd); \n"
			#endif	
			"xrs1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"xrs1 = %#lx\\n\",xrs1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = xrd;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(" + toString(rs1) + " != 0)\n"
			"{\n"
				"if(((" + toString(csr) + " == 0) || (" + toString(csr) + " == 256)) || (" + toString(csr) + " == 768))\n"
				"{\n"
					"uAddr = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 256;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 768;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = -9223372036846388805;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = -9223372036853866189;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = -9223372036853866479;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 68) || (" + toString(csr) + " == 324)) || (" + toString(csr) + " == 836))\n"
				"{\n"
					"uAddr = 68;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 324;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 836;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(((" + toString(csr) + " == 4) || (" + toString(csr) + " == 260)) || (" + toString(csr) + " == 772))\n"
				"{\n"
					"uAddr = 4;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"uAddr = %#lx\\n\",uAddr); \n"
					#endif	
					"sAddr = 260;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"sAddr = %#lx\\n\",sAddr); \n"
					#endif	
					"mAddr = 772;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"mAddr = %#lx\\n\",mAddr); \n"
					#endif	
					"writeMaskM = 3003;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskM = %#lx\\n\",writeMaskM); \n"
					#endif	
					"writeMaskS = 819;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskS = %#lx\\n\",writeMaskS); \n"
					#endif	
					"writeMaskU = 273;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"writeMaskU = %#lx\\n\",writeMaskU); \n"
					#endif	
				"}\n"
				
				"if(uAddr != sAddr)\n"
				"{\n"
					"if(((RV64GCV*)cpu)->CSR[3088] == 3)\n"
					"{\n"
						"writeMask = writeMaskM;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 1)\n"
					"{\n"
						"writeMask = writeMaskS;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"if(((RV64GCV*)cpu)->CSR[3088] == 0)\n"
					"{\n"
						"writeMask = writeMaskU;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"writeMask = %#lx\\n\",writeMask); \n"
						#endif	
					"}\n"
					
					"((RV64GCV*)cpu)->CSR[uAddr] = ((((RV64GCV*)cpu)->CSR[uAddr] & ~writeMask) | ((xrd & ~xrs1) & writeMask))&0xffffffffffffffff&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[uAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[uAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[sAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[sAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[sAddr]); \n"
					#endif	
					"((RV64GCV*)cpu)->CSR[mAddr] = ((RV64GCV*)cpu)->CSR[uAddr];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[mAddr] = %#lx\\n\",((RV64GCV*)cpu)->CSR[mAddr]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = (xrd & ~xrs1)&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[" + toString(csr) + "] = %#lx\\n\",((RV64GCV*)cpu)->CSR[" + toString(csr) + "]); \n"
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
static InstructionDefinition ld_rd_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition sd_rs2_imm_rs1_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 offs = 0;\n"
 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"offs = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
static InstructionDefinition slli_rd_rs1_shamt(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] << " + toString(shamt) + ");\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] >> " + toString(shamt) + ");\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition vadd_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vadd.vv",
 		(uint32_t)0x57,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vadd.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vadd_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vadd_vi_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vadd.vi",
 		(uint32_t)0x3057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vadd.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vadd_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vadd_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vadd.vx",
 		(uint32_t)0x4057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vadd.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vadd_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition srai_rd_rs1_shamt(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 >> " + toString(shamt) + ");\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition vmv_x_s_rd_vs2(
 		ISA32_RV64GCV,
 		"vmv.x.s",
 		(uint32_t)0x42004057,
 		(uint32_t) 0xfe0ff07f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rd = 0;
 		static BitArrayRange R_rd_0 (11,7);
 		etiss_uint64 rd_0 = R_rd_0.read(ba);
 		rd += rd_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmv.x.s\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"ret = vmv_xs(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(rd) + ", " + toString(vs2) + ", _vlen, _vl, 64);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"ret = %#lx\\n\",ret); \n"
				#endif	
				"if(ret != 0)\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
					#endif	
					"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
				"}\n"
				
				"else\n"
				"{\n"
					"((RV64GCV*)cpu)->CSR[8] = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
					#endif	
				"}\n"
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
static InstructionDefinition vmv_s_x_vd_rs1(
 		ISA32_RV64GCV,
 		"vmv.s.x",
 		(uint32_t)0x42004057,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmv.s.x\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmv_sx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vd) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition add_rd_rs1_rs2(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = *((RV64GCV*)cpu)->X[" + toString(rs1) + "] + *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"res = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) + (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#x\\n\",res); \n"
				#endif	
				"etiss_int32 cast_0 = res; \n"
				"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] << (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 64 - 1));\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"sh_val = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) << " + toString(shamt) + ");\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sh_val = %#x\\n\",sh_val); \n"
				#endif	
				"etiss_int32 cast_0 = sh_val; \n"
				"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			"etiss_uint32 count = 0;\n"
 			"etiss_int32 mask = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"mask = 31;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"mask = %#x\\n\",mask); \n"
				#endif	
				"count = ((*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) & mask);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"count = %#x\\n\",count); \n"
				#endif	
				"sh_val = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) << count);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sh_val = %#x\\n\",sh_val); \n"
				#endif	
				"etiss_int32 cast_0 = sh_val; \n"
				"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 choose1 = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
				"}\n"
				"if((etiss_int64)cast_1 < (etiss_int64)cast_0)\n"
				"{\n"
					"choose1 = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"choose1 = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 choose1 = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if((etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs1) + "] < (etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
				"{\n"
					"choose1 = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"choose1 = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"choose1 = %#x\\n\",choose1); \n"
					#endif	
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = choose1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] ^ *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] >> (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 64 - 1));\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"sh_val = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) >> " + toString(shamt) + ");\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sh_val = %#x\\n\",sh_val); \n"
				#endif	
				"etiss_int32 cast_0 = sh_val; \n"
				"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			"etiss_uint32 count = 0;\n"
 			"etiss_int32 mask = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"mask = 31;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"mask = %#x\\n\",mask); \n"
				#endif	
				"count = ((*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) & mask);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"count = %#x\\n\",count); \n"
				#endif	
				"sh_val = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) >> count);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sh_val = %#x\\n\",sh_val); \n"
				#endif	
				"etiss_int32 cast_0 = sh_val; \n"
				"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] | *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"((RV64GCV*)cpu)->CSR[3088] = 0;\n"//PRIVLV=0
			"((RV64GCV*)cpu)->CSR[0] ^= ((etiss_uint32)((((RV64GCV*)cpu)->CSR[0] & 0x10)>>4)) ^ (((RV64GCV*)cpu)->CSR[0] & 0x1);\n"//UIE=UPIE
			"cpu->instructionPointer = ((RV64GCV*)cpu)->CSR[65];\n"//PC=UEPC
			"((RV64GCV*)cpu)->CSR[768]= ((RV64GCV*)cpu)->CSR[0];\n"//keep MSTATUS synchronous to USTATUS
			"((RV64GCV*)cpu)->CSR[256]=((RV64GCV*)cpu)->CSR[0];\n"//keep SSTATUS synchronous to USTATUS
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sub_rd_rs1_rs2(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = *((RV64GCV*)cpu)->X[" + toString(rs1) + "] - *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"res = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) - (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#x\\n\",res); \n"
				#endif	
				"etiss_int32 cast_0 = res; \n"
				"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_0 >> (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 64 - 1));\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 sh_val = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"sh_val = ((etiss_int32)cast_0 >> " + toString(shamt) + ");\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sh_val = %#x\\n\",sh_val); \n"
				#endif	
				"etiss_int32 cast_1 = sh_val; \n"
				"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 sh_val = 0;\n"
 			"etiss_uint32 count = 0;\n"
 			"etiss_int32 mask = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"mask = 31;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"mask = %#x\\n\",mask); \n"
				#endif	
				"count = ((*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) & mask);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"count = %#x\\n\",count); \n"
				#endif	
				"etiss_int64 cast_0 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"sh_val = ((etiss_int32)cast_0 >> count);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"sh_val = %#x\\n\",sh_val); \n"
				#endif	
				"etiss_int32 cast_1 = sh_val; \n"
				"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition fence_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"((RV64GCV*)cpu)->FENCE[0] = ((" + toString(pred) + " << 4) | " + toString(succ) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->FENCE[0] = %#lx\\n\",((RV64GCV*)cpu)->FENCE[0]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"((RV64GCV*)cpu)->CSR[3088] = (((RV64GCV*)cpu)->CSR[256] & 0x100)>>8;\n"//PRIVLV=SPP
			"((RV64GCV*)cpu)->CSR[256] ^= (((RV64GCV*)cpu)->CSR[256] & 0x100);\n"//SPP=0
			"((RV64GCV*)cpu)->CSR[256] ^= ((etiss_uint32)((((RV64GCV*)cpu)->CSR[256] & 0x20)>>4)) ^ (((RV64GCV*)cpu)->CSR[256] & 0x2);\n"//SIE=SPIE
			"cpu->instructionPointer = ((RV64GCV*)cpu)->CSR[321];\n"//PC=SEPC
			"((RV64GCV*)cpu)->CSR[768]= ((RV64GCV*)cpu)->CSR[256];\n"//keep MSTATUS synchronous to SSTATUS
			"((RV64GCV*)cpu)->CSR[0]=((RV64GCV*)cpu)->CSR[256];\n"//keep USTATUS synchronous to SSTATUS
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition wfi_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
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
static InstructionDefinition mret_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"((RV64GCV*)cpu)->CSR[3088] = (((RV64GCV*)cpu)->CSR[768] & 0x1800)>>11;\n"//PRIVLV=MPP
			"((RV64GCV*)cpu)->CSR[768] ^= (((RV64GCV*)cpu)->CSR[768] & 0x1800);\n"//MPP=0
			"((RV64GCV*)cpu)->CSR[768] ^= ((etiss_uint32)((((RV64GCV*)cpu)->CSR[768] & 0x80)>>4)) ^ (((RV64GCV*)cpu)->CSR[768] & 0x8);\n"//MIE=MPIE
			"cpu->instructionPointer = ((RV64GCV*)cpu)->CSR[833];\n"//PC=MEPC
			"((RV64GCV*)cpu)->CSR[0]= ((RV64GCV*)cpu)->CSR[768];\n"//keep USTATUS synchronous to MSTATUS
			"((RV64GCV*)cpu)->CSR[256]=((RV64GCV*)cpu)->CSR[768];\n"//keep SSTATUS synchronous to MSTATUS
		"cpu->instructionPointer = (uint64_t)cpu->instructionPointer; \n"
		
		"return 0;\n"
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition sfence_vma_(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"((RV64GCV*)cpu)->FENCE[2] = " + toString(rs1) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->FENCE[2] = %#lx\\n\",((RV64GCV*)cpu)->FENCE[2]); \n"
			#endif	
			"((RV64GCV*)cpu)->FENCE[3] = " + toString(rs2) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->FENCE[3] = %#lx\\n\",((RV64GCV*)cpu)->FENCE[3]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"res = ((etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs1) + "] * (etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#lx\\n\",res); \n"
				#endif	
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) * (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff)); \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 res = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
				"}\n"
				"res = ((etiss_int64)cast_1 * (etiss_int64)cast_0);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#lx\\n\",res); \n"
				#endif	
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)(res >> 64);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"res = ((etiss_int64)cast_0 * (etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#lx\\n\",res); \n"
				#endif	
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)(res >> 64);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 res = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"res = ((etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs1) + "] * (etiss_uint64)*((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#lx\\n\",res); \n"
				#endif	
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_uint64)(res >> 64);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 XLM1 = 0;\n"
 			"etiss_int64 MMIN = 0;\n"
 			"etiss_int64 M1 = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if(*((RV64GCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
				"{\n"
					"M1 =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"M1 = %#lx\\n\",M1); \n"
					#endif	
					"XLM1 = 64 - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"XLM1 = %#x\\n\",XLM1); \n"
					#endif	
					"ONE = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"ONE = %#lx\\n\",ONE); \n"
					#endif	
					"MMIN = (ONE << XLM1);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"MMIN = %#lx\\n\",MMIN); \n"
					#endif	
					"if((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] == MMIN) && (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] == M1))\n"
					"{\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = MMIN;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
						"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
						"}\n"
						"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
						"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
						"}\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_1 / (etiss_int64)cast_0);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
				"}\n"
				
				"else\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 MMIN = 0;\n"
 			"etiss_int32 M1 = 0;\n"
 			"etiss_int32 ONE = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if(*((RV64GCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
				"{\n"
					"M1 =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"M1 = %#x\\n\",M1); \n"
					#endif	
					"ONE = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"ONE = %#x\\n\",ONE); \n"
					#endif	
					"MMIN = (ONE << 31);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"MMIN = %#x\\n\",MMIN); \n"
					#endif	
					"if(((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) == MMIN) && ((*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) == M1))\n"
					"{\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ( - 1 << 31);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"etiss_int64 cast_0 = (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff); \n"
						"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
						"}\n"
						"etiss_int64 cast_1 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
						"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
						"}\n"
						"etiss_int64 cast_2 = ((etiss_int64)cast_1 / (etiss_int64)cast_0); \n"
						"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
						"}\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_2;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
				"}\n"
				
				"else\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if(*((RV64GCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] / *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if((*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) != 0)\n"
				"{\n"
					"etiss_int64 cast_0 = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) / (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff)); \n"
					"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
					"{\n"
						"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
					"}\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 XLM1 = 0;\n"
 			"etiss_int64 MMIN = 0;\n"
 			"etiss_int64 M1 = 0;\n"
 			"etiss_int64 ONE = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if(*((RV64GCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
				"{\n"
					"M1 =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"M1 = %#lx\\n\",M1); \n"
					#endif	
					"XLM1 = 64 - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"XLM1 = %#x\\n\",XLM1); \n"
					#endif	
					"ONE = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"ONE = %#lx\\n\",ONE); \n"
					#endif	
					"MMIN = (ONE << XLM1);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"MMIN = %#lx\\n\",MMIN); \n"
					#endif	
					"if((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] == MMIN) && (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] == M1))\n"
					"{\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = 0;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
						"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
						"}\n"
						"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
						"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
						"}\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = ((etiss_int64)cast_1 % (etiss_int64)cast_0);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
				"}\n"
				
				"else\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int32 MMIN = 0;\n"
 			"etiss_int32 M1 = 0;\n"
 			"etiss_int32 ONE = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if(*((RV64GCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
				"{\n"
					"M1 =  - 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"M1 = %#x\\n\",M1); \n"
					#endif	
					"ONE = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"ONE = %#x\\n\",ONE); \n"
					#endif	
					"MMIN = (ONE << 31);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"MMIN = %#x\\n\",MMIN); \n"
					#endif	
					"if(((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) == MMIN) && (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] == M1))\n"
					"{\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = 0;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"etiss_int64 cast_0 = (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff); \n"
						"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
						"}\n"
						"etiss_int64 cast_1 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
						"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
						"}\n"
						"etiss_int64 cast_2 = ((etiss_int64)cast_1 % (etiss_int64)cast_0); \n"
						"if((etiss_int64)((etiss_uint64)cast_2 - 0x8000000000000000) > 0x0)\n"
						"{\n"
							"cast_2 =0x0 + (etiss_uint64)cast_2 ;\n"
						"}\n"
						"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_2;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
						#endif	
					"}\n"
				"}\n"
				
				"else\n"
				"{\n"
					"etiss_int64 cast_3 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
					"if((etiss_int64)((etiss_uint64)cast_3 - 0x8000000000000000) > 0x0)\n"
					"{\n"
						"cast_3 =0x0 + (etiss_uint64)cast_3 ;\n"
					"}\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_3;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if(*((RV64GCV*)cpu)->X[" + toString(rs2) + "] != 0)\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] % *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {8}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"if((*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff) != 0)\n"
				"{\n"
					"etiss_int64 cast_0 = ((*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff) % (*((RV64GCV*)cpu)->X[" + toString(rs2) + "] & 0xffffffff)); \n"
					"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
					"{\n"
						"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
					"}\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"etiss_int64 cast_1 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
					"if((etiss_int64)((etiss_uint64)cast_1 - 0x8000000000000000) > 0x0)\n"
					"{\n"
						"cast_1 =0x0 + (etiss_uint64)cast_1 ;\n"
					"}\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
static InstructionDefinition lr_w_rd_rs1(
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
				#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
				"((RV64GCV*)cpu)->RES = offs;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
				#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
				"((RV64GCV*)cpu)->RES = offs;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {12, 13}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"if(offs == ((RV64GCV*)cpu)->RES)\n"
			"{\n"
				"etiss_uint32 MEM_offs;\n"
				"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
				"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
				#endif	
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {12, 13}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"if(offs == ((RV64GCV*)cpu)->RES)\n"
			"{\n"
				"etiss_uint64 MEM_offs;\n"
				"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
				"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
				#endif	
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = 0;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = 1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
					#endif	
				"}\n"
				
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = res1 + *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = res + *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = (res1 ^ *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = (res ^ *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = (res1 & *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = (res & *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = (res1 | *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"res2 = (res | *((RV64GCV*)cpu)->X[" + toString(rs2) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
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
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
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
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
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
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"etiss_int64 cast_1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "]; \n"
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
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(res1 > *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#lx\\n\",res); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(res > *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(res1 < *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA32_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {12, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			"etiss_int64 res1 = 0;\n"
 			"etiss_uint64 res2 = 0;\n"
 			"etiss_uint64 choose1 = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
			#if RV64GCV_DEBUG_CALL
			"printf(\"res1 = %#lx\\n\",res1); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"if(res1 < *((RV64GCV*)cpu)->X[" + toString(rs2) + "])\n"
			"{\n"
				"choose1 = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = res1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"res2 = choose1;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res2 = %#lx\\n\",res2); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = res2;\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
static InstructionDefinition c_addi4spn_rd_imm(
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(imm) + " == 0)\n"
			"{\n"
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = *((RV64GCV*)cpu)->X[2] + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294967232;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[" + toString(rs1) + "]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"*((RV64GCV*)cpu)->X[" + toString(rs1) + "] = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rs1) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rs1) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"if(" + toString(rs1) + " == 0)\n"
			"{\n"
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"*((RV64GCV*)cpu)->X[" + toString(rs1) + "] = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] << " + toString(shamt) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rs1) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rs1) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
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
			"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {14}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294967232;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rd) + " == 0)\n"
			"{\n"
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
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
			"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x100)>>8 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294966784;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(*((RV64GCV*)cpu)->X[" + toString(rs1) + " + 8] == 0)\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 2;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint32 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,4);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 4 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int32 res = 0;\n"
 			
			"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294967232;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(" + toString(rs1) + " != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = (*((RV64GCV*)cpu)->X[" + toString(rs1) + "] & 0xffffffff); \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"res = (etiss_int32)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"res = %#x\\n\",res); \n"
				#endif	
				"etiss_int32 cast_1 = res; \n"
				"if((etiss_int32)((etiss_uint32)cast_1 - 0x80000000) > 0x0)\n"
				"{\n"
					"cast_1 =0x0 + (etiss_uint32)cast_1 ;\n"
				"}\n"
				"*((RV64GCV*)cpu)->X[" + toString(rs1) + "] = (etiss_int64)cast_1;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rs1) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rs1) + "]); \n"
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
static InstructionDefinition c_lui_rd_imm(
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {14}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x20000)>>17 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294705152;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
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
			
			"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x200)>>9 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294966272;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[2]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"*((RV64GCV*)cpu)->X[2] = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[2] = %#lx\\n\",*((RV64GCV*)cpu)->X[2]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
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
			"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}, {14}};\n"
			"etiss_uint32 num_stages = 5;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
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
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = (etiss_int64)cast_0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rs1_idx = 0;\n"
 			
			"rs1_idx = " + toString(rs1) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
			#endif	
			"*((RV64GCV*)cpu)->X[rs1_idx] = (*((RV64GCV*)cpu)->X[rs1_idx] >> " + toString(shamt) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rs1_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rs1_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rs1_idx = 0;\n"
 			
			"rs1_idx = " + toString(rs1) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[rs1_idx]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"*((RV64GCV*)cpu)->X[rs1_idx] = ((etiss_int64)cast_0 >> " + toString(shamt) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rs1_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rs1_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int8 rs1_idx = 0;\n"
 			
			"if((" + toString(imm) + " & 0x20)>>5 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294967232;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"rs1_idx = " + toString(rs1) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rs1_idx = %#x\\n\",rs1_idx); \n"
			#endif	
			"etiss_int64 cast_0 = *((RV64GCV*)cpu)->X[rs1_idx]; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"*((RV64GCV*)cpu)->X[rs1_idx] = ((etiss_int64)cast_0 & imm_extended);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rs1_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rs1_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
			"rd_idx = " + toString(rd) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
			#endif	
			"*((RV64GCV*)cpu)->X[rd_idx] = *((RV64GCV*)cpu)->X[rd_idx] - *((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rd_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rd_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
			"rd_idx = " + toString(rd) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
			#endif	
			"*((RV64GCV*)cpu)->X[rd_idx] = (*((RV64GCV*)cpu)->X[rd_idx] ^ *((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rd_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rd_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
			"rd_idx = " + toString(rd) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
			#endif	
			"*((RV64GCV*)cpu)->X[rd_idx] = (*((RV64GCV*)cpu)->X[rd_idx] | *((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rd_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rd_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int8 rd_idx = 0;\n"
 			
			"rd_idx = " + toString(rd) + " + 8;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"rd_idx = %#x\\n\",rd_idx); \n"
			#endif	
			"*((RV64GCV*)cpu)->X[rd_idx] = (*((RV64GCV*)cpu)->X[rd_idx] & *((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[rd_idx] = %#lx\\n\",*((RV64GCV*)cpu)->X[rd_idx]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"cpu->instructionPointer = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = *((RV64GCV*)cpu)->X[" + toString(rd) + "] + *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			
			"*((RV64GCV*)cpu)->X[1] = " +toString((uint64_t)ic.current_address_)+"ULL  + 2;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[1] = %#lx\\n\",*((RV64GCV*)cpu)->X[1]); \n"
			#endif	
			"cpu->instructionPointer = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1};\n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
			"res = (*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] & 0xffffffff) - (*((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8] & 0xffffffff);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#x\\n\",res); \n"
			#endif	
			"etiss_int32 cast_0 = res; \n"
			"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
			"}\n"
			"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint32 res = 0;\n"
 			
			"res = (*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] & 0xffffffff) + (*((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8] & 0xffffffff);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"res = %#x\\n\",res); \n"
			#endif	
			"etiss_int32 cast_0 = res; \n"
			"if((etiss_int32)((etiss_uint32)cast_0 - 0x80000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint32)cast_0 ;\n"
			"}\n"
			"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = (etiss_int64)cast_0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + " + 8]); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			
			"if((" + toString(imm) + " & 0x800)>>11 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294963200;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
			"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
			"{\n"
				"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
			"}\n"
			"cpu->instructionPointer = (etiss_int64)cast_0 + imm_extended;\n"
			#if RV64GCV_DEBUG_CALL
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
static InstructionDefinition c_bnez_8_rs1_imm(
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {6, 5}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_int64 imm_extended = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"if((" + toString(imm) + " & 0x100)>>8 == 0)\n"
			"{\n"
				"imm_extended = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"imm_extended = 4294967295;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#x\\n\",imm_extended); \n"
				#endif	
				"imm_extended = (imm_extended << 32);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
				"imm_extended = imm_extended + 4294966784;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
				#endif	
			"}\n"
			"imm_extended = imm_extended + " + toString(imm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"imm_extended = %#lx\\n\",imm_extended); \n"
			#endif	
			"if(*((RV64GCV*)cpu)->X[" + toString(rs1) + " + 8] != 0)\n"
			"{\n"
				"etiss_int64 cast_0 = " +toString((uint64_t)ic.current_address_)+"ULL ; \n"
				"if((etiss_int64)((etiss_uint64)cast_0 - 0x8000000000000000) > 0x0)\n"
				"{\n"
					"cast_0 =0x0 + (etiss_uint64)cast_0 ;\n"
				"}\n"
				"choose1 = (etiss_int64)cast_0 + imm_extended;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			// Explicit assignment to PC
			"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 2 ))+"ULL; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"choose1 = " +toString((uint64_t)ic.current_address_)+"ULL  + 2;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"choose1 = %#lx\\n\",choose1); \n"
				#endif	
			"}\n"
			"cpu->instructionPointer = choose1;\n"
			#if RV64GCV_DEBUG_CALL
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[" + toString(rs1) + " + 8] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + " + 8];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
 		ISA16_RV64GCV,
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
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {5}, {10, 13}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 offs = 0;\n"
 			
			"offs = *((RV64GCV*)cpu)->X[2] + " + toString(uimm) + ";\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"offs = %#lx\\n\",offs); \n"
			#endif	
			"etiss_uint64 MEM_offs;\n"
			"tmpbuf = (etiss_uint8 *)&MEM_offs;\n"
			"MEM_offs = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			"exception = (*(system->dwrite))(system->handle,cpu,offs,tmpbuf,8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"MEM_offs = %#x\\n\",MEM_offs); \n"
			#endif	
			"if((offs + 8 > ((RV64GCV*)cpu)->RES) && (offs < 8 + ((RV64GCV*)cpu)->RES))\n"
			"{\n"
				"((RV64GCV*)cpu)->RES = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->RES = %#lx\\n\",((RV64GCV*)cpu)->RES); \n"
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
static InstructionDefinition vsetvli_rd_rs1_zimm(
 		ISA32_RV64GCV,
 		"vsetvli",
 		(uint32_t)0x7057,
 		(uint32_t) 0x8000707f,
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
 		etiss_uint64 zimm = 0;
 		static BitArrayRange R_zimm_0 (30,20);
 		etiss_uint64 zimm_0 = R_zimm_0.read(ba);
 		zimm += zimm_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
 		partInit.getRegisterDependencies().add(reg_name[rs1],64);
  		partInit.getAffectedRegisters().add(reg_name[rd],64);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsetvli\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint8 vta = 0;\n"
 			"etiss_int64 _vlmax = 0;\n"
 			"etiss_uint8 sew = 0;\n"
 			"etiss_int64 _avl = 0;\n"
 			"etiss_int64 _vl = 0;\n"
 			"etiss_int64 _illmask = 0;\n"
 			"etiss_uint64 vlen = 0;\n"
 			"etiss_uint8 lmul = 0;\n"
 			"etiss_uint8 vma = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			
			"sew = vtype_extractSEW(" + toString(zimm) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"sew = %#x\\n\",sew); \n"
			#endif	
			"lmul = vtype_extractLMUL(" + toString(zimm) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"lmul = %#x\\n\",lmul); \n"
			#endif	
			"vta = vtype_extractTA(" + toString(zimm) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"vta = %#x\\n\",vta); \n"
			#endif	
			"vma = vtype_extractMA(" + toString(zimm) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"vma = %#x\\n\",vma); \n"
			#endif	
			"_vlmax = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
			#endif	
			"_illmask = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_illmask = %#lx\\n\",_illmask); \n"
			#endif	
			"vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"vlen = %#lx\\n\",vlen); \n"
			#endif	
			"if(lmul & 4)\n"
			"{\n"
				"_illmask = (1 << 64 - 1);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_illmask = %#lx\\n\",_illmask); \n"
				#endif	
				"if(lmul == 6)\n"
				"{\n"
					"_vlmax = ((vlen / (8 << sew)) / 4);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"if(lmul == 7)\n"
					"{\n"
						"_vlmax = ((vlen / (8 << sew)) / 2);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"_vlmax = ((vlen / (8 << sew)) / 8);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
						#endif	
					"}\n"
				"}\n"
			"}\n"
			
			"else\n"
			"{\n"
				"_illmask = (0 << 64 - 1);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_illmask = %#lx\\n\",_illmask); \n"
				#endif	
				"if(lmul == 0)\n"
				"{\n"
					"_vlmax = (vlen / (8 << sew));\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"if(lmul == 1)\n"
					"{\n"
						"_vlmax = ((vlen / (8 << sew)) * 2);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"if(lmul == 2)\n"
						"{\n"
							"_vlmax = ((vlen / (8 << sew)) * 4);\n"
							#if RV64GCV_DEBUG_CALL
							"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
							#endif	
						"}\n"
						
						"else\n"
						"{\n"
							"if(lmul == 3)\n"
							"{\n"
								"_vlmax = ((vlen / (8 << sew)) * 8);\n"
								#if RV64GCV_DEBUG_CALL
								"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
								#endif	
							"}\n"
							
						"}\n"
					"}\n"
				"}\n"
			"}\n"
			"_avl = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_avl = %#lx\\n\",_avl); \n"
			#endif	
			"if(" + toString(rs1) + " != 0)\n"
			"{\n"
				"_avl = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_avl = %#lx\\n\",_avl); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"_avl = ~0&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_avl = %#lx\\n\",_avl); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"_avl = ((RV64GCV*)cpu)->CSR[3104];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_avl = %#lx\\n\",_avl); \n"
					#endif	
				"}\n"
			"}\n"
			"_vl = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"if(_avl <= _vlmax)\n"
			"{\n"
				"_vl = _avl;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_vl = %#lx\\n\",_vl); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(_avl >= (2 * _vlmax))\n"
				"{\n"
					"_vl = _vlmax;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vl = %#lx\\n\",_vl); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"if(_avl & 2)\n"
					"{\n"
						"choose1 = (_avl / 2) + 1;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"choose1 = %#lx\\n\",choose1); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"choose1 = (_avl / 2);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"choose1 = %#lx\\n\",choose1); \n"
						#endif	
					"}\n"
					"_vl = choose1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vl = %#lx\\n\",_vl); \n"
					#endif	
				"}\n"
			"}\n"
			"((RV64GCV*)cpu)->CSR[3104] = _vl;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->CSR[3104] = %#lx\\n\",((RV64GCV*)cpu)->CSR[3104]); \n"
			#endif	
			"((RV64GCV*)cpu)->CSR[3105] = (_illmask | " + toString(zimm) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->CSR[3105] = %#lx\\n\",((RV64GCV*)cpu)->CSR[3105]); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = _vl;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"((RV64GCV*)cpu)->CSR[8] = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition vsetvl_rd_rs1_rs2(
 		ISA32_RV64GCV,
 		"vsetvl",
 		(uint32_t)0x80007057,
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
 	partInit.code() = std::string("//vsetvl\n")+
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {7}, {14}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint8 vta = 0;\n"
 			"etiss_int64 _vlmax = 0;\n"
 			"etiss_uint8 sew = 0;\n"
 			"etiss_int64 _avl = 0;\n"
 			"etiss_int64 _vl = 0;\n"
 			"etiss_uint16 zimm = 0;\n"
 			"etiss_int64 _illmask = 0;\n"
 			"etiss_uint8 lmul = 0;\n"
 			"etiss_uint8 vma = 0;\n"
 			"etiss_int64 choose1 = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"zimm = *((RV64GCV*)cpu)->X[" + toString(rs2) + "];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"zimm = %#x\\n\",zimm); \n"
			#endif	
			"sew = vtype_extractSEW(zimm);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"sew = %#x\\n\",sew); \n"
			#endif	
			"lmul = vtype_extractLMUL(zimm);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"lmul = %#x\\n\",lmul); \n"
			#endif	
			"vta = vtype_extractTA(zimm);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"vta = %#x\\n\",vta); \n"
			#endif	
			"vma = vtype_extractMA(zimm);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"vma = %#x\\n\",vma); \n"
			#endif	
			"_vlmax = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
			#endif	
			"_illmask = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_illmask = %#lx\\n\",_illmask); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"if(lmul & 4)\n"
			"{\n"
				"_illmask = (1 << 64 - 1);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_illmask = %#lx\\n\",_illmask); \n"
				#endif	
				"if(lmul == 6)\n"
				"{\n"
					"_vlmax = ((_vlen / (8 << sew)) / 4);\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"if(lmul == 7)\n"
					"{\n"
						"_vlmax = ((_vlen / (8 << sew)) / 2);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"_vlmax = ((_vlen / (8 << sew)) / 8);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
						#endif	
					"}\n"
				"}\n"
			"}\n"
			
			"else\n"
			"{\n"
				"_illmask = (0 << 64 - 1);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_illmask = %#lx\\n\",_illmask); \n"
				#endif	
				"if(lmul == 0)\n"
				"{\n"
					"_vlmax = (_vlen / (8 << sew));\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"if(lmul == 1)\n"
					"{\n"
						"_vlmax = ((_vlen / (8 << sew)) * 2);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"if(lmul == 2)\n"
						"{\n"
							"_vlmax = ((_vlen / (8 << sew)) * 4);\n"
							#if RV64GCV_DEBUG_CALL
							"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
							#endif	
						"}\n"
						
						"else\n"
						"{\n"
							"if(lmul == 3)\n"
							"{\n"
								"_vlmax = ((_vlen / (8 << sew)) * 8);\n"
								#if RV64GCV_DEBUG_CALL
								"printf(\"_vlmax = %#lx\\n\",_vlmax); \n"
								#endif	
							"}\n"
							
						"}\n"
					"}\n"
				"}\n"
			"}\n"
			"_avl = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_avl = %#lx\\n\",_avl); \n"
			#endif	
			"if(" + toString(rs1) + " != 0)\n"
			"{\n"
				"_avl = *((RV64GCV*)cpu)->X[" + toString(rs1) + "];\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_avl = %#lx\\n\",_avl); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(" + toString(rd) + " != 0)\n"
				"{\n"
					"_avl = ~0&0xffffffffffffffff;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_avl = %#lx\\n\",_avl); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"_avl = ((RV64GCV*)cpu)->CSR[3104];\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_avl = %#lx\\n\",_avl); \n"
					#endif	
				"}\n"
			"}\n"
			"_vl = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"if(_avl <= _vlmax)\n"
			"{\n"
				"_vl = _avl;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"_vl = %#lx\\n\",_vl); \n"
				#endif	
			"}\n"
			
			"else\n"
			"{\n"
				"if(_avl >= (2 * _vlmax))\n"
				"{\n"
					"_vl = _vlmax;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vl = %#lx\\n\",_vl); \n"
					#endif	
				"}\n"
				
				"else\n"
				"{\n"
					"if(_avl & 2)\n"
					"{\n"
						"choose1 = (_avl / 2) + 1;\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"choose1 = %#lx\\n\",choose1); \n"
						#endif	
					"}\n"
					
					"else\n"
					"{\n"
						"choose1 = (_avl / 2);\n"
						#if RV64GCV_DEBUG_CALL
						"printf(\"choose1 = %#lx\\n\",choose1); \n"
						#endif	
					"}\n"
					"_vl = choose1;\n"
					#if RV64GCV_DEBUG_CALL
					"printf(\"_vl = %#lx\\n\",_vl); \n"
					#endif	
				"}\n"
			"}\n"
			"((RV64GCV*)cpu)->CSR[3104] = _vl;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->CSR[3104] = %#lx\\n\",((RV64GCV*)cpu)->CSR[3104]); \n"
			#endif	
			"((RV64GCV*)cpu)->CSR[3105] = (_illmask | zimm);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->CSR[3105] = %#lx\\n\",((RV64GCV*)cpu)->CSR[3105]); \n"
			#endif	
			"if(" + toString(rd) + " != 0)\n"
			"{\n"
				"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = _vl;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"*((RV64GCV*)cpu)->X[" + toString(rd) + "] = %#lx\\n\",*((RV64GCV*)cpu)->X[" + toString(rd) + "]); \n"
				#endif	
			"}\n"
			
			"((RV64GCV*)cpu)->CSR[8] = 0;\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
			#endif	
		"cpu->instructionPointer = " +toString((uint64_t)(ic.current_address_+ 4 ))+"ULL; \n"
		
; 
return true;
},
0,
nullptr
);
//-------------------------------------------------------------------------------------------------------------------
static InstructionDefinition vle_u_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vle.u",
 		(uint32_t)0x7,
 		(uint32_t) 0xedf0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 width = 0;
 		static BitArrayRange R_width_0 (14,12);
 		etiss_uint64 width_0 = R_width_0.read(ba);
 		width += width_0;
 		etiss_uint64 mew = 0;
 		static BitArrayRange R_mew_0 (28,28);
 		etiss_uint64 mew_0 = R_mew_0.read(ba);
 		mew += mew_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vle.u\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 2}, {11, 13}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _eew = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_eew = vcfg_concatEEW(" + toString(mew) + ", " + toString(width) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_eew = %#lx\\n\",_eew); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = etiss_vload_encoded_unitstride((ETISS_CPU*) cpu, (ETISS_System*) system, ((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", _eew, " + toString(vd) + ", _vstart, _vlen, _vl, *((RV64GCV*)cpu)->X[" + toString(rs1) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vse_u_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vse.u",
 		(uint32_t)0x27,
 		(uint32_t) 0xedf0007f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vs3 = 0;
 		static BitArrayRange R_vs3_0 (11,7);
 		etiss_uint64 vs3_0 = R_vs3_0.read(ba);
 		vs3 += vs3_0;
 		etiss_uint64 width = 0;
 		static BitArrayRange R_width_0 (14,12);
 		etiss_uint64 width_0 = R_width_0.read(ba);
 		width += width_0;
 		etiss_uint64 mew = 0;
 		static BitArrayRange R_mew_0 (28,28);
 		etiss_uint64 mew_0 = R_mew_0.read(ba);
 		mew += mew_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vse.u\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {11, 13}};\n"
			"etiss_uint32 num_stages = 3;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 2};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _eew = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_eew = vcfg_concatEEW(" + toString(mew) + ", " + toString(width) + ");\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_eew = %#lx\\n\",_eew); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = etiss_vstore_encoded_unitstride((ETISS_CPU*) cpu, (ETISS_System*) system, ((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", _eew, " + toString(vs3) + ", _vstart, _vlen, _vl, *((RV64GCV*)cpu)->X[" + toString(rs1) + "]);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsub_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vsub.vv",
 		(uint32_t)0x8000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsub.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsub_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsub_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vsub.vx",
 		(uint32_t)0x8004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsub.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsub_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwaddu_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwaddu.vv",
 		(uint32_t)0xc0000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwaddu.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwaddu_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwaddu_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwaddu.vx",
 		(uint32_t)0xc0004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwaddu.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwaddu_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwadd_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwadd.vv",
 		(uint32_t)0xc4000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwadd.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwadd_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwadd_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwadd.vx",
 		(uint32_t)0xc4004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwadd.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwadd_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsubu_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwsubu.vv",
 		(uint32_t)0xc8000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsubu.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsubu_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsubu_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwsubu.vx",
 		(uint32_t)0xc8004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsubu.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsubu_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsub_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwsub.vv",
 		(uint32_t)0xcc000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsub.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsub_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsub_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwsub.vx",
 		(uint32_t)0xcc004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsub.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsub_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwaddu_w_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwaddu.w.vv",
 		(uint32_t)0xd0000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwaddu.w.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwaddu_w_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwaddu_w_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwaddu.w.vx",
 		(uint32_t)0xd0004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwaddu.w.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwaddu_w_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwadd_w_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwadd.w.vv",
 		(uint32_t)0xd4000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwadd.w.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwadd_w_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwadd_w_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwadd.w.vx",
 		(uint32_t)0xd4004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwadd.w.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwadd_w_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsubu_w_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwsubu.w.vv",
 		(uint32_t)0xd8000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsubu.w.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsubu_w_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsubu_w_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwsubu.w.vx",
 		(uint32_t)0xd8004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsubu.w.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsubu_w_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsub_w_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vwsub.w.vv",
 		(uint32_t)0xdc000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsub.w.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsub_w_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vwsub_w_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vwsub.w.vx",
 		(uint32_t)0xdc004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vwsub.w.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vwsub_w_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vand_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vand.vv",
 		(uint32_t)0x24000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vand.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vand_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vand_vi_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vand.vi",
 		(uint32_t)0x24003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vand.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vand_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vand_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vand.vx",
 		(uint32_t)0x24004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vand.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vand_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vor_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vor.vv",
 		(uint32_t)0x28000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vor.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vor_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vor_vi_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vor.vi",
 		(uint32_t)0x28003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vor.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vor_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vor_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vor.vx",
 		(uint32_t)0x28004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vor.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vor_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vxor_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vxor.vv",
 		(uint32_t)0x2c000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vxor.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vxor_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vxor_vi_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vxor.vi",
 		(uint32_t)0x2c003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vxor.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vxor_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vxor_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vxor.vx",
 		(uint32_t)0x2c004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vxor.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vxor_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsll_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsll.vv",
 		(uint32_t)0x94000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsll.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsll_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsll_vi_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsll.vi",
 		(uint32_t)0x94003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 uimm5 = 0;
 		static BitArrayRange R_uimm5_0 (19,15);
 		etiss_uint64 uimm5_0 = R_uimm5_0.read(ba);
 		uimm5 += uimm5_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsll.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsll_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(uimm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsll_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsll.vx",
 		(uint32_t)0x94004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsll.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsll_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsrl_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsrl.vv",
 		(uint32_t)0xa0000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsrl.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsrl_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsrl_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsrl.vx",
 		(uint32_t)0xa0004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsrl.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsrl_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsrl_vi_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsrl.vi",
 		(uint32_t)0xa4003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 uimm5 = 0;
 		static BitArrayRange R_uimm5_0 (19,15);
 		etiss_uint64 uimm5_0 = R_uimm5_0.read(ba);
 		uimm5 += uimm5_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsrl.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsra_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(uimm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsra_vv_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsra.vv",
 		(uint32_t)0xa4000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsra.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 2, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsra_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vsra_vx_vd_rs1_vm(
 		ISA32_RV64GCV,
 		"vsra.vx",
 		(uint32_t)0xa4004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vsra.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {3, 4, 2}, {9}, {15}};\n"
			"etiss_uint32 num_stages = 4;\n"
			"etiss_uint32 num_resources[100] = {2, 3, 1, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vsra_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmseq_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmseq.vv",
 		(uint32_t)0x60000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmseq.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmseq_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmseq_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmseq.vx",
 		(uint32_t)0x60004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmseq.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmseq_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsne_vi_vd_vs2_simm5_vm(
 		ISA32_RV64GCV,
 		"vmsne.vi",
 		(uint32_t)0x64003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsne.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsne_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsne_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmsne.vv",
 		(uint32_t)0x64000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsne.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsne_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsne_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmsne.vx",
 		(uint32_t)0x64004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsne.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsne_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsltu_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmsltu.vv",
 		(uint32_t)0x68000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsltu.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsltu_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsltu_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmsltu.vx",
 		(uint32_t)0x68004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsltu.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsltu_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmslt_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmslt.vv",
 		(uint32_t)0x6c000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmslt.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmslt_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmslt_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmslt.vx",
 		(uint32_t)0x6c004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmslt.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmslt_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsleu_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmsleu.vv",
 		(uint32_t)0x70000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsleu.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsleu_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsleu_vi_vd_vs2_uimm5_vm(
 		ISA32_RV64GCV,
 		"vmsleu.vi",
 		(uint32_t)0x70003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 uimm5 = 0;
 		static BitArrayRange R_uimm5_0 (19,15);
 		etiss_uint64 uimm5_0 = R_uimm5_0.read(ba);
 		uimm5 += uimm5_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsleu.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsleu_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(uimm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsleu_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmsleu.vx",
 		(uint32_t)0x70004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsleu.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = ETISS_vmsleu_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsle_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmsle.vv",
 		(uint32_t)0x74000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsle.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsle_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsle_vi_vd_vs2_simm5_vm(
 		ISA32_RV64GCV,
 		"vmsle.vi",
 		(uint32_t)0x74003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsle.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsle_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsle_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmsle.vx",
 		(uint32_t)0x74004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsle.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsle_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsgtu_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmsgtu.vv",
 		(uint32_t)0x78000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsgtu.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsgtu_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsgtu_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmsgtu.vx",
 		(uint32_t)0x78004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsgtu.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsgtu_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsgt_vv_vd_vs2_vs1_vm(
 		ISA32_RV64GCV,
 		"vmsgt.vv",
 		(uint32_t)0x7c000057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsgt.vv\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsgt_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs1) + ", " + toString(vs2) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmsgt_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vmsgt.vx",
 		(uint32_t)0x7c004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmsgt.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmsgt_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmv_v_v_vd_vs1(
 		ISA32_RV64GCV,
 		"vmv.v.v",
 		(uint32_t)0x5e000057,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs1 = 0;
 		static BitArrayRange R_vs1_0 (19,15);
 		etiss_uint64 vs1_0 = R_vs1_0.read(ba);
 		vs1 += vs1_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmv.v.v\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmv_vv(((RV64GCV*)cpu)->V, _vtype, " + toString(vd) + ", " + toString(vs1) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmv_v_i_vd_simm5(
 		ISA32_RV64GCV,
 		"vmv.v.i",
 		(uint32_t)0x5e003057,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmv.v.i\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmv_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vd) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vmv_v_x_vd_rs1(
 		ISA32_RV64GCV,
 		"vmv.v.x",
 		(uint32_t)0x5e004057,
 		(uint32_t) 0xfff0707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vmv.v.x\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vmv_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vd) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vslideup_vi_vd_vs2_simm5_vm(
 		ISA32_RV64GCV,
 		"vslideup.vi",
 		(uint32_t)0x38003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vslideup.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vslideup_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vslideup_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vslideup.vx",
 		(uint32_t)0x38004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vslideup.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vslideup_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vslide1up_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vslide1up.vx",
 		(uint32_t)0x38006057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vslide1up.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vslide1up_vx(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vslidedown_vi_vd_vs2_simm5_vm(
 		ISA32_RV64GCV,
 		"vslidedown.vi",
 		(uint32_t)0x3c003057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 simm5 = 0;
 		static BitArrayRange R_simm5_0 (19,15);
 		etiss_uint64 simm5_0 = R_simm5_0.read(ba);
 		simm5 += simm5_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vslidedown.vi\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vslidedown_vi(((RV64GCV*)cpu)->V, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(simm5) + ", _vstart, _vlen, _vl);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vslidedown_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vslidedown.vx",
 		(uint32_t)0x3c004057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vslidedown.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vslidedown_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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
static InstructionDefinition vslide1down_vx_vd_vs2_rs1_vm(
 		ISA32_RV64GCV,
 		"vslide1down.vx",
 		(uint32_t)0x3c006057,
 		(uint32_t) 0xfc00707f,
 		[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
 		{
 		etiss_uint64 rs1 = 0;
 		static BitArrayRange R_rs1_0 (19,15);
 		etiss_uint64 rs1_0 = R_rs1_0.read(ba);
 		rs1 += rs1_0;
 		etiss_uint64 vs2 = 0;
 		static BitArrayRange R_vs2_0 (24,20);
 		etiss_uint64 vs2_0 = R_vs2_0.read(ba);
 		vs2 += vs2_0;
 		etiss_uint64 vm = 0;
 		static BitArrayRange R_vm_0 (25,25);
 		etiss_uint64 vm_0 = R_vm_0.read(ba);
 		vm += vm_0;
 		etiss_uint64 vd = 0;
 		static BitArrayRange R_vd_0 (11,7);
 		etiss_uint64 vd_0 = R_vd_0.read(ba);
 		vd += vd_0;
 		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);
		partInit.getAffectedRegisters().add("instructionPointer",64);
 	partInit.code() = std::string("//vslide1down.vx\n")+
 			"etiss_uint32 exception = 0;\n"
 			"etiss_uint32 temp = 0;\n"
 			"etiss_uint8 * tmpbuf = (etiss_uint8 *)&temp;\n"
			#if RV64GCV_Pipeline1cc
			"etiss_uint32 resource_time [100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};\n"
			"etiss_uint32 resources [100][100] = {{0, 1}, {2}};\n"
			"etiss_uint32 num_stages = 2;\n"
			"etiss_uint32 num_resources[100] = {2, 1};\n"
			"handleResources(resource_time, resources, num_stages, num_resources, cpu);\n"
			#endif

 			"etiss_uint64 _vtype = 0;\n"
 			"etiss_uint64 ret = 0;\n"
 			"etiss_uint64 _vl = 0;\n"
 			"etiss_uint64 _vstart = 0;\n"
 			"etiss_uint64 _vlen = 0;\n"
 			
			"_vtype = ((RV64GCV*)cpu)->CSR[3105];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vtype = %#lx\\n\",_vtype); \n"
			#endif	
			"_vstart = ((RV64GCV*)cpu)->CSR[8];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vstart = %#lx\\n\",_vstart); \n"
			#endif	
			"_vl = ((RV64GCV*)cpu)->CSR[3104];\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vl = %#lx\\n\",_vl); \n"
			#endif	
			"_vlen = (((RV64GCV*)cpu)->CSR[3106] * 8);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"_vlen = %#lx\\n\",_vlen); \n"
			#endif	
			"ret = vslide1down_vx(((RV64GCV*)cpu)->V, *((RV64GCV*)cpu)->X, _vtype, " + toString(vm) + ", " + toString(vd) + ", " + toString(vs2) + ", " + toString(rs1) + ", _vstart, _vlen, _vl, 64);\n"
			#if RV64GCV_DEBUG_CALL
			"printf(\"ret = %#lx\\n\",ret); \n"
			#endif	
			"if(ret != 0)\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = (ret >> 8);\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
				#endif	
				"exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION; \n"
			"}\n"
			
			"else\n"
			"{\n"
				"((RV64GCV*)cpu)->CSR[8] = 0;\n"
				#if RV64GCV_DEBUG_CALL
				"printf(\"((RV64GCV*)cpu)->CSR[8] = %#lx\\n\",((RV64GCV*)cpu)->CSR[8]); \n"
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


