#include <iostream>
#include <string>
#include <limits>

void	caseChar(std::string str)
{
	char const c = static_cast<char const>(str[0]);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int const>(c) << std::endl;
	std::cout << "float: " << static_cast<float const>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double const>(c) << ".0" << std::endl;
}

void	caseInt(std::string str)
{
	try
	{
		int	const i = static_cast<int const>(std::stoi(str));
		if (i == 127 || (i >= 0 && i <= 31))
			std::cout << "char: Non displayable" << std::endl;
		else if (i > 31 && i < 127)
			std::cout << "char: " << static_cast<char const>(i) << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float const>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double const>(i) << ".0" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": error: out_of_range\n";
		return ;
	}
}

void	caseFloat(std::string str)
{
	try
	{
		float const f = static_cast<float const>(stof(str));

		if (static_cast<int const>(f) == 127 || (static_cast<int const>(f) >= 0 && static_cast<int const>(f) <= 31))
			std::cout << "char: Non displayable" << std::endl;
		else if (static_cast<int const>(f) > 31 && static_cast<int const>(f) < 127)
			std::cout << "char: " << static_cast<char const>(f) << std::endl;
		else
			std::cout << "char: impossible" << std::endl;

		if ( static_cast<int const>(f) > std::numeric_limits<int>::min() && static_cast<int const>(f) < std::numeric_limits<int>::max() )
			std::cout << "int: " << static_cast<int const>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		if ( f - static_cast<int const>(f) == 0 )
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;

		if ( f - static_cast<int const>(f) == 0 )
			std::cout << "double: " << f << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double const>(f) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": error: out_of_range\n";
		return ;
	}
}

void	caseDouble(std::string str)
{
	try
	{
		double const d = static_cast<double const>(stod(str));

		if (static_cast<int const>(d) == 127 || (static_cast<int const>(d) >= 0 && static_cast<int const>(d) <= 31))
			std::cout << "char: Non displayable" << std::endl;
		else if (static_cast<int const>(d) > 31 && static_cast<int const>(d) < 127)
			std::cout << "char: " << static_cast<char const>(d) << std::endl;
		else
			std::cout << "char: impossible" << std::endl;

		if (static_cast<int const>(d) > std::numeric_limits<int>::min() && static_cast<int const>(d) < std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int const>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		if (d - static_cast<int const>(d) == 0)
			std::cout << "float: " << d << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float const>(d) << "f" << std::endl;

		if (d - static_cast<int const>(d) == 0)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": error: out_of_range\n";
		return ;
	}
}

int	detectType(std::string str)
{
	if (str.size() == 1 && (str[0] < 48 || str[0] > 57))
		return (1);
	if (str.find(".") == std::string::npos && str.find("n") == std::string::npos)
		return (2);
	if (str[str.size() - 1] == 'f' && str != "-inf" && str != "+inf")
		return (3);
	else
		return (4);
}

int	main(int argc, char *argv[])
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "Incorrect number of parameters" << std::endl;
		return (-1);
	}
	std::string const str = static_cast<std::string const>(argv[1]);
	int typeCode = detectType(str);
	switch (typeCode)
	{
		case 1: caseChar(str); break ;
		case 2: caseInt(str); break ;
		case 3: caseFloat(str); break ;
		case 4: caseDouble(str); break ;
	}
	return (0);
}
