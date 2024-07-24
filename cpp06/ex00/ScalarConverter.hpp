#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

class ScalarConverter {

	private:
		ScalarConverter( void );
		~ScalarConverter();
		ScalarConverter( const ScalarConverter& copy);
		ScalarConverter	&operator= ( ScalarConverter& other );

	public:
		static void	convert( std::string str ) ;

};

class InputNotValableException: public std::exception {
	virtual const char *	what() const throw();
};

#endif