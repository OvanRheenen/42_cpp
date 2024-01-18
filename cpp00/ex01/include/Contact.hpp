#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

std::string	getValidInfo(std::string info_prompt);
std::string	toSize(std::string str);

class Contact
{
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	void	printGeneralInfo(int index);
	void	printAllInfo(void);
	void	addNewContact(void);

private:
	std::string	phone_number;
	std::string	secret;
};

#endif