#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int	main(void)
{
	DiamondTrap	jan("jan");

	jan.printStats();
	jan.whoAmI();
	jan.attack("arbnout");
}
