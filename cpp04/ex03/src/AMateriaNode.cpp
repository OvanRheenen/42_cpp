#include "AMateriaNode.hpp"

//--Con/destructors-----------------------------------------------------------//

AMNode::AMNode() : _materia(nullptr), _prev(nullptr), _next(nullptr), _delete(true) {}

AMNode::AMNode(const AMNode &other)
{
	*this = other;
}

AMNode &AMNode::operator=(const AMNode &other)
{
	_materia = other._materia->clone();
	_prev = other._prev;
	_next = other._next;
	_delete = other._delete;

	return (*this);
}

AMNode::AMNode(AMateria *m, AMNode *prev) : _materia(m), _prev(prev), _next(nullptr), _delete(true) {}

AMNode::~AMNode()
{
	if (_delete && _materia)
		delete _materia;
}


//--Member functions----------------------------------------------------------//

AMNode	*AMNode::getPrev()
{
	return (_prev);
}

AMNode	*AMNode::getNext()
{
	return (_next);
}

AMateria	*AMNode::getMateria()
{
	return (_materia);
}

bool	AMNode::getDelete()
{
	return (_delete);
}

void	AMNode::setPrev(AMNode *prev)
{
	this->_prev = prev;
}

void	AMNode::setNext(AMNode *next)
{
	this->_next = next;
}


void	AMNode::setMateria(const AMateria &materia)
{
	this->_materia = materia.clone();
}

void	AMNode::setDelete(bool toDelete)
{
	this->_delete = toDelete;
}
