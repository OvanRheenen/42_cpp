#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string & name, const int grade);
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat &operator=(const Bureaucrat & other);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();
	
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


std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif