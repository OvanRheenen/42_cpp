#include "Bureaucrat.hpp"

//--Con/destructors-----------------------------------------------------------//

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string & name, const int grade)
	: _name(name) 
{
	_grade = grade; // exception catch
}

Bureaucrat::Bureaucrat(const Bureaucrat & other)
	: _name(other._name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this != &other)
		this->_grade = other._grade;
		// name can't be copied I guess

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

void	Bureaucrat::incrementGrade()
{
	_grade--; // catch exception
}

void	Bureaucrat::decrementGrade()
{
	_grade++; // catch exception
}


//--Other functions-----------------------------------------------------------//

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream	<< bureaucrat.getName()
			<< ", bureaucrat grade " << bureaucrat.getGrade()
			<< "." << std::endl;

	return (ostream);
}
