/*
* In this exercice clearly they want us to use dynamic_cast because when we use it
* we can check (whit pointers or references) if there has been an error because you
* are trying with other object type, diferent from the original.
*/

#include <iostream>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B & b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C & c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}

Base * generate(void)
{
	srand(time(0));
	int const i = rand() % 3;

	if (i == 0)
	{
		std::cout << "Original type: A" << std::endl;
		return (new A);
	}
	else if (i == 1)
	{
		std::cout << "Original type: B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Original type: C" << std::endl;
		return (new C);
	}
}

int main()
{
	{
		Base * base = static_cast<Base *>(generate());
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}
