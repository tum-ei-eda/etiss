/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
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

InstructionSpecificAddressCallback::InstructionSpecificAddressCallback()
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
    mis.foreach ([this](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([this](etiss::instr::InstructionSet &set) {
            set.foreach ([this](etiss::instr::Instruction &instr) {
                instr.addCallback(
                    [this](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
                        if (this->callbackAddresses().find(ic.current_address_) != this->callbackAddresses().end())
                        {
                            std::stringstream ss;
                            ss << "      if ( (*(uint32_t*)(" << getPointerCode()
                               << ")) != " << etiss::toString(pluginData_.state_) << ")\n"
                               << "        return ETISS_RETURNCODE_RELOADCURRENTBLOCK;";
                            cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                            ss.str("");
                            ss.clear();
                            ss << "      uint32_t callbackCalled = InstructionSpecificAddressCallback_callback("
                               << getPointerCode() << ");";
                            // cs.append(CodePart::APPENDEDREQUIRED).code() = ss.str();
                            cs.append(CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                            ss.str("");
                            ss.clear();
                            ss << "      if(callbackCalled)\n"
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
                        [this](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
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
