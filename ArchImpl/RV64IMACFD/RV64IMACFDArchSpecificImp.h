/**
 * Generated on Fri, 03 Nov 2023 13:22:23 +0100.
 *
 * This file contains the architecture specific header for the RV64IMACFD
 * core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV64IMACFDArch_RV64IMACFDARCHSPECIFICIMP_H_
#define ETISS_RV64IMACFDArch_RV64IMACFDARCHSPECIFICIMP_H_

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