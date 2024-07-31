#include <iostream>
#include "Span.hpp"
#include <unistd.h>
#include <vector>
#include <cstdlib>

int main()
{
    Span sp = Span(10);

    srand(time(NULL));
    std::cout << std::endl << "We have created a Span class with a space of " << sp.getNmax() << std::endl;
    for (int i = 0;i < 5;i++) {
        sp.addNumber(rand() % 100);
    }
    std::cout << "Space remaining: " << sp.getSpace() << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::vector<int> input;
    std::cout << std::endl << "trying to put 32 times 100 inside the Span class...." << std::endl;
    input.assign(32, 100);
    try {
        sp.addVector(input);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl << std::endl;

    Span sp2(10000);

    try {
        std::cout << "Trying to put 10000 random values inside new Span" << std::endl;
        sp2.addRandom(10000, 100000000);
        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    // To show the 99999 numbers
    /*for (int i = 0; i < 10000;i++) {
        std::cout << sp2.getVector()[i] << std::endl;
    }
    std::cout << "Finished" << std::endl;*/
    try {
        std::cout << "Trying to put a last number inside the Span that is full" << std::endl;
        sp2.addNumber(0);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}