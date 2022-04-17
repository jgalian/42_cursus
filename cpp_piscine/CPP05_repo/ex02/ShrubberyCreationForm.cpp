#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	AForm( src ),
	_target( src._target )
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::concreteExecution( void ) const
{
	std::string const shrubbery[1] =
	{
		"                     **            \n"\
		"        **         ******          \n"\
		"       ****      **********        \n"\
		"      ********  *************      \n"\
		"    ****************************   \n"\
		"  ***** ### ******** ### ********* \n"\
		"        ###          ###           \n"\
		"        ###          ###           \n"
	};
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file;
	file.open( fileName.c_str(), std::ios::trunc );
	if ( !file.is_open() )
		throw ShrubberyCreationForm::FileOpeningException();
	file << shrubbery[0];
	file.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
