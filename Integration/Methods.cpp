#include"INTEGR.h"


double Trapezes_method(FuncX_t& Fx, const double& l_border, const double& r_border,int& n)
{
	double h (step_count(l_border,r_border,n-1));
	std::vector<double> X (range_vector(l_border,h,n));
	double sum (0);
	for (int i (1); i  < n-1; i ++)
		sum += Fx(X[i]);
	return h/2 * (Fx(X[0]) + Fx(X[n-1])) + h * sum;
}

double Simpson_method(FuncX_t& Fx, const double& l_border, const double& r_border,int& n)
{
	if (n % 2 != 0) n++;
	//automatically makes an even number of nodes
	double h(step_count(l_border, r_border, n-1));
	std::vector<double> X (range_vector(l_border, h, n));
	double sum1(0), sum2(0);
	for (int i (1); i < n/2; i++)
	{
		sum1 += Fx(X[2 * i - 1]);
		sum2 += Fx(X[2 * i]);
	}
	return h / 3 * (Fx(X[0])+2*sum1+4*sum2+Fx(X[n-1]));
}

double c_Simpson_method(FuncXY_t& Fxy, const double& lX_border, const double& rX_border, 
	                    const double& lY_border,const double& rY_border, int& n, int& m)
{
	if (n % 2 != 0) n++;
	if (m % 2 != 0) m++;
	//automatically makes an even number of nodes
	double hX(step_count(lX_border, rX_border, 2*(n-1)));
	double hY(step_count(lY_border, rY_border, 2*(m-1)));
	std::vector<double> X(range_vector(lX_border, hX, 2*n));
	std::vector<double> Y(range_vector(lY_border, hY, 2*m));
	double sum(0);
	for (int i (0); i < n-1; i++)
	{
		for (int j (0); j <m-1; j++)
		{
			sum += Fxy(X[2 * i], Y[2 * j]) + 4 * Fxy(X[2 * i + 1], Y[2 * j])
				+ Fxy(X[2 * i + 2], Y[2 * j]) + 4 * Fxy(X[2 * i], Y[2 * j + 1])
				+ 16 * Fxy(X[2 * i + 1], Y[2 * j + 1]) + 4 * Fxy(X[2 * i + 2], Y[2 * j + 1])
				+ Fxy(X[2 * i], Y[2 * j + 2]) + 4 * Fxy(X[2 * i + 1], Y[2 * j + 2]) + Fxy(X[2 * i + 2], Y[2 * j + 2]);
		}
	}
	return hX*hY/9*sum;
}

/*c_Simpson_method for curved region */
double c_Simpson_method(FuncXY_t& Fxy, FuncXY_t& rg_func, const double& lX_border, const double& rX_border,
	const double& lY_border, const double& rY_border, int& n, int& m)
{
	if (n % 2 != 0) n++;
	if (m % 2 != 0) m++;
	//automatically makes an even number of nodes
	double hX(step_count(lX_border, rX_border, 2 * (n - 1)));
	double hY(step_count(lY_border, rY_border, 2 * (m - 1)));
	std::vector<double> X(range_vector(lX_border, hX, 2 * n));
	std::vector<double> Y(range_vector(lY_border, hY, 2 * m));
	double sum(0);
	for (int i(0); i < n - 1; i++)
	{
		for (int j(0); j < m - 1; j++)
		{
			sum += Gxy(X[2 * i], Y[2 * j],Fxy,rg_func) + 4 * Gxy(X[2 * i + 1], Y[2 * j], Fxy, rg_func)
				+ Gxy(X[2 * i + 2], Y[2 * j], Fxy, rg_func) + 4 * Gxy(X[2 * i], Y[2 * j + 1], Fxy, rg_func)
				+ 16 * Gxy(X[2 * i + 1], Y[2 * j + 1], Fxy, rg_func) + 4 * Gxy(X[2 * i + 2], Y[2 * j + 1], Fxy, rg_func)
				+ Gxy(X[2 * i], Y[2 * j + 2], Fxy, rg_func) + 4 * Gxy(X[2 * i + 1], Y[2 * j + 2], Fxy, rg_func)
				+ Gxy(X[2 * i + 2], Y[2 * j + 2], Fxy, rg_func);
		}
	}
	return hX * hY / 9 * sum;
}