#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// ShrubberyCreationForm Test;
	Bureaucrat scTestConfirm("kmotoyma", 120);
	AForm* sc1 = new ShrubberyCreationForm;
	scTestConfirm.signForm(*sc1);
	scTestConfirm.executeForm(*sc1);
	//RobotomyRequestForm Test;
	Bureaucrat rrTestConfirm("kmotoyam", 30);
	AForm* rr1 = new RobotomyRequestForm;
	rrTestConfirm.signForm(*rr1);
	rrTestConfirm.executeForm(*rr1);
	//PresidentialPardonForm Test;
	Bureaucrat ppTestConfirm("kmotoyam", 3);
	AForm* pp1 = new PresidentalPardonForm;
	ppTestConfirm.signForm(*pp1);
	ppTestConfirm.executeForm(*pp1);

	delete sc1;
	delete rr1;
	delete pp1;
	// /* exec error pattern */
	// Bureaucrat scTestFailerGrade("kmotoyam", 144);
	// AForm* sc2 = new ShrubberyCreationForm;
	// sc2->beSigned(scTestFailerGrade);
	// scTestFailerGrade.executeForm(*sc2);

	
	/* sign error pattern */
	// Bureaucrat scTestFailerGrade("kmotoyam", 120);
	// AForm* sc2 = new ShrubberyCreationForm;
	// scTestFailerGrade.executeForm(*sc2);

	/* both pattern */
	// Bureaucrat scTestFailerGrade("kmotoyam", 150);
	// AForm* sc2 = new ShrubberyCreationForm;
	// scTestFailerGrade.executeForm(*sc2);


}