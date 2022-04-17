#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap uno("Toby");

	uno.attack("Marvin");
	uno.takeDamage(4);
	uno.beRepaired(2);
	uno.guardGate();
	uno.getName();
}
