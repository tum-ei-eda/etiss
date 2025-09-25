// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/PrintInstruction.h

        @detail

*/

#include "etiss/IntegratedLibrary/InstructionSpecificAddressCallback.h"

extern "C"
{
    int InstructionSpecificAddressCallback_callback(void *this_)
    {
        etiss::plugin::InstructionSpecificAddressCallback::Data *data_ =
            (etiss::plugin::InstructionSpecificAddressCallback::Data *)this_;
#if DEBUG
        if (this_ == 0)
        {
            etiss::log(etiss::ERROR, "InstructionSpecificAddressCallback_callback called with nullptr.");
            return false;
        }
        if (data_->this_ == 0)
        {
            etiss::log(etiss::ERROR, "InstructionSpecificAddressCallback_callback called with uninitialized struct.");
        }
#endif
        return ((etiss::plugin::InstructionSpecificAddressCallback *)(data_->this_))->callback();
    }
}

using namespace etiss::plugin;

InstructionSpecificAddressCallback::InstructionSpecificAddressCallback() : uid_{ get_uid_once() }
{
    pluginData_.state_ = 0;
    pluginData_.this_ = this;
}
InstructionSpecificAddressCallback::~InstructionSpecificAddressCallback() {}

void InstructionSpecificAddressCallback::initCodeBlock(etiss::CodeBlock &block) const
{
    block.fileglobalCode().insert("extern int InstructionSpecificAddressCallback_callback(void *);\n");
    block.functionglobalCode().insert("  if ( (*(uint32_t*)(" + getPointerCode() +
                                      ")) != " + etiss::toString(pluginData_.state_) +
                                      ") return ETISS_RETURNCODE_RELOADCURRENTBLOCK;\n"); // add print function
}

void InstructionSpecificAddressCallback::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    mis.foreach (
        [this](etiss::instr::VariableInstructionSet &vis)
        {
            vis.foreach (
                [this](etiss::instr::InstructionSet &set)
                {
                    set.foreach (
                        [this](etiss::instr::Instruction &instr)
                        {
                            instr.addCallback(
                                [this](etiss::instr::BitArray &ba, etiss::CodeSet &cs,
                                       etiss::instr::InstructionContext &ic)
                                {
                                    if (this->callbackAddresses().find(ic.current_address_) !=
                                        this->callbackAddresses().end())
                                    {
                                        std::stringstream ss;
                                        ss << "      if ( (*(uint32_t*)(" << getPointerCode()
                                           << ")) != " << etiss::toString(pluginData_.state_) << ")\n"
                                           << "        return ETISS_RETURNCODE_RELOADCURRENTBLOCK;";
                                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                                        ss.str("");
                                        ss.clear();
                                        ss << "      uint32_t callbackCalled" << uid_
                                           << " = InstructionSpecificAddressCallback_callback(" << getPointerCode()
                                           << ");";
                                        // cs.append(CodePart::APPENDEDREQUIRED).code() = ss.str();
                                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                                        ss.str("");
                                        ss.clear();
                                        ss << "      if(callbackCalled" << uid_ << ")\n"
                                           << "        return ETISS_RETURNCODE_NOERROR;";
                                        // cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() = ss.str();
                                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();
                                    }
                                    return true;
                                },
                                0);
                            if (callbackOnInstruction(instr))
                            {
                                instr.addCallback(
                                    [this](etiss::instr::BitArray &ba, etiss::CodeSet &cs,
                                           etiss::instr::InstructionContext &ic)
                                    {
                                        std::stringstream ss;
                                        ss << "      InstructionSpecificAddressCallback_callback(";
                                        ss << getPointerCode();
                                        ss << ");";
                                        cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();
                                        return true;
                                    },
                                    0);
                            }
                        });
                });
        });
}

std::string InstructionSpecificAddressCallback::_getPluginName() const
{
    return "InstructionSpecificAddressCallback";
}

void *InstructionSpecificAddressCallback::getPluginHandle()
{
    return (void *)&pluginData_;
}
