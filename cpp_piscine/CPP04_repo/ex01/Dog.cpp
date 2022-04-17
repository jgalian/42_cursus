#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "Dog's class default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain;
	return ;
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog's class copy constructor called" << std::endl;
	this->type = src.getType();
	this->_brain = new Brain;
	*this->_brain = *src._brain;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog's class destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &	Dog::operator = ( Dog const & rhs )
{
	std::cout << "Dog's class asignation operator called" << std::endl;
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

void	Dog::makeSound(void) const
{
	std::cout << "Woof woof" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Dog::getIdea(int n) const
{
	this->_brain->printOneIdea(n);
}

/* ************************************************************************** */
