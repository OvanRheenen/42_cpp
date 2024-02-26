#include "WrongCat.hpp"

//--Con/destructors-----------------------------------------------------------//

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	setType("WrongCat");
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
		this->setType(other.getType());

	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called on " << getType() << std::endl;
}

//--Member functions----------------------------------------------------------//

void	WrongCat::makeSound() const
{
	std::cout << "MEOOOO MEOOOO" << std::endl;
}
