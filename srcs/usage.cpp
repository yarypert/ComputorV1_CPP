#include "../includes/computor.hpp"

void	usage(void)
{
	cout << (string)"Usage : ./ComputorV1 " + RED +(string)"<Expression>" + WHI << endl;
	cout << (string)"\t Options : --help" << endl;
	cout << (string)"\t           --examples" << endl;
}

void	examples(void)
{
	cout << GRE + (string)"Exemples of expressions" + WHI << endl;
	cout << GRE + (string)"\tOKAY " + WHI + (string)">>> 5 * X^2 + 3 * X^1 - 4 * X^0 = 0" << endl;
	cout << GRE + (string)"\tOKAY " + WHI + (string)">>> 5 * X^2 + 3 * X - 4 = 0" << endl;
	cout << GRE + (string)"\tOKAY " + WHI + (string)">>> 5 * X^2 + X - 4 = 0" << endl;
	cout << GRE + (string)"\tOKAY " + WHI + (string)">>> 3 * X^0 - 5 * X^2 + 2 * X^1 = 3 * X^2 - 2 * X^1" << endl;
	cout << RED + (string)"\tNOT OKAY " + WHI + (string)">>> 2 * X^" + RED + "4" + WHI + " = 3 * X^" + RED + "-2" + WHI + " - 2 * X^1" << endl;
	cout << RED + (string)"\tNOT OKAY " + WHI + (string)">>> 4 * X^1 " + RED + "=" + WHI + " 7 * X^2 + 5 * X^2 " + RED + "=" + WHI + " 3 * X^2 - 2 * X^1" << endl;
	cout << RED + (string)"\tNOT OKAY " + WHI + (string)">>> " + RED + "Hello" + WHI + " 5 * X^2 + 2 * X^1 - 6 * X^0 = 0" << endl;
	cout << RED + (string)"\tNOT OKAY " + WHI + (string)">>> " + RED + "5X^2" + WHI + " + 2 * X^1 - 6 * X^0 = 0" << endl;
}

void	help(void)
{
	string t = GRE + (string)"-" + WHI;
	string str = GRE + (string)"Format :" + WHI + "\n\t" + t + " Expression must be a second or less degree polynom.\n\t" + t + " Expression must only contains the followings characters : \"123456789+-*/X .=\".\n\t" + t + " Polynomial degree must not be superior to 2 or inferior to 0.\n\t" + t + " You can write \"A * X^0\" or \"A\" where A is a number.\n\t" + t + " You can write \"A * X^1\" or \"A * X\" where A is a number.";

	cout << str << endl;
}
