#include "SLE.h"

bool gauss_method(matrix_t matrix, std::vector<double> b, std::vector<double>& x)
{
	for (int i(0); i < matrix.size(); i++)
	{
		//print_matrix(matrix, b);
		if (!compability(matrix,b, i))
		{
			print_undefine();
			return false;
		}
		double multiplier(1 / matrix[i][i]);
		for (int g(0); g < matrix.size(); g++)
			matrix[i][g] *= multiplier;			
	 	 //print_matrix(matrix, b);
		b[i] *= multiplier;
		for (int g(0); g < matrix.size(); g++)
		{
			if (g == i)	continue;
			multiplier = (-matrix[g][i]);
			for (int c(0); c < matrix.size(); c++)
				matrix[g][c] += (matrix[i][c] * multiplier);
			b[g] += (b[i] * multiplier);
			matrix[g][i] = 0;
		//print_matrix(matrix, b);
		}
	}
	//print_matrix(matrix,b);
	x = b;
	return true;
}






