//
// Created by holaphei on 03/05/25.
//


#include "etiss/IntegratedLibrary/ISAExtensionValidator.h"

#include "../../ArchImpl/RV32IMACFD/RV32IMACFD.h"
#include "etiss/CPUArch.h"

using namespace etiss::plugin;
using namespace etiss::instr;

void ISAExtensionValidator::initInstrSet(etiss::instr::ModedInstructionSet & ) const
{
    std::cout << "ISAExtensionValidator::initInstrSet" << std::endl;
};

/*
 * This function is based on the PrintInstruction plugin implementation. In this early
 * form this plugin works just with RV32IMACFD architecture with hard coded values. Here
 * we generate statements for the C code blocks to declare and initialize variables and then
 * to call the appropriate function from the ones defined in extern "C" blocks. Please also
 * see initCodeBlock in which the functions are included to the code block as extern functions.
 *
 */
void ISAExtensionValidator::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis ) const
{
    std::cout << "ISAExtensionValidator::finalizeInstrSet" << std::endl;
    mis.foreach ([](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([](etiss::instr::InstructionSet &set) {
            set.foreach ([](etiss::instr::Instruction &instr) {
                instr.addCallback(
                    [&instr](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
                        std::stringstream ss;
                        ss << "// ISAExtensionValidation: call function to collect state information;\n";
                        /*
                         * TODO: The cast is now hardcoded. Would be nice if
                         * it could be passed from configuration or as an argument
                         */
                        ss << "ISAExtensionValidation_collect_state((RV32IMACFD*) cpu);\n";
                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                        return true;
                    },
                    0);
            });
        });
    });
};

/*
 * Add defined functions as extern functions to each code block
 */
void ISAExtensionValidator::initCodeBlock(etiss::CodeBlock &block ) const
{
    std::cout << "ISAExtensionValidator::initCodeBlock" << std::endl;
    block.fileglobalCode().insert("extern void ISAExtensionValidation_collect_state(RV32IMACFD*);");
};

void ISAExtensionValidator::finalizeCodeBlock(etiss::CodeBlock & ) const
{
    std::cout << "ISAExtensionValidator::finalizeCodeBlock" << std::endl;
};

void *ISAExtensionValidator::getPluginHandle()
{
  return nullptr;
};

std::string ISAExtensionValidator::_getPluginName() const
{
    return "ISAExtensionValidator";
};



/*
 * functions that are brought in to C code blocks as extern functions. At their current state
 * they simply output different types of data to console.
 *
 */
extern "C"
{

    /**
     * @brief Collects and handles the current CPU state for ISA extension validation.
     *
     * This function extracts the instruction pointer (PC), general-purpose registers (X),
     * and floating-point registers (F) from the given RV32IMACFD CPU state. Currently
     * it prints their values to standard output in a readable format.
     *
     * The state information is intended to be used for verification purposes.
     *
     * @param cpu Pointer to the RV32IMACFD CPU instance whose state should be collected.
     */

    void ISAExtensionValidation_collect_state(RV32IMACFD* cpu)
    {
        /*
         * TODO:
         * Replace all printf calls with an in-memory logging mechanism.
         * Specifically:
         * - Store the collected state information (PC, X and F registers) in memory,
         *   e.g., using a stringstream or a structured data container.
         * - Accumulate logs during execution without printing immediately.
         * - At the end of processing (or at a suitable point), write the entire
         *   collected log data to a file in one batch.
         *
         * This will improve performance by minimizing expensive I/O operations
         * and allow easier post-processing of the collected data.
         *
         * Ask @Johannes about how to best approach this. How to initialize the in-memory
         * solution, and how to store data to file at the end.
         */

        const etiss_uint32 pc = static_cast<etiss_uint32>(reinterpret_cast<ETISS_CPU *>(cpu)->instructionPointer);

        etiss_uint32 x[32];
        for (int i = 0; i < 32; ++i)
            x[i] = *cpu->X[i];

        etiss_uint64 f[32];
        for (int i = 0; i < 32; ++i)
            f[i] = cpu->F[i];

        // PC
        printf("X[%s]: %d\n", "PC", pc);

        // X registers
        for (int i = 0; i < 32; ++i)
        {
            printf("%c[%d]: %u", 'X', i, x[i]);
            if (i != 31)
            {
                printf(", ");
            } else
            {
                printf("\n");
            }
        }

        // F registers:
        for (int i = 0; i < 32; ++i)
        {
            printf("%c[%d]: %lu", 'F', i, f[i]);
            if (i != 31)
            {
                printf(", ");
            } else
            {
                printf("\n");
            }
        }
    }
}



