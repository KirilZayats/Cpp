#include "MNQ.h"

int m;
bool MNQ(const std::vector<double>& X0, const std::vector<double>& Y0, std::vector<double>& A)
{
	std::vector<double> xStep=X0;
    std::vector<double> b(m+1);
	std::vector<double> xStepSum(m*3);
	xStepSum[0] = X0.size();
	b[0] = bCount(X0, Y0, 1);
	for (int i (1); i < xStepSum.size(); i++)
	{
		if(i<m+1)
		b[i] = bCount(xStep, Y0);
		xStepSum[i] = sumXstep(xStep, X0);	
	}
	matrix_t matrix(m+1, std::vector<double>(m+1, 0));
	for (int i(0); i < m+1; i++)
	{
		for (int g(0); g < m + 1; g++)
		{
			matrix[i][g] = xStepSum[g + i];
		}
	}
	LDLT(matrix,b,A);
	return true;
}