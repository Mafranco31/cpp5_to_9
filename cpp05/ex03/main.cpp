#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main( void ) {
    Intern  i1;
    AForm* rrf;

    std::cout << std::endl;
    try {
        rrf = i1.makeForm("Shrubbery Creation", "Montain");
        std::cout << *rrf << std::endl;
        std::cout << std::endl;
        delete rrf;
    }
    catch (std::exception & e) {
        std::cout << "Intern failed to create form because " << e.what() << "." << std::endl;
    }

    std::cout << std::endl;
    try {
        rrf = i1.makeForm("Robotomy Request", "Table");
        std::cout << *rrf << std::endl;
        std::cout << std::endl;
        delete rrf;
    }
    catch (std::exception & e) {
        std::cout << "Intern failed to create form because " << e.what() << "." << std::endl;
    }

        std::cout << std::endl;
    try {
        rrf = i1.makeForm("Presidential Pardon", "Chair");
        std::cout << *rrf << std::endl;
        std::cout << std::endl;
        delete rrf;
    }
    catch (std::exception & e) {
        std::cout << "Intern failed to create form because " << e.what() << "." << std::endl;
    }
    try {
        rrf = i1.makeForm("Fake Form", "Table");
        std::cout << *rrf << std::endl;
        std::cout << std::endl;
        delete rrf;
    }
    catch (std::exception & e) {
        std::cout << "Intern failed to create form because " << e.what() << "." << std::endl;
    }
    std::cout << std::endl;

    Bureaucrat  b1("Tom", 34);

    std::cout << std::endl;
    rrf = i1.makeForm("Shrubbery Creation", "Park");

    std::cout << std::endl;
    b1.signForm(*rrf);

    std::cout << std::endl;
    b1.executeForm(*rrf);

    std::cout << std::endl;

    delete rrf;
    return (0);
}