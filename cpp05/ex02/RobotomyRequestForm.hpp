#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <fstream>
# include <iomanip>

class RobotomyRequestForm: public AForm {

	private:
		const std::string	target;
		
		RobotomyRequestForm();
	public:
	//	Canonical form
		RobotomyRequestForm( const std::string target );
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm& copy);
		RobotomyRequestForm	&operator= ( RobotomyRequestForm& other );

		void	execute(Bureaucrat const & executor) const;
		const std::string &getTarget( void ) const;
};

#endif