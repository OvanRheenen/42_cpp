#include "Cure.hpp"
#include "ICharacter.hpp"

//--Con/destructors-----------------------------------------------------------//

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->type = other.type;
	
	return (*this);
}

Cure::~Cure() {}

//--Member functions----------------------------------------------------------//

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
