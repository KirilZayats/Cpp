#ifndef GAUSS_H
#define GAUSS_H
#include<iostream>
#include<vector>
#include<fstream>
#include <iomanip>
#include <ctime>
#include<string>
#include <cmath>
using matrix_t = std::vector<std::vector<double>>;

void matrix_creat(std::ifstream& matrix_file, matrix_t& matrix,std::vector<double>& b,std::vector<double>& x);
//creates matrix of size,wich it outs from file

void matrix_set(std::ifstream& matrix_file,matrix_t& matrix, std::vector<double>& b);
//sets values in matrix from file

double max_value(const matrix_t& matrix);
//chooses max value from matrix

bool compability(matrix_t& matrix, std::vector<double>& b, const int y_cord);
//chooses max value from x_cord-colum and swap and check compability

bool gauss_method(matrix_t matrix, std::vector<double> b, std::vector<double>& x);
//performs the direct Gaussian method & inverse method

void out_vector(std::vector<double>& solution_vector);
// outs solution vector to file

void print_matrix(matrix_t matrix, std::vector<double> b);
// print matrix to console

//double print_residuals_vector(const std::vector<double>& solution_vector, matrix_t& matrix);
////print vector of residuals

void print_undefine();
//out "UNDEFINE"

bool LDLT(matrix_t matrix, std::vector<double> b, std::vector<double>& x);
//gui

bool sle(matrix_t A, std::vector<double> b, std::vector<double>& x);
//interface of Gauss method

double residual(const matrix_t& A, const std::vector<double>& b, const std::vector<double>& x);
//interface of residual's norm

//double set_eps(matrix_t matrix)
//{
//	return (max_value(matrix) * 1E-6);
//}
//extern double eps;
#endif 
