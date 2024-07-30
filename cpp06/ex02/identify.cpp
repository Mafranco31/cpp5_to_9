#include "main.hpp"

void identify(Base* p) {

    if (dynamic_cast<A*>(p))
        std::cout << "Object is of type A." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object is of type B." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object is of type C." << std::endl;
    else
        std::cout << "Object type is not recognized." << std::endl;

}

void identify(Base& p) {
    /*A &a = dynamic_cast<A&>(p);
    B &b = dynamic_cast<B&>(p);
    C &c = dynamic_cast<C&>(p);

    if (a != 0) {
        std::cout << "Object is of type A."<< std::endl;
        return;
    }
    if (b) {
        std::cout << "Object is of type B."<< std::endl;
        return;
    }
    if (c) {
        std::cout << "Object is of type C."<< std::endl;
        return;
    }*/
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Object is of type A."<< std::endl;
        (void)a;
        return ;
    } catch (const std::exception &e) {}

    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Object is of type B."<< std::endl;
        (void)b;
        return ;
    } catch (const std::exception &e) {}

    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Object is of type C."<< std::endl;
        (void)c;
        return ;
    } catch (const std::exception &e) {}
    std::cout << "Object type is not recognized." << std::endl;
}