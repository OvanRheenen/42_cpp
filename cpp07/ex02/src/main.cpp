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
		catch (std::exception &e) {
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
	std::cout << "-------------------------------" << std::endl;
	#define MAX_VAL 750
	{
		Array<int> numbers((unsigned int)MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		return 0;
	}
}
