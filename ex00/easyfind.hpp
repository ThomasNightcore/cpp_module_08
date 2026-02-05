#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

//#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator iter;
	for (iter = container.begin(); iter != container.end(); ++iter)
	{
		if (*iter == target)
			return iter;
	}

	throw::std::runtime_error("no value found");
}

#endif
