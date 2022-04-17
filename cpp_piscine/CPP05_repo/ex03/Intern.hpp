#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:

		Intern &	operator = ( Intern const & rhs );

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		AForm *		makeForm( std::string formType, std::string formTarget );

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

};

#endif /* ********************************************************** INTERN_H */
