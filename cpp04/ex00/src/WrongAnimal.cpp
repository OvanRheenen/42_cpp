#include "WrongAnimal.hpp"

//--Con/destructors-----------------------------------------------------------//

WrongAnimal::WrongAnimal() :
	_type("not specified")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called on type " << getType() << std::endl;
	*this = other;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignement operator called on type " << getType() << std::endl;
	
	if (this != &other)
		this->setType(other.getType());

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called on " << getType() << std::endl;
}

//--Getters/Setters-----------------------------------------------------------//

std::string const	&WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

//--Member functions----------------------------------------------------------//

void	WrongAnimal::makeSound() const
{
	std::cout << "*random WrongAnimal sound*" << std::endl;
}
