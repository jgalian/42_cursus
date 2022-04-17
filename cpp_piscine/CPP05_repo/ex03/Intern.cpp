#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *			Intern::makeForm( std::string formType, std::string formTarget )
{
	AForm * ret = NULL;
	AForm * fptr[3] =
	{
		new RobotomyRequestForm( formTarget ),
		new PresidentialPardonForm( formTarget ),
		new ShrubberyCreationForm( formTarget )
	};
	std::string formTypes[3] = { "robotomy", "pardon", "shrubbery" };
	for (int i = 0; i < 3; i++)
	{
		if (formType.find(formTypes[i]) != std::string::npos)
		{
			ret = fptr[i];
			std::cout << "Intern creates " << ret->getName() << std::endl;
		}
		else
			delete fptr[i];
	}
	if (ret == NULL)
		throw UnknownFormException();
	return (ret);
}

const char *	Intern::UnknownFormException::what() const throw()
{
	return ("UnknownFormException");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
