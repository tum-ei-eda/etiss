/**
 * Generated on Wed, 19 Jun 2024 11:26:11 +0200.
 *
 * This file contains the architecture specific header for the RV32IMACFDV
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV32IMACFDVArch_RV32IMACFDVARCHSPECIFICIMP_H_
#define ETISS_RV32IMACFDVArch_RV32IMACFDVARCHSPECIFICIMP_H_

#include "RV32IMACFDVFuncs.h"

/**
	@brief VirtualStruct for RV32IMACFDV architecture to faciliate register acess

	@details VirtualStruct enables user to access certain register via their name without knowning ETISS hierarchy of a core.
				Further fiels might be needed to enable gdbserver etc.

*/
class RegField_RV32IMACFDV : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	RegField_RV32IMACFDV(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("X")+etiss::toString(gprid),
			std::string("X")+etiss::toString(gprid),
			R|W,
			4
		),
		gprid_(gprid)
	{}

	RegField_RV32IMACFDV(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			4
		),
		gprid_(gprid)
	{}

	virtual ~RegField_RV32IMACFDV(){}

protected:
	virtual uint64_t _read(size_t offset) const {
		printf("x_read with gprid_ %d\n", gprid_);
		return (uint64_t) *((RV32IMACFDV*)parent_.structure_)->X[gprid_];
	}

	virtual void _write(uint64_t val, size_t offset) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		printf("x_write (%lu) with gprid_ %d\n", val, gprid_);
		*((RV32IMACFDV*)parent_.structure_)->X[gprid_] = (etiss_uint32) val;
	}
};

class FloatRegField_RV32IMACFDV : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	FloatRegField_RV32IMACFDV(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("F")+etiss::toString(gprid),
			std::string("F")+etiss::toString(gprid),
			R|W,
			8
		),
		gprid_(gprid)
	{}

	FloatRegField_RV32IMACFDV(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			8
		),
		gprid_(gprid)
	{}

	virtual ~FloatRegField_RV32IMACFDV(){}

protected:
	virtual uint64_t _read(size_t offset) const {
		printf("f_read with gprid_ %d\n", gprid_);
		return (uint64_t) *((RV32IMACFDV*)parent_.structure_)->F[gprid_];
	}

	virtual void _write(uint64_t val, size_t offset) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		printf("f_write (%lu) with gprid_ %d\n", val, gprid_);
		*((RV32IMACFDV*)parent_.structure_)->F[gprid_] = (etiss_uint64) val;
	}
};

class VectorRegField_RV32IMACFDV : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	VectorRegField_RV32IMACFDV(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("V")+etiss::toString(gprid),
			std::string("V")+etiss::toString(gprid),
			R|W,
			128  // 1024 bits!
			// 64  // 512 bits!
			// 32  // 256 bits!
			// 16  // 128 bits!
			// 8  // 64 bits!
			// 4  // 32 bits!
		),
		gprid_(gprid)
	{}

	VectorRegField_RV32IMACFDV(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			// 16   // 128 bits!
			// 8   // 64 bits!
			4   // 32 bits!
		),
		gprid_(gprid)
	{}

	virtual ~VectorRegField_RV32IMACFDV(){}

protected:
	virtual uint64_t _read(size_t offset) const {
		printf("v_read with gprid_ %d\n", gprid_);
    // TODO: check for out of bounds? (offset < width_/8)
		return (uint64_t) *((uint64_t*)&((RV32IMACFDV*)parent_.structure_)->V[gprid_ * width_ + sizeof(uint64_t) * offset]);
	}

	virtual void _write(uint64_t val, size_t offset) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		printf("v_write (%lu) with gprid_ %d\n", val, gprid_);
    // TODO: check for out of bounds? (offset < width_/8)
		*((uint64_t*)&((RV32IMACFDV*)parent_.structure_)->V[gprid_ * width_ + sizeof(uint64_t)]) = (etiss_uint64) val;  // TODO: write V[gprid_] instead
	}
};

class CSRField_RV32IMACFDV : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	CSRField_RV32IMACFDV(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("CSR")+etiss::toString(gprid),
			std::string("CSR")+etiss::toString(gprid),
			R|W,
			4
		),
		gprid_(gprid)
	{}

	CSRField_RV32IMACFDV(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			4
		),
		gprid_(gprid)
	{}

	virtual ~CSRField_RV32IMACFDV(){}

protected:
	virtual uint64_t _read(size_t offset) const {
		printf("csr_read with gprid_ %d\n", gprid_);
		return (uint64_t) RV32IMACFDV_csr_read((ETISS_CPU*)parent_.structure_, nullptr, nullptr, (etiss_uint32) gprid_);
	}

	virtual void _write(uint64_t val, size_t offset) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		printf("csr_write (%lu) with gprid_ %d\n", val, gprid_);
		RV32IMACFDV_csr_write((ETISS_CPU*)parent_.structure_, nullptr, nullptr, gprid_, (etiss_uint32) val);
	}
};



class pcField_RV32IMACFDV : public etiss::VirtualStruct::Field{
public:
	pcField_RV32IMACFDV(etiss::VirtualStruct & parent)
		: Field(parent,
			"instructionPointer",
			"instructionPointer",
			R|W,
			4
		)
	{}

	virtual ~pcField_RV32IMACFDV(){}

protected:
	virtual uint64_t _read(size_t offset) const {
		return (uint64_t) ((ETISS_CPU *)parent_.structure_)->instructionPointer;
	}

	virtual void _write(uint64_t val, size_t offset) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		((ETISS_CPU *)parent_.structure_)->instructionPointer = (etiss_uint32) val;
	}
};

#endif
