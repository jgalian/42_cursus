#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed( const int num );
		Fixed( const float num );
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &	operator = ( Fixed const & rhs );
		bool	operator > ( Fixed const & rhs ) const;
		bool	operator < ( Fixed const & rhs ) const;
		bool	operator >= ( Fixed const & rhs ) const;
		bool	operator <= ( Fixed const & rhs ) const;
		bool	operator == ( Fixed const & rhs ) const;
		bool	operator != ( Fixed const & rhs ) const;
		Fixed	operator + ( Fixed const & rhs ) const;
		Fixed	operator - ( Fixed const & rhs ) const;
		Fixed	operator * ( Fixed const & rhs ) const;
		Fixed	operator / ( Fixed const & rhs ) const;
		Fixed	operator++ ();
		Fixed	operator++ ( int i );
		Fixed	operator-- ();
		Fixed	operator-- ( int i );

		static Fixed &			min(Fixed &, Fixed &);
		static Fixed const &	min(Fixed const &, Fixed const &);
		static Fixed &			max(Fixed &, Fixed &);
		static Fixed const &	max(Fixed const &, Fixed const &);

		int 	toInt( void ) const;
		float 	toFloat( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int					_rawBits;
		static const int	_fractional_bits = 8;

};

std::ostream &		operator << ( std::ostream & o, Fixed const & i );

#endif /* ************************************************* FIXED_H */
