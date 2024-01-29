#include "Contact.hpp"

void	Contact::printGeneralInfo(int index)
{
	std::cout	<< std::setw(10) << index << "|" 				\
				<< std::setw(10) << toSize(firstName) << "|"	\
				<< std::setw(10) << toSize(lastName) << "|"	\
				<< std::setw(10) << toSize(nickname)			\
				<< std::endl;
}

void	Contact::printAllInfo(void)
{
	std::cout << "First name:	" << firstName << std::endl;
	std::cout << "Last name:	" << lastName << std::endl;
	std::cout << "Nickname:	" << nickname << std::endl;
	std::cout << "Phone number:	" << _phoneNumber << std::endl;
	std::cout << "Secret:		" << _secret << std::endl;
}

void	Contact::addNewContact(void)
{
	std::cout << "Creating new contact" << std::endl;
	firstName = getValidInfo("First name:		");
	lastName = getValidInfo("Last name:		");
	nickname = getValidInfo("Nickname:		");
	_phoneNumber = getValidInfo("Phone number:		");
	_secret = getValidInfo("Secret:		");
}
