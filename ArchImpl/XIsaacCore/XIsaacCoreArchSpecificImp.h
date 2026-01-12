/**
 * Generated on Mon, 10 Nov 2025 11:27:12 +0000.
 *
 * This file contains the architecture specific header for the XIsaacCore
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_XIsaacCoreArch_XIsaacCoreARCHSPECIFICIMP_H_
#define ETISS_XIsaacCoreArch_XIsaacCoreARCHSPECIFICIMP_H_

#include <cstdint>
#include "etiss/Instruction.h"
#include "etiss/VirtualStruct.h"
#include "etiss/jit/CPU.h"
#include "XIsaacCore.h"

/**
    @brief VirtualStruct for XIsaacCore architecture to faciliate register acess

    @details VirtualStruct enables user to access certain register via their name without knowning ETISS hierarchy of a
    core. Further fiels might be needed to enable gdbserver etc.

*/
class RegField_XIsaacCore : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    RegField_XIsaacCore(etiss::VirtualStruct &parent, unsigned gprid)
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

    RegField_XIsaacCore(etiss::VirtualStruct &parent, std::string name, unsigned gprid)
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

    virtual ~RegField_XIsaacCore() {}

  protected:
    virtual uint64_t _read() const
    {
        // clang-format off
        return (uint64_t) *((XIsaacCore*)parent_.structure_)->X[gprid_];
        // clang-format on
    }

    virtual void _write(uint64_t val)
    {
        // clang-format off
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *((XIsaacCore*)parent_.structure_)->X[gprid_] = (etiss_uint32) val;
        // clang-format on
    }
};

class pcField_XIsaacCore : public etiss::VirtualStruct::Field
{
  public:
    pcField_XIsaacCore(etiss::VirtualStruct &parent)
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

    virtual ~pcField_XIsaacCore() {}

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
