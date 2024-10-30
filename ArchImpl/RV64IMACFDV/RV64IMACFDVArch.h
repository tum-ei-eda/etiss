/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the architecture class for the RV64IMACFDV core architecture.
 */

#ifndef ETISS_RV64IMACFDVArch_RV64IMACFDVArch_H_
#define ETISS_RV64IMACFDVArch_RV64IMACFDVArch_H_

#include "etiss/CPUArch.h"
#include "etiss/Instruction.h"
#include "etiss/InterruptVector.h"
#include "etiss/InterruptEnable.h"
#include "RV64IMACFDV.h"
#include "RV64IMACFDVGDBCore.h"

#include <map>

extern const char * const reg_name[];

extern etiss::instr::InstructionGroup ISA16_RV64IMACFDV;
extern etiss::instr::InstructionClass ISA16_RV64IMACFDVClass;
extern etiss::instr::InstructionGroup ISA32_RV64IMACFDV;
extern etiss::instr::InstructionClass ISA32_RV64IMACFDVClass;

extern etiss::instr::InstructionCollection RV64IMACFDVISA;

class RV64IMACFDVArch : public etiss::CPUArch {

public:
	RV64IMACFDVArch(unsigned int);

	virtual const std::set<std::string> & getListenerSupportedRegisters();


	virtual ETISS_CPU * newCPU();
	virtual void resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer);
	virtual void deleteCPU(ETISS_CPU *);

	/**
		@brief get the VirtualStruct of the core to mitigate register access

		@see RV64IMACFDVArchSpecificImp.h
	*/
	virtual std::shared_ptr<etiss::VirtualStruct> getVirtualStruct(ETISS_CPU * cpu);

	/**
		@return 8 (jump instruction + instruction of delay slot)
	*/
	virtual unsigned getMaximumInstructionSizeInBytes();

	/**
		@return 2
	*/
	virtual unsigned getInstructionSizeInBytes();

	/**
		@brief required headers (RV64IMACFDV.h)
	*/
	virtual const std::set<std::string> & getHeaders() const;

	/**
		@brief This function will be called automatically in order to handling architecure dependent exceptions such
			   as interrupt, system call, illegal instructions

		@see RV64IMACFDVArchSpecificImp.h
	*/
	virtual etiss::int32 handleException(etiss::int32 code, ETISS_CPU * cpu);

	/**
		@brief This function is called during CPUArch initialization

		@see RV64IMACFDVArchSpecificImp.h
	*/
	virtual void initInstrSet(etiss::instr::ModedInstructionSet & ) const;
	virtual void initCodeBlock(etiss::CodeBlock & cb) const;

	/**
		@brief Target architecture may have inconsistent endianess. Data read from memory is buffered, and this function
			   is called to alter sequence of buffered data so that the inconsistent endianess is compensated.

		@see RV64IMACFDVArchSpecificImp.h
	*/
	virtual void compensateEndianess(ETISS_CPU * cpu, etiss::instr::BitArray & ba) const ;

	/**
		@brief If interrupt handling is expected, vector table could be provided to support interrupt triggering

		@see RV64IMACFDVArchSpecificImp.h
	*/
	virtual etiss::InterruptVector * createInterruptVector(ETISS_CPU * cpu);
	virtual void deleteInterruptVector(etiss::InterruptVector * vec, ETISS_CPU * cpu);
	virtual etiss::InterruptEnable* createInterruptEnable(ETISS_CPU *cpu);
	virtual void deleteInterruptEnable(etiss::InterruptEnable* en, ETISS_CPU* cpu);

	/**
		@brief get the GDBcore for RV64IMACFDV architecture

		@see RV64IMACFDVGDBCore.h for implementation of GDBcore
	*/
	virtual etiss::plugin::gdb::GDBCore & getGDBCore();

private:
	std::set<std::string> listenerSupportedRegisters_;
	std::set<std::string> headers_;
	RV64IMACFDVGDBCore gdbcore_;
	unsigned int coreno_;
};
#endif
