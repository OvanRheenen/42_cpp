#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cctype>

#define MAX_CONTACTS 8

int			get_valid_int(int len);
std::string	get_valid_info(std::string info_prompt);
std::string	to_size(std::string str);

class Contact
{
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	void	print_general_info(int index);
	void	print_all_info(void);
	void	add_new_contact(void);

private:
	std::string	phone_number;
	std::string	secret;
};

class PhoneBook
{
public:
	Contact	contacts[MAX_CONTACTS];

	void	search(int len);
	void	print_table(int len);
	
	PhoneBook()
	{
		std::cout << "Opening Phonebook" << std::endl;
	}

	~PhoneBook()
	{
		std::cout << "Closing Phonebook" << std::endl;
	}
};
