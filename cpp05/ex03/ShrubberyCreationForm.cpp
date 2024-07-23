#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm ( const std::string target )
	:	AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm& copy ) 
	:	AForm("ShrubberyCreationForm", 145, 137), target(copy.target) {
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm& other ) {
	std::cout << "Copy assignment operator ShrubberyCreationForm called" << std::endl;
	(void)other;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();

	std::ofstream outFile(target + "_shrubbery");
	if (outFile.is_open()) {
		outFile << "    *       *       *    " << std::endl
				<< "   ***     ***     ***   " << std::endl
				<< "  *****   *****   *****  " << std::endl
				<< " ******* ******* ******* " << std::endl
				<< "*************************" << std::endl
				<< "    |       |       |    " << std::endl;
		outFile.close();
    }
	else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

const std::string	&ShrubberyCreationForm::getTarget ( void ) const { return this->target; }
