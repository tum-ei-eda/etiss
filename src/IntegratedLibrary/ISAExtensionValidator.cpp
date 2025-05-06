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
                        // std::stringstream ss;

                        // Taken from RV32IMACFD_RV32Instr.cpp
                        etiss_uint8 rd {0};
                        static BitArrayRange R_rd_0(11, 7);

                        // Output instruction pointer
                        std::stringstream ss_ip;
                        ss_ip << "etiss_uint32 instruction_pointer;\n";
                        ss_ip << "instruction_pointer = (etiss_uint32)(cpu->instructionPointer);\n";
                        ss_ip << "ISAExtensionValidation_print_single_value(" << "\"instructionPointer\"" << ", instruction_pointer);\n";
                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss_ip.str();

                        // Output values from register X
                        std::stringstream ss_x;
                        ss_x << "etiss_uint32 register_values_x[32];\n";
                        for (int i = 0; i < 32; ++i)
                        {
                            ss_x << "register_values_x[" << i << "] = (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" << i << "ULL]);\n";
                        }
                        ss_x << "ISAExtensionValidation_print_register_array_uint32(" << "\"X\"" << ", register_values_x);\n";

                        // Output values from register F (floating point registers)
                        ss_x << "etiss_uint64 register_values_fp[32];\n";
                        for (int i = 0; i < 32; ++i)
                        {
                            ss_x << "register_values_fp[" << i << "] = (etiss_uint64)(((RV32IMACFD*)cpu)->F[" << i << "ULL]);\n";
                        }
                        ss_x << "ISAExtensionValidation_print_register_array_uint64(" << "\"F\"" << ", register_values_fp);\n";

                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss_x.str();

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
    block.fileglobalCode().insert("extern void ISAExtensionValidation_print(const char *);"); // add print function for character arrays
    block.fileglobalCode().insert("extern void ISAExtensionValidation_print_single_value(const char *, etiss_uint32);"); // add print function for character arrays and a etiss_uint32 value
    block.fileglobalCode().insert("extern void ISAExtensionValidation_print_register_array_uint32(const char *, const etiss_uint32 *);"); // add print function for char arrays and etiss_uint32 array
    block.fileglobalCode().insert("extern void ISAExtensionValidation_print_register_array_uint64(const char *, const etiss_uint64 *);"); // add print function for char arrays and etiss_uint64 array
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
     * @brief Print a C-string to the standard output stream and flush it.
     *
     * @param c A null-terminated C-string to print.
     */
    void ISAExtensionValidation_print(const char *c)
    {
        std::cout << c;
        std::cout.flush();
    }

    /**
     * @brief Print a single named register value.
     *
     * Outputs the value of a register with a string label for easier identification.
     *
     * @param c A string label (e.g., register name or description).
     * @param r The 32-bit register value to print.
     */
    void ISAExtensionValidation_print_single_value(const char *c, const etiss_uint32 r)
    {
        printf("X[%s]: %d\n", c, r);
    }

    /**
     * @brief Print all 32 32-bit register values with a common label.
     *
     * Iterates over the register array and prints each value with its index and a shared label.
     *
     * @param c A label or prefix string for each register (e.g., "X" or "reg").
     * @param regs Pointer to an array of 32 32-bit unsigned integer register values.
     */
    void ISAExtensionValidation_print_register_array_uint32(const char *c, const etiss_uint32 *regs)
    {
        for (int i = 0; i < 32; ++i)
        {
            printf("%s[%d]: %u", c, i, regs[i]);
            if (i != 31)
            {
                printf(", ");
            } else
            {
                printf("\n");
            }
        }

    }

    /**
     * @brief Print all 32 64-bit register values with a common label.
     *
     * Iterates over the register array and prints each value with its index and a shared label.
     *
     * @param c A label or prefix string for each register (e.g., "F").
     * @param regs Pointer to an array of 32 64-bit unsigned integer register values.
     */
    void ISAExtensionValidation_print_register_array_uint64(const char *c, const etiss_uint64 *regs)
    {
        for (int i = 0; i < 32; ++i)
        {
            printf("%s[%d]: %lu", c, i, regs[i]);
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



