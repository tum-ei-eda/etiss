/**
 * Generated on Thu, 24 Feb 2022 17:15:20 +0100.
 *
 * This file contains the architecture class for the RV32IMACFD core architecture.
 */

#ifndef ETISS_RV32IMACFDArch_RV32IMACFDArch_H_
#define ETISS_RV32IMACFDArch_RV32IMACFDArch_H_

#include "etiss/CPUArch.h"
#include "etiss/Instruction.h"
#include "etiss/InterruptVector.h"
#include "RV32IMACFD.h"
#include "RV32IMACFDGDBCore.h"

#include <map>

extern const char * const reg_name[];

extern etiss::instr::InstructionGroup ISA16_RV32IMACFD;
extern etiss::instr::InstructionClass ISA16_RV32IMACFDClass;
extern etiss::instr::InstructionGroup ISA32_RV32IMACFD;
extern etiss::instr::InstructionClass ISA32_RV32IMACFDClass;

extern etiss::instr::InstructionCollection RV32IMACFDISA;

class RV32IMACFDArch : public etiss::CPUArch {

public:
	RV32IMACFDArch();

	virtual const std::set<std::string> & getListenerSupportedRegisters();


	virtual ETISS_CPU * newCPU();
	virtual void resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer);
	virtual void deleteCPU(ETISS_CPU *);

	/**
		@brief get the VirtualStruct of the core to mitigate register access

		@see RV32IMACFDArchSpecificImp.h
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
		@brief required headers (RV32IMACFD.h)
	*/
	virtual const std::set<std::string> & getHeaders() const;

	/**
		@brief This function will be called automatically in order to handling architecure dependent exceptions such
			   as interrupt, system call, illegal instructions

		@see RV32IMACFDArchSpecificImp.h
	*/
	virtual etiss::int32 handleException(etiss::int32 code, ETISS_CPU * cpu);

	/**
		@brief This function is called during CPUArch initialization

		@see RV32IMACFDArchSpecificImp.h
	*/
	virtual void initInstrSet(etiss::instr::ModedInstructionSet & ) const;
	virtual void initCodeBlock(etiss::CodeBlock & cb) const;

	/**
		@brief Target architecture may have inconsistent endianess. Data read from memory is buffered, and this function
			   is called to alter sequence of buffered data so that the inconsistent endianess is compensated.

		@see RV32IMACFDArchSpecificImp.h
	*/
	virtual void compensateEndianess(ETISS_CPU * cpu, etiss::instr::BitArray & ba) const ;

	/**
		@brief If interrupt handling is expected, vector table could be provided to support interrupt triggering

		@see RV32IMACFDArchSpecificImp.h
	*/
	virtual etiss::InterruptVector * createInterruptVector(ETISS_CPU * cpu);
	virtual void deleteInterruptVector(etiss::InterruptVector * vec, ETISS_CPU * cpu);

	/**
		@brief get the GDBcore for RV32IMACFD architecture

		@see RV32IMACFDGDBCore.h for implementation of GDBcore
	*/
	virtual etiss::plugin::gdb::GDBCore & getGDBCore();

private:
	std::set<std::string> listenerSupportedRegisters_;
	std::set<std::string> headers_;
	RV32IMACFDGDBCore gdbcore_;
};
#endif
