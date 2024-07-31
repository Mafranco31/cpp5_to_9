#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

/*  *** fonction with void return   *** */
/*template <typename T>
void    example(T &v) {
    int num;
    std::cout << "Data: ";
    for (size_t i = 0; i < 10; ++i) {
        num = rand() % 10;
        v.push_back(num);
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    try {
        std::cout << "Finding number: " << 2 << " ....." << std::endl;
        easyfind(v, 2);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Finding number: " << 5 << " ....." << std::endl;
        easyfind(v, 5);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Finding number: " << 7 << " ....." << std::endl;
        easyfind(v, 7);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Finding number: " << 9 << " ....." << std::endl;
        easyfind(v, 9);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}*/

/*  *** fonction with iterator  *** */
template <typename T>
void    example(T &v) {
    int num;
    std::cout << "Data: ";
    for (size_t i = 0; i < 10; ++i) {
        num = rand() % 10;
        v.push_back(num);
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    typename T::iterator it;
    try {
        it = easyfind(v, 2);
        std::cout << "Number: " << *it << ": found at position " << std::distance(v.begin(), it) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error:  2: " << e.what() << std::endl;
    }
    try {
        it = easyfind(v, 5);
        std::cout << "Number: " << *it << ": found at position " << std::distance(v.begin(), it) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error:  5: " << e.what() << std::endl;
    }
    try {
        it = easyfind(v, 7);
        std::cout << "Number: " << *it << ": found at position " << std::distance(v.begin(), it) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error:  7: " << e.what() << std::endl;
    }
    try {
        it = easyfind(v, 9);
        std::cout << "Number: " << *it << ": found at position " << std::distance(v.begin(), it) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error:  9: " << e.what() << std::endl;
    }
}

int main( void ) {
    std::vector<int>    v;
    std::deque<int>     d;
    std::list<int>      l;
    
    srand(time(NULL));
    std::cout << "********** Vector **********" << std::endl;
    example(v);
    std::cout << std::endl;

    std::cout << "********** Deque **********" << std::endl;
    example(d);
    std::cout << std::endl;

    std::cout << "********** List **********" << std::endl;
    example(l);
    std::cout << std::endl;

    return (0);
}