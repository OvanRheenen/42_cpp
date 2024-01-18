#include <iostream>

class	Zombie
{
private:

public:

	Zombie( void );
	~Zombie( void );

	std::string	name;
};

Zombie::Zombie( void )
{
	std::cout << name << " emerged from their grave!" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << name << " destroyed!" << std::endl; 
}
