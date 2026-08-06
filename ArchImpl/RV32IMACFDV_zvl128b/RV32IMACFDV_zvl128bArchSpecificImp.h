/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the architecture specific header for the RV32IMACFDV_zvl128b
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV32IMACFDV_zvl128bArch_RV32IMACFDV_zvl128bARCHSPECIFICIMP_H_
#define ETISS_RV32IMACFDV_zvl128bArch_RV32IMACFDV_zvl128bARCHSPECIFICIMP_H_

#include <cstdint>
#include "etiss/Instruction.h"
#include "etiss/VirtualStruct.h"
#include "etiss/jit/CPU.h"
#include "RV32IMACFDV_zvl128b.h"
#include "RV32IMACFDV_zvl128bFuncs.h"

/**
    @brief VirtualStruct for RV32IMACFDV_zvl128b architecture to faciliate register acess

    @details VirtualStruct enables user to access certain register via their name without knowning ETISS hierarchy of a
    core. Further fiels might be needed to enable gdbserver etc.

*/
class RegField_RV32IMACFDV_zvl128b : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    RegField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, unsigned gprid)
        // clang-format off
        : Field(
            parent,
            std::string("X") + etiss::toString(gprid),
            std::string("X") + etiss::toString(gprid),
            R|W,
            4
        ),
        // clang-format on
        gprid_(gprid)
    {
    }

    RegField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, std::string name, unsigned gprid)
        // clang-format off
        : Field(
            parent,
            name,
            name,
            R|W,
            4
        ),
        // clang-format on
        gprid_(gprid)
    {
    }

    virtual ~RegField_RV32IMACFDV_zvl128b() {}

  protected:
    virtual uint64_t _read(size_t offset) const
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        return (uint64_t) *((RV32IMACFDV_zvl128b*)parent_.structure_)->X[gprid_];
        // clang-format on
    }

    virtual void _write(uint64_t val, size_t offset)
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *((RV32IMACFDV_zvl128b*)parent_.structure_)->X[gprid_] = (etiss_uint32) val;
        // clang-format on
    }
};

class FloatRegField_RV32IMACFDV_zvl128b : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    FloatRegField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, unsigned gprid)
        // clang-format off
            : Field(parent,
              std::string("F")+etiss::toString(gprid),
              std::string("F")+etiss::toString(gprid),
              R|W,
              4
            ),
            gprid_(gprid)
    // clang-format on
    {
    }

    FloatRegField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, std::string name, unsigned gprid)
        // clang-format off
        : Field(parent,
              name,
              name,
              R|W,
              4
            ),
            gprid_(gprid)
    // clang-format on
    {
    }

    virtual ~FloatRegField_RV32IMACFDV_zvl128b() {}

  protected:
    virtual uint64_t _read(size_t offset) const
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        return (uint64_t) *((RV32IMACFDV_zvl128b*)parent_.structure_)->F[gprid_];
        // clang-format on
    }

    virtual void _write(uint64_t val, size_t offset)
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *((RV32IMACFDV_zvl128b*)parent_.structure_)->F[gprid_] = (etiss_uint32) val;
        // clang-format on
    }
};

class VectorRegField_RV32IMACFDV_zvl128b : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    VectorRegField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent,unsigned gprid)
        // clang-format off
        : Field(parent,
                std::string("V")+etiss::toString(gprid),
                std::string("V")+etiss::toString(gprid),
                R|W,
                16
        ),
        gprid_(gprid)
    // clang-format on
    {
    }

    VectorRegField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, std::string name, unsigned gprid)
        // clang-format off
        : Field(parent,
                name,
                name,
                R|W,
                16
        ),
        gprid_(gprid)
    // clang-format on
    {
    }

     virtual ~VectorRegField_RV32IMACFDV_zvl128b() {}

  protected:
    virtual uint64_t _read(size_t offset) const
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        return (uint64_t) *((uint64_t*)&((RV32IMACFDV_zvl128b*)parent_.structure_)->V[gprid_ * width_ + sizeof(uint64_t) * offset]);
        // clang-format on
    }

    virtual void _write(uint64_t val, size_t offset)
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *((uint64_t*)&((RV32IMACFDV_zvl128b*)parent_.structure_)->V[gprid_ * width_ + sizeof(uint64_t)]) = (etiss_uint64) val;  // TODO: write V[gprid_] instead
        // clang-format on
    }
};

class CSRField_RV32IMACFDV_zvl128b : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    CSRField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, unsigned gprid)
        // clang-format off
        : Field(parent,
            std::string("CSR")+etiss::toString(gprid),
            std::string("CSR")+etiss::toString(gprid),
            R|W,
            4
        ),
        gprid_(gprid)
    // clang-format on
    {
    }

    CSRField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent, std::string name, unsigned gprid)
        // clang-format off
      : Field(parent,
        name,
        name,
        R|W,
        4
      ),
      gprid_(gprid)
    // clang-format on
    {
    }

    virtual ~CSRField_RV32IMACFDV_zvl128b() {}

  protected:
    virtual uint64_t _read(size_t offset) const
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        return (uint64_t) RV32IMACFDV_zvl128b_csr_read((ETISS_CPU*)parent_.structure_, nullptr, nullptr, (etiss_uint32) gprid_);
        // clang-format on
    }

    virtual void _write(uint64_t val, size_t offset)
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        RV32IMACFDV_zvl128b_csr_write((ETISS_CPU*)parent_.structure_, nullptr, nullptr, gprid_, (etiss_uint32) val);
        // clang-format on
    }
};


class pcField_RV32IMACFDV_zvl128b : public etiss::VirtualStruct::Field
{
  public:
    pcField_RV32IMACFDV_zvl128b(etiss::VirtualStruct &parent)
        // clang-format off
        : Field(
            parent,
            "instructionPointer",
            "instructionPointer",
            R|W,
            4
        )
    // clang-format on
    {
    }

    virtual ~pcField_RV32IMACFDV_zvl128b() {}

  protected:
    virtual uint64_t _read(size_t offset) const
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        return (uint64_t) ((ETISS_CPU *)parent_.structure_)->instructionPointer;
        // clang-format on
    }

    virtual void _write(uint64_t val, size_t offset)
    {
        // clang-format off
        assert((offset == 0 || (offset < (bitwidth_ / sizeof(uint64_t)))) && "Virtualstruct field offset out of range");
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        ((ETISS_CPU *)parent_.structure_)->instructionPointer = (etiss_uint32) val;
        // clang-format on
    }
};

#endif
