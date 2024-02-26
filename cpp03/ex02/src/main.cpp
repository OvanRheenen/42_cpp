#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
// construction tests //
	{
		FragTrap	a;
		a.printStats();

		FragTrap	b("bot");
		b.printStats();

		FragTrap	c(b);
		c.printStats();

		ClapTrap	d;
		d.printStats();
		d = b;
		d.printStats();
	}

//attack, damage, repair tests//
	// {
	// 	FragTrap	a("1st");
	// 	ScavTrap	b("2nd");
	// 	ClapTrap	c("3rd");

	// 	a.printStats();
	// 	b.printStats();
	// 	c.printStats();

	// 	a.beRepaired(65);
	// 	a.printStats();
	// 	a.attack("2nd");
	// 	b.takeDamage(a.getAttackDamage());
	// 	b.printStats();

	// 	a.printStats();
	// 	int	i = 0;
	// 	while (c.getHitPoints() > 0)
	// 	{
	// 		std::cout << "attack " << i++ << std::endl;
	// 		a.attack("3rd");
	// 		c.takeDamage(a.getAttackDamage());
	// 		std::cout << std::endl;
	// 	}

	// 	a.printStats();
	// 	b.printStats();
	// 	c.printStats();

	// 	a.highFivesGuys();
	// }
}
