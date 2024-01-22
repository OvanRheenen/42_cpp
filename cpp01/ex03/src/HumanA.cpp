#include "HumanA.hpp"

HumanA::HumanA(std::string name, class Weapon &weapon) : 
	name(name), 
	Weapon(weapon)
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << Weapon.getType() << std::endl;
}
