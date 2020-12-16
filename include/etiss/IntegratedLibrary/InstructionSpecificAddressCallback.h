/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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

        @date July 28, 2014

        @version 0.1

*/
/**
        @file

        @brief contains a simple plugin to print instructions

        @detail

*/
#ifndef ETISS_PLUGIN_InstructionSpecificAddressCallback_H_
#define ETISS_PLUGIN_InstructionSpecificAddressCallback_H_

#include "etiss/Instruction.h"
#include "etiss/Plugin.h"

namespace etiss
{

namespace plugin
{

/**
        @brief a simple plugin that prints the instruction and address when an instruction is executed
*/
class InstructionSpecificAddressCallback : public etiss::TranslationPlugin
{
  public:
    struct Data
    {
        uint32_t state_; // must be first field to allow pointer cast to uint32_t* for direct acess; the state is
                         // increased whenever a change is made
        void *this_;
    };

  private:
    Data pluginData_;
    std::set<uint64_t> caddrset_;

  public:
    InstructionSpecificAddressCallback();
    ~InstructionSpecificAddressCallback();
    /// implement this callback to manipulate the cpu be fore executing the defined instructions at the defined address
    virtual bool callback() = 0; // return values indicates if the block should be stopt with execution

    /// implement to return true to call InstructionSpecificAddressCallback::callback whenever that
    /// etiss::instr::Instruction is executed. used by finalizeInstrSet
    inline virtual bool callbackOnInstruction(etiss::instr::Instruction &instr) const { return false; }

    /// call to add an address at which callback should be called upon execution. May be changed during execution.please
    /// not that only aligned addresses will have an effect.
    inline virtual void addCallbackAddress(uint64_t addr)
    {
        caddrset_.insert(addr);
        pluginData_.state_++; // Force Rewriting of Code Block
    }
    inline virtual void removeCallbackAddress(uint64_t addr)
    {
        caddrset_.erase(addr);
        pluginData_.state_++; // Force Rewriting of Code Block
    }

    inline const std::set<uint64_t> &callbackAddresses() const { return caddrset_; }

    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;
    virtual void initCodeBlock(etiss::CodeBlock &block) const;
    virtual std::string _getPluginName() const;
    virtual void *getPluginHandle();
};

} // namespace plugin

} // namespace etiss

#endif
