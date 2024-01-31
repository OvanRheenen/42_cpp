#include "Fixed.hpp"
#include <iostream>

// constructor
Fixed::Fixed() : 
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed &fixedPointN)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedPointN;
}

//copy assignement operator overload
Fixed	&Fixed::operator=(const Fixed &fixedPointN)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixedPointN.getRawBits());
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}
