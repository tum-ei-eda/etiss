//
// Created by holaphei on 03/05/25.
//


#include "etiss/IntegratedLibrary/ISAExtensionValidator.h"
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
                        std::stringstream ss;

                        // Taken from RV32IMACFD_RV32Instr.cpp
                        etiss_uint8 rd = 0;
                        static BitArrayRange R_rd_0(11, 7);
                        rd += R_rd_0.read(ba) << 0;

                        ss << "ISAExtensionValidation_print(\"*((RV32IMACFD*)cpu)->X[";
                        ss << "Here we want processor state data. Like: ";
                        ss << std::to_string(rd % 32ULL) + "ULL";
                        ss << "]\\n\");\n";


                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

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