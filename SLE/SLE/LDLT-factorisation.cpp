#include "SLE.h"



bool LDLT(matrix_t A, std::vector<double> b, std::vector<double>& x)
{
	for (int j = 0; j < A.size(); j++)
	{
		for (int i = j + 1; i < A.size(); i++)
		{
			double sum = 0;
			for (int k = 0; k <= j - 1; k++)
				sum += A[i][k] * A[k][j];
			A[i][j] = A[i][j] - sum;
		}
		double sum = 0;
		for (int k = 0; k < j; k++)
			sum += A[j][k] * A[k][j];
		A[j][j] = A[j][j] - sum;
		for (int i = j + 1; i < A.size(); i++)
			A[j][i] = A[i][j] / A[j][j];
	}

	std::vector<double> y(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		double sum = 0;
		for (int k = 0; k <= i - 1; k++) 
			sum += A[k][i] * y[k];
		y[i] = b[i] - sum;
	}

	std::vector<double> z(A.size());
	for (int i = 0; i < A.size(); i++)
		z[i] = y[i] / A[i][i];

	
	x[A.size() - 1] = z[A.size() - 1];
	for (int i = A.size() - 2; i >= 0; i--)
	{
		double sum = 0;
		for (int k = i + 1; k < A.size(); k++)
			sum += A[i][k] * x[k];
		x[i] = z[i] - sum;
	}	
	return true;
}