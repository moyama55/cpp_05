#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(130)
{
	try
	{
		if (this->_grade > 150)
			throw GradeTooLowException();
		else if (this->_grade < 0)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	try
	{
		if (this->_grade > 150)
			throw GradeTooLowException();
		else if (this->_grade < 0)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur) : _name(bur._name)
{
	*this = bur;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur)
{
	this->_grade = bur._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int		Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::decrease()
{	
	this->_grade++;
	try
	{
		if (this->_grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

void	Bureaucrat::increase()
{
	this->_grade--;
	try
	{
		if (this->_grade <= 0)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& fm)
{
	try
	{
		fm.beSigned(*this);
		std::cout << this->_name << " signed " << fm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << fm.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TooHigh";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "TooLow";
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream& operator<<(std::ostream&os, Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}