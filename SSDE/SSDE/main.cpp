#include "SSDE.h"



int main()
{
	double h(0.15);
	double length(52);
	std::vector<double> X;
	std::vector<std::vector<double>> Y;
	std::vector<double> Y0 = get_initial_values();
	double X0 = get_initial_x();
	difFunc_t dFy = get_differential_system();
	Euler_implicit_method(dFy,X,Y,X0,Y0,h,length);
	/*for (int i = 0; i < Y.size(); i++)
	{
		for (int j = 0; j < Y[0].size(); j++)
		{
			printf("Y %d.%d - %f.", i,j, Y[i][j]);
		}	
		std::cout<<std::endl;
	}*/
	out_data(X, Y);
	out_dataCSV(X, Y);
	return 0;
}