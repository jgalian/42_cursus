#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

	public:

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		FragTrap &	operator = ( FragTrap const & rhs );

		void	attack( std::string const & target );
		void	highFivesGuys(void);
};

std::ostream &			operator << ( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FRAGTRAP_H */
