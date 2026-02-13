
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
	: std::stack<T, Container>::stack()
{
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T>& other)
	: std::stack<T, Container>::stack(other)
{
	(void)other;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) 
{
}

template<typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack<T, C>& other)
{
	if (this != &other)
	{
		std::stack<T, C>::operator=(other);
	}

	return *this;
}


// ***************** //
//   Default Begin   //
// ***************** //
template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin(void)
{
	return this->c.begin();
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::begin(void) const
{
	return this->c.begin();
}


// *************** //
//   Default End   //
// *************** //
template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end(void)
{
	return this->c.end();
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::end(void) const
{
	return this->c.end();
}


// ***************** //
//   Reverse Begin   //
// ***************** //
template<typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rbegin(void)
{
	return this->c.rbegin();
}

template<typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rbegin(void) const
{
	return this->c.rbegin();
}


// *************** //
//   Reverse End   //
// *************** //
template<typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rend(void)
{
	return this->c.rend();
}

template<typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rend(void) const
{
	return this->c.rend();
}
