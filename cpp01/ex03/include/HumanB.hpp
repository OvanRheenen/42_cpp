#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
private:
	std::string const	_name;
	Weapon				*_Weapon;

public:
	HumanB(std::string name);

	void	attack(void);
	void	setWeapon(class Weapon &weapon);
};

#endif