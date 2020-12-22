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

        @date November 21, 2014

        @version 0.4

*/
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
