#include "Array.hpp"
#include "iostream"

int main(void)
{
	Array<int> a1(5);

	try {
		std::cout << a1[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	{
		std::cout << "int array test:\n" << std::endl;
		Array<int> array(4);
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		array[3] = 4;
		for (unsigned int i = 0; i <= array.size(); i++) {
			try {
				std::cout << array[i] << " ";
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
	}
}
