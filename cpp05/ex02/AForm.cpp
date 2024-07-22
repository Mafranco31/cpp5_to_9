#include "AForm.hpp"

AForm::AForm(): sign_grade(0), exec_grade(0) {}

AForm::AForm ( const std::string name, const int sign_grade, const int exec_grade )
	:
		name(name),
		sign_grade(sign_grade),
		exec_grade(exec_grade) {

	std::cout << "Default Form constructor called" << std::endl;
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	is_signed = false;
}

AForm::AForm ( const AForm &copy )
	:	name(copy.name),
		is_signed(copy.is_signed),
		sign_grade(copy.sign_grade),
		exec_grade(copy.exec_grade) {

	std::cout << "Copy Form constructor called" << std::endl;
}

AForm::~AForm ( void ) {
	std::cout << "Destructor Form called" << std::endl;
}

AForm	&AForm::operator=( AForm& other ) {
	std::cout << "Copy assignment operator Form called" << std::endl;
	if (this != &other) {
        this->is_signed = other.is_signed;
    }
	return *this;
}

// Member funcions

void	AForm::beSigned( const Bureaucrat& bu) {
	if (is_signed)
		throw FormAlreadySigned();
	if (bu.getGrade() > sign_grade)
		throw Bureaucrat::GradeTooLowException();
	is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const { (void)executor; }

// Exceptions

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high !";
}
const char*	AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low !";
}
const char*	AForm::FormAlreadySigned::what() const throw() {
	return "Form is already signed !";
}
const char*	AForm::FormNotSigned::what() const throw() {
	return "Form is not signed !";
}

// Getters
std::string	AForm::getName( void ) const {
	return name;
}
bool	AForm::getStatus( void ) const {
	return is_signed;
}
int	AForm::getSignGrade( void ) const {
	return sign_grade;
}
int	AForm::getExecGrade( void ) const {
	return exec_grade;
}

// Overload of operator <<
std::ostream& operator<<( std::ostream& out, AForm const& form) {
	out << form.getName() << " : status : " << form.getStatus()
	<< ", grade required to sign : " << form.getSignGrade()
	<< ", grade required to execute : " << form.getExecGrade() << ".";
	return out;
}