/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the architecture specific header for the RV64IMACFDV
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV64IMACFDVArch_RV64IMACFDVARCHSPECIFICIMP_H_
#define ETISS_RV64IMACFDVArch_RV64IMACFDVARCHSPECIFICIMP_H_

/**
	@brief VirtualStruct for RV64IMACFDV architecture to faciliate register acess

	@details VirtualStruct enables user to access certain register via their name without knowning ETISS hierarchy of a core.
				Further fiels might be needed to enable gdbserver etc.

*/
class RegField_RV64IMACFDV : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	RegField_RV64IMACFDV(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("X")+etiss::toString(gprid),
			std::string("X")+etiss::toString(gprid),
			R|W,
			8
		),
		gprid_(gprid)
	{}

	RegField_RV64IMACFDV(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			8
		),
		gprid_(gprid)
	{}

	virtual ~RegField_RV64IMACFDV(){}

protected:
	virtual uint64_t _read() const {
		return (uint64_t) *((RV64IMACFDV*)parent_.structure_)->X[gprid_];
	}

	virtual void _write(uint64_t val) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		*((RV64IMACFDV*)parent_.structure_)->X[gprid_] = (etiss_uint64) val;
	}
};

class FloatRegField_RV64IMACFDV : public etiss::VirtualStruct::Field{
private:
	const unsigned gprid_;
public:
	FloatRegField_RV64IMACFDV(etiss::VirtualStruct & parent,unsigned gprid)
		: Field(parent,
			std::string("F")+etiss::toString(gprid),
			std::string("F")+etiss::toString(gprid),
			R|W,
			8
		),
		gprid_(gprid)
	{}

	FloatRegField_RV64IMACFDV(etiss::VirtualStruct & parent, std::string name, unsigned gprid)
		: Field(parent,
			name,
			name,
			R|W,
			8
		),
		gprid_(gprid)
	{}

	virtual ~FloatRegField_RV64IMACFDV(){}

protected:
	virtual uint64_t _read() const {
		return (uint64_t) *((RV64IMACFDV*)parent_.structure_)->F[gprid_];
	}

	virtual void _write(uint64_t val) {
		etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
		*((RV64IMACFDV*)parent_.structure_)->F[gprid_] = (etiss_uint64) val;
	}
};

class pcField_RV64IMACFDV : public etiss::VirtualStruct::Field{
public:
	pcField_RV64IMACFDV(etiss::VirtualStruct & parent)
		: Field(parent,
			"instructionPointer",
			"instructionPointer",
			R|W,
			8
		)
	{}

	virtual ~pcField_RV64IMACFDV(){}

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