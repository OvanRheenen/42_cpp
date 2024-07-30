#include "easyfind.hpp"

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>

int main(void)
{
	std::array<char, 2> ar({'a','b'});
	try {
		auto it = easyfind(ar, 'a');
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::vector<int> vc({-1, 2, 3, 2});
	try {
		auto it = easyfind(vc, 2);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::deque<long> dq({2, 3, 4, 5, 3});
	try {
		auto it = easyfind(dq, 3);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::list<short> lst({3, 8, 1, 9});
	try {
		auto it = easyfind(lst, 1);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::forward_list<bool> flst({true, false, true});
	try {
		auto it = easyfind(flst, false);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::array<int, 3> arr({1, 2, 3});
	try {
		auto it = easyfind(arr, 4);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
