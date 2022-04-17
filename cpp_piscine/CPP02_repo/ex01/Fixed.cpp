#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ) : _rawBits(num << _fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _rawBits(round(num * (1 << _fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &		Fixed::operator = ( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = rhs._rawBits;
	return *this;
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int 	Fixed::toInt( void ) const
{
	return (_rawBits >> _fractional_bits);
}

float 	Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (float)(1 << _fractional_bits));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}


/* ************************************************************************** */
