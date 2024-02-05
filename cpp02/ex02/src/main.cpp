#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
Fixed		a(2);
Fixed		c;
Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

c = a + 4;

std::cout << "\nin/decrementation tests:" << std::endl;
std::cout << "a = " << a << std::endl;
std::cout << "++a: " << ++a << std::endl;
std::cout << "a = " << a << std::endl;
std::cout << "a++: " << a++ << std::endl;
std::cout << "a = " << a << std::endl;
std::cout << "--a: " << --a << std::endl;
std::cout << "a = " << a << std::endl;
std::cout << "a--: " << a-- << std::endl;
std::cout << "a = " << a << std::endl;


std::cout << "\nmin max tests:" << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "max is: " << Fixed::max(a, b) << std::endl;
std::cout << "min is: " << Fixed::min(a, b) << std::endl;

std::cout << "\narithmetic tests:" << std::endl;
std::cout << "a = " << a << ", c = " << c << std::endl;
std::cout << "a + c = " << a + c << std::endl;
std::cout << "a - c = " << a - c << std::endl;
std::cout << "a * c = " << a * c << std::endl;
std::cout << "a / c = " << a / c << std::endl;

std::cout << "\ncomparison tests:" << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "a < b: " << (a < b) << std::endl;
std::cout << "a > b: " << (a > b) << std::endl;
std::cout << "a >= b: " << (a >= b) << std::endl;
std::cout << "a <= b: " << (a <= b) << std::endl;
std::cout << "a == b: " << (a == b) << std::endl;
std::cout << "a != b: " << (a != b) << std::endl;

return 0;
}
