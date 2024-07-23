#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm ( const std::string target )
	:	AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm& copy ) 
	:	AForm("RobotomyRequestForm", 72, 45), target(copy.target) {
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm ( void ) {
	std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm& other ) {
	std::cout << "Copy assignment operator RobotomyRequestForm called" << std::endl;
	(void)other;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getStatus())
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << "** DRRRRRRR........ **" << std::endl;
	srand(time(NULL));
    if (rand() % 2)
		std::cout << "The robotomy failed." << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
}

const std::string	&RobotomyRequestForm::getTarget( void ) const { return this->target; }