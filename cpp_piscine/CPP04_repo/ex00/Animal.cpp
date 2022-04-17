#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Animal's class default constructor called" << std::endl;
	return ;
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal's class copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal's class destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &	Animal::operator = ( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound(void) const
{
	std::cout << "-----" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Animal::getType(void) const
{
	return (this->type);
}

/* ************************************************************************** */
