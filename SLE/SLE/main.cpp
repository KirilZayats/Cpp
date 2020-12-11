#include "SLE.h"


int main()
{
	matrix_t matrix;
	std::vector<double> x;
	std::vector<double> b;
	std::ifstream matrix_file("Test.txt");
	matrix_creat(matrix_file, matrix,b,x);
	matrix_set(matrix_file, matrix,b);
	matrix_file.close();
	///*eps = set_eps(matrix);*/
	//unsigned int start_time = clock();
	//if (!gauss_method(matrix, b, x))
	//{
	//	out_vector(x);
	//	unsigned int end_time = clock();
	//	std::cout << "Time of Gauss's method: " << end_time - start_time << " mseconds" << std::endl;
	//	std::cout << "residual: " << residual(matrix, b, x) << std::endl;
	//}
	
	/////////////////////////////////////////////
	unsigned int start_time1 = clock();
	LDLT(matrix, b, x);
	out_vector(x);
	unsigned int end_time1 = clock();
	std::cout << "time of ldlt-factorisation: " << end_time1 - start_time1<<" mseconds"<< std::endl;
	std::cout<<"residual: "<<residual(matrix,b,x)<<std::endl;
}

