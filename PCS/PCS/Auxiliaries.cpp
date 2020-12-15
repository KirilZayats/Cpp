#include"PCS.h"

matrix_t configuratePlate(double Xlength, double Ylength, double Xstep, double Ystep, double a, double b,const int zoneValue) {
	assert((Ylength / Ystep-int(Ylength / Ystep))==0 || (Xlength / Xstep - int(Xlength / Xstep)) == 0);
	matrix_t matrixTemp(int(Ylength/Ystep), std::vector<double>(int(Xlength/Xstep), 0));
	double aNumber = a / Ystep;
	double bNumber = b / Xstep;
	for (int j(0); j < matrixTemp.size(); j++) {
		for (int k(0); k < matrixTemp[j].size(); k++) {
			if (double(matrixTemp.size()) - 1 - j >= aNumber) {
				if (double(matrixTemp[j].size()) - 1 - k <= bNumber) {
					matrixTemp[j][k] = zoneValue;
				}
				else {
					matrixTemp[j][k] = 0;
				}
			}
			else {
				matrixTemp[j][k] = 0;
			}
		}
	}
	return matrixTemp;
}

bool isExist(matrix_t& matrix,int i, int j,const int zoneValue) {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() &&  matrix[i][j] != zoneValue) {
		return true;
	}
	return false;
}



void printMatrix(matrix_t matrix, const int zoneValue) {
	std::cout << ".....matrix of temperatures....." << std::endl;
	for (int j(0); j < matrix.size(); j++) {
		for (int k(0); k < matrix[j].size(); k++) {
			if (matrix[j][k]== zoneValue) {
				std::cout << "  ";
			}
			else {
				printf("%.2f  ",matrix[j][k]);
			}
		}
		std::cout << std::endl;
	}
}