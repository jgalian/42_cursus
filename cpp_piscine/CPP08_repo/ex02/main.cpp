#include <iostream>
#include <string>
#include <list>
#include "mutantstack.hpp"

int	main(void)
{
	std::cout << std::endl;
	{
		MutantStack<int> mstack;
		MutantStack<int>::iterator it;
		MutantStack<int>::iterator ite;

		mstack.push(3);
		mstack.push(42);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(5);
		mstack.push(7);
		mstack.push(9);
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "Top: " << s.top() << std::endl;
		MutantStack<int> mstack2;
		mstack2 = mstack;
		it = mstack2.begin();
		it++;
		it++;
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	{
		MutantStack<std::string> mstack;
		MutantStack<std::string>::iterator it;
		MutantStack<std::string>::iterator ite;
		mstack.push("hola");
		mstack.push("adios");
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push("manzana");
		mstack.push("pera");
		mstack.push("naranja");
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	{
		std::list<int> mstack;
		std::list<int>::iterator it;
		std::list<int>::iterator ite;

		mstack.push_back(3);
		mstack.push_back(42);
		std::cout << "Top: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push_back(5);
		mstack.push_back(7);
		mstack.push_back(9);
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
		std::cout << "Top: " << s.back() << std::endl;
		std::list<int> mstack2;
		mstack2 = mstack;
		it = mstack2.begin();
		it++;
		it++;
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
