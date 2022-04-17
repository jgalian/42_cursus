#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/*
* In this exercice we've learned:
*	- When a class have a virtual method it is possible to asigne this method to 0. This means that
*	  this is a pure virtual method that can't be implemented into the class, but the sons that inherit
*	  from it should implement it. When this thing happends we name this class as abstract class.
*	  And is usual name the class with a capital 'A' at the beggining of the name. Also, there is
*	  another implication. It is not possible to instanciate an object from an abstract class.
*/

int main()
{
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
