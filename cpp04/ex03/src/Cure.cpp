#include "Cure.hpp"
#include "ICharacter.hpp"

//--Con/destructors-----------------------------------------------------------//

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << "Cure copy constructor called." << std::endl;

	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment operator called." << std::endl;
	
	if (this != &other)
		this->type = other.type;
	
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure default destructor called." << std::endl;
}

//--Member functions----------------------------------------------------------//

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
