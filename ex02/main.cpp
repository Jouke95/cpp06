#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	int n = rand() % 3;
	Base *base = NULL;

	if (n == 0) {
		base = new A;
	}
	else if (n == 1) {
		base = new B;
	}
	else if (n == 2) {
		base = new C;
	}
	return base;
}

void identify(Base* p) {
	A* a_ptr = dynamic_cast<A*>(p);
	if (a_ptr != 0) {
		std::cout << "A" << std::endl;
		return;
	}
	B* b_ptr = dynamic_cast<B*>(p);
	if (b_ptr != 0) {
		std::cout << "B" << std::endl;
		return;
	}
	C* c_ptr = dynamic_cast<C*>(p);
	if (c_ptr != 0) {
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}
}

int main(void) {
	srand(time(NULL));

	Base* random = generate();
	std::cout << "Random:\n";
	identify(random);
	identify(*random);

	A a;
	B b;
	C c;

	std::cout << "Should be A B C:\n";
	identify(a);
	identify(b);
	identify(c);

	delete random;
	return 0;
}
