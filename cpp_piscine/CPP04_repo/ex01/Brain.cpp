#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain's class default constructor called" << std::endl;
	for(size_t i = 0; i < 100; i++)
		this->_ideas[i] = "idea" + std::to_string(i);
	return ;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain's class copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout 	<< "Brain's class destructor called... deleting memory adress "
				<< this << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &		Brain::operator = ( Brain const & rhs )
{
	std::cout << "Brain's class asignation operator called" << std::endl;
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Brain::printOneIdea(int n) const
{
	if (n >= 0 && n <= 100)
		std::cout << this->_ideas[n] << std::endl;
}

/* ************************************************************************** */

