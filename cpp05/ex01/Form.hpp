#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

	private:
		const std::string	name;
		bool	is_signed;
		const int	sign_grade;
		const int	exec_grade;

		Form();
	public:
	//	Canonical form
		Form( std::string name, int sign_grade, int exec_grade );
		virtual ~Form();
		Form( const Form& copy);
		Form	&operator= ( Form& other );

	//	Member funcion
		void		beSigned(const Bureaucrat& bu);

	//	Getters
		std::string	getName( void ) const ;
		bool		getStatus( void ) const ;
		int			getSignGrade( void ) const ;
		int			getExecGrade( void ) const ;

	//	Exceptions
		class GradeTooLowException: public std::exception {
				virtual const char*	what() const throw();
		};
		class GradeTooHighException: public std::exception {
				virtual const char*	what() const throw();
		};
		class FormAlreadySigned: public std::exception {
				virtual const char*	what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Form const & Form);

#endif