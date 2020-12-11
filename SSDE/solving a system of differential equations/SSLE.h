#pragma once
#include"LIB.h"

/*
* Hedder for Gauss metod 
*/

bool gauss_method(matrix_t matrix, std::vector<double> b, std::vector<double>& x);
/*The Gauss method takes a matrix of coefficients for unknown equations 
and a column of free coefficients,as well as a vector for writing the calculated values*/
bool compability(matrix_t& matrix, std::vector<double>& b, const int y_cord);
/*Checks the matrix for compatibility,and if the matrix is not compatible,the program terminates*/
void print_matrix(matrix_t matrix, std::vector<double> b);
//Outs matrix on terminal
double max_value(const matrix_t& matrix);
void print_undefine();
