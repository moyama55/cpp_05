#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// ShrubberyCreationForm Test;
	Bureaucrat scTestConfirm("kmotoyma", 120);
	AForm* sc1 = new ShrubberyCreationForm;
	sc1->beSigned(scTestConfirm);
	scTestConfirm.executeForm(*sc1);
	//RobotomyRequestForm Test;
	Bureaucrat rrTestConfirm("kmotoyam", 30);
	AForm* rr1 = new RobotomyRequestForm;
	rr1->beSigned(rrTestConfirm);
	rrTestConfirm.executeForm(*rr1);
	//PresidentialPardonForm Test;
	Bureaucrat ppTestConfirm("kmotoyam", 3);
	AForm* pp1 = new PresidentalPardonForm;
	pp1->beSigned(ppTestConfirm);
	ppTestConfirm.executeForm(*pp1);
	//Intern test:
	Bureaucrat inTest("kmotoyam", 1);
	Intern in;
	AForm* sc2 = in.makeForm("adadad", "home");
	sc2->beSigned(inTest);
	inTest.executeForm(*sc2);
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