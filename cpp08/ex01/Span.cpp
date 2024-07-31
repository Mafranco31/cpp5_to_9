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

void	Span::addNumber(int num) {
	if (this->v.size() >= this->n)
		throw Span::TooMuchElementsException();
	this->v.push_back(num);
}


int		Span::shortestSpan(void) {
	if (this->v.size() <= 1)
		throw Span::NotEnoughNumbersException();

	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return (shortest);
}

int Span::longestSpan(void) const {
	if (v.size() < 2)
		throw NotEnoughNumbersException();
    return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

void	Span::addRandom( unsigned int num, int max) {
	if (num > getSpace())
		throw TooMuchElementsAddRandomException();
	
	int	number;
	std::vector<int>::iterator	it;
	for (unsigned int i = 0; i < num; i++) {
		it = v.begin();
		number = rand() % max;
		v.insert(it, number);
	}
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

unsigned int	Span::getNmax( void ) const { return n; }

unsigned int	Span::getSpace( void ) const {
	return (this->n - static_cast<unsigned int>(v.size()));
}

std::vector<int>	Span::getVector( void ) const { return v;}

int &Span::operator[](size_t index) {
    if (index >= v.size())
		throw IndexOutOfBoundsException();
	return v.at(index);
}

const char *Span::TooMuchElementsException::what() const throw() {
    return "There is not enough space for more numbers !";
}

const char *Span::TooMuchElementsAddRandomException::what() const throw() {
    return "There is not enough space for all those numbers !";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "There is not enough numbers to get a range !";
}

const char *Span::IndexOutOfBoundsException::what() const throw() {
    return "Index is out of bounds !";
}
