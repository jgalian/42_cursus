#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _rawBits(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ) : _rawBits(num << _fractional_bits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _rawBits(round(num * (1 << _fractional_bits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &		Fixed::operator = ( Fixed const & rhs )
{
	//std::cout << "Assignation operator called" << std::endl;
	_rawBits = rhs._rawBits;
	return *this;
}

bool	Fixed::operator > ( Fixed const & rhs ) const
{
	if (_rawBits > rhs._rawBits)
		return true;
	else
		return false;
}

bool	Fixed::operator < ( Fixed const & rhs ) const
{
	if (_rawBits < rhs._rawBits)
		return true;
	else
		return false;
}

bool	Fixed::operator >= ( Fixed const & rhs ) const
{
	if (_rawBits >= rhs._rawBits)
		return true;
	else
		return false;
}

bool	Fixed::operator <= ( Fixed const & rhs ) const
{
	if (_rawBits <= rhs._rawBits)
		return true;
	else
		return false;
}

bool	Fixed::operator == ( Fixed const & rhs ) const
{
	if (_rawBits == rhs._rawBits)
		return true;
	else
		return false;
}

bool	Fixed::operator != ( Fixed const & rhs ) const
{
	if (_rawBits != rhs._rawBits)
		return true;
	else
		return false;
}

Fixed	Fixed::operator + ( Fixed const & rhs ) const
{
	Fixed temp;
	temp.setRawBits(_rawBits + rhs._rawBits);
	return temp;
}

Fixed	Fixed::operator - ( Fixed const & rhs ) const
{
	Fixed temp;
	temp.setRawBits(_rawBits - rhs._rawBits);
	return temp;
}

Fixed	Fixed::operator * ( Fixed const & rhs ) const
{
	Fixed temp;
	temp.setRawBits((_rawBits * rhs._rawBits) / (1 << this->_fractional_bits));
	return temp;
}

Fixed	Fixed::operator / ( Fixed const & rhs ) const
{
	Fixed temp;
	temp.setRawBits((_rawBits * (1 << _fractional_bits)) / rhs._rawBits);
	return temp;
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

Fixed Fixed::operator++ ()
{
	_rawBits++;
	return ( *this );
}

Fixed Fixed::operator++ ( int i )
{
	Fixed tmp( *this );

	(void)i;
	operator++();
	return ( tmp );
}

Fixed Fixed::operator-- ()
{
	_rawBits--;
	return ( *this );
}

Fixed Fixed::operator-- ( int i )
{
	Fixed tmp( *this );

	(void)i;
	operator--();
	return ( tmp );
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed & Fixed::min(Fixed & num1, Fixed & num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed const & Fixed::min(Fixed const & num1, Fixed const & num2)
{
	if (num1< num2)
		return (num1);
	else
		return (num2);
}

Fixed & Fixed::max(Fixed & num1, Fixed & num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

Fixed const & Fixed::max(Fixed const & num1, Fixed const & num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

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
	//std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}


/* ************************************************************************** */
