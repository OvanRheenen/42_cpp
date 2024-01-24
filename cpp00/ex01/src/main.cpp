#include "PhoneBook.hpp"

static std::string	getCommand()
{
	std::string command;

	while (command != "ADD" && command != "SEARCH" && command != "EXIT")
	{
		std::cout << "Please enter one of the following commands: ADD | SEARCH | EXIT" << std::endl;
		std::cout << "-> ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit(1);
	}
	return (command);
}

static void	addContact(PhoneBook &pb, int &i, int &pb_len)
{
	pb.contacts[i].addNewContact();
	std::cout << "New contact added" << std::endl;
	if (pb_len < MAX_CONTACTS)
		pb_len++;
	if (++i == MAX_CONTACTS)
		i = 0;
}

static void	searchContact(PhoneBook pb, int pb_len)
{
	if (pb_len == 0)
		std::cout << "First add at least one contact using the ADD command" << std::endl;
	else
		pb.search(pb_len);
}

int	main(void)
{
	PhoneBook	pb;
	
	std::string command = getCommand();
	
	int	pb_len = 0;
	int i = 0;
	while (command != "EXIT")
	{
		if (command == "ADD")
			addContact(pb, i, pb_len);
		else if (command == "SEARCH")
			searchContact(pb, pb_len);
		command = getCommand();
	}
	return (1);
}
