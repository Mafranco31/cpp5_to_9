#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main( void ) {
    Form    f1("Rule 1", 30, 10);
    Bureaucrat  b1("Carl", 35);
    Bureaucrat  b2("Jose", 25);

    b1.signForm(f1);
    b2.signForm(f1);
    b2.signForm(f1);
    std::cout << f1 << std::endl;
    return (0);
}