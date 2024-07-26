#include "BitcoinExchange.hpp"
#include <iostream>

int	main( int argc, char **argv ) {
	(void)argc;
	if (argc != 2)
		return 0;
	try {
		BitcoinExchange bt;
		std::cout << std::endl;
		bt.convert(argv[1]);
		std::cout << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}