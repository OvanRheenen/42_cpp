#include "phonebook.hpp"

static bool	is_number(const std::string str)
{
	for (std::string::const_iterator i = str.begin(); i < str.end(); i++)
	{
		if (!std::isdigit(*i))
			return (false);
	}
	return (true);
}

std::string	to_size(std::string str)
{
	std::string	tmp;
	
	if (str.length() > 10)
	{
		tmp = str.substr(0, 9) + ".";
		return (tmp);
	}
	return (str);
}

static int	str_to_int(std::string str)
{
	std::stringstream	stoi;
	int					i;

	stoi << str;
	stoi >> i;

	return (i);
}

int	get_valid_int(int len)
{
	std::string tmp;

	std::getline(std::cin, tmp);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);

	tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

	while (tmp.length() != 1 || !is_number(tmp))
	{
		std::cout << "Please pick an index between 0 and " << len - 1 << ": ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(EXIT_SUCCESS);
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
	}

	return (str_to_int(tmp));
}

std::string trim_tabs(std::string str)
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

	return (str);
}

std::string get_valid_info(std::string info_prompt)
{
	std::string	tmp;

	std::cout << "Add their " << info_prompt;
	std::getline(std::cin, tmp);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);

	tmp = trim_tabs(tmp);

	while (tmp.length() == 0)
	{
		std::cout << "Field can't be left empty" << std::endl << "Add their " << info_prompt;
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(EXIT_SUCCESS);
		tmp = trim_tabs(tmp);
	}

	return (tmp);
}
