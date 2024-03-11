#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

//--Con/destructors-----------------------------------------------------------//

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;

	return (*this);
}

Intern::~Intern() {}

//--Static functions for makeForm()-------------------------------------------//

static AForm *createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

//--Member functions----------------------------------------------------------//

AForm *Intern::makeForm(const std::string &formType, const std::string &target)
{
	const std::string formTypes[3] = 
	{
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation"
	};
	AForm *(*funcs[3])(const std::string &target) =
	{
		&createPresidentialPardonForm,
		&createRobotomyRequestForm,
		&createShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formType == formTypes[i])
		{
			std::cout << "Intern creates " << formType << " form." << std::endl;
			return (funcs[i](target));
		}
	}

	std::cerr << "Error: form '" << formType << "' does not exist." << std::endl;
	return (nullptr);
}
