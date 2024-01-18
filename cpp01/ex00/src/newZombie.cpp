#include "Zombie.hpp"

Zombie	*newZombie( std::string name )
{
	Zombie	*newZombie = nullptr;

	newZombie->name = name;

	return (newZombie);
}
