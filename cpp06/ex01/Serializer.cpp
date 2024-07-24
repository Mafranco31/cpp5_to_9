#include "Serializer.hpp"

Serializer::Serializer ( void ) {
	std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer ( const Serializer &copy ) {
	std::cout << "Copy Serializer constructor called" << std::endl;
	(void)copy;
}

Serializer::~Serializer ( void ) {
	std::cout << "Destructor Serializer called" << std::endl;
}

Serializer	&Serializer::operator=( Serializer& other ) {
	std::cout << "Copy assignment operator Serializer called" << std::endl;
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}