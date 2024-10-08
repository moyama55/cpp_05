#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* form = NULL;
	std::string cmd_array[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	int i = 0;
	for (; i < 3; i++)
	{
		if (cmd_array[i] == name)
			break;
	}
	std::cout << "Intern creates " << cmd_array[i] << std::endl;
	switch (i)
	{
		case 0:
			try
			{
				form = new PresidentalPardonForm(target);
				break;
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				std::exit(1);
			}
		case 1:
			try
			{
				form = new RobotomyRequestForm(target);
				break;	
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				std::exit(1);
			}
		case 2:
			try
			{
				form = new ShrubberyCreationForm(target);
				break;	
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				std::exit(1);
			}
		default:
			std::cout << "invalid name" << std::endl;
			std::exit(1);
			break;
	}
	return form;
}