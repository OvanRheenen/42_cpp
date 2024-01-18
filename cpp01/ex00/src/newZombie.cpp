#include "Zombie.hpp"

Zombie	*newZombie( std::string name )
{
	Zombie	*newZombie;

	newZombie->name = name;

	return (newZombie);
}
