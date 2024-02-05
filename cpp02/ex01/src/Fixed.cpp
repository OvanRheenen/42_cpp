#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// constructor
Fixed::Fixed() :
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// constructor with int arg
// converts [const int] to the corresponding fixed-point value.
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _binPoint;
}

// constructor with float arg
// converts [const float] to the corresponding fixed-point value.
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)f << _binPoint;							// shift integer part past the fixed point at _binPoint 00000000.00101101 -> 00101101.00000000
	float fraction = f - (int)f;							// get the fractional part of the float by subtracting the int part (42.42 - 42 = 0.42)
	fraction = fraction * pow(2, _binPoint);				// get the binary value of the fraction by shifting the . to the right by _binPoint places
	_value = _value | (int)round(fraction);					// add the fractional part in _value using the | operator
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

float	Fixed::toFloat( void ) const
{
	float f = _value >> _binPoint; 					// shift integer part past the fixed point
	float dec = (_value & 255) / pow(2, _binPoint);	// get only the decimal binary value (_value & 255), shift point to the left by _binPoint places
	return (f + dec);
}

int	Fixed::toInt( void ) const
{
	return (_value >> _binPoint);
}

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixedPointN)
{
	ostream << fixedPointN.toFloat();
	return (ostream);
}
