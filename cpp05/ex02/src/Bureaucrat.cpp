#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

//--Con/destructors-----------------------------------------------------------//

Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
	: _name(name) 
{
	try
	{
		setGrade(grade);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		_grade = MIN_GRADE;
		std::cerr	<< e.what()
					<< "-> grade set to default 150 for " << this->_name
					<< std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		_grade = MIN_GRADE;
		std::cerr	<< e.what()
					<< "-> grade set to default 150 for " << this->_name
					<< std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;

	return (*this);
}

Bureaucrat::~Bureaucrat() {}


//--Member functions----------------------------------------------------------//

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::setGrade(const int grade)
{
	if (grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		setGrade(_grade - 1);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr	<< e.what()
					<< "-> grade kept at 1 for " << this->_name
					<< std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		setGrade(_grade + 1);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr	<< e.what()
					<< "-> grade kept at 150 for " << this->_name
					<< std::endl;
	}
}

void	Bureaucrat::signForm(const AForm &form) const
{
	if (form.getSigned())
		std::cout << getName() << " signed " << form.getName() << "." << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (AForm::FormNotSignedException& e)
	{
		std::cerr	<< _name
					<< " couldn't execute " << form.getName() 
					<< ": " << e.what() << std::endl;
		return;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr	<< _name
					<< " couldn't execute " << form.getName() 
					<< ": " << e.what() << std::endl;
		return;
	}

	std::cout << _name << " executed " << form.getName() << " Successfully." << std::endl;
}

//--Exceptions----------------------------------------------------------------//

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("out of range: grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("out of range: grade too low.");
}

//--Other functions-----------------------------------------------------------//

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream	<< bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return (ostream);
}
