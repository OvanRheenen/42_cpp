#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class	WrongAnimal
{
protected:

	std::string _type;

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal();

	void				setType(const std::string &type);
	std::string const &	getType() const;

	void	makeSound() const;
};

#endif