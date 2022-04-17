/*
* In C99, uintptr_t it is defined as "an unsigned integer type with the property
* that any valid pointer to void can be converted to this type, then converted back
* to pointer to void, and the result will compare equal to the original pointer".
*/

#include <iostream>
#include <string>

typedef struct	s_Data
{
	int a;
}				Data;

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	{
		Data data;
		Data *data_ptr;
		uintptr_t raw;

		std::cout << &data << std::endl;

		raw = serialize(&data);
		data_ptr = deserialize(raw);

		std::cout << data_ptr << std::endl;
	}
	return (0);
}
