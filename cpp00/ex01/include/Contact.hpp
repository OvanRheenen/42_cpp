#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

std::string	getValidInfo(std::string info_prompt);
std::string	toSize(std::string str);

class Contact
{
public:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;

	void	printGeneralInfo(int index);
	void	printAllInfo(void);
	void	addNewContact(void);

private:
	std::string	_phoneNumber;
	std::string	_secret;
};

#endif