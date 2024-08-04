#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(130)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	try
	{
		if (this->_grade > 150)
			throw GradeTooLowException();
		else if (this->_grade <= 0)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur)
{
	*this = bur;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur)
{
	this->_name = bur._name;
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

std::ostream& operator<<(std::ostream&os, Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}