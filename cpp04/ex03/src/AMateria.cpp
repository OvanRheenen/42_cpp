#include "AMateria.hpp"

//--Con/destructors-----------------------------------------------------------//

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type) :
	type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (*this != other)
		this->type = other.type;

	return (*this);
}

AMateria::~AMateria()
{
}
