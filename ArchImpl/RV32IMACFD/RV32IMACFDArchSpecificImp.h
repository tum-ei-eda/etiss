/**
 * Generated on Mon, 10 Nov 2025 11:27:12 +0000.
 *
 * This file contains the architecture specific header for the RV32IMACFD
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV32IMACFDArch_RV32IMACFDARCHSPECIFICIMP_H_
#define ETISS_RV32IMACFDArch_RV32IMACFDARCHSPECIFICIMP_H_

#include <cstdint>
#include "etiss/Instruction.h"
#include "etiss/VirtualStruct.h"
#include "etiss/jit/CPU.h"
#include "RV32IMACFD.h"

/**
    @brief VirtualStruct for RV32IMACFD architecture to faciliate register acess

    @details VirtualStruct enables user to access certain register via their name without knowning ETISS hierarchy of a
    core. Further fiels might be needed to enable gdbserver etc.

*/
class RegField_RV32IMACFD : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    RegField_RV32IMACFD(etiss::VirtualStruct &parent, unsigned gprid)
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

    RegField_RV32IMACFD(etiss::VirtualStruct &parent, std::string name, unsigned gprid)
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

    virtual ~RegField_RV32IMACFD() {}

  protected:
    virtual uint64_t _read() const
    {
        // clang-format off
        return (uint64_t) *((RV32IMACFD*)parent_.structure_)->X[gprid_];
        // clang-format on
    }

    virtual void _write(uint64_t val)
    {
        // clang-format off
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *((RV32IMACFD*)parent_.structure_)->X[gprid_] = (etiss_uint32) val;
        // clang-format on
    }
};

class pcField_RV32IMACFD : public etiss::VirtualStruct::Field
{
  public:
    pcField_RV32IMACFD(etiss::VirtualStruct &parent)
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

    virtual ~pcField_RV32IMACFD() {}

  protected:
    virtual uint64_t _read() const
    {
        // clang-format off
        return (uint64_t) ((ETISS_CPU *)parent_.structure_)->instructionPointer;
        // clang-format on
    }

    virtual void _write(uint64_t val)
    {
        // clang-format off
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        ((ETISS_CPU *)parent_.structure_)->instructionPointer = (etiss_uint32) val;
        // clang-format on
    }
};

#endif
