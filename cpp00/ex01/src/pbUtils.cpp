#include <stdlib.h>
#include <string.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	toSize(std::string str)
{
	std::string	tmp;
	
	if (str.length() > 10)
	{
		tmp = str.substr(0, 9) + ".";
		return (tmp);
	}
	return (str);
}

static void	erasespace(std::string &str)
{
	size_t	i = 0;
	size_t	len = str.length();

	while (i < len)
	{
		if (std::isspace(str[i]))
			str.erase(i, 1);
		else
			i++;
	}
}

static bool	isNumber(const std::string str)
{
	for (std::string::const_iterator i = str.begin(); i < str.end(); i++)
	{
		if (!std::isdigit(*i))
			return (false);
	}
	return (true);
}

static int	strToInt(const std::string str)
{
	std::stringstream	stoi;
	int					i;

	stoi << str;
	stoi >> i;

	return (i);
}

static int	getValidInt(int len)
{
	std::string tmp;

	std::getline(std::cin, tmp);
	if (std::cin.eof())
		exit(1);

	erasespace(tmp);

	while (tmp.length() != 1 || !isNumber(tmp))
	{
		if (len - 1 == 0)
			std::cout << "Please pick index 0, there's literally only one choice: ";
		else
			std::cout << "Please pick an index between 0 and " << len - 1 << ": ";

		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(1);

		erasespace(tmp);
	}

	return (strToInt(tmp));
}

static int	getIndex(int len)
{
	std::cout << "Enter the index of the contact information you want to see: ";
	int	i = getValidInt(len);
	while (i < 0 || i >= len)
	{
		if (len - 1 == 0)
			std::cout << "Please pick index 0, there's literally only one choice: ";
		else
			std::cout << "Please pick an index between 0 and " << len - 1 << ": ";
		i = getValidInt(len);
	}
	return (i);
}

static void trimTabs(std::string &str)
{
	// trim from the beginning
	size_t i = 0;
	while (i < str.length() && str[i] == '\t')
		str.erase(i, 1);

	// trim from the end
	i = str.length() - 1;
	while (i >= 0 && str[i] == '\t')
	{
		str.erase(i, 1);
		i--;
	}

	// trim from the middle
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == '\t')
		{
			size_t j = i;
			int tabcount = 0;
			while (j < str.length() && str[j] == '\t')
			{
				tabcount++;
				j++;
			}
			str.replace(i, tabcount, " ");
		}
	}
}

std::string getValidInfo(std::string info_prompt)
{
	std::string	tmp;

	std::cout << "Add their " << info_prompt;
	std::getline(std::cin, tmp);
	if (std::cin.eof())
		exit(1);

	trimTabs(tmp);

	while (tmp.length() == 0)
	{
		std::cout << "Field can't be left empty" << std::endl << "Add their " << info_prompt;
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(1);
		trimTabs(tmp);
	}

	return (tmp);
}
