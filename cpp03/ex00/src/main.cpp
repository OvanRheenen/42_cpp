#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Tymon");
	ClapTrap	c(b);
	ClapTrap	d;

	d = b;

	a.setAD(3);
	a.attack("Tymon");
	b.takeDamage(a.getAD());
	std::cout << "Tymon life left: " << b.getHP() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAD());
	std::cout << "Tymon life left: " << b.getHP() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAD());
	std::cout << "Tymon life left: " << b.getHP() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAD());
	std::cout << "Tymon life left: " << b.getHP() << std::endl;	
	a.attack("Tymon");
	b.takeDamage(a.getAD());
	std::cout << "Tymon life left: " << b.getHP() << std::endl;	

}
