#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;
	Zombie = newZombie("Shaun");
	Zombie->announce();
	free(Zombie);
	
	randomChump("Ed");

	return (0);
}
