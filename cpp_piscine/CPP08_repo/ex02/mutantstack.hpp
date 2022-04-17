#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack() {}
		virtual ~MutantStack() {}

		MutantStack( MutantStack const & src ) : std::stack<T>(src) {}

		MutantStack &	operator = ( MutantStack const & rhs )
		{
			if ( this != &rhs )
			{
				MutantStack temp(rhs);
				temp.swap(*this);
			}
			return *this;
		}

		iterator		begin( void )
		{
			return this->std::stack<T>::c.begin();
		}

		iterator		end( void )
		{
			return this->std::stack<T>::c.end();
		}
};

#endif /* ***************************************************** MUTANTSTACK_H */
