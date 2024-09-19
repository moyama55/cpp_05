#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137)
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
	try
	{
		writingFile.open(filename, std::ios::out);
		if (writingFile.is_open() == false)
			throw std::exception();
		std::string writeText = TREE;
		writingFile << writeText << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cerr << "Caught an ios_base::failure exception: " << e.what() << std::endl;
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}