#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name_("Dirty"), sign_(false), canBeSign_(30), canBeExec_(50)
{
	try
	{
		if (this->canBeSign_ > 150 || this->canBeExec_ > 150)
			throw GradeTooLowException();
		else if (this->canBeSign_ <= 0 || this->canBeExec_ <= 0)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Form::Form(std::string name, int beSign, int beExec) : name_(name), canBeSign_(beSign), canBeExec_(beExec)
{
	this->sign_ = false;
	try
	{
		if (this->canBeSign_ > 150 || this->canBeExec_ > 150)
			throw GradeTooLowException();
		else if (this->canBeSign_ <= 0 || this->canBeExec_ <= 0)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	
}

Form::Form(const Form& other) : name_(other.name_), canBeSign_(other.canBeSign_), canBeExec_(other.canBeExec_)
{
	*this = other;
}

Form::~Form()
{}

Form& Form::operator=(const Form& other)
{
	this->sign_ = other.sign_;
	return (*this);
}

std::string Form::getName()
{
	return this->name_;
}

bool Form::getSign()
{
	return this->sign_;
}

int Form::getBeSign()
{
	return this->canBeSign_;
}

int Form::getBeExec()
{
	return this->canBeExec_;
}

void Form::beSigned(Bureaucrat& bur)
{
	try
	{
		if (this->canBeSign_ < bur.getGrade())
			throw GradeTooLowException();
		else
			this->sign_ = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
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

std::ostream& operator<<(std::ostream&os, Form& other)
{
	os << other.getName() << ", indicating whether it is signed is " << other.getSign() << " , grade required to sign is " << other.getBeSign()
	<< " grade required to execute is " << other.getBeExec();
	return os;
}