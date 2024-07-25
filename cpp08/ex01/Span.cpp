#include "Span.hpp"

Span::Span ( void ) : n(0) {}

Span::Span ( unsigned int n ) : n(n) {
	std::cout << "Default Span constructor called" << std::endl;
}

Span::Span ( const Span &copy ) : n(copy.n), v(copy.v) {
	std::cout << "Copy Span constructor called" << std::endl;
}

Span::~Span ( void ) {
	std::cout << "Destructor Span called" << std::endl;
}

Span	&Span::operator=( const Span& other ) {
	std::cout << "Copy assignment operator Span called" << std::endl;
	if (this == &other)
		return *this;
	n = other.n;
	v = other.v;
	return *this;
}

void Span::addNumber( const int number) {
	if (static_cast<unsigned int>(v.size()) >= n)
		throw TooMuchElementsException();
	
	std::vector<int>::iterator	it = v.begin();
	while (it < v.end() && *it < number) {
		it++;
	}
	v.insert(it, number);
	std::cout << "Number: " << number << " added !" << std::endl;
}

int Span::shortestSpan(void) const {
	if (v.size() < 2)
		throw NotEnoughNumbersException();
	int	shortest = v[1] - v[0];
	for (size_t i = 2; i < v.size(); i++ ) {
		if (v[i] - v[i - 1] < shortest) {
			shortest = v[i] - v[i - 1];
		}
	}
    return shortest;
}

int Span::longestSpan(void) const {
	if (v.size() < 2)
		throw NotEnoughNumbersException();
    return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

void Span::addVector(std::vector<int> vec) {
	if (vec.size() == 0)
		return ;
	size_t	i = 0;
	for (; v.size() < n && i < vec.size(); i++) {
		this->addNumber(vec.at(i));
	}
	if (i < vec.size()) 
		throw TooMuchElementsException();
}

int &Span::operator[](size_t index) {
    if (index >= v.size())
		throw IndexOutOfBoundsException();
	return v.at(index);
}

const char *Span::TooMuchElementsException::what() const throw() {
    return "There is not enough space for more numbers !";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "There is not enough numbers to get a range !";
}

const char *Span::IndexOutOfBoundsException::what() const throw() {
    return "Index is out of bounds !";
}
