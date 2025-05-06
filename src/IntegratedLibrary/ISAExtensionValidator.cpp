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

                        /*ss << "ISAExtensionValidation_print(\"*((RV32IMACFD*)cpu)->X[";
                        // Let's try to output X[x_0, ... x_31]
                        for (int i = 0; i < 32; ++i)
                        {
                            rd += R_rd_0.read(ba) << 0;
                            ss << std::to_string(rd % 32ULL) + "ULL";
                            if (i != 31) ss << ", ";
                        }
                        ss << "]\\n\");\n";*/

                        for (int i = 0; i < 32; i++)
                        {
                            std::stringstream ss;
                            rd += R_rd_0.read(ba) << 0;
                            ss << "etiss_uint32 register_value_" << std::to_string(i) << ";\n";
                            ss << "register_value_" << std::to_string(i) << " = (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" << std::to_string(rd % 32ULL) + "ULL]);\n";
                            ss << "ISAExtensionValidation_print_int(" << i << ", register_value_" << std::to_string(i) << ");\n;";
                            cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();
                        }



                        /*ss << "etiss_uint32 mem_val_0;";
                        ss << "mem_val_0 = (etiss_uint32)(*((RV32IMACFD*)cpu)->X[1ULL]);";*/



                        // cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                        return true;
                    },
                    0);
            });
        });
    });
};

void ISAExtensionValidator::initCodeBlock(etiss::CodeBlock &block ) const
{
    std::cout << "ISAExtensionValidator::initCodeBlock" << std::endl;
    block.fileglobalCode().insert("extern void ISAExtensionValidation_print(const char *);"); // add print function
    block.fileglobalCode().insert("extern void ISAExtensionValidation_print_int(int, etiss_uint32);"); // add print function
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

extern "C"
{
    void ISAExtensionValidation_print(const char *c)
    {
        std::cout << c;
        std::cout.flush();
    }
}

extern "C"
{
    void ISAExtensionValidation_print_int(int x, etiss_uint32 r)
    {
        printf("X[%d]: %d", x, r);
    }
}