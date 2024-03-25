#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{ // given tests
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}
	{ // array test
		const int size = 100;
		Animal* animals[size];

		for (int i = 0; i < size / 2; i++)
		{
			animals[i] = new Dog();
		}

		for (int i = size / 2; i < size; i++)
		{
			animals[i] = new Cat();
		}
		
		for (int i = 0; i < size; i++)
		{
			delete animals[i];
		}
	}
	{ // deep copy tests
		Cat	a;
		Cat	b(a);

		std::cout << std::endl << "Deep copy:" << std::endl;
		a.printMemLocBrain();
		b.printMemLocBrain();

		// WrongCat c;
		// WrongCat d(c);

		// std::cout << std::endl << "Shallow copy (will give a double free error):" << std::endl;
		// c.printMemLocBrain();
		// d.printMemLocBrain();
	}
}
