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

int	main(void)
{
	PhoneBook	phonebook;
	
	std::string command = get_command();
	
	int	pb_len = 0;
	int i = 0;
	while (command != "EXIT")
	{
		if (command == "ADD")
		{
			phonebook.contacts[i].add();
			std::cout << "New contact added" << std::endl;
			if (pb_len < MAX_CONTACTS)
				pb_len++;
			if (++i == MAX_CONTACTS)
				i = 0;
		}
		else if (command == "SEARCH")
		{
			if (pb_len == 0)
				std::cout << "First add at least one contact using the ADD command" << std::endl;
			else
				phonebook.search(pb_len);
		}
		command = get_command();
	}
	return (EXIT_SUCCESS);
}
