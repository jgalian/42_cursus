#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

		std::string	const	_target;

		ShrubberyCreationForm();
		ShrubberyCreationForm &		operator = ( ShrubberyCreationForm const & rhs );

	public:

		ShrubberyCreationForm( std::string const target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm();

		void	concreteExecution( void ) const;

};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */
