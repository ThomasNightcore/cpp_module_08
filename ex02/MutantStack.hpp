#ifndef __MUTANT_STACK_HPP__
#define __MUTANT_STACK_HPP__

#include <deque>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
private:
public:
    MutantStack(void);
    MutantStack(const MutantStack<T> &other);
    ~MutantStack(void);
    MutantStack<T, C> &operator=(const MutantStack<T, C> &other);

    typedef typename C::iterator iterator;
    typedef typename C::const_iterator const_iterator;
    typedef typename C::reverse_iterator reverse_iterator;
    typedef typename C::const_reverse_iterator const_reverse_iterator;

    iterator begin(void);
    const_iterator begin(void) const;

    iterator end(void);
    const_iterator end(void) const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;

    reverse_iterator rend();
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
