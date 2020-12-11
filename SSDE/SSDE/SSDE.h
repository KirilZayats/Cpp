#pragma once
#include<iostream>
#include<vector>
#include <cmath>
#include <functional>
#include<cassert>
#include<fstream>


extern double eps;
extern double const stepMax;
extern double const stepMin;
using matrix_t = std::vector<std::vector<double>>;
using functions_t = std::vector<std::function<double(double, std::vector<double>)>>;
using func_t = std::function<double(double, std::vector<double>)>;
using difFunc_t = std::vector<std::function<double(double, std::vector<double>)>>;
bool gauss_method(matrix_t matrix, std::vector<double> b, std::vector<double>& x);
bool compability(matrix_t& matrix, std::vector<double>& b, const int y_cord);
//chooses max value from x_cord-colum and swap and check compability
bool newton_metod(functions_t& funcs,std::vector<double>& Y,const double& x, std::vector<double>& Y_1,const double& h);
double derivative(func_t& f,std::vector<double> Y,const double& x,const double& h,const int& numb_cord, int g);
//count derivative of function
bool b_check(std::vector<double> b);
bool max_check(std::vector<double> x, std::vector<double> delX);
bool Euler_implicit_method(difFunc_t& dFy, std::vector<double>& X, matrix_t& Y, const double x0,
	                       const std::vector<double>& Y0, double& h, const double length);
bool h_step(std::vector<double> y_1, std::vector<double> y, std::vector<double> y1, double& h, double h_1);
void out_dataCSV(std::vector<double> X, std::vector<std::vector<double>> Y);
void out_data(std::vector<double> X, std::vector<std::vector<double>> Y);
std::vector<std::function<double(double, std::vector<double>)>> get_differential_system();
std::vector<double> get_initial_values();
double get_initial_x();
double f1(double x, std::vector<double>y);
double f2(double x, std::vector<double>y);