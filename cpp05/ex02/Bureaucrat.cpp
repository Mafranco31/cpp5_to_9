#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat ( std::string name, int grade ) : name(name), grade(grade) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat ( const Bureaucrat &copy ) : name(copy.name), grade(copy.grade){
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat ( void ) {
	std::cout << "Destructor Bureaucrat called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat& other ) {
	std::cout << "Copy assignment operator Bureaucrat called" << std::endl;
	if (this != &other) {
        this->grade = other.grade;
    }
	return *this;
}

std::string Bureaucrat::getName( void ) const {
	return name;
}
int Bureaucrat::getGrade( void ) const {
	return grade;
}

void Bureaucrat::signForm ( AForm& f) const {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade( int num ) {
	if (grade - num < 1)
		throw GradeTooHighException();
	else if (grade - num > 150)
		throw GradeTooLowException();
	else
		grade -= num;
}

void Bureaucrat::decrementGrade( int num ) {
	if (grade + num > 150)
		throw GradeTooLowException();
	else if (grade + num < 1)
		throw GradeTooHighException();
	else
		grade += num;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade is too high !";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade is too low !";
}

std::ostream& operator<<( std::ostream& out, Bureaucrat const& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}