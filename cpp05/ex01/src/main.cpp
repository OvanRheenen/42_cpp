#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	me("me", 26);
	Form		form1("contract", 25, 15);

	std::cout << me << std::endl;
	std::cout << form1 << std::endl;

	try
	{
		form1.beSigned(me);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout	<< me.getName() << "couldn't sign "
					<< form1.getName() << ": "
					<< e.what() << std::endl;
	}
	std::cout << form1 << std::endl;
}
