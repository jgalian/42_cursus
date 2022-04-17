#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
	std::cout << "AAnimal's class default constructor called" << std::endl;
	this->type = "Not defined";
	return ;
}

AAnimal::AAnimal( const AAnimal & src )
{
	std::cout << "AAnimal's class copy constructor called" << std::endl;
	this->type = src.getType();
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal's class destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &	AAnimal::operator = ( AAnimal const & rhs )
{
	std::cout << "AAnimal's class asignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound(void) const
{
	std::cout << "-----" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		AAnimal::getType(void) const
{
	return (this->type);
}

void			AAnimal::setType(std::string newType)
{
	this->type = newType;
}

/* ************************************************************************** */
