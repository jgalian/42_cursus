#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "//////////  PRESIDENTIAL PARDON TEST OK  //////////";
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat bobby("Bobby", 5);
		PresidentialPardonForm ppf1("Marvin");
		std::cout << bobby << std::endl;
		std::cout << ppf1 << std::endl;
		ppf1.beSigned(bobby);
		std::cout << ppf1 << std::endl;
		ppf1.execute(bobby);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "///////////  ROBOTOMY REQUEST TEST OK  ////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		RobotomyRequestForm rrf1("Marvin");
		std::cout << bobby << std::endl;
		std::cout << rrf1 << std::endl;
		rrf1.beSigned(bobby);
		std::cout << rrf1 << std::endl;
		rrf1.execute(bobby);
		RobotomyRequestForm rrf2("Nivram");
		rrf2.execute(bobby);
		rrf2.beSigned(bobby);
		rrf2.execute(bobby);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "///////////  SHRUBBERY CREATION FORM  OK  ///////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 5);
		ShrubberyCreationForm scf1("Marvin");
		std::cout << bobby << std::endl;
		std::cout << scf1 << std::endl;
		scf1.beSigned(bobby);
		std::cout << scf1 << std::endl;
		scf1.execute(bobby);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "///////////  EXCEPTION CREATING BUREAUCRAT  ///////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 0);
		ShrubberyCreationForm scf1("Marvin");
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "/////////////  EXCEPTION EXECUTING FORM  /////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bobby("Bobby", 142);
		std::cout << bobby << std::endl;
		ShrubberyCreationForm scf1("Nivram");
		scf1.beSigned(bobby);
		std::cout << scf1 << std::endl;
		scf1.execute(bobby);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}
