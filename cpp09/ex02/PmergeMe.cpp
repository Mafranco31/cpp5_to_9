#include "PmergeMe.hpp"

int isPositiveInteger(const std::string& str) {
    if (str[0] == '-')
        return -1;
    std::stringstream ss(str);
    int intValue;
    ss >> intValue;
    if (!ss.eof() || ss.fail())
        return -1;
    return intValue;
}

const char *	NotAPositiveInteger::what() const throw() {
		return "This program accept only positive integers as arguments.";
}