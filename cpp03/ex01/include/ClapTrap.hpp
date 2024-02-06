#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
private:

	std::string		name;
	unsigned int	HP = 10;
	unsigned int	EP = 10;
	unsigned int	AD = 0;

public:

	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getHP() const;
	int			getEP() const;
	int			getAD() const;

	void	setName(const std::string name);
	void	setHP(const unsigned int amount);
	void	setEP(const unsigned int amount);
	void	setAD(const unsigned int amount);
};

#endif