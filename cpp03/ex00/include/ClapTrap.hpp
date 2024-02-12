#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
private:

	std::string		_name;
	unsigned int	_hitPoints = 10;
	unsigned int	_energyPoints = 10;
	unsigned int	_attackDamage = 0;

public:

	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	printStats() const;
	bool	actionPossible(const std::string &type, const std::string &action) const;

	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;

	void	setName(const std::string name);
	void	setHitPoints(const unsigned int amount);
	void	setEnergyPoints(const unsigned int amount);
	void	setAttackDamage(const unsigned int amount);
};

#endif