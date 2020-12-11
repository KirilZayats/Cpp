#include"SSDE.h"

bool Euler_implicit_method(functions_t& dFy, std::vector<double>& X, matrix_t& Y, const double x0, const std::vector<double>& Y0, double h, const double length)
{
	X.push_back(x0);
	Y.push_back(Y0);
	SFunction_t lNewton(dFy.size());
	for (int i(1); X[i - 1] <= (x0 + length); i++)
	{
		X.push_back(X[i - 1] + h);
		Y.push_back(Y[i - 1]);
		double x(X[i]);		
		std::vector<double> Y_1 = Y[i - 1];
		for (int j = 0; j < dFy.size(); j++) lNewton[j] =[x,Y_1, dFy, i, j,h](std::vector<double> apr) {return apr[j]-Y_1[j]- h * dFy[j](apr, x); };

		if (!newton_metod())
		{
			std::cout << "Newton" << std::endl;
			return false;
		}
	}
	return true;
}