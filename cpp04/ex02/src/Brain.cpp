#include "Brain.hpp"

//--Con/destructors-----------------------------------------------------------//

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignement operator called." << std::endl;
	
	if (this != &other)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			this->_ideas[i] = other._ideas[i];
	}

	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called." << std::endl;
}
