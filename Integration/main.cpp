#include"INTEGR.h"

/**
*
* Zayats Kiril
* Numerical integration methods
* 4-th group,2-d course
* 
*/

int main()
{
	//////////////////////////////////////////////Simpson's method & Trapezes method /////////////////////////////////////////////////
	printf(".....Simpson's method & Trapezes method....\n\n");
	double eps = 1e-4;
	double l_border(0);
	double r_border(5);
	int n(2);//number of points
	FuncX_t F = Fx;
	printf("Trapezes_method result: %.3f\nSimpson_method result: %.3f\n\n",Trapezes_method(F,l_border, r_border, n) 
		                                                                  ,Simpson_method(F, l_border, r_border, n));	
	//////////////////////////////////////////////cube Simpson's method////////////////////////////////////////////////////////////////
	printf(".....Cube Simpson's method....\n\n");
	double lX_border(0);
	double rX_border(1);
	double lY_border(0);
	double rY_border(1);
	int Ypoints = 12;//number of y-points
	int Xpoints = 10;//number of x-points
	FuncXY_t f = Fxy;
	printf("c_Simpson_method result: %.3f\n",c_Simpson_method(f, lX_border, rX_border,lY_border,rY_border,Xpoints,Ypoints));
	//////////////////////////////////////////////Runge_criteria///////////////////////////////////////////////////////////
	printf("\n....Runge_criteria....\n\n");
	Runge_criteria(Trapezes_method, F, l_border, r_border, n,eps);
	Runge_criteria(Simpson_method, F, l_border, r_border, n, eps);
	/////////////////////////////////////////////c_Simpson_method for curved region////////////////////////////////////////////////////////////////
	printf(".....Cube Simpson's method for curved region....\n\n");
	FuncXY_t rg = rg_func;
	lX_border = 0;
	rX_border = 1;
	lY_border = 1;
	rY_border = 2;
	printf("c_Simpson_method for curved region result: %f\n", c_Simpson_method(f,rg,lX_border, rX_border, lY_border, rY_border, Xpoints, Ypoints));
	return 0;
}