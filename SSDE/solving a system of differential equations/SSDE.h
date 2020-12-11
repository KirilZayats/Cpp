#pragma once
#include"SSNE.h"

bool Euler_explicit_metho();
bool Euler_implicit_method(functions_t& dFy, std::vector<double>& X, matrix_t& Y, const double x0,
	const std::vector<double>& Y0, double h, const double length);
std::vector<std::function<double(double, std::vector<double>)>> get_differential_system();
std::vector<double> get_initial_values();
double get_initial_x();
double f1(double x, std::vector<double>y);
double f2(double x, std::vector<double>y);