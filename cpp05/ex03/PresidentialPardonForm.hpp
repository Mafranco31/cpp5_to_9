#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <fstream>
# include <ctime>
# include <stdexcept>

class PresidentialPardonForm: public AForm {

	private:
		const std::string	target;
		PresidentialPardonForm();
	public:
	//	Canonical form
		PresidentialPardonForm( const std::string target );
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm& copy);
		PresidentialPardonForm	&operator= ( PresidentialPardonForm& other );

		void	execute(Bureaucrat const & executor) const;
		//AForm *makeForm( std::string form, std::string target ) const;

		const std::string	&getTarget ( void ) const;
};

#endif