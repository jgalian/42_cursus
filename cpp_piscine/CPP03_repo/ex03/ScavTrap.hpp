#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:

	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap( void );

		ScavTrap &	operator = ( ScavTrap const & rhs );

		void	attack( std::string const & target );
		void	guardGate( void );
};

std::ostream &		operator << ( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */
