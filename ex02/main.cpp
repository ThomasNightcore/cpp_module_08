
#include "MutantStack.hpp"
#include <algorithm>
#include <stack>
#include <iostream>

void subjectTests(void)
{
  	MutantStack<int> mstack;

  	mstack.push(5);
	mstack.push(17);

  	std::cout << mstack.top() << std::endl;

  	mstack.pop();

  	std::cout << mstack.size() << std::endl;

  	mstack.push(3);
  	mstack.push(5);
  	mstack.push(737);
 	//[...]
  	mstack.push(0);

  	MutantStack<int>::iterator it = mstack.begin();
  	MutantStack<int>::iterator ite = mstack.end();

  	++it;
  	--it;
  	while (it != ite) 
	{
    	std::cout << *it << std::endl;
    	++it;
  	}
  	std::stack<int> s(mstack);
}

void print(int i)
{
	std::cout << " " << i << std::endl;
}


int main(void) 
{
	MutantStack<int> stack;

	std::stack<int> test;
	std::cout << " ==== Creating a stack with 5 elements ====" << std::endl;
	for (int i = 1; i < 6; i++)
		stack.push(i * 2);

	std::cout << "stack top is:  " << stack.top() << std::endl;
	std::cout << "stack size is: " << stack.size() << std::endl;

	std::cout << " * popping element..." << std::endl;
	stack.pop();

	stack = const_cast<MutantStack<int> &>(stack);
	std::cout << "stack top is:  " << stack.top() << std::endl;
	std::cout << "stack size is: " << stack.size() << std::endl;

	std::cout << std::endl;
	std::cout << " * iterating over elements..." << std::endl;

	std::for_each(stack.begin(), stack.end(), print);

	std::cout << std::endl;
	std::cout << " * reverse iterating over elements..." << std::endl;

	std::for_each(stack.rbegin(), stack.rend(), print);

	const MutantStack<int> const_stack(stack);

	std::cout << std::endl;
	std::cout << " ==== Copying stack elements to const stack ====" << std::endl;
	std::cout << " * const iterating over elements..." << std::endl;

	std::for_each(const_stack.begin(), const_stack.end(), print);

	std::cout << std::endl;
	std::cout << " * const reverse iterating over elements..." << std::endl;
	std::for_each(const_stack.rbegin(), const_stack.rend(), print);


  	return 0;
}