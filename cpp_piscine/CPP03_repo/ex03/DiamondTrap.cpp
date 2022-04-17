#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap's Default constructor called" << std::endl;
	this->_name = "Default";
	ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_maxHitPoints = 100;
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_maxEnergyPoints = 50;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
	return ;
}

DiamondTrap::DiamondTrap( std::string name )
{
	std::cout << "DiamondTrap's constructor called" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->FragTrap::_maxHitPoints = 100;
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_maxEnergyPoints = 50;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
	return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	std::cout << "DiamondTrap's copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap's destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &		DiamondTrap::operator = ( DiamondTrap const & rhs )
{
	_name = rhs.getName();
	this->ClapTrap::_name = rhs.getName() + "_clap_name";
	this->FragTrap::_maxHitPoints = rhs._maxHitPoints;
	this->FragTrap::_hitPoints = rhs.getHitPoints();
	this->ScavTrap::_maxEnergyPoints = rhs._maxEnergyPoints;
	this->ScavTrap::_energyPoints = rhs.getEnergyPoints();
	this->FragTrap::_attackDamage = rhs.getAttackDamage();
	return (*this);
}

std::ostream &	operator << ( std::ostream & o, DiamondTrap const & i )
{
	o << "DiamondTrap " << i.getName() << " has " << i.getHitPoints() << " hit points and "
		<< i.getEnergyPoints() << " energy points" << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << _name << " grandson of " << ClapTrap::_name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
