#include "phonebook.hpp"

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
		contacts[i].print_general_info(i);
	std::cout << std::string(43, '-') << std::endl;
}

static int	get_index(int len)
{
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
	return (i);
}

void	PhoneBook::search(int len)
{
	print_table(len);
	int i = get_index(len);
	contacts[i].print_all_info();
}

void	Contact::print_general_info(int index)
{
	std::cout	<< std::setw(10) << index << "|" 				\
				<< std::setw(10) << to_size(first_name) << "|"	\
				<< std::setw(10) << to_size(last_name) << "|"	\
				<< std::setw(10) << to_size(nickname)			\
				<< std::endl;
}

void	Contact::print_all_info(void)
{
	std::cout << "First name:	" << first_name << std::endl;
	std::cout << "Last name:	" << last_name << std::endl;
	std::cout << "Nickname:	" << nickname << std::endl;
	std::cout << "Phone number:	" << phone_number << std::endl;
	std::cout << "Secret:		" << secret << std::endl;
}

void	Contact::add_new_contact(void)
{
	std::cout << "Creating new contact" << std::endl;
	first_name = get_valid_info("first name:		");
	last_name = get_valid_info("last name:		");
	nickname = get_valid_info("nickname:		");
	phone_number = get_valid_info("phone number:		");
	secret = get_valid_info("secret:		");
}
