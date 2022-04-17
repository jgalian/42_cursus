#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &		operator = ( AAnimal const & rhs );

		virtual void	makeSound(void) const = 0;

		std::string		getType(void) const;
		void			setType(std::string);

	protected:

		std::string	type;

};

#endif /* ********************************************************** AANIMAL_H */
