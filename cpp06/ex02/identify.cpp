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
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Object is of type A."<< std::endl;
        (void)a;
        return ;
    } catch (const std::bad_cast& ) {}

    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Object is of type B."<< std::endl;
        (void)b;
        return ;
    } catch (const std::bad_cast& ) {}

    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Object is of type C."<< std::endl;
        (void)c;
        return ;
    } catch (const std::bad_cast& ) {}
    std::cout << "Object type is not recognized." << std::endl;
}