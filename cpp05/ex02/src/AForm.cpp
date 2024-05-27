#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

//--Con/destructors-----------------------------------------------------------//

AForm::AForm() : _name("Default"), _signed(false), _gradeSign(MIN_GRADE), _gradeExe(MIN_GRADE) {}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExe, const std::string &target)
	: _name(name), _signed(false), _gradeSign(gradeToSign), _gradeExe(gradeToExe), _target(target) {}


AForm::AForm(const AForm &other)
	: _name(other._name), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		_signed = other._signed;

	return (*this);
}

AForm::~AForm() {}


//--Member functions----------------------------------------------------------//

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeSign() const
{
	return (_gradeSign);
}

int AForm::getGradeExe() const
{
	return (_gradeExe);
}

std::string AForm::getTarget() const
{
	return (_target);
}

void	AForm::setSigned(const bool isSigned)
{
	_signed = isSigned;
}

void AForm::checkValidExecution(Bureaucrat const &executer, AForm const &form) const
{
	if (form.getSigned() == false)
		throw (AForm::FormNotSignedException());
	if (executer.getGrade() > form.getGradeExe())
		throw (Bureaucrat::GradeTooLowException());
}

void AForm::beSigned(Bureaucrat &bureaucrat)
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
		throw (Bureaucrat::GradeTooLowException());
}

//--Exceptions----------------------------------------------------------------//

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("out of range: grade too high.");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("out of range: grade too low.");
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return ("form not signed.");
}

//--Other functions-----------------------------------------------------------//

std::ostream &operator<<(std::ostream &ostream, const AForm &form)
{
	ostream	<< form.getName() << " is "
			<< (form.getSigned() ? "signed" : "not signed") << ".\n"
			<< "Grade required to sign: " << form.getGradeSign() << ".\n"
			<< "Grade required to execute: " << form.getGradeExe() << ".";

	return (ostream);
}
