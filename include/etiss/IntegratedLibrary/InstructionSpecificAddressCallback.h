// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
    size_t get_uid_once(void) const
    {
        static size_t __uid_cntr{ 0 };
        return ++__uid_cntr;
    }
    size_t const uid_;

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
