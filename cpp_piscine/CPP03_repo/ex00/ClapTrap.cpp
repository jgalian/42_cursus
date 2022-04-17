#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap( void ) :
	_name("Default"),
	_maxHitPoints(10),
	_hitPoints(10),
	_maxEnergyPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap's Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) :
	_name(name),
	_maxHitPoints(10),
	_hitPoints(10),
	_maxEnergyPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap's constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "ClapTrap's copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap's destructor called" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &		ClapTrap::operator = ( ClapTrap const & rhs )
{
	_name = rhs.getName();
	_maxHitPoints = rhs._maxHitPoints;
	_hitPoints = rhs.getHitPoints();
	_maxEnergyPoints = rhs._maxEnergyPoints;
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return (*this);
}

std::ostream &	operator << ( std::ostream & o, ClapTrap const & i )
{
	o << "ClapTrap " << i.getName() << " has " << i.getHitPoints() << " hit points and "
		<< i.getEnergyPoints() << " energy points" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(std::string const & target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		decrementEnergyPoints(1);
	}
	else
	{
		std::cout << "ClapTrap " << _name << " does not have enough energy points to attack" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has been attacked and takes " << amount << " points of damage!";
	decrementHitPoints(amount);
	std::cout << " Now it has " << _hitPoints << " hitpoints." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	incrementHitPoints(amount);
	std::cout << "ClapTrap " << _name << " has been repaired and has recovered " << amount << " points of damage!";
	std::cout << " Now it has " << _hitPoints << " hitpoints." << std::endl;
	decrementEnergyPoints(1);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string 	ClapTrap::getName( void ) const
{
	return (_name);
}

unsigned int 	ClapTrap::getHitPoints( void ) const
{
	return (_hitPoints);
}

unsigned int 	ClapTrap::getEnergyPoints( void ) const
{
	return (_energyPoints);
}

unsigned int 	ClapTrap::getAttackDamage( void ) const
{
	return (_attackDamage);
}

void	ClapTrap::incrementHitPoints( unsigned int amount )
{
	if (getHitPoints() + amount > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	else
		_hitPoints += amount;
}

void	ClapTrap::decrementHitPoints( unsigned int amount )
{
	if (amount > getHitPoints())
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void	ClapTrap::incrementEnergyPoints( unsigned int amount )
{
	if (getEnergyPoints() + amount > _maxEnergyPoints)
		_energyPoints = _maxEnergyPoints;
	else
		_energyPoints += amount;
}

void	ClapTrap::decrementEnergyPoints( unsigned int amount )
{
	if (amount > getEnergyPoints())
		_energyPoints = 0;
	else
		_energyPoints -= amount;
}

/* ************************************************************************** */
