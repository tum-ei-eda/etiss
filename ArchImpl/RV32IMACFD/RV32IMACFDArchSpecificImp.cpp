/**
 * Generated on Thu, 24 Feb 2022 17:15:20 +0100.
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
#include "Encoding.h"
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
	etiss_uint32 handledCause = cause;

    std::function<void()> disableItr = [cpu]() {
        if (likely((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MIE))
        {
            // Push MIE, SIE, UIE to MPIE, SPIE, UPIE
            etiss_uint32 irq_enable = ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MIE) |
                                      ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_UIE) |
                                      ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_SIE);
            (*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) = (irq_enable << 4) | ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & 0xffffff00);
        }
    };

    std::function<etiss_uint32(etiss_uint32, etiss_uint32)> handle = [cpu, cause](etiss_uint32 causeCode,
                                                                                  etiss_uint32 addr) {
        std::stringstream msg;

        msg << "Exception is captured with cause code: 0x" << std::hex << causeCode;
        msg << "  Exception message: " << etiss::RETURNCODE::getErrorMessages()[cause] << std::endl;

        switch (causeCode & 0x80000000)
        {

        // Exception
        case 0x0:
            // Check exception delegation
            if (*((RV32IMACFD *)cpu)->CSR[CSR_MEDELEG] & (1 << (causeCode & 0x1f)))
            {
                // Pop MPIE to MIE
                etiss::log(etiss::VERBOSE, "Exception is delegated to supervisor mode");
                (*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) ^=
                    (((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MPIE) >> 4) ^ ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MIE);
                *((RV32IMACFD *)cpu)->CSR[CSR_SCAUSE] = causeCode;
                // Redo the instruction encoutered exception after handling
                *((RV32IMACFD *)cpu)->CSR[CSR_SEPC] = static_cast<etiss_uint32>(cpu->instructionPointer - 4);
                *((RV32IMACFD *)cpu)->CSR[CSR_SSTATUS] ^= (*((RV32IMACFD *)cpu)->CSR[3088] << 8) ^ (*((RV32IMACFD *)cpu)->CSR[CSR_SSTATUS & MSTATUS_SPP]);
                *((RV32IMACFD *)cpu)->CSR[3088] = PRV_S;
                cpu->instructionPointer = *((RV32IMACFD *)cpu)->CSR[CSR_STVEC] & ~0x3;
            }
            else
            {
                *((RV32IMACFD *)cpu)->CSR[CSR_MCAUSE] = causeCode;
                // Redo the instruction encoutered exception after handling
                *((RV32IMACFD *)cpu)->CSR[CSR_MEPC] = static_cast<etiss_uint32>(cpu->instructionPointer - 4);
                (*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) ^=
                    (*((RV32IMACFD *)cpu)->CSR[3088] << 11) ^ ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MPP);
                *((RV32IMACFD *)cpu)->CSR[3088] = PRV_M;
                // Customized handler address other than specified in RISC-V ISA manual
                if (addr)
                {
                    cpu->instructionPointer = addr;
                    break;
                }
                cpu->instructionPointer = *((RV32IMACFD *)cpu)->CSR[CSR_MTVEC] & ~0x3;
            }
            break;

        // Interrupt
        case 0x80000000:
            // Check exception delegation
            if (*((RV32IMACFD *)cpu)->CSR[CSR_MIDELEG] & (1 << (causeCode & 0x1f)))
            {
                // Pop MPIE to MIE
                etiss::log(etiss::VERBOSE, "Interrupt is delegated to supervisor mode");
                (*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) ^=
                    (((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MPIE) >> 4) ^ ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MIE);
                *((RV32IMACFD *)cpu)->CSR[CSR_SCAUSE] = causeCode;
                // Return to instruction next interrupted one
                *((RV32IMACFD *)cpu)->CSR[CSR_SEPC] = static_cast<etiss_uint32>(cpu->instructionPointer);
                *((RV32IMACFD *)cpu)->CSR[CSR_SSTATUS] ^= (*((RV32IMACFD *)cpu)->CSR[3088] << 8) ^ (*((RV32IMACFD *)cpu)->CSR[CSR_SSTATUS] & MSTATUS_SPP);
                *((RV32IMACFD *)cpu)->CSR[3088] = PRV_S;
                if (*((RV32IMACFD *)cpu)->CSR[CSR_STVEC] & 0x1)
                    cpu->instructionPointer = (*((RV32IMACFD *)cpu)->CSR[CSR_STVEC] & ~0x3) + causeCode * 4;
                else
                    cpu->instructionPointer = *((RV32IMACFD *)cpu)->CSR[CSR_STVEC] & ~0x3;
            }
            else
            {
                *((RV32IMACFD *)cpu)->CSR[CSR_MCAUSE] = causeCode;
                // Return to instruction next interrupted one
                *((RV32IMACFD *)cpu)->CSR[CSR_MEPC] = static_cast<etiss_uint32>(cpu->instructionPointer);
                (*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) ^=
                    (*((RV32IMACFD *)cpu)->CSR[3088] << 11) ^ ((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MPP);
                *((RV32IMACFD *)cpu)->CSR[3088] = PRV_M;
                // Customized handler address other than specified in RISC-V ISA manual
                if (addr)
                {
                    cpu->instructionPointer = addr;
                    break;
                }
                if (*((RV32IMACFD *)cpu)->CSR[CSR_MTVEC] & 0x1)
                    cpu->instructionPointer = (*((RV32IMACFD *)cpu)->CSR[CSR_MTVEC] & ~0x3) + causeCode * 4;
                else
                    cpu->instructionPointer = *((RV32IMACFD *)cpu)->CSR[CSR_MTVEC] & ~0x3;
            }
            break;
        }

        msg << "Program is redirected to address: 0x" << std::hex << cpu->instructionPointer << std::endl;
        etiss::log(etiss::VERBOSE, msg.str());
        return etiss::RETURNCODE::NOERROR;
    };

    switch (cause)
    {

    case etiss::RETURNCODE::INTERRUPT:
        if (!((*((RV32IMACFD *)cpu)->CSR[CSR_MSTATUS]) & MSTATUS_MIE))
        {
            std::stringstream msg;
            msg << "Interrupt handling is globally disabled. Interrupt line is still pending." << std::endl;
            etiss::log(etiss::INFO, msg.str());
            handledCause = etiss::RETURNCODE::NOERROR;
            break;
        }
        {
            etiss_uint32 mip_tmp = (*(((RV32IMACFD *)cpu))->CSR[CSR_MIP]);
            if (0 == mip_tmp)
            {
                handledCause = etiss::RETURNCODE::NOERROR;
                break;
            }
            etiss_uint32 irqLine = 0;
            for (size_t i = 0; i < sizeof(mip_tmp) * 8; ++i)
            {
                // Highest interrupt line with highest priority
                if (unlikely((mip_tmp >> i) & 0x1))
                    irqLine = i;
            }

            if (!((*(((RV32IMACFD *)cpu))->CSR[CSR_MIE]) & (1 << irqLine)))
            {
                std::stringstream msg;
                handledCause = etiss::RETURNCODE::NOERROR;
                msg << "Interrupt line: " << irqLine << " is disabled. Interrupt is still pending." << std::endl;
                etiss::log(etiss::INFO, msg.str());
                break;
            }

            disableItr();

            handledCause = handle(irqLine | 0x80000000, 0);
        }
        break;

    case etiss::RETURNCODE::RESET:
        handledCause = handle(0, etiss::cfg().get<uint64_t>("vp.entry_point", 0));
        break;

    case etiss::RETURNCODE::INSTR_PAGEFAULT:
        disableItr();
        handledCause = handle(CAUSE_FETCH_PAGE_FAULT, 0);
        break;

    case etiss::RETURNCODE::LOAD_PAGEFAULT:

        disableItr();
        handledCause = handle(CAUSE_LOAD_PAGE_FAULT, 0);
        break;

    case etiss::RETURNCODE::STORE_PAGEFAULT:

        disableItr();
        handledCause = handle(CAUSE_STORE_PAGE_FAULT, 0);
        break;

    case etiss::RETURNCODE::ILLEGALINSTRUCTION:
    {
        disableItr();
        std::stringstream msg;
        msg << "Illegal instruction at address: 0x" << std::hex << cpu->instructionPointer << std::endl;
        *((RV32IMACFD *)cpu)->CSR[CSR_MTVAL] = static_cast<etiss_uint32>(cpu->instructionPointer);
        // Point to next instruction
        cpu->instructionPointer += 4;
        etiss::log(etiss::WARNING, msg.str());
        handledCause = handle(CAUSE_ILLEGAL_INSTRUCTION, 0);
        break;
    }

    case etiss::RETURNCODE::DBUS_READ_ERROR:

        disableItr();
        handledCause = handle(CAUSE_LOAD_ACCESS, 0);
        break;

    case etiss::RETURNCODE::DBUS_WRITE_ERROR:

        disableItr();
        handledCause = handle(CAUSE_STORE_ACCESS, 0);
        break;

    case etiss::RETURNCODE::IBUS_READ_ERROR:

        disableItr();
        handledCause = handle(CAUSE_FETCH_ACCESS, 0);
        break;

    case etiss::RETURNCODE::IBUS_WRITE_ERROR:

        disableItr();
        handledCause = handle(CAUSE_STORE_ACCESS, 0);
        break;

    case etiss::RETURNCODE::BREAKPOINT:

        disableItr();
        handledCause = handle(CAUSE_BREAKPOINT, 0);
        break;

    case etiss::RETURNCODE::SYSCALL:

        disableItr();
        switch (*((RV32IMACFD *)cpu)->CSR[3088])
        {
        case PRV_U:
            handledCause = handle(CAUSE_USER_ECALL, 0);
            break;
        case PRV_S:
            handledCause = handle(CAUSE_SUPERVISOR_ECALL, 0);
            break;
        case PRV_M:
            handledCause = handle(CAUSE_MACHINE_ECALL, 0);
            break;
        default:
            etiss::log(etiss::ERROR, "System call type not supported for current architecture.");
        }

        break;

    case etiss::RETURNCODE::ILLEGALJUMP:
    {
        disableItr();
        std::stringstream msg;
        msg << "Illegal instruction access at address: 0x" << std::hex << cpu->instructionPointer << std::endl;
        *((RV32IMACFD *)cpu)->CSR[CSR_MTVAL] = static_cast<etiss_uint32>(cpu->instructionPointer);
        // Point to next instruction
        cpu->instructionPointer += 4;
        etiss::log(etiss::WARNING, msg.str());
        handledCause = handle(CAUSE_FETCH_ACCESS, 0);
        break;
    }

    default:
    {
        std::stringstream msg;
        msg << "Exception is not handled by architecture. Exception message: ";
        msg << etiss::RETURNCODE::getErrorMessages()[cause] << std::endl;
        etiss::log(etiss::INFO, msg.str());
    }
        handledCause = cause;
        break;
    }
	return handledCause;
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

	/**************************************************************************
	*		            Implementation of interrupt vector              	  *
	***************************************************************************/

	// This is a default vector, implemented to avoid segfaults. Replace
	// with actual implementation if necessary.

	std::vector<etiss::uint32 *> vec;
	std::vector<etiss::uint32 *> mask;

	return new etiss::MappedInterruptVector<etiss::uint32>(vec, mask);
}

void RV32IMACFDArch::deleteInterruptVector(etiss::InterruptVector * vec, ETISS_CPU * cpu)
{
	delete vec;
}
