#include "ScavTrap.hpp"

//--Con/destructors-----------------------------------------------------------//

ScavTrap::ScavTrap()
{
	this->setName("DefaultBot");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);

	std::cout	<< "Default constructor called, " 
				<< "ScavTrap " << this->getName()
				<< " created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);

	std::cout	<< "Name construtor called, "
				<< "ScavTrap " << this->getName()
				<< " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout	<< "Copy constructor called, " 
				<< "copy of ScavTrap " << other.getName()
				<< " created" << std::endl;

	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called on ScavTrap " << this->getName() << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	}

	std::cout	<< "Copy assignement operator called, " 
				<< "copy of ScavTrap " << other.getName()
				<< " made" << std::endl;

	return (*this);
}

//--Member functions----------------------------------------------------------//

void	ScavTrap::attack(const std::string &target)
{
	if (actionPossible("ScavTrap", "attack"))
	{
		std::cout	<< "ScavTrap " << this->getName()
			<< " attacks " << target
			<< " causing " << this->getAttackDamage()
			<< " points of damage 💥" << std::endl;

		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void	ScavTrap::guardGate()
{
	if (actionPossible("ScavTrap", "Gatekeep"))
		std::cout	<< "Scavtrap " << getName()
					<< " is currently in Gatekeeper mode." << std::endl;
}
