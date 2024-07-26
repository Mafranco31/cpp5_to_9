#include "BitcoinExchange.hpp"

std::multimap<std::string, std::string> BitcoinExchange::getMap( void ) {
	const char* filename = "data.csv";
	std::multimap<std::string, std::string> m;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw ErrorOpeningFileException();
    }

    std::string line;
	size_t	pos;

	std::getline(file, line);
    while (std::getline(file, line)) {
		pos = line.find(',');
		std::string num;
		std::stringstream ss(line.substr(pos + 1, line.length()));
		ss  >> num;
		
		m.insert( std::pair<std::string, std::string>(line.substr(0, pos), num));
    }
	/*while (std::getline(file, line)) {
		pos = line.find(',');
		std::stringstream ss(line.substr(pos + 1, line.length()));
		double num;
		ss  >> num;

		m.insert( std::pair<std::string, double>(line.substr(0, pos), num));
    }*/
	/*	************* print map **************	*/
	/*std::map<std::string, float>::iterator	it = data.begin();
	while (it != data.end()) {
		std::cout << it->first << ", " << it->second << std::endl;
		it++;
	}*/

    file.close();
    return m;
}

BitcoinExchange::BitcoinExchange( void )
{
	try {
    	data = getMap();
	} catch (std::exception & e) {
		throw e;
	}
	std::multimap<std::string, std::string>::iterator	it = data.begin();
	while (it != data.end()) {
		std::cout << it->first << ", " << it->second << std::endl;
		it++;
	}
	std::cout << "Default BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange ( const BitcoinExchange &copy ) : data(copy.data) {
	std::cout << "Copy BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange ( void ) {
	std::cout << "Destructor BitcoinExchange called" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange& other ) {
	std::cout << "Copy assignment operator BitcoinExchange called" << std::endl;
	if (this != &other)
		data = other.data;
	return *this;
}

void BitcoinExchange::convert( std::string path ) const {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw ErrorOpeningFileException();
    }

    std::string line;
	size_t	pos;

	std::getline(file, line);
    while (std::getline(file, line)) {
		pos = line.find('|');
		double f;
		std::string date;
		std::stringstream ss(line.substr(0, pos -1));
		ss  >> date;
		if (date >= "2009-01-02") {
			std::stringstream ss(data.lower_bound(date)->second);
			ss  >> f;
			std::cout << date << " => " << std::fixed << std::setprecision(2) << f << std::endl;
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
    }
}

const char *BitcoinExchange::ErrorOpeningFileException::what() const throw() {
    return "Error: could not open file.";
}
