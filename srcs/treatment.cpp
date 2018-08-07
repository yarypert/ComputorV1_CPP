#include "../includes/computor.hpp"

void		format(Poly & exp)
{
	string ret;
	for (unsigned int i = 0; i < exp.str.length(); i++)
		if((exp.str[i] >= '0' && exp.str[i] <= '9') || exp.str[i] == '^' || exp.str[i] == 'X' || exp.str[i] == '.')
			ret += exp.str[i];
		else if (exp.str[i] == '+' || exp.str[i] == '-' || exp.str[i] == '*' || exp.str[i] == '/' || exp.str[i] == '=')
			ret = ret + ' ' + exp.str[i] + ' ';
	exp.fstr = ret;
}

void	split(Poly & exp)
{
	unsigned int i = 0;
	string word;
	vector<string> tab;

	while (exp.fstr[i])
	{
		if ((exp.fstr[i] == '+' || exp.fstr[i] == '-' || exp.fstr[i] == '=') && word.size())
		{
			exp.tab.push_back(word);
			word.clear();
		}
		word += exp.fstr[i];
		i++;
	}
	if (word.size())
		exp.tab.push_back(word);
	i = 0;
	while (i < exp.tab.size())
	{
		if (exp.tab[i][exp.tab[i].length() - 1] == ' ')
			exp.tab[i].erase(exp.tab[i].length() - 1);
		i++;
	}
}

void	change_sign(Poly & exp)
{
	unsigned int i = 0;
	int flag = 0;
	while (i < exp.tab.size())
	{
		if (exp.tab[i][0] == '=')
			flag = 1;
		if (exp.tab[i][0] == '+' && flag == 1)
			exp.tab[i][0] = '-';
		else if (exp.tab[i][0] == '-' && flag == 1)
			exp.tab[i][0] = '+';
		i++;
	}
}

void	print_vector(Poly & exp)
{
	unsigned int i = 0;
	while (i < exp.tab.size())
		cout << exp.tab[i++] << endl;
}


void	error(string err)
{
	cout << err << endl;
	exit(0);
}

void	check_degree(Poly & exp)
{
	exp.deg = 0;
	for (unsigned int i = 0; i < exp.fstr.length(); i++)
	{
		if (exp.fstr[i] == 'X' && exp.fstr[i + 1] == '^' && (exp.fstr[i + 2] 
		== '0' || exp.fstr[i + 2] == '1' || exp.fstr[i + 2] == '2'))
		{
			if (exp.fstr[i + 2] - 48 > exp.deg)
				exp.deg = exp.fstr[i + 2] - 48;
		}
		else if (exp.fstr[i] == 'X' && exp.fstr[i + 1] != '^')
			error("Expression isn't correctly formatted.");
	}
	if (exp.deg > 2)
		error("Polynomial degree is strictly superior to 2, i can't solve.");
}

void	check(Poly & exp)
{
	for (unsigned int i = 0; i < exp.str.length(); i++)
	{
		if ((exp.str[i] >= '0' && exp.str[i] <= '9') || exp.str[i] == '=' || exp.str[i] == ' ' || exp.str[i] == '+' || exp.str[i] == '-' || exp.str[i] == '*' || exp.str[i] == '/' || exp.str[i] == 'X' || exp.str[i] == '^' || exp.str[i] == '.')
			;
		else
			error("Expression contains invalid characters.");
	}
	check_degree(exp);
}

void	 get_signs(Poly & exp)
{
	for (unsigned int i = 0;i < exp.tab.size(); i++)
	{
			if (exp.tab[i][0] == '-')
				exp.sign += '-';
			else if (exp.tab[i][0] == '+')
				exp.sign += '+';
			else if (exp.tab[i][0] != '+' && exp.tab[i][0] != '-' && exp.tab[i][0] != '=')
				exp.sign += '+';
	}
}

void	insert_equal_sign(Poly & exp)
{
	unsigned int j = 0;
	for (unsigned int i = 0; i < exp.str.length(); i++)
	{
		if (exp.str[i] == '=')
		{
			j = i;
			while (exp.str[j] == ' ')
				j++;
			if (exp.str[j + 1] != '+' && exp.str[j + 1] != '-')
			{
				exp.str.insert(j + 1, "+");
				return ;
			}
		}
	}
}

void	del_signs(Poly & exp)
{
	for (unsigned int i = 0; i < exp.tab.size(); i++)
	{
		if (exp.tab[i][0] == '=')
		{
			exp.tab.erase(exp.tab.begin() + i);
			i--;
		}
		else if (exp.tab[i][0] == '+' || exp.tab[i][0] == '-')
		{
			exp.tab[i].erase(exp.tab[i].begin() + 1);
			exp.tab[i].erase(exp.tab[i].begin());
		}
	}
}

double	get_value(double val, char sign)
{
	if (sign == '-')
		val = -1 * val;
	else if (sign == '+')
		val = val;
	return(val);
}

void	get_abc(Poly & exp)
{
	double val;
	for(unsigned int i = 0; i < exp.tab.size(); i++)
	{
	val = stod(exp.tab[i]);
		if (exp.tab[i][exp.tab[i].length() - 1] == '2')
			exp.a = exp.a + get_value(val, exp.sign[i]);
		if (exp.tab[i][exp.tab[i].length() - 1] == '1')
			exp.b = exp.b + get_value(val, exp.sign[i]);
		if (exp.tab[i][exp.tab[i].length() - 1] == '0')
			exp.c = exp.c + get_value(val, exp.sign[i]);
	}
}

void	simp_exp(Poly & exp)
{
	char ca[64];
	char cb[64];
	char cc[64];
	sprintf(ca, "%g", exp.a);
	sprintf(cb, "%g", exp.b);
	sprintf(cc, "%g", exp.c);
	string a = ca;
	string b = cb;
	string c = cc;
	char signb = exp.b >= 0 ? '+' : ' ';
	char signc = exp.c >= 0 ? '+' : ' ';
	exp.sstr = a + " * X^2 " + signb + " " + b + " * X^1 " + signc + " " + c + " * X^0 = 0";
	exp.ssstr = a + " * X^2 " + signb + " " + b + " * X " + signc + " " + c + " = 0";
}

void	compute(Poly & exp)
{
	exp.str.erase(remove(exp.str.begin(), exp.str.end(), ' '), exp.str.end());
	insert_equal_sign(exp);
	format(exp);
	check(exp);
	split(exp);
	change_sign(exp);
	get_signs(exp);
	del_signs(exp);
	get_abc(exp);
	simp_exp(exp);
}
