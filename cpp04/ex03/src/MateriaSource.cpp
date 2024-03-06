#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//--Con/destructors-----------------------------------------------------------//

MateriaSource::MateriaSource()
{
	_memory = new AMateria*[4];

	for (int i = 0; i < 4; i++)
		_memory[i] = nullptr;

}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			this->_memory[i] = other._memory[i];
	}

	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i])
			delete _memory[i];
	}

	delete[] _memory;
}

//--Member functions----------------------------------------------------------//

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_memory[i])
		{
			_memory[i] = m;
			return;
		}
	}

	std::cout << "Cannot learn Materia, memory is full." << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i]->getType() == type)
			return (_memory[i]->clone());
	}

	std::cout << "Cannot create Materia, type not found in memory." << std::endl;
	return (nullptr);
}

void	MateriaSource::printMemory()
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i])
			std::cout << i << " " << _memory[i]->getType() << std::endl;
		else
			std::cout << i << " empty" << std::endl;
	}
}
