#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		std::string const	_name;
		bool				_status;
		unsigned int const	_gradeRequiredToSignIt;
		unsigned int const	_gradeRequiredToExecuteIt;

		Form();

	public:

		Form( std::string const name, const unsigned int gradeRequiredToSignIt, unsigned const int gradeRequiredToExecuteIt );
		Form( Form const & src );
		~Form();

		Form &		operator = ( Form const & rhs );

		void		beSigned( const Bureaucrat & bureaucrat );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class NotUnsignedNumberException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		std::string const	getName( void ) const;
		bool				getStatus( void ) const;
		unsigned int		getGradeRequiredToSignIt( void ) const;
		unsigned int		getGradeRequiredToExecuteIt( void ) const;
		void				setStatusSigned( void );

};

std::ostream &			operator << ( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
