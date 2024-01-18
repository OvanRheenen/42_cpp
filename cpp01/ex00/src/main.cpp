#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;
	Zombie = newZombie("Shaun");
	Zombie->announce();
	delete Zombie;

	std::cout << std::endl;
	
	randomChump("Ed");

	return (0);
}
