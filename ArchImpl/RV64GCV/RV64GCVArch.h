// This file was generated on Tue Nov 24 19:15:14 CET 2020
// If necessary please modify this file according to the instructions
// Contact: eda@tum

#ifndef ETISS_RV64GCVArch_RV64GCVArch_H_
#define ETISS_RV64GCVArch_RV64GCVArch_H_

#include "etiss/CPUArch.h"
#include "etiss/Instruction.h"
#include "etiss/InterruptVector.h"
#include "RV64GCV.h"
#include "RV64GCVGDBCore.h"

#include <map>

class RV64GCVArch : public etiss::CPUArch {

public:

	RV64GCVArch();

	virtual const std::set<std::string> & getListenerSupportedRegisters();


	virtual ETISS_CPU * newCPU();
	virtual void resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer);
	virtual void deleteCPU(ETISS_CPU *);
	
	/**
		@brief get the VirtualStruct of the core to mitigate register access
		
		@see RV64GCVArchSpecificImp.h
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
		@brief required headers (RV64GCV.h)
	*/
	virtual const std::set<std::string> & getHeaders() const;

	/**
		@brief This function will be called automatically in order to handling architecure dependent exceptions such 
		       as interrupt, system call, illegal instructions

		@see RV64GCVArchSpecificImp.h
	*/
	virtual etiss::int32 handleException(etiss::int32 code,ETISS_CPU * cpu);

	/**
		@brief This function is called during CPUArch initialization

		@see RV64GCVArchSpecificImp.h
	*/
	virtual void initInstrSet(etiss::instr::ModedInstructionSet & ) const;
	virtual void initCodeBlock(etiss::CodeBlock & cb) const;

	/**
		@brief Target architecture may have inconsistent endianess. Data read from memory is buffered, and this function 			       
			   is called to alter sequence of buffered data so that the inconsistent endianess is compensated.

		@see RV64GCVArchSpecificImp.h
	*/
	virtual void compensateEndianess(ETISS_CPU * cpu,etiss::instr::BitArray & ba) const ;
	
	/**
		@brief If interrupt handling is expected, vector table could be provided to support interrupt triggering

		@see RV64GCVArchSpecificImp.h
	*/
	virtual etiss::InterruptVector * createInterruptVector(ETISS_CPU * cpu);
	virtual void deleteInterruptVector(etiss::InterruptVector * vec,ETISS_CPU * cpu);
	
	/**
		@brief get the GDBcore for RV64GCV architecture
		
		@see RV64GCVGDBCore.h for implementation of GDBcore
	*/
	virtual etiss::plugin::gdb::GDBCore & getGDBCore();

private:

	std::set<std::string> listenerSupportedRegisters_;
	std::set<std::string> headers_;
	RV64GCVGDBCore gdbcore_;


};
#endif
