#include "Form.hpp"
#include <iostream>

//--Con/destructors-----------------------------------------------------------//

Form::Form() : _name("Default"), _signed(false), _gradeSign(MIN_GRADE), _gradeExe(MIN_GRADE) {}

Form::Form(const std::string &name, const int gradeSign, const int gradeExe)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (_gradeSign > MIN_GRADE || _gradeExe > MIN_GRADE)
		throw (Form::GradeTooLowException());
	if (_gradeSign < MAX_GRADE || _gradeExe < MAX_GRADE)
		throw (Form::GradeTooHighException());
}

Form::Form(const Form &other)
	: _name(other._name), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;

	return (*this);
}

Form::~Form() {}

//--Member functions----------------------------------------------------------//

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeSign() const
{
	return (_gradeSign);
}

int Form::getGradeExe() const
{
	return (_gradeExe);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed == true)
	{
		std::cout << _name << " is already signed." << std::endl;
		return;
	}

	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;

	bureaucrat.signForm(*this);

	if (bureaucrat.getGrade() > _gradeSign)
		throw (Form::GradeTooLowException());
}

//--Exceptions----------------------------------------------------------------//

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("out of range: grade too high.");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("out of range: grade too low.");
}

//--Other functions-----------------------------------------------------------//

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
	ostream	<< form.getName() << " is "
			<< (form.getSigned() ? "signed" : "not signed") << ".\n"
			<< "Grade required to sign: " << form.getGradeSign() << ".\n"
			<< "Grade required to execute: " << form.getGradeExe() << ".";

	return (ostream);
}