#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class	WrongCat : public WrongAnimal
{
private:

	Brain	*_brain;

public:

	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat();

	void	makeSound() const;
	void	printMemLocBrain() const;
};

#endif