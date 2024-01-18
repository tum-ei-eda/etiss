#ifndef ETISS_INCLUDE_INTERRUPTENABLE_H_
#define ETISS_INCLUDE_INTERRUPTENABLE_H_

namespace etiss {

class InterruptEnable
{
	public:
		virtual ~InterruptEnable() {}
		virtual bool isEnabled() { return true; }
};

template <typename t>
class MappedInterruptEnable : public InterruptEnable
{
	public:
		MappedInterruptEnable(t* enable_reg, t mask) :
			enable_reg_(enable_reg),
			mask_(mask)
		{

		}

		virtual ~MappedInterruptEnable() {}

		bool isEnabled() override
		{
			return *enable_reg_ & mask_;
		};

	private:
		t* enable_reg_;
		t mask_;
};

}
#endif