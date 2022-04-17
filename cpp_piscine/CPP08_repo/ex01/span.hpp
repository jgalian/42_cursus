#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <time.h>
# include <stdlib.h>
# include <limits.h>
# include <algorithm>

class Span
{
	private:
		size_t				 _N;
		std::vector<int>	_vec;

		Span();

	public:

		Span(size_t N);
		Span( Span const & src );
		~Span();

		void			addNumber(int value);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printValue(size_t pos);
		void			printAllValues(void);
		void			addRandomValues(size_t n_elements);

		Span &		operator = ( Span const & rhs );



		std::vector<int> &		getVector(void);

};

std::ostream &			operator << ( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */
