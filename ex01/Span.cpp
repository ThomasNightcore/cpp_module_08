#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>

Span::Span(void)
{
}

Span::Span(unsigned int size)
{
	m_size = size;
	m_buffer = std::vector<int>();
}

Span::Span(const Span& other)
{
	m_size = other.m_size;
	m_buffer = std::vector<int>(other.m_buffer);
}

Span::~Span(void)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		m_size = other.m_size;
		m_buffer = std::vector<int>(other.m_buffer);
	}

	return *this;
}

void Span::addNumber(int number)
{
	if (m_buffer.size() >= m_size)
	{
		throw std::length_error("Adding a number would exceed length limit");
	}

	m_buffer.push_back(number);
	std::sort(m_buffer.begin(), m_buffer.end());
}

int Span::shortestSpan(void) const
{
	int span = INT_MAX;

	for (unsigned long i = 0; i < m_buffer.size(); i++)
	{
		for (unsigned long j = i + 1; j < m_buffer.size(); j++)
		{
			int dist = std::max(m_buffer[i], m_buffer[j]) - std::min(m_buffer[i], m_buffer[j]);
			if (dist < span)
				span = dist;
		}
	}

	return span;
}

int Span::longestSpan(void) const
{
	int span = INT_MIN;

	for (unsigned long i = 0; i < m_buffer.size(); i++)
	{
		for (unsigned long j = i + 1; j < m_buffer.size(); j++)
		{
			int dist = std::max(m_buffer[i], m_buffer[j]) - std::min(m_buffer[i], m_buffer[j]);
			if (dist > span)
				span = dist;
		}
	}

	return span;
}
