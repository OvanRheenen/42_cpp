#include "HumanB.hpp"

HumanB::HumanB(std::string name) : 
	name(name),
	Weapon(nullptr)
{
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(class Weapon &weapon_ref)
{
	Weapon = &weapon_ref;
}
