#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria * source[4];

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator = ( MateriaSource const & rhs );

		void				learnMateria( AMateria * m );
		AMateria *			createMateria( std::string const & type );

};

#endif /* *************************************************** MATERIASOURCE_H */
