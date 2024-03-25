#include "AAnimal.hpp"

//--Con/destructors-----------------------------------------------------------//

AAnimal::AAnimal() :
	_type("AAnimal")
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called on type " << getType() << std::endl;
	*this = other;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignement operator called on type " << getType() << std::endl;
	
	if (this != &other)
		this->setType(other.getType());

	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal default destructor called on " << getType() << std::endl;
}

//--Getters/Setters-----------------------------------------------------------//

std::string const	&AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::setType(const std::string &type)
{
	this->_type = type;
}
