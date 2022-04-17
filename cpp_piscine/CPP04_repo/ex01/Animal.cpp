#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Animal's class default constructor called" << std::endl;
	this->type = "Not defined";
	return ;
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal's class copy constructor called" << std::endl;
	this->type = src.getType();
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
	std::cout << "Animal's class asignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return (*this); 
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

void			Animal::setType(std::string newType)
{
	this->type = newType;
}

/* ************************************************************************** */
