#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T >
void print( T const & index )
{
	std::cout << index << std::endl;
}

template < typename T >
void	iter(T * array, unsigned int const length, void (*f)(T const & index))
{
	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}

#endif
