#include <iostream>
#include "PresidentialPardonForm.hpp"

//--Con/destructors-----------------------------------------------------------//

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presindential Pardon", 25, 5, "Default Criminal") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExe(), other.getTarget())
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	
	this->setSigned(other.getSigned());

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}


//--Member functions----------------------------------------------------------//

void PresidentialPardonForm::execute(Bureaucrat const & executer) const
{
	checkValidExecution(executer, *this);

	std::cout	<< getTarget() 
				<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
