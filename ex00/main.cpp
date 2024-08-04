#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test1("kmotoyam", 100);
	Bureaucrat test2("kmotoyam", 0);
	Bureaucrat test3("kmotoyam", 10);
	test1.decrease();
	test2.increase();
	std::cout << test1 << std::endl;
}