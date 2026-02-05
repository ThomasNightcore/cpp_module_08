#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

//#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator iter, end;
	for (iter = container.begin(), end = container.end(); iter != end; ++iter)
	{
		if (*iter == target)
			return iter;
	}

	throw::std::runtime_error("no value found");
}

#endif
