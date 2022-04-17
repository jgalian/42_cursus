#include "span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(size_t N) : _N(N)
{
	_vec.reserve(_N);
}

Span::Span( const Span & src )
{
	this->_N = src._N;
	this->_vec = src._vec;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator = ( Span const & rhs )
{
	if ( this != &rhs )
	{
		Span temp(rhs);
		this->_vec.swap(temp._vec);
		this->_N = rhs._N;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int value)
{
	if (_vec.size() >= _vec.capacity())
		throw ("No more elements can be added. Maximum capacity reached.");
	_vec.push_back(value);
}

unsigned int		Span::shortestSpan()
{
	unsigned int	ret = UINT_MAX;
	unsigned int	tmp;
	std::vector<int>::iterator it;

	if (_vec.size() < 2)
		throw ("Needed more elements to calculate shortest span");
	for (it = _vec.begin() + 1; it != _vec.end(); it++)
	{
		if (*(it - 1) == *it)
			tmp = 0;
		else if (*(it - 1) < *it)
			tmp = *it - *(it - 1);
		else
			tmp = *(it - 1) - *it;
		if (tmp < ret)
			ret = tmp;
	}
	return (ret);
}

unsigned int		Span::longestSpan()
{
	unsigned int	ret = 0;
	unsigned int	tmp;
	std::vector<int>::iterator it;

	if (_vec.size() < 2)
	{
		throw ("Needed more elements to calculate longest span");
		return (-1);
	}
	for (it = _vec.begin() + 1; it != _vec.end(); it++)
	{
		if (*(it - 1) == *it)
			tmp = 0;
		else if (*(it - 1) < *it)
			tmp = *it - *(it - 1);
		else
			tmp = *(it - 1) - *it;
		if (tmp > ret)
			ret = tmp;
	}
	return (ret);
}

void	Span::addRandomValues(size_t n_elements)
{
	srand (time(NULL));
	for (size_t i = 0; i < n_elements; i++)
		this->addNumber(rand() % INT_MAX + (INT_MAX / 2));
}

void		Span::printValue(size_t pos)
{
	if (pos >= this->_vec.size())
		throw ("Error: trying to print position higher than the actual size of vector");
	std::cout << this->_vec.at(pos);
}

void		Span::printAllValues(void)
{
	std::vector<int>::iterator it;
	for (it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int> &		Span::getVector(void)
{
	return (this->_vec);
}

/* ************************************************************************** */
