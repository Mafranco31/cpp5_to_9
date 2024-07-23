#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern {

	private:
		AForm *makeFormPP( std::string form, std::string target, AForm *rrf);
		AForm *makeFormRR( std::string form, std::string target, AForm *rrf);
		AForm *makeFormSC( std::string form, std::string target, AForm *rrf);

	public:
	//	Canonical form
		Intern( void );
		~Intern();
		Intern( const Intern& copy);
		Intern	&operator= ( Intern& other );

		AForm *makeForm( std::string form, std::string target );

		class FormDoesntExistException: public std::exception {
				virtual const char*	what() const throw();
		};
};

#endif