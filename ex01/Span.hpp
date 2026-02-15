#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <algorithm>
#include <set>

class Span {
private:
    unsigned int m_size;
    std::multiset<int> m_set;

    Span(void);

public:
    Span(unsigned int size);
    Span(const Span &other);
    ~Span(void);
    Span &operator=(const Span &other);

    void addNumber(int number);
    int shortestSpan(void) const;
    int longestSpan(void) const;

    template <typename T>
    void assign(T &from, T &to) {
        int len = std::distance(from, to);
        if (m_set.size() + len > m_size) {
            throw FullSpanException();
        }

        std::for_each(from, to, &std::multiset<int>::insert);
    }

    class FullSpanException : public std::exception {
        virtual const char *what(void) const throw();
    };

    class NotEnoughElementsInSpanException : public std::exception {
        virtual const char *what(void) const throw();
    };
};

#endif
