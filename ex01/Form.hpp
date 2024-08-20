#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name_;
		bool				sign_;
		const int			canBeSign_;
		const int			canBeExec_;
	public:
		Form();
		Form(std::string name, int beSign, int beExec);
		~Form();
		Form(const Form& f);
		Form& operator=(const Form& f);
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		std::string getName();
		bool		getSign();
		int			getBeSign();
		int			getBeExec();
		void		beSigned(Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream&os, Form& other);

#endif