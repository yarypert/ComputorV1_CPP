#ifndef COMPUTOR_HPP
# define COMPUTOR_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


# define RED "\033[38;5;196m"
# define GRE "\033[38;5;10m"
# define BLU "\033[38;5;27m"
# define WHI "\033[0m"

using namespace std;

class	Poly
{
	public:
		Poly(void);
		~Poly(void);

		string			str;
		string			fstr;
		string			sstr;
		string			ssstr;
		vector<string>	tab;
		int				deg;
		double			a;
		double			b;
		double			c;
		string			sign;
		double			delta;
};

//treatment.cpp
void		compute(Poly & exp);
void		change_sign(Poly & exp);
void		split(Poly & exp);
void		format(Poly & exp);
void		print_vector(Poly & exp);
void		error(string str);
void		check_degree(Poly & exp);
void		check(Poly & exp);
void		get_signs(Poly & exp);
void		insert_equal_sign(Poly & exp);
void		del_signs(Poly&exp);
double		get_value(double val, char sign);
void		get_abc(Poly & exp);
void		simp_exp(Poly & exp);

//solve.cpp
void		solve(Poly & exp);
void		print_header(void);

//usage.cpp
void		usage(void);
void		help(void);
void		examples(void);



#endif
