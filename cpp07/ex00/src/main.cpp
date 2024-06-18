#include "whatever.hpp"
#include <iostream>
#include <string>

int
main( void )
{
	{	
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "---------------------\nconst tests:\n" << std::endl;
	{
		const int a = 2;
		const int b = 3;

		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		const std::string c = "chaine1";
		const std::string d = "chaine2";
		
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "----------------------\nmore types tests:\n" << std::endl;
	{
		bool bool_a = true;
		bool bool_b = false;

		::swap( bool_a, bool_b );
		std::cout << "bool_a = " << bool_a << ", bool_b = " << bool_b << std::endl;

		double double_a = 3.14;
		double double_b = 2.718;

		::swap( double_a, double_b );
		std::cout << "double_a = " << double_a << ", double_b = " << double_b << std::endl;
		std::cout << "min( double_a, double_b ) = " << ::min( double_a, double_b ) << std::endl;
		std::cout << "max( double_a, double_b ) = " << ::max( double_a, double_b ) << std::endl;
	}
	return 0;
}
