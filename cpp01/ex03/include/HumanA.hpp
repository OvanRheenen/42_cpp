#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
private:
	std::string const	_name;
	Weapon				&_Weapon;

public:
	HumanA(std::string name, class Weapon &weapon);

	void	attack(void);
};

#endif