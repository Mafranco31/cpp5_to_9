#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <stdlib.h>

class Span {

	private:
		unsigned int		n;
		std::vector<int>	v;

	public:
	//	Canonical form
		Span( void );
		Span( unsigned int n );
		~Span();
		Span( const Span& copy);
		Span	&operator= ( const Span& other );

	//	Member functions
		void	addNumber( const int i );
		int		shortestSpan( void ) ;
		int		longestSpan( void ) const ;
		void	addVector( std::vector<int> v );
		void	addRandom( unsigned int num, int max);

	//	Getters
		unsigned int	getNmax( void ) const ;
		unsigned int	getSpace( void ) const ;
		std::vector<int>	getVector( void ) const;

	//	Overload operator
		int	&operator[]( size_t index );

	//	Exceptions
		class TooMuchElementsException: public std::exception {
			const char	*what() const throw ();
		};
		class TooMuchElementsAddRandomException: public std::exception {
			const char	*what() const throw ();
		};
		class NotEnoughNumbersException: public std::exception {
			const char	*what() const throw ();
		};
		class IndexOutOfBoundsException: public std::exception {
			const char	*what() const throw ();
		};
};

#endif