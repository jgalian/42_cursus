#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
#include <unistd.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

		std::string const	_target;

		RobotomyRequestForm();
		RobotomyRequestForm &	operator = ( RobotomyRequestForm const & rhs );

	public:

		RobotomyRequestForm( std::string const target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm();

		void	concreteExecution( void ) const;

};

//std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */
