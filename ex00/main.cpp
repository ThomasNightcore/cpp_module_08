
#include <deque>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::cout << " ======== Testing with vector ======== " << std::endl;
	std::vector<int> vect(10);
	for (int i = 0; i < 10; i++)
		vect.push_back(i);
	try 
	{
		std::vector<int>::iterator res = easyfind(vect, 4);
		std::cout << "found element " << *res << std::endl;
		res = easyfind(vect, 0);
		std::cout << "found element " << *res << std::endl;
	} 
	catch (std::exception& ex)
	{
		std::cout << "Caught exception " << ex.what() << std::endl;
	}

	std::cout << std::endl << " ======== Testing with deque ======== " << std::endl;
	std::deque<int> queue = std::deque<int>();
	for (int i = 0; i < 100000; i++)
		queue.push_back(i);
	try 
	{
		std::deque<int>::iterator res = easyfind(queue, 500);
		std::cout << "found element " << *res << std::endl;
		res = easyfind(queue, 89880);
		std::cout << "found element " << *res << std::endl;
	} 
	catch (std::exception& ex)
	{
		std::cout << "Caught exception " << ex.what() << std::endl;
	}

	std::cout << std::endl << " ======== Testing with list ======== " << std::endl;
	std::list<int> list(10);
	for (int i = 0; i < 1000; i++)
		list.push_back(i);
	try 
	{
		std::list<int>::iterator res = easyfind(list, 5);
		std::cout << "found element " << *res << std::endl;
		res = easyfind(list, 50);
		std::cout << "found element " << *res << std::endl;
		res = easyfind(list, 9000);
		std::cout << "found element " << *res << std::endl;
	} 
	catch (std::exception& ex)
	{
		std::cout << "Caught exception " << ex.what() << std::endl;
	}

	return 0;
}