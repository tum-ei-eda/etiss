//
// Created by holaphei on 03/05/25.
//

#ifndef ISAEXTENSIONVALIDATOR_H
#define ISAEXTENSIONVALIDATOR_H

#include "etiss/Plugin.h"

namespace etiss
{
namespace plugin
{

class ISAExtensionValidator : public etiss::TranslationPlugin {
public:
    virtual void initInstrSet(etiss::instr::ModedInstructionSet & ) const;
    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet & ) const;
    virtual void initCodeBlock(etiss::CodeBlock & ) const;
    virtual void finalizeCodeBlock(etiss::CodeBlock & ) const;
    virtual void * getPluginHandle();
    virtual std::string _getPluginName() const;
};


#endif //ISAEXTENSIONVALIDATOR_H


}// namespace plugin
}// namespace etiss


