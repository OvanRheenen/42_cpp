#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <algorithm>
# include <sstream>
# include "Contact.hpp"

# define MAX_CONTACTS 8

int			getValidInt(int len);
std::string	toSize(std::string str);

class PhoneBook
{
public:
	Contact	contacts[MAX_CONTACTS];

	PhoneBook(void);
	~PhoneBook(void);

	void	search(int len);
	void	print_table(int len);
};

#endif