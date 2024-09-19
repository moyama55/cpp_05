#ifndef ROBOTOMYREQUESTFORM_HPP

#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>


class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(RobotomyRequestForm& other);
		void	execute(Bureaucrat const & executor) const;
		void	executalble() const;
};

#endif