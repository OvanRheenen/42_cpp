#include "Floor.hpp"
#include "AMateriaNode.hpp"

//--Con/destructors-----------------------------------------------------------//

int	Floor::_size = 0;

Floor::Floor() : _firstNode(nullptr), _lastNode(nullptr) {}

Floor::Floor(const Floor &other)
{
	*this = other;
}

Floor &Floor::operator=(const Floor &other)
{
	AMNode	*currentNode = other._firstNode;
	AMNode* copiedNode = nullptr;
	AMNode* previousNode = nullptr;

	while (currentNode)
	{
		AMateria *clonedMateria = currentNode->getMateria()->clone();
		copiedNode = new AMNode(clonedMateria, nullptr);

		if (previousNode)
			previousNode->setNext(copiedNode);
		else
			_firstNode = copiedNode;

		previousNode = copiedNode;
    	currentNode = currentNode->getNext();
	}

	_lastNode = copiedNode;
	_size = other._size;

	return (*this);
}

Floor::~Floor()
{
	while (_firstNode != nullptr)
	{
		AMNode *next = _firstNode->getNext();
		delete _firstNode;
		_size--;
		_firstNode = next;
	}
}

//--Member functions----------------------------------------------------------//

void	Floor::addNode(AMateria *m)
{
	_lastNode = new AMNode(m, _lastNode);

	m->setStatus(ON_THE_FLOOR);

	_size++;

	if (!_firstNode)
		_firstNode = _lastNode;
	else
		_lastNode->getPrev()->setNext(_lastNode);
}

void	Floor::removeFromFloor(AMateria *m)
{
	AMNode	*tmp;

	tmp = this->_firstNode;
	
	while (tmp && tmp->getMateria() != m)
		tmp = tmp->getNext();

	if (tmp)
	{
		if (tmp->getPrev())
			tmp->getPrev()->setNext(tmp->getNext());
		if (tmp->getNext())
			tmp->getNext()->setPrev(tmp->getPrev());
		if (this->_firstNode == tmp)
			this->_firstNode = tmp->getNext();
		if (this->_lastNode == tmp)
			this->_lastNode = tmp->getPrev();
		tmp->setDelete(false);
		delete tmp;
	}
}

int	Floor::getSize() const
{
	return (_size);
}
