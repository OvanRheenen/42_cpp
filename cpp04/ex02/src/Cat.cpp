#include "Cat.hpp"
#include "Brain.hpp"

//--Con/destructors-----------------------------------------------------------//

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	setType("Cat");
	_brain = new Brain();
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
	{
		_brain = new Brain();
		*(this->_brain) = *(other._brain);
		this->setType(other.getType());
	}

	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called on " << getType() << std::endl;
	delete _brain;
}

//--Member functions----------------------------------------------------------//

void	Cat::makeSound() const
{
	std::cout << "meow meow" << std::endl;
}

void	Cat::printMemLocBrain() const
{
	std::cout << "Mem location of brain: " << this->_brain << std::endl;
}