#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat's class default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain;
	return ;
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat's class copy constructor called" << std::endl;
	this->type = src.getType();
	this->_brain = new Brain;
	*this->_brain = *src._brain;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat's class destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &	Cat::operator = ( Cat const & rhs )
{
	std::cout << "Cat's class asignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();

		//this->_brain = rhs._brain; // -> Shallow copy

		if (this->_brain)
		{
			delete this->_brain;
			this->_brain = new Brain;		// -> Deep copy
			*this->_brain = *rhs._brain;
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound(void) const
{
	std::cout << "Meaowwww meaooowwww" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Cat::getIdea(int n) const
{
	this->_brain->printOneIdea(n);
}

/* ************************************************************************** */
