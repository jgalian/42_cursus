#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	std::cout << "Character's DEFAULT CONSTRUCTOR called" << std::endl;
	return ;
}

Character::Character( std::string name )
{
	std::cout << "Character's CONSTRUCTOR called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character( const Character & src )
{
	std::cout << "Character's COPY CONSTRUCTOR called" << std::endl;
	this->_name = src.getName();

	for (int i = 0; i < 4; i++)
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << "Character's DESTRUCTOR called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &		Character::operator = ( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
		}
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Character::equip( AMateria * m )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void		Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4)
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void		Character::use( int idx, ICharacter & target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &	Character::getName( void ) const
{
	return (this->_name);
}

/* ************************************************************************** */
