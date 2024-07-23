#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm ( const std::string target )
	:	AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm& copy ) 
	:	AForm("PresidentialPardonForm", 25, 5), target(copy.target) {
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm ( void ) {
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm& other ) {
	std::cout << "Copy assignment operator PresidentialPardonForm called" << std::endl;
	(void)other;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getStatus())
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string	&PresidentialPardonForm::getTarget ( void ) const { return this->target; }
