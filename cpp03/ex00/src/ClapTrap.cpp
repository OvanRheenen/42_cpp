#include "ClapTrap.hpp"

//--Con/destructors-----------------------------------------------------------//

ClapTrap::ClapTrap() :
	name("Jan")
{
	std::cout	<< "Default constructor called, " 
				<< "ClapTrap " << this->name
				<< " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) :
	name(name)
{
	std::cout	<< "Name construtor called, "
				<< "ClapTrap " << name << " created" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout	<< "Copy constructor called, " 
				<< "copy of ClapTrap " << other.name << " created" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called on ClapTrap " << this->name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout	<< "Copy assignement operator called, " 
				<< "copy of ClapTrap " << other.name << " created" << std::endl;
	this->setName(other.getName());
	this->setHP(other.getHP());
	this->setEP(other.getEP());
	this->setAD(other.getAD());
	return (*this);
}


//--Member functions----------------------------------------------------------//

void	ClapTrap::attack(const std::string& target)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout	<< "ClapTrap " << this->name
					<< " attacks " << target
					<< " causing " << this->AD << " points of damage 💥" << std::endl;
		this->setEP(this->getEP() - 1);
	}
	else
	{
		if (this->HP <= 0)
			std::cout	<< "ClapTrap " << this->name
						<< " is unable to attack. They're dead 💀" << std::endl;
		else
			std::cout	<< "ClapTrap " << this->name
						<< " is unable to attack. They're out of energy points 🪫" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HP > 0)
	{
		if (amount > this->HP)
			this->setHP(0);
		else
		{
			std::cout	<< "ClapTrap " << this->name
					<< " takes " << amount << " of damage 🤕" << std::endl;
			this->setHP(this->getHP() - amount);
		}
	}
	else
		std::cout	<< "ClapTrap " << this->name
					<< " can't take anymore damage. They're dead 💀" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP > 0)
	{
		std::cout	<< "ClapTrap " << this->name 
					<< " is repaired by " << amount << " hit points 🏥" << std::endl;
		this->setHP(this->getHP() + amount);
		this->setEP(this->getEP() - 1);
	}
	else
		std::cout	<< "ClapTrap " << this->name
					<< " can't be repaired. They're out of energy points 🪫" << std::endl;
}


//--Getters-------------------------------------------------------------------//

std::string	ClapTrap::getName() const
{
	return (name);
}

int	ClapTrap::getHP() const
{
	return (HP);
}

int	ClapTrap::getEP() const
{
	return (EP);
}

int	ClapTrap::getAD() const
{
	return (AD);
}


//--Setters-------------------------------------------------------------------//

void	ClapTrap::setName(const std::string name)
{
	this->name = name;
}

void	ClapTrap::setHP(const unsigned int amount)
{
	this->HP = amount;
}

void	ClapTrap::setEP(const unsigned int amount)
{
	this->EP = amount;
}

void	ClapTrap::setAD(const unsigned int amount)
{
	this->AD = amount;
}
