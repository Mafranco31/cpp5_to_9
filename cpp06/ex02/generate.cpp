#include "main.hpp"
#include <cstdlib>

Base * generate(void) {
	srand(time(NULL));
	int num = rand() % 3;

	switch (num) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
        default:
            return NULL;
	}
}