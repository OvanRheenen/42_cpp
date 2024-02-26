#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "DiamondTrap create: " << std::endl;
	DiamondTrap	jan("jan");
	std::cout << "Done\n" << std::endl;

	jan.printStats();
	jan.whoAmI();
	std::cout << std::endl;
	jan.attack("arnout");
	std::cout << std::endl;
	jan.beRepaired(100);
	jan.takeDamage(150);
	std::cout << std::endl;

	jan.guardGate();
	jan.highFivesGuys();
	std::cout << std::endl;

	jan.setHitPoints(25);
	jan.setEnergyPoints(30);
	jan.setAttackDamage(20);
	jan.printStats();
}
