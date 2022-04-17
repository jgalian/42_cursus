#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap's Default constructor called" << std::endl;
	_name = "Default";
	_maxHitPoints = 100;
	_hitPoints = 100;
	_maxEnergyPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( std::string name )
{
	std::cout << "FragTrap's constructor called" << std::endl;
	_name = name;
	_maxHitPoints = 100;
	_hitPoints = 100;
	_maxEnergyPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << "FragTrap's copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap's destructor called" << std::endl;
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &		FragTrap::operator = ( FragTrap const & rhs )
{
	_name = rhs.getName();
	_maxHitPoints = rhs._maxHitPoints;
	_hitPoints = rhs.getHitPoints();
	_maxEnergyPoints = rhs._maxEnergyPoints;
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return (*this);
}

std::ostream &	operator << ( std::ostream & o, FragTrap const & i )
{
	o << "FragTrap " << i.getName() << " has " << i.getHitPoints() << " hit points and "
		<< i.getEnergyPoints() << " energy points" << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	FragTrap::attack(std::string const & target)
{
	if (_energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attack " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		decrementEnergyPoints(1);
	}
	else
	{
		std::cout << "FragTrap " << _name << " does not have enough energy points to attack" << std::endl;
	}
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << _name << " is giving high-fives" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
