#include"PCS.h"


void methodSeidel(matrix_t& matrixTemp, double T1, double T2, double stepX, double stepY, double eps, const int zoneValue)
{
	for (int j(0); j < matrixTemp.size(); j++) {
		for (int k(0); k < matrixTemp[j].size() && matrixTemp[j][k] != zoneValue; k++) {
			matrixTemp[j][k] = T1;
		}
	}
	matrix_t pastTemp(matrixTemp);
	for (int i = 0; i < 3000; i++)
	{
		bool isEquilibrium = true;

		for (int j(0); j < matrixTemp.size(); j++) {

			for (int k(0); k < matrixTemp[j].size() && matrixTemp[j][k] != zoneValue; k++) {
				double number = 0, perimetr = 0;
				double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
				if (isExist(pastTemp, j - 1, k, zoneValue)) {
					perimetr += stepX / stepY;
					t1 = pastTemp[j - 1][k];
				}
				if (isExist(pastTemp, j, k + 1, zoneValue)) {
					t2 = pastTemp[j][k + 1];
					perimetr += stepY / stepX;
				}
				else {
					if (k + 1 == matrixTemp[0].size()) {
						t2 = T2;
						perimetr += stepY / stepX;
					}
				}
				if (isExist(pastTemp, j + 1, k, zoneValue)) {
					t3 = pastTemp[j + 1][k];
					perimetr += stepX / stepY;
				}
				if (isExist(pastTemp, j, k - 1, zoneValue)) {
					t4 = pastTemp[j][k - 1];
					perimetr += stepY / stepX;
				}
				else {
					if (k - 1 < 0) {
						t4 = T1;
						perimetr += stepY / stepX;
					}
				}
				matrixTemp[j][k] = pastTemp[j][k] + (stepX / (4 * stepY)) * ((stepX / stepY) * (t1 + t3) + (stepY / stepX) * (t2 + t4) - pastTemp[j][k] * perimetr);
				if (abs(pastTemp[j][k] - matrixTemp[j][k]) > eps) {
					isEquilibrium = false;
				}
			}
		}
		if (isEquilibrium) {
			break;
		}

		pastTemp = matrixTemp;
		if (i % 250 == 0)
			printMatrix(matrixTemp, zoneValue);
	}
}