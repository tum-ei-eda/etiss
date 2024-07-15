/**
 * Generated on Tue, 25 Apr 2023 11:23:36 +0200.
 *
 * This file contains the GDBCore adapter for the RV32IMACFD core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV32IMACFDArch_RV32IMACFDGDBCORE_H_
#define ETISS_RV32IMACFDArch_RV32IMACFDGDBCORE_H_

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include <sstream>

/**
	@brief This class is the brige between RV32IMACFD architecture and gdbserver

	@details Gdbserver integrated in ETISS calls GDBCore to read/write registers via virtualStrruct
				The index in mapRegister() should strictly follow the RV32IMACFD gdb tool defined register
				order. Because gdbserver will send raw register data sequentially in strict order over
				RSP ->TCP/IP ->RSP protocal

				Check the order with gdb command:
				$(gdb) info all-registers
				which lists all registers supported and its order.

				By default only general purpose register and instruction pointer are supported. Further
				Special Function Register/Control and Status Register could be added manually. Meanwhile
				virtualStruct in RV32IMACFDArch.cpp should be modified as well as well

*/
class RV32IMACFDGDBCore : public etiss::plugin::gdb::GDBCore {
public:
	std::string mapRegister(unsigned index){
		if (index < 32){
			std::stringstream ss;
			ss << "X" << index;
			return ss.str();
		}

		if ((32 < index) and (index < 65)){
			std::stringstream ss;
			ss << "F" << (index - 33);
			return ss.str();
		}

		if ((64 < index) and (index < 69)){
			std::stringstream ss;
			ss << "CSR" << (index - 65);
			return ss.str();
		}
		
		switch (index){
		case 32:
			return "instructionPointer";
		/**************************************************************************
		*   Further register should be added here to send data over gdbserver	  *
		***************************************************************************/
		// 
                case 1000:
                        return "CSR3072";
                case 1001:
                        return "CSR3200";
                case 1002:
                        return "CSR3073";
                case 1003:
                        return "CSR3201";
                case 1004:
                        return "CSR3074";
                case 1005:
                        return "CSR3202";
                // M CSR
                case 1006:
                        return "CSR3857";
                case 1007:
                        return "CSR3858";
                case 1008:
                        return "CSR3859";
                case 1009:
                        return "CSR3860";
                case 1010:
                        return "CSR768";
                case 1011:
                        return "CSR769";
                case 1012:
                        return "CSR770";
                case 1013:
                        return "CSR771";
                case 1014:
                        return "CSR772";
                case 1015:
                        return "CSR773";
                case 1016:
                        return "CSR774";
                case 1017:
                        return "CSR832";
                case 1018:
                        return "CSR833";
                case 1019:
                        return "CSR834";
                case 1020:
                        return "CSR835";
                case 1021:
                        return "CSR836";
		}
		return "";
	}

	unsigned mapRegister(std::string name){
		return INVALIDMAPPING;
	}

	unsigned mappedRegisterCount(){
		// Modify according to sent register number
		return 108;
	}

	etiss::uint64 getInstructionPointer(ETISS_CPU * cpu){
		return cpu->instructionPointer;
	}

	bool isLittleEndian(){
		// Modify according to RV32IMACFD manual
		return true;
	}
};

#endif
