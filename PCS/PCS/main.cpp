#include"PCS.h"



int main() {
	double eps = 1e-4;
	double yLength = 2;
	double xLength = 2;
	double xStep = 0.1;
	double yStep = 0.2;
	double a = 1;
	double b = 1;
	double T1 = 12;
	double T2 = 35;
	const int zoneValue = -1;
	matrix_t matrixTemp(configuratePlate(xLength, yLength, xStep, yStep, a, b,zoneValue));
	printMatrix(matrixTemp,zoneValue);
	methodSeidel(matrixTemp, T1, T2, xStep, yStep, eps,zoneValue);
	printMatrix(matrixTemp,zoneValue);
	draw_image(matrixTemp,zoneValue,a/yStep,b/xStep);
}