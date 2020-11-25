#include "SLE.h"



bool LDLT(matrix_t A, std::vector<double> b, std::vector<double>& x)
{
	matrix_t L(A.size(), std::vector<double>(A.size(), 0));
	matrix_t D(A.size(), std::vector<double>(A.size(), 0));	

	for (int i = 0; i < L.size(); i++)
		L[i][i] = 1;

	for (int j = 0; j < A.size(); j++)
	{
		for (int i = j + 1; i < A.size(); i++)
		{
			double sum = 0;
			for (int k = 0; k <= j - 1; k++)
				sum += A[i][k] * L[j][k];
			A[i][j] = A[i][j] - sum;
		}
		double sum = 0;
		for (int k = 0; k < j; k++)
			sum += A[j][k] * L[j][k];
		D[j][j] = A[j][j] - sum;
		for (int i = j + 1; i < A.size(); i++)
			L[i][j] = A[i][j] / D[j][j];
	}

	std::vector<double> y(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		double sum = 0;
		for (int k = 0; k <= i - 1; k++) 
			sum += L[i][k] * y[k];
		y[i] = b[i] - sum;
	}

	std::vector<double> z(A.size());
	for (int i = 0; i < A.size(); i++)
		z[i] = y[i] / D[i][i];

	
	x[L.size() - 1] = z[L.size() - 1];
	for (int i = A.size() - 2; i >= 0; i--)
	{
		double sum = 0;
		for (int k = i + 1; k < A.size(); k++)
			sum += L[k][i] * x[k];
		x[i] = z[i] - sum;
	}	
	return true;
}