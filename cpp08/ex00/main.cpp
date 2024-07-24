#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
void    example(T v) {
    std::cout << "Data: ";
    for (size_t i = 0; i < 10; ++i) {
        v.push_back(static_cast<int>(i) + 1);
        std::cout << static_cast<int>(i) + 1 << ", ";
    }
    std::cout << std::endl;
    try {
        std::cout << "Number found: " << easyfind(v, 1) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Number found: " << easyfind(v, 10) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Number found: " << easyfind(v, 11) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main( void ) {
    std::vector<int>    v;
    std::deque<int>     d;
    std::list<int>      l;
    
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