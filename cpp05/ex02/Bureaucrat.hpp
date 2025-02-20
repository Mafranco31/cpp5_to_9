#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat {

	private:
		const std::string name;
		int	grade;

		Bureaucrat();

	public:
	//	Canonical form
		Bureaucrat( std::string name, int grade );
		virtual ~Bureaucrat();
		Bureaucrat( const Bureaucrat& copy);
		Bureaucrat	&operator= ( Bureaucrat& other );

	//	Member funcions
		void	signForm ( AForm& f) const ;
		void	executeForm(AForm const & form) const ;

	//	Getters
		std::string getName( void ) const;
		int	getGrade( void ) const;

	//	Increment and Decrement the grade
		void	incrementGrade( int num );
		void	decrementGrade( int num );

	//	Exception classes
		class GradeTooLowException: public std::exception {
				virtual const char*	what() const throw();
		};
		class GradeTooHighException: public std::exception {
				virtual const char*	what() const throw();
		};

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & Bureaucrat);

#endif