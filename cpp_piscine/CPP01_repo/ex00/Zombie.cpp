#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "hola" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " destuctor called" << std::endl;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
