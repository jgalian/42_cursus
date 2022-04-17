#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	std::cout << "WrongCat's class default constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WrongCat's class copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's class destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &	WrongCat::operator = ( WrongCat const & rhs )
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

void	WrongCat::makeSound(void) const
{
	std::cout << "Meaowwww meaooowwww" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
