#include "../includes/computor.hpp"

void	init(Poly & exp)
{
	exp.deg = 0;
	exp.a = 0;
	exp.b = 0;
	exp.c = 0;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		string cmp = argv[1];
		if (cmp.compare("--help") == 0)
			help();
		else if (cmp.compare("--examples") == 0)
			examples();
		else
		{
			Poly	exp;
			init(exp);
			exp.str = argv[1];
			print_header();
			compute(exp);
			solve(exp);
		}
	}
	else
		usage();
	return 0;
}
