#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator = ( Brain const & rhs );

		void		printOneIdea(int n) const;

	private:

		std::string _ideas[100];

};

#endif /* *********************************************************** BRAIN_H */
