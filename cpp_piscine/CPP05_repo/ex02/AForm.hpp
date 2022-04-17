#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		std::string const	_name;
		bool				_status;
		const unsigned int	_gradeRequiredToSignIt;
		const unsigned int	_gradeRequiredToExecuteIt;

		AForm();
		AForm &			operator = ( AForm const & rhs );

	public:

		AForm( std::string const name, const unsigned int gradeRequiredToSignIt, unsigned const int gradeRequiredToExecuteIt );
		AForm( AForm const & src );
		virtual	~AForm();

		void			beSigned( Bureaucrat const & bureaucrat );
		void			execute( Bureaucrat const & executor ) const;
		virtual void	concreteExecution( void ) const = 0;

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

		class FileOpeningException
		{
			public:
				virtual const char * what() const throw();
		};

		std::string const	getName( void ) const;
		bool				getStatus( void ) const;
		void				setStatusSigned( void );
		unsigned int		getGradeRequiredToSignIt( void ) const;
		unsigned int		getGradeRequiredToExecuteIt( void ) const;

};

std::ostream &			operator << ( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */
