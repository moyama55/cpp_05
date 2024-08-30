#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test1("kmotoyam", 120);
	Bureaucrat test2("kmotoyam", 3);
	Bureaucrat test3("kmotoyam", 10);
	test1.decrease();
	test2.increase();
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
}