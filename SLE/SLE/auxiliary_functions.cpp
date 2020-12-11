#include "SLE.h"

bool compability(matrix_t& matrix,std::vector<double>& b, const int y_cord)
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
	if (max < 1E-7)	return false;
	else {
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

double max_value(const matrix_t& matrix)
{
	double max(0.);
	for (int i(0); i < matrix.size(); i++)
	{
		for (int g(0); g < matrix[0].size(); g++)
		{
			if (abs(matrix[i][g]) > max)
			     max = abs(matrix[i][g]);			
		}
	}
	return max;
}

void print_matrix(matrix_t matrix, std::vector<double> b)
{
	printf("%2d  %2d\n",matrix.size(), matrix[0].size());
	for (int i(0); i < matrix.size(); i++)
	{
		std::cout << "|| " << i << " || ";
		for (int g = 0; g < matrix.size(); g++)
			printf("%4.3f", matrix[i][g]);
		printf(" | %4.3f ||\n ",b[i]);		
	}
	printf("\n\n");
}

void print_undefine()
{
	std::ofstream result_file("Result.txt");
	result_file << "UNDEFINE";
}
