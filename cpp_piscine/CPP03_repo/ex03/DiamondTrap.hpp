#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string	_name;

	public:

		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap( void );

		DiamondTrap &	operator = ( DiamondTrap const & rhs );

		void	attack( std::string const & target );
		void	whoAmI( void );
};

std::ostream &			operator << ( std::ostream & o, DiamondTrap const & i );

#endif /* ***************************************************** DIAMONDTRAP_H */
