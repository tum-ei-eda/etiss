/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the architecture specific implementation for the RV64IMACFDV
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#include <vector>

#include "RV64IMACFDVArch.h"
#include "RV64IMACFDVArchSpecificImp.h"
#include "RV64IMACFDVFuncs.h"

/**
	@brief This function will be called automatically in order to handling exceptions such as interrupt, system call, illegal instructions

	@details Exception handling mechanism is implementation dependent for each cpu variant. Please add it to the following block if exception
				handling is demanded.
				Pesudo example:
				switch(cause){
						case etiss::RETURNCODE::INTERRUPT:
							.
							.
							.
						break;

*/
etiss::int32 RV64IMACFDVArch::handleException(etiss::int32 cause, ETISS_CPU * cpu)
{
	RV64IMACFDV_translate_exc_code(cpu, nullptr, nullptr, cause);
	cpu->instructionPointer = cpu->nextPc;
	return 0;
}

/**
	@brief This function is called during CPUArch initialization

	@details Function pointer length_updater_ has to be replaced if multiple length instruction execution is supported. This
				function enables dynamic instruction length update in order to guarantee correct binary translation
				Pesudo example:
				vis->length_updater_ = [](VariableInstructionSet & ,InstructionContext & ic, BitArray & ba)
				{
					switch(ba.byteCount()){
						case 4:
							if ( INSTRUCTION_LENTH_NOT_EQUAL(4)){
								updateInstrLength(ic, ba);
								ic.is_not_default_width_ = true;
									.
									.
									.
							}
							break;
					}
				};

*/
void RV64IMACFDVArch::initInstrSet(etiss::instr::ModedInstructionSet & mis) const
{
	if (false) {
		// Pre-compilation of instruction set to view instruction tree. Enable by setting 'true' above.

		etiss::instr::ModedInstructionSet iset("RV64IMACFDVISA");
		bool ok = true;
		RV64IMACFDVISA.addTo(iset,ok);

		iset.compile();

		std::cout << iset.print() << std::endl;
	}

	bool ok = true;
	RV64IMACFDVISA.addTo(mis,ok);
	if (!ok)
		etiss::log(etiss::FATALERROR,"Failed to add instructions for RV64IMACFDVISA");

	etiss::instr::VariableInstructionSet * vis = mis.get(1);

	using namespace etiss;
	using namespace etiss::instr;

	vis->get(32)->getInvalid().addCallback(
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 error_code = 0;
static BitArrayRange R_error_code_0(31, 0);
error_code += R_error_code_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//trap_entry 32\n");

// -----------------------------------------------------------------------------
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFDV_translate_exc_code(cpu, system, plugin_pointers, " + std::to_string(error_code) + "ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//trap_entry 32\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0
	);

	vis->get(16)->getInvalid().addCallback(
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 error_code = 0;
static BitArrayRange R_error_code_0(31, 0);
error_code += R_error_code_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//trap_entry 16\n");

// -----------------------------------------------------------------------------
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFDV_translate_exc_code(cpu, system, plugin_pointers, " + std::to_string(error_code) + "ULL);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//trap_entry 16\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0
	);


	/**************************************************************************
	*		      vis->length_updater_ should be replaced here	         	  *
	***************************************************************************/
}

/**
	@brief This function is called whenever a data is read from memory

	@details Target architecture may have inconsistent endianess. Data read from memory is buffered, and this function
				is called to alter sequence of buffered data so that the inconsistent endianess is compensated.
				Example for ARMv6M:
				void * ptr = ba.internalBuffer();
				if (ba.byteCount() == 2)
				{
					*((uint32_t*)ptr) = ((uint16_t)(*((uint8_t*)ptr))) | ((uint16_t)(*(((uint8_t*)ptr)+1)) << 8);
				}
				else if (ba.byteCount() == 4)
				{
					*((uint32_t*)ptr) = ((((uint32_t)(*((uint8_t*)ptr))) | ((uint32_t)(*(((uint8_t*)ptr)+1)) << 8)) << 16) | ((uint32_t)(*(((uint8_t*)ptr)+2)) ) | ((uint32_t)(*(((uint8_t*)ptr)+3)) << 8);
				}
				else
				{
					etiss::log(etiss::FATALERROR,"Endianess cannot be handled",ba.byteCount());
				}

	@attention Default endianess: little-endian

*/
void RV64IMACFDVArch::compensateEndianess(ETISS_CPU * cpu, etiss::instr::BitArray & ba) const
{
	/**************************************************************************
	*		                Endianess compensation	                    	  *
	***************************************************************************/
}

std::shared_ptr<etiss::VirtualStruct> RV64IMACFDVArch::getVirtualStruct(ETISS_CPU * cpu)
{
	auto ret = etiss::VirtualStruct::allocate(
		cpu,
		[] (etiss::VirtualStruct::Field*f) {
			delete f;
		}
	);

	for (uint32_t i = 0; i < 32; ++i){
		ret->addField(new RegField_RV64IMACFDV(*ret,i));
	}

	ret->addField(new pcField_RV64IMACFDV(*ret));
	return ret;
}

/**
	@brief If interrupt handling is expected, vector table could be provided to support interrupt triggering

	@details Interrupt vector table is used to inform the core whenever an edge/level triggered interrupt
				incoming. The content of interrupt vector could be a special register or standalone interrupt
				lines.
*/
etiss::InterruptVector * RV64IMACFDVArch::createInterruptVector(ETISS_CPU * cpu)
{
	if (cpu == 0)
		return 0;

  	std::vector<etiss::uint64 *> vec;
	std::vector<etiss::uint64 *> mask;

	vec.push_back(&((RV64IMACFDV*)cpu)->MIP);
	mask.push_back(&((RV64IMACFDV*)cpu)->MIE);

	return new etiss::MappedInterruptVector<etiss::uint64>(vec, mask);
}

void RV64IMACFDVArch::deleteInterruptVector(etiss::InterruptVector * vec, ETISS_CPU * cpu)
{
	delete vec;
}

etiss::InterruptEnable* RV64IMACFDVArch::createInterruptEnable(ETISS_CPU* cpu) {
 	return new etiss::MappedInterruptEnable<etiss::uint64>(&((RV64IMACFDV*)cpu)->MSTATUS, 15);
}

void RV64IMACFDVArch::deleteInterruptEnable(etiss::InterruptEnable* en, ETISS_CPU* cpu) {
	delete en;
}
