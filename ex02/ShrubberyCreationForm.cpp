#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other.getName(), other.getBeSign(), other.getBeExec())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getBeExec() && this->getSign() == false)
		throw AForm::BothErrorException();
	else if (this->getSign() == false)
		throw AForm::UnSignedException();
	else if (executor.getGrade() > this->getBeExec())
		throw AForm::UnExecException();
	this->executalble();
}

void ShrubberyCreationForm::executalble() const
{
	std::ofstream	writingFile;
	std::string		filename = this->getName();
	filename += "_shrubbery";
	writingFile.open(filename, std::ios::out);
	std::string writeText = TREE;
	writingFile << writeText << std::endl;
}