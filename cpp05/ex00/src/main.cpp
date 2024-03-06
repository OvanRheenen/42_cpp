#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("a", 1);
	Bureaucrat	b("b", 150);
	Bureaucrat	c("c", -1);
	Bureaucrat	d("d", 151);

	a.incrementGrade();
	b.decrementGrade();

	std::cout << "before decrementation: " << a << std::endl;
	a.decrementGrade();
	std::cout << "after decrementation: " << a << std::endl;

	std::cout << "before incrementation: " << b << std::endl;
	b.incrementGrade();
	std::cout << "after incrementation: " << b << std::endl;

	return 0;
}
