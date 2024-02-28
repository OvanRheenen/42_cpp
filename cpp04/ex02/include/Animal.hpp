#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
protected:

	std::string	_type;

	Animal();
	Animal(const Animal &other);

public:

	Animal	&operator=(const Animal &other);
	virtual ~Animal();

	std::string const	&getType() const;
	void				setType(const std::string &type);

	virtual void	makeSound() const;

};

#endif