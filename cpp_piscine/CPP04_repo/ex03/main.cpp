#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

int main()
{

	std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(3, *bob);
	std::cout << std::endl;
	me->unequip(1);
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	return 0;
}
