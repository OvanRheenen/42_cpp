#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() :
	_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = n << _binPoint;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = (int)f << _binPoint;							// shift integer part past the fixed point at _binPoint 00000000.00101101 -> 00101101.00000000
	float fraction = f - (int)f;							// get the fractional part of the float by subtracting the int part (42.42 - 42 = 0.42)
	fraction = fraction * pow(2, _binPoint);				// get the binary value of the fraction by shifting the . to the right by _binPoint places
	_value = _value | (int)round(fraction);					// add the fractional part in _value using the | operator
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixedPointN)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixedPointN;
}

Fixed	&Fixed::operator=(const Fixed &fixedPointN)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixedPointN.getRawBits());
	return (*this);
}

bool	Fixed::operator>(const Fixed &fixedPointN) const
{
	if (this->_value > fixedPointN._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &fixedPointN) const
{
	if (this->_value < fixedPointN._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &fixedPointN) const
{
	if (this->_value >= fixedPointN._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &fixedPointN) const
{
	if (this->_value <= fixedPointN._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &fixedPointN) const
{
	if (this->_value == fixedPointN._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &fixedPointN) const
{
	if (this->_value != fixedPointN._value)
		return (true);
	else
		return (false);
}

float	Fixed::operator+(const Fixed &fixedPointN) const
{
	return (this->toFloat() + fixedPointN.toFloat());
}

float	Fixed::operator-(const Fixed &fixedPointN) const
{
	return (this->toFloat() - fixedPointN.toFloat());
}

float	Fixed::operator*(const Fixed &fixedPointN) const
{
	return (this->toFloat() * fixedPointN.toFloat());
}

float	Fixed::operator/(const Fixed &fixedPointN) const
{
	return (this->toFloat() / fixedPointN.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);	
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
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
