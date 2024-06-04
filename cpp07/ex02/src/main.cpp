#include "Array.hpp"
#include "iostream"

#include "../../ex01/include/iter.hpp"
#include "../../ex00/include/whatever.hpp"

int main(void)
{
	{	
		std::cout << "out of bounds test:\n" << std::endl;
		Array<int> a1((unsigned int)5);

		try {
			std::cout << a1[5] << std::endl;
		}
		catch (Array<int>::OutOfBoundsException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-------------------------------" << std::endl;
	{
		std::cout << "char array test:\n" << std::endl;
		
		Array<char> array('a', 'b', 'c', 'd', 'e');

		iter(array.getData(), array.size(), &increment);
		
		array.print();
		try {
			std::cout << array[array.size() + 1] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		std::cout << "\nmax from " << array[1] << " and " << array[2] << ": " << max(array[1], array[2]) << "\n" << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	{
		std::cout << "copy and assignment operator tests:\n" << std::endl;

		Array<int> arr1(1,2,3,4);
		Array<int> arr2(4);

		arr2 = arr1;
		
		Array<int> arr3(arr2);

		arr2.print();

		arr2[0] = 41;
		iter(arr1.getData(), arr1.size(), &increment);

		std::cout << "\narray 1:" << std::endl;
		arr1.print();
		std::cout << "\narray 2:" << std::endl;
		arr2.print();
		std::cout << "\narray 3:" << std::endl;
		arr3.print();
	}
}
