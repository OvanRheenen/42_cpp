#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

//--Con/destructors-----------------------------------------------------------//

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137, "Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExe(), other.getTarget())
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	
	this->setSigned(other.getSigned());

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


//--Member functions----------------------------------------------------------//

void ShrubberyCreationForm::execute(Bureaucrat const & executer) const
{
	checkValidExecution(executer, *this);

	std::ifstream inFile ("./asciitree.txt");
	if (!inFile.is_open())
	{
		std::cerr	<< "Error: unable to open input file: '" 
					<< "./asciitree.txt" << "'"
					<< std::endl;
		return;
	}

	std::ofstream outFile (getTarget() + "_shrubbery");
	if (!outFile.is_open())
	{
		std::cerr	<< "Error: unable to open output file: '" 
					<< getTarget() + "_shrubbery" << "'"
					<< std::endl;
		return;
	}

	std::string tmpLine;
	while (std::getline(inFile, tmpLine))
		outFile << tmpLine << '\n';

	std::cout	<< "Shrubbery created in file "
				<< getTarget() + "_shrubbery." << std::endl;
}
