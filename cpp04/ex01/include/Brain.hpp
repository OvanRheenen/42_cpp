#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define MAX_IDEAS 100

class	Brain
{
private:

	std::string _ideas[MAX_IDEAS];

public:

	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

};

#endif