#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "A zombie emerged from their grave!" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << _name << " is destroyed!" << std::endl; 
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	this->_name = name;
}
