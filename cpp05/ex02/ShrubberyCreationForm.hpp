#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm {

	private:
		const std::string	target;
		ShrubberyCreationForm();
	public:
	//	Canonical form
		ShrubberyCreationForm( const std::string target );
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm& copy);
		ShrubberyCreationForm	&operator= ( ShrubberyCreationForm& other );

		void	execute(Bureaucrat const & executor) const;

		std::string	getTarget ( void ) const;
};

#endif