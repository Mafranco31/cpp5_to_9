#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(), target("default") {}

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
	if (!is_signed)
		throw FormNotSigned();
	if (executor.getGrade() > exec_grade)
		throw Bureaucrat::GradeTooLowException();

	std::cout << "** DRRRRRRR........ **" << std::endl;
	srand(time(NULL));
    if (rand() % 2)
		std::cout << "The robotomy failed." << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
}

std::string RobotomyRequestForm::getTarget( void ) const { return target; }