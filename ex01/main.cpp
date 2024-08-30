#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	test1("kmotoyam", 40);
	Bureaucrat	test2("two", 10);
	Form		doc1;
	Form		doc2;
	std::cout << doc1 << std::endl;
	test1.signForm(doc1);
	std::cout << doc1 << std::endl;

	std::cout << doc2 << std::endl;
	test2.signForm(doc2);
	std::cout << doc2 << std::endl;
}