#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>


#define TREE "\
    *\n\
   ***\n\
  *****\n\
 *******\n\
*********\n\
   |||\n"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm& other);
		void	execute(Bureaucrat const & executor) const;
		void	executalble() const;
};

#endif

