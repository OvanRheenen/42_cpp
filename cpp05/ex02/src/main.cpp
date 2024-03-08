#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int	main(void)
{
	{	// Shrubbery test
		std::cout << "Shrubbery form test:\n" << std::endl;

		Bureaucrat *dude = new Bureaucrat("Employee", 50);
		Bureaucrat *pres = new Bureaucrat("The President", 1);
		AForm *shrubForm = new ShrubberyCreationForm("test");

		try
		{
			shrubForm->beSigned(*dude);
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr	<< dude->getName() 
						<< " coudln't sign " << shrubForm->getName()
						<< ": " << e.what() << std::endl;
		}

		dude->executeForm(*shrubForm);
		pres->executeForm(*shrubForm);

		delete dude;
		delete pres;
		delete shrubForm;
	}
	std::cout << "-----------------------------------------" << std::endl;
	{	// Robotmy test
		std::cout << "Robotomy form test:\n" << std::endl;

		Bureaucrat *dude = new Bureaucrat("Employee", 50);
		Bureaucrat *pres = new Bureaucrat("The President", 1);
		AForm *robForm = new RobotomyRequestForm("Employee");

		try
		{
			robForm->beSigned(*dude);
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr	<< dude->getName() 
						<< " coudln't sign " << robForm->getName()
						<< ": " << e.what() << std::endl;
		}

		dude->executeForm(*robForm);
		pres->executeForm(*robForm);

		delete dude;
		delete pres;
		delete robForm;
	}
	std::cout << "-----------------------------------------" << std::endl;
	{	// Pardon test
		std::cout << "Pardon form test:\n" << std::endl;

		Bureaucrat *dude = new Bureaucrat("Employee", 50);
		Bureaucrat *pres = new Bureaucrat("The President", 1);
		AForm *pardonForm = new PresidentialPardonForm("Criminal 1");

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
			std::cerr	<< dude->getName() 
						<< " coudln't sign " << pardonForm->getName()
						<< ": " << e.what() << std::endl;
		}

		dude->executeForm(*pardonForm);
		pres->executeForm(*pardonForm);

		delete dude;
		delete pres;
		delete pardonForm;
	}
}