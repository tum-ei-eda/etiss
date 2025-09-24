// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief

        @detail

*/

#ifndef ETISS_TIMING_H
#define ETISS_TIMING_H

#include "etiss/Instruction.h"
#include "etiss/Misc.h"
#include "etiss/Plugin.h"

#include <functional>
#include <regex>

namespace etiss
{

class DataSheetAccurateTiming : public TranslationPlugin
{
  private:
    struct Rule
    {
        std::function<bool(uint32_t /*mode*/)> mode;
        std::function<bool(unsigned /*width*/)> width;
        std::function<bool(etiss::instr::Instruction & /*instr*/)> instr;
        std::function<void(etiss::instr::Instruction &)> handler;
    };

  public:
    /**
            this is the main add rule function.
            any other addRule function must map to this
            @attention this function will test ALL rules if they match.
    */
    void addRule(std::function<bool(uint32_t /*mode*/)> matchesMode,
                 std::function<bool(unsigned /*width*/)> matchesWidth,
                 std::function<bool(etiss::instr::Instruction & /*instr*/)> matchesInstr,
                 std::function<void(etiss::instr::Instruction & /*match*/)> handleMatch);
    /**
            adds a rule for the given mode,width and instruction name
    */
    void addRule(const std::tuple<uint32_t, unsigned, const char *,
                                  std::function<void(etiss::instr::Instruction & /*match*/)>> &tuple);
    /**
            adds a rule that uses regular expressions to match mode,width and instruction name
    */
    void addRule(const std::tuple<std::regex, std::regex, std::regex,
                                  std::function<void(etiss::instr::Instruction & /*match*/)>> &tuple);
    inline void addRule(
        const std::tuple<std::regex, std::regex, std::regex, void (*)(etiss::instr::Instruction & /*match*/)> &tuple)
    {
        addRule(make_tuple(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple),
                           std::function<void(etiss::instr::Instruction &)>(std::get<3>(tuple))));
    }

    template <unsigned cycles, bool isNotAdditionalTime = true>
    /**
     simple template function that adds the given number of cycles to the cpu time if the related rule matches
     if isNotAdditionalTime is true then this handler will signal that no other main timing rules need to be applied.
     usually this should prevent the CPUArch implementation from adding the default timing
     */
    static void handleMatch_cycles(etiss::instr::Instruction &instr)
    {
        static_assert((cycles > 0) || (!isNotAdditionalTime),
                      "etiss::DataSheetAccurateTiming::handleMatch_cycles may not be used with cycle = 0 and "
                      "isNoteAdditionalTime = false");
        std::string code;
        if (cycles == 1)
        {
            code = "cpu->cpuTime_ps += cpu->cpuCycleTime_ps; //DataSheetAccurateTiming\n";
        }
        else
        {
            code = std::string("cpu->cpuTime_ps += ") + etiss::toString(cycles) +
                   " * cpu->cpuCycleTime_ps; //DataSheetAccurateTiming\n";
        }
        instr.addCallback(
            [code](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
                CodePart &cp = cs.prepend(CodePart::INITIALREQUIRED);
                cp.getAffectedRegisters().add("cpuTime_ps", 64);
                cp.code() = code;

                return true;
            },
            isNotAdditionalTime ? ((uint32_t)etiss::instr::Instruction::BUILTINGROUP::CPUTIMEUPDATE) : 0);
    }

  private:
    /// terminates recursion
    inline void ctor_hlpr() {}
    template <typename A, typename... T>
    /// handles the argument list passed to the template constructor
    void ctor_hlpr(const A &arg, const T &... rules)
    {
        addRule(arg); // store current element
        ctor_hlpr(rules...);
    }

  public:
    const std::string name_;
    template <typename... T>
    DataSheetAccurateTiming(const std::string &name, const T &... rules) : name_(name)
    {
        ctor_hlpr(rules...);
    }
    virtual ~DataSheetAccurateTiming();

    /**
            performs lookups for instructions that are in the modded instruction set to add timing code (e.g.
       "cpu->cpuTime_ps += X * cpu->cycleTime_ps;")
    */
    virtual void initInstrSet(etiss::instr::ModedInstructionSet &) const;

  protected:
    inline std::string _getPluginName() const { return name_; }

  private:
    std::list<Rule *> rules_;
};

} // namespace etiss

#endif // ETISS_TIMING_H
