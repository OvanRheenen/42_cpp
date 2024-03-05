#include "AMateria.hpp"
#include "ICharacter.hpp"

//--Con/destructors-----------------------------------------------------------//

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) :
	type(type), status(AVAILABLE)
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
	{
		this->type = other.type;
		this->status = other.status;
	}

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
