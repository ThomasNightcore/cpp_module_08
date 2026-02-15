
#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
static void hasElemnt(T &container, int value) {
    typename T::iterator res = easyfind(container, value);
    if (res != container.end()) {
        std::cout << "found element " << *res << std::endl;
        return;
    }
    std::cout << "Could not find element " << value << std::endl;
}

int main(void) {
    const int vect_size = 10;
    std::cout << " ======== Testing with vector (size = " << vect_size
              << ") ======== " << std::endl;
    std::vector<int> vect(vect_size);
    for (int i = 0; i < vect_size; i++)
        vect.push_back(i);

    hasElemnt(vect, 4);
    hasElemnt(vect, 0);
    hasElemnt(vect, -10);

    const int queue_size = 100000;
    std::cout << std::endl
              << " ======== Testing with deque (size = " << queue_size
              << ") ======== " << std::endl;
    std::deque<int> queue = std::deque<int>();
    for (int i = 0; i < 100000; i++)
        queue.push_back(i);

    hasElemnt(queue, 500);
    hasElemnt(queue, 89880);

    const int list_size = 1000;
    std::cout << std::endl
              << " ======== Testing with list (size = " << list_size
              << ") ======== " << std::endl;
    std::list<int> list(list_size);
    for (int i = 0; i < list_size; i++)
        list.push_back(i);
    hasElemnt(list, 5);
    hasElemnt(list, 50);
    hasElemnt(list, 9000);

    return 0;
}