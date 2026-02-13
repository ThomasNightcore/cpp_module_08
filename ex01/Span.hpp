#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <vector>

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

};

#endif
