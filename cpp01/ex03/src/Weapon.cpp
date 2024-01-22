#include "Weapon.hpp"

Weapon::Weapon(std::string type) : 
	type(type)
{
}

std::string const &	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}
