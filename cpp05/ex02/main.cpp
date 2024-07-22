#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    ShrubberyCreationForm    f1("Park");
    Bureaucrat  b1("Carl", 150);
    Bureaucrat  b2("Jose", 5);
    std::cout << "** Shrubbery Creation Form **" << std::endl;

    b2.signForm(f1);
    b1.executeForm(f1);
    b2.executeForm(f1);
    std::cout << f1 << std::endl;

    std::cout << std::endl;
    std::cout << "** Robotomy Request Form **" << std::endl;

    RobotomyRequestForm f2("Mark");
    b1.signForm(f2);
    b2.signForm(f2);
    b2.executeForm(f2);
    std::cout << f2 << std::endl;

    std::cout << std::endl;
    std::cout << "** Presidential Pardon Form **" << std::endl;
    PresidentialPardonForm f3("Dyson");
    b1.signForm(f3);
    b2.signForm(f3);
    b2.executeForm(f3);
    std::cout << f3 << std::endl;

    std::cout << std::endl;
    return (0);
}