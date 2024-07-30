#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

void    convert( std::string argv)
{
    std::cout << "*** converting " << argv << " ***" << std::endl << std::endl;
    try {
        ScalarConverter::convert(argv);
    }
    catch (std::exception & e) {
        std::cout << "Error: " << e.what() << "." << std::endl;
    }
    std::cout << std::endl;
}

int main( int argc, char **argv) {
    if (argc == 1) {
        convert("42");
        convert("0");
        convert("-0");
        convert("-2147483648");
        convert("2147483648");
        convert("42f");
        convert("42.");
        convert("42.0");
        convert("2341490210384902834");
        convert("120934801924123948f");
        convert("42.424242");
        convert("azr");
        convert("213g34");
        convert("nan");
        convert("nanf");
        convert("-inf");
        convert("-inff");
        convert("+inf");
        convert("+inff");
    }
    else {
        for (int i = 0; i < argc - 1; i++) {
            convert(argv[i + 1]);
        }
    }
}