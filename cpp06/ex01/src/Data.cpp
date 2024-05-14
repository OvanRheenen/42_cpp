#include "Data.hpp"

//--Con/destructors-----------------------------------------------------------//

Data::Data() : _someAmount(42) {}

Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	if (this == &other)
		return (*this);

	this->_someAmount = other._someAmount;

	return (*this);
}

Data::~Data() {}
