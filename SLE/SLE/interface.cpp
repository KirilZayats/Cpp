#include "SLE.h"


double residual(const matrix_t& A, const std::vector<double>& b, const std::vector<double>& x)
{		
	std::vector<double> residual_vector(x.size());
	for (int i(0); i < x.size(); i++)
	{
		for (int g(0); g < x.size(); g++)
			residual_vector[i] += A[i][g] * x[g];
		residual_vector[i] -= b[i];
	}
	double max(0);
	for (int i = 0; i < residual_vector.size(); i++)
	{
		if (abs(residual_vector[i]) > max)
			max = abs(residual_vector[i]);
	}
	return max;
}

bool sle(matrix_t& A, std::vector<double>& b, std::vector<double>& x)
{	
	if (gauss_method(A,b, x))return true;
	else return false;
}