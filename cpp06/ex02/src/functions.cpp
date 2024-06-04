#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

enum e_class
{
	ACLASS,
	BCLASS,
	CCLASS
};

Base *generate(void)
{
	srand(time(nullptr));
	switch (rand() % 3)
	{
		case ACLASS:
			std::cout << "A class created" << std::endl;
			return(new A());
		case BCLASS:
			std::cout << "B class created" << std::endl;
			return(new B());
		case CCLASS:
			std::cout << "C class created" << std::endl;
			return(new C());
	}
	return (nullptr);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "class is of type A" << std::endl;
	else if (b)
		std::cout << "class is of type B" << std::endl;
	else if (c)
		std::cout << "class is of type C" << std::endl;
	else
		std::cout << "class is not of type A, B or C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "class is of type A" << std::endl;
		(void)a;
		return;
	}
	catch(const std::bad_cast &e)
	{
		(void)e;
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "class is of type B" << std::endl;
		(void)b;
		return;
	}
	catch(const std::bad_cast &e)
	{
		(void)e;
	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "class is of type C" << std::endl;
		(void)c;
		return;
	}
	catch(const std::bad_cast &e)
	{
		(void)e;
	}
}
