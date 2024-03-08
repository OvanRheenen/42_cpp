#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int	main(void)
{
	Bureaucrat *dude = new Bureaucrat("Tymon", 25);
	Bureaucrat *pres = new Bureaucrat("The President", 1);
	AForm *shrub = new ShrubberyCreationForm("test");

	try
	{
		shrub->beSigned(*dude);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr	<< dude->getName() 
					<< " coudln't sign " << shrub->getName()
					<< ": " << e.what() << std::endl;
	}

	pres->executeForm(*shrub);

	delete dude;
	delete pres;
	delete shrub;
}