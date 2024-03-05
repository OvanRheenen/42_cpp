#ifndef FLOOR_H
# define FLOOR_H

# include "AMateria.hpp"
# include "AMateriaNode.hpp"

class Floor
{
private:
	AMNode	*_firstNode;
	AMNode	*_lastNode;
	static int	_size;

public:
	Floor();
	Floor(const Floor &other);
	Floor &operator=(const Floor &other);
	~Floor();

	void	addNode(AMateria *m);
	void	removeFromFloor(AMateria *m);
	int	getSize() const;
};

#endif