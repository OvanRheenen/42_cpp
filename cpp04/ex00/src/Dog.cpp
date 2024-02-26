#include "Dog.hpp"

//--Con/destructors-----------------------------------------------------------//

Dog::Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called on type " << getType() << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignement operator called on type " << getType() << std::endl;
	
	if (this != &other)
		this->setType(other.getType());

	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called on " << getType() << std::endl;
}

//--Member functions----------------------------------------------------------//

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}
