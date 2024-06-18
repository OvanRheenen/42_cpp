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
		easyfind(ar, 'a');
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::vector<int> vc({-1, 2, 3, 2});
	try {
		easyfind(vc, 2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::deque<long> dq({2, 3, 4, 5, 3});
	try {
		easyfind(dq, 3);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::list<short> lst({3, 8, 1, 9});
	try {
		easyfind(lst, 1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::forward_list<bool> flst({true, false, true});
	try {
		easyfind(flst, false);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::array<int, 3> arr({1, 2, 3});
	try {
		easyfind(arr, 4);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
