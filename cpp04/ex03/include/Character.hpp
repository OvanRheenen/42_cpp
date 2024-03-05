#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria 	**_inventory;
	static Floor	_floor;

public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif