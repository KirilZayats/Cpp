#include "SLE.h"


void out_vector(std::vector<double>& solution_vector)
{
	std::ofstream result_file("Result.txt");
	for (int i(0); i < solution_vector.size(); i++)
		result_file << solution_vector[i] << std::endl;
}
void matrix_set(std::ifstream& matrix_file, matrix_t& matrix, std::vector<double>& b)
{
	for (int i(0); i < matrix.size(); i++)
	{
		for (int g(0); g < matrix.size(); g++)
			matrix_file >> matrix[i][g];		
		matrix_file >> b[i];
	}
}

void matrix_creat(std::ifstream& matrix_file, matrix_t& matrix, std::vector<double>& b, std::vector<double>& x)
{
	int order_matrix(0);
	matrix_file >> order_matrix;
	matrix_t timly_matrix(order_matrix, std::vector<double>(order_matrix, 0));
	matrix = timly_matrix;
	std::vector<double> b_timly(order_matrix);
	b = b_timly;
	std::vector<double> x_timly(order_matrix);
	x = x_timly;
}