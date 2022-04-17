#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice's DEFAULT CONSTRUCTOR called" << std::endl;
	return ;
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	std::cout << "Ice's COPY CONSTRUCTOR called" << std::endl;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "Ice's DEFAULT DESTRUCTOR called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &			Ice::operator=( Ice const & rhs )
{
	std::cout << "Ice's OPERATOR = called" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

	AMateria *	Ice::clone() const
	{
		AMateria * tmp = new Ice(*this);
		return (tmp);
	}

	void		Ice::use( ICharacter & target )
	{
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
