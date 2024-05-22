#include "iter.hpp"
#include <iostream>

int main(void)
{
	int array[4] = {1,2,3,4};

	iter(array, 4, &print);
	iter(array, 4, &increment);
	std::cout << "after incrementing:" << std::endl;
	iter(array, 4, &print);
}
