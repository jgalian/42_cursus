#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade) : _name(name)
{
	if ((int)grade < 0)
		throw Bureaucrat::NotUnsignedNumberException();
	else if (grade == 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) :
	_name(src._name),
	_grade(src._grade)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &		Bureaucrat::operator = ( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &		operator << ( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Bureaucrat::signForm( AForm & form ) const
{
	if (form.getStatus())
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because it is already signed" << std::endl;
		return ;
	}
	if (this->getGrade() <= form.getGradeRequiredToSignIt())
	{
		form.setStatusSigned();
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

void		Bureaucrat::executeForm( AForm const & form ) const
{
	if (form.getStatus() == 0)
	{
		std::cout << "Form needs to be signed in order to be executed" << std::endl;
		return ;
	}
	if (this->getGrade() <= form.getGradeRequiredToExecuteIt())
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *	Bureaucrat::NotUnsignedNumberException::what() const throw()
{
	return ("NotUnsignedNumberException");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

unsigned int		Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void		Bureaucrat::setGrade( unsigned int const grade )
{
	if ((int)grade < 0)
		throw Bureaucrat::NotUnsignedNumberException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void		Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		--this->_grade;
}

void		Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		++this->_grade;
}

/* ************************************************************************** */
