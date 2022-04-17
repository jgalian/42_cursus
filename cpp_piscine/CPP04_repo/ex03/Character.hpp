#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:

		std::string		_name;
		AMateria *		_inventory[4];

		Character();

	public:


		Character( std::string name );
		Character( Character const & src );
		~Character();

		Character &			operator = ( Character const & rhs );

		void				equip( AMateria * m );
		void				unequip( int idx );
		void				use( int idx, ICharacter & target );

		std::string const &	getName( void ) const;

};

#endif /* ******************************************************* CHARACTER_H */
