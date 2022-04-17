#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:

		std::string 	_name;
		unsigned int	_maxHitPoints;
		unsigned int	_hitPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap &	operator = ( ClapTrap const & rhs );

		 void	attack( std::string const & target );
		 void	takeDamage( unsigned int amount );
		 void	beRepaired( unsigned int amount );

		std::string 	getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int 	getEnergyPoints( void ) const;
		unsigned int 	getAttackDamage( void ) const;
		void			incrementHitPoints( unsigned int );
		void			decrementHitPoints( unsigned int );
		void			incrementEnergyPoints( unsigned int );
		void			decrementEnergyPoints( unsigned int );

};

std::ostream &		operator << ( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */
