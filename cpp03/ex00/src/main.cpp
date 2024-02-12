#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Tymon");
	ClapTrap	c(b);
	ClapTrap	d;

	d = b;

	a.setAttackDamage(3);
	a.attack("Tymon");
	b.takeDamage(a.getAttackDamage());
	std::cout << "Tymon life left: " << b.getHitPoints() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAttackDamage());
	std::cout << "Tymon life left: " << b.getHitPoints() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAttackDamage());
	std::cout << "Tymon life left: " << b.getHitPoints() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAttackDamage());
	std::cout << "Tymon life left: " << b.getHitPoints() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAttackDamage());
	std::cout << "Tymon life left: " << b.getHitPoints() << std::endl;	

}
