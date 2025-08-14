/**
 * Generated on Thu, 14 Aug 2025 12:04:42 +0200.
 *
 * This file contains the architecture specific implementation for the RV32IMACFD
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#include <vector>

#include "RV32IMACFDArch.h"
#include "RV32IMACFDArchSpecificImp.h"
#include "RV32IMACFDFuncs.h"

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
etiss::int32 RV32IMACFDArch::handleException(etiss::int32 cause, ETISS_CPU * cpu)
{
	RV32IMACFD_translate_exc_code(cpu, nullptr, nullptr, cause);
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
void RV32IMACFDArch::initInstrSet(etiss::instr::ModedInstructionSet & mis) const
{

    {
     /* Set default JIT Extensions. Read Parameters set from ETISS configuration and append with architecturally needed */
     std::string cfgPar = "";
     cfgPar = etiss::cfg().get<std::string>("jit.external_headers", ";");
     etiss::cfg().set<std::string>("jit.external_headers", cfgPar + "etiss/jit/libsoftfloat.h");

     cfgPar = etiss::cfg().get<std::string>("jit.external_libs", ";");
     etiss::cfg().set<std::string>("jit.external_libs", cfgPar + "softfloat");

     cfgPar = etiss::cfg().get<std::string>("jit.external_header_paths", ";");
     etiss::cfg().set<std::string>("jit.external_header_paths", cfgPar + "/etiss/jit");

     cfgPar = etiss::cfg().get<std::string>("jit.external_lib_paths", ";");
     etiss::cfg().set<std::string>("jit.external_lib_paths", cfgPar + "/etiss/jit");

    }

    if (false) {
        // Pre-compilation of instruction set to view instruction tree. Could be disabled.
        etiss::instr::ModedInstructionSet iset("RV32IMACFDISA");
		bool ok = true;
		RV32IMACFDISA.addTo(iset,ok);

		iset.compile();

		std::cout << iset.print() << std::endl;
	}

	bool ok = true;
	RV32IMACFDISA.addTo(mis,ok);
	if (!ok)
		etiss::log(etiss::FATALERROR,"Failed to add instructions for RV32IMACFDISA");

    etiss::instr::VariableInstructionSet *vis = mis.get(1);

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
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, " + std::to_string(error_code) + "ULL);\n";
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
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, " + std::to_string(error_code) + "ULL);\n";
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

    vis->length_updater_ = [](VariableInstructionSet &, InstructionContext &ic, BitArray &ba) {
        std::function<void(InstructionContext & ic, etiss_uint32 opRd)> updateRV32IMACFDInstrLength =
            [](InstructionContext &ic, etiss_uint32 opRd) {
                ic.instr_width_fully_evaluated_ = true;
                ic.is_not_default_width_ = true;
                if (opRd == 0x3f)
                    ic.instr_width_ = 64;
                else if ((opRd & 0x3f) == 0x1f)
                    ic.instr_width_ = 48;
                else if (((opRd & 0x1f) >= 0x3) && ((opRd & 0x1f) < 0x1f))
                    ic.instr_width_ = 32;
                else if(opRd == 0x7f) /* P-Extension instructions */
                    ic.instr_width_ = 32;
                else if ((opRd & 0x3) != 0x3)
                    ic.instr_width_ = 16;
                else
                    // This might happen when code is followed by data.
                    ic.is_not_default_width_ = false;
            };

        BitArrayRange op(6, 0);
        etiss_uint32 opRd = op.read(ba);

        /*BitArrayRange fullOp(ba.byteCount()*8-1,0);
        etiss_uint32 fullOpRd = fullOp.read(ba);

        std::stringstream ss;
        ss << "Byte count: " << ba.byteCount()<< std::endl;
        ss << "opcode: 0x" <<std::hex<< fullOpRd << std::endl;
        ss << "Current PC: 0x" <<std::hex<< ic.current_address_ << std::endl;
        std::cout << ss.str() << std::endl;*/

        switch (ba.byteCount())
        {
        case 2:
            if (((opRd & 0x3) != 0x3) || (opRd == 0))
            {
                ic.is_not_default_width_ = false;
                break;
            }
            else
            {
                updateRV32IMACFDInstrLength(ic, opRd);
                break;
            }
        case 4:
            if ((((opRd & 0x1f) >= 0x3) || ((opRd & 0x1f) < 0x1f)) || (opRd == 0))
            {
                ic.is_not_default_width_ = false;
                break;
            }
            else if(opRd == 0x7f) /* P-Extension instructions */
            {
                updateRV32IMACFDInstrLength(ic, opRd);
                break;
            }
            else
            {
                updateRV32IMACFDInstrLength(ic, opRd);
                break;
            }
        case 6:
            if (((opRd & 0x3f) == 0x1f) || (opRd == 0))
            {
                ic.is_not_default_width_ = false;
                break;
            }
            else
            {
                updateRV32IMACFDInstrLength(ic, opRd);
                break;
            }
        case 8:
            if ((opRd == 0x3f) || (opRd == 0))
            {
                ic.is_not_default_width_ = false;
                break;
            }
            else
            {
                updateRV32IMACFDInstrLength(ic, opRd);
                break;
            }
        default:
            // This might happen when code is followed by data.
            ic.is_not_default_width_ = false;
        }
    };

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
void RV32IMACFDArch::compensateEndianess(ETISS_CPU * cpu, etiss::instr::BitArray & ba) const
{
	/**************************************************************************
	*		                Endianess compensation	                    	  *
	***************************************************************************/
}

std::shared_ptr<etiss::VirtualStruct> RV32IMACFDArch::getVirtualStruct(ETISS_CPU * cpu)
{
	auto ret = etiss::VirtualStruct::allocate(
		cpu,
		[] (etiss::VirtualStruct::Field*f) {
			delete f;
		}
	);

	for (uint32_t i = 0; i < 32; ++i){
		ret->addField(new RegField_RV32IMACFD(*ret,i));
	}

	ret->addField(new pcField_RV32IMACFD(*ret));
	return ret;
}

/**
	@brief If interrupt handling is expected, vector table could be provided to support interrupt triggering

	@details Interrupt vector table is used to inform the core whenever an edge/level triggered interrupt
				incoming. The content of interrupt vector could be a special register or standalone interrupt
				lines.
*/
etiss::InterruptVector * RV32IMACFDArch::createInterruptVector(ETISS_CPU * cpu)
{
	if (cpu == 0)
		return 0;

	std::vector<etiss::uint32 *> vec;
	std::vector<etiss::uint32 *> mask;

	vec.push_back(&((RV32IMACFD*)cpu)->MIE);
	mask.push_back(&((RV32IMACFD*)cpu)->MIP);

	return new etiss::MappedInterruptVector<etiss::uint32>(vec, mask);
}

void RV32IMACFDArch::deleteInterruptVector(etiss::InterruptVector * vec, ETISS_CPU * cpu)
{
	delete vec;
}

etiss::InterruptEnable* RV32IMACFDArch::createInterruptEnable(ETISS_CPU* cpu) {
 	return new etiss::MappedInterruptEnable<etiss::uint32>(&((RV32IMACFD*)cpu)->MSTATUS, 15);
}

void RV32IMACFDArch::deleteInterruptEnable(etiss::InterruptEnable* en, ETISS_CPU* cpu) {
	delete en;
}
