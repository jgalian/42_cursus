#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm( std::string const name, unsigned const int gradeRequiredToSignIt, unsigned const int gradeRequiredToExecuteIt ) :
	_name(name),
	_status(0),
	_gradeRequiredToSignIt(gradeRequiredToSignIt),
	_gradeRequiredToExecuteIt(gradeRequiredToExecuteIt)
{
	if ((int)gradeRequiredToSignIt < 0 || (int)gradeRequiredToExecuteIt < 0)
		throw AForm::NotUnsignedNumberException();
	if (gradeRequiredToSignIt == 0 || gradeRequiredToExecuteIt == 0)
		throw AForm::GradeTooHighException();
	if (gradeRequiredToSignIt > 150 || gradeRequiredToExecuteIt > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm & src ) :
	_name(src._name),
	_status(src._status),
	_gradeRequiredToSignIt(src._gradeRequiredToSignIt),
	_gradeRequiredToExecuteIt(src._gradeRequiredToExecuteIt)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &		operator << ( std::ostream & o, AForm const & i )
{
	std::string status_message;

	if (i.getStatus())
	{
		status_message = " is ready to be executed by a burocrat whit grade higher or equal than ";
		o << i.getName() << status_message << i.getGradeRequiredToExecuteIt();
	}
	else
	{
		status_message = " is waiting to be signed by a bureaucrat with grade higher or equal than ";
		o << i.getName() << status_message << i.getGradeRequiredToSignIt();
	}
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			AForm::beSigned( const Bureaucrat & bureaucrat )
{
	if (this->getStatus())
	{
		std::cout << this->getName() << " is already signed" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() <= this->getGradeRequiredToSignIt())
		bureaucrat.signForm(*this);
	else
		throw AForm::GradeTooLowException();
}

void				AForm::execute( Bureaucrat const & executor ) const
{
	if (this->getStatus() == 0)
	{
		std::cout << "Form needs to be signed in order to be executed" << std::endl;
		return ;
	}
	if (executor.getGrade() <= this->getGradeRequiredToExecuteIt())
	{
		executor.executeForm(*this);
		concreteExecution();
	}
	else
		throw AForm::GradeTooLowException();
}

const char *		AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char *		AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *		AForm::NotUnsignedNumberException::what() const throw()
{
	return ("NotUnsignedNumberException");
}

const char *		AForm::FileOpeningException::what() const throw()
{
	return ("FileOpeningException");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	AForm::getName( void ) const
{
	return (this->_name);
}

bool				AForm::getStatus( void ) const
{
	return (this->_status);
}

void				AForm::setStatusSigned( void )
{
	this->_status = 1;
}

unsigned int		AForm::getGradeRequiredToSignIt( void ) const
{
	return (this->_gradeRequiredToSignIt);
}

unsigned int 		AForm::getGradeRequiredToExecuteIt( void ) const
{
	return (this->_gradeRequiredToExecuteIt);
}

/* ************************************************************************** */
