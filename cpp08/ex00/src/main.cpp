#include "easyfind.hpp"

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <iterator>

int main(void)
{
	std::array<char, 2> ar({'a','b'});
	try {
		auto it = easyfind(ar, 'a');
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	std::vector<int> vc({-1, 2, 3, 2});
	try {
		auto it = easyfind(vc, 2);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	std::deque<long> dq({2, 3, 4, 5, 3});
	try {
		auto it = easyfind(dq, 3);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";
	
	std::list<short> lst({3, 8, 1, 9});
	try {
		auto it = easyfind(lst, 1);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";
	
	std::forward_list<bool> flst({true, false, true});
	try {
		auto it = easyfind(flst, false);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";
	
	std::array<int, 3> arr({1, 2, 3});
	try {
		auto it = easyfind(arr, 4);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";
	
	std::vector<int> vec(1000);
    for (int i = 0; i < 1000; i++)
	{
        if (i == 10)
			vec[i] = 9;
		else
			vec[i] = i;
    }
    vec[500] = 10;
	try {
        auto it = easyfind(vec, 10);
		std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
