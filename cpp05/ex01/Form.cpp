#include "Form.hpp"

Form::Form(): sign_grade(0), exec_grade(0) {}

Form::Form ( std::string name, int sign_grade, int exec_grade ) : name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
	std::cout << "Default Form constructor called" << std::endl;
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	is_signed = false;
}

Form::Form ( const Form &copy ) : name(copy.name),  is_signed(copy.is_signed), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade) {
	std::cout << "Copy Form constructor called" << std::endl;
}

Form::~Form ( void ) {
	std::cout << "Destructor Form called" << std::endl;
}

Form	&Form::operator=( Form& other ) {
	std::cout << "Copy assignment operator Form called" << std::endl;
	if (this != &other) {
        this->is_signed = other.is_signed;
    }
	return *this;
}

// Member funcions

void	Form::beSigned( const Bureaucrat& bu) {
	if (is_signed)
		throw FormAlreadySigned();
	if (bu.getGrade() > sign_grade)
		throw Bureaucrat::GradeTooLowException();
	is_signed = true;
}

// Exceptions

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high !";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low !";
}

const char*	Form::FormAlreadySigned::what() const throw() {
	return "Form is already signed !";
}

// Getters
const std::string	&Form::getName( void ) const {
	return name;
}

bool	Form::getStatus( void ) const {
	return is_signed;
}

int	Form::getSignGrade( void ) const {
	return sign_grade;
}

int	Form::getExecGrade( void ) const {
	return exec_grade;
}

// Overload of operator <<
std::ostream& operator<<( std::ostream& out, Form const& Form) {
	out << Form.getName() << " : status : " << Form.getStatus() << ", grade required to sign : " << Form.getSignGrade() << ", grade required to execute : " << Form.getExecGrade() << ".";
	return out;
}