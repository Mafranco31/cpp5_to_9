#include <iostream>
#include "Span.hpp"
#include <unistd.h>
#include <vector>

int main()
{
    Span sp = Span(10);

    sp.addNumber(0);
    sp.addNumber(200);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(100);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::vector<int> input;
    input.assign(32, 100);
    try {
        sp.addVector(input);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    return 0;
}