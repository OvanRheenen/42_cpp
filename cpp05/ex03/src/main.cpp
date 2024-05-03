#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main(void)
{
	{ // subject test
		std::cout << "Normal test:\n" << std::endl;

		Intern	someIntern;
		AForm	*form;

		form = someIntern.makeForm("Robotomy Request", "Bender");

		if (form != nullptr)
			delete form;
	}
	std::cout << "-----------------------------------------------" << std::endl;
	{ 
		std::cout << "Non-existent form test:\n" << std::endl;

		Intern	intern1;
		AForm	*form;

		form = intern1.makeForm("Housing contract", "Expat");

		if (form != nullptr)
			delete form;
	}
	std::cout << "-----------------------------------------------" << std::endl;
	{	// Pardon test
		std::cout << "Pardon form test:\n" << std::endl;

		Bureaucrat	*dude = new Bureaucrat("Employee", 50);
		Bureaucrat	*pres = new Bureaucrat("The President", 1);
		Intern		*newGuy = new Intern();
		
		AForm *pardonForm = newGuy->makeForm("Presidential Pardon", "Some criminal");

		try
		{
			pardonForm->beSigned(*dude);
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr	<< dude->getName() 
						<< " coudln't sign " << pardonForm->getName()
						<< ": " << e.what() << std::endl;
		}

		try
		{
			pardonForm->beSigned(*pres);
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr	<< pres->getName() 
						<< " coudln't sign " << pardonForm->getName()
						<< ": " << e.what() << std::endl;
		}

		dude->executeForm(*pardonForm);
		pres->executeForm(*pardonForm);

		delete dude;
		delete pres;
		delete newGuy;
		delete pardonForm;
	}

}
