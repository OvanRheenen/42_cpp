#include "Character.hpp"
#include "Floor.hpp"
#include "AMateria.hpp"

//--Con/destructors-----------------------------------------------------------//

Floor	Character::_floor = Floor();

Character::Character() :
	_name("Default")
{
	_inventory = new AMateria*[4];

	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const std::string &name) :
	_name(name)
{
	_inventory = new AMateria*[4];

	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;

		_inventory = new AMateria*[4];

		for (int i = 0; i < 4; i++)
			this->_inventory[i] = other._inventory[i];
	}

	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
		}
	}

	delete[] _inventory;
}

//--Member functions----------------------------------------------------------//

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (m == nullptr)
	{
		std::cout << "Materia does not exist." << std::endl;
		return;
	}

	if (m->getStatus() == EQUIPPED)
	{
		std::cout << _name << " cannot equip materia, it is already equipped by another character." << std::endl;
		return; 
	}
	else if (m->getStatus() == ON_THE_FLOOR)
	{
		_floor.removeFromFloor(m);
	}

	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			m->setStatus(EQUIPPED);
			return;
		}
	}

	std::cout << _name << " cannot equip materia, inventory is full." << std::endl;
	_floor.addNode(m);
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		_floor.addNode(_inventory[idx]);
		_inventory[idx] = nullptr;
		return;
	}

	std::cout << _name << " cannot unequip materia, no materia exists at idx " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		_inventory[idx]->use(target);
		return;
	}
	
	std::cout << _name << " cannot use materia, no materia exists at idx " << idx << std::endl;
}
