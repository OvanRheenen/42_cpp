#include "Cat.hpp"

//--Con/destructors-----------------------------------------------------------//

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called on type " << getType() << std::endl;
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement operator called on type " << getType() << std::endl;
	
	if (this != &other)
		this->setType(other.getType());

	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called on " << getType() << std::endl;
}

//--Member functions----------------------------------------------------------//

void	Cat::makeSound() const
{
	std::cout << "meow meow" << std::endl;
}
