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
	std::cout << "_secret:		" << _secret << std::endl;
}

void	Contact::addNewContact(void)
{
	std::cout << "Creating new contact" << std::endl;
	firstName = getValidInfo("first name:		");
	lastName = getValidInfo("last name:		");
	nickname = getValidInfo("nickname:		");
	_phoneNumber = getValidInfo("phone number:		");
	_secret = getValidInfo("_secret:		");
}
