#include "phonebook.hpp"

static std::string	get_command()
{
	std::string command;

	while (command != "ADD" && command != "SEARCH" && command != "EXIT")
	{
		std::cout << "Please enter one of the following commands: ADD | SEARCH | EXIT" << std::endl;
		std::cout << "-> ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
	}
	return (command);
}

static void	add_contact(PhoneBook &pb, int &i, int &pb_len)
{
	pb.contacts[i].add_new_contact();
	std::cout << "New contact added" << std::endl;
	if (pb_len < MAX_CONTACTS)
		pb_len++;
	if (++i == MAX_CONTACTS)
		i = 0;
}

static void	search_contact(PhoneBook pb, int pb_len)
{
	if (pb_len == 0)
		std::cout << "First add at least one contact using the ADD command" << std::endl;
	else
		pb.search(pb_len);
}

int	main(void)
{
	PhoneBook	pb;
	
	std::string command = get_command();
	
	int	pb_len = 0;
	int i = 0;
	while (command != "EXIT")
	{
		if (command == "ADD")
			add_contact(pb, i, pb_len);
		else if (command == "SEARCH")
			search_contact(pb, pb_len);
		command = get_command();
	}
	return (EXIT_SUCCESS);
}
