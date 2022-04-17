#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap's Default constructor called" << std::endl;
	_name = "Default";
	_maxHitPoints = 100;
	_hitPoints = 100;
	_maxEnergyPoints = 50;
	_energyPoints = 50;
	_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( std::string name )
{
	std::cout << "ScavTrap's constructor called" << std::endl;
	_name = name;
	_maxHitPoints = 100;
	_hitPoints = 100;
	_maxEnergyPoints = 50;
	_energyPoints = 50;
	_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << "ScavTrap's copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap's destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &		ScavTrap::operator = ( ScavTrap const & rhs )
{
	_name = rhs.getName();
	_maxHitPoints = rhs._maxHitPoints;
	_hitPoints = rhs.getHitPoints();
	_maxEnergyPoints = rhs._maxEnergyPoints;
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return (*this);
}

std::ostream &	operator << ( std::ostream & o, ScavTrap const & i )
{
	o << "ScavTrap " << i.getName() << " has " << i.getHitPoints() << " hit points and "
		<< i.getEnergyPoints() << " energy points" << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::attack(std::string const & target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		decrementEnergyPoints(1);
	}
	else
	{
		std::cout << "ScavTrap " << _name << " does not have enough energy points to attack" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
