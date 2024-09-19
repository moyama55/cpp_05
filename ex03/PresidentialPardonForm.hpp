#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentalPardonForm : public AForm
{
	public:
		PresidentalPardonForm();
		PresidentalPardonForm(std::string targt);
		~PresidentalPardonForm();
		PresidentalPardonForm(PresidentalPardonForm& other);
		PresidentalPardonForm&	operator=(PresidentalPardonForm& other);
		void	execute(Bureaucrat const & executor) const;
		void	executalble() const;
};

#endif