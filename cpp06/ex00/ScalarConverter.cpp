#include "ScalarConverter.hpp"

/*	**************** Constructors & Destructor ***************	*/
ScalarConverter::ScalarConverter(void) {
    std::cout << "Default ScalarConverter constructor called" << std::endl;
}
ScalarConverter::ScalarConverter ( const ScalarConverter &copy ) {
	std::cout << "Copy ScalarConverter constructor called" << std::endl;
	(void) copy;
}
ScalarConverter::~ScalarConverter ( void ) {
	std::cout << "Destructor ScalarConverter called" << std::endl;
}
ScalarConverter	&ScalarConverter::operator=( ScalarConverter& other ) {
	std::cout << "Copy assignment operator ScalarConverter called" << std::endl;
	(void) other;
	return *this;
}

/*	********************* Get type ***************************	*/
bool isInteger(const std::string& str) {
    std::stringstream ss(str);
    int intValue;
    ss >> intValue;
    return ss.eof() && !ss.fail();
}
bool isFloat(const std::string& str) {
    std::stringstream ss(str);
    float intValue;
    ss >> intValue;
    return ss.eof() && !ss.fail();
}
bool isDouble(const std::string& str) {
    std::stringstream ss(str);
    double intValue;
    ss >> intValue;
    return ss.eof() && !ss.fail();
}

/*	******************* Converter Char ***********************	*/
void	ScalarConverter::fromChar( std::string str) {
	char	num = static_cast<unsigned char>(str[0]);

	std::cout << "char: " << num << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
}

/*	******************** Converter Int ***********************	*/
void	ScalarConverter::fromInt( std::string str) {
	//int	num = std::stoi(str);
	std::stringstream ss(str);
    int num;
    ss >> num;

	if (num < 0 || num > 255)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: " << static_cast<unsigned char>(num) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

/*	******************* Converter Float **********************	*/
void	ScalarConverter::fromFloat( std::string str) {
	//float	num = std::stof(str);

	std::stringstream ss(str);

    float num;
    ss >> num;

	if (num < 0. || num > 255.)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: " << static_cast<unsigned char>(num) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (num > 2147483647 || num < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	std::cout << std::endl << "str : " << str << std::fixed << std::endl;
	if (str.find(".") >= str.length() - 1 ) {
		std::cout << std::setprecision(1);
		std::cout << "float: "  << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	else {
		std::cout << "float: "  << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	std::cout << "float fonction" << std::endl;
}

/*	****************** Converter Double **********************	*/
void	ScalarConverter::fromDouble( std::string str) {
	//double	num = std::stod(str);
	std::stringstream ss(str);
    double num;
    ss >> num;

	if (num < 0. || num > 255.)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: " << static_cast<unsigned char>(num) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (num > 2147483647 || num < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (str.find('.') >= str.length() - 1) {
		std::cout << std::setprecision(1);
		std::cout << "float: "  << std::fixed << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << std::fixed << num << std::endl;
	}
	else {
		std::cout << std::setprecision(str.length() - str.find('.') - 1);
		std::cout << "float: "   << std::fixed << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << std::fixed << num << std::endl;
	}
	std::cout << "double fonction" << std::endl;
}

/*	*********************** Parsing **************************	*/
void		ScalarConverter::getType( std::string str ) {
	if (str.length() == 1 && std::isprint(str[0]))
		return fromChar(str);
	else if (isInteger(str))
		return fromInt(str);
	else if (str[str.length() - 1] == 'f' && isFloat(str.substr(0, str.length() - 1)))
		return fromFloat(str.substr(0, str.length() - 1));
	else if (isDouble(str))
		return fromDouble(str);
	else
		throw InputNotValableException();
}

void	ScalarConverter::convert( std::string str ) {
	if (str == "nan" || str == "nanf"|| str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
		return special(str);
	try {
		getType(str);
	}
	catch (std::exception & e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

void	ScalarConverter::special( std::string str ) {
	if (str == "nan") { std::cout << "nan: " << static_cast<double>(std::numeric_limits<double>::quiet_NaN()) << std::endl; }
	if (str == "nanf") { std::cout << "nanf: " << std::numeric_limits<float>::quiet_NaN() << std::endl; }
	if (str == "-inf") { std::cout << "-inf: " << -std::numeric_limits<double>::infinity() << std::endl; }
	if (str == "+inf") { std::cout << "+inf: " << std::numeric_limits<double>::infinity() << std::endl; }
	if (str == "-inff") { std::cout << "-inff: " << -std::numeric_limits<float>::infinity() << std::endl; }
	if (str == "+inff") { std::cout << "+inff: " << std::numeric_limits<float>::infinity() << std::endl; }
}

/*	********************* Exception **************************	*/

const char*	ScalarConverter::InputNotValableException::what() const throw() {
	return "The input is not valable !";
}