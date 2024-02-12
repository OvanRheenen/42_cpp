#include "ClapTrap.hpp"

//--Con/destructors-----------------------------------------------------------//

ClapTrap::ClapTrap() :
	_name("Jan")
{
	std::cout	<< "Default constructor called, " 
				<< "ClapTrap " << _name
				<< " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
	_name(name)
{
	std::cout	<< "Name construtor called, "
				<< "ClapTrap " << _name
				<< " created" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout	<< "Copy constructor called, " 
				<< "copy of ClapTrap " << other.getName()
				<< " created" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout	<< "Copy assignement operator called, " 
				<< "copy of ClapTrap " << other.getName()
				<< " made" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called on ClapTrap " << this->_name << std::endl;
}


//--Member functions----------------------------------------------------------//

bool	ClapTrap::actionPossible(const std::string &type, const std::string &action) const
{
	if (action != "be repaired" && getHitPoints() == 0)
	{
		std::cout	<< type << " " << getName()
					<< " is unable to " << action
					<< ". They're dead 💀" << std::endl;
		return (false);
	}
	else if ((action == "attack" || action == "be repaired") && getEnergyPoints() == 0)
	{
		std::cout	<< type << " " << getName()
					<< " is unable to " << action
					<< ". They're out of energy points 🪫" << std::endl;
		return (false);
	}

	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (actionPossible("ClapTrap", "attack"))
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " attacks " << target
					<< " causing " << this->_attackDamage << " points of damage 💥" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);

	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (actionPossible("ClapTrap", "take damage"))
	{
		if (amount > this->_hitPoints)
		{
			std::cout	<< "ClapTrap " << this->_name
					<< " takes " << this->_hitPoints << " of damage 🤕" << std::endl;
			this->setHitPoints(0);
		}
		else
		{
			std::cout	<< "ClapTrap " << this->_name
					<< " takes " << amount << " of damage 🤕" << std::endl;
			this->setHitPoints(this->getHitPoints() - amount);
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (actionPossible("ClapTrap", "be repaired"))
	{
		std::cout	<< "ClapTrap " << this->_name 
					<< " is repaired by " << amount << " hit points 🏥" << std::endl;
		this->setHitPoints(this->getHitPoints() + amount);
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}


//--Getters-------------------------------------------------------------------//

std::string	ClapTrap::getName() const
{
	return (_name);
}

int	ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}


//--Setters-------------------------------------------------------------------//

void	ClapTrap::setName(const std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(const unsigned int amount)
{
	this->_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(const unsigned int amount)
{
	this->_energyPoints = amount;
}

void	ClapTrap::setAttackDamage(const unsigned int amount)
{
	this->_attackDamage = amount;
}
