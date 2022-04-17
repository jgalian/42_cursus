#include <iostream>
#include "whatever.hpp"

int main(void)
{
	std::cout << std::endl;
	{
		int		a[5] = { 1, 2, 3, 4, 5 };
		iter(a, 5, print);
	}
	std::cout << std::endl;
	{
		char	a[5] = { 'a', 'b', 'c', 'd', 'e' };
		iter(a, 5, print);
	}
	std::cout << std::endl;
	{
		std::string	a[3] = { "hola", "que", "tal" };
		iter(a, 3, print);
	}
	std::cout << std::endl;
	return (0);
}
