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

static int	getIndex(int len)
{
	std::cout << "Enter the index of the contact information you want to see: ";
	int	i = getValidInt(len);
	while (i < 0 || i >= len)
	{
		if (len - 1 == 0)
			std::cout << "Please pick index 0, there's literally only one choice: ";
		else
			std::cout << "Please pick an index between 0 and " << len - 1 << ": ";
		i = getValidInt(len);
	}
	return (i);
}

void	PhoneBook::search(int len)
{
	print_table(len);
	int i = getIndex(len);
	contacts[i].printAllInfo();
}
