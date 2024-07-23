#include "Intern.hpp"

Intern::Intern ( void ) {
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern ( const Intern &copy ) {
	std::cout << "Copy Intern constructor called" << std::endl;
	(void) copy;
}

Intern::~Intern ( void ) {
	std::cout << "Destructor Intern called" << std::endl;
}

Intern	&Intern::operator=( Intern& other ) {
	std::cout << "Copy assignment operator Intern called" << std::endl;
	(void) other;
	return *this;
}

AForm *Intern::makeFormPP( std::string form, std::string target, AForm *rrf) {
	if (!rrf && form == "Presidential Pardon")
		return  new PresidentialPardonForm(target);
	return rrf;
}

AForm *Intern::makeFormRR( std::string form, std::string target, AForm *rrf) {
	if (!rrf && form == "Robotomy Request")
		return  new RobotomyRequestForm(target);
	return rrf;
}

AForm *Intern::makeFormSC( std::string form, std::string target, AForm *rrf) {
	if (!rrf && form == "Shrubbery Creation")
		return  new ShrubberyCreationForm(target);
	return rrf;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm	*rrf;
	
	rrf = nullptr;
	rrf = makeFormPP( form, target, rrf );
	rrf = makeFormRR( form, target, rrf );
	rrf = makeFormSC( form, target, rrf );
	if (!rrf)
		throw FormDoesntExistException();
	std::cout << "Intern creates " << form << "." << std::endl;
	return rrf;
}

const char*	Intern::FormDoesntExistException::what() const throw() {
	return "Form doesn't exist !";
}
