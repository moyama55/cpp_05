#include "PresidentialPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm(): AForm("Obama", 25, 5)
{}

PresidentalPardonForm::~PresidentalPardonForm()
{}

PresidentalPardonForm::PresidentalPardonForm(std::string target, int sign, int exec): AForm(target, sign, exec)
{}

PresidentalPardonForm::PresidentalPardonForm(PresidentalPardonForm& other) : AForm(other.getName(), other.getBeSign(), other.getBeExec())
{}

PresidentalPardonForm& PresidentalPardonForm::operator=(PresidentalPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

void PresidentalPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getBeExec() && this->getSign() == false)
		throw AForm::BothErrorException();
	else if (this->getSign() == false)
		throw AForm::UnSignedException();
	else if (executor.getGrade() > this->getBeExec())
		throw AForm::UnExecException();
	this->executalble();
}

void PresidentalPardonForm::executalble() const
{
	std::cout << "Zaphod Beeblebrox allowed " << this->getName() << std::endl;
}
