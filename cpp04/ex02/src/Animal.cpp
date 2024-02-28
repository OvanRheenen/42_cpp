#include "Animal.hpp"

//--Con/destructors-----------------------------------------------------------//

Animal::Animal() :
	_type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called on type " << getType() << std::endl;
	*this = other;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignement operator called on type " << getType() << std::endl;
	
	if (this != &other)
		this->setType(other.getType());

	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called on " << getType() << std::endl;
}

//--Getters/Setters-----------------------------------------------------------//

std::string const	&Animal::getType() const
{
	return (_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}

//--Member functions----------------------------------------------------------//

void	Animal::makeSound() const
{
	std::cout << "*random animal sound*" << std::endl;
}
