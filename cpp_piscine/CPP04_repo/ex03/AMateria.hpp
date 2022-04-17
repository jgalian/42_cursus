#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:

		std::string	_type;

	public:

		AMateria();
		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &			operator = ( AMateria const & rhs );

		virtual AMateria *	clone() const = 0;
		virtual void		use( ICharacter & target );

		std::string const &	getType() const;

};

#endif /* ******************************************************** AMATERIA_H */
