#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "A zombie emerged from their grave!" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << name << " is destroyed!" << std::endl; 
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
