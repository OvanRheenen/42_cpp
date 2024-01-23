#include "replace.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

static std::string	copyAndReplace(std::string line, std::string s1, std::string s2)
{
	std::string repLine;

	if (s1.length() == 0)
		return (line);

	size_t pos;
	size_t i = 0;
	while (i < line.length())
	{
		pos = line.find(s1, i);
		if (pos == std::string::npos)
		{
			repLine += line.substr(i);
			break;
		}
		else
		{
			repLine += line.substr(i, pos - i);
			repLine += s2;
			i += pos + s1.length();
		}
	}
	return (repLine);
}

int	openAndCopy(char *filename, char *s1, char *s2)
{
	std::ifstream	inFile (filename);
	if (!inFile.is_open())
	{
		std::cout << "Error: unable to open input file: '" << filename << "'" << std::endl;
		return (1);
	}

	std::ofstream	outFile ((std::string)filename += ".replace");
	if (!outFile.is_open())
	{
		std::cout << "Error: unable to open output file";
		return (1);
	}

	std::string tmpLine;
	while (std::getline(inFile, tmpLine))
		outFile << copyAndReplace(tmpLine, s1, s2) << std::endl;

	return (0);
}
