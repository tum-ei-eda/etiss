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

        @brief

        @detail

*/
#include "etiss/Instruction.h"

#include <sstream>
#include <cassert>
#include <cmath>
#if ETISS_USE_BYTESWAP_H
#include <byteswap.h>
#endif

namespace etiss
{

namespace instr
{

typedef BitArray::size_type size_type;

char* Buffer::internalBuffer()
{
    return static_cast<char *>(static_cast<void *>(d_));
}
unsigned Buffer::internalBufferSize()
{
    return intcount_ * sizeof(I);
}

void Buffer::recoverFromEndianness(unsigned alignment, endian_t endianness)
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

unsigned BitArray::byteCount() const {
    unsigned mod = size() % (8);
    unsigned ret = (size() - mod) / (8);
    if (mod > 0) ret++;
    return ret;
}
unsigned BitArray::intCount() const {
    unsigned mod = size() % (sizeof(I) * 8);
    unsigned ret = (size() - mod) / (sizeof(I) * 8);
    if (mod > 0) ret++;
    return ret;
}

std::vector<BitArray> BitArray::permutate(const BitArray& input, std::vector<size_type> indexes)
{
    std::vector<BitArray> results{input};
    int count = 0;
    for(const auto& i : indexes){
        for(int j=0; j<(1<<count); j++){
            results.push_back(results[j]);
            results[j].flip(i);
            results.push_back(results[j]);
        }
        results.erase(results.begin(), results.begin() + (1<<count));
        count++;
    }
    return results;
}

void BitArray::set_value(size_type width, unsigned long value){
    BitArray b(width, value);
    *this = b;
}

void BitArray::set_value(unsigned long value){
    set_value(size(), value);
}

BitArray BitArray::get_range(size_type end, size_type start) const
{
    // shift the bits and resize it accordingly
    BitArray ret = *this;
    ret >>= start;
    ret.resize(end-start+1);
    return ret;
}

void BitArray::set_range(unsigned long val, size_type end, size_type start){
    auto len = end - start + 1;
    BitArray range(len, val);
    for(size_type i = 0; i < len; ++i)
        (*this)[i+start] = range[i];
}

std::string BitArray::to_string() const
{
    std::string s;
    boost::to_string(*this, s);
    return s;
}

BitArrayRange::BitArrayRange(unsigned endindex_included, unsigned startindex_included)
    : startpos(startindex_included), endpos(endindex_included) {}

I BitArrayRange::read(const BitArray& ba)
{
    assert(ba.size() > (endpos - startpos + 1) && "BitArrayRange outside of BitArray");
    auto range = ba.get_range(endpos, startpos);
    return range.to_ulong();
}

void BitArrayRange::write(BitArray &ba, I val)
{
    assert(ba.size() > (endpos - startpos + 1) && "BitArrayRange outside of BitArray");
    ba.set_range(val, endpos, startpos);
}

BitArray::size_type BitArrayRange::start()
{
    return startpos;
}

BitArray::size_type BitArrayRange::end()
{
    return endpos;
}

OPCode::OPCode(const BitArray &code, const BitArray &mask) : code_(code & mask), mask_(mask)
{
    if (code_.size() != mask_.size())
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

unsigned &InstructionContext::ufield(std::string name)
{
    return ufields_[name];
}

Instruction::Instruction(const OPCode &opc, const std::string &name)
    : builtinGroups_(0), printer_(printASMSimple), opc_(opc), name_(name), width(opc.code_.size())
{
}
std::string Instruction::printASMSimple(BitArray &ba, Instruction &instr)
{
    std::stringstream ss;
    ss << instr.name_ << " # 0x" << ba << " [UNKNOWN PARAMETERS]";
    return ss.str();
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

InstructionSet::InstructionSet(VariableInstructionSet &parent, unsigned width, const std::string &name, unsigned c_size)
    : parent_(parent), name_(name), width_(width), root_(nullptr), invalid(width, -1, -1, "INVALID"), chunk_size(c_size)
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
    auto iter = instrmap_.begin();
    // delete instructions
    while (iter != instrmap_.end())
    {
        Instruction *i = iter->second;
        instrmap_.erase(iter);
        iter = instrmap_.begin();
        delete i;
    }
    for(int i = 0; i < width_ / chunk_size; i++)
        delete[] root_[i];
    delete root_;
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

    root_ = new Node*[width_ / chunk_size](); // number of groups = width_ / chunk_size

    bool ok = true;

    std::vector<size_type> indexes;
    for (const auto& op2instr : instrmap_){ // iterate through all instructions
        Instruction* inst = op2instr.second; // current instruction to be assigned
        BitArray code = op2instr.first->code_; // opcode of the current instruction
        BitArray mask = op2instr.first->mask_; // mask of the opcode

        // iterate through chunks and permutate chunks. then put them into nodes
        for (size_type i = 0; i < mask.size() / chunk_size; ++i){
            auto chunk_bits_code = code.get_range((i+1)*chunk_size-1, i*chunk_size); // ith chunk of the opcode
            auto chunk_bits_mask = mask.get_range((i+1)*chunk_size-1, i*chunk_size); // ith chunk of the mask

            indexes.clear();
            for (size_type j = 0; j < chunk_bits_mask.size(); ++j)
                if (!chunk_bits_mask[j]) indexes.push_back(j); // these indexed should be permutated since
                                                               // they dont have associated mask bit

            if(!(root_[i])) // not initialized
                root_[i] = new Node[(int)std::pow(2, chunk_size)]; // each group has 2^(chunksize) nodes

            auto permutated_chunk_codes = BitArray::permutate(chunk_bits_code, indexes); // put permutated codes

            for(const auto& permutated_chunk : permutated_chunk_codes){
                auto val = permutated_chunk.to_ulong(); // index of the node based on the value of the chunk
                root_[i][val].insert(inst); // assign the current instruction to the associated node
            }
        }
    }
    return ok;
}

Instruction *InstructionSet::resolve(BitArray &instr)
{
    std::set<Instruction*> results;
    for (size_type i = 0; i < instr.size() / chunk_size; ++i){ // divide the incoming bitarray into chunks
        auto chunk_bits_code = instr.get_range((i+1)*chunk_size-1, i*chunk_size); // get ith chunk

        auto val = chunk_bits_code.to_ulong(); // the value chunk is evaluated to,
                                               // which is also the index of the associated node
        auto instrs_in_node = root_[i][val]; // val'th node

        if(i==0) results = instrs_in_node;
        else{ // intersect all the associated nodes, the result will be the decoded instruction
            std::set<Instruction*> results_o;
            std::set_intersection(results.begin(), results.end(), // intersect the ith node with the
                instrs_in_node.begin(), instrs_in_node.end(),     // current results
                std::inserter(results_o, results_o.begin()));     // put overlapped instructions to results_o
            results = results_o; // write the overlapped instructions to results
        }
    }

    if(results.empty()) return nullptr; // there is no overlapped instruction after the decoding
    else if(results.size() == 1) return *(results.begin()); // instruction is found succesfully
    else{
        // sometimes an instruction can be a subset of another instruction and hence the
        // algorithm can find multiple instruction. In such cases, it is returning the parent
        // instruction by simply returning the instrucion whose opcode is the longest,
        // i.e mask has the most 1-bits.
        auto longest = std::max_element(results.begin(), results.end(),
            [](const Instruction* lhs, const Instruction* rhs) { return lhs->opc_.mask_.count() < rhs->opc_.mask_.count();});
        return *longest;
    }
}

std::string InstructionSet::print(std::string prefix, bool printunused)
{
    if (root_ != nullptr)
    {
        std::stringstream ss;
        ss << prefix << name_ << "[" << width_ << "]:\n";
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
