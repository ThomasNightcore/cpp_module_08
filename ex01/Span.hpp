#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <vector>
#include <algorithm>

class Span {
private:
	unsigned int m_size;
	std::vector<int> m_buffer;

	Span(void);

public:
	Span(unsigned int size);
	Span(const Span& other);
	~Span(void);
	Span& operator=(const Span& other);

	void addNumber(int number);
	int shortestSpan(void) const;
	int longestSpan(void) const;

	template<typename T>
	void assign(T& from, T& to)
	{
		std::for_each(from, to, &Span::addNumber);
	}

};

#endif
