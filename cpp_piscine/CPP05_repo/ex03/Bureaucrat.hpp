#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		std::string const	_name;
		unsigned int		_grade;

		Bureaucrat();

	public:


		Bureaucrat( const std::string name, const unsigned int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &	operator = ( Bureaucrat const & rhs );

		void			signForm( AForm & form ) const;
		void			executeForm( AForm const & form ) const;

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

		const std::string	getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				setGrade( unsigned int const);
		void				incrementGrade( void);
		void				decrementGrade( void );

};

std::ostream &			operator << ( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
