#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <list>
# include <exception>
# include <sstream>
# include <ctime>
# include <algorithm>
# include <iomanip>
# include <sys/time.h>

int isPositiveInteger(const std::string& str);

template <typename T>
void mySort( T& m ) {
	int temp;
    typename T::iterator it;
	typename T::iterator prev;
	typename T::iterator j;
    for (it = m.begin(); it != m.end(); ++it)
	{
        temp = *it;
        j = it;
        while (j != m.begin()) {
            prev = j;
            --prev;
            if (*prev > temp) {
                *j = *prev;
                --j;
            }
            else
                break;
        }
        *j = temp;
    }
}

template <typename T>
void fordJohnsonAlgorithm( T& m ) {
    typename T::iterator begin = m.begin();
    typename T::iterator mid = m.begin();
    std::advance(mid, m.size() / 2);
    typename T::iterator end = m.end();
    T left(begin, mid);
    T right(mid, end);
    if (left.size() > 1)
        mySort(left);
    if (right.size() > 1)
        mySort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), m.begin());
}

class NotAPositiveInteger: public std::exception {
	virtual const char *	what() const throw();
};

template <typename T>
void parseInput( T& cont, char ** argv) {
    int num = 0;
    for (size_t i = 0; argv[i]; i++) {
        num = isPositiveInteger(argv[i]);
        if (num == -1)
            throw NotAPositiveInteger();
        cont.push_back(num);
    }
}

#endif