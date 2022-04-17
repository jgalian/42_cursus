#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap uno("Toby");

	uno.attack("Marvin");
	uno.takeDamage(4);
	uno.beRepaired(2);
	std::cout << uno;
}
