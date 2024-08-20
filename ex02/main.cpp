#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat	test1("kmotoyam", 20);
	Bureaucrat	test2("two", 130);
	AForm		doc1;
	AForm		doc2;
	std::cout << doc1 << std::endl;
	doc1.beSigned(test1);
	// doc1.beSigned(test2);
	test1.signForm(doc1);
	test2.signForm(doc2);
}