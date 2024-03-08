#include <iostream>
#include <cstdlib>
#include <time.h>
#include "RobotomyRequestForm.hpp"

//--Con/destructors-----------------------------------------------------------//

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45, "Default Person") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExe(), other.getTarget())
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	
	this->setSigned(other.getSigned());

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}


//--Member functions----------------------------------------------------------//

void RobotomyRequestForm::execute(Bureaucrat const & executer) const
{
	checkValidExecution(executer, *this);

	srand(time(0));
	std::cout	<< "* DRILLING NOISES *\n"
				<< (rand() % 2 == 0 ? "Successfully robotomized " : "Failed to robotomize ")
				<< getTarget() << "." << std::endl;
}
