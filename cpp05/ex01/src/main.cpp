#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	{	// basic tests
		std::cout << "Basic test:\n" << std::endl;

		Bureaucrat	me("me", 25);
		Form		form1("contract", 50, 25);

		std::cout << me << std::endl;
		std::cout << form1 << std::endl;

		try
		{
			form1.beSigned(me);
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cerr	<< me.getName() << " couldn't sign "
						<< form1.getName() << ": "
						<< e.what() << std::endl;
		}

		std::cout << form1 << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
	{	// Not allowed to sign test
		std::cout << "Not allowed to sign:\n" << std::endl;

		Bureaucrat	me("me", 25);
		Bureaucrat	manager("manager", 15);
		Bureaucrat	boss("boss", 1);

		Form *form1 = nullptr;
		try
		{
			form1 = new Form("contract", 20, 15);
		}
		catch (std::exception& e)
		{
			std::cout << "Can't create new form: " << e.what() << std::endl;
			delete form1;
			return (1);
		}

		try
		{
			form1->beSigned(me);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr	<< me.getName() << " couldn't sign "
						<< form1->getName() << ": "
						<< e.what() << std::endl;
		}

		std::cout << *form1 << std::endl;

		try
		{
			form1->beSigned(manager);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr	<< manager.getName() << " couldn't sign "
						<< form1->getName() << ": "
						<< e.what() << std::endl;
		}
		
		std::cout << *form1 << std::endl;

		// try to sign again
		try
		{
			form1->beSigned(boss);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr	<< boss.getName() << " couldn't sign "
						<< form1->getName() << ": "
						<< e.what() << std::endl;
		}

		delete form1;
	}
	std::cout << "------------------------------------------" << std::endl;
	{	// Invalid form grades
		std::cout << "Invalid form tests:\n" << std::endl;

		Form *a = nullptr;
	
		try
		{
			a = new Form("high sign", -2, 50);
		}
		catch (std::exception& e)
		{
			std::cout << "Can't create new form: " << e.what() << std::endl;
			delete a;
		}

		try
		{
			a = new Form("low sign", 166, 50);
		}
		catch (std::exception& e)
		{
			std::cout << "Can't create new form: " << e.what() << std::endl;
			delete a;
		}

		try
		{
			a = new Form("high exe", 50, -41);
		}
		catch (std::exception& e)
		{
			std::cout << "Can't create new form: " << e.what() << std::endl;
			delete a;
		}

		try
		{
			a = new Form("low exe", 50, 431);
		}
		catch (std::exception& e)
		{
			std::cout << "Can't create new form: " << e.what() << std::endl;
			delete a;
		}
	}
}
