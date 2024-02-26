#include "HumanB.hpp"

HumanB::HumanB(std::string name) : 
	_name(name),
	_Weapon(nullptr)
{
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(class Weapon &weapon_ref)
{
	_Weapon = &weapon_ref;
}
