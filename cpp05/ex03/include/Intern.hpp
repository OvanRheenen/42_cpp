#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formType, const std::string &target);
};

#endif