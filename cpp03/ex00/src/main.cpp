#include "ClapTrap.hpp"

int	main(void)
{
//construction tests//
	{
		ClapTrap	a;

		a.printStats();

		ClapTrap	b("Tymon");

		b.printStats();

		ClapTrap	c(b);

		c.printStats();

		ClapTrap	d;
		d = b;
		d.printStats();
	}

//attack, damage, repair tests//
	// {
	// 	ClapTrap	a("1st");
	// 	ClapTrap	b("2nd");

	// 	a.attack("2nd");
	// 	b.takeDamage(1);
	// 	b.printStats();
	// 	a.printStats();

	// 	for (int i = 0; i < 9; i++)
	// 	{
	// 		a.attack("2nd");
	// 		b.takeDamage(1);
	// 	}

	// 	b.printStats();
	// 	a.printStats();
	// 	a.attack("2nd");
	// 	b.takeDamage(1);
	
	// 	b.beRepaired(10);
	// 	b.printStats();

	// 	a.beRepaired(10);
	// 	a.printStats();
	// }

}
