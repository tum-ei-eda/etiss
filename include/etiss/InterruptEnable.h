// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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