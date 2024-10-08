#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int				  _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& bur);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& bur);
		std::string getName();
		int			getGrade();
		void		decrease();
		void		increase();
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream&os, Bureaucrat& bur);

#endif