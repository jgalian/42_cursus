#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &		operator = ( WrongAnimal const & rhs );

		void	makeSound(void) const;

		std::string		getType(void) const;

	protected:

		std::string	type;
};

#endif /* ***************************************************** WRONGANIMAL_H */
