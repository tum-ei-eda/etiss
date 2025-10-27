// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief simple test system implementation with fault functionality

*/

#ifndef ETISS_INCLUDE_INTEGRATEDLIBRARY_FAULT_MEMORYMANIPULATIONSYSTEM_H_
#define ETISS_INCLUDE_INTEGRATEDLIBRARY_FAULT_MEMORYMANIPULATIONSYSTEM_H_
#include "etiss/System.h"
#include "etiss/make_unique.h"
#include <fstream>

#include "etiss/SimpleMemSystem.h"

#include "etiss/VirtualStruct.h"

#include <memory>
#include <map>
#include <stack>

#include <functional>

#include "etiss/fault/Misc.h"
#include "enum.h"

namespace etiss
{

BETTER_ENUM(MM_MemOpType, char, UNDEF = 0, COPY, AND, OR, XOR, NAND, NOR)
BETTER_ENUM(MM_MemManipCmd, char, UNDEF = 0, PUSH, POP, OR, RMW, RRMW)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Memory word faulter base class
class MemoryWordManipulatorBase
{
  public:
    typedef MM_MemOpType mem_op_t;
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Memory operation class
    class MemOp : mem_op_t
    {
      public:
        ////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief executes memory operation with operands \p src1 and \p src2 and returns result
        template <typename word_t>
        word_t operator()(word_t src1, word_t src2) const;
        ////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Constructor takes string encoded memory operation \ref MemOpType
        MemOp(const std::string &memop_str) : mem_op_t(mem_op_t::_from_string(memop_str.c_str())) {}
    } /* class MemOp */;

    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Memory operation type code
    typedef MM_MemManipCmd mem_manip_cmd_t;

    virtual etiss::int32 push(size_t address) = 0;
    virtual etiss::int32 pop(size_t address) = 0;
    virtual etiss::int32 rmw(size_t address, MemOp op, etiss::uint64 mod_val) = 0;
    virtual etiss::int32 rrmw(size_t dstsrc1_address, MemOp op, size_t src2_address) = 0;
} /* class MemoryWordManipulatorBase */;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Memory word faulter class template \p word_t
template <typename word_t>
class MemoryWordManipulator : public MemoryWordManipulatorBase
{
  private:
    std::function<word_t(size_t address, etiss::int32 &return_code)> mem_read_word_;
    ///< function to read a single word from memory
    std::function<void(size_t address, word_t val, etiss::int32 &return_code)> mem_write_word_;
    ///< function to write a single word to memory
    std::stack<word_t> memstack_{};
    ///< memory stack to allow read modify write manipulations to memory

  public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief pop the last added element from the memory stack and write it to memory \p address
    /// \return etiss::RETURNCODE encoded via \ref MemoryManipulationSystem::dbus_access
    virtual etiss::int32 pop(size_t address);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief read memory from \p address and push it to memory stack
    /// \return etiss::RETURNCODE encoded via \ref MemoryManipulationSystem::dbus_access
    virtual etiss::int32 push(size_t address);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief read-modify-write memory word at \p address with \p mod_val by bit-wise operation \p op
    /// \p mod_val is type casted to \p word_t
    /// \return etiss::RETURNCODE encoded via \ref MemoryManipulationSystem::dbus_access
    virtual etiss::int32 rmw(size_t address, MemOp op, etiss::uint64 mod_val);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief read-readmodify-write memory word at \p dstsrc1_address with memory word at
    /// \p src2_address by bit-wise operation \p op
    /// \return etiss::RETURNCODE encoded via \ref MemoryManipulationSystem::dbus_access
    virtual etiss::int32 rrmw(size_t dstsrc1_address, MemOp op, size_t src2_address);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Constructor taking \p mem_read_word and \p mem_write_word functions for memory
    /// fault action
    MemoryWordManipulator(
        std::function<word_t(size_t address, etiss::int32 &return_code)> const &mem_read_word,
        std::function<void(size_t address, word_t val, etiss::int32 &return_code)> const &mem_write_word);
} /* class MemoryWordManipulator */;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Simple etiss:System implementation for testing
class MemoryManipulationSystem : public VirtualStructSupport, public SimpleMemSystem
{
  public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Constructor takes \p name for reference of this class as a name \ref Injector
    MemoryManipulationSystem(const std::string &name = "system");
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief get virtual struct associated name
    inline const std::string &getName() { return name_; }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief get virtual struct
    std::shared_ptr<etiss::VirtualStruct> getStruct(void);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief initialize this virtual struct and mount it to \p cpu_core
    void init_manipulation(std::shared_ptr<etiss::VirtualStructSupport> vs_parent);

  private:
    std::string name_;
    etiss::uint8 arch_width_;
    std::shared_ptr<etiss::VirtualStruct> vsystem_;
    std::unique_ptr<etiss::MemoryWordManipulatorBase> mem_manipulator_;
};

/* template "implemenations" */
template <typename word_t>
word_t MemoryWordManipulatorBase::MemOp::operator()(word_t src1, word_t src2) const
{
    switch (*this)
    {
    case MM_MemOpType::COPY:
        return src2;
    case MM_MemOpType::AND:
        return (src1 & src2);
    case MM_MemOpType::OR:
        return (src1 | src2);
    case MM_MemOpType::XOR:
        return (src1 ^ src2);
    case MM_MemOpType::NAND:
        return ~(src1 & src2);
    case MM_MemOpType::NOR:
        return ~(src1 | src2);
    default:
        break;
    }
    return src1;
}

template <typename word_t>
etiss::int32 MemoryWordManipulator<word_t>::pop(size_t address)
{
    etiss::int32 return_code;
    mem_write_word_(address, memstack_.top(), return_code);
    memstack_.pop();
    return return_code;
}

template <typename word_t>
etiss::int32 MemoryWordManipulator<word_t>::push(size_t address)
{
    etiss::int32 return_code;
    memstack_.push(mem_read_word_(address, return_code));
    return return_code;
}

template <typename word_t>
etiss::int32 MemoryWordManipulator<word_t>::rmw(size_t address, MemOp op, etiss::uint64 mod_val)
{
    etiss::int32 return_code;
    word_t mem_val = mem_read_word_(address, return_code);
    if (return_code == RETURNCODE::NOERROR)
    {
        mem_val = op(mem_val, static_cast<word_t>(mod_val));
        mem_write_word_(address, mem_val, return_code);
    }
    return return_code;
}
template <typename word_t>
etiss::int32 MemoryWordManipulator<word_t>::rrmw(size_t dstsrc1_address, MemOp op, size_t src2_address)
{
    etiss::int32 return_code;
    word_t src1mem_val = mem_read_word_(dstsrc1_address, return_code);
    if (return_code == RETURNCODE::NOERROR)
    {
        word_t src2mem_val = mem_read_word_(src2_address, return_code);
        if (return_code == RETURNCODE::NOERROR)
        {
            src1mem_val = op(src1mem_val, src2mem_val);
            mem_write_word_(dstsrc1_address, src1mem_val, return_code);
        }
    }
    return return_code;
}
template <typename word_t>
MemoryWordManipulator<word_t>::MemoryWordManipulator(
    std::function<word_t(size_t address, etiss::int32 &return_code)> const &mem_read_word,
    std::function<void(size_t address, word_t val, etiss::int32 &return_code)> const &mem_write_word)
    : mem_read_word_(mem_read_word), mem_write_word_(mem_write_word)
{
}

} // namespace etiss

#endif // ETISS_INCLUDE_INTEGRATEDLIBRARY_FAULT_MEMORYMANIPULATIONSYSTEM_H_
