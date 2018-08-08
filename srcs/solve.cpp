#include "../includes/computor.hpp"

void	print_solution(Poly & exp)
{
	double sol1 = 0;
	double sol2 = 0;
	exp.delta = (exp.b * exp.b) - 4 * exp.a * exp.c;
	cout << "Polynomial Degree : " << exp.deg << endl;
	if (exp.delta < 0)
		cout << "Discriminant is " << exp.delta << " and is stricly negative, there are no solutions." << endl;
	else if (exp.delta == 0)
	{
		sol1 = -(exp.b / (2 * exp.a));
		cout << "Discriminant is equal to zero, there is only one solution :" << endl;
		printf("\n%g\n", sol1);
	}
	else if (exp.delta > 0)
	{
		sol1 = -((exp.b + sqrt(exp.delta)) / (2 * exp.a));
		sol2 = -((exp.b - sqrt(exp.delta)) / (2 * exp.a));
		cout << "Discriminant is " << exp.delta  << " and is stricly positive, there are two solutions :" << endl;
		printf("%g\n", sol1);
		printf("%g\n", sol2);
	}
}

void	print_expression(Poly & exp)
{
	cout << "Reduced form :" << endl << exp.sstr << endl;
	//cout << " Or :" << endl << "    " << exp.ssstr << endl << endl;
}

void	print_header(void)
{
	cout << BLU << "///////////////////////////////////////////" << endl;
	cout << "//              " << RED << "ComputorV1" << BLU << "               //" << endl;
	cout << "//      " << RED << "By : Supreme Leader Yarypert" << BLU << "     //" << endl;
	cout << "///////////////////////////////////////////"<< WHI << endl;
}

void	solve(Poly & exp)
{
	print_expression(exp);
	print_solution(exp);
}
