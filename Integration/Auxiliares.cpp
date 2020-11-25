#include"INTEGR.h"


double Fx(double x)
{
	return 2*x+1;
}

double Fxy(double x, double y)
{
	return (x - 0.5) * (x - 0.5) + (y - 1.5) * (y - 1.5);
}

double Gxy(double x, double y, FuncXY_t Fxy, FuncXY_t funkArea)
{
	if (funkArea(x, y) <= 0)
		return Fxy(x, y);
	else
		return 0;
}

double rg_func(double x, double y)
{
	return (x - 0.5) * (x - 0.5) + (y - 1.5) * (y - 1.5) - 0.5 * 0.5;
}

bool Runge_criteria(double(*func)(FuncX_t&,const double&,const double&,int&),FuncX_t& Fx, const double& l_border, const double& r_border, int n, const double& eps)
{	
	if (func == Simpson_method)
	{
		double I2h(2);
		double Ih(4.5);
		while(true)
		{
			I2h = Simpson_method(Fx, l_border, r_border, n);
			int n2 = 2 * n - 1;
			Ih= Simpson_method(Fx, l_border, r_border,n2);
			if (abs(Ih - I2h) < 15 * eps)
			{
				printf("Simpson_method result with an error %f: %.3f \nNumber od points: %d \n\n",eps, I2h,n);
				return true;
			}
			n = n2;
		}
	}
	if(func == Trapezes_method)
	{ 
		double I2h(0);
		double Ih(0);
		while (true)
		{
			I2h = Trapezes_method(Fx, l_border, r_border, n);
			int n2 = 2 * n - 1;
			Ih = Trapezes_method(Fx, l_border, r_border, n2);
			if (abs(Ih - I2h) < 3 * eps)
			{
				printf("Trapezes_method result with an error %f: %.3f \nNumber od points: %d \n\n", eps, I2h, n);
				return true;
			}
			n = n2;
		}
	}
	else
	{
		printf("There is no such function!\n");
			return false;
	}
}

std::vector<double> range_vector(double l_border,double step,double n)
{
	std::vector<double> range(n);
	for (int i (0); i < n; i++)
	{
		range.at(i) = l_border + i * step;
	}
	return range;
}

double step_count(const double& l_border, const double& r_border, const int& n)
{
	return (r_border - l_border) / (n);
}