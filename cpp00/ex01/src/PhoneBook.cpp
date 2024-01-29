#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Opening Phonebook" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Closing Phonebook" << std::endl;
}

void	PhoneBook::print_table(int len)
{
	std::cout	<< std::setw(10) << "index" << "|"		\
				<< std::setw(10) << "first name" << "|"	\
				<< std::setw(10) << "last name" << "|"	\
				<< std::setw(10) << "nickname"			\
				<< std::endl \
				<< std::string(43, '-') \
				<< std::endl;
	for (int i = 0; i < len; i++)
		contacts[i].printGeneralInfo(i);
	std::cout << std::string(43, '-') << std::endl;
}

void	PhoneBook::search(int len)
{
	print_table(len);
	int i = getIndex(len);
	contacts[i].printAllInfo();
}
