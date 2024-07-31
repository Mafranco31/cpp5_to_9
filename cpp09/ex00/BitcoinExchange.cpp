#include "BitcoinExchange.hpp"

/*	********** Get the data.csv file into data variable **********	*/
std::map<std::string, float> BitcoinExchange::getMap( void ) {
	const char* filename = "data.csv";
	std::map<std::string, float> m;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw ErrorOpeningFileException();
    }

    std::string line;
	size_t	pos;

	std::getline(file, line);
    
	while (std::getline(file, line)) {
		pos = line.find(',');
		std::stringstream ss(line.substr(pos + 1, line.length()));
		float num;
		ss  >> num;

		m.insert( std::pair<std::string, float>(line.substr(0, pos), num));
    }
	/*	************* print map **************	*/
	/*std::map<std::string, float>::iterator	it = data.begin();
	while (it != data.end()) {
		std::cout << it->first << ", " << it->second << std::endl;
		it++;
	}*/

    file.close();
    return m;
}

/*	********** Orthodox Canonical Form **********	*/
BitcoinExchange::BitcoinExchange( void )
{
	try {
    	data = getMap();
	} catch (std::exception & e) {
		throw;
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

/*	******************** Date checking ***********************	*/
int	BitcoinExchange::validDate( std::string date) const {
	if (date.length() != 10) { return 0; }
	for (size_t	i = 0;i < 10;i++) {
		if (!isdigit(date[i]) && i != 4 && i != 7) { return 0; }
	}
	if (date[4] != '-' || date[7] != '-') { return 0; }
	if ((date[5] == '1' && date[6] > '2') || (date[5] == '0' && date[6] == '0') || date[5] > '1') { return 0; }
	if (date[8] > '3' || (date[8] == '3' && date[9] > '1') || (date[8] == '0' && date[9] == '0')) { return 0; }
	return 1;
}

/*	******************** Value checking **********************	*/
int	BitcoinExchange::validValue( std::string value) const {
	size_t	i = 0;
	while (isspace(value[i])) i++;
	if (i ==  value.length()) { 
		std::cout << "Error: not a number." << std::endl;
		return 0;
	}
	int	point = 0;
	if (value[i] == '-') { 
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}
	if (value[i] == '+') { i++; }
	for (;i < value.length();i++) {
		if (!isdigit(value[i]) && value[i] != '.') {
			std::cout << "Error: not a number." << std::endl;
			return 0;
		}
		if (value[i] == '.') {
			if (point == 1) {
				std::cout << "Error: not a number." << std::endl;
				return 0;
			}
			point = 1;
		}
		if (point == 0 && i > 4) {
			std::cout << "Error: too large number." << std::endl;
			return 0;
		}
	}
	return 1;
}

void BitcoinExchange::convert( std::string path ) {
    std::ifstream file(path.c_str());
    if (!file.is_open()) {
        throw ErrorOpeningFileException();
    }

    std::string line;
	size_t		pos;
	std::string	date;
	std::string	value;
	float		f;

	std::getline(file, line);
    while (std::getline(file, line)) {
		if (line.length() == 0)
			continue;
		pos = line.find('|');
		if (pos == std::string::npos || pos < 2 || line.length() - pos <= 1) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		date = line.substr(0, pos -1);
		value = line.substr(pos + 1, line.length());

		if (!validValue(value)) { continue; }

		std::stringstream ss2(value);
		ss2 >> f;

		if (! (f >= 0 && f <= 1000)) {
			std::cout << "Error: too large number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = data.lower_bound(date);
		if (it != data.begin() && it->first != date)
			it--;


		if (validDate(date))
			std::cout << date << " => " << value << " = " << f * it->second << std::endl;
		else
			std::cout << "Error: bad input => " << line << std::endl;
    }
}

const char *BitcoinExchange::ErrorOpeningFileException::what() const throw() {
    return "Error: could not open file.";
}

const char *BitcoinExchange::DateNotValidException::what() const throw() {
    return "Error: could not open file.";
}
