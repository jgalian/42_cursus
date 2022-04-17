#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "/////////////  SIGNING FORM OK  ///////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		Form c101("c101", 120, 140);
		std::cout << bobby << std::endl;
		std::cout << c101 << std::endl;
		c101.beSigned(bobby);
		std::cout << c101 << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "////////////  SIGNING GRADE LOW KO  ////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat jimmy("Jimmy", 138);
		Form r302("r302", 100, 110);
		std::cout << jimmy << std::endl;
		std::cout << r302 << std::endl;
		r302.beSigned(jimmy);
		std::cout << r302 << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "///////////  INCORRECT GRADE FORM KO  ///////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Form p607("p607", 0, 101);
		std::cout << p607 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}
