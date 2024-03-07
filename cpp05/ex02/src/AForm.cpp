#include "AForm.hpp"
#include "Bureaucrat.hpp"

//--Con/destructors-----------------------------------------------------------//

AForm::AForm() : _name("Default"), _signed(false), _gradeSign(MIN_GRADE), _gradeExe(MIN_GRADE) {}

AForm::AForm(const AForm &other)
	: _name(other._name), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);

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

//--Exceptions----------------------------------------------------------------//


//--Other functions-----------------------------------------------------------//
