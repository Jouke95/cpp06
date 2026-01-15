#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* result = reinterpret_cast<Data*>(raw);
	return result;
}
