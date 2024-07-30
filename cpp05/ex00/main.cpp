#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main( void ) {
    try {
        Bureaucrat sarah("Sarah", 40);
        std::cout << sarah;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat etienne("Etienne", 0);
        std::cout << etienne;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat thomas("Thomas", 151);
        std::cout << thomas;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat josh("Josh", 40);
        josh.decrementGrade(11123);
        std::cout << josh;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat tom("Tom", 40);
        tom.incrementGrade(900);
        std::cout << tom;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat cyrille("Cyrille", 40);
        cyrille.decrementGrade(-50);
        std::cout << cyrille;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat mathieu("Mathieu", 110);
        mathieu.decrementGrade(40);
        std::cout << mathieu;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat nicolas("Nicolas", 40);
        nicolas.incrementGrade(39);
        std::cout << nicolas;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    //std::cout << josh << std::endl;
    return (0);
}