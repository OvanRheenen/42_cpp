#ifndef AMATERIANODE_HPP
# define AMATERIANODE_HPP

# include "AMateria.hpp"

class AMNode
{
private:
	AMateria	*_materia;
	AMNode	*_prev;
	AMNode	*_next;
	bool	_delete;

public:
	AMNode();
	AMNode(const AMNode &other);
	AMNode &operator=(const AMNode &other);
	AMNode(AMateria *m, AMNode *prev);
	~AMNode();

	AMNode	*getPrev();
	AMNode	*getNext();
	AMateria	*getMateria();
	bool	getDelete();

	void	setPrev(AMNode *prev);
	void	setNext(AMNode *next);
	void	setMateria(const AMateria &materia);
	void	setDelete(bool toDelete);
};

#endif