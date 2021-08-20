// This file was generated on Mon Jun 22 18:08:07 CEST 2020
// If necessary please modify this file according to the instructions
// Contact: eda@tum

#ifndef ETISS_RV64GCVArch_RV64GCVGDBCORE_H_
#define ETISS_RV64GCVArch_RV64GCVGDBCORE_H_

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include <sstream>

/**
	@brief This class is the brige between RV64GCV architecture and gdbserver
	
	@details Gdbserver integrated in ETISS calls GDBCore to read/write registers via virtualStrruct
			 The index in mapRegister() should strictly follow the RV64GCV gdb tool defined register 
			 order. Because gdbserver will send raw register data sequentially in strict order over
			 RSP ->TCP/IP ->RSP protocal
			 
			 Check the order with gdb command: 
			 $(gdb) info all-registers
			 which lists all registers supported and its order.
			 
			 By default only general purpose register and instruction pointer are supported. Further
			 Special Function Register/Control and Status Register could be added manually. Meanwhile
			 virtualStruct in RV64GCVArch.cpp should be modified as well as well
	
*/
class RV64GCVGDBCore : public etiss::plugin::gdb::GDBCore {
public:
	std::string mapRegister(unsigned index){
		if (index < 32){
			std::stringstream ss;
			ss << "R" << index;
			return ss.str();
		}
		switch (index){
		case 32:
			return "instructionPointer";
		/**************************************************************************
	    *   Further register should be added here to send data over gdbserver	  *
		***************************************************************************/
		}
        if (index > 64)
        {
            std::stringstream ss;
            ss << "CSR" << index - 65;
            return ss.str();
        }
		return "";
	}
	unsigned mapRegister(std::string name){
		return INVALIDMAPPING;
	}
	unsigned mappedRegisterCount(){
		// Modify according to sent register number
		return 33;
	}
	etiss::uint64 getInstructionPointer(ETISS_CPU * cpu){
		return cpu->instructionPointer;
	}
	
	bool isLittleEndian(){
		// Modify according to RV64GCV manual
		return true;
	}
	};
	
#endif
