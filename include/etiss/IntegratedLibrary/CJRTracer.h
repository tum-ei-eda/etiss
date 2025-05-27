//
// Created by holaphei on 27/05/25.
//

#ifndef CJRINSTRUCTIONCALLBACK_H
#define CJRINSTRUCTIONCALLBACK_H

#include "etiss/IntegratedLibrary/InstructionSpecificAddressCallback.h"

class CJRTracer : public etiss::plugin::InstructionSpecificAddressCallback
{
public:
    CJRTracer();

    virtual bool callback() override;

    virtual bool callbackOnInstruction(etiss::instr::Instruction &instr) const override;
};

#endif // CJRINSTRUCTIONCALLBACK_H
