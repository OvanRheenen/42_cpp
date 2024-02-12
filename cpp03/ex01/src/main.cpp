#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
//construction tests//
	{
		ScavTrap	a;
		a.printStats();

		ScavTrap	b("tBot");
		b.printStats();

		ScavTrap	c(b);
		c.printStats();

		ClapTrap	d;
		d.printStats();
		d = b;
		d.printStats();
	}

//attack, damage, repair tests//
	// {
	// 	ScavTrap	a("1st");
	// 	ClapTrap	b("2nd");

	// 	a.printStats();
	// 	b.printStats();

	// 	b.beRepaired(190);
	// 	b.printStats();
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
	// }
}
