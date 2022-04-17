#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure's DEFAULT CONSTRUCTOR called" << std::endl;
	return ;
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
	std::cout << "Cure's COPY CONSTRUCTOR called" << std::endl;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "Cure's DEFAULT DESTRUCTOR called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &			Cure::operator = ( Cure const & rhs )
{
	std::cout << "Cure's OPERATOR = called" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

	AMateria *	Cure::clone() const
	{
		return (new Cure(*this));
	}

	void		Cure::use( ICharacter & target )
	{
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
