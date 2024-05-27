#include "iter.hpp"
#include <iostream>

int main(void)
{
	{	
		std::cout << "int array test:\n" << std::endl;
		int array[4] = {1,2,3,4};

		std::cout << "before incrementing:" << std::endl;
		iter(array, 4, &print);
		iter(array, 4, &increment);
		std::cout << "after incrementing:" << std::endl;
		iter(array, 4, &print);
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "char array test:\n" << std::endl;
		char array[4] = {'a','b','c','d'};

		std::cout << "before incrementing:" << std::endl;
		iter(array, 4, &print);
		iter(array, 4, &increment);
		std::cout << "after incrementing:" << std::endl;
		iter(array, 4, &print);
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "string array test:\n" << std::endl;
		char one[6] = "hello";
		char two[6] = "world";
		char three[5] = "it's";
		char four[3] = "me";
		char *array[4] = {one,two,three,four};

		std::cout << "before incrementing:" << std::endl;
		iter(array, 4, &print);
		iter(array, 4, &increment);
		std::cout << "after incrementing:" << std::endl;
		iter(array, 4, &print);
	}
}
