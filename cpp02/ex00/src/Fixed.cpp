#include "Fixed.hpp"
#include <iostream>

//--Con/Destructors-----------------------------------------------------------//

Fixed::Fixed() : 
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixedPointN)
{
	std::cout << "Copy constructor called" << std::endl;
	
	*this = fixedPointN;
}

Fixed	&Fixed::operator=(const Fixed &fixedPointN)
{
	if (this != &fixedPointN)
		std::cout << "Copy assignment operator called" << std::endl;
	
	this->setRawBits(fixedPointN.getRawBits());
	
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//--Member functions----------------------------------------------------------//

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}
