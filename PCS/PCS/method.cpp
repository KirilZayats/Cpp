#include"PCS.h"


void methodSeidel(matrix_t& matrixTemp, double T1, double T2, double stepX, double stepY, double eps,const int zoneValue)
{
	for (int j(0); j < matrixTemp.size(); j++) {
		for (int k(0); k < matrixTemp[j].size() && matrixTemp[j][k] != zoneValue; k++) {
			matrixTemp[j][k] = T1;
		}
	}
	for (int i = 0; i < 3000; i++)
	{
		bool isEquilibrium = true;
		for (int j(0); j < matrixTemp.size(); j++) {
			
			for (int k(0); k < matrixTemp[j].size() && matrixTemp[j][k] != zoneValue; k++) {
				double temp = 0;
				double number = 0;
				double pastStep = matrixTemp[j][k];
				if (isExist(matrixTemp, j - 1, k, zoneValue)) {
					number += stepX;
					temp += stepX*matrixTemp[j - 1][k];
				}
				if (isExist(matrixTemp, j, k + 1,zoneValue)) {
					number +=stepY;
					temp += stepY*matrixTemp[j][k + 1];
				}
				else {
					if (k + 1 == matrixTemp[0].size()) {
						temp += stepY*T2;
						number += stepY;
					}
				}
				if (isExist(matrixTemp, j + 1, k, zoneValue)) {
					number += stepX;
					temp += stepX* matrixTemp[j + 1][k];
				}
				if (isExist(matrixTemp, j, k - 1, zoneValue)) {
					number +=stepY;
					temp += stepY*matrixTemp[j][k - 1];
				}
				else {
					if (k - 1 < 0) {
						temp += stepY * T1;
						number += stepY;
					}
				}
				temp /= number;
				matrixTemp[j][k] = temp;
				if (abs(pastStep - temp) > eps) {
					isEquilibrium = false;
				}
			}
		}
		if (isEquilibrium) {
			break;
		}
	}
}