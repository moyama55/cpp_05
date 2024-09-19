#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robot", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other.getName(), other.getBeSign(), other.getBeExec())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getBeExec() && this->getSign() == false)
		throw AForm::BothErrorException();
	else if (this->getSign() == false)
		throw AForm::UnSignedException();
	else if (executor.getGrade() > this->getBeExec())
		throw AForm::UnExecException();
	this->executalble();
}

void RobotomyRequestForm::executalble() const
{
	srand((unsigned int)time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->getName() << " is became a robot " << std::endl;
	else
		std::cout << this->getName() << " couldn't become a robot " << std::endl; 
}