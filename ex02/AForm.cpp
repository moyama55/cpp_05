#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name_("Dirty"), sign_(false), canBeSign_(30), canBeExec_(50)
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

AForm::AForm(std::string name, int beSign, int beExec) : name_(name), canBeSign_(beSign), canBeExec_(beExec)
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

AForm::AForm(const AForm& other) : name_(other.name_), canBeSign_(other.canBeSign_), canBeExec_(other.canBeExec_)
{
	*this = other;
}

AForm::~AForm()
{}

AForm& AForm::operator=(const AForm& other)
{
	this->sign_ = other.sign_;
	return (*this);
}

std::string AForm::getName()
{
	return this->name_;
}

bool AForm::getSign()
{
	return this->sign_;
}

int AForm::getBeSign()
{
	return this->canBeSign_;
}

int AForm::getBeExec()
{
	return this->canBeExec_;
}

void AForm::beSigned(Bureaucrat& bur)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return "TooHigh";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "TooLow";
}

std::ostream& operator<<(std::ostream&os, AForm& other)
{
	os << other.getName() << ", indicating whether it is signed is " << other.getSign() << " , grade required to sign is " << other.getBeSign()
	<< " grade required to execute is " << other.getBeExec();
	return os;
}