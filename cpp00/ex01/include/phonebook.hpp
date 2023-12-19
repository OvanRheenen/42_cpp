#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cctype>

#define MAX_CONTACTS 8

bool		is_number(const std::string str);
int			get_valid_int(int len);
std::string	to_size(std::string str);
std::string	get_valid_info(const char *info_prompt);

class Contact
{
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::stringstream test;

	void print_general_info(int index)
	{
		std::cout << std::setw(10) << index << "|";
		std::cout << std::setw(10) << to_size(first_name) << "|";
		std::cout << std::setw(10) << to_size(last_name) << "|";
		std::cout << std::setw(10) << to_size(nickname) << std::endl;
	}

	void print_all_info()
	{
		std::cout << "First name:	" << first_name << std::endl;
		std::cout << "Last name:	" << last_name << std::endl;
		std::cout << "Nickname:	" << nickname << std::endl;
		std::cout << "Phone number:	" << phone_number << std::endl;
		std::cout << "Secret:		" << secret << std::endl;
	}

	void add()
	{
		std::cout << "Creating new contact" << std::endl;
		first_name = get_valid_info("first name:		");
		last_name = get_valid_info("last name:		");
		nickname = get_valid_info("nickname:		");
		phone_number = get_valid_info("phone number:		");
		secret = get_valid_info("secret:		");
	}

private:
	std::string	phone_number;
	std::string	secret;
};

class PhoneBook
{
public:
	Contact	contacts[MAX_CONTACTS];

	PhoneBook()
	{
		std::cout << "Opening Phonebook" << std::endl;
	}

	~PhoneBook()
	{
		std::cout << "Closing Phonebook" << std::endl;
	}

	void search(int len)
	{
		std::cout << std::setw(10) << "index" << "|";
		std::cout << std::setw(10) << "first name" << "|";
		std::cout << std::setw(10) << "last name" << "|";
		std::cout << std::setw(10) << "nickname" << std::endl;
		std::cout << std::string(43, '-') << std::endl;
		for (int i = 0; i < len; i++)
			contacts[i].print_general_info(i);
		std::cout << std::string(43, '-') << std::endl;

		std::cout << "Enter the index of the contact information you want to see: ";
		int	i = get_valid_int(len);
		while (i < 0 || i >= len)
		{
			if (len - 1 == 0)
				std::cout << "Please pick index 0, there's literally only one choice: ";
			else
				std::cout << "Please pick an index between 0 and " << len - 1 << ": ";
			i = get_valid_int(len);
		}
		contacts[i].print_all_info();
	}
};
