#pragma once
#include<iostream>
#include<cmath>
#include<vector>
#include<cassert>

using matrix_t = std::vector<std::vector<double>>;
void methodSeidel(matrix_t& matrixTemp, double T1, double T2, double stepX, double stepY, double eps,const int zoneValue);
matrix_t configuratePlate(double Xlength, double Ylength, double Xstep, double Ystep, double a, double b, const int zoneValue);
bool isExist(matrix_t& matrix, int i, int j,const int zoneValue);
void printMatrix(matrix_t matrix,const int zoneValue);
void draw_image(matrix_t& matrix, const int zoneValue, double a, double b);