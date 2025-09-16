/**
 * Generated on Tue, 16 Sep 2025 12:56:33 +0200.
 *
 * This file contains the architecture specific header for the RV64IMACFD
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV64IMACFDArch_RV64IMACFDARCHSPECIFICIMP_H_
#define ETISS_RV64IMACFDArch_RV64IMACFDARCHSPECIFICIMP_H_

#include "RV64IMACFDFuncs.h"

/**
	@brief VirtualStruct for RV64IMACFD architecture to faciliate register acess

	@details VirtualStruct enables user to access certain register via their name without knowning ETISS hierarchy of a core.
				Further fiels might be needed to enable gdbserver etc.

*/
class RegField_RV64IMACFD : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	RegField_RV64IMACFD(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("X")+etiss::toString(gprid),
			std::string("X")+etiss::toString(gprid),
			R|W,
			8
		),
		gprid_(gprid)
	{}

	RegField_RV64IMACFD(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			8
		),
		gprid_(gprid)
	{}

	virtual ~RegField_RV64IMACFD(){}

protected:
	virtual uint64_t _read() const {
		return (uint64_t) *((RV64IMACFD*)parent_.structure_)->X[gprid_];
	}

	virtual void _write(uint64_t val) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		*((RV64IMACFD*)parent_.structure_)->X[gprid_] = (etiss_uint64) val;
	}
};

class FloatRegField_RV64IMACFD : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	FloatRegField_RV64IMACFD(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("F")+etiss::toString(gprid),
			std::string("F")+etiss::toString(gprid),
			R|W,
			8
		),
		gprid_(gprid)
	{}

	FloatRegField_RV64IMACFD(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			8
		),
		gprid_(gprid)
	{}

	virtual ~FloatRegField_RV64IMACFD(){}

protected:
	virtual uint64_t _read() const {
		return (uint64_t) *((RV64IMACFD*)parent_.structure_)->F[gprid_];
	}

	virtual void _write(uint64_t val) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		*((RV64IMACFD*)parent_.structure_)->F[gprid_] = (etiss_uint64) val;
	}
};


class CSRField_RV64IMACFD : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	CSRField_RV64IMACFD(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("CSR")+etiss::toString(gprid),
			std::string("CSR")+etiss::toString(gprid),
			R|W,
			8
		),
		gprid_(gprid)
	{}

	CSRField_RV64IMACFD(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			8
		),
		gprid_(gprid)
	{}

	virtual ~CSRField_RV64IMACFD(){}

protected:
	virtual uint64_t _read() const {
		return (uint64_t) RV64IMACFD_csr_read((ETISS_CPU*)parent_.structure_, nullptr, nullptr, (etiss_uint64) gprid_);
	}

	virtual void _write(uint64_t val) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		RV64IMACFD_csr_write((ETISS_CPU*)parent_.structure_, nullptr, nullptr, gprid_, (etiss_uint64) val);
	}
};


class pcField_RV64IMACFD : public etiss::VirtualStruct::Field{
public:
	pcField_RV64IMACFD(etiss::VirtualStruct & parent)
		: Field(parent,
			"instructionPointer",
			"instructionPointer",
			R|W,
			8
		)
	{}

	virtual ~pcField_RV64IMACFD(){}

protected:
	virtual uint64_t _read() const {
		return (uint64_t) ((ETISS_CPU *)parent_.structure_)->instructionPointer;
	}

	virtual void _write(uint64_t val) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		((ETISS_CPU *)parent_.structure_)->instructionPointer = (etiss_uint64) val;
	}
};

#endif