#include "RPN.hpp"

void	RPN::parse(std::string str) {
	int	f = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(str[i])) {
			if ((std::isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && f == 0)
				f = 1;
			else
				throw BadStringPassed();
		}
		else
			f = 0;
	}
}

void	RPN::calcul(double nb1, double nb2, char c) {
	double	newNum = 0;

	switch (c) {
		case '+':
			newNum = nb1 + nb2;
			break;
		case '-':
			newNum = nb1 - nb2;
			break;
		case '*':
			newNum = nb1 * nb2;
			break;
		case '/':
			if (nb2 == 0)
				throw DivPerZero();
			newNum = nb1 / nb2;
	}
	if (f_show)
		std::cout << nb1 << " " << c << " " << nb2
			<< " = " << newNum << std::endl;
	st.push(newNum);
}

void	RPN::performCalcul(char c) {
	if (st.empty())
		throw BadRPNForm();
	double	nb2 = st.top();
	st.pop();
	if (st.empty())
		throw BadRPNForm();
	double	nb1 = st.top();
	st.pop();
	calcul(nb1, nb2, c);
}

void	RPN::createList( std::string str ) {
	try {
		parse(str);
	} catch (std::exception & e) {
		throw;
	}
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it) {
		if (!(std::isspace(*it))) {
			if (std::isdigit(*it))
				st.push(static_cast<double>(*it) - 48.);
			else {
				performCalcul(*it);
			}
				
		}
	}
	if (st.size() != 1)
		throw BadRPNForm();
	result = st.top();
}


//	Canonical form

RPN::RPN ( const std::string &str ) {
	f_show = 0;
	try {
		createList(str);
	} catch (std::exception & e) {
		throw;
	}
}

RPN::RPN ( const std::string &str, int f_show ) : f_show(f_show){
	try {
		createList(str);
	} catch (std::exception & e) {
		throw;
	}
}

RPN::RPN ( const RPN &copy ) {
	*this = copy;
}

RPN::~RPN ( void ) {
}

RPN	&RPN::operator=( const RPN& other ) {
	st = other.st;
	result = other.result;
	return *this;
}



//	Getters

double	RPN::getResult() const {return result;}


//	Exceptions

const char*	RPN::BadStringPassed::what() const throw() {
	return "Arg must contain only digits, '+', '-', '/' or '*', separated by a space(s).";
}

const char*	RPN::BadRPNForm::what() const throw() {
	return "Bad RPN Form !";
}

const char*	RPN::DivPerZero::what() const throw() {
	return "Division by 0 is not allowed.";
}