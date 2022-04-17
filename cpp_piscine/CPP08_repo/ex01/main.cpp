#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "span.hpp"

int	main(void)
{
	std::cout << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(42);
		sp.printAllValues();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(56);
	}
	catch(const char * error)
	{
		std::cerr << error << '\n';
	}

	std::cout << std::endl;
	std::cout << "////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(5);
		sp.printAllValues();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const char * error)
	{
		std::cerr << error << '\n';
	}

	std::cout << std::endl;

	// try
	// {
	// 	Span sp = Span(10000);
	//
	// 	sp.addRandomValues(10000);
	// 	sp.printAllValues();
	// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	// }
	// catch(const char * error)
	// {
	// 	std::cerr << error << '\n';
	// }

	return (0);
}
