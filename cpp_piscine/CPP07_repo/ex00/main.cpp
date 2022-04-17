#include <iostream>
#include "whatever.hpp"

int main(void)
{
	std::cout << std::endl;
	{
		int x = 5;
		int y = 10;

		std::cout << "before swap -->  x = " << x << "   y = " << y << std::endl;
		swap(x, y);
		std::cout << "after swap --->  x = " << x << "   y = " << y << std::endl;
		std::cout << "min = " << min(x, y) << std::endl;
		std::cout << "max = " << max(x, y) << std::endl << std::endl;
	}
	{
		float x = 5.5;
		float y = 10.10;

		std::cout << "before swap -->  x = " << x << "   y = " << y << std::endl;
		swap(x, y);
		std::cout << "after swap --->  x = " << x << "   y = " << y << std::endl;
		std::cout << "min = " << min(x, y) << std::endl;
		std::cout << "max = " << max(x, y) << std::endl << std::endl;
	}
	{
		char x = 'a';
		char y = 'z';

		std::cout << "before swap -->  x = " << x << "   y = " << y << std::endl;
		swap(x, y);
		std::cout << "after swap --->  x = " << x << "   y = " << y << std::endl;
		std::cout << "min = " << min(x, y) << std::endl;
		std::cout << "max = " << max(x, y) << std::endl << std::endl;
	}
	{
		std::string x = "hola";
		std::string y = "adios";

		std::cout << "before swap -->  x = " << x << "   y = " << y << std::endl;
		swap(x, y);
		std::cout << "after swap --->  x = " << x << "   y = " << y << std::endl;
		std::cout << "min = " << ::min(x, y) << std::endl;
		std::cout << "max = " << ::max(x, y) << std::endl << std::endl;
	}
	return (0);
}

