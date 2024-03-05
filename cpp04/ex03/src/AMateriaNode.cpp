#include "AMateriaNode.hpp"

//--Con/destructors-----------------------------------------------------------//

AMNode::AMNode()
	: _materia(nullptr), _prev(nullptr), _next(nullptr), _delete(true)
{
	std::cout << "AMNode default constructor called." << std::endl;
}

AMNode::AMNode(const AMNode &other)
{
	std::cout << "AMNode copy constructor called." << std::endl;

	*this = other;
}

AMNode &AMNode::operator=(const AMNode &other)
{
	std::cout << "AMNode copy assignment operator called." << std::endl;

	_materia = other._materia->clone();
	_prev = other._prev;
	_next = other._next;
	_delete = other._delete;

	return (*this);
}

AMNode::AMNode(AMateria *m, AMNode *prev)
	: _materia(m), _prev(prev), _next(nullptr), _delete(true)
{
	std::cout << "AMNode add node constructor called." << std::endl;
}

AMNode::~AMNode()
{
	std::cout << "AMNode default destructor called." << std::endl;

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
