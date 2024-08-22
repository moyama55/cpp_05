#ifndef INTERN_HPP

#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern& other);
		Intern& operator=(const Intern& other);
		AForm* makeForm(std::string name, std::string target);
};

#endif