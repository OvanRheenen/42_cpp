#include "Contact.hpp"

void	Contact::printGeneralInfo(int index)
{
	std::cout	<< std::setw(10) << index << "|" 				\
				<< std::setw(10) << toSize(first_name) << "|"	\
				<< std::setw(10) << toSize(last_name) << "|"	\
				<< std::setw(10) << toSize(nickname)			\
				<< std::endl;
}

void	Contact::printAllInfo(void)
{
	std::cout << "First name:	" << first_name << std::endl;
	std::cout << "Last name:	" << last_name << std::endl;
	std::cout << "Nickname:	" << nickname << std::endl;
	std::cout << "Phone number:	" << phone_number << std::endl;
	std::cout << "Secret:		" << secret << std::endl;
}

void	Contact::addNewContact(void)
{
	std::cout << "Creating new contact" << std::endl;
	first_name = getValidInfo("first name:		");
	last_name = getValidInfo("last name:		");
	nickname = getValidInfo("nickname:		");
	phone_number = getValidInfo("phone number:		");
	secret = getValidInfo("secret:		");
}
