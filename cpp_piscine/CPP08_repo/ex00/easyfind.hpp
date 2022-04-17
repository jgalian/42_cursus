#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <algorithm>

template<typename T>
int * easyfind(T t, int value)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), value);
	if (it == t.end())
		throw ("Value not found");
	return (&(*it));
}

#endif
