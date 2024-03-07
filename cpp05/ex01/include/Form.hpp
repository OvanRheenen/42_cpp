#ifndef FORM_H
# define FORM_H

# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExe;

public:
	Form();
	Form(const std::string &name, const int gradeSign, const int gradeExe);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExe() const;

	void	beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);

#endif