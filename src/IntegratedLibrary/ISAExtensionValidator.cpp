//
// Created by holaphei on 03/05/25.
//

#include "etiss/IntegratedLibrary/ISAExtensionValidator.h"

using namespace etiss::plugin;

void ISAExtensionValidator::initInstrSet(etiss::instr::ModedInstructionSet & ) const
{
    std::cout << "ISAExtensionValidator::initInstrSet" << std::endl;
};

void ISAExtensionValidator::finalizeInstrSet(etiss::instr::ModedInstructionSet & ) const
{
    std::cout << "ISAExtensionValidator::finalizeInstrSet" << std::endl;
};

void ISAExtensionValidator::initCodeBlock(etiss::CodeBlock & ) const
{
    std::cout << "ISAExtensionValidator::initCodeBlock" << std::endl;
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