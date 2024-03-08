#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExe;
	const std::string	_target;

protected:
	AForm();
	AForm(const std::string &name, const int gradeToSign, const int gradeToExe, const std::string &target);
	AForm(const AForm &other);

public:
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	// getters and setters
	virtual std::string	getName() const;
	virtual bool		getSigned() const;
	virtual int			getGradeSign() const;
	virtual int			getGradeExe() const;
	virtual std::string getTarget() const;

	virtual void setSigned(const bool isSigned);

	// other member functions
	virtual void	beSigned(Bureaucrat &bureaucrat);
	void			checkValidExecution(Bureaucrat const &executer, AForm const &form) const; // checks for conditions, then calls exeForm();
	virtual void	execute(Bureaucrat const & executer) const = 0;

	// exceptions
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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};
};

std::ostream &operator<<(std::ostream &ostream, const AForm &form);

#endif