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

        @date July 23, 2014

        @version 0.1

*/
/**
        @file

        @brief classes to hold code and additional information used for optimization of instruction translations

*/

#ifndef ETISS_INCLUDE_CODEPART_H_
#define ETISS_INCLUDE_CODEPART_H_

#include <string>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

#include "etiss/jit/types.h"
#include "etiss/Misc.h"

namespace etiss
{

/**
        @brief abstract description of needed or affected register bits.
        due to special behaviour of this class when used in a set (RegisterSet) not all const functions have const
   character. use with caution.

	@TODO For consitency width's should really be size_t
*/
class RegisterPart
{
  public:
    inline RegisterPart() : name(""), bits(0), regWidth(0) {}
    /**
            @param name register name should be same as defined by the respective etiss::CPUArch instance.
            @param registerWidth the register width in bits. must be consistet with the name and the context (e.g. cpu1
       and cpu2 are allowed to have the same register with different widths).
            @param bits relevant bits of the register (->register part).
    */
    inline RegisterPart(const std::string &name, unsigned registerWidth, etiss::uintMax bits = (uintMax)((intMax)-1))
        : name(name), regWidth(registerWidth)
    {
        uintMax mask = 0;
        for (unsigned i = 0; i < regWidth; i++)
        {
            mask |= ((uintMax)1) << i;
        }
        this->bits = bits & mask;
    }
    inline RegisterPart(const RegisterPart &cpy)
    {
        this->name = cpy.name;
        this->bits = cpy.bits;
        this->regWidth = cpy.regWidth;
    }

  public:
    /**
            @brief check for equality
    */
    inline bool matches(const RegisterPart &rp) const
    {
        if (this->name != rp.name)
            return false;
#if DEBUG
        if (this->regWidth != rp.regWidth && !(isEmpty() || rp.isEmpty()))
        {
            std::cout << "Serve Warning: RegisterPart definitions exist with same name (=same register) but different "
                         "register width values"
                      << std::endl;
            return false;
        }
#endif
        return this->bits == rp.bits;
    }
    /**
            @brief check if passed RegisterPart is a subset of relevant bits of the same register
    */
    inline bool contains(const RegisterPart &rp) const
    {
        if (this->name != rp.name)
            return false;
#if DEBUG
        if (this->regWidth != rp.regWidth && !(isEmpty() || rp.isEmpty()))
        {
            std::cout << "Serve Warning: RegisterPart definitions exist with same name (=same register) but different "
                         "register width values"
                      << std::endl;
            return false;
        }
#endif
        return (this->bits & rp.bits) == rp.bits; // this->bits has every bit of rp.bits
    }
    /**
            this is not a const function in the usual sense.
    */
    inline void applyShadow(const RegisterPart &rp) const
    {
        if (name == rp.name)
            bits = bits & (~rp.bits);
    }
    /**
            this is not a const function in the usual sense.
    */
    inline void merge(const RegisterPart &rp) const
    {
        if (name == rp.name)
            bits = bits | rp.bits;
    }
    /**
            this is not a const function in the usual sense.
    */
    inline void intersect(const RegisterPart &rp) const
    {
        if (name == rp.name)
            bits = bits & rp.bits;
    }
    inline bool maskedBy(const RegisterPart &rp) const { return rp.contains(*this); }
    inline const std::string &getName() const { return name; }
    inline const etiss::uintMax &getAffectedBits() const { return bits; }
    inline const unsigned &getRegisterWidth() const { return regWidth; }
    /**
            @brief true if unnamed or no relevant bits
    */
    inline bool isEmpty() const { return bits == 0 || name.length() == 0; }
    inline bool operator<(const RegisterPart &other) const
    {
        if (name < other.name)
            return true;
#if DEBUG
        if (regWidth < other.regWidth && !(isEmpty() || other.isEmpty()))
        {
            std::cout << "Serve Warning: RegisterPart definitions exist with same name (=same register) but different "
                         "register width values"
                      << std::endl;
            return true;
        }
#endif
        return bits < other.bits;
    }
    /**
            @brief same as matches(const RegisterPart & other)
    */
    inline bool operator==(const RegisterPart &other) const { return matches(other); }

  private:
    std::string name;
    mutable etiss::uintMax bits;
    unsigned regWidth;
};

/**
        @brief set of register parts. each register contained in a set has a different name.
*/
class RegisterSet
{
    /**
            @brief special comparison function that only takes register name into account. the use of this function and
       the special pseudo const function of RegisterPart allow the use of std::set as the main data container of
       RegisterSet
    */
    struct lex_compare
    {
        bool operator()(const RegisterPart &lhs, const RegisterPart &rhs) const
        {
            return lhs.getName() < rhs.getName();
        }
    };

  public:
    inline RegisterSet() {}
    inline RegisterSet(const RegisterSet &rs) { set_ = rs.set_; }
    /**
            @brief add a registerPart to the set or just its relevant bits if a register with the same name is already
       present
    */
    inline void add(const RegisterPart &rp)
    {
        if (rp.isEmpty())
            return;
        std::set<RegisterPart, lex_compare>::iterator iter = set_.find(rp);
        if (iter != set_.end())
        {
            (*iter).merge(rp);
            if (iter->isEmpty())
            {
                set_.erase(iter);
            }
        }
        else
        {
            set_.insert(rp);
        }
    }
    /**
            @see add(const RegisterPart & rp)
    */
    inline void add(const std::string &name, unsigned registerWidth, etiss::uintMax bits = (uintMax)((intMax)-1))
    {
        add(RegisterPart(name, registerWidth, bits));
    }
    /**
            @brief any register bits set in the passed RegisterSet won't be set in this RegisterSet
    */
    inline void applyShadow(const RegisterSet &rs)
    {
        std::set<RegisterPart, lex_compare>::iterator iter = set_.begin();
        std::set<RegisterPart, lex_compare>::const_iterator oiter;
        while (iter != set_.end())
        {
            oiter = rs.set_.find(*iter);
            if (oiter != rs.set_.end())
            {
                iter->applyShadow(*oiter);
                if (iter->isEmpty())
                {
                    set_.erase(iter++);
                }
                else
                {
                    iter++;
                }
            }
            else
            {
                iter++;
            }
        }
    }
    /**
            @brief any register bits set in the passed RegisterSet will be set in this RegisterSet (plus previously set
       bits)
    */
    inline void merge(const RegisterSet &rs)
    {
        std::set<RegisterPart, lex_compare>::const_iterator iter = rs.set_.begin();
        while (iter != rs.set_.end())
        {
            add(*iter);
            iter++;
        }
    }
    /**
            @brief only register bits set in this AND the passed RegisterSet remain set in this RegisterSet
    */
    inline void intersect(const RegisterSet &rs)
    {
        std::set<RegisterPart, lex_compare>::iterator iter = set_.begin();
        while (iter != set_.end())
        {
            std::set<RegisterPart, lex_compare>::const_iterator f = rs.set_.find(*iter);
            if (f != rs.set_.end())
            {
                iter->intersect(*f);
                if (iter->isEmpty())
                {
                    set_.erase(iter++);
                }
                else
                {
                    iter++;
                }
            }
            else
            {
                set_.erase(iter++);
            }
        }
    }
    /**
            @return true if no register in this set is in the passed RegisterSet
    */
    inline bool disjoint(const RegisterSet &rs) const
    {
        std::set<RegisterPart, lex_compare>::const_iterator iter = set_.begin();
        while (iter != set_.end())
        {
            std::set<RegisterPart, lex_compare>::const_iterator f = rs.set_.find(*iter);
            if (f != rs.set_.end())
            {
                return false;
            }
            iter++;
        }
        return true;
    }
    /**
            @return true if any bit set in this RegisterSet is also set in the passed RegisterSet
    */
    inline bool maskedBy(const RegisterSet &rs) const
    {
        std::set<RegisterPart, lex_compare>::const_iterator iter = set_.begin();
        while (iter != set_.end())
        {
            std::set<RegisterPart, lex_compare>::const_iterator oiter = rs.set_.find(*iter);
            if (oiter != rs.set_.end())
            {
                if (!iter->maskedBy(*oiter))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            iter++;
        }
        return true;
    }
    inline bool isEmpty() { return set_.empty(); }
    inline void clear() { set_.clear(); }
    /**
            @brief writes a human readable string listing all set bit of every register in this RegisterSet
    */
    inline std::string _dbg_print() const
    {
        std::stringstream ss;
        std::set<RegisterPart, lex_compare>::const_iterator iter = set_.begin();
        while (iter != set_.end())
        {
            ss << iter->getName() << ": " << std::hex << iter->getAffectedBits() << "\n";
            iter++;
        }
        return ss.str();
    }

  private:
    std::set<RegisterPart, lex_compare> set_;
};

/**
        @brief Contains a small code snipped. usually mulatiple CodeParts are used in a CodeSet to translate on
   instruction.
        @detail Each code part consists of a code snipped (e.g. "cpu->R[1] = cpu->R[2] + 42;") a set of register
   dependencies (e.g. "R2") and a set of affected registers (e.g. "R1"). CodeParts are assembled in a CodeSet where they
   can be possitioned in defferent consecutive sections (CodePart::TYPE).

*/
class CodePart
{
  public:
    /**
            @brief defines position,optionality and the ability to return a code for a CodePart. The order of
       declaration of these types is also the order of code sections
            @detail Only PREINITIALDEBUGRETURNING and APPENDEDRETURNINGREQUIRED may be chosen for CodeParts that contain
       a return statement (e.g. "return 0;"). If a TYPE contains the sequence OPTIONAL then the affected registers are
       inspected to decide if the CodePart is needed
    */
    enum TYPE
    {
        PREINITIALDEBUGRETURNING,
        INITIALREQUIRED,
        OPTIONALMIDDLE,
        APPENDEDREQUIRED,
        APPENDEDOPTIONAL,
        APPENDEDRETURNINGREQUIRED
    };
    inline CodePart() : flag_requireAll_(false) {}
    inline CodePart(const std::string &code, const RegisterSet &registerDependencies = RegisterSet(),
                    const RegisterSet &affectedRegisters = RegisterSet())
        : code_(code)
        , registerDependencies_(registerDependencies)
        , affectedRegisters_(affectedRegisters)
        , flag_requireAll_(false)
    {
    }
    inline RegisterSet &getRegisterDependencies() { return registerDependencies_; }
    inline RegisterSet &getAffectedRegisters() { return affectedRegisters_; }
    inline std::string &getCode() { return code_; }
    inline std::string &code() { return code_; }
    inline const std::string &code() const { return code_; }
    inline const RegisterSet &getRegisterDependencies() const { return registerDependencies_; }
    inline const RegisterSet &getAffectedRegisters() const { return affectedRegisters_; }
    inline const std::string &getCode() const { return code_; }
    inline const bool &fullRegistersDependency() const { return flag_requireAll_; }

  private:
    std::string code_;
    RegisterSet registerDependencies_;
    RegisterSet affectedRegisters_;
    bool flag_requireAll_;
};

/// define translation class as friend to edit endindex_
class Translation;
/**
        @brief A set of CodeParts. This class stores CodeParts and appends them as needed in the CodeSet::toString
   function
*/
class CodeSet
{

  public:
    inline CodeSet() {}
    inline CodeSet(const CodeSet &cs)
    {
        pindbgretreq_parts_ = cs.pindbgretreq_parts_;
        inireq_parts_ = cs.inireq_parts_;
        midopt_parts_ = cs.midopt_parts_;
        appreq_parts_ = cs.appreq_parts_;
        appopt_parts_ = cs.appopt_parts_;
        appretreq_parts_ = cs.appretreq_parts_;
    }
    inline void append(const CodePart &part, CodePart::TYPE type)
    {
        switch (type)
        {
        case CodePart::PREINITIALDEBUGRETURNING:
            pindbgretreq_parts_.push_front(part);
            break;
        case CodePart::INITIALREQUIRED:
            inireq_parts_.push_front(part);
            break;
        case CodePart::OPTIONALMIDDLE:
            midopt_parts_.push_front(part);
            break;
        case CodePart::APPENDEDREQUIRED:
            appreq_parts_.push_front(part);
            break;
        case CodePart::APPENDEDOPTIONAL:
            appopt_parts_.push_front(part);
            break;
        case CodePart::APPENDEDRETURNINGREQUIRED:
            appretreq_parts_.push_front(part);
            break;
        }
    }
    inline CodePart &append(CodePart::TYPE type)
    {
        switch (type)
        {
        case CodePart::PREINITIALDEBUGRETURNING:
            pindbgretreq_parts_.emplace_front();
            return pindbgretreq_parts_.front();
        case CodePart::INITIALREQUIRED:
            inireq_parts_.emplace_front();
            return inireq_parts_.front();
        case CodePart::OPTIONALMIDDLE:
            midopt_parts_.emplace_front();
            return midopt_parts_.front();
        case CodePart::APPENDEDREQUIRED:
            appreq_parts_.emplace_front();
            return appreq_parts_.front();
        case CodePart::APPENDEDOPTIONAL:
            appopt_parts_.emplace_front();
            return appopt_parts_.front();
        case CodePart::APPENDEDRETURNINGREQUIRED:
            appretreq_parts_.emplace_front();
            return appretreq_parts_.front();
        default:
            std::cout << "ERROR: etiss::CodePart::append called with invalid etiss::CodePart::TYPE parameter"
                      << std::endl;
            appretreq_parts_.emplace_front();
            return appretreq_parts_.front();
        }
    }
    inline CodePart &prepend(CodePart::TYPE type)
    {
        switch (type)
        {
        case CodePart::PREINITIALDEBUGRETURNING:
            pindbgretreq_parts_.emplace_back();
            return pindbgretreq_parts_.back();
        case CodePart::INITIALREQUIRED:
            inireq_parts_.emplace_back();
            return inireq_parts_.back();
        case CodePart::OPTIONALMIDDLE:
            midopt_parts_.emplace_back();
            return midopt_parts_.back();
        case CodePart::APPENDEDREQUIRED:
            appreq_parts_.emplace_back();
            return appreq_parts_.back();
        case CodePart::APPENDEDOPTIONAL:
            appopt_parts_.emplace_back();
            return appopt_parts_.back();
        case CodePart::APPENDEDRETURNINGREQUIRED:
            appretreq_parts_.emplace_back();
            return appretreq_parts_.back();
        default:
            std::cout << "ERROR: etiss::CodePart::prepend called with invalid etiss::CodePart::TYPE parameter"
                      << std::endl;
            appretreq_parts_.emplace_back();
            return appretreq_parts_.back();
        }
    }

  private:
    static void writeCodeParts(std::string &code, const std::list<CodePart> &parts, bool required, RegisterSet &ignored,
                               bool intersect);

  public:
    /**
            @brief writes the contained CodeParts as needed with respect to the given RegisterSet of bits that are not
       required to be set by this code
    */
    std::string toString(RegisterSet &ignored, bool &ok) const;

  private:
    std::list<CodePart> pindbgretreq_parts_;
    std::list<CodePart> inireq_parts_;
    std::list<CodePart> midopt_parts_;
    std::list<CodePart> appreq_parts_;
    std::list<CodePart> appopt_parts_;
    std::list<CodePart> appretreq_parts_;
};

/**
        @brief A list of CodeSets. this structure corresponds to the content of the switch statement of the translated
   block where one CodeSet is one translates instruction is one section after a case label.

        @detail e.g.:
                switch (instructionpointer){
                case 0:
                        {
                        ...	// CodeSet number 0
                        }
                case 1:
                        {
                        ...	// CodeSet number 1
                        }
                }
*/
class CodeBlock
{
    friend class Translation;

  public:
    /**
            @brief equivalent of a translated instruction
    */
    class Line
    {
        friend class CodeBlock;

      private:
      public:
        Line(const Line &line) : codeset_(line.codeset_), addr_(line.addr_) {}
        inline Line(etiss::uint64 addr) : addr_(addr) {}
        inline CodeSet &getCodeSet() { return codeset_; }
        inline const etiss::uint64 &getAddress() { return addr_; }

      private:
        CodeSet codeset_;
        bool ismeta_;
        etiss::uint64 addr_;
    };

  public:
    inline CodeBlock(etiss::uint64 startindex) : startindex_(startindex) {}
    inline Line &get(unsigned index) { return lines_[index]; }
    inline Line &append(etiss::uint64 addr)
    {
        lines_.push_back(Line(addr));
        return lines_.back();
    }
    inline unsigned length() const { return (unsigned)lines_.size(); }
    inline std::vector<std::string> &fileglobalCode() { return fileglobal_code; }
    inline std::vector<std::string> &functionglobalCode() { return functionglobal_code; }
    void toCode(std::stringstream &out, const std::string &funcname, std::set<std::string> *fileglobalcode);

  private:
    std::vector<Line> lines_;
    etiss::uint64 startindex_;
    etiss::uint64 endaddress_;
    std::vector<std::string> fileglobal_code;
    std::vector<std::string> functionglobal_code;
};
} // namespace etiss
#endif
