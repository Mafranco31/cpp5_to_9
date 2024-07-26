#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <exception>
# include <sstream>

class BitcoinExchange {

	private:
		std::map<std::string, float>	data;

		std::map<std::string, float> getMap( void );
		int	validDate( std::string date ) const;
		int	validValue( std::string value ) const;
		
	public:
	//	Canonical form
		BitcoinExchange( void );
		~BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& copy);
		BitcoinExchange	&operator= ( const BitcoinExchange& other );

		void convert( std::string path ) ;

		class ErrorOpeningFileException: public std::exception {
			const char	*what() const throw ();
		};

		class DateNotValidException: public std::exception {
			const char	*what() const throw ();
		};
};

#endif