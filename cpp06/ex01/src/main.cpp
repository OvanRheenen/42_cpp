#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{
	Data *test = new Data();
	uintptr_t uintTest = Serializer::serialize(test);

	std::cout 	<< "Address: " << std::setw(14) << test << "\n"
				<< "serialized: " << std::setw(10) << Serializer::serialize(test) << "\n"
				<< "deserialized: " << std::setw(1) << Serializer::deserialize(uintTest)
				<< std::endl;
	return (0);
}
