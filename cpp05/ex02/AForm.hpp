#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {

	protected:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;

		AForm();
	public:
	//	Canonical form
		AForm( const std::string name, const int sign_grade, const int exec_grade );
		virtual ~AForm();
		AForm( const AForm& copy);
		AForm	&operator= ( AForm& other );

	//	Member funcion
		void		beSigned(const Bureaucrat& bu);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSigned: public std::exception {
				virtual const char*	what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, AForm const & form);

#endif