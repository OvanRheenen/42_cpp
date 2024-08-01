#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

template <typename iterator>
void printStack(iterator begin, iterator end)
{
	for (; begin != end; begin++)
	{
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}

int main()
{
	{//subject tests
		std::cout << "Subject tests with MutantStack:" << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{//subject tests with list
		std::cout << "\nSubject tests with std::list:" << std::endl;

		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.back() << std::endl;
		
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{//my tests
		std::cout << "\nMy tests:\n" << std::endl;

		MutantStack< int > mstack;
		mstack.push(8);
		mstack.push(30);
		mstack.push(16);
		mstack.push(2);
		mstack.push(21);

		MutantStack< int >::iterator it = mstack.begin();
		MutantStack< int >::iterator ite = mstack.end();

		std::cout << "Current stack: "; printStack(it, ite);
		std::sort(it, ite);
		std::cout << "Sorted stack: "; printStack(it, ite); std::cout << std::endl;
		
		MutantStack< int >::const_iterator cit = mstack.cbegin();
		MutantStack< int >::const_iterator cite = mstack.cend();
		std::cout << "Print using const its: "; printStack(cit, cite); std::cout << std::endl;
		// *cit = 25;

		MutantStack< int >::reverse_iterator rit = mstack.rbegin();
		MutantStack< int >::reverse_iterator rite = mstack.rend();
		std::cout << "Print using reverse its: "; printStack(rit, rite); std::cout << std::endl;

		MutantStack< int >::const_reverse_iterator crit = mstack.crbegin();
		MutantStack< int >::const_reverse_iterator crite = mstack.crend();
		std::cout << "Print using reverse its: "; printStack(crit, crite); std::cout << std::endl;
		// *crit = 10;
	}
	{
		std::cout << "Mutant stack with different underlying container:" << std::endl;

		MutantStack< int, std::vector< int > > mstack;
		mstack.push(8);
		mstack.push(30);
		mstack.push(16);
		mstack.push(2);
		mstack.push(21);

		MutantStack< int, std::vector< int > >::iterator it = mstack.begin();
		MutantStack< int, std::vector< int > >::iterator ite = mstack.end();

		std::cout << "Current stack: "; printStack(it, ite);
		std::sort(it, ite);
		std::cout << "Sorted stack: "; printStack(it, ite);
	}
}