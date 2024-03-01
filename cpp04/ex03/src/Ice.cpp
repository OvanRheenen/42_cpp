#include "Ice.hpp"

//--Con/destructors-----------------------------------------------------------//

Ice::Ice() :
	type("ice")
{
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	if (*this != other)
		this->type = other.type;
}

Ice::~Ice()
{
}

//--Member functions----------------------------------------------------------//

AMateria	*Ice::clone()
{
	
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.name << " *"
}
