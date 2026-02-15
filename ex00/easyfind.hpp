#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int target) {
    return std::find(container.begin(), container.end(), target);
}

#endif
