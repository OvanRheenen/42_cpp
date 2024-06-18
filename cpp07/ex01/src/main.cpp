#include "iter.hpp"
#include <iostream>

int main(void)
{
	{	
		std::cout << "---------------\nint array test:\n" << std::endl;
		int array[4] = {1,2,3,4};

		std::cout << "before incrementing:" << std::endl;
		iter(array, 4, &print);
		iter(array, 4, &increment);
		std::cout << "after incrementing:" << std::endl;
		iter(array, 4, &print);
		std::cout << std::endl;
	}
	{
		std::cout << "----------------\nchar array test:\n" << std::endl;
		char array[4] = {'a','b','c','d'};

		std::cout << "before incrementing:" << std::endl;
		iter(array, 4, &print);
		iter(array, 4, &increment);
		std::cout << "after incrementing:" << std::endl;
		iter(array, 4, &print);
		std::cout << std::endl;
	}
	{
		std::cout << "----------------\nstring array test:\n" << std::endl;
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
