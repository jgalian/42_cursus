#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/*
* In this exercice we've learned:
*	- When a class have a virtual method, it also needs a virtual destructor. If not, compiler will probably complain.
*	  This is necessary because an object could be instanciated as both, parent and child. And if the object is deleted
*	  as a father and destructor is not declared as virtual, it is going to use the father's destructor and the son's
*	  part of the object is not going to be freed.
*	- Shallow copy vs Deep copy. When using shallow copy, only copies the value of the variables in an object. But there
*	  is a problem when the variable is allocated on the heap because the shallow copy takes the adress and copy it to
*	  the second object. This way, both objects ended with a variable pointing to the same adress, which most of the time
*	  is a problem. To avoid this, the deep copy should allocate space for the second object variable and copies on it
*	  the value. But first, should check if the variable is already pointing to a allocated memory adress, and if so,
*	  should freed it in order to avoid memory leaks. The copy constructor should be explicitly defined.
*/

int main()
{
	{
		int	n = 4;

		std::cout << std::endl;
		std::cout << "//////////////////////////////////////////////" << std::endl;
		std::cout << std::endl;
		Animal *animals[n];
		for (int i = 0; i < n; i++)
		{
			if (i < n / 2)
			{
				animals[i] = new Dog();
				std::cout << std::endl;
			}
			else
			{
				animals[i] = new Cat();
				std::cout << std::endl;
			}
		}
		std::cout << "animals[0].getType() = " << animals[0]->getType() << std::endl;
		std::cout << "animals[2].getType() = " << animals[2]->getType() << std::endl;
		std::cout << "animals[1].makeSound() = "; animals[1]->makeSound();
		std::cout << "animals[3].makeSound() = "; animals[3]->makeSound();

		std::cout << std::endl;
		Animal otherAnimal(*animals[1]);
		std::cout << "otherAnimal.getType() = " << otherAnimal.getType() << std::endl;
		std::cout << "otherAnimal.makeSound() = "; otherAnimal.makeSound();

		std::cout << std::endl;
		Animal otherAnimal2;
		otherAnimal2 = *animals[2];
		std::cout << "otherAnimal2.getType() = " << otherAnimal2.getType() << std::endl;
		std::cout << "otherAnimal2.makeSound() = "; otherAnimal2.makeSound();

		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			delete animals[i];
			std::cout << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "//////////////////////////////////////////////" << std::endl;
		std::cout << std::endl;

		Cat cat;
		std::cout << std::endl;
		Cat cat2;
		std::cout << std::endl;
		cat2 = cat;
		std::cout << std::endl;
		cat2.getIdea(50);
		std::cout << "cat2.getType() = " << cat2.getType() << std::endl;
		std::cout << "cat2.makeSound() = "; cat2.makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "//////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
}
