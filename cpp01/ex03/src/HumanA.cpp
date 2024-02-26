#include "HumanA.hpp"

HumanA::HumanA(std::string name, class Weapon &weapon) : 
	_name(name), 
	_Weapon(weapon)
{
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
