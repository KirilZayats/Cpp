#include"SSDE.h"


double eps(1e-6);
bool gauss_method(matrix_t matrix, std::vector<double> b, std::vector<double>& x)
{
	for (int i(0); i < matrix.size(); i++)
	{
		if (!compability(matrix, b, i))	return false;		
		double multiplier(1 / matrix[i][i]);
		for (int g(0); g < matrix.size(); g++)
			matrix[i][g] *= multiplier;		
		b[i] *= multiplier;
		for (int g(0); g < matrix.size(); g++)
		{
			if (g == i)	continue;
			multiplier = (-matrix[g][i]);
			for (int c(0); c < matrix.size(); c++)
				matrix[g][c] += (matrix[i][c] * multiplier);			
			b[g] += (b[i] * multiplier);
			matrix[g][i] = 0;			
		}
	}
	x = b;
	return true;
}

bool compability(matrix_t& matrix, std::vector<double>& b, const int y_cord)
{
	double max(matrix[y_cord][y_cord]);
	int y_max_cord(0);
	for (int i = y_cord; i < matrix.size(); i++)
	{
		if (abs(matrix[i][y_cord]) > max)
		{
			max = abs(matrix[i][y_cord]);
			y_max_cord = i;
		}
	}
	if (max < eps)	return false;
	else
	{
		if (y_max_cord != 0)
		{
			matrix[y_max_cord].swap(matrix[y_cord]);
			double a = b[y_max_cord];
			b[y_max_cord] = b[y_cord];
			b[y_cord] = a;
		}
	}
	return true;
}

bool newton_metod(functions_t& funcs, std::vector<double>& Y,const double& x, std::vector<double>& Y_1, const double& h)
{
	for (int i(0); i < 100; i++)
	{	
		std::vector<double> b(funcs.size());
		for (int g(0); g < funcs.size(); g++)
			b[g] = Y[g]-Y_1[g]-h*funcs[g](x,Y);			
		matrix_t derivativ(Y.size(), std::vector<double>(Y.size(), 0));
		for (int g(0); g < Y.size(); g++)
		{
			for (int f(0); f <Y.size(); f++)
			derivativ[g][f] = derivative(funcs[g],Y,x,h,f,g);			
		}
		std::vector<double> deltY(Y.size());
		if (!gauss_method(derivativ, b, deltY))	return false;		
		for (int g(0); g <Y.size(); g++)
		   Y[g] -= deltY[g];		
		if (!max_check(Y, deltY) && !b_check(b))return true;		
	}
	return false;
}

bool max_check(std::vector<double> x, std::vector<double> delX)
{
	double max(0);
	std::vector<double> normVect(x.size());
	for (int i = 0; i < x.size(); i++)
	{
		if (abs(x[i]) <= 1)
		  normVect[i] = abs(delX[i]);		
		else 	
		normVect[i] = abs(delX[i] / x[i]);		
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
		if (abs(b[g]) > max)
			max = abs(b[g]);		
	}
	return max > eps;	
}

double derivative(func_t& f, std::vector<double> Y, const double& x,const double& h, const int& numb_cord,int g)
{
	double FdeltPlus(0);
	double FdeltMinus(0);
	double y_timly(abs(Y[numb_cord]));
	if (abs(Y[numb_cord]) > 1)
	{
		Y[numb_cord] += eps * y_timly;
		FdeltPlus =Y[g]-h*f(x,Y);
		Y[numb_cord] -= 2 * eps * y_timly;
		FdeltMinus = Y[g] - h * f(x, Y);
		return (FdeltPlus - FdeltMinus) / (2 * eps * y_timly);
	}
	else
	{
		Y[numb_cord] += eps;
		FdeltPlus = Y[g] - h * f(x, Y);
		Y[numb_cord] -= 2 * eps;
		FdeltMinus = Y[g] - h * f(x, Y);
		return (FdeltPlus - FdeltMinus) / (2 * eps);
	}
}

void out_data(std::vector<double> X, std::vector<std::vector<double>> Y)
{
	std::ofstream out("solution.txt");
	out << "             Rabbits & foxes"<<std::endl;
	for (int i = 0; i < X.size(); i++)
	{
		out << X[i] << " weeks " << Y[i][0] << " foxes " << Y[i][1] << " rabbits " << std::endl;
	}
}
void out_dataCSV(std::vector<double> X, std::vector<std::vector<double>> Y)
{
	std::ofstream out("solutionCSV.csv");	
	for (int i = 0; i < X.size(); i++)
	{
		out << X[i] << ',' << Y[i][0] << ',' << Y[i][1] << std::endl;
	}
}

bool h_step(std::vector<double> y_1, std::vector<double> y, std::vector<double> y1, double& h, double h_1)
{
	std::vector<double> epsl(y_1.size());
	for (int i(0); i < y_1.size(); i++)
	{
		epsl[i] = -(h / (h + h_1)) * (y1[i] - y[i] - (h / h_1) * (y[i] - y_1[i]));		
	}
	double maxEps(0.);
	for (int i(0); i < epsl.size(); i++)
	{
		if (abs(epsl[i]) > maxEps)
			maxEps = epsl[i];
	}
	if (abs(maxEps) > eps) {
		h /= 2;
		if (h < stepMin) {
			h = stepMin;
			return true;
		}
		return false;
	} 
	if (abs(maxEps) >= eps / 4 && abs(maxEps) <= eps) {
		return true;
	}
	if (abs(maxEps) < eps / 4) {
		h *= 2;
		if (h >stepMax) {
			h = stepMax;
			true;
		}
		return false;
	}
}

using std::vector;
#define y1 y[0]
#define y2 y[1]

double f1(double x, vector<double>y) {
	assert(y.size() == 2);
	return (0.4-0.01*y2)*y1;
}

double f2(double x, vector<double>y) {
	assert(y.size() == 2);
	return (-0.3+0.005*y1)*y2;
}

#undef y1
#undef y2

typedef std::function<double(double, vector<double>)> equation;

vector<equation> get_differential_system() {
	return { f1, f2 };
}

double get_initial_x() {
	return 0;
}

vector<double> get_initial_values() {
	return {70, 50};
}
