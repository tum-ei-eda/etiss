/**
 * Generated on Tue, 16 Sep 2025 12:56:33 +0200.
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
		if ((32 < index) && (index < 65)){
			std::stringstream ss;
			ss << "F" << (index - 33);
			return ss.str();
		}
		if ((64 < index) && (index < 69)){  // FCSR
			std::stringstream ss;
			ss << "CSR" << (index - 65);
			return ss.str();
		}
		switch (index){
		case 32:
			return "instructionPointer";
		case 1: return "X0";
		case 2: return "X1";
		case 3: return "X2";
		case 4: return "X3";
		case 5: return "X4";
		case 6: return "X5";
		case 7: return "X6";
		case 8: return "X7";
		case 9: return "X8";
		case 10: return "X9";
		case 11: return "X10";
		case 12: return "X11";
		case 13: return "X12";
		case 14: return "X13";
		case 15: return "X14";
		case 16: return "X15";
		case 17: return "X16";
		case 18: return "X17";
		case 19: return "X18";
		case 20: return "X19";
		case 21: return "X20";
		case 22: return "X21";
		case 23: return "X22";
		case 24: return "X23";
		case 25: return "X24";
		case 26: return "X25";
		case 27: return "X26";
		case 28: return "X27";
		case 29: return "X28";
		case 30: return "X29";
		case 31: return "X30";
		case 32: return "X31";
		case 33: return "F0";
		case 34: return "F1";
		case 35: return "F2";
		case 36: return "F3";
		case 37: return "F4";
		case 38: return "F5";
		case 39: return "F6";
		case 40: return "F7";
		case 41: return "F8";
		case 42: return "F9";
		case 43: return "F10";
		case 44: return "F11";
		case 45: return "F12";
		case 46: return "F13";
		case 47: return "F14";
		case 48: return "F15";
		case 49: return "F16";
		case 50: return "F17";
		case 51: return "F18";
		case 52: return "F19";
		case 53: return "F20";
		case 54: return "F21";
		case 55: return "F22";
		case 56: return "F23";
		case 57: return "F24";
		case 58: return "F25";
		case 59: return "F26";
		case 60: return "F27";
		case 61: return "F28";
		case 62: return "F29";
		case 63: return "F30";
		case 64: return "F31";
		case 68: return "CSR3";
		/**************************************************************************
		*   Further register should be added here to send data over gdbserver	  *
		***************************************************************************/
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
		// Modify according to RV32IMACFD manual
		return true;
	}
};

#endif
