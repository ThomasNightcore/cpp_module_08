#include "Span.hpp"

#include <algorithm>
#include <limits>
#include <set>

Span::Span(void) {
}

Span::Span(unsigned int size) {
    m_size = size;
    m_set = std::multiset<int>();
}

Span::Span(const Span &other) {
    m_size = other.m_size;
    m_set = std::multiset<int>(other.m_set);
}

Span::~Span(void) {
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        m_size = other.m_size;
        m_set = std::multiset<int>(other.m_set);
    }

    return *this;
}

void Span::addNumber(int number) {
    if (m_set.size() >= m_size) {
        throw FullSpanException();
    }

    m_set.insert(number);
}

int Span::shortestSpan(void) const {
    if (m_set.size() < 2) {
        throw NotEnoughElementsInSpanException();
    }

    int span = std::numeric_limits<int>::max();
    std::multiset<int>::iterator iter = m_set.begin();
    for (iter = ++m_set.begin(); iter != m_set.end(); iter++) {
        int a = *--iter;
        int b = *++iter;
        int diff = b - a;
        if (diff < span)
            span = diff;
    }

    return span;
}

int Span::longestSpan(void) const {
    if (m_set.size() < 2) {
        throw NotEnoughElementsInSpanException();
    }

    return *--m_set.end() - *m_set.begin();
}

const char *Span::NotEnoughElementsInSpanException::what(void) const throw() {
    return "Not enough elements to calculate a span";
}

const char *Span::FullSpanException::what(void) const throw() {
    return "Full Span capacity has been reached";
}
