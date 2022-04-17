#include "Bureaucrat.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "/////////////  BUROCRAT TEST OK  /////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		std::cout << bobby << std::endl;
		bobby.incrementGrade();
		std::cout << bobby << std::endl;
		bobby.decrementGrade();
		bobby.decrementGrade();
		std::cout << bobby << std::endl;
		Bureaucrat marvin("Marvin", 150);
		std::cout << marvin << std::endl;
		marvin.setGrade(140);
		std::cout << marvin << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "/////////////  BUROCRAT GRADE TO HIGH  /////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat johnny("Johnny", 1);
		std::cout << johnny << std::endl;
		johnny.incrementGrade();
		std::cout << johnny << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "/////////////  BUROCRAT GRADE TO LOW  /////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat johnny("Johnny", 151);
		std::cout << johnny << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}
