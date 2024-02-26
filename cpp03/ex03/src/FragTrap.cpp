#include "FragTrap.hpp"

//--Con/destructors-----------------------------------------------------------//

FragTrap::FragTrap()
{
	this->setName("DefaultBot");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	std::cout	<< "Default constructor called, " 
				<< "FragTrap " << this->getName()
				<< " created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	std::cout	<< "Name construtor called, "
				<< "FragTrap " << this->getName()
				<< " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout	<< "Copy constructor called, " 
				<< "copy of FragTrap " << other.getName()
				<< " created" << std::endl;

	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called on FragTrap " << this->getName() << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}

	std::cout	<< "Copy assignement operator called, " 
				<< "copy of FragTrap " << other.getName()
				<< " made" << std::endl;

	return (*this);
}

//--Member functions----------------------------------------------------------//

void	FragTrap::highFivesGuys(void)
{
	if (actionPossible("FragTrap", "high five"))
		std::cout	<< "FragTrap " << getName()
					<< " wants a high five!" << std::endl;
}
