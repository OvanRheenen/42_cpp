#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int	main(void)
{
// construction test //
	{
		DiamondTrap	jan("jan");
		jan.printStats();
	}
//attack, damage, repair tests//
	// {
	// 	DiamondTrap	a("1st");
	// 	ClapTrap	b("2nd");

	// 	a.printStats();
	// 	b.printStats();

	// 	a.beRepaired(190);
	// 	a.printStats();
	// 	a.attack("2nd");
	// 	b.takeDamage(a.getAttackDamage());
	// 	b.printStats();

	// 	a.printStats();
	// 	int	i = 0;
	// 	while (b.getHitPoints() > 0)
	// 	{
	// 		std::cout << "attack " << i++ << std::endl;
	// 		a.attack("2nd");
	// 		b.takeDamage(a.getAttackDamage());
	// 		b.beRepaired(a.getAttackDamage() / 2);
	// 		std::cout << std::endl;
	// 	}

	// 	a.printStats();
	// 	b.printStats();

	// 	a.guardGate();
	// 	a.highFivesGuys();
	// }
}

