#include "classes.hpp"
#include <chrono>

namespace ts
{
	
	void Timer::reset()
	{
		m_beg = clock_t::now();
	}
}