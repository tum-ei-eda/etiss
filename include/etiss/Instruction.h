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

        @date November 17, 2014

        @version 0.4

*/
/**
        @file

        @brief contains container classes to store instruction definitions + translation functions and build a
   translatio tree.

        @detail the classes can be seperated into 3 types.
        general storage classes for bit vectors and related (BitArray,BitArrayReader,OPCode),
        classes that contain defined instructions and their translation functions
   (VariableInstructionSet,ModedInstructionSet,InstructionSet,Instruction) and classes that contain instruction
   definitions and can be added to the previous type of classes. For example use of these definition classes please have
   a look at the OR1K architecture implementation

*/

#ifndef ETISS_INCLUDE_INSTRUCTION_H_
#define ETISS_INCLUDE_INSTRUCTION_H_

#include "etiss/Misc.h"

#include "etiss/CodePart.h"

#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

namespace etiss
{

namespace instr
{

typedef uint32_t I;

/**
        @brief stores a bit vector
*/
class BitArray
{
  public:
  private:
    static_assert(std::is_unsigned<I>::value, "etiss::instr::BitArray may only be used with unsigned integral types");
    static_assert(std::is_integral<I>::value, "etiss::instr::BitArray may only be used with unsigned integral types");
    friend class BitArrayRange;

  private:
    static const unsigned aaddr_mask_;
    static const unsigned aaddr_shift_;
    static unsigned gen_mask(unsigned width, unsigned intcount)
    {
        unsigned bc = intcount * sizeof(I) * 8;
        bc = bc - width;
        bc = sizeof(I) * 8 - bc;
        I ret = 0;
        for (unsigned i = 0; i < bc; i++)
            ret = (ret << 1) | 1;
        return ret;
    }
    static unsigned gen_intcount(unsigned width)
    {
        unsigned mod = width % (sizeof(I) * 8);
        unsigned ret = (width - mod) / (sizeof(I) * 8);
        if (mod > 0)
            ret++;
        return ret;
    }
    static unsigned gen_bytecount(unsigned width)
    {
        unsigned mod = width % (8);
        unsigned ret = (width - mod) / (8);
        if (mod > 0)
            ret++;
        return ret;
    }

  private:
    const unsigned intcount_;   ///< number of I's required to store the data
    I *d_;                      ///< stored data
    const unsigned w_;          ///< bit width
    const unsigned bw_;         ///< byte width
    const unsigned endmask_;    ///< mask to remove additional bits due to width/sizeof(I) missmatch
    mutable bool bsvalid_;      ///< @see getBitSetCount
    mutable unsigned *bscount_; ///< @see getBitSetCount
  public:
    /**
        constructs a bit array with the given width in bits.
    */
    BitArray(unsigned width);
    template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
    /**
        constructs a bit array with the given width in bits. the passed value is used to initialize the array and may be
       longer or shorter than the storage type I
    */
    BitArray(unsigned width, const T val)
        : intcount_(gen_intcount(width))
        , d_(new I[intcount_])
        , w_(width)
        , bw_(gen_bytecount(width))
        , endmask_(gen_mask(width, intcount_))
        , bsvalid_(false)
        , bscount_(nullptr)
    {
        int start = (int)sizeof(T);
        int mod = start % sizeof(I);
        start = (start - mod) / sizeof(I);
        if (mod > 0)
        {
            start++;
        }
        for (unsigned i = start; start >= 0 && i < intcount_; i++)
        {
            d_[i] = 0;
        }
        *this = val;
    }
    /**
        copy ctor
    */
    BitArray(const BitArray &o);
    /**
        move ctor
    */
    BitArray(BitArray &&o);
    /**
        dtor
    */
    ~BitArray();

    /**
        @return number of internal number of I variables used to store the bit
       array
    */
    inline unsigned wordCount() const { return intcount_; }
    /**
        @return number of bytes stored in this array (rounded up if neccessary)
    */
    inline unsigned byteCount() const { return bw_; }
    /**
        @return number of bits in this array. this equals the width value passed
       to the constructor
    */
    inline unsigned width() const { return w_; }
    /**
        returns a reference to the word at the given index.
        @attention the index is not check. use wordCount() to get the size of the internal storage array
        @attention the array size in bits may be smaller then the total count of bits in the storage array. in this case
       the additional bits MUST be zero
    */
    inline I &getWord(unsigned index) { return d_[index]; }
    /**
        const version. @see getWord(unsigned index)
    */
    inline const I &getWord(unsigned index) const { return d_[index]; }
    /**
        @return the value of the bit at the given index
    */
    bool get(unsigned index) const;
    /**
        sets the value of the bit at the given index
    */
    void set(unsigned index, bool val);
    /**
        sets all bits in the array to the given value
    */
    void setAll(bool val);
    /// bitwise or operator
    BitArray operator|(const BitArray &o) const;
    /// bitwise and operator
    BitArray operator&(const BitArray &o) const;
    /// bitwise not operator
    BitArray operator~() const;
    /// less than operator
    bool operator<(const BitArray &o) const;
    /// equals operator
    bool operator==(const BitArray &o) const;
    inline bool operator!=(const BitArray &o) const { return !((*this) == o); }

    template <typename LI>
    /**
        assign operator. allows to use any type of integral value
        @attention if LI is larger than this bit array the most significant bits will be silently discarded
        @attention signed variables will have their msb extended
    */
    typename std::enable_if<std::is_integral<LI>::value && (sizeof(LI) > sizeof(I)), BitArray &>::type operator=(LI val)
    {
        if (intcount_ > 0)
        {
            unsigned pos = 0;
            while (pos < intcount_)
            {
                d_[pos++] = (I)val;
                val = val >> (sizeof(I) * 8);
            }
            d_[intcount_ - 1] = d_[intcount_ - 1] & endmask_;
        }
        return *this;
    }
    template <typename LI>
    /**
        assign operator. allows to use any type of integral value
        @attention signed variables will have their msb extended.
    */
    typename std::enable_if<std::is_integral<LI>::value && (sizeof(LI) <= sizeof(I)), BitArray &>::type operator=(
        LI val)
    {
        typedef typename std::conditional<std::is_signed<LI>::value, typename std::make_signed<I>::type,
                                          typename std::make_unsigned<I>::type>::type CI; // conversion type
        if (intcount_ > 0)
        {
            d_[0] = (I)((CI)val);
            if (intcount_ == 1)
            {
                d_[0] = d_[0] & endmask_;
            }
            else
            {
                // force correct msb expansion
                val = val >> ((sizeof(LI) * 8) >> 1);
                val = val >> ((sizeof(LI) * 8) >> 1);
                val = val >> (1);
                // apply expanded msb
                for (unsigned i = 1; i < intcount_; i++)
                {
                    d_[i] = (I)((CI)val);
                }
                // unset additional bits
                d_[intcount_ - 1] = d_[intcount_ - 1] & endmask_;
            }
        }
        return *this;
    }

    /**
        copy operator
    */
    BitArray &operator=(const BitArray &o);
    /**
        move operator
    */
    BitArray &operator=(BitArray &&o);

    /**
        returns the number of consecutive bits set upwards from given address. e.g. b1011 -> getBitSetCount(0) returns
       2,getBitSetCount(1) returns 1, getBitSetCount(2) returns 0
    */
    unsigned getBitSetCount(unsigned index) const;

    /**
        @brief get the internal buffer
        @attention call recoverFromEndianness() to order the bytes after writing data
        @attention selective write operations together with recoverFromEndianness() are not supported
    */
    char *internalBuffer();
    /**
        @return same as width * sizeof(I)
    */
    unsigned internalBufferSize();
    /**
        changes byte positions as needed to resove endiannes incompabilities after
       using the internal buffer to write
    */
    void recoverFromEndianness(unsigned alignment, endian_t endianness);
};

/**
        @attention only use if val has only one bit set to 1
*/
CONSTEXPR unsigned etiss_instr_sqrt_2pow(unsigned val)
{
    return val == 1 ? 0 : (1 + etiss_instr_sqrt_2pow(val >> 1));
}

/**
    creates a mask to get the lower address of a bitwise address. e.g. for sizeof(I)==4, address 33:
   (33&etiss_instr_generateMask()) is 1
*/
CONSTEXPR I etiss_instr_generateMask()
{
    return ~(((I)-1) << (etiss_instr_sqrt_2pow(sizeof(I) * 8)));
}

/// allow printing of bit arrays (always hex)
std::ostream &operator<<(std::ostream &os, const BitArray tf);

/**
 * Acts as a view/filter to a BitArray. Reading through it will only return bits
 * within the range. Writing through it will only set bits within the range.
 *
 * The length of the range may not be larger than sizeof(I)*8.
 */
class BitArrayRange
{
  public:
    etiss_del_como(BitArrayRange)

        private : unsigned filterStart_;
    unsigned filterEnd_;
    unsigned filterLen_;
    unsigned lowPartShift_ = 0;
    I lowPartMask_ = 0;
    unsigned dataArrayIndex_ = 0;
    bool needsSplitAccess_ = false;
    I highPartMask_ = 0;
    unsigned highPartShift_ = 0;

    static const size_t Ibits = sizeof(I) * 8;

  public:
    /**
        @attention startindex_included MUST be the higher valued index. Only exception is for zero length ranges where
       startindex_included+1==endindex_included
    */
    BitArrayRange(unsigned startindex_included, unsigned endindex_included);

    /**
        reads bits from the range to the return value starting at the lsb. higher
       bits are set to zero
    */
    I read(const BitArray &ba);
    /**
        write the bit from the passed value starting at the lsb to the range.
    */
    void write(const BitArray &ba, I val);
    /**
        sets all bits of the range to the specified value (true =1;false =0)
    */
    void setAll(const BitArray &ba, bool val);

    /**
        highest bit of the range (included)
    */
    unsigned start();
    /**
        lowest bit of the range (included).
        @attention for zero length ranges end() equals start()+1
    */
    unsigned end();
};

/**
    defines the relevant bits and their value to identify an instruction.
    e.g. l.add of the or1k architecture:

    \image html opcode_l_add_or1k.png

    opcode: 0x38 (bit 31-25), 0x0 (bit 9-8), 0x0 (bit 3-0)

    the resulting code as passed to the constructor would be: 0xE0000000
    the resulting mask as passed to the constructor would be: 0xFC00030F

    to simplify that procedure a simple language is provided to generate those
    values from a representation that is much more similar to the opcode
   definition in text form.

    see uint32_t parse_i32(const char * s) or for a more general implementation see template <typename T> T
   parse_i(const char * s)

    if there is c++11 support then the literal operator ""_i32 can be used
   instead of parse_i32()

    the syntax for parse_i/parse_i32 is very simple. the number of bits is followed by an 'x' and the value represented
   in hex (additional bits from the hex representation are discarded). further such definitions are seperated by a space
   character. the definitions further to the left will be left shifted by the length of followind definitions. e.g for
   l.add:

    uint32_t code = parse_i32("6x32 16x0 2x0 4x0 4x0"); // or  parse_i32("6x32 26x0") or parse_i32("6x32 15x0 1x0 2x0
   4x0 4x0") uint32_t mask = parse_i32("6xFF 16x0 2xF 4x0 4xF");



*/
class OPCode
{

  public:
    const BitArray code_;
    const BitArray mask_;
    template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
    /**
        ctor that uses integral values for mask and code
        @attention only if DEBUG is defined as non zero a warning message will be printed if the code doesn't fit the
       mask
        @param width width in bits
    */
    OPCode(unsigned width, const T code, const T mask) : code_(width, code & mask), mask_(width, mask)
    {
#if DEBUG
        if ((code & mask) != code)
        {
            etiss::log(etiss::WARNING, "etiss::instr::OPCode constructed with mismatched code and mask");
        }
        if (width != 16 && width != 32 && width != 64 && width != 128 && width != 256)
        {
            etiss::log(etiss::VERBOSE, std::string("OPCode with unusual width: ") + toString(width) +
                                           "[width must be given in bits and is usually 16,32,64,128,256 bits long]");
        }
#endif
    }

    /**
        @attention the width of code and mask MUST be equal
    */
    OPCode(const BitArray &code, const BitArray &mask);

    /**
        copy ctor
    */
    OPCode(const OPCode &cpy);

    /**
        comparison operator for map/sets. compares mask and code to provide some
       sort of order. has no further meaning.
    */
    bool operator<(const OPCode &o) const;
    inline bool operator==(const OPCode &o) const { return !((*this < o) || (o < *this)); }
    inline bool operator!=(const OPCode &o) const { return !((*this) == o); }
};

/**
    calls operator< of the objects. cannot handle NULL pointers
*/
struct less
{
    bool operator()(const OPCode *const &o1, const OPCode *const &o2) const;
};

class Instruction;

/**
    base class that is used to build the instruction translation tree within an
   InstructionSet object
    @attention any change to virtual functions must be applied to
   etiss::instr::Instruction aswell
*/
class Node
{
  private:
    /// no copy/moce operations
    etiss_del_como(Node)
        /// array of sub nodes
        Node **subs_;
    /// reader to extract the bits to identify a sub node
    BitArrayRange *reader_;

  public:
    /**
        ctor
    */
    Node();
    /**
        dtor
    */
    virtual ~Node();
    /**
        called by InstructionSet::compile()
        calls Node::compile() of sub nodes
        @param instrmap_ a subset of instructions that will be put into/linked as sub nodes.
        @param used bits that have already been used in previous nodes and cannot be used by this node to distinguish
       instruction opcodes
    */
    virtual void compile(const std::map<const OPCode *, Instruction *, etiss::instr::less> &instrmap_,
                         const BitArray &used, bool &ok, std::list<std::string> &warnings,
                         std::list<std::string> &errors);
    /**
        performs a lookup for the matching Instruction for the passed instruction
       in the bit array.
    */
    virtual Instruction *resolve(BitArray &instr);
    /**
        returns true if this object is an instance of etiss::instr::Instruction
    */
    virtual bool isInstruction();
    /**
        recursive print function to produce a human readable text that represents the structure of this node and sub
       nodes
        @see InstructionSet::print()
    */
    virtual std::string print(std::string indent, I pos, unsigned pfillwidth, bool printunused = false);
};

/**
    this class contains parameters that persist in between instruction lookpus/translation within a translation block.
    the instruction context passed is guaranteed to have been passed to all previous instruction lookups in order.

    the or1k architecture implementaion for example uses this class to store information about a delay slot instruction
   and forces the translaton block to newver separate jump and delay slot instructions

    if an architecture needs to pass additional information in between instruction translations the ufield function can
   be used to create additional variables. such variable names should alway be prefixed with a unique string to avoid
   collision with plugins
*/
class InstructionContext
{

  public:
    etiss_del_como(InstructionContext)

        inline InstructionContext()
    {
    } ///< instruction context is initialized by etiss::Translation class

    bool is_not_default_width_; ///< if true the this instruction is not as long as the width of the variable
                                ///< instruction set
    unsigned instr_width_;
    bool instr_width_fully_evaluated_; ///< if true the length_updater_ function will be called again after instr_width_
                                       ///< bits are available
    bool force_append_next_instr_;     ///< if true then the block will continue with the next instruction and cannot be
                                       ///< terminated
    bool force_block_end_; ///< if true then the block ends after the current instruction. will be overridden by
                           ///< force_append_next_instr_
    unsigned &ufield(std::string name);
    template <typename T>
    /**
        returns a persistent field
        @param plugin should always be the plugin to which the field belongs.
       Should almost always be (*this).
    */
    uint64_t &ufield(const T &plugin, std::string name)
    {
        return lufields_[&plugin][name];
    }
    uint64_t current_address_;       ///< start address of current instruction
    uint64_t current_local_address_; ///< address within the current block

  public:
    //////////////////////////////////////////////////
    // common fields
    unsigned cf_delay_slot_;

  private:
    std::map<std::string, unsigned> ufields_; ///< additional fields that can be used by any plugin/architecture. field
                                              ///< names must consider this (as in: use descriptive,long names).
    std::map<void *, std::map<std::string, uint64_t>>
        lufields_; ///< additonal fields that are local (private) to a plugin/architecture.
};

/**
    holds information and translation callbacks for an instruction.
<pre>
    Location in an instruction translation tree:
    ModedInstructionSet
        ↳ VariableInstructionSet (e.g. for mode 0)
            ↳ InstructionSet (e.g. 32 bit)
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                    ↳ ...
                        ↳ <b>Instruction</b>
            ↳ InstructionSet (e.g. 16 bit)
</pre>
*/
class Instruction : public Node, public etiss::ToString
{
  private:
    std::list<std::tuple<std::function<bool(BitArray &, etiss::CodeSet &, InstructionContext &)>, uint32_t,
                         std::set<uint32_t>>>
        callbacks_;
    uint32_t builtinGroups_;
    std::set<uint32_t> groups_;
    std::function<std::string(BitArray &, Instruction &)> printer_;

  public:
    etiss_del_como(Instruction)

        enum class BUILTINGROUP : uint32_t {
            CPUTIMEUPDATE = 1 << 0 ///< signal that the callback handles updating of the time. by default a CPUArch will
                                   ///< increase the time by one cycle if no callback with that flag is present
        };

    const OPCode opc_;
    const std::string name_;

    static std::string printASMSimple(BitArray &ba, Instruction &instr);

    Instruction(const OPCode &opc, const std::string &name);
    template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
    Instruction(unsigned width, const T code, const T mask, const std::string &name)
        : builtinGroups_(0), printer_(printASMSimple), opc_(OPCode(width, code, mask)), name_(name)
    {
    }
    virtual void compile(const std::map<const OPCode *, Instruction *, etiss::instr::less> &instrmap_,
                         const BitArray &used, bool &ok, std::list<std::string> &warnings,
                         std::list<std::string> &errors);
    virtual Instruction *resolve(BitArray &instr);
    virtual bool isInstruction();
    virtual std::string print(std::string indent, I pos, unsigned pfillwidth, bool printunused = false);
    bool addCallback(std::function<bool(BitArray &, etiss::CodeSet &, InstructionContext &)> callback,
                     uint32_t builtinGroups, const std::set<uint32_t> &groups = std::set<uint32_t>());
    bool translate(BitArray &, CodeSet &cs, InstructionContext &context);
    uint32_t &presentBuiltinGroups();
    std::set<uint32_t> &presentGroups();
    std::string printASM(BitArray &);
    void setASMPrinter(std::function<std::string(BitArray &, Instruction &)> printer);
    inline std::string toString() const { return name_; }
};

class VariableInstructionSet;
/**
    holds etiss::instr::Instruction instances and handles automatic instruction
tree creation. <pre> Location in an instruction translation tree:
    ModedInstructionSet
        ↳ VariableInstructionSet (e.g. for mode 0)
            ↳ <b>InstructionSet</b> (e.g. 32 bit)
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                    ↳ ...
                        ↳ Instruction
            ↳ InstructionSet (e.g. 16 bit)
</pre>
*/
class InstructionSet : public etiss::ToString
{
  private:
  public:
    etiss_del_como(InstructionSet)

        VariableInstructionSet &parent_;
    const std::string name_;
    const unsigned width_;

    InstructionSet(VariableInstructionSet &parent, unsigned width, const std::string &name);
    ~InstructionSet();

    Instruction *get(const OPCode &key);
    Instruction &open(const OPCode &key, const std::string &name);
    Instruction *create(const OPCode &key, const std::string &name);

    template <typename T>
    Instruction &open(T code, T val, const std::string &name)
    {
        return open(OPCode(width_, code, val), name);
    }

    bool compile();

    Instruction *resolve(BitArray &instr);

    std::string print(std::string prefix, bool printunused = false);

    Instruction &getInvalid();

    void foreach (std::function<void(Instruction &)> func);

    size_t size();

    inline std::string toString() const { return name_; }

  private:
    std::map<const OPCode *, Instruction *, etiss::instr::less> instrmap_;

    Node *root_;

    Instruction invalid;
};

class ModedInstructionSet;
/**
    holds etiss::instr::InstructionSet instances with different bit widths.

<pre>
    Location in an instruction translation tree:
    <b>ModedInstructionSet<b>
        ↳ VariableInstructionSet (e.g. for mode 0)
            ↳ InstructionSet (e.g. 32 bit)
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                    ↳ ...
                        ↳ Instruction
            ↳ InstructionSet (e.g. 16 bit)
</pre>
*/
class VariableInstructionSet
{
  private:
    std::map<unsigned, InstructionSet *> ismap_;

  public:
    ModedInstructionSet &parent_;
    unsigned width_;
    const std::string archname_;
    std::function<void(VariableInstructionSet &, InstructionContext &, BitArray &)> length_updater_;

  public:
    etiss_del_como(VariableInstructionSet)

        VariableInstructionSet(ModedInstructionSet &, unsigned width, const std::string &archname);
    ~VariableInstructionSet();
    bool compile();

    InstructionSet *get(unsigned width);
    InstructionSet *create(unsigned width, const std::string &name = std::string());
    InstructionSet &open(unsigned width, const std::string &name = std::string());
    inline InstructionSet *getMain() { return get(width_); }
    inline InstructionSet *createMain(const std::string &name = std::string()) { return create(width_); }
    inline InstructionSet &openMain(const std::string &name = std::string()) { return open(width_); }

    template <typename T>
    Instruction &open(unsigned bits, T code, T mask, const char *name)
    {
#if DEBUG
        unsigned bytes = bits >> 3;
        if (bytes * 8 != bits)
        {
            etiss_log(ERROR, "Invalid bit count");
            throw std::runtime_error();
        }
#endif
        return open(bits).open<T>(bits, code, mask, std::string(name));
    }

    void foreach (std::function<void(InstructionSet &)> func);

    std::string print(std::string prefix = std::string());
};

/**
    holds etiss::instr::VariableInstructionSet instances for different modes.

    The field ETISS_CPU::mode selects the matching VariableInstructionSet from
this ModedInstructionSet.

    ETISS includes a mode check at the start of a translation block to check if the translated block was compiled with
the same mode as the current mode. If the modes mismatch the block will be discarded and translated again.

<pre>
    Location in an instruction translation tree:
    <b>ModedInstructionSet</b>
        ↳ VariableInstructionSet (e.g. for mode 0)
            ↳ InstructionSet (e.g. 32 bit)
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                ↳ Node
                    ↳ ...
                    .
                    .
                    .
                    ↳ ...
                        ↳ Instruction
            ↳ InstructionSet (e.g. 16 bit)
</pre>
*/
class ModedInstructionSet
{
  private:
    std::map<uint32_t, std::string> modetostring_;
    std::map<std::string, uint32_t> stringtomode_;
    std::map<uint32_t, VariableInstructionSet *> vismap_;
    std::map<VariableInstructionSet *, uint32_t> invvismap_;

  public:
    const std::string archname_;

  public:
    etiss_del_como(ModedInstructionSet)

        ModedInstructionSet(const std::string &name);
    ~ModedInstructionSet();

    VariableInstructionSet *get(uint32_t mode);
    VariableInstructionSet *create(uint32_t mode, unsigned width, const std::string &name = std::string());
    /**
        @attention in non debug build a width missmatch will be silently ignored
    */
    VariableInstructionSet &open(uint32_t mode, unsigned width, const std::string &name = std::string());

    template <typename T>
    Instruction &open(uint32_t mode, unsigned width, unsigned bits, T code, T mask, const char *instrname)
    {
        return open(mode, width).open<T>(bits, code, mask, instrname);
    }

    uint32_t getMode(VariableInstructionSet *vis);
    inline uint32_t getMode(VariableInstructionSet &vis) { return getMode(&vis); }

    void foreach (std::function<void(VariableInstructionSet &)> call);

    bool compile();

    std::string print(std::string prefix = std::string());
};

class InstructionClass;
/**
        maps to ModedInstructionSet
*/
class InstructionCollection
{
  private:
    std::set<InstructionClass *> classes_;
    template <typename... T>
    void add(InstructionClass &klass, T &... args)
    {
        classes_.insert(&klass);
        add(args...);
    }
    inline void add() {}

  public:
    etiss_del_como(InstructionCollection)

        const std::string name_; // e.g. ARMv6-M
    template <typename... T>
    inline InstructionCollection(const std::string &name, InstructionClass &class1, T &... otherclasses) : name_(name)
    {
        add(class1, otherclasses...);
    }
    inline void foreach (std::function<void(InstructionClass &)> call)
    {
        for (auto iter = classes_.begin(); iter != classes_.end(); iter++)
        {
            call(**iter);
        }
    }
    void addTo(ModedInstructionSet &set, bool &ok);
};
class InstructionGroup;
/**
        maps to VariableInstructionSet
*/
class InstructionClass
{
  private:
    std::set<InstructionGroup *> groups_;
    template <typename... T>
    void add(InstructionGroup &group, T &... args)
    {
        groups_.insert(&group);
        add(args...);
    }
    inline void add() {}

  public:
    const unsigned mode_;    // e.g. 0 for ARM 1 for thumb
    const std::string name_; // e.g. ARM
    const unsigned width_;   // most common read width (fastest)
  public:
    etiss_del_como(InstructionClass)

        template <typename... T>
        InstructionClass(unsigned mode, const std::string &name, unsigned width, InstructionGroup &group1,
                         T &... othergroups)
        : mode_(mode), name_(name), width_(width)
    {
        add(group1, othergroups...);
    }
    inline void foreach (std::function<void(InstructionGroup &)> call)
    {
        for (auto iter = groups_.begin(); iter != groups_.end(); iter++)
        {
            call(**iter);
        }
    }
    void addTo(VariableInstructionSet &set, bool &ok);
};
class InstructionDefinition;
/**
        maps to InstructionSet
*/
class InstructionGroup : public etiss::ToString
{
    friend class InstructionDefinition;

  private:
    std::set<InstructionDefinition *> defs_;

  public:
    const std::string name_; // e.g. thumb / thumb-2
    const unsigned width_;   // e.g. 16/32 bits
  public:
    etiss_del_como(InstructionGroup)

        inline InstructionGroup(const std::string &name, unsigned width)
        : name_(name), width_(width)
    {
    }
    inline void foreach (std::function<void(InstructionDefinition &)> call)
    {
        for (auto iter = defs_.begin(); iter != defs_.end(); iter++)
        {
            call(**iter);
        }
    }
    void addTo(InstructionSet &set, bool &ok);
    inline std::string toString() const { return name_; }
};
/**
        maps to Instruction
*/
class InstructionDefinition : public etiss::ToString
{
  public:
    InstructionGroup &group_;
    const std::string name_;
    const OPCode opc_;
    const std::function<bool(BitArray &, etiss::CodeSet &, InstructionContext &)> callback_;
    const std::function<std::string(BitArray &, Instruction &)> ASMprinter_;
    const uint32_t builtinGroups_;

  public:
    etiss_del_como(InstructionDefinition)

        template <typename T>
        InstructionDefinition(InstructionGroup &ig, const std::string &name, T code, T mask,
                              std::function<bool(BitArray &, etiss::CodeSet &, InstructionContext &)> callback,
                              uint32_t builtinGroups, std::function<std::string(BitArray &, Instruction &)> ASMprinter)
        : group_(ig)
        , name_(name)
        , opc_(ig.width_, code, mask)
        , callback_(callback)
        , ASMprinter_(ASMprinter)
        , builtinGroups_(builtinGroups)
    {
        if (!callback)
        {
            etiss_log(
                FATALERROR,
                (std::string(
                     "Instruction defined without a function callback. This instruction definition will be ignored: ") +
                 name));
            return;
        }
        group_.defs_.insert(this);
    }
    inline ~InstructionDefinition()
    {
        // group_.defs_.erase(this); // removed since InstructionDefinition should not be deleted during execution
    }
    void addTo(Instruction &set, bool &ok);
    inline std::string toString() const { return group_.name_ + ":" + name_; }
};

#if __cplusplus >= 201103L
uint32_t operator"" _i32(const char *s);
#endif

uint32_t parse_i32(const char *s);

template <typename T_>
/**

    @brief this parser basically allows to write as a string hexadecimal values which will be appended as if it is one
hexadecimal sequence and the "0x" prefix is replaced by a "<decimal number>x" [e.g. 12x] that defines the length in
bits. e.g. "2xF 2x0 4xF" -> 0xCF

    <pre>
        syntax:
            string: definition [' ' string]
            definition: bit_count 'x' bit_value
            bit_count: digit [bit_count]
            digit: '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
            bit_value: hdigit [bit_value]
            hdigit: '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' |
'A' | 'B' | 'C' | 'D' | 'E' | 'F'
    </pre>
    bit_count is a decimal number that defines the length in bits of the definition.
    bit_value defines the values of the bits of the definition in hexadecimal format.
    the definitions are alwas placed at the least significant bits and are left shifted by definitions to the right from
them. the total sum of bit_count occurences in a string must match the width of the return type otherwise an error
message is printed the behaviour is undefined in case of a bit_value that has less bits than defined by the bit_count.

    <pre>
        example parsing process of "2xF 2x0 2xF 10x0":
            initial value:          0x0000
            parse 1. definition:    0x0003
            parse 2. definition:    0x000C
            parse 3. definition:    0x0033
            parse 4. definition:    0xCC00
    </pre>

@see etiss::instr::OPCode for an example use of this syntax.

*/
typename std::enable_if<std::is_integral<T_>::value, typename std::make_unsigned<T_>::type>::type parse_i(
    const char *s, bool *good = 0)
{
    if (good)
        *good = true;
    typedef typename std::make_unsigned<T_>::type U;
    unsigned shifted = 0;
    unsigned pos = 0;
    int mode = 0;
    U tmp = 0;
    U ret = 0;
    U mask = 0;
    do
    {
        switch (mode)
        {
        case 0:
            if (s[pos] >= '0' && s[pos] <= '9')
            {
                tmp = tmp * 10 + s[pos] - '0';
            }
            else if (s[pos] == 'x' || s[pos] == 'x')
            {
                mask = 0;
                ret = ret << tmp;
                shifted += tmp;
                for (unsigned i = 0; i < tmp; i++)
                    mask = (mask << 1) | 1;
                tmp = 0;
                mode = 1;
            }
            else if (s[pos] == ' ' || s[pos] == '\t')
            {
                // ignore spaces
                // TODO only ignore leading spaces
            }
            else
            {
                if (good)
                    *good = false;
                etiss::log(etiss::ERROR, std::string("Failed to parse literal ") + s);
                return (U)(T_)-1;
            }
            break;
        case 1:
            if (s[pos] >= '0' && s[pos] <= '9')
            {
                tmp = tmp * 16 + s[pos] - '0';
            }
            else if (s[pos] >= 'a' && s[pos] <= 'f')
            {
                tmp = tmp * 16 + s[pos] + 10 - 'a';
            }
            else if (s[pos] >= 'A' && s[pos] <= 'F')
            {
                tmp = tmp * 16 + s[pos] + 10 - 'A';
            }
            else if (s[pos] == ' ' || s[pos] == '\t' || s[pos] == 0)
            {
                // complain if hex is shorter than bit length?
                ret = ret | (tmp & mask);
                tmp = 0;
                mode = 0;
            }
            else
            {
                if (good)
                    *good = false;
                etiss::log(etiss::ERROR, std::string("Failed to parse literal ") + s);
                return (U)(T_)-1;
            }
        }
    } while (s[pos++] != 0);

    if (shifted != 32)
    {
        if (good)
            *good = false;
        etiss::log(etiss::ERROR, std::string("Failed to parse literal due to invalid length: ") + s);
        // return  (U)(T_)-1; return the parsed value anyway
    }

    return ret;
}

} // namespace instr

} // namespace etiss
#endif
