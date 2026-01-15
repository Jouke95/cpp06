#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int main(void) {
	Data data = {42, "hello"};

	Data *ptr = &data;
	std::cout << ptr << std::endl;

	uintptr_t address = Serializer::serialize(&data);
	std::cout << address << std::endl;
	
	ptr = Serializer::deserialize(address);
	std::cout << ptr << std::endl;

	std::cout << ptr->number << " and " << ptr->str << std::endl;

	return 0;
}
