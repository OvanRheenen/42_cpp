#include "Ice.hpp"

//--Con/destructors-----------------------------------------------------------//

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Ice copy constructor called." << std::endl;

	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy assignment operator called." << std::endl;

	if (this != &other)
		this->type = other.type;
	
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice default destructor called." << std::endl;
}

//--Member functions----------------------------------------------------------//

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
