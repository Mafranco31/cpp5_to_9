# include "main.hpp"

int main( void ) {
    Base *b = generate();

    identify(b);
    identify(*b);

    delete b;
}