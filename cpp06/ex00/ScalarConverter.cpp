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
void	fromChar( std::string str) {
	int i;
	if (str.length() == 1) { i = 0; }
	else { i = 1; }

	char	num = static_cast<unsigned char>(str[i]);

	std::cout << "char: " << num << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

/*	******************** Converter Int ***********************	*/
void	fromInt( std::string str) {
	std::stringstream ss(str);
    int num;
    ss >> num;

	if (num < 0 || num > 255)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: " << static_cast<unsigned char>(num) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

/*	******************* Converter Float **********************	*/
void	fromFloat( std::string str) {
	std::stringstream ss(str);

    float num;
    ss >> num;

	if (num < 0. || num > 255.)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: " << static_cast<unsigned char>(num) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (num > 2147483647. || num < -2147483648.)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (str.find(".") >= str.length() - 1 ) {
		std::cout << std::setprecision(1);
		std::cout << "float: "  << std::fixed << num << "f" << std::endl;
		std::cout << "double: " << std::fixed << static_cast<double>(num) << std::endl;
	}
	else {
		std::cout << "float: "  << std::fixed << num << "f" << std::endl;
		std::cout << "double: " << std::fixed << static_cast<double>(num) << std::endl;
	}
}

/*	****************** Converter Double **********************	*/
void	fromDouble( std::string str) {
	std::stringstream ss(str);
    double num;
    ss >> num;

	if (num < 0. || num > 255.)
		std::cout << "char: impossible" << std::endl;
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
		std::cout << "float: "  << std::fixed << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << std::fixed << num << std::endl;
	}
}

/*	*************** Converter Special Floats *****************	*/
void	specialF( std::string str ) {
	float	num;
	if (str == "nanf") { num = std::numeric_limits<double>::quiet_NaN(); }
	else if (str == "-inff") { num = -std::numeric_limits<double>::infinity(); }
	else { num = std::numeric_limits<double>::infinity(); }

	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) <<  num << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

/*	*************** Converter Special Doubles ****************	*/
void	specialD( std::string str ) {
	long double	num;
	if (str == "nan") { num = std::numeric_limits<double>::quiet_NaN(); }
	else if (str == "-inf") { num = -std::numeric_limits<double>::infinity(); }
	else { num = std::numeric_limits<double>::infinity(); }

	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) <<  static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) <<  num << std::endl;
}

/*	*********************** Parsing **************************	*/
void		getType( std::string str ) {
	if ((str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		|| (str[0] == str[2] && (str[0] == '\'' || str[0] == '"') && std::isdigit(str[1]) && str.length() == 3))
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

/*	********************* Main funcion ***********************	*/
void	ScalarConverter::convert( std::string str ) {
	if (str == "nanf"|| str == "-inff" || str == "+inff")
		return specialF(str);
	if (str == "nan" || str == "-inf" || str == "+inf")
		return specialD(str);
	try {
		getType(str);
	}
	catch (std::exception & e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

/*	********************* Exception **************************	*/
const char*	InputNotValableException::what() const throw() {
	return "The input is not valable !";
}