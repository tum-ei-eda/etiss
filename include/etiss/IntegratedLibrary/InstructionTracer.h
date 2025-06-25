//
// Created by holaphei on 27/05/25.
//

#ifndef CJRINSTRUCTIONCALLBACK_H
#define CJRINSTRUCTIONCALLBACK_H

#include "etiss/IntegratedLibrary/InstructionSpecificAddressCallback.h"
#include "../../ArchImpl/RV32IMACFD/RV32IMACFD.h"

#include <string>
#include <mutex>

class InstructionTracer : public etiss::plugin::InstructionSpecificAddressCallback
{
public:
    InstructionTracer();


private:
    /* immutable after construction */
    std::string output_path_;

    /* grows at run time inside callback() */
    std::string snapshot_content_;

    int         counter_ = 0;

    /* lightweight synchronisation in case ETISS runs callbacks from several cores */
    std::mutex  mutex_;

    /* InstructionSpecificAddressCallback overrides */
    bool callback() override;                                                       // run-time hook
    bool callbackOnInstruction(etiss::instr::Instruction &instr) const override;    // decode-time hook


    void initCodeBlock(etiss::CodeBlock & ) const override;
    void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const override;

};

#endif // CJRINSTRUCTIONCALLBACK_H
