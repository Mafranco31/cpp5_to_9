#include "ScalarConverter.hpp"

int main( int argc, char **argv) {
    if (argc == 2){
        try {
            ScalarConverter::convert(argv[1]);
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << "." << std::endl;
        }
    }
    else
        std::cout << "Converter works as follow:" << std::endl << "\t./convert <value>" << std::endl;
}