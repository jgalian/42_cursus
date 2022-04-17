#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator = ( Dog const & rhs );

		void		makeSound(void) const;

		void		getIdea(int) const;

	private:

		Brain *_brain;

};

#endif /* ************************************************************* DOG_H */
