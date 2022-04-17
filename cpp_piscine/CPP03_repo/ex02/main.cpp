#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap harry("Harry");

		harry.attack("Marvin");
		harry.takeDamage(4);
		harry.beRepaired(2);
		std::cout << harry.getName() << std::endl;
	}
	std::cout << std::endl;
	{
		ScavTrap toby("Toby");

		toby.attack("Marvin");
		toby.takeDamage(4);
		toby.beRepaired(2);
		toby.guardGate();
		std::cout << toby.getName() << std::endl;
	}
	std::cout << std::endl;
	{
		FragTrap larry("Larry");

		larry.attack("Marvin");
		larry.takeDamage(4);
		larry.beRepaired(2);
		larry.highFivesGuys();
		std::cout << larry.getName() << std::endl;
	}


}
