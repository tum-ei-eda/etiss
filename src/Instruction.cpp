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

        @date November 17, 2014

        @version 0.4

*/
/**
        @file

        @brief

        @detail

*/
#include "etiss/Instruction.h"

#include <sstream>
#include <cassert>

#if ETISS_USE_BYTESWAP_H
#include <byteswap.h>
#endif

namespace etiss
{

namespace instr
{

BitArray::BitArray(unsigned width)
    : intcount_(gen_intcount(width))
    , d_(new I[intcount_])
    , w_(width)
    , bw_(gen_bytecount(width))
    , endmask_(gen_mask(width, intcount_))
    , bsvalid_(false)
    , bscount_(nullptr)
{
    for (unsigned i = 0; i < intcount_; i++)
    {
        d_[i] = 0;
    }
}

BitArray::BitArray(const BitArray &o)
    : intcount_(o.intcount_)
    , d_(new I[o.intcount_])
    , w_(o.w_)
    , bw_(o.bw_)
    , endmask_(o.endmask_)
    , bsvalid_(o.bsvalid_)
    , bscount_(bsvalid_ ? new unsigned[w_] : nullptr)
{
    for (unsigned i = 0; i < intcount_; i++)
    {
        d_[i] = o.d_[i];
    }
    if (bsvalid_)
    {
        for (unsigned i = 0; i < w_; i++)
        {
            bscount_[i] = o.bscount_[i];
        }
    }
}
BitArray::BitArray(BitArray &&o)
    : intcount_(o.intcount_)
    , d_(o.d_)
    , w_(o.w_)
    , bw_(o.bw_)
    , endmask_(o.endmask_)
    , bsvalid_(o.bsvalid_)
    , bscount_(o.bscount_)
{
    o.d_ = nullptr;
    o.bscount_ = nullptr;
}
BitArray &BitArray::operator=(BitArray &&o)
{
    if (w_ == o.w_)
    { // move if same length
        delete[] d_;
        d_ = o.d_;
        o.d_ = nullptr;
        delete[] bscount_;
        bscount_ = o.bscount_;
        o.bscount_ = nullptr;
    }
    else
    { // copy
        BitArray &ba = o;
        *this = ba;
    }

    return *this;
}
BitArray::~BitArray()
{
    delete[] d_;
    delete[] bscount_;
}

bool BitArray::get(unsigned index) const
{

#if DEBUG
    if (index >= w_)
    {
        throw "Index out of bounds";
    }
#endif

    return ((d_[index >> aaddr_shift_] >> (index & aaddr_mask_)) & 1) != 0;
}
void BitArray::set(unsigned index, bool val)
{

#if DEBUG
    if (index >= w_)
    {
        throw "Index out of bounds";
    }
#endif
    bsvalid_ = false;
    I &cur = d_[index >> aaddr_shift_];
    I v = 1 << (index & aaddr_mask_);
    if (val)
    {
        cur = cur | v;
    }
    else
    {
        cur = cur & ~v;
    }
}
void BitArray::setAll(bool val)
{
    if (!val)
    {
        for (unsigned i = 0; i < intcount_; i++)
        {
            d_[i] = 0;
        }
    }
    else
    {
        typedef std::make_signed<I>::type SI;
        for (unsigned i = 0; i < intcount_; i++)
        {
            d_[i] = (I)((SI)-1);
        }
    }
}
BitArray BitArray::operator|(const BitArray &o) const
{
    unsigned width = (w_ > o.w_) ? w_ : o.w_;
    unsigned intmin = (w_ < o.w_) ? intcount_ : o.intcount_;
    BitArray ret(width);
    for (unsigned i = 0; i < intmin; i++)
    {
        ret.d_[i] = d_[i] | o.d_[i];
    }
    return ret;
}
BitArray BitArray::operator&(const BitArray &o) const
{
    unsigned width = (w_ > o.w_) ? w_ : o.w_;
    unsigned intmin = (w_ < o.w_) ? intcount_ : o.intcount_;
    BitArray ret(width);
    for (unsigned i = 0; i < intmin; i++)
    {
        ret.d_[i] = d_[i] & o.d_[i];
    }
    return ret;
}
BitArray BitArray::operator~() const
{
    BitArray ret(*this);
    for (unsigned i = 0; i < intcount_; i++)
    {
        ret.d_[i] = ~ret.d_[i];
    }
    return ret;
}
bool BitArray::operator<(const BitArray &o) const
{
    if (w_ != o.w_)
    {
        return w_ < o.w_;
    }
    for (unsigned i = intcount_; i > 0; i--)
    {
        if (d_[i - 1] != o.d_[i - 1])
            return d_[i - 1] < o.d_[i - 1];
    }
    return false;
}
bool BitArray::operator==(const BitArray &o) const
{
    if (w_ != o.w_)
    {
        return false;
    }
    for (unsigned i = intcount_; i > 0; i--)
    {
        if (d_[i - 1] != o.d_[i - 1])
            return false;
    }
    return true;
}

BitArray &BitArray::operator=(const BitArray &o)
{
    if (o.w_ != w_)
        throw std::runtime_error("operator= called with incompatible bit array");
    for (unsigned i = 0; i < intcount_; i++)
    {
        d_[i] = o.d_[i];
    }
    bsvalid_ = o.bsvalid_;
    if (bsvalid_)
    {
        if (bscount_ == nullptr)
            bscount_ = new unsigned[w_];
        for (unsigned i = 0; i < w_; i++)
        {
            bscount_[i] = o.bscount_[i];
        }
    }
    return *this;
}

unsigned BitArray::getBitSetCount(unsigned index) const
{
    if (bscount_ == nullptr)
        bscount_ = new unsigned[w_];
    if (!bsvalid_)
    {
        unsigned p = 0;
        for (unsigned i = 0; i < w_; i++)
        {
            bscount_[i] = 0;
            if (!get(i))
            {
                for (unsigned j = p; j < i; j++)
                {
                    bscount_[j] = i - j;
                }
                p = i + 1;
            }
        }
        for (unsigned j = p; j < w_; j++)
        {
            bscount_[j] = w_ - j;
        }
        bsvalid_ = true;
    }
    return bscount_[index];
}

char *BitArray::internalBuffer()
{
    return static_cast<char *>(static_cast<void *>(d_));
}
unsigned BitArray::internalBufferSize()
{
    return intcount_ * sizeof(I);
}

void BitArray::recoverFromEndianness(unsigned alignment, endian_t endianness)
{
    if (intcount_ <= 0)
        return;

#if ETISS_USE_BYTESWAP_H
    if (sizeof(I) == alignment)
    {
        if (endianness != getEndianness())
        {
            if (sizeof(I) == 4)
            {
                for (unsigned i = 0; i < intcount_; i++)
                {
                    d_[i] = __bswap_32(d_[i]);
                }
            }
            else
            {
                // TODO
                etiss::log(etiss::FATALERROR, "bit swap notimplemented for this case", alignment, endianness, sizeof(I),
                           ETISS_SRCLOC);
            }
        }
    }
    else
    {
        etiss::log(etiss::FATALERROR, "bit swap notimplemented for this case", alignment, endianness, sizeof(I),
                   ETISS_SRCLOC);
    }
#else

    if (sizeof(I) == alignment)
    {
        if (endianness != getEndianness())
        {
            for (unsigned i = 0; i < intcount_; i++)
            {
                for (unsigned j = 0; j < (sizeof(I) >> 1); j++)
                {
                    int8_t tmp = ((int8_t *)&(d_[i]))[j];
                    ((int8_t *)&(d_[i]))[j] = ((int8_t *)&(d_[i]))[sizeof(I) - 1 - j];
                    ((int8_t *)&(d_[i]))[sizeof(I) - 1 - j] = tmp;
                }
            }
        }
    }
    else
    {
        etiss::log(etiss::FATALERROR, "bit swap notimplemented for this case", alignment, endianness, sizeof(I),
                   ETISS_SRCLOC);
    }

#endif
}

const unsigned etiss::instr::BitArray::aaddr_mask_ = etiss_instr_generateMask();
const unsigned etiss::instr::BitArray::aaddr_shift_ = etiss_instr_sqrt_2pow(sizeof(I) * 8);

std::ostream &operator<<(std::ostream &os, const BitArray tf)
{
    os << "0x";
    if (tf.wordCount() <= 0)
    {
        return os;
    }
    auto flagold = os.flags();
    auto widthold = os.width();
    auto fillold = os.fill();
    os.flags(std::ios::right | std::ios::hex);
    os.fill('0');
    os.width((tf.byteCount() - sizeof(I) * (tf.wordCount() - 1)) * 2);
    os << std::setw((tf.byteCount() * 8 - sizeof(I) * (tf.wordCount() - 1) * 8) >> 2)
       << tf.getWord((tf.wordCount() - 1));
    for (int i = ((int)tf.wordCount()) - 2; i >= 0; i--)
        os << std::setw((sizeof(I) * 8) >> 2) << tf.getWord(i);
    os.flags(flagold);
    os.width(widthold);
    os.fill(fillold);
    return os;
}

BitArrayRange::BitArrayRange(unsigned startindex_included, unsigned endindex_included)
    : filterStart_(startindex_included), filterEnd_(endindex_included), filterLen_(filterStart_ + 1 - filterEnd_)
{
    assert(filterStart_ + 1 >= filterEnd_ && "Invalid BitArrayRange constructor arguments");
    assert(filterLen_ <= sizeof(I) * 8 && "Invalid BitArrayRange width");

    lowPartShift_ = filterEnd_ % Ibits;
    if (lowPartShift_ + filterLen_ <= Ibits)
    {
        needsSplitAccess_ = false;
        dataArrayIndex_ = (filterEnd_ - lowPartShift_) / Ibits;
        for (unsigned i = 0; i < filterLen_; i++)
        {
            lowPartMask_ = (lowPartMask_ << 1) | 1;
        }
    }
    else
    {
        needsSplitAccess_ = true;
        highPartShift_ = Ibits - lowPartShift_;
        dataArrayIndex_ = (filterEnd_ - lowPartShift_) / Ibits;
        for (unsigned i = 0; i < highPartShift_; i++)
        {
            lowPartMask_ = (lowPartMask_ << 1) | 1;
        }
        for (unsigned i = 0; i < (lowPartShift_ + filterLen_) * Ibits; i++)
        {
            highPartMask_ = (highPartMask_ << 1) | 1;
        }
    }
}

I BitArrayRange::read(const BitArray &ba)
{
    assert(ba.w_ > filterStart_ && "BitArrayRange outside of BitArray");

    I ret = (ba.d_[dataArrayIndex_] >> lowPartShift_) & lowPartMask_;
    if (needsSplitAccess_)
    {
        ret |= (ba.d_[dataArrayIndex_ + 1] & highPartMask_) << highPartShift_;
    }
    return ret;
}
void BitArrayRange::write(const BitArray &ba, I val)
{
    assert(ba.w_ > filterStart_ && "BitArrayRange outside of BitArray");

    ba.d_[dataArrayIndex_] =
        ((val & lowPartMask_) << lowPartShift_) | (ba.d_[dataArrayIndex_] & ~(lowPartMask_ << lowPartShift_));
    if (needsSplitAccess_)
    {
        ba.d_[dataArrayIndex_ + 1] =
            ((val >> highPartShift_) & highPartMask_) | (ba.d_[dataArrayIndex_ + 1] & ~highPartMask_);
    }
}

void BitArrayRange::setAll(const BitArray &ba, bool val)
{
    if (!val)
    {
        write(ba, 0);
    }
    else
    {
        typedef std::make_signed<I>::type SI;
        write(ba, (I)((SI)-1));
    }
}

unsigned BitArrayRange::start()
{
    return filterStart_;
}
unsigned BitArrayRange::end()
{
    return filterEnd_;
}

OPCode::OPCode(const BitArray &code, const BitArray &mask) : code_(code & mask), mask_(mask)
{
    if (code_.width() != mask_.width())
    {
        etiss::log(etiss::ERROR, "etiss::instr::OPCode constructed with code and mask of different widths");
        throw std::runtime_error("etiss::instr::OPCode constructed with code and mask of different widths");
    }
#if DEBUG
    if (!((code & mask) == code))
    {
        etiss::log(etiss::WARNING, "etiss::instr::OPCode constructed with mismatched code and mask");
    }
#endif
}

OPCode::OPCode(const OPCode &cpy) : code_(cpy.code_), mask_(cpy.mask_) {}

bool OPCode::operator<(const OPCode &o) const
{
    if (mask_ != o.mask_)
        return mask_ < o.mask_;
    if (code_ != o.code_)
        return code_ < o.code_;
    return false;
}

bool less::operator()(const OPCode *const &o1, const OPCode *const &o2) const
{

    if ((o1 == 0) || (o2 == 0))
    {
        if (o2 != 0)
            return true;
        etiss_log(FATALERROR, "null pointer passed to etiss::instr::less");
        return false;
    }

    return (*o1) < (*o2);
}

Node::Node() : subs_(nullptr), reader_(nullptr) {}
Node::~Node()
{
    if (subs_ != nullptr && reader_ != nullptr)
    {
        const unsigned w(reader_->start() + 1 - reader_->end());
        for (I i = 0; i < (I(1) << w); i++)
        {
            if (subs_[i])
            {
                if (!subs_[i]->isInstruction()) // instruction objects are managed by InstructionSet
                {
                    delete subs_[i];
                }
            }
        }
        delete[] subs_;
        delete reader_;
    }
}
// Helper node to differentiate between instructions that have the same opcode
// but a different mask. The more specific mask will match first, the delegate
// to another node which may also be an OverlappedNode.
class OverlappedNode : public Node, public etiss::ToString
{
public:
    etiss_del_como(OverlappedNode)

    OverlappedNode(Instruction *matchInstr, Node *delegateNode)
        : m_matchInstr(matchInstr)
        , m_delegateNode(delegateNode)
    {
    }

    Instruction *resolve(BitArray &instr) override
    {
        auto &mask = m_matchInstr->opc_.mask_;
        BitArrayRange reader(mask.width() - 1, 0);
        if ((reader.read(instr) & reader.read(mask)) == reader.read(m_matchInstr->opc_.code_))
        {
            return m_matchInstr;
        }
        return m_delegateNode->resolve(instr);
    }

    Instruction *m_matchInstr;
    Node *m_delegateNode;
};
static void AssertOnTrueCollision(Instruction *i1, Instruction *i2)
{
    if (i1->opc_ == i2->opc_)
    {
        etiss::log(etiss::FATALERROR, "ISA contains the same instruction multiple times!");
    }
}
static void HandleCollision(Instruction *instr, Node *&node)
{
    auto otherInstr = dynamic_cast<Instruction*>(node);
    if (otherInstr)
    {
        AssertOnTrueCollision(instr, otherInstr);
        if ((instr->opc_.mask_ & otherInstr->opc_.mask_) == instr->opc_.mask_)
        {
            node = new OverlappedNode(otherInstr, instr);
        } else {
            node = new OverlappedNode(instr, node);
        }
    } else {
        auto otherNode = dynamic_cast<OverlappedNode*>(node);
        if (otherNode)
        {
            AssertOnTrueCollision(instr, otherNode->m_matchInstr);
            if ((instr->opc_.mask_ & otherNode->m_matchInstr->opc_.mask_) == instr->opc_.mask_)
            {
                auto replacedNode = otherNode->m_delegateNode;
                auto replInstr = dynamic_cast<Instruction*>(replacedNode);
                BitArray replacedMask(instr->opc_.mask_.width());
                if (replInstr)
                {
                    AssertOnTrueCollision(instr, replInstr);
                    replacedMask = replInstr->opc_.mask_;
                } else {
                    auto replSpecNode = dynamic_cast<OverlappedNode*>(replacedNode);
                    if (replSpecNode)
                    {
                        replacedMask = replSpecNode->m_matchInstr->opc_.mask_;
                    } else {
                        etiss::log(etiss::FATALERROR, "OverlappedNode delegate must not be a plain Node");
                    }
                }
                if ((instr->opc_.mask_ & replacedMask) == instr->opc_.mask_)
                {
                    if (replInstr) {
                        otherNode->m_delegateNode = new OverlappedNode(replInstr, instr);
                    } else {
                        etiss::log(etiss::FATALERROR, "OverlappedNode delegate must not be a plain Node");
                    }
                } else {
                    otherNode->m_delegateNode = new OverlappedNode(instr, replacedNode);
                }
            } else {
                node = new OverlappedNode(instr, otherNode);
            }
        } else {
            etiss::log(etiss::FATALERROR, "OverlappedNode delegate must not be a plain Node");
        }
    }
}
void Node::compile(const std::map<const OPCode *, Instruction *, etiss::instr::less> &instrmap_, const BitArray &used,
                   bool &ok, std::list<std::string> &warnings, std::list<std::string> &errors)
{
    using MapType = std::remove_const<std::remove_reference<decltype(instrmap_)>::type>::type;

    // This masks bits that have already been compiled.
    BitArray mask(~used);
    // Build mask that has only the bits set that are present in all masks.
    for (const auto &op2instr : instrmap_)
    {
        mask = mask & op2instr.first->mask_;
    }

    for (unsigned i = 0; i < mask.width(); i++)
    {
        unsigned bsc = mask.getBitSetCount(i);
        bsc = std::min(bsc, (unsigned)(sizeof(I) * 8) - 1);
        if (bsc == 0)
            continue;

        reader_ = new BitArrayRange(i + bsc - 1, i);
        size_t size = static_cast<size_t>(1) << bsc;
        subs_ = new Node *[size]();
        auto sub_maps = new MapType *[size]();

        // Only set the bits from the current bit set being examined.
        mask.setAll(false);
        reader_->setAll(mask, true);
        const BitArray newused(used | mask);

        for (const auto &op2instr : instrmap_)
        {
            auto &op = op2instr.first;
            auto &instr = op2instr.second;
            auto &node = subs_[reader_->read(op->code_)];
            auto &sub_map = sub_maps[reader_->read(op->code_)];

            // Is this a finalized instruction?
            if (op->mask_ == newused)
            {
                // Check if there was already a node.
                if (node)
                {
                    // Try to convert existing node to overlap node.
                    if (!sub_map || sub_map->empty())
                    {
                        etiss::log(etiss::FATALERROR, "Expecting non-empty sub_map for existing node");
                    }
                    else
                    {
                        Node *replaceNode = sub_map->begin()->second;
                        for (const auto &subInstr : *sub_map)
                        {
                            HandleCollision(subInstr.second, replaceNode);
                        }
                        HandleCollision(instr, replaceNode);
                        delete node;
                        node = replaceNode;
                    }
                }
                else
                {
                    node = instr;
                }
            }
            else
            {
                if (!sub_map)
                {
                    if (node)
                    {
                        HandleCollision(instr, node);
                    }
                    else
                    {
                        node = new Node();
                        sub_map = new MapType();
                    }
                }
                if (sub_map)
                {
                    if (!sub_map->insert(op2instr).second)
                    {
                        etiss_log(ERROR, "failed to store instruction in map");
                    }
                }
            }
        }

        for (size_t j = 0; j < size; j++)
        {
            if (sub_maps[j])
            {
                subs_[j]->compile(*sub_maps[j], newused, ok, warnings, errors);
                delete sub_maps[j];
            }
        }
        delete[] sub_maps;
        // Done with the given tree.
        return;
    }

    ok = true;
}
Instruction *Node::resolve(BitArray &instr)
{
#if DEBUG
    if (subs_ == nullptr || reader_ == nullptr)
        etiss::log(etiss::FATALERROR, "etiss::instr::Node::resolve called witout a previous valid compilation call");
#endif
    Node *sub = subs_[reader_->read(instr)];
    if (unlikely(sub == nullptr))
    {
        return nullptr;
    }
    return sub->resolve(instr);
}
bool Node::isInstruction()
{
    return false;
}
std::string Node::print(std::string indent, I pos, unsigned pfillwidth, bool printunused)
{
    std::stringstream ss;
    if (reader_ != nullptr && subs_ != nullptr)
    {
        ss << indent << "@0x" << std::hex << std::setw(pfillwidth) << pos << std::dec << " Node[" << reader_->start()
           << ":" << reader_->end() << "]\n";
        ss.fill('0');
        std::string newindent = indent + "\t";
        const unsigned w(reader_->start() + 1 - reader_->end());
        int fillwidth = w >> 2;
        if (w % 4)
            fillwidth++;
        for (I i = 0; i < (I(1) << w); i++)
        {
            Node *n = subs_[i];
            if (n == nullptr)
            {
                if (printunused)
                {
                    ss << indent << "\t@0x" << std::hex << std::setw(fillwidth) << i << std::dec << " UNUSED\n";
                }
            }
            else
            {
                ss << n->print(newindent, i, fillwidth, printunused);
            }
        }
    }
    else
    {
        ss << indent << "@0x" << std::hex << pos << std::dec << " Uninitialized Node\n";
    }
    return ss.str();
}

unsigned &InstructionContext::ufield(std::string name)
{
    return ufields_[name];
}

Instruction::Instruction(const OPCode &opc, const std::string &name)
    : builtinGroups_(0), printer_(printASMSimple), opc_(opc), name_(name)
{
}
std::string Instruction::printASMSimple(BitArray &ba, Instruction &instr)
{
    std::stringstream ss;
    ss << instr.name_ << " # 0x" << ba << " [UNKNOWN PARAMETERS]";
    return ss.str();
}

void Instruction::compile(const std::map<const OPCode *, Instruction *, etiss::instr::less> &instrmap_,
                          const BitArray &used, bool &ok, std::list<std::string> &warnings,
                          std::list<std::string> &errors)
{
    etiss::log(etiss::FATALERROR, "Instruction::compile should NEVER be called.");
}
Instruction *Instruction::resolve(BitArray &instr)
{
    return this; // already parse instruction?
}
bool Instruction::isInstruction()
{
    return true;
}
std::string Instruction::print(std::string indent, I pos, unsigned pfillwidth, bool printunused)
{
    std::stringstream ss;
    ss.fill('0');
    ss << indent << "@0x" << std::hex << std::setw(pfillwidth) << pos << std::dec << " Instruction: " << name_ << "\n";
    return ss.str();
}
bool Instruction::addCallback(std::function<bool(BitArray &, etiss::CodeSet &, InstructionContext &)> callback,
                              uint32_t builtinGroups, const std::set<uint32_t> &groups)
{

    if ((builtinGroups_ & builtinGroups) != 0)
    {
        etiss::log(etiss::VERBOSE, "cannot add instruction translation callback due to overlapping builtin group",
                   *this);
        return false;
    }
    for (auto iter = groups.begin(); iter != groups.end(); iter++)
    {
        if (groups_.find(*iter) != groups_.end())
        {
            etiss::log(etiss::VERBOSE, "cannot add instruction translation callback due to overlapping group", *this);
            return false;
        }
    }

    if (!callback)
    {
        etiss::log(etiss::VERBOSE, "empty instruction translation callback", *this);
        return false;
    }

    builtinGroups_ |= builtinGroups;
    for (auto iter = groups.begin(); iter != groups.end(); iter++)
    {
        groups_.insert(*iter);
    }

    callbacks_.push_back(std::tuple<std::function<bool(BitArray &, etiss::CodeSet &, InstructionContext &)>, uint32_t,
                                    std::set<uint32_t>>(callback, builtinGroups, groups));

    return true;
}
bool Instruction::translate(BitArray &ba, CodeSet &cs, InstructionContext &context)
{
    bool ok = true;
    for (auto iter = callbacks_.begin(); iter != callbacks_.end(); iter++)
    {
        ok = ok & std::get<0>(*iter)(ba, cs, context);
    }
    return ok;
}

uint32_t &Instruction::presentBuiltinGroups()
{
    return builtinGroups_;
}
std::set<uint32_t> &Instruction::presentGroups()
{
    return groups_;
}

std::string Instruction::printASM(BitArray &ba)
{
    return printer_(ba, *this);
}

void Instruction::setASMPrinter(std::function<std::string(BitArray &, Instruction &)> printer)
{
    printer_ = printer;
    if (!printer_)
        printer_ = printASMSimple;
}

InstructionSet::InstructionSet(VariableInstructionSet &parent, unsigned width, const std::string &name)
    : parent_(parent), name_(name), width_(width), root_(nullptr), invalid(width, -1, -1, "INVALID")
{

    invalid.addCallback(
        [](BitArray &ba, CodeSet &cs, InstructionContext &ic) {
            std::stringstream ss;
            ss << "\t\treturn ETISS_RETURNCODE_ILLEGALINSTRUCTION;";
            //#if DEBUG
            ss << " // @0x" << std::hex << ic.current_address_ << std::dec << ": " << ba;
            //#endif
            ss << "\n";
            cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() = ss.str();
            return true;
        },
        0);
}
InstructionSet::~InstructionSet()
{
    delete root_;
    auto iter = instrmap_.begin();
    // delete instructions
    while (iter != instrmap_.end())
    {
        Instruction *i = iter->second;
        instrmap_.erase(iter);
        iter = instrmap_.begin();
        delete i;
    }
}

Instruction *InstructionSet::get(const OPCode &key)
{
    auto f = instrmap_.find(&key);
    if (f != instrmap_.end())
    {
        return f->second;
    }
    return nullptr;
}
Instruction &InstructionSet::open(const OPCode &key, const std::string &name)
{
    Instruction *ret = get(key);
    if (ret != nullptr)
        return *ret;
    ret = create(key, name);
#if DEBUG
    if (ret == nullptr)
    {
        etiss_log(FATALERROR, "should not happen");
    }
#endif
    return *ret;
}
Instruction *InstructionSet::create(const OPCode &key, const std::string &name)
{
    auto f = instrmap_.find(&key);
    if (f != instrmap_.end())
    {
        return nullptr;
    }
    Instruction *ret = new Instruction(key, name);
    if (instrmap_.insert(std::pair<const OPCode *, Instruction *>(&ret->opc_, ret)).second == false)
    {
        etiss::log(ERROR, "Failed to add instruction to instrmap_.", name, *this);
        delete ret;
        return nullptr;
    }
    return ret;
}

bool InstructionSet::compile()
{
    delete root_; // cleanup
    root_ = nullptr;

    root_ = new Node();

    std::list<std::string> warnings;
    std::list<std::string> errors;

    bool ok = true;

    BitArray emptymask(width_);
    emptymask.setAll(false);

    root_->compile(instrmap_, emptymask, ok, warnings, errors);

    for (auto iter = warnings.begin(); iter != warnings.end(); iter++)
        etiss::log(etiss::WARNING, *iter);

    for (auto iter = errors.begin(); iter != errors.end(); iter++)
        etiss::log(etiss::ERROR, *iter);

    if (!ok)
    {
        delete root_;
        root_ = nullptr;
    }

    return ok;
}

Instruction *InstructionSet::resolve(BitArray &instr)
{
    return root_->resolve(instr);
}

std::string InstructionSet::print(std::string prefix, bool printunused)
{
    if (root_ != nullptr)
    {
        std::stringstream ss;
        ss << prefix << name_ << "[" << width_ << "]:\n";
        ss << root_->print(prefix + "\t", 0, 1, printunused);
        return ss.str();
    }
    else
    {
        return "EMPTY\n";
    }
}

Instruction &InstructionSet::getInvalid()
{
    return invalid;
}

void InstructionSet::foreach (std::function<void(Instruction &)> func)
{
    for (auto iter = instrmap_.begin(); iter != instrmap_.end(); iter++)
    {
#if DEBUG
        if (iter->second != nullptr)
        {
#endif
            func(*iter->second);
#if DEBUG
        }
        else
        {
            etiss::log(etiss::ERROR, "InstructionSet::getInvalid found a null pointer");
        }
#endif
    }
}

size_t InstructionSet::size()
{
    return instrmap_.size();
}

VariableInstructionSet::VariableInstructionSet(ModedInstructionSet &parent, unsigned width, const std::string &archname)
    : parent_(parent), width_(width), archname_(archname)
{
    length_updater_ = [this](VariableInstructionSet &, InstructionContext &con, BitArray &) {
        con.is_not_default_width_ = false;
        con.instr_width_ = width_;
    };
}
VariableInstructionSet::~VariableInstructionSet()
{
    // delete instruction set
    for (auto iter = ismap_.begin(); iter != ismap_.end(); iter++)
    {
        delete iter->second;
    }
}

bool VariableInstructionSet::compile()
{
    bool ok = true;
    for (auto iter = ismap_.begin(); iter != ismap_.end();)
    {
        if (iter->second->size() <= 0)
        {
            etiss::log(etiss::WARNING, "Removed empty etiss::instr::InstructionSet during compilation.", *iter->second);
            ismap_.erase(iter++);
        }
        else
        {
            ok = ok & iter->second->compile();
            iter++;
        }
    }
    if (ismap_.begin() != ismap_.end())
        width_ = ismap_.begin()->first;
    return ok;
}

InstructionSet *VariableInstructionSet::get(unsigned width)
{
    auto f = ismap_.find(width);
    if (f != ismap_.end())
        return f->second;
    return nullptr;
}
InstructionSet *VariableInstructionSet::create(unsigned width, const std::string &name)
{
    auto f = ismap_.find(width);
    if (f != ismap_.end())
        return nullptr;
    InstructionSet *ret = new InstructionSet(*this, width, name);
    ismap_[width] = ret;
    return ret;
}
InstructionSet &VariableInstructionSet::open(unsigned width, const std::string &name)
{
    InstructionSet *ret = get(width);
    if (ret != nullptr)
    {
        return *ret;
    }
    return *create(width, name);
}

void VariableInstructionSet::foreach (std::function<void(InstructionSet &)> call)
{
    for (auto iter = ismap_.begin(); iter != ismap_.end(); iter++)
    {
        if (iter->second != nullptr)
        {
            call(*(iter->second));
        }
        else
        {
            etiss_log(ERROR, "invalid pointer in ismap_.");
        }
    }
}

std::string VariableInstructionSet::print(std::string prefix)
{
    std::stringstream ss;
    ss << prefix << archname_ << "[default: " << width_ << "]:\n";
    foreach ([&ss, &prefix](InstructionSet &is) { ss << is.print(prefix + "\t"); })
        ;
    return ss.str();
}

ModedInstructionSet::ModedInstructionSet(const std::string &name) : archname_(name) {}
ModedInstructionSet::~ModedInstructionSet()
{
    // delete variable instruction sets
    for (auto iter = vismap_.begin(); iter != vismap_.end(); ++iter)
    {
        delete iter->second;
    }
}
VariableInstructionSet *ModedInstructionSet::get(uint32_t mode)
{
    auto f = vismap_.find(mode);
    if (f != vismap_.end())
        return f->second;
    return nullptr;
}
VariableInstructionSet *ModedInstructionSet::create(uint32_t mode, unsigned width, const std::string &name)
{
    auto f = vismap_.find(mode);
    if (f != vismap_.end())
    {
#if DEBUG
        if (f->second->width_ != width)
        {
            etiss_log(ERROR, "missmatch width values");
        }
#endif
        return nullptr;
    }
    VariableInstructionSet *ret = new VariableInstructionSet(*this, width, name);
    vismap_[mode] = ret;
    invvismap_[ret] = mode;
    return ret;
}
VariableInstructionSet &ModedInstructionSet::open(uint32_t mode, unsigned width, const std::string &name)
{
    VariableInstructionSet *ret = get(mode);
    if (ret != nullptr)
    {
#if DEBUG
        if (ret->width_ != width)
        {
            etiss_log(ERROR, "missmatch width values");
        }
#endif
        return *ret;
    }
    return *create(mode, width, name);
}
uint32_t ModedInstructionSet::getMode(VariableInstructionSet *vis)
{
    auto iter = invvismap_.find(vis);
    if (iter != invvismap_.end())
        return iter->second;
    etiss_log(ERROR,
              "variable instruction set mode cannot be found since this moded instruction set is not its parent");
    return (uint32_t)-1;
}

void ModedInstructionSet::foreach (std::function<void(VariableInstructionSet &)> call)
{
    for (auto iter = vismap_.begin(); iter != vismap_.end(); iter++)
    {
        if (iter->second != nullptr)
        {
            call(*(iter->second));
        }
        else
        {
            etiss_log(ERROR, "invalid pointer in vismap_.");
        }
    }
}

bool ModedInstructionSet::compile()
{
    bool ok = true;
    foreach ([&ok](VariableInstructionSet &vis) { ok = ok & vis.compile(); })
        ;
    return ok;
}

std::string ModedInstructionSet::print(std::string prefix)
{
    std::stringstream ss;
    ss << prefix << archname_ << ":\n";
    foreach ([&ss, &prefix](VariableInstructionSet &vis) {
        ss << prefix << "MODE " << vis.parent_.getMode(vis) << ": ";
        ss << vis.print(prefix + "\t");
    })
        ;
    return ss.str();
}

void InstructionCollection::addTo(ModedInstructionSet &set, bool &ok)
{
    foreach ([&set, &ok](InstructionClass &klass) {
        VariableInstructionSet &vis = set.open(klass.mode_, klass.width_, klass.name_);
        klass.addTo(vis, ok);
    })
        ;
}
void InstructionClass::addTo(VariableInstructionSet &set, bool &ok)
{
    foreach ([&set, &ok](InstructionGroup &group) {
        InstructionSet &is = set.open(group.width_, group.name_);
        group.addTo(is, ok);
    })
        ;
}
void InstructionGroup::addTo(InstructionSet &set, bool &ok)
{
    foreach ([&set, &ok](InstructionDefinition &id) {
        Instruction *instr = set.create(id.opc_, id.name_);
        if (instr == nullptr)
        {
            ok = false;
            etiss::log(ERROR, "failed to add InstructionDefinition to Instruction set.", id, set);
            return;
        }
        id.addTo(*instr, ok);
    })
        ;
}
void InstructionDefinition::addTo(Instruction &instr, bool &ok)
{

    if (!(opc_ == instr.opc_))
    {
        etiss::log(etiss::ERROR, "cannot add instruction definition to instruction.", *this, instr);
        ok = false;
        return;
    }
    etiss::log(VERBOSE, "Added instruction definition to instruction.", *this, instr);
    instr.addCallback(callback_, builtinGroups_);
    if (ASMprinter_)
    {
        instr.setASMPrinter(ASMprinter_);
    }
}

#if __cplusplus >= 201103L
uint32_t operator"" _i32(const char *s)
{
    return parse_i32(s);
}
#endif
uint32_t parse_i32(const char *s)
{
    return parse_i<uint32_t>(s);
}

} // namespace instr

} // namespace etiss
