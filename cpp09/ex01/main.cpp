#include <iostream>
#include <string>
#include "RPN.hpp"

int main( int argc, char **argv ) {
    if (argc != 2 || static_cast<std::string>(argv[1]).length() == 0) {
        std::cout << "RPN needs a polish mathematical expression as argument." << std::endl;
        return (0);
    }
    try {
        RPN rpn(argv[1], 1);
        std::cout << rpn.getResult() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
