#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	test1("kmotoyam", 20);
	Bureaucrat	test2("two", 130);
	Form		doc1;
	Form		doc2;
	std::cout << doc1 << std::endl;
	doc1.beSigned(test1);
	// doc1.beSigned(test2);
	test1.signForm(doc1);
	test2.signForm(doc2);
}