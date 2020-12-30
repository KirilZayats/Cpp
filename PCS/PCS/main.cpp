#include"PCS.h"
#include<fstream>


namespace metod {
	class Method
	{
		//void programm();
	 };
}
int main() {
	double eps = 1e-3;
	double yLength = 2;
	double xLength = 2;
	double xStep = 0.1;
	double yStep = 0.2;
	double a = 1;
	double b = 1;
	double T1 = 12;
	double T2 = 35;
	const int zoneValue = -1;
	int numbIter(0);
	double lamda(1);	
	matrix_t matrixTemp;
	std::ofstream file("ResultsOfTests.txt");
	for (unsigned k = 0; k < 20; k++)
	{
		double epsCopy = eps;
		file<<"....LAMBDA = "<< lamda << std::endl << std::endl;
		for (unsigned j = 0; j < 5; j++)
		{
			double xSteCopy = xStep;
			double yStepCopy = yStep;
			file << ".....eps = " << epsCopy << std::endl << std::endl;
			for (unsigned i(0); i < 5; i++) {
				matrixTemp = configuratePlate(xLength, yLength, xSteCopy, yStepCopy, a, b, zoneValue);
				//printMatrix(matrixTemp, zoneValue);
				methodSeidel(matrixTemp, T1, T2, xSteCopy, yStepCopy, epsCopy, zoneValue, lamda, numbIter);
				//printMatrix(matrixTemp, zoneValue);
				file << "number of iterations with xStep = " << xSteCopy << " and yStep = " << yStepCopy << " : " << numbIter << std::endl;
				xSteCopy += 0.05;
				yStepCopy += 0.05;
				numbIter = 0;
			}
			epsCopy /= 10;
		}
		lamda += 0.05;
	}
	matrixTemp = configuratePlate(xLength, yLength, xStep, yStep, a, b, zoneValue);
	printMatrix(matrixTemp, zoneValue);
	methodSeidel(matrixTemp, T1, T2, xStep, yStep, eps, zoneValue, 1.8, numbIter);
	printMatrix(matrixTemp, zoneValue);
	draw_image(matrixTemp,zoneValue,a/yStep,b/xStep);
}


void metod::Method::programm()
{
#include <stdlib.h>
#include <math.h>
#define PRES double
#define NXB 15
#define NX NXB*3+1
#define NYB 12
#define NY NYB*3+1
#define REP 3000
#define EPSL 1.e-5
#define LL 1.7f
#define TEM1 5.0f
#define TEM2 15.0f
#define HX 0.2f
#define HY 0.3f
	using namespace std;
	void maxpvr(PRES * t1, PRES * del, PRES * maxdel)
	{
		PRES d = fabs(*del) / fabs(*t1);
		if (d > * maxdel) *maxdel = d;
	}
	int main(int argc, char** argv)
	{
		ofstream foutT("c:/work/dT.dat", ios_base::out | ios_base::trunc
			| ios_base::binary);
		int i1, i2, j1, j2, rp, i, j, k = 0;
		PRES T1 = TEM1, T2 = TEM2, h = HX, r = HY, tx, t0, t1, del,
			maxdel = 0.0f;
		PRES T[NY][NX];
		PRES lam = LL;
		PRES eps = EPSL;
		int prz = 1;
		int nT = 0;
		PRES alf_1 = -h / r;
		PRES alf_2 = -r / h;
		PRES alf_3 = alf_2 * 0.5f;
		PRES alf_4 = alf_1 * 0.5f;
		PRES gam_1 = -2.f * (alf_1 + alf_2);
		PRES gam_2 = -1.5f * (alf_1 + alf_2);
		PRES gam_3 = -(alf_1 + alf_2);
		PRES gam_4 = -(alf_3 + alf_4);
		i1 = NXB + NXB; i2 = i1 + NXB;
		j1 = NYB; j2 = NYB * 3; rp = REP;
		for (j = 0; j <= j2; j++) {
			for (i = 0; i <= i2; i++) { T[j][i] = 0.0f; }
		}
		for (j = 0; j <= j1; j++) T[j][0] = T1;
		for (i = i1; i <= i2; i++) T[j2][i] = T2;
		while (k < rp && prz == 1) {
			k++;
			for (j = 0; j < j2; j++) {
				for (i = 1; i <= i2; i++) {
					t0 = T[j][i];
					if (i >= 0 && i < i2 && j == 0) {
						tx = -(alf_3 * (T[j][i - 1] + T[j][i + 1]) + alf_1 * T[j + 1][i]) / gam_3;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
					else if (i == i2 && j == 0) {
						tx = -(alf_3 * T[j][i - 1] + alf_4 * T[j + 1][i]) / gam_4;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
					else if (i == i2 && j > 0 && j < j2) {
						tx = -(alf_4 * (T[j - 1][i] + T[j + 1][i]) + alf_2 * T[j][i - 1]) / gam_3;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
					if (i > 0 && i < i1 && j == j1) {
						tx = -(alf_3 * (T[j][i - 1] + T[j][i + 1]) + alf_1 * T[j - 1][i]) / gam_3;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
					else if (i == i1 && j == j1) {

						tx = -(alf_3 * T[j][i - 1] + alf_4 * T[j + 1][i] + alf_2 * T[j][i + 1] + alf_1 * T[j -
							1][i]) / gam_2;

						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;

						maxpvr(&t1, &del, &maxdel);
					}
					else if (i == i1 && j > j1 && j < j2) {
						tx = -(alf_4 * (T[j - 1][i] + T[j + 1][i]) + alf_2 * T[j][i + 1]) / gam_3;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
					else if (i > 0 && i < i2 && j>0 && j < j1) {
						tx = -(alf_1 * (T[j - 1][i] + T[j + 1][i]) + alf_2 * (T[j][i - 1] + T[j][i + 1]))
							/ gam_1;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
					else if (i > i1 && i<i2 && j>j1 - 1 && j < j2) {
						tx = -(alf_1 * (T[j - 1][i] + T[j + 1][i]) + alf_2 * (T[j][i - 1] + T[j][i + 1]))
							/ gam_1;
						del = lam * (tx - t0); t1 = t0 + del; T[j][i] = t1;
						maxpvr(&t1, &del, &maxdel);
					}
				}
			}
			nT++; PRES w = maxdel;
			foutT.write((char*)&w, sizeof w);
			if (maxdel < eps) prz = 0; maxdel = 0.0f;
		}
		foutT.close();
		ofstream fouT("c:/work/nT.dat", ios_base::out | ios_base::trunc |
			ios_base::binary);
		fouT.write((char*)&nT, sizeof nT);
		fouT.close(); // закрываем файл
		ofstream fout("c:/work/Pole.dat", ios_base::out | ios_base::trunc
			| ios_base::binary);
		for (j = 0; j < NY; j++) {
			for (i = 0; i < NX; i++) {
				PRES w = T[j][i];
				fout.write((char*)&w, sizeof w);
			}
		}
		fout.close();
		int n_x = NX; int n_y = NY;
		ofstream fou("c:/work/Param.dat", ios_base::out |
			ios_base::trunc | ios_base::binary);
		fou.write((char*)&n_x, sizeof n_x);
		fou.write((char*)&n_y, sizeof n_y);
		fou.close();
	}
}