#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name_;
		bool				sign_;
		const int			canBeSign_;
		const int			canBeExec_;
	public:
		AForm();
		AForm(std::string name, int beSign, int beExec);
		~AForm();
		AForm(const AForm& f);
		AForm& operator=(const AForm& f);
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		std::string 	getName();
		bool			getSign();
		int				getBeSign();
		int				getBeExec();
		void			beSigned(Bureaucrat& bur);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream&os, AForm& other);

#endif