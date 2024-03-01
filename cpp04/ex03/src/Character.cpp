#include "Character.hpp"

//--Con/destructors-----------------------------------------------------------//

Character::Character() :
	_name("Default")
{
	std::cout << "Character default destructor called." << std::endl;
	
	_inventory = new AMateria*[4];

	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const std::string &name) :
	_name(name)
{
	std::cout << "Character name constructor called." << std::endl;

	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called." << std::endl;
	
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called." << std::endl;
	
	if (this != &other)
	{
		this->_name = other._name;

		for (int i = 0; i < 4; i++)
			this->_inventory[i] = other._inventory[i];
	}
}

Character::~Character()
{
	std::cout << "Character default destructor called." << std::endl;

	delete _inventory;
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
	if (_inventory[idx])
		_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
