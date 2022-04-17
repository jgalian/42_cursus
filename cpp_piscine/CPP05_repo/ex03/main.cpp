#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "////////////////  INTERN ROBOTOMY OK  ///////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->beSigned(bobby);
		rrf->execute(bobby);
		delete rrf;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "////////////////  INTERN PARDON OK  /////////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("pardon", "Marvin");
		rrf->beSigned(bobby);
		rrf->execute(bobby);
		delete rrf;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "////////////////  INTERN TEST KO  /////////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("random form", "Marvin");
		rrf->beSigned(bobby);
		rrf->execute(bobby);
		delete rrf;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}
