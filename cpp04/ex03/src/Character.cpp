#include "Character.hpp"

//--Con/destructors-----------------------------------------------------------//

Character::Character() :
	_name("Default")
{
}

Character::Character(const std::string &name) :
	_name(name)
{
}

Character::Character(const Character &other)
{
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	if (*this != other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = other._inventory[i];
	}
}

Character::~Character()
{
}

//--Member functions----------------------------------------------------------//

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
			_inventory[i] = m;
	}
}

void Character::unequip(int idx)
{
	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	_inventory[idx].use(target);
}
