#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <list>
# include <stack>

class RPN {

	private:
		RPN( const RPN& copy);
		RPN	&operator= ( const RPN& other );

		void	parse(std::string str);
		void	calcul(double nb1, double nb2, char c);
		void	performCalcul(char c );
		void	createList( std::string str );

		std::list<char>	lst;
		std::stack<double>	st;
		double	result;
		int		f_show;

	public:

		RPN( const std::string & str );
		RPN( const std::string & str, int f_show );
		~RPN();

		double	getResult() const;

		class BadStringPassed: public std::exception {
				virtual const char*	what() const throw();
		};
		class BadRPNForm: public std::exception {
				virtual const char*	what() const throw();
		};
		class DivPerZero: public std::exception {
				virtual const char*	what() const throw();
		};

};

#endif