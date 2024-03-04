#ifndef FLOOR_H
# define FLOOR_H

# include "AMateria.hpp"

class Floor
{
private:
	AMateria	*_firstNode;
	AMateria	*_lastNode;
	int			_size;

public:
	Floor();
	Floor(const Floor &other);
	Floor *operator=(const Floor &other);
	~Floor();

	void	addNode(AMateria *m);
};

#endif