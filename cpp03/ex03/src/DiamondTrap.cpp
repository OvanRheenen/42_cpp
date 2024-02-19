#include "DiamondTrap.hpp"

//--Con/destructors-----------------------------------------------------------//

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	ScavTrap	tmpScav;
	FragTrap	tmpFrag;

	_name = "Default";
	ClapTrap::setName(_name + "_clap_name");

	setHitPoints(tmpFrag.getHitPoints());
	setEnergyPoints(tmpScav.getEnergyPoints());
	setAttackDamage(tmpFrag.getAttackDamage());

	std::cout	<< "Default constructor called, " 
			<< "DiamondTrap " << _name
			<< " created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)  : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	ScavTrap	tmpScav;
	FragTrap	tmpFrag;

	_name = name;
	ClapTrap::setName(_name + "_clap_name");

	setHitPoints(tmpFrag.getHitPoints());
	setEnergyPoints(tmpScav.getEnergyPoints());
	setAttackDamage(tmpFrag.getAttackDamage());

	std::cout	<< "Name constructor called, " 
			<< "DiamondTrap " << _name
			<< " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout	<< "Copy constructor called, " 
				<< "copy of DiamondTrap " << other.getName()
				<< " created" << std::endl;
	
	*this = other;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	}

	std::cout	<< "Copy assignement operator called, " 
				<< "copy of DiamondTrap " << other.getName()
				<< " made" << std::endl;
	
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called on DiamondTrap " << this->getName() << std::endl;
}

//--Member functions----------------------------------------------------------//

void	DiamondTrap::whoAmI()
{
	if (this->actionPossible("DiamondTrap", "repspond"))
	{
		std::cout	<< "My DiamondTrap name is " << this->_name
					<< "\nMy ClapTrap name is " << this->ClapTrap::getName() << std::endl;
	}
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
