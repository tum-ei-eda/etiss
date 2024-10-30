/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the GDBCore adapter for the RV64IMACFDV core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV64IMACFDVArch_RV64IMACFDVGDBCORE_H_
#define ETISS_RV64IMACFDVArch_RV64IMACFDVGDBCORE_H_

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include <sstream>

/**
	@brief This class is the brige between RV64IMACFDV architecture and gdbserver

	@details Gdbserver integrated in ETISS calls GDBCore to read/write registers via virtualStrruct
				The index in mapRegister() should strictly follow the RV64IMACFDV gdb tool defined register
				order. Because gdbserver will send raw register data sequentially in strict order over
				RSP ->TCP/IP ->RSP protocal

				Check the order with gdb command:
				$(gdb) info all-registers
				which lists all registers supported and its order.

				By default only general purpose register and instruction pointer are supported. Further
				Special Function Register/Control and Status Register could be added manually. Meanwhile
				virtualStruct in RV64IMACFDVArch.cpp should be modified as well as well

*/
class RV64IMACFDVGDBCore : public etiss::plugin::gdb::GDBCore {
public:
	std::string mapRegister(unsigned index){
		printf("index in GDBCore.h %d\n", index);

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
		if ((64 < index) and (index < 69)){  //FCSR
			std::stringstream ss;
			ss << "CSR" << (index - 65);
			return ss.str();
		}
		if ((1999 < index) and (index < 2032)){
			std::stringstream ss;
			ss << "V" << (index - 2000);
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
		case 1001:
			return "CSR3072";
		case 1002:
		case 1003:
			return "CSR3073";
		case 1004:
		case 1005:
			return "CSR3074";
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
		// VCSR
		case 2032:
			return "CSR8";
		case 2033:
			return "CSR9";
		case 2034:
			return "CSR10";
		case 2035:
			return "CSR15";
		case 2036:
			return "CSR3104";
		case 2037:
			return "CSR3105";
		case 2038:
			return "CSR3106";
		}
		return "";
	}
	unsigned mapRegister(std::string name){
		return INVALIDMAPPING;
	}

	unsigned mappedRegisterCount(){
		// Modify according to sent register number
		return 115;
	}

	etiss::uint64 getInstructionPointer(ETISS_CPU * cpu){
		return cpu->instructionPointer;
	}

	bool isLittleEndian(){
		// Modify according to RV64IMACFDV manual
		return true;
	}
};

#endif
