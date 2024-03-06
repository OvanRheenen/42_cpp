#include "AMateria.hpp"
#include "ICharacter.hpp"

//--Con/destructors-----------------------------------------------------------//

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : type(type), status(AVAILABLE) {}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->status = other.status;
	}

	return (*this);
}

AMateria::~AMateria() {}

//--Member functions----------------------------------------------------------//

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* nothing happens to " << target.getName() << " inside the base class *" << std::endl;
}

Status AMateria::getStatus()
{
	return (status);
}

void	AMateria::setStatus(Status status)
{
	this->status = status;
}
