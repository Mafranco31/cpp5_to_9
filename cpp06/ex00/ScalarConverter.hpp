#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

class ScalarConverter {

	private:

		static void	getType( std::string str );

		static void	fromChar( std::string str );
		static void	fromInt( std::string str );
		static void	fromFloat( std::string str );
		static void	fromDouble( std::string str );

		static void special( std::string str );

		ScalarConverter( void );
		~ScalarConverter();
		ScalarConverter( const ScalarConverter& copy);
		ScalarConverter	&operator= ( ScalarConverter& other );

	public:
		
		static void	convert( std::string str ) ;

		class InputNotValableException: public std::exception {
			virtual const char *	what() const throw();
		};

};

#endif