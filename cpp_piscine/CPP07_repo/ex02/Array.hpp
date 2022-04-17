#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template < typename T >
class Array
{
	private:

		T * _array;
		unsigned int const _size;

	public:

		Array() : _size(0)
		{
			std::cout << "Constructor por defecto" << std::endl;
			_array = new T[0];
		}

		Array(unsigned int n) : _size(n)
		{
			std::cout << "Constructor parametrizado" << std::endl;
			_array = new T[n];
		}

		Array( Array const & src ) : _size(src._size)
		{
			std::cout << "Copy constructor" << std::endl;
			_array = new T [src._size];
			for (unsigned int i = 0; i < src._size; i++)
				_array[i] = src._array[i];
		}

		~Array()
		{
			std::cout << "Destructor" << std::endl;
			delete [] _array;
		}

		Array &		operator = ( Array const & rhs )
		{
			std::cout << "Operator = overloading" << std::endl;
			swap(rhs);
			return *this;
		}

		T &	operator [] (unsigned int pos)
		{
			if (pos >= _size)
				throw (std::out_of_range("out_of_range"));
			else
				return (_array[pos]);
		}

		unsigned int	size() const
		{
			return (_size);
		}

};

#endif /* *********************************************************** ARRAY_H */
