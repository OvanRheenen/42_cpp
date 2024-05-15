#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

#include <iostream>
#include <cstdlib>

int main(void)
{
	Base *p = generate();
	Base &r = *p;
	
	identify(r);
	identify(p);
	
	delete p;
}
