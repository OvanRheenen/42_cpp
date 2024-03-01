#include "AMateria.hpp"

//--Con/destructors-----------------------------------------------------------//

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) :
	type(type)
{
	std::cout << "AMateria type constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor called." << std::endl;

	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment operator called." << std::endl;

	if (this != &other)
		this->type = other.type;

	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria default destructor called." << std::endl;
}

//--Member functions----------------------------------------------------------//

std::string const & AMateria::getType() const
{
	return (type);
}
