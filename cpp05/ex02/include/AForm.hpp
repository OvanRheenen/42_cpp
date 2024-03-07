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

protected:
	AForm();
	AForm(const AForm &other);

public:
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	void checkValidExecution(Bureaucrat const &executer, AForm const &form) const; // checks for conditions, then calls exeForm();
	virtual void execute(Bureaucrat const & executer) const = 0;

	virtual std::string	getName() const;
	virtual bool		getSigned() const;
	virtual int			getGradeSign() const;
	virtual int			getGradeExe() const;

	virtual void	beSigned(Bureaucrat &bureaucrat);
};

#endif