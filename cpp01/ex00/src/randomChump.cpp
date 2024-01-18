#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	newZombie;

	newZombie.name = name;

	newZombie.announce();
}
