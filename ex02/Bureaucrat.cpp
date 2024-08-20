#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

std::string Bureaucrat::getName()
{
	return this->_name;
}

int		Bureaucrat::getGrade()
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

void	Bureaucrat::signForm(Form& fm)
{
	if (fm.getSign() == true)
		std::cout << "bureaucrat sigend form" << std::endl; 
	else
		std::cout << "bureaucrat" << " couldn't sign " << "form" << " because unresolved" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TooHigh";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "TooLow";
}

std::ostream& operator<<(std::ostream&os, Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}