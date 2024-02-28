#include "WrongCat.hpp"
#include "Brain.hpp"

//--Con/destructors-----------------------------------------------------------//

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	setType("WrongCat");
	_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat copy constructor called on type " << getType() << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignement operator called on type " << getType() << std::endl;
	
	if (this != &other)
	{
		this->setType(other.getType());
		this->_brain = other._brain;
	}

	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called on " << getType() << std::endl;
	delete _brain;
}

//--Member functions----------------------------------------------------------//

void	WrongCat::makeSound() const
{
	std::cout << "MEOOOO MEOOOO" << std::endl;
}

void	WrongCat::printMemLocBrain() const
{
	std::cout << "Mem location of brain: " << this->_brain << std::endl;
}
