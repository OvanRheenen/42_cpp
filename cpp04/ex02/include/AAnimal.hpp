#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class	AAnimal
{
protected:

	std::string	_type;

	AAnimal();
	AAnimal(const AAnimal &other);

public:

	AAnimal	&operator=(const AAnimal &other);
	virtual ~AAnimal();

	std::string const	&getType() const;
	void				setType(const std::string &type);

	virtual void	makeSound() const = 0;

};

#endif