#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{ // given tests
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		delete j;
		delete i;
	}
	{ // array test
		const int size = 100;
		AAnimal* animals[size];

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
	}
	// { // AAnimal class cannot be instantiated test, does not compile
	// 	const AAnimal* a = new AAnimal();
	// 	const AAnimal* b = new AAnimal();
	// }
}
