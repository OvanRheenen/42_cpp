#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//--Con/destructors-----------------------------------------------------------//

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default destructor called." << std::endl;
	
	_memory = new AMateria*[4];

	for (int i = 0; i < 4; i++)
		_memory[i] = nullptr;

}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			this->_memory[i] = other._memory[i];
	}

	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called." << std::endl;
	
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
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i]->getType() == type)
			return (_memory[i]->clone());
	}
	return (0);
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
