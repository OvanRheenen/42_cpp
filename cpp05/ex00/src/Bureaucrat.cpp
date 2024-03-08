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
		return (*this);
	
	this->_grade = other._grade;

	return (*this);
}

Bureaucrat::~Bureaucrat() {}


//--Member functions----------------------------------------------------------//

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::setGrade(const int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
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
		std::cerr	<< "Exception caught: " << e.what()
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
		std::cerr	<< "Exception caught: " << e.what()
					<< "-> grade kept at 150 for " << this->_name
					<< std::endl;
	}
}

//--Exceptions----------------------------------------------------------------//

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("out of range: too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("out of range: too low.");
}

//--Other functions-----------------------------------------------------------//

std::ostream & operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream	<< bureaucrat.getName()
			<< ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return (ostream);
}
