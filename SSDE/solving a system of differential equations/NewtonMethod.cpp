#include"SSNE.h"
#include"SSLE.h"


double eps = 1e-6;
bool newton_metod(functions_t dFy, lb_t funcs, std::vector<double>& Y, int& iter)
{	
	for (int i(0); i < 100; i++)
	{
		iter++;
		std::vector<double> b(dFy.size());
		for (int g(0); g < dFy.size(); g++)
			b[g] = funcs(g);
		matrix_t derivativ(Y.size(), std::vector<double>(Y.size(), 0));
		for (int g(0); g < Y.size(); g++)
		{
			for (int f(0); f < Y.size(); f++)
				derivativ[g][f] = derivative(funcs, Y, f,g);
		}
		std::vector<double> deltY(Y.size());
		if (!gauss_method(derivativ, b, deltY))	return false;
		for (int g(0); g < Y.size(); g++)
			Y[g] -= deltY[g];
		if (!max_check(Y, deltY) && !b_check(b))
		{
			return true;
		}
	}
	return false;
}

double derivative(lb_t f, std::vector<double> Y, int numb_cord,int func_cord)
{
	double FdeltPlus(0);
	double FdeltMinus(0);
	double y_timly(Y[numb_cord]);
	double delt(eps);
	if (Y[numb_cord] > 1)delt *= y_timly;	
	Y[numb_cord] += delt;
	FdeltPlus = f(func_cord);
	Y[numb_cord] -= 2 * delt;
	FdeltMinus = f(func_cord);
	return (FdeltPlus - FdeltMinus) / 2*delt;
	

}

bool max_check(std::vector<double> x, std::vector<double> delX)
{
	double max(0);

	std::vector<double> normVect(x.size());

	for (int i = 0; i < x.size(); i++)
	{
		if (abs(x[i]) <= 1) normVect[i] = abs(delX[i]);
		else normVect[i] = abs(delX[i] / x[i]);
	}

	for (int i = 0; i < x.size(); i++)
	{
		if (normVect[i] > max)
			max = abs(normVect[i]);
	}
	return max > eps;
}

bool b_check(std::vector<double> b)
{
	double max(0.);
	for (int g(0); g < b.size(); g++)
	{
		if (abs(b[g]) > max)max = abs(b[g]);
	}
	return max > eps;
}