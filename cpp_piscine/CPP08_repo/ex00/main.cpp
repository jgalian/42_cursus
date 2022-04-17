#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	std::list<int> lst;

	vec.push_back(3);
	vec.push_back(63);
	vec.push_back(-23);
	vec.push_back(67);
	vec.push_back(62);
	vec.push_back(34);
	vec.push_back(42);
	vec.push_back(-356);
	vec.push_back(53);
	vec.push_back(67);
	vec.push_back(23);

	lst.push_back(3);
	lst.push_back(63);
	lst.push_back(-23);
	lst.push_back(67);
	lst.push_back(34);
	lst.push_back(62);
	lst.push_back(42);
	lst.push_back(-356);
	lst.push_back(53);
	lst.push_back(67);
	lst.push_back(23);

	std::cout << "/////////////////  VECTOR  ////////////////" << std::endl;

	try
	{
		int * match = easyfind(vec, 42);
		std::cout << "Value founded in address: " << match << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << '\n';
	}

	try
	{
		int * match = easyfind(vec, 11);
		std::cout << "Value founded in address: " << match << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << '\n';
	}

	std::cout << "//////////////////  LIST  /////////////////" << std::endl;

	try
	{
		int * match = easyfind(lst, 42);
		std::cout << "Value founded in address: " << match << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << '\n';
	}

	try
	{
		int * match = easyfind(lst, 11);
		std::cout << "Value founded in address: " << match << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << '\n';
	}

	return (0);
}
