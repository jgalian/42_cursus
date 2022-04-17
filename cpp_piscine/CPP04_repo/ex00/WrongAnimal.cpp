#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal's class default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << "WrongAnimal's class copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's class destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &	WrongAnimal::operator = ( WrongAnimal const & rhs )
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

void	WrongAnimal::makeSound(void) const
{
	std::cout << "-----" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		WrongAnimal::getType(void) const
{
	return (this->type);
}

/* ************************************************************************** */
